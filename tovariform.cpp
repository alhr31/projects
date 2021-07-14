#include "tovariform.h"

void TovariForm::Update()
{
    Tovari = new QSqlQueryModel(this);
    this->setWindowTitle("Товары");
    Tovari->setQuery("SELECT [Name] as Товар,"
                     "[Ed Izm] as [Единицы измерения] "
                     "FROM [Tovar],[Ed Izm]  "
                     "WHERE [Tovar].[ID Ed Izm]=[Ed Izm].[ID Ed Izm]");
    tableView->setModel(Tovari);
    tableView->show();
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

TovariForm::TovariForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    Update();
}

void TovariForm::on_pushButton_clicked()
{
    AddTovarForm *AddTovar=new AddTovarForm;
    AddTovar->show();
}

void TovariForm::on_pushButton_3_clicked()
{
    Update();
}

void TovariForm::on_pushButton_2_clicked()
{
    DelTovarForm *DelTovar=new DelTovarForm;
    DelTovar->show();
}
