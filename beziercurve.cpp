#include "beziercurve.h"

BezierCurve::BezierCurve(Database* database, QObject *parent) :
	QObject(parent), QGraphicsPathItem()
{
	m_database = database;
	m_nodeList = QList<BezierNode*>();
	connect(this,SIGNAL(nodeAdd(BezierNode*)), m_database, SLOT(addNode(BezierNode*)));
}

Database *BezierCurve::database()
{
	return m_database;
}

QRectF BezierCurve::boundingRect()
{
	QGraphicsPathItem::boundingRect();
}

QPainterPath BezierCurve::shape()
{
	QGraphicsPathItem::shape();
}

void BezierCurve::appendNode(BezierNode *node) {
	m_nodeList.append(node);
	emit nodeAdd(node);
}


QList<BezierNode*> BezierCurve::nodeList() {
	return m_nodeList;
}

void BezierCurve::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	QGraphicsPathItem::paint(painter, option, widget);
}

void BezierCurve::updatePath() {
	QPainterPath path;
	for (int i = 0; i < nodeList().size(); i++) {
		BezierNode* firstNode = nodeList().at(i);
		path.moveTo(firstNode->point());
		if (i < nodeList().size() - 1) {
			QPointF p1, p2, p3, p4;
			//p1
			p1 = firstNode->point();
			//p2
			BezierControlPoint* firstControlPoint = firstNode->rightControlPoint();
			if (firstControlPoint == NULL) {
				p2 = p1;
			} else {
				p2 = firstControlPoint->point();
			}
			//p4
			BezierNode* secondNode = nodeList().at(i+1);
			p4 = secondNode->point();
			//p3
			BezierControlPoint* secondControlPoint = secondNode->leftControlPoint();
			if (secondControlPoint == NULL) {
				p3 = p4;
			} else {
				p3 = secondControlPoint->point();
			}
			//drawing spline
			path.cubicTo(p2,p3,p4);
		}

	}
	this->setPath(path);
}
