#ifndef BEZIERNODE_H
#define BEZIERNODE_H

#include <QObject>
#include <QPointF>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
#include <QPainterPathStroker>
#include "beziercontrolpoint.h"
class BezierControlPoint;
class BezierNode : public QGraphicsItem
{
	Q_INTERFACES(QGraphicsItem)
public:
	enum Type {Symmetric, Smooth, Angular};
	BezierNode(QPointF point = QPointF(0,0), Type type = Symmetric);
	void setPoint(QPointF point);
	QPointF& point();
	void setLeftControlPoint(BezierControlPoint*);
	BezierControlPoint* leftControlPoint();
	void setRightControlPoint(BezierControlPoint*);
	BezierControlPoint* rightControlPoint();
	void setType(Type);
	Type type();

	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
	QPainterPath shape() const;



public slots:
//	void mousePressEvent(QGraphicsSceneMouseEvent *event);
	//	void dragEnterEvent(QGraphicsSceneDragDropEvent *event);
	bool sceneEvent(QEvent *event);
private:
	QPointF m_point;
	BezierControlPoint* m_leftControlPoint;
	BezierControlPoint* m_rightControlPoint;
	Type m_type;
	bool m_selected = false;
	bool m_hovered = false;
};

#endif // BEZIERNODE_H
