#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include <QMainWindow>
#include "QPushButton"
#include "mainwindow.h"

namespace Ui {
class Menu;
}

class Menu : public QWidget
{
    Q_OBJECT

public:
    explicit Menu(QWidget *parent = nullptr);
    ~Menu();

private:
    Ui::Menu *ui;
    //MainWindow mainWindow;

private slots:
    void jouer();
};

#endif // MENU_H
