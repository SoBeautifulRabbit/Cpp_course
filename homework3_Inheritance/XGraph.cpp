//
// ����FLTK 1.1.10��ͼ�ο������
// ͼ�����ʵ��
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
// Modified by ZhangHua @ 2015-11-09
// Modified by LiDongxu @ 2018-05-25
//
// ��Visual Studio 2017 �±�д����2010�����������ض��������Ŀ�ꡱ�����õ�
//
// ��ͬѧ���ڴ��ļ������Զ���ͼ�����ʵ�ִ��롣

#include "XGraph.h"

#include <FL/Fl.H>
//#include <FL/Fl_Window.H>
#include <FL/fl_draw.h>

void XShape::AddPoint(XPoint point)
{
	// �ѵ���ӵ��㼯
	points.push_back(point);
}

void XShape::SetPoint(int idx, XPoint point)
{
	// �޸ĵ㼯�е�ָ����
	if (idx>=0 && idx<points.size())
	{
		points[idx] = point;
	}
}

void XShape::Draw()
{
	// ���û��ʵ���ɫ
	fl_color(lineColor.ToInt());

	// ���ͼ��
	DrawLines();

	// �ָ����ʵ���ɫ
	XColor defaultColor;
	fl_color(defaultColor.ToInt());
}

XLine::XLine(XPoint p1, XPoint p2)
{
	// ��ֱ�ߵ���������ӵ��㼯��
	AddPoint(p1);
	AddPoint(p2);
}

void XLine::DrawLines()
{
	// ʹ��FLTK�еĻ��ߺ�������ֱ��
	fl_line(points[0].xx, points[0].yy, points[1].xx, points[1].yy);
}

XTriangle::XTriangle(XPoint p1, XPoint p2, XPoint p3)
{
	// �������ε������ؼ�����ӵ��㼯��
	AddPoint(p1);
	AddPoint(p2);
	AddPoint(p3);
}

void XTriangle::DrawLines()
{
	// ʹ��FLTK�еĶ���λ��ƺ�������������
	fl_polygon(points[0].xx,points[0].yy , points[1].xx,points[1].yy , points[2].xx,points[2].yy);
}

XRectangle::XRectangle(XPoint p1, XPoint p2)
{
	//�Ѿ��ε������ؼ�����ӵ��㼯��
	AddPoint(p1);
	AddPoint(p2);
}

void XRectangle::DrawLines()
{
	// ʹ��FLTK�еĶ���λ��ƺ�����������
	fl_polygon(points[0].xx,points[0].yy , points[0].xx,points[1].yy , points[1].xx,points[1].yy , points[1].xx,points[0].yy);
}

XPolygon::XPolygon(const vector<XPoint> &input_points)
{
	points=input_points;  //�����ⲿ����������ֵ���������е�����
}

void XPolygon::DrawLines()
{
	// ʹ��FLTK�еĶ���λ��ƺ�����������
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
