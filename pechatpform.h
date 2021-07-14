#ifndef PECHATPFORM_H
#define PECHATPFORM_H

#include <QSqlQuery>
#include "QtPrintSupport/QPrintDialog"
#include "QtPrintSupport/QPrinter"
#include <QPrintDialog>
#include <QPainter>
#include <QMessageBox>
#include "ui_pechatpform.h"

class PechatPForm : public QWidget, private Ui::PechatPForm
{
    Q_OBJECT

    QMessageBox message;

    QPrinter printer;
    QPainter *painter;

public:
    explicit PechatPForm(QWidget *parent = nullptr);
private slots:
    void on_pushButton_clicked();
};

#endif // PECHATPFORM_H
