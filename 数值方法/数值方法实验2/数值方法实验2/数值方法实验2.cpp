// ��ֵ����ʵ��2.cpp : �������̨Ӧ�ó������ڵ㡣
//���Է������ֱ�ӽⷨ������˹��Ԫ��

#include "stdafx.h"
#include "GaussMethed.h"
#include "iostream"
using namespace std;

int main()
{
	//��˹��Ԫ��
	double arr[3][4] = { {1,2,3,14},{0,1,2,8},{2,4,1,13} };
	Equations e(arr);
	e.show();
	system("pause");
    return 0;
}

