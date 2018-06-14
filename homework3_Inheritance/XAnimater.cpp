//
// ����FLTK 1.1.10��ͼ�����Ĳ��Գ���
//
// Created by ZhangHua @ 2011-04-27
// Modified by ZhangHua @ 2014-11-11
// Modified by LiDongxu @ 2018-05-25
//
// ��Visual Studio 2017 �±�д����2010�����������ض��������Ŀ�ꡱ�����õ�
//
// ��ͬѧ���ڴ��ļ��������Լ��Ķ����ű����롣

#include "XWindow.h"
#include <vector>
#include <cmath>

//inline void graph_a_house(int x, XInteractiveWindow &window);

int main(int argc, char **argv) {
	// ��������ʾ����ʽ�Ļ�ͼ����
	XInteractiveWindow window(600, 400, "���׶�������������ʾ�棩");
	window.show(argc, argv);

	// �ȴ���������һ������ť�������ʵ����ͣ����
	window.WaitForClick();

	//��ʾ������ע�͵���
	/*
	// ����һ��ֱ��
	XLine line1(XPoint(100, 100), XPoint(100, 200));
	// �Ѹ�ֱ����ӵ�������
	window.Add(line1);
	//window.draw()�����ᱻ�Զ����á����������ػ档

	window.WaitForClick();

	// �����ڶ���ֱ�ߣ�������ɫ������ӵ�������
	XLine line2(XPoint(200, 100), XPoint(300, 100));
	line2.SetLineColor(XColor::XCOLOR_BLUE);  //XCOLOR an enumerator
	window.Add(line2);

	window.WaitForClick();

	// ����11��ֱ�ߣ�����ӵ�������
	XLine lines[11];
	XPoint startPoint(400, 100); //�������ԡ�
	for (int i=0; i<11; i++)
	{
		lines[i].SetPoint(0, startPoint);
		lines[i].SetPoint(1, XPoint(500, 100+10*i));
		window.Add(lines[i]);
		window.Delay(200);  //200����
	}

	window.WaitForClick();

	// �ı�ڶ���ֱ�ߵ���ɫ
	line2.SetLineColor(XColor::XCOLOR_GREEN);

	window.WaitForClick();
	
	*/
	
	//����Ĵ�����Ի�һ�����ӣ�

	// ��������Բ:
	XCircle circle1(XPoint(98, 363), 30);
	XCircle circle2(XPoint(190, 363), 30);

	//�������ǵ���ɫΪ��ɫ
	circle1.SetLineColor(XColor::XCOLOR_BLACK);
	circle2.SetLineColor(XColor::XCOLOR_BLACK);

	// ��������Բ��ӵ�������
	window.Add(circle1);
	window.Add(circle2);
	window.WaitForClick();
	
	// ����һ������
	XRectangle rectangle1(XPoint(54, 333), XPoint(235, 185));
	// ����������ɫΪ��ɫ
	rectangle1.SetLineColor(XColor::XCOLOR_GREEN);
	// �Ѹþ�����ӵ�������
	window.Add(rectangle1);
	window.WaitForClick();

	// ����һ��������
	XTriangle triangle1(XPoint(30, 183), XPoint(258, 183), XPoint(145, 62));
	// ����������ɫΪ��ɫ
	triangle1.SetLineColor(XColor::XCOLOR_RED);
	// �Ѹ���������ӵ�������
	window.Add(triangle1);
	window.WaitForClick();

	// ����һ�������
	// �ȴ���һ�������ؼ��������
	vector<XPoint> input_points;

	//�ѹؼ������vector�С����������ѹ�� �������� �Ĺؼ��㣬�Ӷ�ʵ�������������εĻ��ơ�
	input_points.push_back(XPoint(178, 264));
	input_points.push_back(XPoint(220, 248));
	input_points.push_back(XPoint(220, 213));
	input_points.push_back(XPoint(178, 194));
	input_points.push_back(XPoint(135, 213));
	input_points.push_back(XPoint(135, 248));

	XPolygon polygon1(input_points);             //���������뺯��
	polygon1.SetLineColor(XColor::XCOLOR_BLUE);  //���ö������ɫΪ��ɫ

    // �Ѹö������ӵ�������
	window.Add(polygon1);

	window.WaitForClick();

	
	//�÷��Ӷ�������
	for (int i = 0; i < 300; i++) // ÿһ��ѭ��������һ�����ӣ�ƽ����Ϊi
	{
		window.Clear();
		// ��������Բ
		// ������Sin����ʹ���ֱ���С
		// ������λ(-22.0458)��Ϊ��ʹ���ճ���ͣ������λ�á�
		XCircle circle01(XPoint(98 + i, 363), 15+15*sin(0.1*i-22.0458));
		XCircle circle02(XPoint(190 + i, 363),15+15*sin(0.1*i-22.0458));

		//�������ǵ���ɫΪ��ɫ
		circle01.SetLineColor(XColor::XCOLOR_BLACK);
		circle02.SetLineColor(XColor::XCOLOR_BLACK);

		// ��������Բ��ӵ�������
		window.Add(circle01);
		window.Add(circle02);

		// ����һ������
		XRectangle rectangle01(XPoint(54 + i, 333), XPoint(235 + i, 185));
		// ����������ɫΪ��ɫ
		rectangle01.SetLineColor(XColor::XCOLOR_GREEN);
		// �Ѹþ�����ӵ�������
		window.Add(rectangle01);

		// ����һ��������
		XTriangle triangle01(XPoint(30 + i, 183), XPoint(258 + i, 183), XPoint(145 + i, 62));
		// ����������ɫΪ��ɫ
		triangle01.SetLineColor(XColor::XCOLOR_RED);
		// �Ѹ���������ӵ�������
		window.Add(triangle01);

		// ����һ�������
		// �ȴ���һ�������ؼ��������
		vector<XPoint> input_points;

		//�ѹؼ������vector�С����������ѹ�� �������� �Ĺؼ��㣬�Ӷ�ʵ�������������εĻ��ơ�
		input_points.push_back(XPoint(178 + i, 264));
		input_points.push_back(XPoint(220 + i, 248));
		input_points.push_back(XPoint(220 + i, 213));
		input_points.push_back(XPoint(178 + i, 194));
		input_points.push_back(XPoint(135 + i, 213));
		input_points.push_back(XPoint(135 + i, 248));

		XPolygon polygon01(input_points);             //���������뺯��
		polygon01.SetLineColor(XColor::XCOLOR_BLUE);  //���ö������ɫΪ��ɫ

													 // �Ѹö������ӵ�������
		window.Add(polygon01);

	
		window.Delay(15);           //��ͣ15����
		if (i == 299)
		{
			window.WaitForClick();
		}
	}
}
