#include "sectionscene.h"

SectionScene::SectionScene(Database* database, QObject *parent) :
	QGraphicsScene(parent)
{
	this->database = database;
	this->setSceneRect(-100,-100,200,200);
	connect(database,SIGNAL(curveFocus(BezierCurve*)),this,SLOT(focusCurve(BezierCurve*)));
	connect(database,SIGNAL(nodeAdd(BezierNode*)),this,SLOT(addNode(BezierNode*)));
	QPainter* painter = new QPainter();
	addItem(new QGraphicsRectItem(QRectF(0,0,100,100)));
}

BezierCurve *SectionScene::currentCurve()
{
	return m_currentCurve;
}

void SectionScene::focusCurve(BezierCurve *curve)
{
	m_currentCurve = curve;
}

void SectionScene::addNode(BezierNode *node)
{
	addItem(node);
	if (node->leftControlPoint()) addItem(node->leftControlPoint());
	if (node->rightControlPoint()) addItem(node->rightControlPoint());
	update();
}

void SectionScene::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
	if (e->button() == Qt::LeftButton && e->modifiers() == Qt::ControlModifier) {
		BezierNode* node = new BezierNode(e->scenePos());
		currentCurve()->appendNode(node);

	} else {
		if (items(e->scenePos()).size()) {
			QGraphicsScene::mousePressEvent(e);
		}
	}
}



