#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(0, 0, BOARD_WIDTH, BOARD_HEIGHT, this);
    scene->setBackgroundBrush(QBrush(QColor("#1e1e2e")));
    view = new QGraphicsView(scene, this);

    view->setFixedSize(BOARD_WIDTH + 5, BOARD_HEIGHT + 5);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setCentralWidget(view);
    setWindowTitle("Snake Game - C++ & Qt");
    setFixedSize(BOARD_WIDTH + 20, BOARD_HEIGHT + 20);

    currentDirection = Direction::RIGHT;
    initSnake();

    spawnApple();

    gameTimer = new QTimer(this);
    connect(gameTimer, &QTimer::timeout, this, &MainWindow::moveSnake);
    gameTimer->start(150);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initSnake()
{
    int startX = 100;
    int startY = 100;

    for (int i = 0; i < 3; ++i) {
        QGraphicsRectItem *segment = scene->addRect(0, 0, GRID_SIZE - 1, GRID_SIZE - 1,
                                                    QPen(Qt::NoPen),
                                                    QBrush(QColor(166, 227, 161)));

        segment->setPos(startX - (i * GRID_SIZE), startY);

        snake.append(segment);
    }
}

void MainWindow::moveSnake()
{
    if (snake.isEmpty()) return;

    QPointF headPos = snake.first()->pos();
    qreal newX = headPos.x();
    qreal newY = headPos.y();

    switch (currentDirection) {
    case Direction::UP:    newY -= GRID_SIZE; break;
    case Direction::DOWN:  newY += GRID_SIZE; break;
    case Direction::LEFT:  newX -= GRID_SIZE; break;
    case Direction::RIGHT: newX += GRID_SIZE; break;
    }

    if (newX < 0 || newX >= BOARD_WIDTH || newY < 0 || newY >= BOARD_HEIGHT) {
        gameOver();
        return;
    }

    for (int i = 0; i < snake.size(); ++i) {
        if (snake[i]->pos() == QPointF(newX, newY)) {
            gameOver();
            return;
        }
    }

    if (apple && apple->pos() == QPointF(newX, newY)) {

        QGraphicsRectItem *newSegment = scene->addRect(0, 0, GRID_SIZE - 1, GRID_SIZE - 1,
                                                       QPen(Qt::NoPen),
                                                       QBrush(QColor(166, 227, 161)));

        newSegment->setPos(snake.last()->pos());
        snake.append(newSegment);

        score += 10;
        setWindowTitle(QString("Snake Game - Wynik: %1").arg(score));
        spawnApple();
    }

    for (int i = snake.size() - 1; i > 0; --i) {
        snake[i]->setPos(snake[i - 1]->pos());
    }
    snake.first()->setPos(newX, newY);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
    case Qt::Key_W:
        if (currentDirection != Direction::DOWN)
            currentDirection = Direction::UP;
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        if (currentDirection != Direction::UP)
            currentDirection = Direction::DOWN;
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        if (currentDirection != Direction::RIGHT)
            currentDirection = Direction::LEFT;
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        if (currentDirection != Direction::LEFT)
            currentDirection = Direction::RIGHT;
        break;
    default:
        QMainWindow::keyPressEvent(event);
        break;
    }
}

void MainWindow::spawnApple()
{
    int maxGridX = BOARD_WIDTH / GRID_SIZE;
    int maxGridY = BOARD_HEIGHT / GRID_SIZE;

    int randomX = QRandomGenerator::global()->bounded(maxGridX) * GRID_SIZE;
    int randomY = QRandomGenerator::global()->bounded(maxGridY) * GRID_SIZE;

    if (!apple) {
        apple = scene->addRect(0, 0, GRID_SIZE - 1, GRID_SIZE - 1,
                               QPen(Qt::NoPen),
                               QBrush(QColor(243, 139, 168)));
    }

    apple->setPos(randomX, randomY);
}

void MainWindow::gameOver()
{
    gameTimer->stop();

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Koniec Gry!");
    msgBox.setText(QString("Przegrałeś!\nTwój wynik to: %1 punktów.").arg(score));
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();

    close();
}