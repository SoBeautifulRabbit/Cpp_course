//
//	������
//	��Ƭ��
//
//	Created by ZhangHua @ 2015-10
//  Updated by ZhangHua @ 2018-04
//		-��string�ദ���ַ���
//
//  �밴��ҵҪ�������Ƭ�����ƺ�ʵ�֡�
//  ѧ������� ѧ�ţ�2015301510021

#ifndef _XPHOTO_H_
#define _XPHOTO_H_

#include <string>
using std::string;

#define TITLESIZE 256 // ��ű�������鳤��
#define DESCRSIZE 1024 // ���˵�������鳤��
#define DATETIMESIZE 20 // ���ʱ���ַ��������鳤��

// ��Ƭ
class XPhoto
{
private:
	unsigned int m_id; // ��ѡ���ԣ���Ƭ��ţ�����Ψһ��ʶһ����Ƭ����������Լ����һ���Զ���ŵ��㷨��
	                   // ������m_id����Ϊ��Ƭ��˳����е��߼���ţ�����Ψһ��
	                   // ���ǵ�����Ƭ��ɾ��ʱ������Ƭ��m_id�����μ�һ��
	string m_title; // ����
	string m_descr; // ˵��
	string m_add_datetime; // �޸�ʱ��


	// �����ں��������������


public:
	// ˽�����ݳ�Ա��Setter��Getter�������޸ĺͶ�ȡ������
	void SetTitle(const string &title) { m_title = title; }
	string GetTitle() { return m_title; }
	void SetDescr(const string &descr) { m_descr = descr; }
	string GetDescr() { return m_descr; }
	void SetAddDatetime(const string &add_datetime) { m_add_datetime = add_datetime; }
	string GetAddDatetime() { return m_add_datetime; }
	void SetIDNumber(const unsigned int &id) { m_id = id; }
	unsigned int GetIDNumber() { return m_id; }

	// �����ں�����Ӳ�������

};

#endif