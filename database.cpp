#include "database.h"

Database::Database(QObject *parent) :
	QObject(parent)
{
	this->skinCurve = new BezierCurve;
	this->frameCurve = new BezierCurve;
//	BezierNode* firstNode = new BezierNode(QPointF(0,0));
//	skinCurve->appendNode(firstNode);
}


void Database::addPoint(BezierCurve::Purpose purpose, QPointF point) {
	BezierCurve* curve = this->getCurve(purpose);
	BezierNode* node = new BezierNode(point);
	curve->appendNode(node);
	emit nodeAdded(node);
//	this->selectedPoints.append(&(node->getRightControlPoint()));
//	this->points.append(&(node->getPoint()));
//	this->points.append(&(node->getLeftControlPoint()));
//	this->points.append(&(node->getRightControlPoint()));
//	emit curvesChanged();
}

BezierCurve* Database::getCurve(BezierCurve::Purpose purpose) {
	BezierCurve* curve;
	switch (purpose) {
		case BezierCurve::Frame:
			curve = frameCurve;
			break;
		case BezierCurve::Skin:
			curve = skinCurve;
			break;
	}
	return curve;
}
