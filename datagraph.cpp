#include "datagraph.h"
#include "ui_datagraph.h"
#include "include.h"

DataGraph::DataGraph(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DataGraph)
{
    ui->setupUi(this);
    for(int i = 0;i < 50000;i++){
        TopPOI[i] = 0;
        TopLocation[i] = i;
    }

}

DataGraph::~DataGraph()
{
    delete ui;
}

void DataGraph::addData(int userID,int locationID,QString time,float latitude,float longitude,long long int DataNum){
    user_ID[DataNum] = userID;
    location_ID[DataNum] = locationID;
    time_[DataNum] = time;
    latitude_[DataNum] = latitude;
    longitude_[DataNum] = longitude;
    count += 1;

}

void DataGraph::DrawGraph(){

//    qDebug()<<"hhhhh  "<<count<<endl;
//    this->show();
//    this->setGeometry(600,400,1000,1000);
//     QChartView *chartView  = new QChartView;
//     QChart *chart = new QChart();
//     chart->setTitle("The Graph");
//     chartView->setChart(chart);
//     setCentralWidget(chartView);
//     QLineSeries *series = new QLineSeries;
//     chart->addSeries(series);
//     for(int i = 0;i < count;i++){
//         series->append(latitude_[i],longitude_[i]);
//         qDebug()<<"We are doing"<<i<<endl;
//     }
//     QValueAxis *axisX = new QValueAxis;
//     axisX->setRange(-150,150);
//     chart->setAxisX(axisX,series);
//     QValueAxis *axisY = new QValueAxis;
//     axisY->setRange(-150,150);
//     chart->setAxisY(axisY,series);
//     calTop();
    this->setGeometry(600,400,1000,1000);
    QScatterSeries *series1 = new QScatterSeries();
    series1->setName("user1");
    series1->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series1->setMarkerSize(10.0);


    for(long long int i = 0;i < count ;i++){
            series1->append(latitude_[i], longitude_[i]);
//            qDebug()<<"we add"<<latitude_[i]<<longitude_[i]<<time_[i]<<endl;
    }
    QChart *chart = new QChart();
    chart->addSeries(series1);
    chart->setTitle("User trajectory scatter plot ");
    chart->createDefaultAxes();
    chart->setDropShadowEnabled(false);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    this->setCentralWidget(chartView);
    this->show();
    calTop();
}


void DataGraph::guodu(){
//    qDebug()<<"Data loading done!"<<endl;
}

void DataGraph::calTop(){
    for(long long int i = 0;i < count;i++){
        TopPOI[location_ID[i]] += 1;
    }
    for (int i = 0; i < 49999; i++) {
            for (int j = 0; j < 49999-i; j++) {
                if (TopPOI[j] < TopPOI[j + 1]) {  
                    int temp = TopPOI[j];
                    int tmp = TopLocation[j];
                    TopPOI[j] = TopPOI[j + 1];
                    TopLocation[j] = TopLocation[j + 1];
                    TopPOI[j + 1] = temp;
                    TopLocation[j + 1] = tmp;
                }
            }
        }

    for(int i = 0;i < 10;i++){
        qDebug()<<TopPOI[i]<<endl;
    }
}

void DataGraph::drawTop(){
//    this->show();
//    this->setGeometry(600,400,1000,1000);
//     QChartView *chartView  = new QChartView;
//     QChart *chart = new QChart();
//     chart->setTitle("The Graph");
//     chartView->setChart(chart);
//     setCentralWidget(chartView);
//     QLineSeries *series = new QLineSeries;
//     chart->addSeries(series);
//     for(int i = 0;i < 10;i++){
//         series->append(TopLocation[i],TopPOI[i]);
//         qDebug()<<"We are doing"<<TopLocation[i]<<TopPOI[i]<<endl;
//     }
//     QValueAxis *axisX = new QValueAxis;
//     axisX->setRange(0,30);
//     chart->setAxisX(axisX,series);
//     QValueAxis *axisY = new QValueAxis;
//     axisY->setRange(0,150);
//     chart->setAxisY(axisY,series);


//    this->setGeometry(600,400,1000,1000);
    QBarSet *set0 = new QBarSet("Top10POI");
    *set0 << TopPOI[0] << TopPOI[1] << TopPOI[2] << TopPOI[3] << TopPOI[4] << TopPOI[5] <<TopPOI[6]<<TopPOI[7]<<TopPOI[8]<<TopPOI[9];
    QBarSeries *series = new QBarSeries();
    series->append(set0);
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("Top 10 POI");
    QStringList categories;
    QString cat[10];
    for(int i = 0;i<10;i++){
        cat[i] = QString::number(TopLocation[i]);
    }
    categories << cat[0] << cat[1] << cat[2] << cat[3] << cat[4] << cat[5] <<cat[6] <<cat[7]<<cat[8]<<cat[9];

    QBarCategoryAxis *axis = new QBarCategoryAxis();
    axis->append(categories);
    chart->createDefaultAxes();
    chart->setAxisX(axis, series);

    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    this->setCentralWidget(chartView);

    this->show();
}

void DataGraph::drawCompare(int object1,int object2){
    this->setGeometry(600,400,1000,1000);
    QScatterSeries *series1 = new QScatterSeries();
    series1->setName("user1");
    series1->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series1->setMarkerSize(10.0);

    QScatterSeries *series2 = new QScatterSeries();
    series2->setName("user2");
    series2->setMarkerShape(QScatterSeries::MarkerShapeCircle);
    series2->setMarkerSize(10.0);

    for(long long int i = 0;i < count ;i++){
        if(user_ID[i]==object1){
            series1->append(latitude_[i], longitude_[i]);
        }
        if(user_ID[i]==object2){
            series2->append(latitude_[i], longitude_[i]);
        }
    }
    QChart *chart = new QChart();
    chart->addSeries(series1);
    chart->addSeries(series2);
    chart->setTitle("comparison Graph");
    chart->createDefaultAxes();
    chart->setDropShadowEnabled(false);

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    this->setCentralWidget(chartView);
    this->show();

}

void DataGraph::drawOne(int user){
    int countnum[24];
    for(int i = 0;i < 24;i++){
        countnum[i] = 0;
    }
    for(long long int i = 0;i < count ;i++){
        if(user_ID[i]==user){
            int time = time_[i].at(11).digitValue()*10+time_[i].at(12).digitValue();

            for(int i = 0;i < 24;i++){
                if(time == i){
                    countnum[i] += 1;
                }
            }
        }

    }
        this->show();
        this->setGeometry(600,400,1000,1000);
         QChartView *chartView  = new QChartView;
         QChart *chart = new QChart();
         if(countnum[23]+countnum[0]+countnum[1]+countnum[2]+countnum[3]+countnum[4]>15){
             chart->setTitle("This is the user time graph,we can see that the user always stay up late");
         }
         else chart->setTitle("This is the user time graph,we can see that the user have a healthy schedule");
         chartView->setChart(chart);
         setCentralWidget(chartView);
         QLineSeries *series = new QLineSeries;
         chart->addSeries(series);
         for(int i = 0;i < 24;i++){
             series->append(i,countnum[i]);
//             qDebug()<<"we are"<<i<<countnum<<endl;

         }
         QValueAxis *axisX = new QValueAxis;
         axisX->setRange(0,24);
         chart->setAxisX(axisX,series);
         QValueAxis *axisY = new QValueAxis;
         axisY->setRange(0,40);
         chart->setAxisY(axisY,series);
        this->setGeometry(600,400,1000,1000);

}
