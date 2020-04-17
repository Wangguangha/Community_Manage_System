#include "dataform.h"
#include "ui_dataform.h"

#include <QSqlDatabase>
#include <QDebug>

DataForm::DataForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataForm)
{
    ui->setupUi(this);
    InitWindow();
}

DataForm::~DataForm()
{
    delete ui;
}

void DataForm::closeEvent(QCloseEvent *)
{
    emit exitData();
}

void DataForm::InitWindow()
{
    //如果遇到错误提示，请先添加响应头文件
    QSqlDatabase db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setPort(3306);
    db.setDatabaseName("commucity");         //数据库名
    db.setUserName("root");                  //登陆身份
    db.setPassword("wang.");                 //登陆密码

    bool ok = db.open();
    if (ok)
    {
        qDebug() << QString("数据库打开成功");
    }
    else
    {
        qDebug() << "数据库打开失败！";
    }


    model = new QStandardItemModel(this);
    theSelection = new QItemSelectionModel(model);
    ui->tableView->setModel(model);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents );
    model->setHorizontalHeaderItem(0, new QStandardItem("小区名称"));
    model->setHorizontalHeaderItem(1, new QStandardItem("小区人数"));
    model->setHorizontalHeaderItem(2, new QStandardItem("小区编号"));


    QSqlQuery query("select * from com_city");//查询表的内容
    QStringList list;
    int i = 0;
    while (query.next()) {
          list.append(query.value(0).toString());
          model->setItem(i, 0, new QStandardItem(list.at(3*i)));
          list.append(query.value(1).toString());
          model->setItem(i, 1, new QStandardItem(list.at(3*i+1)));
          list.append(query.value(2).toString());
          model->setItem(i, 2, new QStandardItem(list.at(3*i+2)));
          ++i;
    }
}

void DataForm::on_comboBox_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
    {
        model = new QStandardItemModel(this);
        theSelection = new QItemSelectionModel(model);
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents );
        model->setHorizontalHeaderItem(0, new QStandardItem("小区名称"));
        model->setHorizontalHeaderItem(1, new QStandardItem("小区人数"));
        model->setHorizontalHeaderItem(2, new QStandardItem("小区编号"));


        QSqlQuery query("select * from com_city");//查询表的内容
        QStringList list;
        int i = 0;
        while (query.next()) {
              list.append(query.value(0).toString());
              model->setItem(i, 0, new QStandardItem(list.at(3*i)));
              list.append(query.value(1).toString());
              model->setItem(i, 1, new QStandardItem(list.at(3*i+1)));
              list.append(query.value(2).toString());
              model->setItem(i, 2, new QStandardItem(list.at(3*i+2)));
              ++i;
        }
        break;
    };
    case 1:
        {
        model = new QStandardItemModel(this);
        theSelection = new QItemSelectionModel(model);
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents );
        model->setHorizontalHeaderItem(0, new QStandardItem("家庭编号"));
        model->setHorizontalHeaderItem(1, new QStandardItem("所需物资"));


        QSqlQuery query("select * from family");//查询表的内容
        QStringList list;
        int i = 0;
        while (query.next()) {
              list.append(query.value(0).toString());
              model->setItem(i, 0, new QStandardItem(list.at(2*i)));
              list.append(query.value(1).toString());
              model->setItem(i, 1, new QStandardItem(list.at(2*i+1)));
              ++i;
        }
        break;
    };
    case 2:
        {
        model = new QStandardItemModel(this);
        theSelection = new QItemSelectionModel(model);
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents );
        model->setHorizontalHeaderItem(0, new QStandardItem("姓名"));
        model->setHorizontalHeaderItem(1, new QStandardItem("性别"));
        model->setHorizontalHeaderItem(2, new QStandardItem("家庭编号"));
        model->setHorizontalHeaderItem(3, new QStandardItem("小区编号"));
        model->setHorizontalHeaderItem(4, new QStandardItem("电话号码"));


        QSqlQuery query("select * from people");//查询表的内容
        QStringList list;
        int i = 0;
        while (query.next()) {
              list.append(query.value(0).toString());
              model->setItem(i, 0, new QStandardItem(list.at(5*i)));
              list.append(query.value(1).toString());
              model->setItem(i, 1, new QStandardItem(list.at(5*i+1)));
              list.append(query.value(2).toString());
              model->setItem(i, 2, new QStandardItem(list.at(5*i+2)));
              list.append(query.value(3).toString());
              model->setItem(i, 3, new QStandardItem(list.at(5*i+3)));
              list.append(query.value(4).toString());
              model->setItem(i, 4, new QStandardItem(list.at(5*i+4)));
              ++i;
        }
        break;
    };
    case 3:
        {
        model = new QStandardItemModel(this);
        theSelection = new QItemSelectionModel(model);
        ui->tableView->setModel(model);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents );
        model->setHorizontalHeaderItem(0, new QStandardItem("姓名"));
        model->setHorizontalHeaderItem(1, new QStandardItem("温度"));


        QSqlQuery query("select * from Temp");//查询表的内容
        QStringList list;
        int i = 0;
        while (query.next()) {
              list.append(query.value(0).toString());
              model->setItem(i, 0, new QStandardItem(list.at(2*i)));
              list.append(query.value(1).toString());
              model->setItem(i, 1, new QStandardItem(list.at(2*i+1)));
              ++i;
        }
        break;
    };
    }
}
