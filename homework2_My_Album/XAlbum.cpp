//
//	������
//	�����
//
//	Created by ZhangHua @ 2015-10
//  2017-10 ����ShowAllPhotos��AddPhoto�����ĳ�ʼ�հ׶��塣
//
//  �밴��ҵҪ���������ĳ�Ա������
//  ѧ������� ѧ�ţ�2015301510021

#include <iostream>
#include <fstream>
using namespace std;

#include "XAlbum.h"
#include "XUtility.h"

void ShowPhoto(XPhoto &photo);  //չʾһ����Ƭ���������
void SavePhoto(XPhoto &photo, ofstream &outFile);  //�洢һ����Ƭ��������ݵ��ļ�
void ModifyIDNumber(XPhoto &photo);  //�޸�һ����Ƭ�����m_id

bool XAlbum::AddPhoto()
{
	// ��ӡ�������Ƭ���Ĵ���
	if (m_photo_list.IsFull())
	{
		cout << endl << "�Բ������������ˣ�������������100����Ƭ��";
	}

	//ʵ����һ����Ƭ����
	XPhoto photo;

	string title;
	cout<<"��Ƭ�����֣�";
	cin>>title;
	if (title[0]==NULL)
		return false;

	string descr;
	cout<<"��Ƭ��������";
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

	//����Ƭ��ӵ���ᣨ�б���
	m_photo_list.AppendItem(photo);

	// �����������ʾ��ôʹ��XUtility���ȡ��ǰϵͳʱ�䣬�������Ҫ�˹���
	//cout<<"��ǰʱ�䣺"<<XUtility::GetCurDateTime()<<endl<<endl;

	// ��ʱ���� true��������޸�
	return true;
}

void XAlbum::ShowAllPhotos()
{
	// ��ӡ���ʾȫ����Ƭ���Ĵ���
	CheckEmpty();
	//��ʹCheckEmptyΪtrue��ִ�������������Ҳ������ʲô�������˲���Ҫ
	//��CheckEmptyΪtrueʱ��ֹ��������Ĺ��̡�
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
	cout << "������������ĵ���Ƭ�ı�Ż����ƣ�";
	int number;
	string name;
	if (cin >> number) //����û�������Ǳ��
	{
		if (m_photo_list.GetItem(number, photo))
		{
			cout << endl<< "��������Ҫ�޸ĵ���Ƭ����Ϣ��" << endl;
			ShowPhoto(photo);
		}
		else
		{
			cout << "�Բ���û���ҵ����Ϊ" << number << "����Ƭ��" << endl;
			return false;
		}
	}
	else //����û����������Ƭ����
	{
		cin.clear();
		cin >> name;
		if (m_photo_list.LocateItem(name, photo))
		{
			cout << endl<< "��������Ҫ�޸ĵ���Ƭ����Ϣ��" << endl;
			ShowPhoto(photo);
			number = photo.GetIDNumber();
		}
		else
		{
			cout << "�Բ���û���ҵ�����Ϊ" << name << "����Ƭ��" << endl;
			return false;
		}
	}
	string title;
	cout << "�������µ���Ƭ���������������޸ģ�������##(������������һ��)��";
	cin >> title;
	
	string descr;
	cout << "�������µ���Ƭ�����������������޸ģ�������##(������������һ��)��";
	cin >> descr;
	
	string add_datetime;
	add_datetime = XUtility::GetCurDateTime();

	cout << "���Ƿ�Ҫ�޸�������Ƭ����Ϣ����Y/N��";
	string yn;
	cin >> yn;

	while (yn != "Y" && yn != "N" && yn != "y" && yn != "n")
	{
		std::cout << "�������������Y��N";
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cin >> yn;
	}

	if (yn == "N" || yn == "n")
	{
		cout << "�ѷ�������Ƭ��Ϣ���޸ġ�" << endl;
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

//�����޸��������ʱ��m_add_datetime

	m_photo_list.SetItem(number, photo);
	
	if (title == "##" && descr == "##")
	{
		cout << "��û�ж���Ƭ��Ϣ�����κ��޸ġ�" << endl;
		return false;
	}
	cout << "�ѳɹ��޸�����Ƭ��Ϣ��" << endl;

	return true;
}

void XAlbum::SearchPhoto()
{
	XPhoto photo;
	cout << endl;
	cout<<"������������ҵ� ��Ƭ���� �� ��ţ� ";
	int number;
	string name;
	if (cin >> number) //����û�������Ǳ��
	{
		if (m_photo_list.GetItem(number, photo))
		{
			cout << "�ɹ��ҵ����Ϊ" << number << "����Ƭ��"<<endl;
			ShowPhoto(photo);
		}
		else
		{
			cout << "�Բ���û���ҵ����Ϊ" << number << "����Ƭ��" << endl;
		}
	}
	else //����û����������Ƭ����
	{
		cin.clear();
		cin >> name;
		if (m_photo_list.LocateItem(name, photo))
		{
			cout << "�ɹ��ҵ�����Ϊ" << name << "����Ƭ��" << endl;
			ShowPhoto(photo);
		}
		else
		{
			cout << "�Բ���û���ҵ�����Ϊ" << name << "����Ƭ��" << endl;
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
	cout << "����������ɾ������Ƭ�ı�ţ� ";
	int number;
	string name;
	cin >> number;

	cout << "���Ƿ����Ҫɾ�����Ϊ"<<number<<"����Ƭ����Y/N��";
	string yn;
	cin >> yn;

	while (yn != "Y" && yn != "N" && yn != "y" && yn != "n")
	{
		std::cout << "�������������Y��N";
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cin >> yn;
	}

	if (yn == "N" || yn == "n")
	{
		cout << "��ȡ��ɾ����" << endl;
		return false;
	}

	if (m_photo_list.DeleteItem(number))
	{
		cout << "�ɹ�ɾ���˱��Ϊ" << number << "����Ƭ��" << endl;
	}
	else
	{
		cout << "�Բ���û���ҵ����Ϊ" << number << "����Ƭ��" << endl;
		return false;
	}

	//�����б�Ŵ��ڱ�ɾ����Ƭ�ı�ŵ���Ƭ�ı�ż�һ
	m_photo_list.Traverse(ModifyIDNumber, number);
	return true;
}

bool XAlbum::CheckEmpty()
{
	if (m_photo_list.IsEmpty())
	{
		cout <<"����û�������Ƭ������ǿյġ�" << endl;
		return true;
	}
	return false;
}

bool XAlbum::SaveToFile()
{
	if (CheckEmpty())
	{
		cout << "û�д�����д���ļ���\n";
		cout << "�������Ƭ������һ��";
		return false;
	}
	ofstream outFile;
	outFile.open("myAlbumOutput.txt");  //��������ļ����洢��Դ�ļ����ִ���ļ�����Ŀ¼
	m_photo_list.Traverse(SavePhoto, outFile);
	cout << "�ѳɹ�������д���ļ�\n";
	cout << "�ļ�λ�ڿ�ִ���ļ���Դ�ļ�����Ŀ¼��\n";
	cout << "�ļ���ΪmyAlbumOutput.txt\n";
	outFile.close();
	return true;
}

//���º���������ĳ�Ա�������������ǳ�Ա������ĳ��ģ��

void ShowPhoto(XPhoto &photo)
{
	cout << "��Ƭ��ţ� " << photo.GetIDNumber() << endl;
	cout << "���⣺     " << photo.GetTitle() << endl;
	cout << "������     " << photo.GetDescr() << endl;
	cout << "���ʱ�䣺 " << photo.GetAddDatetime() << endl << endl;
}

void SavePhoto(XPhoto &photo, ofstream &outFile)
{
	outFile << "��Ƭ��ţ� " << photo.GetIDNumber() << endl;
	outFile << "���⣺     " << photo.GetTitle() << endl;
	outFile << "������     " << photo.GetDescr() << endl;
	outFile << "���ʱ�䣺 " << photo.GetAddDatetime() << endl << endl;
}

void ModifyIDNumber(XPhoto &photo)
{
	int number;
	number = photo.GetIDNumber();
	number--;
	photo.SetIDNumber(number);
}

