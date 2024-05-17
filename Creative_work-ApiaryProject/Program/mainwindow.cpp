#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QWidget"
#include "QLabel"
#include "QPixmap"
#include "QTimer"
#include "QTime"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    createVectors();

    ui->setupUi(this);
    QTimer* timer = new QTimer(this);
    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(ontimeout()));


    /////////////////////////////////////////////////////////////////////////////////////////////
    ///



    for(int i = 0; i<100; i++){
        dates.push_back(0);
    }

    QString a = QDateTime::currentDateTime().toString("dd");
    dates[0] = a.toInt() - 100;





    for(int i = 1; i < 100 ;i++){
        dates[i] = dates[0] + i;
    }


    diff(10);

}

void MainWindow::createVectors(){
    QSqlQuery query("SELECT * FROM dt LIMIT 100" );
    while(query.next()){
        this->temper.push_front(query.value(3).toDouble());
        this->vlazhn.push_front(query.value(2).toDouble());
        this->prives.push_front(query.value(1).toDouble());
//        for (int i = 0; i > 9 ; i++ ) query.next();
    }
}

void MainWindow::on_pushButton_clicked() // Кнопка Анализ
{
    if (temper[89] > 37) {f = true; QMessageBox::critical(this, "Температура > 37°C", "Высок шанс гибели расплода. Необходимо убрать утепление.");}
    if (temper[89] < 8)  {f = true; QMessageBox::critical(this, "Температура < 8°C", "Высок шанс гибели пчёл. Необходимо установить утепление.");}

    if (vlazhn[89] < 70) {f = true; QMessageBox::critical(this, "Влажность в улье <70%", "Слишком сухо: это мешает развитию расплода! Обеспечьте пчёл источником воды.");}
    if (vlazhn[89] < 98 && vlazhn[89] >= 70 ) {f = true; QMessageBox::warning(this, "Влажность в улье <98%", "Высок риск возникновения плесени. Необходимо проветривание: уберите утепление.");}

    if (prives[89] > 47) {f = true; QMessageBox::warning(this, "Улей переполнен", "Необходимо поменять рамки, убрать мёд");}
    if (prives[89] < prives[88]) {f = true; QMessageBox::warning(this, "Вес улья уменьшился", "Необходимо проверить состояние улья.");}
    if (!f) {QMessageBox::information(this, "Information", "Нарушений нет");}
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ontimeout()
{
    ui->label->setText(QTime::currentTime().toString());
}

void MainWindow::diff(int a){

    tmin = temper[99];
    tmax = temper[99];
    vmin = vlazhn[99];
    vmax = vlazhn[99];
    pmin = prives[99];
    pmax = prives[99];

    for(int i = 0; i<a; i++){
        if (temper[99 - a + i] > tmax) { tmax = temper[99 - a + i]; }
        if (temper[99 - a + i] < tmin) { tmin = temper[99 - a + i]; }
        if (vlazhn[99 - a + i] > vmax) { vmax = vlazhn[99 - a + i]; }
        if (vlazhn[99 - a + i] < vmin) { vmin = vlazhn[99 - a + i]; }
        if (prives[99 - a + i] > pmax) { pmax = prives[99 - a + i]; }
        if (prives[99 - a + i] < pmin) { pmin = prives[99 - a + i]; }
    }
    if (vmax > 95) {vmax = 95;}


    dates1.clear();
    temper1.clear();
    vlazhn1.clear();
    prives1.clear();
    for(int i = 0; i<a; i++){
        dates1.push_back(0);
        prives1.push_back(0);
        vlazhn1.push_back(0);
        temper1.push_back(0);
    }
    for(int i = 0; i<a; i++){
        temper1[i] = (temper[99 - a + i]);
        vlazhn1[i] = (vlazhn[99 - a + i]);
        prives1[i] = (prives[99 - a + i]);
        dates1[i] = (dates[100 - a + i]);
    }

    ui->widget->clearPlottables();
    ui->widget_2->clearPlottables();
    ui->widget_3->clearPlottables();

    ui->widget->xAxis->setRange(dates1[0] - 1, dates1[a - 1] + 1);
    ui->widget->yAxis->setRange(tmin-5, tmax+5);
    ui->widget->addGraph();
    ui->widget->graph(0)->addData(dates1, temper1);
    ui->widget->replot();

    ui->widget_2->xAxis->setRange(dates1[0] - 1, dates1[a - 1] + 1);
    ui->widget_2->yAxis->setRange(vmin-5, vmax+5);
    ui->widget_2->addGraph();
    ui->widget_2->graph(0)->addData(dates1, vlazhn1);
    ui->widget_2->replot();

    ui->widget_3->xAxis->setRange(dates1[0] - 1, dates1[a - 1] + 1);
    ui->widget_3->yAxis->setRange(pmin-5, pmax+5);
    ui->widget_3->addGraph();
    ui->widget_3->graph(0)->addData(dates1, prives1);
    ui->widget_3->replot();
}

void MainWindow::on_pushButton_2_clicked()
{
    diff(5);
}

void MainWindow::on_pushButton_3_clicked()
{
    diff(10);
}

void MainWindow::on_pushButton_4_clicked()
{
    diff(30);
}

void MainWindow::on_pushButton_5_clicked()
{
    diff(60);
}

void MainWindow::on_pushButton_6_clicked()
{
    diff(90);
}

