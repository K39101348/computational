#include<iostream>
using namespace std;
int main() {
	float number=6;//定義 number為正整數
	while (number !=0 & number != 1 & number != 2 & number != 3 & number != 4 & number != 5  ) {
		cout << "Please enter a number 0 to 5 : ";//不符合要求的數字進入迴圈
		cin >> number;//讓使用者輸入數字
		}
	if (number == 0) {
		cout << "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊" << endl;
		cout << "＊Name： WEI-LU LIN 　　　　　  ＊" << endl;
		cout << "＊E-mail：K39101348＠gmail.com  ＊" << endl;
		cout << "＊Birthday：July 27th　 　　　  ＊" << endl;
		cout << "＊Height：183cm　　　　　　 　  ＊" << endl;
		cout << "＊ｗeight：64kg                 ＊" << endl;
		cout << "＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊＊" << endl;//輸入0的時候跑出名牌
	}
	if (number == 1)
		cout << "*" << endl;//輸入1跑出一顆星
	if (number == 2)
		cout << "**" << endl;//輸入2跑出二顆星
	if (number == 3)
		cout << "***" << endl;//輸入3跑出三顆星
	if (number == 4)
		cout << "****" << endl;//輸入4跑出四顆星
	if (number == 5)
		cout << "*****" << endl;//輸入5跑出五顆星
	
}