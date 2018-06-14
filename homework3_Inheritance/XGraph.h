//
// 基于FLTK 1.1.10的图形库基础版
// 图形类
// XPoint（点）
// XShape（形状）
//   XLine（直线）
// XColor（颜色）
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
// Modified by ZhangHua @ 2015-11-09
// Modified by LiDongxu @ 2018-05-25
//
// 在Visual Studio 2017 下编写，由2010版解决方案“重定解决方案目标”升级得到
//
// 请同学们在此文件增加自己的图形类。

#ifndef _XGRAPH_H_
#define _XGRAPH_H_

#include <vector>
using namespace std;

#include "FL/fl_draw.h"

// 点
class XPoint
{
public:
	int xx, yy; // 点的坐标值

	XPoint(int x=0, int y=0) { xx=x; yy=y; }
};

// 颜色（重新包装FLTK中的颜色）
class XColor
{
private:
	Fl_Color cc; // 颜色值

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

// 形状
class XShape
{
private:
	XColor lineColor; // 线段颜色

protected:
	vector<XPoint> points; // 点集  vector可以视为一种动态数组。<>中是一个向量中保存的数据类型。

public:
	XShape() : lineColor() {}  //构造函数

	// 添加点
	void AddPoint(XPoint point);
	// 修改某一点的值
	void SetPoint(int idx, XPoint point);
	// 设置线段颜色
	void SetLineColor(XColor c) { lineColor = c; }
	// 绘制图形（包括设置画笔颜色、绘出线段、恢复画笔的颜色）
	void Draw();

protected:
	// 绘制某一种具体图形（只有具体的类才能实现）
	// 注意：这是一个纯虚函数，在每一个非抽象子类中必须重新声明和定义此函数！
	virtual void DrawLines() = 0;  //这个函数是被draw(0)函数调用的
};

// 直线
class XLine : public XShape
{
public:
	// 直线包括两个点
	XLine(XPoint p1=XPoint(0, 0), XPoint p2=XPoint(0, 0));  //构造函数

	// 绘出直线
	void DrawLines();
};

class XTriangle : public XShape
{
public:
	//三角形包括三个关键点
	XTriangle(XPoint p1=XPoint(0,0), XPoint p2=XPoint(0,0), XPoint p3=XPoint(0,0)); //构造函数

	//绘出三角形
	void DrawLines();
};

class XRectangle : public XShape
{
public:
	//矩形包括两个关键点
	XRectangle(XPoint p1=XPoint(0,0), XPoint p2=XPoint(0,0)); //构造函数

	//绘出矩形
	void DrawLines();
};

class XPolygon : public XShape
{
public:
	//矩形包括多个关键点
	XPolygon(const vector<XPoint> &input_points); //构造函数

	//绘出矩形
	void DrawLines();
};

class XCircle : public XShape
{
private:
	int Xradius;
public:
	//圆包括1个关键点和1个半径参数
	XCircle(XPoint p1 = XPoint(0, 0), int r1 = 0); //构造函数

	//绘出图形
	void DrawLines();
};

#endif