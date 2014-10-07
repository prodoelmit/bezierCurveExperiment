#ifndef SECTIONVIEW_H
#define SECTIONVIEW_H

#include <QGraphicsScene>
#include "database.h"
#include <QMouseEvent>
#include <QVector2D>
#include "beziercurve.h"
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsView>
#include <QTransform>
class SectionScene : public QGraphicsScene
{
	Q_OBJECT
public:
	explicit SectionScene(Database* database, QObject *parent = 0);
	BezierCurve* currentCurve();
signals:

public slots:
	void focusCurve(BezierCurve* curve);
	void addNode(BezierNode* node);
private:
	void mousePressEvent(QGraphicsSceneMouseEvent* e);
	Database* database;
	BezierCurve* m_currentCurve;
};

#endif // SECTIONVIEW_H
