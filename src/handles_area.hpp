/*
 * Copyright 2016 Analog Devices, Inc.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3, or (at your option)
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Radio; see the file LICENSE.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street,
 * Boston, MA 02110-1301, USA.
 */

#ifndef HANDLES_AREA_H
#define HANDLES_AREA_H

#include <QWidget>

class QPoint;
class PlotLineHandle;

class HandlesArea: public QWidget
{
	Q_OBJECT

public:
	HandlesArea(QWidget *parent);

Q_SIGNALS:
	void sizeChanged(QSize);

protected:
	void mousePressEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseReleaseEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void mouseMoveEvent(QMouseEvent *event) Q_DECL_OVERRIDE;
	void resizeEvent(QResizeEvent *event) Q_DECL_OVERRIDE;
	virtual void resizeMask(QSize) = 0;

protected:
	QWidget *canvas;
	PlotLineHandle *selectedItem;
	QPoint hotspot;
};

class VertHandlesArea: public HandlesArea
{
public:
	VertHandlesArea(QWidget *parent = 0);

	int topPadding();
	void setTopPadding(int);
	int bottomPadding();
	void setBottomPadding(int);
	int largestChildHeight();
	void setLargestChildHeight(int);

protected:
	void resizeMask(QSize) Q_DECL_OVERRIDE;

private:
	int top_padding;
	int bottom_padding;
	int largest_child_height;
};

class HorizHandlesArea: public HandlesArea
{
public:
	HorizHandlesArea(QWidget *parent = 0);

	int leftPadding();
	void setLeftPadding(int);
	int rightPadding();
	void setRightPadding(int);
	int largestChildWidth();
	void setLargestChildWidth(int);

protected:
	void resizeMask(QSize) Q_DECL_OVERRIDE;

private:
	int left_padding;
	int right_padding;
	int largest_child_width;
};

#endif // HANDLES_AREA_H
