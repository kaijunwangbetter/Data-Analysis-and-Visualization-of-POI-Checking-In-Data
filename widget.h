#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include  "include.h"
#include "selectdialog.h"
#include "progressdialog.h"
#include "datagraph.h"

#include "datachooser.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Widget *ui;
    SelectDialog *selectDialog;
    ProgressDialog *progressDialog;
    DataGraph *dataGraph;
    DataChooser *dataChooser;
};
#endif // WIDGET_H
