#ifndef DELTOVARFORM_H
#define DELTOVARFORM_H

#include <QSqlQuery>
#include <QMessageBox>
#include "ui_deltovarform.h"

class DelTovarForm : public QWidget, private Ui::DelTovarForm
{
    Q_OBJECT

    QMessageBox message;

public:
    explicit DelTovarForm(QWidget *parent = nullptr);
private slots:
    void on_pushButton_clicked();
};

#endif // DELTOVARFORM_H
