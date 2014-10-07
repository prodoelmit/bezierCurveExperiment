#ifndef BEZIERCONTROLPOINT_H
#define BEZIERCONTROLPOINT_H

#include <QGraphicsItem>
#include <QPointF>
#include <beziernode.h>
#include <QPainterPath>
#include <QPainter>
#include <QRectF>

class BezierNode;
class BezierControlPoint : public QGraphicsItem
{
public:
	BezierControlPoint(QPointF point, BezierNode* parentNode = 0);
	BezierNode* parentNode();
	void setParentNode(BezierNode*);

	QPainterPath shape();
	QPointF point();
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	QRectF boundingRect() const;

private:
	QPointF m_point;
	BezierNode* m_parentNode;
};

#endif // BEZIERCONTROLPOINT_H
