// ��ֵ���㷽��ʵ��һ.cpp : �������̨Ӧ�ó������ڵ㡣
//�������

#include "stdafx.h"
#include "iostream"
#include "iomanip"
using namespace std;
//��f(x)=x3+4x2-10


//���ַ����f(x)=x3+4x2-10=0��[1,2]�ڵ�һ��ʵ��
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

//������
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

//ţ�ٷ�
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

//���߷�
double secantM(double x0, double x1)
{
	if (abs(x0 - x1)  < 0.000005)
		return x1;
	return secantM(x1, x1 - value(x1) / (value(x1) - value(x0))*(x1 - x0));
}

int main()
{
	//cout Ĭ�����6λС��������cout << setprecision(n) << x����չ��nΪС��λ��
	cout << "���ַ���������" << endl;
	cout << setprecision(10) << dichotomy(1, 2) << endl;
	cout << "��������������" << endl;
	cout << setprecision(10) << iterative(1.5) << endl;
	cout << "ţ�ٷ���������" << endl;
	cout << setprecision(10) << nfunction(1.5) << endl;
	cout << "���߷���������" << endl;
	cout << setprecision(10) << secantM(1, 2) << endl;
	system("pause");
	return 0;
}