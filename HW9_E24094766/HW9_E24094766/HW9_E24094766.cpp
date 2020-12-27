#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	fstream file;
	string choose;
	double minsup;
	double minconfi;
	cout << "請輸入檔名，包含.txt";
	cin >> choose;
	cout << "請輸入min support再輸入min confidence";
	cin >> minsup >> minconfi;
	file.open(choose, ios::in);
	if (!file)
		cout << "檔案開起失敗";
	vector<string>check;
	string temp;
	while (getline(file, temp))
	{
		check.push_back(temp);
	}
	vector<vector<int>>data;
	for (int i = 0; i < check.size(); i++)
	{
		vector<int>a;
		for (int j = 0; j < 10; j++)
		{
			a.push_back(0);
		}
		data.push_back(a);
	}
	for (int i = 0; i < check.size(); i++)
	{
		for (int j = 0; j < check[i].size(); j++)
		{
			if (check[i][j] == 'A')
				data[i][0] = 1;
			if (check[i][j] == 'B')
				data[i][1] = 1;
			if (check[i][j] == 'C')
				data[i][2] = 1;
			if (check[i][j] == 'D')
				data[i][3] = 1;
			if (check[i][j] == 'E')
				data[i][4] = 1;
			if (check[i][j] == 'F')
				data[i][5] = 1;
			if (check[i][j] == 'G')
				data[i][6] = 1;
			if (check[i][j] == 'H')
				data[i][7] = 1;
			if (check[i][j] == 'I')
				data[i][8] = 1;
			if (check[i][j] == 'J')
				data[i][9] = 1;
		}
	}
	///////////////////////////////////////////////////////////////////////////////////////////////
	vector <string> frequentpattern;
	char a = 'A';
	char b = 'A';
	char c = 'A';
	char d = 'A';
	char e = 'A';
	double p = 0;
	for (int K = 0; K < 5; K++)
	{
		if (K == 0)
		{
			for (int j = 0; j < 10; j++)
			{
				double total = 0;
				for (int i = 0; i < data.size(); i++)
				{
					total = data[i][j] + total;
				}
				if (total / data.size() >= minsup)
				{
					a = 'A';
					a = a + j;
					string pattern;
					pattern = a;
					frequentpattern.push_back(pattern);
				}
			}
		}
		if (K == 1)
		{
			for (int j = 0; j < 10; j++)
			{
				for (int l = j + 1; l < 10; l++)
				{
					double count = 0;
					for (int i = 0; i < data.size(); i++)
					{
						if (data[i][j] == 1 && data[i][l] == 1)
						{
							count++;
						}
					}
					if (count / data.size() >= minsup)
					{
						a = 'A';
						b = 'A';
						a = a + j;
						b = b + l;
						string pattern;
						pattern = a;
						pattern = pattern + b;
						frequentpattern.push_back(pattern);
					}
				}
			}
		}
		if (K == 2)
		{
			for (int j = 0; j < 10; j++)
			{
				for (int l = j + 1; l < 10; l++)
				{
					for (int m = l + 1; m < 10; m++)
					{
						double count = 0;
						for (int i = 0; i < data.size(); i++)
						{
							if (data[i][j] == 1 && data[i][l] == 1 && data[i][m] == 1)
							{
								count++;
							}
						}
						if (count / data.size() >= minsup)
						{
							a = 'A';
							b = 'A';
							c = 'A';
							a = a + j;
							b = b + l;
							c = c + m;
							string pattern;
							pattern = a;
							pattern = pattern + b;
							pattern = pattern + c;
							frequentpattern.push_back(pattern);
						}
					}
				}
			}
		}
		if (K == 3)
		{
			for (int j = 0; j < 10; j++)
			{
				for (int l = j + 1; l < 10; l++)
				{
					for (int m = l + 1; m < 10; m++)
					{
						for (int n = m + 1; n < 10; n++)
						{
							double count = 0;
							for (int i = 0; i < data.size(); i++)
							{
								if (data[i][j] == 1 && data[i][l] == 1 && data[i][m] == 1 && data[i][n] == 1)
								{
									count++;
								}
							}
							if (count / data.size() >= minsup)
							{
								a = 'A';
								b = 'A';
								c = 'A';
								d = 'A';
								a = a + j;
								b = b + l;
								c = c + m;
								d = d + n;
								string pattern;
								pattern = a;
								pattern = pattern + b;
								pattern = pattern + c;
								pattern = pattern + d;
								frequentpattern.push_back(pattern);
							}
						}
					}
				}
			}
		}
		if (K == 4)
		{
			for (int j = 0; j < 10; j++)
			{
				for (int l = j + 1; l < 10; l++)
				{
					for (int m = l + 1; m < 10; m++)
					{
						for (int n = m + 1; n < 10; n++)
						{
							for (int o = n + 1; o < 10; o++)
							{
								double count = 0;
								for (int i = 0; i < data.size(); i++)
								{
									if (data[i][j] == 1 && data[i][l] == 1 && data[i][m] == 1 && data[i][n] == 1 && data[i][o] == 1)
									{
										count++;
									}
								}
								if (count / data.size() >= minsup)
								{
									a = 'A';
									b = 'A';
									c = 'A';
									d = 'A';
									e = 'A';
									a = a + j;
									b = b + l;
									c = c + m;
									d = d + n;
									e = e + o;
									string pattern;
									pattern = a;
									pattern = pattern + b;
									pattern = pattern + c;
									pattern = pattern + d;
									pattern = pattern + e;
									frequentpattern.push_back(pattern);
								}
							}
						}
					}
				}
			}
		}
	}
	//////////////////////////////////////////////////////////////////////////////

	for (int i = 0; i < frequentpattern.size(); i++)
	{
		for (int j = 0; j < frequentpattern.size(); j++)
		{
			vector<int>transform;
			int f = 0;
			double count1 = 0;
			double count2 = 0;
			if (i == j)
				continue;
			for (int k = 0; k < frequentpattern[i].size(); k++)
			{
				for (int l = 0; l < frequentpattern[j].size(); l++)
				{
					if (frequentpattern[i][k] == frequentpattern[j][l])
						goto next;
				}
			}
			
			for (int k = 0; k < frequentpattern[i].size(); k++)
			{
				f = frequentpattern[i][k] - 65;
				transform.push_back(f);
			}
			for (int k = 0; k < data.size(); k++)
			{
				if (transform.size() == 1)
				{
					for (int l = 0; l < data.size(); l++)
					{
						if (data[l][transform[0]] == 1)
							count1++;
					}
					for (int l = 0; l < frequentpattern[j].size(); l++)
					{
						f = frequentpattern[j][l] - 65;
						transform.push_back(f);
					}
					if (transform.size() == 2)
					{
						for (int l = 0; l < data.size(); l++)
						{
							if (data[l][transform[0]] == 1 && data[l][transform[1]] == 1)
								count2++;
						}
						if (count2 / count1 >= minconfi)
						{
							cout << frequentpattern[i] << "->" << frequentpattern[j] << "(" << count2 << "/" << count1 << ")" << "\n";
							goto next;
						}
						goto next;
					}
					if (transform.size() == 3)
					{
						for (int l = 0; l < data.size(); l++)
						{
							if (data[l][transform[0]] == 1 && data[l][transform[1]] == 1 && data[l][transform[2]] == 1)
								count2++;
						}
						if (count2 / count1 >= minconfi)
						{
							cout << frequentpattern[i] << "->" << frequentpattern[j] << "(" << count2 << "/" << count1 << ")" << "\n";
							goto next;
						}
						goto next;
					}
					if (transform.size() == 4)
					{
						for (int l = 0; l < data.size(); l++)
						{
							if (data[l][transform[0]] == 1 && data[l][transform[1]] == 1 && data[l][transform[2]] == 1 && data[l][transform[3]] == 1)
								count2++;
						}
						if (count2 / count1 >= minconfi)
						{
							cout << frequentpattern[i] << "->" << frequentpattern[j] << "(" << count2 << "/" << count1 << ")" << "\n";
							goto next;
						}
						goto next;
					}
					if (transform.size() == 5)
					{
						for (int l = 0; l < data.size(); l++)
						{
							if (data[l][transform[0]] == 1 && data[l][transform[1]] == 1 && data[l][transform[2]] == 1 && data[l][transform[3]] == 1 && data[l][transform[4]] == 1)
								count2++;
						}
						if (count2 / count1 >= minconfi)
						{
							cout << frequentpattern[i] << "->" << frequentpattern[j] << "(" << count2 << "/" << count1 << ")" << "\n";
							goto next;
						}
						goto next;
					}
				}
				if (transform.size() == 2)
				{
					for (int l = 0; l < data.size(); l++)
					{
						if (data[l][transform[0]] == 1 && data[l][transform[1]] == 1)
							count1++;
					}
					for (int l = 0; l < frequentpattern[j].size(); l++)
					{
						f = frequentpattern[j][l] - 65;
						transform.push_back(f);
					}
					if (transform.size() == 3)
					{
						for (int l = 0; l < data.size(); l++)
						{
							if (data[l][transform[0]] == 1 && data[l][transform[1]] == 1 && data[l][transform[2]] == 1)
								count2++;
						}
						if (count2 / count1 >= minconfi)
						{
							cout << frequentpattern[i] << "->" << frequentpattern[j] << "(" << count2 << "/" << count1 << ")" << "\n";
							goto next;
						}
						goto next;
					}
					if (transform.size() == 4)
					{
						for (int l = 0; l < data.size(); l++)
						{
							if (data[l][transform[0]] == 1 && data[l][transform[1]] == 1 && data[l][transform[2]] == 1 && data[l][transform[3]] == 1)
								count2++;
						}
						if (count2 / count1 >= minconfi)
						{
							cout << frequentpattern[i] << "->" << frequentpattern[j] << "(" << count2 << "/" << count1 << ")" << "\n";
							goto next;
						}
						goto next;
					}
					if (transform.size() == 5)
					{
						for (int l = 0; l < data.size(); l++)
						{
							if (data[l][transform[0]] == 1 && data[l][transform[1]] == 1 && data[l][transform[2]] == 1 && data[l][transform[3]] == 1 && data[l][transform[4]] == 1)
								count2++;
						}
						if (count2 / count1 >= minconfi)
						{
							cout << frequentpattern[i] << "->" << frequentpattern[j] << "(" << count2 << "/" << count1 << ")" << "\n";
							goto next;
						}
						goto next;
					}
				}
				if (transform.size() == 3)
				{
					for (int l = 0; l < data.size(); l++)
					{
						if (data[l][transform[0]] == 1 && data[l][transform[1]] == 1 && data[l][transform[2]] == 1)
							count1++;
					}
					for (int l = 0; l < frequentpattern[j].size(); l++)
					{
						f = frequentpattern[j][l] - 65;
						transform.push_back(f);
					}
					if (transform.size() == 4)
					{
						for (int l = 0; l < data.size(); l++)
						{
							if (data[l][transform[0]] == 1 && data[l][transform[1]] == 1 && data[l][transform[2]] == 1 && data[l][transform[3]] == 1)
								count2++;
						}
						if (count2 / count1 >= minconfi)
						{
							cout << frequentpattern[i] << "->" << frequentpattern[j] << "(" << count2 << "/" << count1 << ")" << "\n";
							goto next;
						}
						goto next;
					}
					if (transform.size() == 5)
					{
						for (int l = 0; l < data.size(); l++)
						{
							if (data[l][transform[0]] == 1 && data[l][transform[1]] == 1 && data[l][transform[2]] == 1 && data[l][transform[3]] == 1 && data[l][transform[4]] == 1)
								count2++;
						}
						if (count2 / count1 >= minconfi)
						{
							cout << frequentpattern[i] << "->" << frequentpattern[j] << "(" << count2 << "/" << count1 << ")" << "\n";
							goto next;
						}
						goto next;
					}

				}
				if (transform.size() == 4)
				{
					for (int l = 0; l < data.size(); l++)
					{
						if (data[l][transform[0]] == 1 && data[l][transform[1]] == 1 && data[l][transform[2]] == 1 && data[l][transform[3]] == 1)
							count1++;
					}
					for (int l = 0; l < frequentpattern[j].size(); l++)
					{
						f = frequentpattern[j][l] - 65;
						transform.push_back(f);
					}
					if (transform.size() == 5)
					{
						for (int l = 0; l < data.size(); l++)
						{
							if (data[l][transform[0]] == 1 && data[l][transform[1]] == 1 && data[l][transform[2]] == 1 && data[l][transform[3]] == 1 && data[l][transform[4]] == 1)
								count2++;
						}
						if (count2 / count1 >= minconfi)
						{
							cout << frequentpattern[i] << "->" << frequentpattern[j] << "(" << count2 << "/" << count1 << ")" << "\n";
							goto next;
						}
						goto next;
					}
				}
			}
		next:
			;
		}
	}
	system("pause");
	return 0;
}