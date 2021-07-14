#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    setupUi(this);
    Connect();
    Update();
    this->setWindowTitle("Приложение Склад");
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

}

void MainWindow::Connect()

{

        Sklad = QSqlDatabase::addDatabase("QODBC");
        Sklad.setDatabaseName("DRIVER={SQL Server};SERVER=HOME-PC;DATABASE=diplom;Trusted_Connection=yes;");
        Sklad.open();

}



void MainWindow::Update()
{
    Skl = new QSqlQueryModel(this);
    Skl->setQuery("SELECT [Name] as Товар,[Count Na Sklade] as [Количество на складе],[Ed Izm] as [Единицы измерения] "
                  "FROM [Sklad],[Tovar],[Ed Izm]  "
                  "WHERE [Sklad].[ID Tovara]=[Tovar].[ID Tovara] and [Tovar].[ID Ed Izm]=[Ed Izm].[ID Ed Izm]");
    tableView->setModel(Skl);
    tableView->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    Update();
}



void MainWindow::on_pushButton_clicked()
{
    PostavkiForm *Postavki=new PostavkiForm;
    Postavki->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    ProdajiForm *Prodaji= new ProdajiForm;
    Prodaji->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    TovariForm *Tovari=new TovariForm;
    Tovari->show();
}

//void MainWindow::on_pushButton_5_clicked()
//{
//    // получаем указатель на Excel
//        QAxObject *mExcel = new QAxObject("Excel.Application",this);

//        QAxObject *analyze = mExcel->querySubObject("Analyze");
//        // на директорию, откуда грузить
//        QAxObject *analyzes = analyze->querySubObject( "Open(const QString&)",
//                                                         "C:\Users\user\Desktop\DIPLOM\таблицы с продажами.xlsx" );
//        // на листы
//        QAxObject *mSheets = analyze->querySubObject( "Sheets" );
//        // указываем, какой лист выбрать
//        QAxObject *StatSheet = mSheets->querySubObject( "Item(const QVariant&)", QVariant("mainSheet") );
//        // получение указателя на ячейку [row][col] ((!)нумерация с единицы)
//        QAxObject* cell = StatSheet->querySubObject("Cells(QVariant,QVariant)", 1, 1);

//        if (querySubObject("Cells(QVariant,QVariant)", 2, 5)) < 0
//            then
//            {
//                message.setText("Нужно дозаказать товар");
//                message.exec();
//            }
//                else
//                    {
//                         message.setText("Этого товара достаточно на складе, дополнительно заказывать не нужно");
//                         message.exec();
//                    }

//        // освобождение памяти
//        delete cell;
//        delete StatSheet;
//        delete mSheets;
//        analyze->dynamicCall("Save()");
//        delete analyze;
//        //закрываем
//        delete analyzes;
//        //закрываем Excel
//        mExcel->dynamicCall("Quit()");
//        delete mExcel;
//}

