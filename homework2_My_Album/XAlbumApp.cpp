//
//	���Ӧ�ó���
//
//	Created by ZhangHua @ 2015-10
//  2017-10 �����������޸ĳ�ʼ��ʾ��
//  2018-04 �޸Ĳ�����ʾ��Ϣ��
//
//  �밴��ҵҪ�����Ӧ�ó������ƺ�ʵ�֡�
//  ѧ������� ѧ�ţ�2015301510021

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <conio.h>
using namespace std;

#include "XAlbum.h"

// ��ʾ������Ĺ��ܲ˵�������ȡ�û�ѡ��ִ�еĹ�����
// ����ֵ���û�ѡ��Ĺ�������
int menu();

// ����������غ���
int main()
{
	XAlbum myAlbum; // ������

	int choice; // �����û�ѡ��Ĺ�������
	do
	{
		// ��ʾ�˵�����ȡҪִ�еĹ�����
		choice = menu();

		// ���ݹ�������ִ����Ӧ�Ĳ���
		switch (choice)
		{
		case 1: // [1]��ʾȫ����Ƭ�б�
			{
				std::cout<<"\n��ѡ��ִ��[1]��ʾȫ����Ƭ\n\n";
				myAlbum.ShowAllPhotos();
				break;
			}
		case 2: // [2]�����Ƭ
			{
				std::cout<<"\n��ѡ��ִ��[2]�����Ƭ\n\n";
				myAlbum.AddPhoto();
				break;
			}
		case 3: // [3]������Ƭ
			{
				std::cout<<"\n��ѡ��ִ��[3]������Ƭ\n\n";
				myAlbum.SearchPhoto();
				break;
			}
		case 4: // [4]ɾ����Ƭ
			{
				std::cout<<"\n��ѡ��ִ��[4]ɾ����Ƭ\n\n";
				myAlbum.DeletePhoto();
				break;
			}
		case 5: // [5]�޸���Ƭ
			{
				std::cout<<"\n��ѡ��ִ��[5]�޸���Ƭ\n\n";
				myAlbum.ModifyPhoto();
				break;
			}

		case 6: // [6]�洢���ļ�
		{
			std::cout << "\n��ѡ��ִ��[6]�洢���ļ�\n\n";
			myAlbum.SaveToFile();
			break;
		}

		case 7: // [7]��ȡ�ļ���¼
		{
			std::cout << "\n��ѡ��ִ��[7]��ȡ�ļ���¼\n";
			std::cout << "�Բ��𣬸ù�����ʱ��δʵ�֣�����[6]�洢���ļ���\n";
			break;
		}
		case 0: std::cout<<"\n�ټ�\n\n"<<endl; break;
		}

		system("pause");
	} while (choice != 0);

	return 0;
}

int menu()
{
	system("cls");
	std::cout<<"====================\n";
	std::cout<<"     ��һ�����\n";
	std::cout<<"      ver  1.0\n";
	std::cout<<"--------------------\n";
	std::cout<<"[1]��ʾȫ����Ƭ\n";
	std::cout<<"[2]�����Ƭ\n";
	std::cout<<"[3]������Ƭ\n";
	std::cout<<"[4]ɾ����Ƭ\n";
	std::cout<<"[5]�޸���Ƭ\n";
	std::cout<<"[6]�洢���ļ�\n";
	std::cout<<"[7]��ȡ�ļ���¼(��δʵ��)\n";
	std::cout<<"[0]�˳�\n";
	std::cout<<"====================\n";
	
	std::cout<<"��ѡ��Ҫִ�еĹ��ܣ�\n";

	int choice;

	//����Ӧ���޸Ĵ��룬�ж��û�������Ƿ���һ������
	//�����û���������֣������ַ���"ef"��ʱ������������ѭ��
	std::cin >> choice;
	while (choice<0 || choice>7)
	{
		std::cout<<"�������������ѡ��Ҫִ�еĹ��ܣ�1~7��������0�˳���\n";
		std::cin.clear();
		std::cin.ignore(1024, '\n');
		std::cin >> choice;
	}

	//����ԭ���Ĵ���
	//while (choice<0 || choice>5)
	//{
	//	std::cout << "�������������ѡ��Ҫִ�еĹ��ܣ�1~5��������0�˳���\n";
	//	std::cin >> choice;
	//}
	return choice;
}