#include<iostream>
#include<string>
#include<math.h>
#include<sstream>
using namespace std;
 int main()
 {
	 int a;
	 int array[7][7] = { 0 };
	 //float n;
	 string x;
	 cout << "輸入0到6的整數" << endl;
	 int ans=0;
	 while (getline(cin, x))                                                  //防呆空白格
	 {
		 stringstream sa(x);
		 if (!(sa >> ans))                                                   //防呆非整數
		 {
			 cout << "error! input integer plz:";
		 }
		 else if (!sa.eof())                                                 //防呆小數
		 {
			 cout << "error! input integer plz:";
		 }
		 else
		 {
			 stringstream ss(x.c_str());
			 ss >> a;
			 if (a < 0 || a>6)                                                       //防呆0或是負數
			 {
				 cout << "error! input integer from 0 to 6 plz:";
				 continue;
			 }
			 else
			 {
				 break;
			 }
		 }
	 }
	 for (int i = 0; i < 7; i++) 
	 {
		 array[i][a]=1;
		 a = a + 2;
		 if (a > 6)
		 {
			 a = a - 7;
		 }

	 }
	 for (int i = 0; i < 7; i++) {
		 for (int j = 0; j < 7; j++) {
			 if (array[i][j]==1)
			 {
				 cout << j;
			 }
		 }
	 }
 }