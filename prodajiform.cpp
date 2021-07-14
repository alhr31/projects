#include "prodajiform.h"

ProdajiForm::ProdajiForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->setWindowTitle("Продажи");
    Update();
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void ProdajiForm::Update()
{
    prodaji = new QSqlQueryModel(this);
    prodaji->setQuery("SELECT [Name] as Товар,[Name PR] as Имя,[Prise PR] as Цена,[Count PR] as Количество,[Data PR] as Дата,[Summa PR] as Сумма FROM [Klienti],[Prodaji],[Tovar] WHERE [Prodaji].[ID Tovara]=[Tovar].[ID Tovara] and [Klienti].[ID Klienta]=[Prodaji].[ID Klienta]");
    tableView->setModel(prodaji);
    tableView->show();
    prodaji2 = new QSqlQueryModel(this);
    prodaji2->setQuery("SELECT [Name PR] as Имя,Sum([Summa PR]) AS Сумма FROM [Klienti],[Prodaji] WHERE [Klienti].[ID Klienta]=[Prodaji].[ID Klienta] group by [Name PR]");
    tableView_2->setModel(prodaji2);
    tableView_2->show();
}

void ProdajiForm::on_pushButton_3_clicked()
{
    Update();
}

void ProdajiForm::on_pushButton_clicked()
{
    AddProdajiForm *AddProdaji=new AddProdajiForm;
    AddProdaji->show();
}

void ProdajiForm::on_pushButton_2_clicked()
{
    KlientiForm *Klienti=new KlientiForm;
    Klienti->show();
}

void ProdajiForm::on_pushButton_4_clicked()
{

    PechatPRForm *PechatPR=new PechatPRForm;
    PechatPR->show();
}
