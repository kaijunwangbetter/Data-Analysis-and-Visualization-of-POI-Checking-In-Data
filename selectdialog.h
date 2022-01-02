#ifndef SELECTDIALOG_H
#define SELECTDIALOG_H

#include <QDialog>
#include "include.h"
#include "progressdialog.h"
#include "datagraph.h"

namespace Ui {
class SelectDialog;
}

class SelectDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectDialog(QWidget *parent = nullptr);
    ~SelectDialog();

private slots:
    void on_pushButton_clicked();


private:
    Ui::SelectDialog *ui;
    int startID = 0;
    int endID = 13930;
    float startlatitude = -90;
    float endlatitude = 90;
    float startlongitude = -180;
    float endlongitude = 180;

    QString time;
    long long int DataNum = 0;


signals:
    void emitOneRecord(int,int,QString,float,float,long long int);
    void emitFileNumber(long long int);
    void loadDone();

};

#endif // SELECTDIALOG_H
