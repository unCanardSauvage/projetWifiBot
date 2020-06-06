#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include <QWidget>
#include <QMainWindow>
#include "mainwindow.h"
#include "QGraphicsView"

namespace Ui {
class MenuPrincipal;
}

class MenuPrincipal : public QWidget
{
    Q_OBJECT

public:
    explicit MenuPrincipal(QWidget *parent = nullptr);
    ~MenuPrincipal();

private:
    Ui::MenuPrincipal *ui;
    MainWindow mainwindow;

private slots:
    void jouer();
    void quitter();
};

#endif // MENUPRINCIPAL_H
