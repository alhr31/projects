#include "addtovarform.h"

AddTovarForm::AddTovarForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->setWindowTitle("Добавить новый товар");
    Set = new QSqlQueryModel(this);
    Set->setQuery("select [Ed Izm] FROM [Ed Izm]");
    comboBox->setModel(Set);
}

void AddTovarForm::on_pushButton_clicked()
{
    QSqlQuery Add;
    QString EdIzm,Name;


    Name=lineEdit->text();
    EdIzm = comboBox->currentText();



    if(Name!="")
    {
        Add.exec("SELECT Name FROM [Tovar] WHERE [Name]='"+Name+"'");
        if(!Add.first())
        {
            Add.exec("SELECT [ID Ed Izm] FROM [Ed Izm] WHERE [Ed Izm]='"+EdIzm+"'");
            Add.first();
            EdIzm=Add.value(0).toString();
            Add.exec("INSERT INTO [Tovar] ([Name],[ID Ed Izm]) VALUES ('"+Name+"',"+EdIzm+")");
            close();
        }
        else
        {
            message.setText("Данный товар уже существует.");
            message.exec();
        }
    }
    else
    {
        message.setText("Введите корректное название.");
        message.exec();
    }
}
