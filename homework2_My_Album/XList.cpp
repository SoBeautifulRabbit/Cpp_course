//
//	列表类
//
//	Created by ZhangHua @ 2014-10
//  2017-10 定义部分成员函数；增加部分成员函数的初始空白定义。
//
//  请按作业要求完成列表类的设计和实现。
//  学生：李东旭 学号：2015301510021

#include "XList.h"
#include <fstream>
using std::ofstream;

XList::XList()
{
	Initialize();
}

void XList::Initialize()
{
	m_items = 0;
}

bool XList::IsEmpty()
{
	if (m_items==0)
		return true;
	else
		return false;
}

bool XList::IsFull()
{
	if (m_items>=LISTSIZE)
		return true;
	else
		return false;
}

int XList::ItemCount()
{
	return m_items;
}

bool XList::AppendItem(Item &item)
{
	if (IsFull()) return false;

	m_entries[m_items] = item;
	m_items++;

	return true;
}

void XList::Traverse(void (*pFun)(Item &item))
{
	for (int i=0; i<m_items; i++)
	{
		pFun(m_entries[i]);
	}
}

void XList::Traverse(void(*pFun)(Item &item) , int idx)
{
	for (int i = --idx; i<m_items; i++)
	{
		pFun(m_entries[i]);
	}
}

void XList::Traverse(void(*pFun)(Item &item, ofstream &outFile), ofstream &outFile)
{
	for (int i = 0; i<m_items; i++)
	{
		pFun(m_entries[i], outFile);
	}
}

void XList::Clear()
{
	m_items = 0;
}


// =======================================================
// 后面函数的定义还未完成，你视需要添加代码。
// =======================================================

bool XList::SetItem(int idx, Item &item)
{
	// 添加代码

	if (idx<1 || idx>m_items)
	{
		return false;
	}
	m_entries[idx - 1] = item;
	return true;
}

bool XList::GetItem(int idx, Item &item)
{
	// 添加代码
	if (idx < 1 || idx > m_items)
	{
		return false;
	}
	item = m_entries[idx - 1];
	return true;
}

bool XList::LocateItem(string name, Item & item)
{
	int i = 0;
	while (i < m_items && (m_entries[i].GetTitle()) != name)
	{
		i++;
	}
	if (i >= m_items) //遍历了整个线性表却仍然没有找到，则返回false
	{
		return false;
	}
	else
	{
		item = m_entries[i];
		return true;
	}
}

bool XList::DeleteItem(int idx)
{
	// 添加代码
	if (idx<1 || idx > m_items)
	{
		return false;
	}
	idx--; //将逻辑序号转化为物理序号
	for (int i = idx; i < m_items; i++)
	{
		m_entries[i] = m_entries[i + 1];
	}
	m_items--;
	return true;
}
