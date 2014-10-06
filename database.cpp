#include "database.h"

Database::Database(QObject *parent) :
	QObject(parent)
{
	this->skinCurve = new BezierCurve;
	this->frameCurve = new BezierCurve;
//	BezierNode* firstNode = new BezierNode(QPointF(0,0));
//	skinCurve->appendNode(firstNode);
}

void Database::dragPoints(QPointF translation) {
	for (int i = 0; i < selectedPoints.size(); i++) {
		QPointF* point = selectedPoints[i];
		*point = *(backupPoints[i]) + translation;
	}
	emit curvesChanged();
}

void Database::pointSelectedAt(QPointF clickPoint) {
	qreal tolerance = 0.01;
	for (int i = 0; i < points.size(); i++) {
		QPointF* point = points[i];
		QPointF delta = clickPoint - *point;
		QVector2D vector(delta);
		if (vector.length() < tolerance) {
			this->selectedPoints.clear();
			this->selectedPoints.append(point);
			break;
		}
	}
}

void Database::startDragging() {
	backupPoints.clear();
	for (int i = 0; i < selectedPoints.size(); i++) {
		QPointF* backupPoint = new QPointF(*(selectedPoints[i]));
		backupPoints.append(backupPoint);
	}
	draggingEnabled = true;
}

void Database::stopDragging() {
	qDeleteAll(backupPoints);
	backupPoints.clear();
	selectedPoints.clear();
	draggingEnabled = false;
	emit curvesChanged();
}

void Database::cancelDragging() {
	for (int i = 0; i < selectedPoints.size(); i++) {
		*(selectedPoints[i]) = *(backupPoints[i]);
	}
//	qDeleteAll(backupPoints);
	backupPoints.clear();
	draggingEnabled = false;
	emit curvesChanged();
}

void Database::addPoint(BezierCurve::Purpose purpose, QPointF point) {
	BezierCurve* curve = this->getCurve(purpose);
	BezierNode* node = new BezierNode(point);
	curve->appendNode(node);
	this->selectedPoints.append(&(node->getRightControlPoint()));
	this->points.append(&(node->getPoint()));
	this->points.append(&(node->getLeftControlPoint()));
	this->points.append(&(node->getRightControlPoint()));
	emit curvesChanged();
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
