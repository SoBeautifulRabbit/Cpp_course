//
//	公用工具类
//  此类提供了一组实用的功能函数。
//
//	Created by ZhangHua @ 2015-04
//  Updated by ZhangHua @ 2018-04
//  学生：李东旭 学号：2015301510021
//		-用string类处理字符串

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "XUtility.h"

//下方用到的函数localtime在Visual Studio2017中将被弃用，该命令使编译器不报错：
#pragma warning(disable:4996)

string XUtility::GetCurDateTime()
{
	time_t t = time(NULL);
    char tmp[20];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %X", localtime(&t));
	return string(tmp);
}