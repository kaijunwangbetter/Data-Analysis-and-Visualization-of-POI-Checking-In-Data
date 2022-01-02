#ifndef PROGRESSDIALOG_H
#define PROGRESSDIALOG_H

#include <QWidget>
#include "include.h"

namespace Ui {
class ProgressDialog;
}

class ProgressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ProgressDialog(QDialog *parent = nullptr);
    ~ProgressDialog();

private:
    Ui::ProgressDialog *ui;
    QLabel *progress;

public slots:
    void progressValue(long long int);
};

#endif // PROGRESSDIALOG_H
