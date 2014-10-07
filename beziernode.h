#ifndef BEZIERNODE_H
#define BEZIERNODE_H

#include <QObject>
#include <QPointF>
#include <QList>
#include <QGraphicsItem>
#include <QRectF>
#include <QPainter>
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

private:
	QPointF* point;
	QPointF* leftControlPoint;
	QPointF* rightControlPoint;
	Type type;
};

#endif // BEZIERNODE_H
