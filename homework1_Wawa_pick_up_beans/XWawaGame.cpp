//李东旭2015301510021 第一次作业
//在Microsoft Visual C++ 2010学习版中编写
//系统环境Windows7 SP1 32位
//缩进使用了Tab键

#include <iostream>
#include <conio.h>
using namespace std;

#include "XWawa.h"

#pragma comment(lib, "XWawa.lib") //使用静态库文件

void BEGIN();
void END(XWawa&);
void common_method(XWawa&);

void main()
{
	XWawa wawa;

	//由用户指定一个任务代码
	int tasknumber;
	cout<<"\n\n您想让wawa完成哪个任务? \n\n0：演示\n1：无障碍的爬山和下山\n2：越过固定障碍\n3：越过高度不确定、宽度固定、有间距的若干障碍\n4：越过高度、宽度和间距都不确定的若干障碍";
	cout<<"请输入一个数字并按回车继续"<<endl;
	cin>>tasknumber;

	while (1)
	{
		if (tasknumber==0 || tasknumber==1 || tasknumber==2 || tasknumber==3 || tasknumber==4)
			break;
		else
		{
			cout<<"您不能这样输入。您应该输入0、1、2、3、4 这5个整数中的一个"<<endl<<"请您重新输入并按回车键"<<endl;
			cin>>tasknumber;
		}
	}

	//为瓦瓦分派任务
	wawa.assignTask(tasknumber);


	// 提示按下任意键后开始执行后面的指令（完成任务的算法实现）
	BEGIN();

	// 请输入你的指令
	// 指令开始
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
			//上坡段
			while (1)
			{
				wawa.moveRight();
				wawa.pickupBean();
				if (wawa.upsideIsClear())
					wawa.moveUp();
				else
					break;
			}

			//下坡段
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
	// 指令结束

	// 检查上面的指令执行后是否完成了任务，并给出相应的提示
	END(wawa);
}

void common_method(XWawa &wawa) //对于任务2、3、4，我们有一种通用的走法，可以把这种走法定义成一个函数
{
	bool movedup = false; //false表示上一步不是向上走的，true表示上一步是向上走的
	while (1)
	{
		if (wawa.beanIsHere())
			wawa.pickupBean();
		else
			;

		//检查任务是否完成
		if (wawa.taskIsAccomplished())
		{
			break;
		}

		//移动一格
		if (wawa.downsideIsClear() && movedup==false)  //优先向下走。但如果上一步向上走了，这一步不能向下走，否则会原地折返
			{
				wawa.moveDown();
				movedup=false;
			}
		else if (wawa.rightIsClear()) //如果不向下走,就尝试向右走
			{
				wawa.moveRight();
				movedup=false;
			}
		else
			{
				wawa.moveUp(); //如果向右走不了,就必须向上走
				movedup=true;
			}
	}
}

void BEGIN()
{
	printf("\n按下任意键后开始执行你的指令。");
	_getch();
}

void END(XWawa &wawa)
{
	printf("\n所有指令已执行完毕。");
	if (wawa.taskIsAccomplished())
	{
		cout<<"\n恭喜！任务已完成。瓦瓦移动了"<<wawa.GetMoveCount()<<"次。";
	}
	else
	{
		printf("\n很遗憾，任务没有完成。修改代码，再试一次吧。");
	}
	printf("\n按下任意键后退出程序...\n");
	_getch();
}
