//
//	相册程序
//	照片类
//
//	Created by ZhangHua @ 2015-10
//  Updated by ZhangHua @ 2018-04
//		-用string类处理字符串
//
//  请按作业要求完成照片类的设计和实现。
//  学生：李东旭 学号：2015301510021

#ifndef _XPHOTO_H_
#define _XPHOTO_H_

#include <string>
using std::string;

#define TITLESIZE 256 // 存放标题的数组长度
#define DESCRSIZE 1024 // 存放说明的数组长度
#define DATETIMESIZE 20 // 存放时间字符串的数组长度

// 照片
class XPhoto
{
private:
	unsigned int m_id; // 可选属性：照片编号（用来唯一标识一张照片）。最好是自己设计一个自动编号的算法。
	                   // 本程序将m_id定义为照片在顺序表中的逻辑编号，它是唯一的
	                   // 但是当有照片被删除时，后方照片的m_id会依次减一。
	string m_title; // 标题
	string m_descr; // 说明
	string m_add_datetime; // 修改时间


	// 可以在后面添加其他属性


public:
	// 私有数据成员的Setter和Getter函数（修改和读取函数）
	void SetTitle(const string &title) { m_title = title; }
	string GetTitle() { return m_title; }
	void SetDescr(const string &descr) { m_descr = descr; }
	string GetDescr() { return m_descr; }
	void SetAddDatetime(const string &add_datetime) { m_add_datetime = add_datetime; }
	string GetAddDatetime() { return m_add_datetime; }
	void SetIDNumber(const unsigned int &id) { m_id = id; }
	unsigned int GetIDNumber() { return m_id; }

	// 可以在后面添加操作函数

};

#endif