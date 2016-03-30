///高斯消元法

#pragma once
#include "iostream"
using namespace std;
class Equations
{
public:
	Equations(double arr[3][4]);
	~Equations(){}
	void solve();
	void show();
private:
	double equation[3][4];
	double result[3];
};
Equations::Equations(double arr[3][4])
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 4; j++)
			equation[i][j] = arr[i][j];
	solve();
}
void Equations::solve()
{
	for (int k = 0; k < 3; k++)
	{
		for (int i = 0; i < 3; i++)
		{
			if (i == k)continue;
			if (equation[i][k] == 0)continue;
			double temp = equation[i][k] / equation[k][k];
			for (int j = 0; j < 4; j++)
			{
				equation[i][j] -=  equation[k][j] * temp;
			}
		}
	}
	for (int i = 0; i < 3; i++)
	{
		result[i] = equation[i][3] / equation[i][i];
	}
}
void Equations::show()
{
	cout << "equation:" << endl;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << equation[i][j] << "\t";
		cout << endl;
	}
	cout << "The result is:" << endl;
	for (int i = 0; i < 3; i++)
	{
		cout << "x" << i << "=" << result[i] << endl;
	}
}