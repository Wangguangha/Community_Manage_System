#include "tempform.h"
#include "ui_tempform.h"
#include <QString>

TempForm::TempForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TempForm)
{
    ui->setupUi(this);

    InitWindow();
}

TempForm::~TempForm()
{
    delete ui;
}

void TempForm::closeEvent(QCloseEvent *)
{
    emit exitTemp();
}

void TempForm::InitWindow()
{
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("commucity");         //数据库名
    db.setUserName("root");                  //登陆身份
    db.setPassword("wang.");                 //登陆密码

    bool ok = db.open();
    if (!ok)
        QMessageBox::warning(this,"warning","数据库打开失败!",QMessageBox::Ok);


    model = new QStandardItemModel(this);
    theSelection = new QItemSelectionModel(model);
    ui->tableView->setModel(model);
    model->setHorizontalHeaderItem(0, new QStandardItem("姓名") );
    model->setHorizontalHeaderItem(1, new QStandardItem("温度"));

    QSqlQuery query("select Name,Temp from Temp");//查询表的内容
    QStringList list;
    int i = 0;
    while (query.next()) {
          list.append(query.value(0).toString());
          model->setItem(i, 0, new QStandardItem(list.at(2*i)));
          list.append(query.value(1).toString());
          model->setItem(i, 1, new QStandardItem(list.at(2*i+1)));
          ++i;
    }

    ui->btn_add->setEnabled(false);
    ui->btn_del->setEnabled(false);
    ui->btn_edit->setEnabled(true);
    ui->btn_show->setEnabled(false);
}

void TempForm::on_btn_add_clicked()
{
    //增加按钮
    QList<QStandardItem*>    aItemList;   //容器类
    QStandardItem   *aItem;
    for(int i=0;i<2;i++)
    {
        aItem=new QStandardItem("");      //创建Item
        aItemList << aItem;               //添加到容器
    }


    model->insertRow(model->rowCount(),aItemList);              //插入一行，需要每个Cell的Item
    QModelIndex curIndex=model->index(model->rowCount()-1,0);   //创建最后一行的ModelIndex
    theSelection->clearSelection();                             //清空选择项
    theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);//设置刚插入的行为当前选择行
}

void TempForm::on_btn_del_clicked()
{
    //删除按钮
    QModelIndex curIndex=theSelection->currentIndex();  //获取当前选择单元格的模型索引

    if (curIndex.row()==model->rowCount()-1)            //最后一行
        model->removeRow(curIndex.row());               //删除最后一行
    else
    {
        model->removeRow(curIndex.row());               //删除一行，并重新设置当前选择行
        theSelection->setCurrentIndex(curIndex,QItemSelectionModel::Select);
    }
}

void TempForm::on_btn_edit_clicked()
{
    //修改按钮
    ui->btn_add->setEnabled(true);
    ui->btn_del->setEnabled(true);
    ui->btn_edit->setEnabled(false);
    ui->btn_show->setEnabled(true);
}

void TempForm::on_btn_show_clicked()
{
    //保存按钮
    QStandardItem   *aItem;
    int i,j;
    QString str;
    QSqlQuery query;

    for ( i=0;i<model->rowCount();i++)
    {
        str = str + "(";
        for( j=0;j<model->columnCount();j++)
        {
            aItem=model->item(i,j);
            if(j == 0)
            {
                str=str+"'"+aItem->text()+"'"+",";
            }
            else
            {
                str=str+aItem->text()+")"+QString::asprintf(",");
            }
        }
    }
    str = str.left(str.length()-1);

    QString sql=QStringLiteral("delete from Temp");
    query.exec(sql);

    QString s=QStringLiteral("insert into Temp values %1;").arg(str);
    if(!query.exec(s))
        qDebug() << query.lastError();


    ui->btn_add->setEnabled(false);
    ui->btn_del->setEnabled(false);
    ui->btn_edit->setEnabled(true);
    ui->btn_show->setEnabled(false);
}
