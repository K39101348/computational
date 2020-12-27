#include<iostream>
#include<iomanip>
#include<stdio.h>
using namespace std;
void hanoi_function(int n,char init,char pass,char target) //自定義函數 n是層數 init是初始 pass是過渡的位置 target是最後要到的地方
{
	if (n >= 1)
	{ 
		hanoi_function(n - 1, init, target, pass); //遞迴
		cout << "move plate " << n <<" from "<<init<< " to " << target << endl;
		hanoi_function(n - 1, pass, init, target);
		
	}
	else
		return;
}
int main()
{
	double n;
	cout << "please input an intger:";
	do
	{
		cin >> n;
		if (cin.fail() || n <= 0|| n-(int)n!=0) //沒符合條件時的防呆
		{
			cout << "input error please input again.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else 
		{
			break;//符合條件
		}
	} while ((cin.fail() || n <= 0 || n - (int)n != 0));
	hanoi_function(n, 'A', 'B', 'C');//叫出自定義函式
	return 0;
}