#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "rectangle.h"
#include "cutting_task.h"

#include <QDebug>
#include <QRandomGenerator>
#include <vector>

void parse_QString_to_Rectangles(std::vector<Rectangle>& rectangles, QString str)
{
    QStringList pairs = str.split("; ");

    for (const QString& pair : pairs)
    {
        QStringList values = pair.split(" ");
        Rectangle tmp_rectangle (values[0].toInt(), values[1].toInt());
        rectangles.push_back(tmp_rectangle);
    }
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::print_rectangles(std::vector<Rectangle>& rectangles, int lenght_main, int width_main, int count_list)
{
    int height_scene = 100;
    int width_scene = 100;
    scene.clear();
    scene.setSceneRect(0, 0, height_scene, width_scene);
    QGraphicsRectItem *rect = scene.addRect(0, 0, width_main, lenght_main);
    rect->setBrush(Qt::NoBrush);
    rect->setPen(QPen(Qt::black));

    for (int i = 0; i < count_list; ++i)
    {
        QGraphicsRectItem *rect_first = scene.addRect(
            rectangles[i].x,
            rectangles[i].y,
            rectangles[i].is_rotated ? rectangles[i].get_length() : rectangles[i].get_width(),
            rectangles[i].is_rotated ? rectangles[i].get_width() : rectangles[i].get_length()
            );

        rect_first->setBrush(Qt::NoBrush);
        rect_first->setPen(QPen(Qt::black));
    }

    ui->graphicsView->setScene(&scene);
}

void MainWindow::on_pushButton_clicked()
{
    int count_list = ui->count_list->text().toInt();
    int lenght_main = ui->lenght_main_list->text().toInt();
    int width_main = ui->width_main_list->text().toInt();

    int count_of_manufactured = 0;

    std::vector<Rectangle> rectangles;

    parse_QString_to_Rectangles(rectangles, ui->params->text());

    calculate_coord_rectangles(rectangles, lenght_main, width_main, count_list, count_of_manufactured);

    qDebug() << count_of_manufactured;
    ui->label_8->setText(QString::number(count_of_manufactured));

    print_rectangles(rectangles, lenght_main, width_main, count_list);
}

void MainWindow::on_Button_test1_clicked()
{
    int count_list = 3;
    int lenght_main = 100;
    int width_main = 50;

    int count_of_manufactured = 0;

    std::vector<Rectangle> rectangles;

    parse_QString_to_Rectangles(rectangles, ui->test1_text->text());

    calculate_coord_rectangles(rectangles, lenght_main, width_main, count_list, count_of_manufactured);

    qDebug() << count_of_manufactured;
    ui->label_8->setText(QString::number(count_of_manufactured));

    print_rectangles(rectangles, lenght_main, width_main, count_list);
}

void MainWindow::on_Button_test2_clicked()
{
    int count_list = 4;
    int lenght_main = 100;
    int width_main = 50;

    int count_of_manufactured = 0;

    std::vector<Rectangle> rectangles;

    parse_QString_to_Rectangles(rectangles, ui->test2_text->text());

    calculate_coord_rectangles(rectangles, lenght_main, width_main, count_list, count_of_manufactured);

    qDebug() << count_of_manufactured;
    ui->label_8->setText(QString::number(count_of_manufactured));

    print_rectangles(rectangles, lenght_main, width_main, count_list);
}


void MainWindow::on_Button_test3_clicked()
{
    int count_list = 5;
    int lenght_main = 100;
    int width_main = 50;

    int count_of_manufactured = 0;

    std::vector<Rectangle> rectangles;

    parse_QString_to_Rectangles(rectangles, ui->test3_text->text());

    calculate_coord_rectangles(rectangles, lenght_main, width_main, count_list, count_of_manufactured);

    qDebug() << count_of_manufactured;
    ui->label_8->setText(QString::number(count_of_manufactured));

    print_rectangles(rectangles, lenght_main, width_main, count_list);
}


void MainWindow::on_Button_test4_clicked()
{
    int count_list = 7;
    int lenght_main = 100;
    int width_main = 50;

    std::vector<Rectangle> rectangles;

    int count_of_manufactured = 0;

    parse_QString_to_Rectangles(rectangles, ui->test4_text->text());

    calculate_coord_rectangles(rectangles, lenght_main, width_main, count_list, count_of_manufactured);

    qDebug() << count_of_manufactured;
    ui->label_8->setText(QString::number(count_of_manufactured));

    print_rectangles(rectangles, lenght_main, width_main, count_list);
}


void MainWindow::on_Button_test5_clicked()
{
    int count_list = 6;
    int lenght_main = 100;
    int width_main = 50;

    std::vector<Rectangle> rectangles;

    int count_of_manufactured = 0;

    parse_QString_to_Rectangles(rectangles, ui->test5_text->text());

    calculate_coord_rectangles(rectangles, lenght_main, width_main, count_list, count_of_manufactured);

    qDebug() << count_of_manufactured;
    ui->label_8->setText(QString::number(count_of_manufactured));

    print_rectangles(rectangles, lenght_main, width_main, count_list);
}