#ifndef DELKLIENTFORM_H
#define DELKLIENTFORM_H

#include <QSqlQuery>
#include <QMessageBox>
#include "ui_delklientform.h"

class DelKlientForm : public QWidget, private Ui::DelKlientForm
{
    Q_OBJECT

    QMessageBox message;

public:
    explicit DelKlientForm(QWidget *parent = nullptr);
private slots:
    void on_pushButton_clicked();
};

#endif // DELKLIENTFORM_H
