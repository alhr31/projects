#include "delklientform.h"

DelKlientForm::DelKlientForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->setWindowTitle("Удалить клиента");
    message.setText("Удаление клиента приведёт к удалению всех заказов связанных с ним.");
    message.exec();
}

void DelKlientForm::on_pushButton_clicked()
{
    QString Name;
    QSqlQuery Del;

    Name=lineEdit->text();

    if(Name!="")
    {
        Del.exec("SELECT [Name PR] FROM [Klienti] WHERE [Name PR]='"+Name+"'");
        if(Del.first())
        {
            Del.exec("delete from [Klienti] where [Name PR]='"+Name+"'");
            close();
        }
        else
        {
            message.setText("Клиент не найден.");
            message.exec();
        }
    }
    else
    {
        message.setText("Введите имя.");
        message.exec();
    }
}
