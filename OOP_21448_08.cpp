#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>

QImage img(500, 500, QImage::Format_RGB888);

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap::fromImage(img));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    int i;
    i = ui->textEdit->toPlainText().toInt();
    kochCurve(250, 150, 336.5, 300, i);
    kochCurve(163.5, 300, 250, 150, i);
    kochCurve(336.5, 300, 163.5, 300, i);

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::dda(float x1, float y1, float x2, float y2)
{
    float dx, dy, length, xinc, yinc;

    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
        length = abs(dx);

    else
    {
        length = abs(dy);
    }
    xinc = dx / length;
    yinc = dy / length;
    int i = 0;
    float x = x1;
    float y = y1;
    while (i <= length)
    {
        img.setPixel(x, y, qRgb(255, 255, 255));
        x = x + xinc;
        y = y + yinc;
        i++;
    }

    ui->label->setPixmap(QPixmap::fromImage(img));
}

void MainWindow::kochCurve(int x1, int y1, int x2, int y2, int iterations)
{
    if (iterations == 0)
    {
        dda(x1, y1, x2, y2);
    }
    else
    {
        float x3, y3, x4, y4;
        x3 = (2 * x1 + x2) / 3;
        y3 = (2 * y1 + y2) / 3;
        x4 = (2 * x2 + x1) / 3;
        y4 = (2 * y2 + y1) / 3;
        float theta = 3.14 / 3;
        float x, y;
        x = x3 + (x4 - x3) * cos(theta) + (y4 - y3) * sin(theta);
        y = y3 - (x4 - x3) * sin(theta) + (y4 - y3) * cos(theta);

        kochCurve(x1, y1, x3, y3, iterations - 1);
        kochCurve(x3, y3, x, y, iterations - 1);
        kochCurve(x, y, x4, y4, iterations - 1);
        kochCurve(x4, y4, x2, y2, iterations - 1);
    }
}