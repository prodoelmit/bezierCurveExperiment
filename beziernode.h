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
class BezierNode : public QObject, public QGraphicsItem
{
    Q_OBJECT
	Q_INTERFACES(QGraphicsItem)
public:
	enum Type {Symmetric, Smooth, Angular};
	explicit BezierNode(QPointF point, QObject *parent = 0);
	QPointF& getPoint();
	QPointF& getLeftControlPoint();
	QPointF& getRightControlPoint();
	void setPoint(QPointF);
	void setLeftControlPoint(QPointF);
	void setRightControlPoint(QPointF);
	void setType(Type);
	Type getType();
	QRectF boundingRect() const;
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

	void hoverEnterEvent(QGraphicsSceneHoverEvent * event);
	QPainterPath shape() const;
	void mousePressEvent(QGraphicsSceneMouseEvent *event);
private:
	QPointF* point;
	QPointF* leftControlPoint;
	QPointF* rightControlPoint;
	Type type;
	bool selected = false;
	bool hovered = false;
};

#endif // BEZIERNODE_H
