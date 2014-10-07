#include "beziernode.h"

BezierNode::BezierNode(QPointF point, QObject *parent) :
	QObject(parent), QGraphicsItem()
{
	this->setFlags(ItemIsMovable | ItemIsFocusable);
	this->point = new QPointF(point);
	this->leftControlPoint = new QPointF(point);
	this->rightControlPoint = new QPointF(point);
	this->type = Symmetric;
	this->setAcceptHoverEvents(true);
	this->setAcceptedMouseButtons(Qt::LeftButton);
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
	qreal tolerance = 15;
	QPointF leftTop(point->x() - tolerance, point->y() + tolerance);
	QPointF rightBottom(point->x() + tolerance, point->y() - tolerance);
	return QRectF(leftTop,rightBottom);
}

void BezierNode::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
	if (hovered) {
		painter->setBrush(QBrush(QColor("black")));
	}
	painter->drawEllipse(*point,15,15);
	this->scene()->update();
}

void BezierNode::hoverEnterEvent(QGraphicsSceneHoverEvent * event) {
//	this->hovered = true;
	this->update();
}

QPainterPath BezierNode::shape() const {
	QPainterPath path;
	path.setFillRule(Qt::WindingFill);
	path.addEllipse(boundingRect());
	return path;
}

void BezierNode::mousePressEvent(QGraphicsSceneMouseEvent *event) {
	this->hovered = true;
	update();
}


