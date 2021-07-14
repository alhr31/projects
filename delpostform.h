#ifndef DELPOSTFORM_H
#define DELPOSTFORM_H

#include <QSqlQuery>
#include <QMessageBox>
#include "ui_delpostform.h"

class DelPostForm : public QWidget, private Ui::DelPostForm
{
    Q_OBJECT

    QMessageBox message;

public:
    explicit DelPostForm(QWidget *parent = nullptr);
private slots:
    void on_pushButton_clicked();
};

#endif // DELPOSTFORM_H
