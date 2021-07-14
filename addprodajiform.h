#ifndef ADDPRODAJIFORM_H
#define ADDPRODAJIFORM_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDebug>
#include "ui_addprodajiform.h"

class AddProdajiForm : public QWidget, private Ui::AddProdajiForm
{
    Q_OBJECT

    QSqlQueryModel* combo1;
    QSqlQueryModel* combo2;

    QMessageBox message;

public:
    explicit AddProdajiForm(QWidget *parent = nullptr);
private slots:
    void on_pushButton_clicked();
};

#endif // ADDPRODAJIFORM_H
