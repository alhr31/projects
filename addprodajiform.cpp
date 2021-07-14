#include "addprodajiform.h"

AddProdajiForm::AddProdajiForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->setWindowTitle("Добавить новую продажу");
    combo1 = new QSqlQueryModel(this);
    combo1->setQuery("select [Name PR] FROM [Klienti]");
    comboBox->setModel(combo1);
    combo2 = new QSqlQueryModel(this);
    combo2->setQuery("select [Name] FROM [Tovar],[Sklad] WHERE [Sklad].[ID Tovara]=[Tovar].[ID Tovara]");
    comboBox_2->setModel(combo2);
}

void AddProdajiForm::on_pushButton_clicked()
{
    QSqlQuery Prod;
    QString Klient,Name,Prise,Count,DATA,Izm,CON;


    Prise=lineEdit->text();
    Count=spinBox->text();
    DATA=lineEdit_2->text();
    Klient = comboBox->currentText();
    Name = comboBox_2->currentText();

    qDebug() <<Prise<<Count<<DATA<<Klient<<Name;

    if(Prise!="")
    {
        if(DATA!="")
        {

            Prod.exec("SELECT [ID Klienta] FROM [Klienti] WHERE [Name PR]='"+Klient+"'");
            Prod.first();
            Klient=Prod.value(0).toString();

            Prod.exec("SELECT [ID Ed Izm] FROM [Tovar] WHERE [Name]='"+Name+"'");
            Prod.first();
            Izm=Prod.value(0).toString();

            Prod.exec("SELECT [ID Tovara] FROM [Tovar] WHERE [Name]='"+Name+"'");
            Prod.first();
            Name=Prod.value(0).toString();

            Prod.exec("SELECT [Count Na Sklade] FROM [Sklad] WHERE [ID Tovara]="+Name);
            if(Prod.first())
            {
                CON=Prod.value(0).toString();
                if(Count.toInt()<=CON.toInt())
                {
                    qDebug()<<Prise<<Count<<DATA<<Name<<Izm<<Klient;
                    Prod.exec("INSERT INTO [Prodaji] ([Prise PR],[Count PR],[Data PR],[Summa PR],[ID Tovara],[ID Ed Izm],[ID Klienta]) VALUES ("+Prise+","+Count+",'"+DATA+"',"+Prise+"*"+Count+","+Name+","+Izm+","+Klient+")");
                    if(Count.toInt()==CON.toInt())
                    {
                        Prod.exec("DELETE FROM [Sklad] WHERE [ID Tovara]="+Name);
                    }
                    else
                    {
                        Prod.exec("UPDATE [Sklad] SET [Count Na Sklade] ="+CON+"-"+Count+" WHERE [ID Tovara]="+Name);
                    }
                    close();
                }
                else
                {
                    message.setText("Товара недостаточно на складе.");
                    message.exec();
                }
            }
            else
            {
                message.setText("Товара нет на складе.");
                message.exec();
            }
        }
        else
        {
            message.setText("Введите дату.");
            message.exec();
        }
    }
    else
    {
        message.setText("Введите цену за единицу.");
        message.exec();
    }
}
