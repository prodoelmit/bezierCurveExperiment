#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	this->database = new Database;
	this->sectionScene = new SectionScene(database);
	database->addCurve();
	database->focusCurve(database->curveList().first());
	BezierCurve* curve = database->currentCurve();
	QWidget* mainWidget = new QWidget;
	QHBoxLayout* mainLayout = new QHBoxLayout;
	setCentralWidget(mainWidget);
	mainWidget->setLayout(mainLayout);
	QGraphicsView* view = new QGraphicsView(sectionScene);
//	view->setMouseTracking(true);
	mainLayout->addWidget(view);
}

MainWindow::~MainWindow()
{

}
