#include "addklientform.h"

AddKlientForm::AddKlientForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->setWindowTitle("Добавить нового клиента");
}

void AddKlientForm::on_pushButton_clicked()
{
    QString Name,Adres,Number;
    QSqlQuery Add;

    Name=lineEdit->text();
    Adres=lineEdit_2->text();
    Number=lineEdit_3->text();

    if(Name!="")
    {
        if(Adres!="")
        {
            if(Number!="")
            {
                Add.exec("SELECT [Name PR] FROM [Klienti] WHERE [Name PR]='"+Name+"'");
                if(!Add.first())
                {
                    Add.exec("INSERT INTO [Klienti] ([Name PR],[Adres PR],[Number TL PR]) VALUES ('"+Name+"','"+Adres+"','"+Number+"')");
                }
                else
                {
                    message.setText("Клиент с таким именем уже существует.");
                    message.exec();
                }
                close();
            }
            else
            {
                message.setText("Введите номер телефона.");
                message.exec();
            }
        }
        else
        {
            message.setText("Введите адрес.");
            message.exec();
        }
    }
    else
    {
        message.setText("Введите имя.");
        message.exec();
    }
}
