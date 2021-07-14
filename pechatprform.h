#ifndef PECHATPRFORM_H
#define PECHATPRFORM_H

#include <QSqlQuery>
#include "QtPrintSupport/QPrintDialog"
#include "QtPrintSupport/QPrinter"
#include <QPrintDialog>
#include <QPainter>
#include <QMessageBox>
#include <QDebug>
#include "ui_pechatprform.h"

class PechatPRForm : public QWidget, private Ui::PechatPRForm
{
    Q_OBJECT

    QMessageBox message;

    QPrinter printer;
    QPainter *painter;

public:
    explicit PechatPRForm(QWidget *parent = nullptr);
private slots:
    void on_pushButton_clicked();
};

#endif // PECHATPRFORM_H
