#include <iostream>
using namespace std;
int main()
{
	int a = 0, b = 1, c, n,i;
		cout << "請輸入一個正整數:";
		cin >> n;
		if (n == 1) 
		{
			cout << a << endl;
		}
		if (n >= 2)
		{
			cout << a << endl;
			cout << b << endl;
			for (i = 3; i <= n+1; i++)
			{
				c = a + b;
				a = b;
				b = c;
				cout << c<<endl;
			}
		}
    
}

