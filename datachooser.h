#ifndef DATACHOOSER_H
#define DATACHOOSER_H

#include <QMainWindow>

namespace Ui {
class DataChooser;
}

class DataChooser : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataChooser(QWidget *parent = nullptr);
    ~DataChooser();

signals:
    void graphshow();
    void graphTop();
    void compareTwo(int,int);
    void findOne(int);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::DataChooser *ui;
};

#endif // DATACHOOSER_H
