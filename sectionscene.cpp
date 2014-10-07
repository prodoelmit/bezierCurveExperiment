#include "sectionscene.h"

SectionScene::SectionScene(Database* database, QObject *parent) :
	QGraphicsScene(parent)
{
	this->database = database;
	QPainter* painter = new QPainter();
	connect(this,SIGNAL(selectAt(QPointF)),database,SLOT(pointSelectedAt(QPointF)));
	connect(this,SIGNAL(draggedBy(QPointF)),database,SLOT(dragPoints(QPointF)));
	connect(this,SIGNAL(startDragging()),database,SLOT(startDragging()));
	connect(this,SIGNAL(cancelDragging()),database,SLOT(cancelDragging()));
	connect(this,SIGNAL(stopDragging()),database,SLOT(stopDragging()));
	connect(database,SIGNAL(nodeAdded(BezierNode*)),this,SLOT(addNode(BezierNode*)));
	connect(this,SIGNAL(pointAdded(BezierCurve::Purpose,QPointF)),database,SLOT(addPoint(BezierCurve::Purpose,QPointF)));
	connect(this,SIGNAL(nodeAdded(BezierCurve::Purpose, QPointF)),database,SLOT(addPoint(BezierCurve::Purpose,QPointF)));
}

void SectionScene::mousePressEvent(QGraphicsSceneMouseEvent *e) {
	if (e->button() == Qt::LeftButton && e->modifiers() == Qt::ControlModifier) {
		emit nodeAdded(BezierCurve::Skin,e->scenePos());
	} else if (e->button() == Qt::RightButton) {

	}
}

void SectionScene::mouseMoveEvent(QMouseEvent *e) {

}

void SectionScene::mouseReleaseEvent(QMouseEvent *e) {

}


void SectionScene::addNode(BezierNode *node) {
	addItem(node);
	update();
}
