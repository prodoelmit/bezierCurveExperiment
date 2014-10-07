#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "database.h"
#include "sectionscene.h"
#include "beziercurve.h"
#include <QLayout>
#include <QHBoxLayout>
#include <QGraphicsView>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
	Database* database;
	SectionScene* sectionScene;
};

#endif // MAINWINDOW_H
