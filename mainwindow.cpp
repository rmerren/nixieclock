#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    pixmaps.append(QPixmap(":/nixie/Nixie_0"));
    pixmaps.append(QPixmap(":/nixie/Nixie_1"));
    pixmaps.append(QPixmap(":/nixie/Nixie_2"));
    pixmaps.append(QPixmap(":/nixie/Nixie_3"));
    pixmaps.append(QPixmap(":/nixie/Nixie_4"));
    pixmaps.append(QPixmap(":/nixie/Nixie_5"));
    pixmaps.append(QPixmap(":/nixie/Nixie_6"));
    pixmaps.append(QPixmap(":/nixie/Nixie_7"));
    pixmaps.append(QPixmap(":/nixie/Nixie_8"));
    pixmaps.append(QPixmap(":/nixie/Nixie_9"));

    timer.start(100);
    set_time();
    connect(&timer,SIGNAL(timeout()),this,SLOT(set_time()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::set_time()
{
    QTime time = QTime::currentTime();

    int new_hour = time.hour();
    int new_minute = time.minute();
    int new_second = time.second();

    int new_hour_10 = new_hour / 10;
    int new_hour_1 = new_hour % 10;
    int new_minute_10 = new_minute / 10;
    int new_minute_1 = new_minute % 10;
    int new_second_10 = new_second / 10;
    int new_second_1 = new_second % 10;

    if (new_hour_10 != current_hour_10) {
        current_hour_10 = new_hour_10;
        ui->label_hour_10->setPixmap(pixmaps[new_hour_10]);
    }

    if (new_hour_1 != current_hour_1) {
        current_hour_1 = new_hour_1;
        ui->label_hour_1->setPixmap(pixmaps[new_hour_1]);
    }

    if (new_minute_10 != current_minute_10) {
        current_minute_10 = new_minute_10;
        ui->label_minute_10->setPixmap(pixmaps[new_minute_10]);
    }

    if (new_minute_1 != current_minute_1) {
        current_minute_1 = new_minute_1;
        ui->label_minute_1->setPixmap(pixmaps[new_minute_1]);
    }

    if (new_second_10 != current_second_10) {
        current_second_10 = new_second_10;
        ui->label_second_10->setPixmap(pixmaps[new_second_10]);
    }

    if (new_second_1 != current_second_1) {
        current_second_1 = new_second_1;
        ui->label_second_1->setPixmap(pixmaps[new_second_1]);
    }

}
