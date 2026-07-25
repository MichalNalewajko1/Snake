#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QTimer>
#include <QKeyEvent>
#include <QList>
#include <QRandomGenerator>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

enum class Direction { UP, DOWN, LEFT, RIGHT };

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

protected:
    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void moveSnake();
private:
    Ui::MainWindow *ui;

    QGraphicsScene *scene;
    QGraphicsView *view;

    const int BOARD_WIDTH = 600;
    const int BOARD_HEIGHT = 600;
    const int GRID_SIZE = 20;

    QList<QGraphicsRectItem*> snake;
    QGraphicsRectItem *apple = nullptr;

    Direction currentDirection;
    QTimer *gameTimer;

    int score = 0;

    void initSnake();

    void spawnApple();
    void gameOver();
};
#endif // MAINWINDOW_H
