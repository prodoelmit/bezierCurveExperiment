#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>
#include <QPointF>
#include "beziernode.h"
#include "beziercurve.h"
#include <QVector2D>
class BezierCurve;
class Database : public QObject
{
	Q_OBJECT
public:
	explicit Database(QObject *parent = 0);
	QList<BezierCurve*> curveList();
	BezierCurve* currentCurve();
signals:
	void curveFocus(BezierCurve* curve);
	void nodeAdd(BezierNode* node);
public slots:
	void addNode(BezierNode* node);
	void addCurve();
	void focusCurve(BezierCurve* curve);
private:
	QList<BezierCurve*> m_curveList;
	BezierCurve* m_currentCurve;
};

#endif // DATABASE_H
