#ifndef POSTAVKIFORM_H
#define POSTAVKIFORM_H

#include <QSqlQueryModel>
#include <addpostavkiform.h>
#include <postavshikform.h>
#include <pechatpform.h>
#include "ui_postavkiform.h"


class PostavkiForm : public QWidget, private Ui::PostavkiForm
{
    Q_OBJECT

    QSqlQueryModel* postavki;
    QSqlQueryModel* postavki2;

    void Update();

public:
    explicit PostavkiForm(QWidget *parent = nullptr);
private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
};

#endif // POSTAVKIFORM_H
