#ifndef KLIENTIFORM_H
#define KLIENTIFORM_H

#include <QSqlQueryModel>
#include <addklientform.h>
#include <delklientform.h>
#include "ui_klientiform.h"

class KlientiForm : public QWidget, private Ui::KlientiForm
{
    Q_OBJECT

    QSqlQueryModel* Klient;

    void Update();

public:
    explicit KlientiForm(QWidget *parent = nullptr);
private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // KLIENTIFORM_H
