#include<iostream>
#include<ctime>
#include <stdlib.h>
#include<iomanip>
using namespace std;

int main()
{
	int row_size = 0;
	int column_size = 0;
	int type;
	int sum;

	cout << "Please enter the lenth of 2D matrix"<<endl;
	cout << "row:";
	cin >> row_size;
	while (row_size <= 0) {
		cout << "Error! Please enter a number." << endl;
		cout << "row:";
		cin >> row_size;
	}
	cout << "column:";
	cin>> column_size;
	while (column_size <= 0) {
		cout << "Error! Please enter a number." << endl;
		cout << "column:";
		cin >> column_size;
	}

	cout << "Please choose the type:" << endl;
	cout << "Type 1 input by user." << endl;
	cout << "Type 2 use random numbers by computer." << endl;
	cout << "choose type:";
	cin >> type;

	while (type != 1 && type != 2) {
		cout << "Error! Please choose type 1 or 2" << endl;
		cout << "choose type:";
		cin >> type;
	}
	double **array;
	array = new double* [row_size];
	for (int i = 0; i < row_size; i++)
	{
		array[i] = new double[column_size];
	}
	if (type == 1) 
	{
		cout << "Please enter the numbers.";
		for (int i = 0; i < row_size; i++) 
		{
			for (int j=0; j < column_size;j++) 
			{
				cin >> array[i][j];
			}
		}
	}
	else if(type==2) {
		srand(time(NULL));
		for (int i = 0; i < row_size; i++) 
		{
			for (int j=0; j < column_size; j++) 
			{
				array[i][j] = rand() % (201) - 100;
			}
		}
	}
	cout << "***************************************" << endl;
	cout << "母矩陣:" << endl;
	for (int i = 0; i < row_size; i++) 
	{
		for (int j = 0; j < column_size; j++) 
		{
			cout<<setw(4)<< array[i][j];
		}
		cout << endl;
	}
	cout << "****************************************" << endl;
	cout << "最大子矩陣:"<<endl;
	int max2=-99999999999999999;
	int w, x, y, z;
	for (int i = 0; i < row_size; i++) 
	{
		for (int i2 = i; i2 < row_size; i2++) 
		{
			for (int j = 0; j < column_size; j++) 
			{
				for (int j2 = j; j2 < column_size; j2++) 
				{
					int max=0;
					for (int k = i; k <= i2; k++) 
					{
						for (int l = j; l <= j2; l++) 
						{
							max += array[k][l];
						}
					}
					if (max > max2) 
					{
						max2 = max;
						w = i;
						x = i2;
						y = j;
						z = j2;
					}
				}
			}
		}
	}
	for (int m = w; m <= x; m++) 
	{
		for (int n = y; n <= z; n++) 
		{
			cout<<setw(4)<< array[m][n];
		}
		cout<<endl;
	}
	cout << "****************************************" << endl;
	cout << "最大值:"<<endl;
	cout << max2;
}