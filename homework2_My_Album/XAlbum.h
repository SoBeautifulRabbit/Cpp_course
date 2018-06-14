//
//	����������
//	�����
//
//	Created by ZhangHua @ 2015-10
//  2017-10 ����ShowAllPhotos��AddPhoto����������
//
//  �밴��ҵҪ�������������ƺ�ʵ�֡�
//  ѧ������� ѧ�ţ�2015301510021

#ifndef _XALBUM_H_
#define _XALBUM_H_

#include "XList.h"
#include "XPhoto.h"

class XAlbum
{
protected:
	XList m_photo_list; // ���б��������������е���Ƭ
	bool CheckEmpty();  // �����Ϊ��ʱ����true���ú���ֻ����Ա�������

public:
	// �����Ƭ
	bool AddPhoto();

	// ��ʾȫ����Ƭ
	void ShowAllPhotos();

	// �����ں�����Ӹ��������Ƭ�ĳ�Ա����

	// ����Ż����Ƹ��ĸ���Ƭ����Ϣ
	bool ModifyPhoto();

	// ����Ż����Ʋ�����Ƭ
	void SearchPhoto();

	//�����ɾ����Ƭ
	bool DeletePhoto();

	//��������Ƭ����Ϣ���浽һ��txt�ļ�
	bool SaveToFile();
};

#endif