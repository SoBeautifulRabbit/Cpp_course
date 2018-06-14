//���2015301510021 ��һ����ҵ
//��Microsoft Visual C++ 2010ѧϰ���б�д
//ϵͳ����Windows7 SP1 32λ
//����ʹ����Tab��

#include <iostream>
#include <conio.h>
using namespace std;

#include "XWawa.h"

#pragma comment(lib, "XWawa.lib") //ʹ�þ�̬���ļ�

void BEGIN();
void END(XWawa&);
void common_method(XWawa&);

void main()
{
	XWawa wawa;

	//���û�ָ��һ���������
	int tasknumber;
	cout<<"\n\n������wawa����ĸ�����? \n\n0����ʾ\n1�����ϰ�����ɽ����ɽ\n2��Խ���̶��ϰ�\n3��Խ���߶Ȳ�ȷ������ȹ̶����м��������ϰ�\n4��Խ���߶ȡ���Ⱥͼ�඼��ȷ���������ϰ�";
	cout<<"������һ�����ֲ����س�����"<<endl;
	cin>>tasknumber;

	while (1)
	{
		if (tasknumber==0 || tasknumber==1 || tasknumber==2 || tasknumber==3 || tasknumber==4)
			break;
		else
		{
			cout<<"�������������롣��Ӧ������0��1��2��3��4 ��5�������е�һ��"<<endl<<"�����������벢���س���"<<endl;
			cin>>tasknumber;
		}
	}

	//Ϊ���߷�������
	wawa.assignTask(tasknumber);


	// ��ʾ�����������ʼִ�к����ָ����������㷨ʵ�֣�
	BEGIN();

	// ���������ָ��
	// ָ�ʼ
	// --------------------------------------------------

	switch (tasknumber)
	{
		case 0:  //task 0
			wawa.moveUp();
			wawa.moveUp();
			while (wawa.beanIsHere())
			{
				wawa.pickupBean();
				if (wawa.rightIsClear())
					wawa.moveRight();
				else
					break;
			}
		break;

		case 1:  //task 1
			//���¶�
			while (1)
			{
				wawa.moveRight();
				wawa.pickupBean();
				if (wawa.upsideIsClear())
					wawa.moveUp();
				else
					break;
			}

			//���¶�
			while (1)
			{
				if (wawa.downsideIsClear())
					wawa.moveDown();
				else
					break;

				wawa.moveRight();
				wawa.pickupBean();
			}
		break;

		case 2:  //task 2
			common_method(wawa);
		break;

		case 3:  //task 3
			common_method(wawa);
		break;

		case 4:  //task 4
			common_method(wawa);
		break;
		
	}

	// --------------------------------------------------
	// ָ�����

	// ��������ָ��ִ�к��Ƿ���������񣬲�������Ӧ����ʾ
	END(wawa);
}

void common_method(XWawa &wawa) //��������2��3��4��������һ��ͨ�õ��߷������԰������߷������һ������
{
	bool movedup = false; //false��ʾ��һ�����������ߵģ�true��ʾ��һ���������ߵ�
	while (1)
	{
		if (wawa.beanIsHere())
			wawa.pickupBean();
		else
			;

		//��������Ƿ����
		if (wawa.taskIsAccomplished())
		{
			break;
		}

		//�ƶ�һ��
		if (wawa.downsideIsClear() && movedup==false)  //���������ߡ��������һ���������ˣ���һ�����������ߣ������ԭ���۷�
			{
				wawa.moveDown();
				movedup=false;
			}
		else if (wawa.rightIsClear()) //�����������,�ͳ���������
			{
				wawa.moveRight();
				movedup=false;
			}
		else
			{
				wawa.moveUp(); //��������߲���,�ͱ���������
				movedup=true;
			}
	}
}

void BEGIN()
{
	printf("\n�����������ʼִ�����ָ�");
	_getch();
}

void END(XWawa &wawa)
{
	printf("\n����ָ����ִ����ϡ�");
	if (wawa.taskIsAccomplished())
	{
		cout<<"\n��ϲ����������ɡ������ƶ���"<<wawa.GetMoveCount()<<"�Ρ�";
	}
	else
	{
		printf("\n���ź�������û����ɡ��޸Ĵ��룬����һ�ΰɡ�");
	}
	printf("\n������������˳�����...\n");
	_getch();
}
