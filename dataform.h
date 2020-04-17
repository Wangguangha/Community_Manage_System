#ifndef DATAFORM_H
#define DATAFORM_H

#include <QItemSelectionModel>
#include <QStandardItemModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QWidget>

namespace Ui {
class DataForm;
}

class DataForm : public QWidget
{
    Q_OBJECT

public:
    explicit DataForm(QWidget *parent = nullptr);
    ~DataForm();

    void InitWindow();


private:
    Ui::DataForm *ui;

    void closeEvent(QCloseEvent *);
    QStandardItemModel *model;
    QItemSelectionModel *theSelection;
    QSqlDatabase db;

signals:
        void exitData();
private slots:
        void on_comboBox_currentIndexChanged(int index);
};

#endif // DATAFORM_H
