#include "addpostavkiform.h"

AddPostavkiForm::AddPostavkiForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->setWindowTitle("Добавить новую поставку");
    combo1 = new QSqlQueryModel(this);
    combo1->setQuery("select [Name P] FROM [Postavshik]");
    comboBox->setModel(combo1);
    combo2 = new QSqlQueryModel(this);
    combo2->setQuery("select [Name] FROM [Tovar]");
    comboBox_2->setModel(combo2);
}

void AddPostavkiForm::on_pushButton_clicked()
{
    QSqlQuery Add;
    QString Post,Name,Prise,Count,DATA,Izm;


    Prise=lineEdit->text();
    Count=spinBox->text();
    DATA=lineEdit_3->text();
    Post = comboBox->currentText();
    Name = comboBox_2->currentText();


    if(Prise!="")
    {
        if(DATA!="")
        {
            Add.exec("SELECT [ID Postavshika] FROM [Postavshik] WHERE [Name P]='"+Post+"'");
            Add.first();
            Post=Add.value(0).toString();

            Add.exec("SELECT [ID Ed Izm] FROM [Tovar] WHERE [Name]='"+Name+"'");
            Add.first();
            Izm=Add.value(0).toString();

            Add.exec("SELECT [ID Tovara] FROM [Tovar] WHERE [Name]='"+Name+"'");
            Add.first();
            Name=Add.value(0).toString();

            qDebug() <<Count<<Name<<Izm;

            Add.exec("INSERT INTO [Postavka] ([Prise P],[Count P],[Data P],[Summa P],[ID Tovara],[ID Ed Izm],[ID Postavshika]) VALUES ("+Prise+","+Count+",'"+DATA+"',"+Prise+"*"+Count+","+Name+","+Izm+","+Post+")");

            Add.exec("SELECT [ID Tovara] FROM [Sklad] WHERE [ID Tovara]="+Name);
            if(Add.first())
            {
                QString COL;
                Add.exec("SELECT [Count Na Sklade] FROM [Sklad] WHERE [ID Tovara]="+Name);
                Add.first();
                COL=Add.value(0).toString();
                Add.exec("UPDATE [Sklad] SET [Count Na Sklade] ="+COL+"+"+Count+" WHERE [ID Tovara]="+Name);
            }
            else
            {
                qDebug() <<Count<<Name<<Izm;
                Add.exec("INSERT INTO [Sklad] ([Count Na Sklade],[ID Tovara],[ID Ed Izm]) VALUES ("+Count+","+Name+","+Izm+")");
            }
            close();
        }
        else
        {
            message.setText("Введите дату.");
            message.exec();
        }
    }
    else
    {
        message.setText("Этого товара достаточно на складе, дополнительно заказывать не нужно.");
       message.exec();
    }
}
