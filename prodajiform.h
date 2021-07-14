#ifndef PRODAJIFORM_H
#define PRODAJIFORM_H

#include <QSqlQueryModel>
#include <addprodajiform.h>
#include <klientiform.h>
#include <pechatprform.h>
#include "ui_prodajiform.h"

class ProdajiForm : public QWidget, private Ui::ProdajiForm
{
    Q_OBJECT

    QSqlQueryModel* prodaji;
    QSqlQueryModel* prodaji2;

    void Update();

public:
    explicit ProdajiForm(QWidget *parent = nullptr);
private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
};

#endif // PRODAJIFORM_H
