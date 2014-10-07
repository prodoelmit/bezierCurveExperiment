#include "beziernode.h"

BezierNode::BezierNode(QPointF point, QObject *parent) :
	QObject(parent)
{
	this->point = new QPointF(point);
	this->leftControlPoint = new QPointF(point);
	this->rightControlPoint = new QPointF(point);
	this->type = Symmetric;
}

QPointF& BezierNode::getPoint(){
	return *(this->point);
}

QPointF& BezierNode::getLeftControlPoint() {
	return *(this->leftControlPoint);
}
QPointF& BezierNode::getRightControlPoint() {
	return *(this->rightControlPoint);
}

void BezierNode::setPoint(QPointF point){
	delete this->point;
	this->point = new QPointF(point);
}

void BezierNode::setLeftControlPoint(QPointF leftCP){
	delete this->leftControlPoint;
	this->leftControlPoint = new QPointF(leftCP);
}

void BezierNode::setRightControlPoint(QPointF rightCP){
	delete this->rightControlPoint;
	this->rightControlPoint = new QPointF(rightCP);
}

void BezierNode::setType(Type type){
	this->type = type;
}

BezierNode::Type BezierNode::getType(){
	return this->type;
}

QRectF BezierNode::boundingRect() const {
	return QRectF(0,0,5,5);
}

void BezierNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	painter->drawEllipse(QPoint(0,0),10,10);
	painter->drawEllipse(QPoint(50,50),5,5);
	painter->drawEllipse(*point,15,15);
}

