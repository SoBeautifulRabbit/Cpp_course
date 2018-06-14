//
// 基于FLTK 1.1.10的图形类库的测试程序
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
// Modified by LiDongxu @ 2018-05-25
//
// 在Visual Studio 2017 下编写，由2010版解决方案“重定解决方案目标”升级得到
//
// 请同学们在此文件中增加自己的动画脚本代码。

#include "XWindow.h"
#include <vector>
#include <cmath>

//inline void graph_a_house(int x, XInteractiveWindow &window);

int main(int argc, char **argv) {
	// 创建并显示交互式的绘图窗口
	XInteractiveWindow window(600, 400, "简易动画制作程序（演示版）");
	window.show(argc, argv);

	// 等待单击“下一步”按钮后继续，实现暂停功能
	window.WaitForClick();

	//将示例代码注释掉：
	/*
	// 创建一条直线
	XLine line1(XPoint(100, 100), XPoint(100, 200));
	// 把该直线添加到窗口中
	window.Add(line1);
	//window.draw()函数会被自动调用。窗口立即重绘。

	window.WaitForClick();

	// 创建第二条直线，设置颜色，并添加到窗口中
	XLine line2(XPoint(200, 100), XPoint(300, 100));
	line2.SetLineColor(XColor::XCOLOR_BLUE);  //XCOLOR an enumerator
	window.Add(line2);

	window.WaitForClick();

	// 创建11条直线，并添加到窗口中
	XLine lines[11];
	XPoint startPoint(400, 100); //公共属性。
	for (int i=0; i<11; i++)
	{
		lines[i].SetPoint(0, startPoint);
		lines[i].SetPoint(1, XPoint(500, 100+10*i));
		window.Add(lines[i]);
		window.Delay(200);  //200毫秒
	}

	window.WaitForClick();

	// 改变第二条直线的颜色
	line2.SetLineColor(XColor::XCOLOR_GREEN);

	window.WaitForClick();
	
	*/
	
	//下面的代码可以画一幢房子：

	// 创建两个圆:
	XCircle circle1(XPoint(98, 363), 30);
	XCircle circle2(XPoint(190, 363), 30);

	//设置它们的颜色为黑色
	circle1.SetLineColor(XColor::XCOLOR_BLACK);
	circle2.SetLineColor(XColor::XCOLOR_BLACK);

	// 把这两个圆添加到窗口中
	window.Add(circle1);
	window.Add(circle2);
	window.WaitForClick();
	
	// 创建一个矩形
	XRectangle rectangle1(XPoint(54, 333), XPoint(235, 185));
	// 设置它的颜色为绿色
	rectangle1.SetLineColor(XColor::XCOLOR_GREEN);
	// 把该矩形添加到窗口中
	window.Add(rectangle1);
	window.WaitForClick();

	// 创建一个三角形
	XTriangle triangle1(XPoint(30, 183), XPoint(258, 183), XPoint(145, 62));
	// 设置它的颜色为红色
	triangle1.SetLineColor(XColor::XCOLOR_RED);
	// 把该三角形添加到窗口中
	window.Add(triangle1);
	window.WaitForClick();

	// 创建一个多边形
	// 先创建一个包含关键点的向量
	vector<XPoint> input_points;

	//把关键点放入vector中。在这里可以压入 任意数量 的关键点，从而实现任意边数多边形的绘制。
	input_points.push_back(XPoint(178, 264));
	input_points.push_back(XPoint(220, 248));
	input_points.push_back(XPoint(220, 213));
	input_points.push_back(XPoint(178, 194));
	input_points.push_back(XPoint(135, 213));
	input_points.push_back(XPoint(135, 248));

	XPolygon polygon1(input_points);             //将向量传入函数
	polygon1.SetLineColor(XColor::XCOLOR_BLUE);  //设置多边形颜色为蓝色

    // 把该多边形添加到窗口中
	window.Add(polygon1);

	window.WaitForClick();

	
	//让房子动起来：
	for (int i = 0; i < 300; i++) // 每一个循环都画出一栋房子，平移量为i
	{
		window.Clear();
		// 创建两个圆
		// 用正弦Sin函数使车轮变大变小
		// 加上相位(-22.0458)是为了使最终车轮停在最大的位置。
		XCircle circle01(XPoint(98 + i, 363), 15+15*sin(0.1*i-22.0458));
		XCircle circle02(XPoint(190 + i, 363),15+15*sin(0.1*i-22.0458));

		//设置它们的颜色为黑色
		circle01.SetLineColor(XColor::XCOLOR_BLACK);
		circle02.SetLineColor(XColor::XCOLOR_BLACK);

		// 把这两个圆添加到窗口中
		window.Add(circle01);
		window.Add(circle02);

		// 创建一个矩形
		XRectangle rectangle01(XPoint(54 + i, 333), XPoint(235 + i, 185));
		// 设置它的颜色为绿色
		rectangle01.SetLineColor(XColor::XCOLOR_GREEN);
		// 把该矩形添加到窗口中
		window.Add(rectangle01);

		// 创建一个三角形
		XTriangle triangle01(XPoint(30 + i, 183), XPoint(258 + i, 183), XPoint(145 + i, 62));
		// 设置它的颜色为红色
		triangle01.SetLineColor(XColor::XCOLOR_RED);
		// 把该三角形添加到窗口中
		window.Add(triangle01);

		// 创建一个多边形
		// 先创建一个包含关键点的向量
		vector<XPoint> input_points;

		//把关键点放入vector中。在这里可以压入 任意数量 的关键点，从而实现任意边数多边形的绘制。
		input_points.push_back(XPoint(178 + i, 264));
		input_points.push_back(XPoint(220 + i, 248));
		input_points.push_back(XPoint(220 + i, 213));
		input_points.push_back(XPoint(178 + i, 194));
		input_points.push_back(XPoint(135 + i, 213));
		input_points.push_back(XPoint(135 + i, 248));

		XPolygon polygon01(input_points);             //将向量传入函数
		polygon01.SetLineColor(XColor::XCOLOR_BLUE);  //设置多边形颜色为蓝色

													 // 把该多边形添加到窗口中
		window.Add(polygon01);

	
		window.Delay(15);           //暂停15毫秒
		if (i == 299)
		{
			window.WaitForClick();
		}
	}
}
