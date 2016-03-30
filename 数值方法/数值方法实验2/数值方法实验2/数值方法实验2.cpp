// 数值方法实验2.cpp : 定义控制台应用程序的入口点。
//线性方程组的直接解法——高斯消元法

#include "stdafx.h"
#include "GaussMethed.h"
#include "iostream"
using namespace std;

int main()
{
	//高斯消元法
	double arr[3][4] = { {1,2,3,14},{0,1,2,8},{2,4,1,13} };
	Equations e(arr);
	e.show();
	system("pause");
    return 0;
}

