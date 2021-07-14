#include "addpostform.h"

AddPostForm::AddPostForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->setWindowTitle("Добавить нового поставщика");
}

void AddPostForm::on_pushButton_clicked()
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
                Add.exec("SELECT [Name P] FROM [Postavshik] WHERE [Name P]='"+Name+"'");
                if(!Add.first())
                {
                    Add.exec("INSERT INTO [Postavshik] ([Name P],[Adres P],[Number TL P]) VALUES ('"+Name+"','"+Adres+"','"+Number+"')");
                }
                else
                {
                    message.setText("Поставщик с таким именем уже существует.");
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
        message.setText("Введите название.");
        message.exec();
    }
}
