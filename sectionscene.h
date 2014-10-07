#ifndef SECTIONVIEW_H
#define SECTIONVIEW_H

#include <QGraphicsScene>
#include "database.h"
#include <QMouseEvent>
#include <QVector2D>
#include "beziercurve.h"
#include <QGraphicsSceneMouseEvent>
class SectionScene : public QGraphicsScene
{
	Q_OBJECT
public:
	explicit SectionScene(Database* database, QObject *parent = 0);

signals:

	void startDragging();
	void cancelDragging();
	void stopDragging();
	void draggedBy(QPointF point);
	void selectAt(QPointF point);
	void nodeAdded(BezierCurve::Purpose purpose, QPointF point);
	void pointAdded(BezierCurve::Purpose purpose, QPointF point);
public slots:
	void addNode(BezierNode* node);

private:
	void mousePressEvent(QGraphicsSceneMouseEvent* e);
	void mouseMoveEvent(QMouseEvent* e);
	void mouseReleaseEvent(QMouseEvent* e);

	Database* database;
};

#endif // SECTIONVIEW_H
