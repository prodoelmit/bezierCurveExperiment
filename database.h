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
public slots:
	void pointSelectedAt(QPointF clickPoint);
	void startDragging();
	void dragPoints(QPointF translation);
	void stopDragging();
	void cancelDragging();
	void addPoint(BezierCurve::Purpose purpose, QPointF point);
private:
	bool draggingEnabled;
	BezierCurve* skinCurve;
	BezierCurve* frameCurve;
	QList<QPointF*> selectedPoints;
	QList<QPointF*> backupPoints;
	QList<QPointF*> points;
};

#endif // DATABASE_H
