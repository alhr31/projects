#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QtSql>
#include <QSqlDatabase>
#include <QSqlQueryModel>
#include <QDebug>
#include <QMessageBox>
#include <postavkiform.h>
#include <prodajiform.h>
#include <tovariform.h>
#include "ui_mainwindow.h"


class MainWindow : public QMainWindow, private Ui::MainWindow
{
    Q_OBJECT

    QSqlDatabase Sklad;
    QSqlQueryModel* Skl;

    void Connect();
    void Update();

public:
    explicit MainWindow(QWidget *parent = nullptr);
private slots:
    void on_pushButton_3_clicked();
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
};

#endif // MAINWINDOW_H
