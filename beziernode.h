#ifndef BEZIERNODE_H
#define BEZIERNODE_H

#include <QObject>
#include <QPointF>
#include <QList>
class BezierNode : public QObject
{
    Q_OBJECT
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

private:
	QPointF* point;
	QPointF* leftControlPoint;
	QPointF* rightControlPoint;
	Type type;
};

#endif // BEZIERNODE_H
