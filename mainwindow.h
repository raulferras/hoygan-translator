#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ui_mainwindow.h"
#include "dicsionario.h"


class MainWindow : public QMainWindow, private Ui::MainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);

protected:
	Dicsionario dicsionario;
    void changeEvent(QEvent *e);
	void translate();

private slots:
	void on_pushButton_released();
};

#endif // MAINWINDOW_H
