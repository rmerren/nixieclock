#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QList>
#include <QMainWindow>
#include <QMouseEvent>
#include <QPixmap>
#include <QTimer>
#include <QTime>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void mouseDoubleClickEvent(QMouseEvent* event);

private:
    Ui::MainWindow *ui;
    QList<QPixmap> pixmaps;
    QTimer timer;
    int current_hour_10;
    int current_hour_1;
    int current_minute_10;
    int current_minute_1;
    int current_second_10;
    int current_second_1;
    bool is_full_screen;

private slots:
    void set_time();
    void toggle_full_screen();
};

#endif // MAINWINDOW_H
