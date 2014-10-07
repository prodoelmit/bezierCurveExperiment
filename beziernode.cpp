#include "beziernode.h"

BezierNode::BezierNode(QPointF point, Type type) : QGraphicsItem()
{
	m_point = point;
	m_type = type;
	if (type == Symmetric) {
		BezierControlPoint* leftControlPoint = new BezierControlPoint(point - QPoint(30,0),this);
		BezierControlPoint* rightControlPoint = new BezierControlPoint(point + QPoint(30,0),this);
		setLeftControlPoint(leftControlPoint);
		setRightControlPoint(rightControlPoint);
	}
//	setFlags(ItemIsMovable);
}

void BezierNode::setPoint(QPointF point)
{
	m_point = point;
}

QPointF &BezierNode::point()
{
	return m_point;
}

void BezierNode::setLeftControlPoint(BezierControlPoint* leftControlPoint)
{
	m_leftControlPoint = leftControlPoint;
}

BezierControlPoint *BezierNode::leftControlPoint()
{
	return m_leftControlPoint;
}


void BezierNode::setRightControlPoint(BezierControlPoint* rightControlPoint)
{
	m_rightControlPoint = rightControlPoint;
}

BezierControlPoint *BezierNode::rightControlPoint()
{
	return m_rightControlPoint;
}

void BezierNode::setType(BezierNode::Type type)
{
	m_type = type;
}

BezierNode::Type BezierNode::type()
{
	return m_type;
}

QRectF BezierNode::boundingRect() const
{
	qreal size = 7;
	QPointF topLeft = m_point - QPointF(size,-size);
	QPointF bottomRight = m_point + QPointF(size, -size);
	return QRectF(topLeft,bottomRight);
}

void BezierNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawEllipse(boundingRect());
}

QPainterPath BezierNode::shape() const
{

	QPainterPath path;
	path.addEllipse(boundingRect());
}

//void BezierNode::mousePressEvent(QGraphicsSceneMouseEvent *event) {
//	QGraphicsItem::mousePressEvent(event);
//}

//void BezierNode::dragEnterEvent(QGraphicsSceneDragDropEvent *event) {
//	QGraphicsItem::dragEnterEvent(event);
//}

bool BezierNode::sceneEvent(QEvent *event) {

}


