#ifndef ADDPOSTAVKIFORM_H
#define ADDPOSTAVKIFORM_H

#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QMessageBox>
#include <QDebug>
#include "ui_addpostavkiform.h"

class AddPostavkiForm : public QWidget, private Ui::AddPostavkiForm
{
    Q_OBJECT

    QSqlQueryModel* combo1;
    QSqlQueryModel* combo2;

    QMessageBox message;

public:
    explicit AddPostavkiForm(QWidget *parent = nullptr);
private slots:
    void on_pushButton_clicked();
};

#endif // ADDPOSTAVKIFORM_H
