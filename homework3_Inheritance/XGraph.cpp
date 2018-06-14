//
// 基于FLTK 1.1.10的图形库基础版
// 图形类的实现
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
// Modified by ZhangHua @ 2015-11-09
// Modified by LiDongxu @ 2018-05-25
//
// 在Visual Studio 2017 下编写，由2010版解决方案“重定解决方案目标”升级得到
//
// 请同学们在此文件增加自定义图形类的实现代码。

#include "XGraph.h"

#include <FL/Fl.H>
//#include <FL/Fl_Window.H>
#include <FL/fl_draw.h>

void XShape::AddPoint(XPoint point)
{
	// 把点添加到点集
	points.push_back(point);
}

void XShape::SetPoint(int idx, XPoint point)
{
	// 修改点集中的指定点
	if (idx>=0 && idx<points.size())
	{
		points[idx] = point;
	}
}

void XShape::Draw()
{
	// 设置画笔的颜色
	fl_color(lineColor.ToInt());

	// 绘出图形
	DrawLines();

	// 恢复画笔的颜色
	XColor defaultColor;
	fl_color(defaultColor.ToInt());
}

XLine::XLine(XPoint p1, XPoint p2)
{
	// 把直线的两个点添加到点集中
	AddPoint(p1);
	AddPoint(p2);
}

void XLine::DrawLines()
{
	// 使用FLTK中的绘线函数画出直线
	fl_line(points[0].xx, points[0].yy, points[1].xx, points[1].yy);
}

XTriangle::XTriangle(XPoint p1, XPoint p2, XPoint p3)
{
	// 把三角形的三个关键点添加到点集中
	AddPoint(p1);
	AddPoint(p2);
	AddPoint(p3);
}

void XTriangle::DrawLines()
{
	// 使用FLTK中的多边形绘制函数画出三角形
	fl_polygon(points[0].xx,points[0].yy , points[1].xx,points[1].yy , points[2].xx,points[2].yy);
}

XRectangle::XRectangle(XPoint p1, XPoint p2)
{
	//把矩形的两个关键点添加到点集中
	AddPoint(p1);
	AddPoint(p2);
}

void XRectangle::DrawLines()
{
	// 使用FLTK中的多边形绘制函数画出矩形
	fl_polygon(points[0].xx,points[0].yy , points[0].xx,points[1].yy , points[1].xx,points[1].yy , points[1].xx,points[0].yy);
}

XPolygon::XPolygon(const vector<XPoint> &input_points)
{
	points=input_points;  //引用外部的向量，赋值给类属性中的向量
}

void XPolygon::DrawLines()
{
	// 使用FLTK中的多边形绘制函数画出矩形
	fl_begin_polygon();
	for(int i=0;i<=points.size()-1;i++)
	{
		fl_vertex(points[i].xx,points[i].yy);
	}
	fl_end_polygon();
}

XCircle::XCircle(XPoint p1, int r1)
{
	AddPoint(p1);
	Xradius = r1;
}

void XCircle::DrawLines()
{
	fl_circle(points[0].xx, points[0].yy, Xradius);
}
