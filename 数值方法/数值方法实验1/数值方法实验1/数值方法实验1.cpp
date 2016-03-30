// 数值计算方法实验一.cpp : 定义控制台应用程序的入口点。
//方程求根

#include "stdafx.h"
#include "iostream"
#include "iomanip"
using namespace std;
//求f(x)=x3+4x2-10


//二分法求解f(x)=x3+4x2-10=0在[1,2]内的一个实根
double value(double x)
{
	return x*x*x + 4 * x*x - 10;
}
double dichotomy(double left, double right)
{
	double m = (right + left) / 2;
	if (value(m) == 0)
	{
		return m;
	}
	if (abs(right - left) / 2 <= 0.000005)
	{
		return m;
	}
	double s = value(m);
	if (s*value(left)>0)
	{
		return dichotomy(m, right);
	}
	else
	{
		return dichotomy(left, m);
	}
}

//迭代法
double value1(double x)
{
	return 0.5*sqrt(10 - x*x*x);
}
double iterative(double x)
{
	double y = value1(x);
	if (abs(value1(y) - y) <0.000005)
	{
		return value1(y);
	}
	return iterative(value1(y));
}

//牛顿法
double value2(double x)
{
	return value(x) / (3 * x*x + 8 * x);
}
double nfunction(double x)
{
	if (abs(x - value2(x) - x)  < 0.000005)
		return x - value2(x);
	return nfunction(x - value2(x));
}

//割线法
double secantM(double x0, double x1)
{
	if (abs(x0 - x1)  < 0.000005)
		return x1;
	return secantM(x1, x1 - value(x1) / (value(x1) - value(x0))*(x1 - x0));
}

int main()
{
	//cout 默认输出6位小数，可用cout << setprecision(n) << x；扩展，n为小数位数
	cout << "二分法计算结果：" << endl;
	cout << setprecision(10) << dichotomy(1, 2) << endl;
	cout << "迭代法计算结果：" << endl;
	cout << setprecision(10) << iterative(1.5) << endl;
	cout << "牛顿法计算结果：" << endl;
	cout << setprecision(10) << nfunction(1.5) << endl;
	cout << "割线法计算结果：" << endl;
	cout << setprecision(10) << secantM(1, 2) << endl;
	system("pause");
	return 0;
}