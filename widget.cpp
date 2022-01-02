#include "widget.h"
#include "ui_widget.h"
#include "selectdialog.h"
#include "include.h"
#include "progressdialog.h"
#include "datachooser.h"


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    selectDialog = new SelectDialog(this);
    dataGraph = new DataGraph();
    dataChooser = new DataChooser();
    connect(selectDialog,SIGNAL(emitOneRecord(int,int,QString,float,float,long long int)),dataGraph,SLOT(addData(int,int,QString,float,float,long long int)));
    connect(selectDialog,SIGNAL(loadDone()),dataGraph,SLOT(guodu()));
    connect(dataChooser,SIGNAL(graphshow()),dataGraph,SLOT(DrawGraph()));
    connect(dataChooser,SIGNAL(graphTop()),dataGraph,SLOT(drawTop()));
    connect(dataChooser,SIGNAL(compareTwo(int,int)),dataGraph,SLOT(drawCompare(int,int)));
    connect(dataChooser,SIGNAL(findOne(int)),dataGraph,SLOT(drawOne(int)));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::on_pushButton_clicked()
{  
    selectDialog->show();


}

void Widget::on_pushButton_2_clicked()
{
    dataChooser->show();
}
