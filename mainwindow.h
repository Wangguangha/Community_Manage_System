#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "dataform.h"
#include "delform.h"
#include "tempform.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_act_close_triggered();

    void on_btn_data_clicked();

    void on_btn_Temp_clicked();

    void on_btn_delivery_clicked();

    void on_act_delivery_triggered();

    void on_act_showT_triggered();

    void on_act_data_triggered();

private:
    Ui::MainWindow *ui;
    void paintEvent(QPaintEvent *event);
};

#endif // MAINWINDOW_H
