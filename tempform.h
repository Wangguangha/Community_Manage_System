#ifndef TEMPFORM_H
#define TEMPFORM_H

#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QWidget>
#include <QDebug>

namespace Ui {
class TempForm;
}

class TempForm : public QWidget
{
    Q_OBJECT

public:
    explicit TempForm(QWidget *parent = nullptr);
    ~TempForm();

    void InitWindow();

private:
    Ui::TempForm *ui;
    void closeEvent(QCloseEvent *);
    QStandardItemModel *model;
    QItemSelectionModel *theSelection;
    QSqlDatabase db;

signals:
        void exitTemp();
private slots:
        void on_btn_add_clicked();
        void on_btn_del_clicked();
        void on_btn_edit_clicked();
        void on_btn_show_clicked();
};

#endif // TEMPFORM_H
