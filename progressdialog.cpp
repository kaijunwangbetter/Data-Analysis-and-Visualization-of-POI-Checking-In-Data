#include "progressdialog.h"
#include "ui_progressdialog.h"

ProgressDialog::ProgressDialog(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::ProgressDialog)
{
    ui->setupUi(this);
    progress=new QLabel(ui->progressBar);
    this->setWindowTitle("Loading Data");
    ui->progressBar->setMaximum(1040000);
}

ProgressDialog::~ProgressDialog()
{
    delete ui;
}


void ProgressDialog::progressValue(long long int value)
{
    ui->progressBar->setValue(value);

}

