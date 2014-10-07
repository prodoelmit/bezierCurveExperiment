#include "beziercontrolpoint.h"

BezierControlPoint::BezierControlPoint(QPointF point, BezierNode* parentNode)
{
	m_point = point;
	m_parentNode = parentNode;
}

BezierNode* BezierControlPoint::parentNode()
{
	return m_parentNode;
}

void BezierControlPoint::setParentNode(BezierNode* parentNode)
{
	m_parentNode = parentNode;
}

QPainterPath BezierControlPoint::shape()
{
	QPainterPath path;
	path.addEllipse(boundingRect());
}

QPointF BezierControlPoint::point()
{
	return m_point;
}

void BezierControlPoint::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	painter->drawEllipse(boundingRect());
	painter->drawLine(parentNode()->point(),this->point());
}

QRectF BezierControlPoint::boundingRect() const
{
	qreal size = 5;
	QPointF topLeft(m_point - QPointF(size,-size));
	QPointF bottomRight(m_point + QPointF(size,-size));
	return QRectF(topLeft,bottomRight);
}



