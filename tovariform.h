#ifndef TOVARIFORM_H
#define TOVARIFORM_H

#include <QSqlQueryModel>
#include <addtovarform.h>
#include <deltovarform.h>
#include "ui_tovariform.h"

class TovariForm : public QWidget, private Ui::TovariForm
{
    Q_OBJECT

    QSqlQueryModel* Tovari;

    void Update();

public:
    explicit TovariForm(QWidget *parent = nullptr);
private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
};

#endif // TOVARIFORM_H
