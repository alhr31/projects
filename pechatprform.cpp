#include "pechatprform.h"

PechatPRForm::PechatPRForm(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    this->setWindowTitle("Печать");
}

void PechatPRForm::on_pushButton_clicked()
{
    QSqlQuery PeCH;
    QString IDPR;
    QString Name,NamePR,PrisePR,CountPR,DataPR,SummaPR,IZM;

    Name=lineEdit_4->text();
    NamePR=lineEdit_2->text();
    DataPR=lineEdit_3->text();

    qDebug() <<Name<<NamePR<<DataPR;

    PeCH.exec("select [ID Prodaji] from [Prodaji] WHERE [ID Tovara]=(SELECT [ID Tovara] FROM [Tovar] WHERE [Name]='"+Name+"') and [ID Klienta]=(SELECT [ID Klienta] FROM [Klienti] WHERE [Name PR] ='"+NamePR+"') and [Data PR] = '"+DataPR+"'");
    if(PeCH.first())
    {
        IDPR= PeCH.value(0).toString();


        PeCH.exec("select Name from [Tovar] WHERE [ID Tovara]= (SELECT [ID Tovara] FROM [Prodaji] WHERE [ID Prodaji]="+IDPR+")");
        PeCH.first();
        Name= PeCH.value(0).toString();

        PeCH.exec("select [Name PR] from [Klienti] WHERE [ID Klienta]=(select [ID Klienta] FROM [Prodaji] WHERE [ID Prodaji]="+IDPR+")");
        PeCH.first();
        NamePR= PeCH.value(0).toString();

        PeCH.exec("select [Prise PR] from [Prodaji] WHERE [ID Prodaji]="+IDPR);
        PeCH.first();
        PrisePR= PeCH.value(0).toString();

        PeCH.exec("select [Count PR] from [Prodaji] WHERE [ID Prodaji]="+IDPR);
        PeCH.first();
        CountPR= PeCH.value(0).toString();

        PeCH.exec("select [Data PR] from [Prodaji] WHERE [ID Prodaji]="+IDPR);
        PeCH.first();
        DataPR= PeCH.value(0).toString();

        PeCH.exec("select [Summa PR] from [Prodaji] WHERE [ID Prodaji]="+IDPR);
        PeCH.first();
        SummaPR= PeCH.value(0).toString();

        PeCH.exec("select [Ed Izm] from [Ed Izm] WHERE [ID Ed Izm]=( SELECT [ID Ed Izm] FROM [Prodaji] WHERE [ID Prodaji]="+IDPR+")");
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
                   // int X_twoTab = 3700;
                    int tab = 25;
                    painter.drawText(otstup1,otstup,"Клиент: " + NamePR);

                    otstup += tab;
                    QRect rectfont = QRect(otstup1,otstup,otstup2,tab);
                    painter.drawText(rectfont, Qt::AlignLeft,"Купил: " + Name);

                    otstup +=tab;
                    rectfont = QRect(otstup1,otstup,otstup2,tab);
                    painter.drawText(rectfont, Qt::AlignLeft ,"В количестве: " + CountPR +" "+ IZM);

                    otstup += tab;
                    rectfont = QRect(otstup1,otstup,otstup2,tab);
                    painter.drawText(rectfont, Qt::AlignLeft,"По цене: " + PrisePR+" за "+ IZM);

                    otstup += tab;
                    rectfont = QRect(otstup1,otstup,otstup2,tab);
                    painter.drawText(rectfont, Qt::AlignLeft,"Общая сумма покупки: " + SummaPR);

                    otstup += tab;
                    rectfont = QRect(otstup1,otstup,otstup2,tab);
                    painter.drawText(rectfont, Qt::AlignLeft,"Дата: "+DataPR);

                    painter.end();
                    }
    }
    else
    {
        message.setText("Продаж не найдено.");
        message.exec();

    }

}
