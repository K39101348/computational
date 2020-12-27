#include<iostream>
#include<fstream>
#include<string>
#include<vector> 
using namespace std;
int main()
{
	/////////開啟檔案//////////////
	fstream file;
	string choose;
	cout << "請輸入檔名，包含.txt";
	cin >> choose;
	file.open(choose, ios::in);
	if (!file)
		cout << "檔案開起失敗";
	vector<string>input;
	string temp;
	string a;

	while (getline(file, temp))
	{
		input.push_back(temp);
	}
	
		/////////////////建構LCS表格///////////////////////
		for (int i = 0; i < input.size(); i = i + 2)//讓數據兩筆兩筆讀
		{
			int m = input[i].size() + 1;
			int n = input[i + 1].size() + 1;
			vector<vector<vector<string>>>length(m, vector<vector<string>>(n, vector<string>(1)));
			for (int j = 1; j <= input[i].size(); j++)        //讀取並建立表格
			{
				for (int k = 1; k <= input[i + 1].size(); k++)
				{
					if (input[i][j - 1] == input[i + 1][k - 1])  //字元相等時
					{
						for (int i1 = 0; i1 < length[j][k - 1].size(); i1++) {
							a = length[j - 1][k - 1] + input[i][j - 1][i1]
								length[j][k].push_back(a);  //來自左上
						}
					}
					if (input[i][j - 1] != input[i + 1][k - 1])  //字元不等時
					{
						if (length[j - 1][k][0].size() < length[j][k - 1][0].size())
						{
							for (int i1 = 0; i1 < length[j][k - 1].size(); i1++)
							{
								length[j][k].push_back(length[j][k - 1][i1]);
							}
							//來自左方
						}
						if (length[j - 1][k][0].size() > length[j][k - 1][0].size())
						{
							for (int i1 = 0; i1 < length[j][k - 1].size(); i1++)
							{
								length[j][k] = length[j - 1][k][i1];      //來自上方
							}
						}
					}
				}
			}
			string maxlen = length[m - 1][n - 1]; //長度表格對右下角必為lcs長度
			
			


		}
	fstream file;
	file.open("result_E24094766.txt", ios::out);
	file << "lcs長度為" length[m - 1][n - 1] << "\n";
	file << "LCS為" << maxlen.size();
	system("pause");
	return 0;
}