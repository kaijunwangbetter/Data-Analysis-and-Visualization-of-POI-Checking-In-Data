#include "selectdialog.h"
#include "ui_selectdialog.h"
#include "include.h"
#include <iostream>
#include <cstring>
#include <QDateTime>
#include "datagraph.h"
#include "progressdialog.h"

SelectDialog::SelectDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectDialog)
{
    ui->setupUi(this);


}

SelectDialog::~SelectDialog()
{
    delete ui;
}

void SelectDialog::on_pushButton_clicked()
{
    startID = ui->lineEdit->text().toInt();
    endID = ui->lineEdit_2->text().toInt();
    startlatitude = ui->lineEdit_3->text().toFloat();
    endlatitude = ui->lineEdit_4->text().toFloat();
    startlongitude = ui->lineEdit_5->text().toFloat();
    endlongitude = ui->lineEdit_6->text().toFloat();
    qDebug()<<startID<<endID<<"777777"<<endl;
    ProgressDialog *progressDialog=new ProgressDialog(this);

    progressDialog->show();
    progressDialog->raise();

    connect(this,SIGNAL(emitFileNumber(long long int)),progressDialog,SLOT(progressValue(long long int)));

    QString fileName = "D:/Qtfile/POIFinal/gowalla.csv";
    QFile testFile(fileName);

    if(!testFile.open(QIODevice::ReadOnly))
    {
        qDebug()<<"Error : Can't load file   "+fileName;

    }
    qDebug()<<"Error : Can load file   "+fileName;
    QTextStream * text=new QTextStream(&testFile);

    QStringList lines=text->readAll().split('\n');
    for(long long int t=1;t<lines.size()-1;t++)
    {
        QStringList oneRecord;//记录一条目录
        oneRecord=lines.at(t).split(',');//每一行的每一个项目

        int userID=oneRecord.at(0).toUInt();
        int locationID = oneRecord.at(1).toUInt();
        QString time = QString::fromStdString(oneRecord.at(2).toStdString());
        float latitude = oneRecord.at(3).toFloat();
        float longitude = oneRecord.at(4).toFloat();

        if(ui->checkBox->checkState()){
            if(!ui->checkBox_2->checkState()){
                if(startlatitude<=latitude&&endlatitude>=latitude&&startlongitude<=longitude&&endlongitude>=longitude){
                    emit  emitOneRecord(userID,locationID,time,latitude,longitude,DataNum);
                    DataNum += 1;
                }
            }
            else{
                if(startlatitude<=latitude&&endlatitude>=latitude&&startlongitude<=longitude&&endlongitude>=longitude&&startID<=userID && endID>=userID){
                    emit  emitOneRecord(userID,locationID,time,latitude,longitude,DataNum);
                    DataNum += 1;
                }
            }
        }
        else if(ui->checkBox_2->checkState()){
            if(startID<=userID && endID>=userID)
            {
                emit  emitOneRecord(userID,locationID,time,latitude,longitude,DataNum);
                DataNum += 1;
            }
        }
        long long int fileNumber = t;
        if(t%10000==0)
            emit emitFileNumber(fileNumber);
    }
    emit loadDone();
    qDebug()<<"finished!"+fileName;

}


