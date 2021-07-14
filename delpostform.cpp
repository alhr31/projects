#include "delpostform.h"

DelPostForm::DelPostForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->setWindowTitle("Удалить поставщика");
    message.setText("Удаление поставщика приведёт к удалению всех поставок связанных с ним.");
    message.exec();
}

void DelPostForm::on_pushButton_clicked()
{
    QString Name;
    QSqlQuery Del;

    Name=lineEdit->text();

    if(Name!="")
    {
        Del.exec("SELECT [Name P] FROM [Postavshik] WHERE [Name P]='"+Name+"'");
        if(Del.first())
        {
            Del.exec("delete from [Postavshik] where [Name P]='"+Name+"'");
            close();
        }
        else
        {
            message.setText("Поставщик не найден.");
            message.exec();
        }
    }
    else
    {
        message.setText("Введите название.");
        message.exec();
    }
}
