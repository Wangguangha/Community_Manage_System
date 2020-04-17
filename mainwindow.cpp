#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QSqlDatabase>
#include <QPaintEvent>
#include <QPainter>
#include <QPixmap>
#include <QDebug>
#include <QPen>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPixmap pix(":/icon/Background.jpg");
    painter.drawPixmap(this->rect(),pix);
}

void MainWindow::on_act_close_triggered()
{
    //退出按钮槽函数
    this->close();
}

void MainWindow::on_btn_data_clicked()
{
    //数据操作
    DataForm *dataform = new DataForm(this);
    dataform->setWindowFlag(Qt::Window,true);
    dataform->setWindowTitle("DataForm");

    this->hide();
    dataform->show();
    connect(dataform,SIGNAL(exitData()),this,SLOT(show()));
}

void MainWindow::on_btn_Temp_clicked()
{
    //温度操作
    TempForm *tempform = new TempForm(this);
    tempform->setWindowFlag(Qt::Window,true);
    tempform->setWindowTitle("TempForm");

    this->hide();
    tempform->show();
    connect(tempform,SIGNAL(exitTemp()),this,SLOT(show()));
}

void MainWindow::on_btn_delivery_clicked()
{
    //物资配送
    DelForm *delform = new DelForm(this);
    delform->setWindowFlag(Qt::Window,true);
    delform->setWindowTitle("DelForm");

    this->hide();
    delform->show();
    connect(delform,SIGNAL(exitDel()),this,SLOT(show()));
}

void MainWindow::on_act_delivery_triggered()
{
    on_btn_delivery_clicked();
}

void MainWindow::on_act_showT_triggered()
{
    on_btn_Temp_clicked();
}

void MainWindow::on_act_data_triggered()
{
    on_btn_data_clicked();
}
