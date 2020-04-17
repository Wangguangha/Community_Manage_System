#ifndef DELFORM_H
#define DELFORM_H

#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QWidget>

namespace Ui {
class DelForm;
}

class DelForm : public QWidget
{
    Q_OBJECT

public:
    explicit DelForm(QWidget *parent = nullptr);
    ~DelForm();

    void InitWindow();

private:
    Ui::DelForm *ui;
    void closeEvent(QCloseEvent *);
    QStandardItemModel *model;
    QItemSelectionModel *theSelection;
    QSqlDatabase db;

signals:
    void exitDel();
private slots:
    void on_btn_add_clicked();
    void on_btn_del_clicked();
    void on_btn_edit_clicked();
    void on_btn_show_clicked();
};

#endif // DELFORM_H
