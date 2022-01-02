#include "datachooser.h"
#include "ui_datachooser.h"
#include "include.h"

DataChooser::DataChooser(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataChooser)
{
    ui->setupUi(this);
}

DataChooser::~DataChooser()
{
    delete ui;
}


void DataChooser::on_pushButton_clicked()
{
    emit graphshow();
//    qDebug()<<"emitemit"<<endl;
}

void DataChooser::on_pushButton_2_clicked()
{
    emit graphTop();
//    qDebug()<<"emitTop"<<endl;
}

void DataChooser::on_pushButton_3_clicked()
{
    int object1 = ui->lineEdit->text().toInt();
    int object2 = ui->lineEdit_2->text().toInt();
    emit compareTwo(object1, object2);
}

void DataChooser::on_pushButton_4_clicked()
{
    int user = ui->lineEdit_3->text().toInt();
    emit findOne(user);
}
