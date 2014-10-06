#ifndef SECTIONVIEW_H
#define SECTIONVIEW_H

#include <QGraphicsView>
#include "database.h"
#include <QMouseEvent>
#include <QVector2D>
#include "beziercurve.h"
class SectionView : public QGraphicsView
{
	Q_OBJECT
public:
	explicit SectionView(Database* database, QWidget *parent = 0);

signals:

	void startDragging();
	void cancelDragging();
	void stopDragging();
	void draggedBy(QPointF point);
	void selectAt(QPointF point);

	void pointAdded(BezierCurve::Purpose purpose, QPointF point);
public slots:
	void repaint();

private:
	void mousePressEvent(QMouseEvent* e);
	void mouseMoveEvent(QMouseEvent* e);
	void mouseReleaseEvent(QMouseEvent* e);
	Database* database;
	QPointF startPoint;
	QPointF endPoint;
	QGraphicsScene* scene;
};

#endif // SECTIONVIEW_H
