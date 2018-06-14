//
// ����FLTK 1.1.10��ͼ�ο������
// ͼ����
// XPoint���㣩
// XShape����״��
//   XLine��ֱ�ߣ�
// XColor����ɫ��
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
// Modified by ZhangHua @ 2015-11-09
// Modified by LiDongxu @ 2018-05-25
//
// ��Visual Studio 2017 �±�д����2010�����������ض��������Ŀ�ꡱ�����õ�
//
// ��ͬѧ���ڴ��ļ������Լ���ͼ���ࡣ

#ifndef _XGRAPH_H_
#define _XGRAPH_H_

#include <vector>
using namespace std;

#include "FL/fl_draw.h"

// ��
class XPoint
{
public:
	int xx, yy; // �������ֵ

	XPoint(int x=0, int y=0) { xx=x; yy=y; }
};

// ��ɫ�����°�װFLTK�е���ɫ��
class XColor
{
private:
	Fl_Color cc; // ��ɫֵ

public:
	enum XColorType
	{
		XCOLOR_RED = FL_RED,
		XCOLOR_GREEN = FL_GREEN,
		XCOLOR_BLUE = FL_BLUE,
		XCOLOR_YELLOW = FL_YELLOW,
		XCOLOR_WHITE = FL_WHITE,
		XCOLOR_BLACK = FL_BLACK
	};

	XColor(XColorType c=XCOLOR_RED) : cc(Fl_Color(c)) { }

	int ToInt() { return cc; }
};

// ��״
class XShape
{
private:
	XColor lineColor; // �߶���ɫ

protected:
	vector<XPoint> points; // �㼯  vector������Ϊһ�ֶ�̬���顣<>����һ�������б�����������͡�

public:
	XShape() : lineColor() {}  //���캯��

	// ��ӵ�
	void AddPoint(XPoint point);
	// �޸�ĳһ���ֵ
	void SetPoint(int idx, XPoint point);
	// �����߶���ɫ
	void SetLineColor(XColor c) { lineColor = c; }
	// ����ͼ�Σ��������û�����ɫ������߶Ρ��ָ����ʵ���ɫ��
	void Draw();

protected:
	// ����ĳһ�־���ͼ�Σ�ֻ�о���������ʵ�֣�
	// ע�⣺����һ�����麯������ÿһ���ǳ��������б������������Ͷ���˺�����
	virtual void DrawLines() = 0;  //��������Ǳ�draw(0)�������õ�
};

// ֱ��
class XLine : public XShape
{
public:
	// ֱ�߰���������
	XLine(XPoint p1=XPoint(0, 0), XPoint p2=XPoint(0, 0));  //���캯��

	// ���ֱ��
	void DrawLines();
};

class XTriangle : public XShape
{
public:
	//�����ΰ��������ؼ���
	XTriangle(XPoint p1=XPoint(0,0), XPoint p2=XPoint(0,0), XPoint p3=XPoint(0,0)); //���캯��

	//���������
	void DrawLines();
};

class XRectangle : public XShape
{
public:
	//���ΰ��������ؼ���
	XRectangle(XPoint p1=XPoint(0,0), XPoint p2=XPoint(0,0)); //���캯��

	//�������
	void DrawLines();
};

class XPolygon : public XShape
{
public:
	//���ΰ�������ؼ���
	XPolygon(const vector<XPoint> &input_points); //���캯��

	//�������
	void DrawLines();
};

class XCircle : public XShape
{
private:
	int Xradius;
public:
	//Բ����1���ؼ����1���뾶����
	XCircle(XPoint p1 = XPoint(0, 0), int r1 = 0); //���캯��

	//���ͼ��
	void DrawLines();
};

#endif