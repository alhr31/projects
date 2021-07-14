#include "postavshikform.h"

PostavshikForm::PostavshikForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->setWindowTitle("Поставщики");
    Update();
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

void PostavshikForm::Update()
{
    Postavshik = new QSqlQueryModel(this);
    Postavshik->setQuery("SELECT [Name P] as Имя,[Adres P] as Адрес,[Number TL P] as Телефон FROM [Postavshik]");
    tableView->setModel(Postavshik);
    tableView->show();
}

void PostavshikForm::on_pushButton_3_clicked()
{
    Update();
}

void PostavshikForm::on_pushButton_clicked()
{
    AddPostForm *AddPost=new AddPostForm;
    AddPost->show();
}

void PostavshikForm::on_pushButton_2_clicked()
{
    DelPostForm *DelPost=new DelPostForm;
    DelPost->show();
}
