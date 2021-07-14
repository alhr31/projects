#include "klientiform.h"

KlientiForm::KlientiForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->setWindowTitle("Клиенты");
    Update();
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void KlientiForm::Update()
{
    Klient = new QSqlQueryModel(this);
    Klient->setQuery("SELECT [Name PR] as Имя,[Adres PR] as Адрес,[Number TL PR] as Телефон FROM [Klienti]");
    tableView->setModel(Klient);
    tableView->show();
}

void KlientiForm::on_pushButton_3_clicked()
{
    Update();
}

void KlientiForm::on_pushButton_clicked()
{
    AddKlientForm *AddKlient=new AddKlientForm;
    AddKlient->show();
}

void KlientiForm::on_pushButton_2_clicked()
{
    DelKlientForm *DelKlient=new DelKlientForm;
    DelKlient->show();
}
