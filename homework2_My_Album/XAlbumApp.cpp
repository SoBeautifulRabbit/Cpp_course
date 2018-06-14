//
//	相册应用程序
//
//	Created by ZhangHua @ 2015-10
//  2017-10 增加相册对象；修改初始提示。
//  2018-04 修改部分提示信息。
//
//  请按作业要求完成应用程序的设计和实现。
//  学生：李东旭 学号：2015301510021

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
using namespace std;

#include "XAlbum.h"

// 显示相册程序的功能菜单，并获取用户选择执行的功能项
// 返回值是用户选择的功能项编号
int menu();

// 相册程序的主控函数
int main()
{
	XAlbum myAlbum; // 相册对象

	int choice; // 保存用户选择的功能项编号
	do
	{
		// 显示菜单，获取要执行的功能项
		choice = menu();

		// 根据功能项编号执行相应的操作
		switch (choice)
		{
		case 1: // [1]显示全部照片列表
			{
				std::cout<<"\n你选择执行[1]显示全部照片\n\n";
				myAlbum.ShowAllPhotos();
				break;
			}
		case 2: // [2]添加照片
			{
				std::cout<<"\n你选择执行[2]添加照片\n\n";
				myAlbum.AddPhoto();
				break;
			}
		case 3: // [3]查找照片
			{
				std::cout<<"\n你选择执行[3]查找照片\n\n";
				myAlbum.SearchPhoto();
				break;
			}
		case 4: // [4]删除照片
			{
				std::cout<<"\n你选择执行[4]删除照片\n\n";
				myAlbum.DeletePhoto();
				break;
			}
		case 5: // [5]修改照片
			{
				std::cout<<"\n你选择执行[5]修改照片\n\n";
				myAlbum.ModifyPhoto();
				break;
			}

		case 6: // [6]存储到文件
		{
			std::cout << "\n你选择执行[6]存储到文件\n\n";
			myAlbum.SaveToFile();
			break;
		}

		case 7: // [7]读取文件记录
		{
			std::cout << "\n你选择执行[7]读取文件记录\n";
			std::cout << "对不起，该功能暂时还未实现，试试[6]存储到文件吧\n";
			break;
		}
		case 0: std::cout<<"\n再见\n\n"<<endl; break;
		}

		system("pause");
	} while (choice != 0);

	return 0;
}

int menu()
{
	system("cls");
	std::cout<<"====================\n";
	std::cout<<"     非一般相册\n";
	std::cout<<"      ver  1.0\n";
	std::cout<<"--------------------\n";
	std::cout<<"[1]显示全部照片\n";
	std::cout<<"[2]添加照片\n";
	std::cout<<"[3]查找照片\n";
	std::cout<<"[4]删除照片\n";
	std::cout<<"[5]修改照片\n";
	std::cout<<"[6]存储到文件\n";
	std::cout<<"[7]读取文件记录(暂未实现)\n";
	std::cout<<"[0]退出\n";
	std::cout<<"====================\n";
	
	std::cout<<"请选择要执行的功能：\n";

	int choice;

	//这里应该修改代码，判断用户输入的是否是一个数字
	//否则用户输入非数字（比如字符串"ef"）时，程序会进入死循环
	std::cin >> choice;
	while (choice<0 || choice>7)
	{
		std::cout<<"输入错误。请重新选择要执行的功能（1~7），输入0退出：\n";
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cin >> choice;
	}

	//这是原来的代码
	//while (choice<0 || choice>5)
	//{
	//	std::cout << "输入错误。请重新选择要执行的功能（1~5），输入0退出：\n";
	//	std::cin >> choice;
	//}
	return choice;
}