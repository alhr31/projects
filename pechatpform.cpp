#include "pechatpform.h"

PechatPForm::PechatPForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->setWindowTitle("Печать");
}

void PechatPForm::on_pushButton_clicked()
{
    QSqlQuery PeCH;
    QString IDP;
    QString Name,NameP,PriseP,CountP,DataP,SummaP,IZM;

    Name=lineEdit_2->text();
    NameP=lineEdit->text();
    DataP=lineEdit_3->text();

    PeCH.exec("select [ID Postavki] from [Postavka] WHERE [ID Tovara]=(SELECT [ID Tovara] FROM [Tovar] WHERE [Name]='"+Name+"') and [ID Postavshika]=(SELECT [ID Postavshika] FROM [Postavshik] WHERE [Name P] ='"+NameP+"') and [Data P] = '"+DataP+"'");
    if(PeCH.first())
    {
        IDP= PeCH.value(0).toString();


        PeCH.exec("select Name from [Tovar] WHERE [ID Tovara]= (SELECT [ID Tovara] FROM [Postavka] WHERE [ID Postavki]="+IDP+")");
        PeCH.first();
        Name= PeCH.value(0).toString();

        PeCH.exec("select [Name P] from [Postavshik] WHERE [ID Postavshika]=(select [ID Postavshika] FROM [Postavka] WHERE [ID Postavki]="+IDP+")");
        PeCH.first();
        NameP= PeCH.value(0).toString();

        PeCH.exec("select [Prise P] from [Postavka] WHERE [ID Postavki]="+IDP);
        PeCH.first();
        PriseP= PeCH.value(0).toString();

        PeCH.exec("select [Count P] from [Postavka] WHERE [ID Postavki]="+IDP);
        PeCH.first();
        CountP= PeCH.value(0).toString();

        PeCH.exec("select [Data P] from [Postavka] WHERE [ID Postavki]="+IDP);
        PeCH.first();
        DataP= PeCH.value(0).toString();

        PeCH.exec("select [Summa P] from [Postavka] WHERE [ID Postavki]="+IDP);
        PeCH.first();
        SummaP= PeCH.value(0).toString();

        PeCH.exec("select [Ed Izm] from [Ed Izm] WHERE [ID Ed Izm]=( SELECT [ID Ed Izm] FROM [Postavka] WHERE [ID Postavki]="+IDP+")");
        PeCH.first();
        IZM= PeCH.value(0).toString();

        QPrintDialog printDialog(&printer, this);

        if (printDialog.exec())
                     {
                     QPainter painter;
                     if (! painter.begin(&printer))
                     {
                         qWarning("Ошибка открытия принтера!");
                         return;
                     }
                    painter.setFont(QFont("Arial", 14));
                    int otstup = 30;
                    int otstup2=3500;
                    int otstup1 = 20;
                    int tab = 25;
                    painter.drawText(otstup1,otstup,"Поставщик: " + NameP);

                    otstup += tab;
                    QRect rectfont = QRect(otstup1,otstup,otstup2,tab);
                    painter.drawText(rectfont, Qt::AlignLeft,"Поставил: " + Name);

                    otstup +=tab;
                    rectfont = QRect(otstup1,otstup,otstup2,tab);
                    painter.drawText(rectfont, Qt::AlignLeft ,"В количестве: " + CountP +" "+ IZM);

                    otstup += tab;
                    rectfont = QRect(otstup1,otstup,otstup2,tab);
                    painter.drawText(rectfont, Qt::AlignLeft,"По цене: " + PriseP+" за "+ IZM);

                    otstup += tab;
                    rectfont = QRect(otstup1,otstup,otstup2,tab);
                    painter.drawText(rectfont, Qt::AlignLeft,"Общая сумма поставки: " + SummaP);

                    otstup += tab;
                    rectfont = QRect(otstup1,otstup,otstup2,tab);
                    painter.drawText(rectfont, Qt::AlignLeft,"Дата: "+DataP);

                    painter.end();
                    }
    }
    else
    {
        message.setText("Поставки не найдено.");
        message.exec();

    }

}
