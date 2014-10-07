#include "database.h"

Database::Database(QObject *parent) :
	QObject(parent)
{
	m_curveList = QList<BezierCurve*>();
}

QList<BezierCurve *> Database::curveList()
{
	return m_curveList;
}

BezierCurve *Database::currentCurve()
{
	return m_currentCurve;
}

void Database::addNode(BezierNode *node)
{
	emit nodeAdd(node);
}

void Database::addCurve()
{
	BezierCurve* curve = new BezierCurve(this);
	m_curveList.append(curve);
}

void Database::focusCurve(BezierCurve *curve)
{
	m_currentCurve = curve;
	emit curveFocus(m_currentCurve);
}

