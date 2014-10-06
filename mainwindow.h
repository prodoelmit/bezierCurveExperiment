#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "sectionview.h"
#include "database.h"
#include <QLayout>
#include <QHBoxLayout>
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
private:
	Database* database;
	SectionView* sectionView;
};

#endif // MAINWINDOW_H
