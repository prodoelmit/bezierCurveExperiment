#include "sectionscene.h"

SectionScene::SectionScene(Database* database, QObject *parent) :
	QGraphicsScene(parent)
{
	this->database = database;
	QPainter* painter = new QPainter();
	this->setSceneRect(-100,-100,200,200);
	connect(database,SIGNAL(nodeAdded(BezierNode*)),this,SLOT(addNode(BezierNode*)));
	connect(this,SIGNAL(pointAdded(BezierCurve::Purpose,QPointF)),database,SLOT(addPoint(BezierCurve::Purpose,QPointF)));
	connect(this,SIGNAL(nodeAdded(BezierCurve::Purpose, QPointF)),database,SLOT(addPoint(BezierCurve::Purpose,QPointF)));
//
	addItem(new QGraphicsRectItem(QRectF(0,0,100,100)));
}

void SectionScene::mousePressEvent(QGraphicsSceneMouseEvent *e) {
	if (e->button() == Qt::LeftButton && e->modifiers() == Qt::ControlModifier) {
		emit nodeAdded(BezierCurve::Skin,e->scenePos());
	} else if (e->button() == Qt::LeftButton) {

		QGraphicsItem* node = this->itemAt(e->scenePos(),QTransform());
		if (node != NULL) {
			sendEvent(node,e);
		}
	}

}



void SectionScene::addNode(BezierNode *node) {
	addItem(node);
	update(-100,-100,200,200);
}


