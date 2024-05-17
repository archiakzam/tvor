#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>
#include <QVector>
#include <QtSql>
#include <QSqlDatabase>
#include <QMessageBox>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void createVectors();

    QVector<double> dates;

//    QVector<double> temper = {3, 4};

//    QVector<double> vlazhn = {3, 5};

//    QVector<double> prives = {3, 5};

    QVector<double> temper = {32, 34, 30, 34, 29 ,28, 31, 33, 30, 28,
                             32, 34, 30, 34, 29 ,28, 31, 33, 30, 28,
                             32, 34, 30, 34, 29 ,28, 31, 33, 30, 28,
                             32, 34, 30, 34, 29 ,28, 31, 33, 30, 28,
                             32, 34, 30, 34, 29 ,28, 31, 33, 30, 28,
                             32, 34, 30, 34, 29 ,28, 31, 33, 30, 28,
                             32, 34, 30, 34, 29 ,28, 31, 33, 30, 28,
                             32, 34, 30, 34, 29 ,28, 31, 33, 30, 28,
                             32, 34, 30, 34, 29 ,28, 31, 33, 30, 28,
                              32, 34, 30, 34, 29 ,28, 31, 33, 30, 28
                             };


    QVector<double> vlazhn = {98, 95 ,92, 99, 94 ,96, 95, 91, 93, 99,
                              98, 95 ,92, 99, 94 ,96, 95, 91, 93, 99,
                              98, 95 ,92, 99, 94 ,96, 95, 91, 93, 99,
                              98, 95 ,92, 99, 94 ,96, 95, 91, 93, 99,
                              98, 95 ,92, 99, 94 ,96, 95, 91, 93, 99,
                              98, 95 ,92, 99, 94 ,96, 95, 91, 93, 99,
                              98, 95 ,92, 99, 94 ,96, 95, 91, 93, 99,
                              98, 95 ,92, 99, 94 ,96, 95, 91, 93, 99,
                              98, 95 ,92, 99, 94 ,96, 95, 91, 93, 99,
                              98, 95 ,92, 99, 94 ,96, 95, 91, 93, 99
                             };



    QVector<double> prives = {32, 32.25 ,32.6, 33, 33.29 ,33.7, 34.1, 34.24, 34.5, 35,
                              32, 32.25 ,32.6, 33, 33.29 ,33.7, 34.1, 34.24, 34.5, 35,
                              32, 32.25 ,32.6, 33, 33.29 ,33.7, 34.1, 34.24, 34.5, 35,
                              32, 32.25 ,32.6, 33, 33.29 ,33.7, 34.1, 34.24, 34.5, 35,
                              32, 32.25 ,32.6, 33, 33.29 ,33.7, 34.1, 34.24, 34.5, 35,
                              32, 32.25 ,32.6, 33, 33.29 ,33.7, 34.1, 34.24, 34.5, 35,
                              32, 32.25 ,32.6, 33, 33.29 ,33.7, 34.1, 34.24, 34.5, 35,
                              32, 32.25 ,32.6, 33, 33.29 ,33.7, 34.1, 34.24, 34.5, 35,
                              32, 32.25 ,32.6, 33, 33.29 ,33.7, 34.1, 34.24, 34.5, 35,
                              32, 32.25 ,32.6, 33, 33.29 ,33.7, 34.1, 34.24, 34.5, 35

                             };

    QVector<double> temper1;
    QVector<double> vlazhn1;
    QVector<double> prives1;
    QVector<double> dates1;

    bool f = false;
    int num1, num2, number; // переменные для начальной и конечной даты в графиках
    double tmax, tmin, vmax, vmin, pmax, pmin; // Для макс и мин значений векторов данных


/////////////////////////////

/////////////////////////////


public slots:
    void ontimeout();
    void diff(int d);

private slots:
    void on_pushButton_clicked();


    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();
    void on_pushButton_4_clicked();
    void on_pushButton_5_clicked();
    void on_pushButton_6_clicked();
};
#endif // MAINWINDOW_H
