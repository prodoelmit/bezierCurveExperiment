#include "beziercurve.h"

BezierCurve::BezierCurve(QObject *parent) :
	QObject(parent)
{
	this->nodeList = QList<BezierNode*>();
}

void BezierCurve::appendNode(BezierNode *node) {
	this->nodeList.append(node);
}


QList<BezierNode*> BezierCurve::getNodeList() {
	return this->nodeList;
}
