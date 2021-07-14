#ifndef ADDKLIENTFORM_H
#define ADDKLIENTFORM_H

#include <QSqlQuery>
#include <QMessageBox>
#include "ui_addklientform.h"

class AddKlientForm : public QWidget, private Ui::AddKlientForm
{
    Q_OBJECT

    QMessageBox message;

public:
    explicit AddKlientForm(QWidget *parent = nullptr);
private slots:
    void on_pushButton_clicked();
};

#endif // ADDKLIENTFORM_H
