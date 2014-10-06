#include "sectionview.h"

SectionView::SectionView(Database* database, QWidget *parent) :
	QGraphicsView(parent)
{
	this->database = database;
	this->scene = new QGraphicsScene;
	connect(this,SIGNAL(selectAt(QPointF)),database,SLOT(pointSelectedAt(QPointF)));
	connect(this,SIGNAL(draggedBy(QPointF)),database,SLOT(dragPoints(QPointF)));
	connect(this,SIGNAL(startDragging()),database,SLOT(startDragging()));
	connect(this,SIGNAL(cancelDragging()),database,SLOT(cancelDragging()));
	connect(this,SIGNAL(stopDragging()),database,SLOT(stopDragging()));
	connect(database,SIGNAL(curvesChanged()),this,SLOT(repaint()));
	connect(this,SIGNAL(pointAdded(BezierCurve::Purpose,QPointF)),database,SLOT(addPoint(BezierCurve::Purpose,QPointF)));
}

void SectionView::mousePressEvent(QMouseEvent *e) {
	if (e->button() == Qt::LeftButton) {
		startPoint = e->localPos();
		emit selectAt(startPoint);
		emit startDragging();
	} else if (e->button() == Qt::RightButton) {
		startPoint = e->localPos();
		emit pointAdded(BezierCurve::Skin, startPoint);
		emit startDragging();
	}
}

void SectionView::mouseMoveEvent(QMouseEvent *e) {
	QPointF translation = e->localPos();
	emit draggedBy(translation);
}

void SectionView::mouseReleaseEvent(QMouseEvent *e) {
	qreal tolerance = 0.01;
	if (e->button() == Qt::LeftButton) {
		endPoint = e->localPos();
		QPointF delta = endPoint - startPoint;
		QVector2D vector(delta);
		if (vector.length() < tolerance) {
			emit cancelDragging();
		} else {
			emit stopDragging();
		}
	} else if (e->button() == Qt::RightButton) {
		endPoint = e->localPos();
		QPointF delta = endPoint - startPoint;
		QVector2D vector(delta);
		if (vector.length() < tolerance) {
			emit cancelDragging();
		} else {
			emit stopDragging();
		}
	}
	this->repaint();
}


void SectionView::repaint() {
	QPainter* painter = new QPainter();
	QPainterPath path;
	QList<BezierNode*> nodeList = database->getCurve(BezierCurve::Skin)->getNodeList();
	for (int i = 0; i < nodeList.size(); i++) {
		BezierNode* firstNode = nodeList[i];
		path.moveTo(firstNode->getPoint());
		if (i < nodeList.size() - 1) {
			BezierNode* secondNode = nodeList[i+1];
			path.cubicTo(firstNode->getRightControlPoint(),
						 secondNode->getLeftControlPoint(),
						 secondNode->getPoint());
		}
	}

	scene->clear();
	scene->addText("Hello world");
	scene->addPath(path);
	this->setScene(scene);
//	QGraphicsView view(scene);
//	view.show();
	this->render(painter);
//	this->centerOn(QPointF(0,0));

}



