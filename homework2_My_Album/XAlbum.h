//
//	个人相册程序
//	相册类
//
//	Created by ZhangHua @ 2015-10
//  2017-10 增加ShowAllPhotos和AddPhoto函数的声明
//
//  请按作业要求完成相册类的设计和实现。
//  学生：李东旭 学号：2015301510021

#ifndef _XALBUM_H_
#define _XALBUM_H_

#include "XList.h"
#include "XPhoto.h"

class XAlbum
{
protected:
	XList m_photo_list; // 用列表对象来保存相册中的照片
	bool CheckEmpty();  // 在相册为空时返回true，该函数只被成员对象访问

public:
	// 添加照片
	bool AddPhoto();

	// 显示全部照片
	void ShowAllPhotos();

	// 可以在后面添加更多管理照片的成员函数

	// 按编号或名称更改该照片的信息
	bool ModifyPhoto();

	// 按编号或名称查找照片
	void SearchPhoto();

	//按编号删除照片
	bool DeletePhoto();

	//将所有照片的信息保存到一个txt文件
	bool SaveToFile();
};

#endif