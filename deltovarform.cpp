#include "deltovarform.h"

DelTovarForm::DelTovarForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->setWindowTitle("Удалить товар");
}

void DelTovarForm::on_pushButton_clicked()
{
    QString Name;
    QSqlQuery Del;

    Name=lineEdit->text();

    if(Name!="")
    {
        Del.exec("SELECT Name FROM [Tovar] WHERE [Name]='"+Name+"'");
        if(Del.first())
        {
            Del.exec("delete from [Tovar] where [Name]='"+Name+"'");
            close();
        }
        else
        {
            message.setText("Товар не найден.");
            message.exec();
        }
    }
    else
    {
        message.setText("Введите название.");
        message.exec();
    }
}
