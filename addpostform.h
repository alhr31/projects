#ifndef ADDPOSTFORM_H
#define ADDPOSTFORM_H

#include <QSqlQuery>
#include <QMessageBox>
#include "ui_addpostform.h"

class AddPostForm : public QWidget, private Ui::AddPostForm
{
    Q_OBJECT

    QMessageBox message;

public:
    explicit AddPostForm(QWidget *parent = nullptr);
private slots:
    void on_pushButton_clicked();
};

#endif // ADDPOSTFORM_H
