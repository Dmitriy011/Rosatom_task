#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QHBoxLayout>
#include <QPushButton>

#include <vector>

#include "rectangle.h"
#include "cutting_task.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void on_pushButton_clicked();

    void print_rectangles(std::vector<Rectangle>&, int, int, int);
private slots:
    void on_Button_test5_clicked();

    void on_Button_test4_clicked();

    void on_Button_test3_clicked();

    void on_Button_test2_clicked();

    void on_Button_test1_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;

    QGraphicsScene scene; // Объявляем QGraphicsScene как член класса
    QGraphicsView *view;
};
#endif // MAINWINDOW_H
