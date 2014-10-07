#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	this->database = new Database;
	this->sectionScene = new SectionScene(database);
//	database->addPoint(BezierCurve::Skin, QPointF(0,0));
//	database->addPoint(BezierCurve::Skin, QPointF(1,1));
	QWidget* mainWidget = new QWidget;
	QHBoxLayout* mainLayout = new QHBoxLayout;
	setCentralWidget(mainWidget);
	mainWidget->setLayout(mainLayout);
	QGraphicsView* view = new QGraphicsView(sectionScene);
	mainLayout->addWidget(view);
}

MainWindow::~MainWindow()
{

}
