#include "postavkiform.h"

void PostavkiForm::Update()
{
    postavki = new QSqlQueryModel(this);
    this->setWindowTitle("Поставки");
    postavki->setQuery("SELECT [Name] as Товар,[Name P] as Имя,[Prise P] as Цена,[Count P] as Количество,[Data P] as Дата,[Summa P] as Сумма FROM [Postavka],[Postavshik],[Tovar] WHERE [Postavka].[ID Tovara]=[Tovar].[ID Tovara] and [Postavka].[ID Postavshika]=[Postavshik].[ID Postavshika]");
    tableView->setModel(postavki);
    tableView->show();
    postavki2 = new QSqlQueryModel(this);
    postavki2->setQuery("SELECT [Name P] as Имя,Sum([Summa P]) AS Сумма FROM [Postavka],[Postavshik] WHERE [Postavshik].[ID Postavshika]=[Postavka].[ID Postavshika] Group by [Name P]");
    tableView_2->setModel(postavki2);
    tableView_2->show();
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    tableView_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

PostavkiForm::PostavkiForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    Update();
}

void PostavkiForm::on_pushButton_3_clicked()
{
    Update();
}

void PostavkiForm::on_pushButton_clicked()
{
    AddPostavkiForm *AddPostavki=new AddPostavkiForm;
    AddPostavki->show();
}

void PostavkiForm::on_pushButton_2_clicked()
{
    PostavshikForm *Postavshik=new PostavshikForm;
    Postavshik->show();
}

void PostavkiForm::on_pushButton_4_clicked()
{
    PechatPForm *Pechat=new PechatPForm;
    Pechat->show();
}
