/*******************************************************************

Part of the Fritzing project - http://fritzing.org
Copyright (c) 2007-2019 Fritzing

Fritzing is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Fritzing is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Fritzing.  If not, see <http://www.gnu.org/licenses/>.

********************************************************************/

#ifndef ZOOMABLEGRAPHICSVIEW_H
#define ZOOMABLEGRAPHICSVIEW_H

#include <QGraphicsView>
#include <QMenu>
#include <QHash>
#include <QList>
#include <QPinchGesture>


class ZoomableGraphicsView : public QGraphicsView
{
	Q_OBJECT

public:
	ZoomableGraphicsView(QWidget* parent = 0);

	void relativeZoom(double step, bool centerToCursor);
	void absoluteZoom(double percent);
	double currentZoom();
	void setAcceptWheelEvents(bool);
	virtual void ensureFixedToBottomRightItems() {}
	bool viewFromBelow();
	virtual void setViewFromBelow(bool);

	static const int MaxScaleValue;

public:
	enum WheelMapping {
		ScrollPrimary,
		ZoomPrimary,
		Guess,
		Pure,
		WheelMappingCount
	};

	static WheelMapping wheelMapping();
	static void setWheelMapping(WheelMapping);
	bool event(QEvent *event);

Q_SIGNALS:
	void zoomChanged(double zoom);
	void zoomOutOfRange(double zoom);

protected:
	virtual void wheelEvent(QWheelEvent* event);
	bool gestureEvent(QGestureEvent *event);
	void pinchTriggered(QPinchGesture *gesture);

protected:
	double m_scaleValue;
	int m_maxScaleValue;
	int m_minScaleValue;
	bool m_acceptWheelEvents;
	qint64 m_guessTouchpadId;
	bool m_viewFromBelow;

protected:
	static WheelMapping m_wheelMapping;
};

#endif
