#ifndef POSTAVSHIKFORM_H
#define POSTAVSHIKFORM_H

#include <QSqlQueryModel>
#include <addpostform.h>
#include <delpostform.h>
#include "ui_postavshikform.h"

class PostavshikForm : public QWidget, private Ui::PostavshikForm
{
    Q_OBJECT

    QSqlQueryModel* Postavshik;

    void Update();

public:
    explicit PostavshikForm(QWidget *parent = nullptr);
private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
};

#endif // POSTAVSHIKFORM_H
