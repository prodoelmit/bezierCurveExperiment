#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QPointF>
#include "beziernode.h"
#include "beziercurve.h"
#include <QVector2D>
class Database : public QObject
{
	Q_OBJECT
public:
	explicit Database(QObject *parent = 0);
	BezierCurve* getCurve(BezierCurve::Purpose purpose);

signals:
	void curvesChanged();
	void nodeAdded(BezierNode* node);
public slots:
	void addPoint(BezierCurve::Purpose purpose, QPointF point);
private:
	BezierCurve* skinCurve;
	BezierCurve* frameCurve;
};

#endif // DATABASE_H
