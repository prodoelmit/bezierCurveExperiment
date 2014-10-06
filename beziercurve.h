#ifndef BEZIERCURVE_H
#define BEZIERCURVE_H

#include <QObject>
#include "beziernode.h"
class BezierCurve : public QObject
{
	Q_OBJECT
public:
	explicit BezierCurve(QObject *parent = 0);
	enum Purpose {Skin, Frame};
	QList<BezierNode*> getNodeList();
	void removeNode(BezierNode* node);
	void appendNode(BezierNode* node);
signals:

public slots:

private:
	QList<BezierNode*> nodeList;

};

#endif // BEZIERCURVE_H
