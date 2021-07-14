#ifndef ADDTOVARFORM_H
#define ADDTOVARFORM_H

#include <QSqlQueryModel>
#include <QSqlQuery>
#include <QMessageBox>
#include "ui_addtovarform.h"

class AddTovarForm : public QWidget, private Ui::AddTovarForm
{
    Q_OBJECT

    QSqlQueryModel* Set;

    QMessageBox message;

public:
    explicit AddTovarForm(QWidget *parent = nullptr);
private slots:
    void on_pushButton_clicked();
};

#endif // ADDTOVARFORM_H
