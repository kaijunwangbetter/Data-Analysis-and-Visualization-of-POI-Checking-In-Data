#ifndef DATAGRAPH_H
#define DATAGRAPH_H

#include <QMainWindow>

namespace Ui {
class DataGraph;
}

class DataGraph : public QMainWindow
{
    Q_OBJECT

public:
    explicit DataGraph(QWidget *parent = nullptr);
    ~DataGraph();
    void calTop();


private:
    Ui::DataGraph *ui;
    int user_ID[1502536];
    int location_ID[1502536];
    QString time_[1502536];
    float latitude_[1502536];
    float longitude_[1502536];
    int TopPOI[50000];
    int TopLocation[50000];
    long long int count = 0;
public slots:
    void addData(int userID,int locationID,QString time,float latitude,float longitude,long long int DataNum);

private slots:
    void guodu();
    void DrawGraph();
    void drawTop();
    void drawCompare(int object1,int object2);
    void drawOne(int user);
};

#endif // DATAGRAPH_H
