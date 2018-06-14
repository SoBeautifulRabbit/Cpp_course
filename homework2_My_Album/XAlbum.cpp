//
//	相册程序
//	相册类
//
//	Created by ZhangHua @ 2015-10
//  2017-10 增加ShowAllPhotos和AddPhoto函数的初始空白定义。
//
//  请按作业要求定义相册类的成员函数。
//  学生：李东旭 学号：2015301510021

#include <iostream>
#include <fstream>
using namespace std;

#include "XAlbum.h"
#include "XUtility.h"

void ShowPhoto(XPhoto &photo);  //展示一个照片对象的内容
void SavePhoto(XPhoto &photo, ofstream &outFile);  //存储一个照片对象的内容到文件
void ModifyIDNumber(XPhoto &photo);  //修改一个照片对象的m_id

bool XAlbum::AddPhoto()
{
	// 添加“增加照片”的代码
	if (m_photo_list.IsFull())
	{
		cout << endl << "对不起，这个相册满了，它最多可以容纳100张照片。";
	}

	//实例化一个照片对象
	XPhoto photo;

	string title;
	cout<<"照片的名字：";
	cin>>title;
	if (title[0]==NULL)
		return false;

	string descr;
	cout<<"照片的描述：";
	cin>>descr;
	if (title[0]==NULL)
		return false;

	string add_datetime;
	add_datetime=XUtility::GetCurDateTime();

	unsigned int id;
	id=m_photo_list.ItemCount()+1;

    photo.SetTitle(title);
	photo.SetDescr(descr);
	photo.SetAddDatetime(add_datetime);
	photo.SetIDNumber(id);

	//将照片添加到相册（列表）中
	m_photo_list.AppendItem(photo);

	// 这条语句是演示怎么使用XUtility类获取当前系统时间，你可能需要此功能
	//cout<<"当前时间："<<XUtility::GetCurDateTime()<<endl<<endl;

	// 暂时返回 true，你可以修改
	return true;
}

void XAlbum::ShowAllPhotos()
{
	// 添加“显示全部照片”的代码
	CheckEmpty();
	//即使CheckEmpty为true，执行下面这条语句也不会有什么后果，因此不需要
	//当CheckEmpty为true时终止这个函数的过程。
	m_photo_list.Traverse(ShowPhoto);
}

bool XAlbum::ModifyPhoto()
{
	if (CheckEmpty())
	{
		return false;
	}
	XPhoto photo;
	cout << endl;
	cout << "请输入您想更改的照片的编号或名称：";
	int number;
	string name;
	if (cin >> number) //如果用户输入的是编号
	{
		if (m_photo_list.GetItem(number, photo))
		{
			cout << endl<< "这是您将要修改的照片的信息：" << endl;
			ShowPhoto(photo);
		}
		else
		{
			cout << "对不起，没有找到编号为" << number << "的照片。" << endl;
			return false;
		}
	}
	else //如果用户输入的是照片名称
	{
		cin.clear();
		cin >> name;
		if (m_photo_list.LocateItem(name, photo))
		{
			cout << endl<< "这是您将要修改的照片的信息：" << endl;
			ShowPhoto(photo);
			number = photo.GetIDNumber();
		}
		else
		{
			cout << "对不起，没有找到名字为" << name << "的照片。" << endl;
			return false;
		}
	}
	string title;
	cout << "请输入新的照片名：（如果该项不作修改，请输入##(两个井号连在一起)）";
	cin >> title;
	
	string descr;
	cout << "请输入新的照片描述：（如果该项不作修改，请输入##(两个井号连在一起)）";
	cin >> descr;
	
	string add_datetime;
	add_datetime = XUtility::GetCurDateTime();

	cout << "您是否要修改这张照片的信息？（Y/N）";
	string yn;
	cin >> yn;

	while (yn != "Y" && yn != "N" && yn != "y" && yn != "n")
	{
		std::cout << "输入错误。请输入Y或N";
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cin >> yn;
	}

	if (yn == "N" || yn == "n")
	{
		cout << "已放弃对照片信息的修改。" << endl;
		return false;
	}

	if (title != "##")
	{
		photo.SetTitle(title);
	}
	if (descr != "##")
	{
		photo.SetDescr(descr);
	}

//并不修改添加日期时间m_add_datetime

	m_photo_list.SetItem(number, photo);
	
	if (title == "##" && descr == "##")
	{
		cout << "您没有对照片信息作出任何修改。" << endl;
		return false;
	}
	cout << "已成功修改了照片信息！" << endl;

	return true;
}

void XAlbum::SearchPhoto()
{
	XPhoto photo;
	cout << endl;
	cout<<"请输入您想查找的 照片名称 或 编号： ";
	int number;
	string name;
	if (cin >> number) //如果用户输入的是编号
	{
		if (m_photo_list.GetItem(number, photo))
		{
			cout << "成功找到编号为" << number << "的照片！"<<endl;
			ShowPhoto(photo);
		}
		else
		{
			cout << "对不起，没有找到编号为" << number << "的照片。" << endl;
		}
	}
	else //如果用户输入的是照片名称
	{
		cin.clear();
		cin >> name;
		if (m_photo_list.LocateItem(name, photo))
		{
			cout << "成功找到名字为" << name << "的照片！" << endl;
			ShowPhoto(photo);
		}
		else
		{
			cout << "对不起，没有找到名字为" << name << "的照片。" << endl;
		}
	}
}

bool XAlbum::DeletePhoto()
{
	if (CheckEmpty())
	{
		return false;
	}
	cout << endl;
	cout << "请输入您想删除的照片的编号： ";
	int number;
	string name;
	cin >> number;

	cout << "您是否真的要删除编号为"<<number<<"的照片？（Y/N）";
	string yn;
	cin >> yn;

	while (yn != "Y" && yn != "N" && yn != "y" && yn != "n")
	{
		std::cout << "输入错误。请输入Y或N";
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cin >> yn;
	}

	if (yn == "N" || yn == "n")
	{
		cout << "已取消删除。" << endl;
		return false;
	}

	if (m_photo_list.DeleteItem(number))
	{
		cout << "成功删除了编号为" << number << "的照片！" << endl;
	}
	else
	{
		cout << "对不起，没有找到编号为" << number << "的照片。" << endl;
		return false;
	}

	//将所有编号大于被删除照片的编号的照片的编号减一
	m_photo_list.Traverse(ModifyIDNumber, number);
	return true;
}

bool XAlbum::CheckEmpty()
{
	if (m_photo_list.IsEmpty())
	{
		cout <<"您还没有添加照片，相册是空的。" << endl;
		return true;
	}
	return false;
}

bool XAlbum::SaveToFile()
{
	if (CheckEmpty())
	{
		cout << "没有创建或写入文件。\n";
		cout << "请添加照片后再试一次";
		return false;
	}
	ofstream outFile;
	outFile.open("myAlbumOutput.txt");  //创建这个文件并存储于源文件或可执行文件所在目录
	m_photo_list.Traverse(SavePhoto, outFile);
	cout << "已成功创建或写入文件\n";
	cout << "文件位于可执行文件或源文件所在目录。\n";
	cout << "文件名为myAlbumOutput.txt\n";
	outFile.close();
	return true;
}

//以下函数不是类的成员函数，但它们是成员函数的某个模块

void ShowPhoto(XPhoto &photo)
{
	cout << "照片编号： " << photo.GetIDNumber() << endl;
	cout << "标题：     " << photo.GetTitle() << endl;
	cout << "描述：     " << photo.GetDescr() << endl;
	cout << "添加时间： " << photo.GetAddDatetime() << endl << endl;
}

void SavePhoto(XPhoto &photo, ofstream &outFile)
{
	outFile << "照片编号： " << photo.GetIDNumber() << endl;
	outFile << "标题：     " << photo.GetTitle() << endl;
	outFile << "描述：     " << photo.GetDescr() << endl;
	outFile << "添加时间： " << photo.GetAddDatetime() << endl << endl;
}

void ModifyIDNumber(XPhoto &photo)
{
	int number;
	number = photo.GetIDNumber();
	number--;
	photo.SetIDNumber(number);
}

