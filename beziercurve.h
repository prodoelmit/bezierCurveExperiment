#ifndef BEZIERCURVE_H
#define BEZIERCURVE_H

#include <QObject>
#include "database.h"
#include "beziernode.h"
#include "beziercontrolpoint.h"

class Database;

class BezierCurve : public QObject, public QGraphicsPathItem
{
	Q_OBJECT
	Q_INTERFACES(QGraphicsItem)
public:
	BezierCurve(Database* database, QObject *parent = 0);
	QList<BezierNode*> nodeList();
	Database* database();

	QRectF boundingRect();

	QPainterPath shape();
	void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
signals:
	void nodeAdd(BezierNode* node);
public slots:
	void updatePath();

	void appendNode(BezierNode* node);
private:
	QList<BezierNode*> m_nodeList;
	Database* m_database;

};

#endif // BEZIERCURVE_H
