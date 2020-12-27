#include<iostream>
#include<iomanip>
#include<ctime>
#include<cstdlib>
#include<vector>
using namespace std;
char cards[76] = { 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'A', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'C',  'C',  'C',  'C',  'C',  'C',  'C',  'C',  'C', 'D',  'D',  'D',  'D',  'D',  'D',  'D',  'D',  'D','E','E','E','E','E','E','E','E','E','F','F','F','F','F','F','F','F','F','G','G','G','G','G','G','G','G','G','h','h','h','i','i','i','i','i','i','i','i','i','i' };
//牌庫
int a;
const int light = 4;
const int posi = 3;
char table[light][posi] = { 'o','o','o','o','o','o','o','o','o','o','o','o' };//桌面
int answer;//使用者放牌的變數
int b;
void outputtable(void);//輸出桌面上的狀況
int c = -1;//使用者輸入0即為抽牌 1即為收牌
void rotate1(void);//user-AI1-AI2-AI3
void rotate2(void);//AI1-AI2-AI3-user
void rotate3(void);//AI2-AI3-user-AI1
void rotate4(void);//AI3-user-AI1-AI2
void outputpocket(void);//輸出所有玩家的手牌
int A = 0, B = 0, C = 0, D = 0, E = 0, F = 0, G = 0, h = 0, l = 0;//計算玩家各種手牌的數量
vector<char>user(100, 'o');
vector<char>AI1(100, 'o');
vector<char>AI2(100, 'o');
vector<char>AI3(100, 'o');
//儲存所有玩家的手牌
int lightAns = -1;
vector<int>lighting(4, 0);
int AI1bool1 = 0;
int AI1bool2 = 0;
int AI1bool3 = 0;
int AI1bool4 = 0;
int AI2bool1 = 0;
int AI2bool2 = 0;
int AI2bool3 = 0;
int AI2bool4 = 0;
int AI3bool1 = 0;
int AI3bool2 = 0;
int AI3bool3 = 0;
int AI3bool4 = 0;
//AI判斷收牌抽牌的變數
void AI1turn();
void AI2turn();
void AI3turn();
void userturn();
int usertake = 0;
int AI1take = 0;
int AI2take = 0;
int AI3take = 0;
int endcounter = 0;//倒數第16張維結束牌 用一個變數計算
void score();//計算最後成績並輸出
int userscore = 0, AI1score = 0, AI2score = 0, AI3score = 0;//儲存成績的變數
int main()
{
	srand(time(0));
	//發給四位玩家各一張不相同顏色的牌
	while (user[0] == AI1[0] || user[0] == AI2[0] || user[0] == AI3[0] || AI1[0] == AI2[0] || AI1[0] == AI3[0] || AI2[0] == AI3[0])
	{
		a = rand() % 76;
		while (cards[a] == 'X' || cards[a] == 'h' || cards[a] == 'i')
		{
			a = rand() % 76;
		}
		user[0] = cards[a];
		cards[a] = 'X';

		a = rand() % 76;
		while (cards[a] == 'X' || cards[a] == 'h' || cards[a] == 'i')
		{
			a = rand() % 76;
		}
		AI1[0] = cards[a];
		cards[a] = 'X';

		a = rand() % 76;
		while (cards[a] == 'X' || cards[a] == 'h' || cards[a] == 'i')
		{
			a = rand() % 76;
		}
		AI2[0] = cards[a];
		cards[a] = 'X';

		a = rand() % 76;
		while (cards[a] == 'X' || cards[a] == 'h' || cards[a] == 'i')
		{
			a = rand() % 76;
		}
		AI3[0] = cards[a];
		cards[a] = 'X';
	}
	outputtable();
	outputpocket();
	rotate1();
	while (endcounter < 61)//遊戲輪轉
	{
		if (usertake == -1)
		{
			rotate1();
		}
		else if (AI1take == -1)
		{
			rotate2();
		}
		else if (AI2take == -1)
		{
			rotate3();
		}
		else if (AI3take == -1)
		{
			rotate4();
		}
		endcounter = 0;
		for (int i = 0; i < 100; i++)//判斷遊戲何時結束
		{
			if (user[i] != 'o')
				endcounter++;
			if (AI1[i] != 'o')
				endcounter++;
			if (AI2[i] != 'o')
				endcounter++;
			if (AI3[i] != 'o')
				endcounter++;
		}
		cout << "endcounter=" << endcounter << endl;
	}
	score();//輸出成績
	cout << "game ends" << endl;
	system("pause");
	return 0;
}
void outputtable()//輸出桌面狀況
{
	for (int i = 0; i < light; i++)
	{
		if (lighting[i] == 0)//燈如果已經關掉就不輸出
		{
			cout << "light" << i + 1 << setw(2);
			for (int j = 0; j < posi; j++)
			{
				if (table[i][j] == 'A')
					cout << "red" << setw(3);
				else if (table[i][j] == 'B')
					cout << "orange" << setw(3);
				else if (table[i][j] == 'C')
					cout << "pink" << setw(3);
				else if (table[i][j] == 'D')
					cout << "green" << setw(3);
				else if (table[i][j] == 'E')
					cout << "blue" << setw(3);
				else if (table[i][j] == 'F')
					cout << "grey" << setw(3);
				else if (table[i][j] == 'G')
					cout << "yellow" << setw(3);
				else if (table[i][j] == 'h')
					cout << "彩" << setw(3);
				else if (table[i][j] == 'i')
					cout << "加" << setw(3);
				else
					cout << table[i][j] << setw(3);
			}
			cout << endl;
		}
	}
}
void outputpocket()//輸出大家手牌
{
	A = 0; B = 0; C = 0; D = 0; E = 0; F = 0; G = 0; h = 0; l = 0;
	for (int k = 0; k < 100; k++)//判斷使用者手牌有哪些
	{
		if (user[k] == 'A')
			A++;
		else if (user[k] == 'B')
			B++;
		else if (user[k] == 'C')
			C++;
		else if (user[k] == 'D')
			D++;
		else if (user[k] == 'E')
			E++;
		else if (user[k] == 'F')
			F++;
		else if (user[k] == 'G')
			G++;
		else if (user[k] == 'h')
			h++;
		else if (user[k] == 'i')
			l++;
	}
	cout << "***********User***********" << endl;
	cout << "red";
	for (int k = 0; k < A; k++)//以*數量來表達各種顏色數量
	{
		cout << "*";
	}
	cout << endl;
	cout << "orange";
	for (int k = 0; k < B; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "pink";
	for (int k = 0; k < C; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "green";
	for (int k = 0; k < D; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "blue";
	for (int k = 0; k < E; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "grey";
	for (int k = 0; k < F; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "yellow";
	for (int k = 0; k < G; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "彩色";
	for (int k = 0; k < h; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "加二";
	for (int k = 0; k < l; k++)
	{
		cout << "*";
	}
	A = 0; B = 0; C = 0; D = 0; E = 0; F = 0; G = 0; h = 0; l = 0;
	cout << endl;
	/******************************************************************************************************************/
	for (int k = 0; k < 100; k++)//判斷AI手牌
	{
		if (AI1[k] == 'A')
			A++;
		else if (AI1[k] == 'B')
			B++;
		else if (AI1[k] == 'C')
			C++;
		else if (AI1[k] == 'D')
			D++;
		else if (AI1[k] == 'E')
			E++;
		else if (AI1[k] == 'F')
			F++;
		else if (AI1[k] == 'G')
			G++;
		else if (AI1[k] == 'h')
			h++;
		else if (AI1[k] == 'i')
			l++;
	}
	cout << "***********AI1***********" << endl;
	cout << "red";
	for (int k = 0; k < A; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "orange";
	for (int k = 0; k < B; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "pink";
	for (int k = 0; k < C; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "green";
	for (int k = 0; k < D; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "blue";
	for (int k = 0; k < E; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "gray";
	for (int k = 0; k < F; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "yellow";
	for (int k = 0; k < G; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "彩色";
	for (int k = 0; k < h; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "加二";
	for (int k = 0; k < l; k++)
	{
		cout << "*";
	}
	A = 0; B = 0; C = 0; D = 0; E = 0; F = 0; G = 0; h = 0; l = 0;
	cout << endl;
	/**********************************************************************************************************************/
	for (int k = 0; k < 100; k++)
	{
		if (AI2[k] == 'A')
			A++;
		else if (AI2[k] == 'B')
			B++;
		else if (AI2[k] == 'C')
			C++;
		else if (AI2[k] == 'D')
			D++;
		else if (AI2[k] == 'E')
			E++;
		else if (AI2[k] == 'F')
			F++;
		else if (AI2[k] == 'G')
			G++;
		else if (AI2[k] == 'h')
			h++;
		else if (AI2[k] == 'i')
			l++;
	}
	cout << "***********AI2***********" << endl;
	cout << "red";
	for (int k = 0; k < A; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "orange";
	for (int k = 0; k < B; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "yellow";
	for (int k = 0; k < C; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "green";
	for (int k = 0; k < D; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "blue";
	for (int k = 0; k < E; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "gray";
	for (int k = 0; k < F; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "yellow";
	for (int k = 0; k < G; k++)
	{
		cout << "*";
	}cout << endl;
	cout << "彩色";
	for (int k = 0; k < h; k++)
	{
		cout << "*";
	}cout << endl;
	cout << "加二";
	for (int k = 0; k < l; k++)
	{
		cout << "*";
	}
	A = 0; B = 0; C = 0; D = 0; E = 0; F = 0; G = 0; h = 0; l = 0;
	cout << endl;
	/*********************************************************************************************************************/
	for (int k = 0; k < 100; k++)
	{
		if (AI3[k] == 'A')
			A++;
		else if (AI3[k] == 'B')
			B++;
		else if (AI3[k] == 'C')
			C++;
		else if (AI3[k] == 'D')
			D++;
		else if (AI3[k] == 'E')
			E++;
		else if (AI3[k] == 'F')
			F++;
		else if (AI3[k] == 'G')
			G++;
		else if (AI3[k] == 'h')
			h++;
		else if (AI3[k] == 'i')
			l++;
	}
	cout << "***********AI3***********" << endl;
	cout << "red";
	for (int k = 0; k < A; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "orange";
	for (int k = 0; k < B; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "pink";
	for (int k = 0; k < C; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "green";
	for (int k = 0; k < D; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "blue";
	for (int k = 0; k < E; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "gray";
	for (int k = 0; k < F; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "yellow";
	for (int k = 0; k < G; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "彩色";
	for (int k = 0; k < h; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "加二";
	for (int k = 0; k < l; k++)
	{
		cout << "*";
	}
	cout << endl;
	cout << "*************************" << endl;
}
void rotate1()//user-AI1-AI2-AI3
{
	usertake = 0; AI1take = 0; AI2take = 0;; AI3take = 0;
	for (int i = 0; i < 4; i++)
	{
		lighting[i] = 0;
	}
	while (lighting[0] == 0 || lighting[1] == 0 || lighting[2] == 0 || lighting[3] == 0)
	{
		
		if (usertake == 0)
			userturn();
		if (AI1take == 0)
			AI1turn();
		if (AI2take == 0)
			AI2turn();
		if (AI3take == 0)
			AI3turn();
		if (usertake != 0)
			usertake++;
		if (AI1take != 0)
			AI1take++;
		if (AI2take != 0)
			AI2take++;
		if (AI3take != 0)
			AI3take++;
		//判斷大家取牌的順序
	}
	//下一輪的第一個設為-1
	if (usertake < AI1take && usertake < AI2take && usertake < AI3take)
		usertake = -1;
	else if (AI1take < usertake && AI1take < AI2take && AI1take < AI3take)
		AI1take = -1;
	else if (AI2take < usertake && AI2take < AI1take && AI2take < AI3take)
		AI2take = -1;
	else if (AI3take < usertake && AI3take < AI2take && AI3take < AI1take)
		AI3take = -1;
	/***************************************************************************/
	else if (usertake == AI1take && usertake == AI2take && usertake < AI3take)
		AI2take = -1;
	else if (usertake == AI1take && usertake == AI3take && usertake < AI2take)
		AI3take = -1;
	else if (usertake == AI2take && usertake == AI3take && usertake < AI1take)
		AI3take = -1;
	else if (AI1take == AI2take && AI1take == AI3take && AI1take < usertake)
		AI3take = -1;
	/******************************************************************************/
	else if (usertake == AI1take && usertake < AI2take && usertake < AI3take)
		AI1take = -1;
	else if (usertake == AI2take && usertake < AI1take && usertake < AI3take)
		AI2take = -1;
	else if (usertake == AI3take && usertake < AI1take && usertake < AI2take)
		AI3take = -1;
	else if (AI1take == AI2take && AI1take < usertake && AI1take < AI3take)
		AI2take = -1;
	else if (AI1take == AI3take && AI1take < usertake && AI1take < AI2take)
		AI3take = -1;
	else if (AI2take == AI3take && AI2take < AI1take && AI2take < usertake)
		AI3take = -1;
	/******************************************************************************/
	else if (usertake == AI1take && usertake == AI2take && usertake == AI3take)
		AI3take == -1;
}
void rotate2()//AI1-AI2-AI3-user
{
	usertake = 0; AI1take = 0; AI2take = 0;; AI3take = 0;
	for (int i = 0; i < 4; i++)
	{
		lighting[i] = 0;
	}
	while (lighting[0] == 0 || lighting[1] == 0 || lighting[2] == 0 || lighting[3] == 0)
	{
		if (AI1take == 0)
			AI1turn();
		if (AI2take == 0)
			AI2turn();
		if (AI3take == 0)
			AI3turn();
		if (usertake == 0)
			userturn();
		if (usertake != 0)
			usertake++;
		if (AI1take != 0)
			AI1take++;
		if (AI2take != 0)
			AI2take++;
		if (AI3take != 0)
			AI3take++;
	}
	if (usertake < AI1take && usertake < AI2take && usertake < AI3take)
		usertake = -1;
	else if (AI1take < usertake && AI1take < AI2take && AI1take < AI3take)
		AI1take = -1;
	else if (AI2take < usertake && AI2take < AI1take && AI2take < AI3take)
		AI2take = -1;
	else if (AI3take < usertake && AI3take < AI2take && AI3take < AI1take)
		AI3take = -1;
	/***************************************************************************/
	else if (usertake == AI1take && usertake == AI2take && usertake < AI3take)
		usertake = -1;
	else if (usertake == AI1take && usertake == AI3take && usertake < AI2take)
		usertake = -1;
	else if (usertake == AI2take && usertake == AI3take && usertake < AI1take)
		usertake = -1;
	else if (AI1take == AI2take && AI1take == AI3take && AI1take < usertake)
		AI3take = -1;
	/******************************************************************************/
	else if (usertake == AI1take && usertake < AI2take && usertake < AI3take)
		usertake = -1;
	else if (usertake == AI2take && usertake < AI1take && usertake < AI3take)
		usertake = -1;
	else if (usertake == AI3take && usertake < AI1take && usertake < AI2take)
		usertake = -1;
	else if (AI1take == AI2take && AI1take < usertake && AI1take < AI3take)
		AI2take = -1;
	else if (AI1take == AI3take && AI1take < usertake && AI1take < AI2take)
		AI3take = -1;
	else if (AI2take == AI3take && AI2take < AI1take && AI2take < usertake)
		AI3take = -1;
	/******************************************************************************/
	else if (usertake == AI1take && usertake == AI2take && usertake == AI3take)
		usertake == -1;
}
void rotate3()//AI2-AI3-user-AI1
{
	usertake = 0; AI1take = 0; AI2take = 0;; AI3take = 0;
	for (int i = 0; i < 4; i++)
	{
		lighting[i] = 0;
	}
	while (lighting[0] == 0 || lighting[1] == 0 || lighting[2] == 0 || lighting[3] == 0)
	{
		if (AI2take == 0)
			AI2turn();
		if (AI3take == 0)
			AI3turn();
		if (usertake == 0)
			userturn();
		if (AI1take == 0)
			AI1turn();
		if (usertake != 0)
			usertake++;
		if (AI1take != 0)
			AI1take++;
		if (AI2take != 0)
			AI2take++;
		if (AI3take != 0)
			AI3take++;
	}
	if (usertake < AI1take && usertake < AI2take && usertake < AI3take)
		usertake = -1;
	else if (AI1take < usertake && AI1take < AI2take && AI1take < AI3take)
		AI1take = -1;
	else if (AI2take < usertake && AI2take < AI1take && AI2take < AI3take)
		AI2take = -1;
	else if (AI3take < usertake && AI3take < AI2take && AI3take < AI1take)
		AI3take = -1;
	/***************************************************************************/
	else if (usertake == AI1take && usertake == AI2take && usertake < AI3take)
		AI1take = -1;
	else if (usertake == AI1take && usertake == AI3take && usertake < AI2take)
		AI1take = -1;
	else if (usertake == AI2take && usertake == AI3take && usertake < AI1take)
		usertake = -1;
	else if (AI1take == AI2take && AI1take == AI3take && AI1take < usertake)
		AI1take = -1;
	/******************************************************************************/
	else if (usertake == AI1take && usertake < AI2take && usertake < AI3take)
		AI1take = -1;
	else if (usertake == AI2take && usertake < AI1take && usertake < AI3take)
		usertake = -1;
	else if (usertake == AI3take && usertake < AI1take && usertake < AI2take)
		usertake = -1;
	else if (AI1take == AI2take && AI1take < usertake && AI1take < AI3take)
		AI1take = -1;
	else if (AI1take == AI3take && AI1take < usertake && AI1take < AI2take)
		AI1take = -1;
	else if (AI2take == AI3take && AI2take < AI1take && AI2take < usertake)
		AI3take = -1;
	/******************************************************************************/
	else if (usertake == AI1take && usertake == AI2take && usertake == AI3take)
		AI1take == -1;
}
void rotate4()//AI3-user-AI1-AI2
{
	usertake = 0; AI1take = 0; AI2take = 0;; AI3take = 0;
	for (int i = 0; i < 4; i++)
	{
		lighting[i] = 0;
	}
	while (lighting[0] == 0 || lighting[1] == 0 || lighting[2] == 0 || lighting[3] == 0)
	{
		if (AI3take == 0)
			AI3turn();
		if (usertake == 0)
			userturn();
		if (AI1take == 0)
			AI1turn();
		if (AI2take == 0)
			AI2turn();
		if (usertake != 0)
			usertake++;
		if (AI1take != 0)
			AI1take++;
		if (AI2take != 0)
			AI2take++;
		if (AI3take != 0)
			AI3take++;
	}
	if (usertake < AI1take && usertake < AI2take && usertake < AI3take)
		usertake = -1;
	else if (AI1take < usertake && AI1take < AI2take && AI1take < AI3take)
		AI1take = -1;
	else if (AI2take < usertake && AI2take < AI1take && AI2take < AI3take)
		AI2take = -1;
	else if (AI3take < usertake && AI3take < AI2take && AI3take < AI1take)
		AI3take = -1;
	/***************************************************************************/
	else if (usertake == AI1take && usertake == AI2take && usertake < AI3take)
		AI2take = -1;
	else if (usertake == AI1take && usertake == AI3take && usertake < AI2take)
		AI1take = -1;
	else if (usertake == AI2take && usertake == AI3take && usertake < AI1take)
		AI2take = -1;
	else if (AI1take == AI2take && AI1take == AI3take && AI1take < usertake)
		AI2take = -1;
	/******************************************************************************/
	else if (usertake == AI1take && usertake < AI2take && usertake < AI3take)
		AI1take = -1;
	else if (usertake == AI2take && usertake < AI1take && usertake < AI3take)
		AI2take = -1;
	else if (usertake == AI3take && usertake < AI1take && usertake < AI2take)
		usertake = -1;
	else if (AI1take == AI2take && AI1take < usertake && AI1take < AI3take)
		AI2take = -1;
	else if (AI1take == AI3take && AI1take < usertake && AI1take < AI2take)
		AI1take = -1;
	else if (AI2take == AI3take && AI2take < AI1take && AI2take < usertake)
		AI2take = -1;
	/******************************************************************************/
	else if (usertake == AI1take && usertake == AI2take && usertake == AI3take)
		AI2take == -1;
}
void AI1turn()
{
	//以設定參數的方式讓AI判斷
	AI1bool1 = 0; AI1bool2 = 0; AI1bool3 = 0; AI1bool4 = 0;
	cout << "AI1 turn" << endl;
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < 3; j++)
			{
				if (table[i][j] == 'h')
					AI1bool1++;
				if (table[i][j] == 'i')
					AI1bool1 += 5;
				for (int k = 0; k < 100; k++)
				{
					if (table[i][j] == AI1[k] && AI1[k] != 'o')
						AI1bool1++;
				}
			}
		}
		else if (i == 1)
		{
			for (int j = 0; j < 3; j++)
			{
				if (table[i][j] == 'h')
					AI1bool2++;
				if (table[i][j] == 'i')
					AI1bool2 += 5;
				for (int k = 0; k < 100; k++)
				{
					if (table[i][j] == AI1[k] && AI1[k] != 'o')
						AI1bool2++;
				}
			}
		}
		else if (i == 2)
		{
			for (int j = 0; j < 3; j++)
			{
				if (table[i][j] == 'h')
					AI1bool3++;
				if (table[i][j] == 'i')
					AI1bool3 += 5;
				for (int k = 0; k < 100; k++)
				{
					if (table[i][j] == AI1[k] && AI1[k] != 'o')
						AI1bool3++;
				}
			}
		}
		else if (i == 3)
		{
			for (int j = 0; j < 3; j++)
			{
				if (table[i][j] == 'h')
					AI1bool4++;
				if (table[i][j] == 'i')
					AI1bool4 += 9;
				for (int k = 0; k < 100; k++)
				{
					if (table[i][j] == AI1[k] && AI1[k] != 'o')
						AI1bool4++;
				}
			}
		}
	}
	if (AI1bool1 > 2)
	{
		AI1take = 1;
		lighting[0] = 1;
		cout << "close 1" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI1[j] == 'o')
				{
					AI1[j] = table[0][i];
					table[0][i] = 'o';
				}
			}
		}
	}
	else if (AI1bool2 > 2)
	{
		AI1take = 1;
		lighting[1] = 1;
		cout << "close 2" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI1[j] == 'o')
				{
					AI1[j] = table[1][i];
					table[1][i] = 'o';
				}
			}
		}
	}
	else if (AI1bool3 > 2)
	{
		AI1take = 1;
		lighting[2] = 1;
		cout << "close 3" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI1[j] == 'o')
				{
					AI1[j] = table[2][i];
					table[2][i] = 'o';
				}
			}
		}
	}
	else if (AI1bool4 > 2)
	{
		AI1take = 1;
		lighting[3] = 1;
		cout << "close 4" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI1[j] == 'o')
				{
					AI1[j] = table[3][i];
					table[3][i] = 'o';
				}
			}
		}
	}
	else if (table[0][0] != 'o' && table[0][1] != 'o' && table[0][2] != 'o')
	{
		AI1take = 1;
		lighting[0] = 1;
		cout << "close 1" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI1[j] == 'o')
				{
					AI1[j] = table[0][i];
					table[0][i] = 'o';
				}
			}
		}
	}
	else if (table[1][0] != 'o' && table[1][1] != 'o' && table[1][2] != 'o')
	{
		AI1take = 1;
		lighting[1] = 1;
		cout << "close 2" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI1[j] == 'o')
				{
					AI1[j] = table[1][i];
					table[1][i] = 'o';
				}
			}
		}
	}
	else if (table[2][0] != 'o' && table[2][1] != 'o' && table[2][2] != 'o')
	{
		AI1take = 1;
		lighting[2] = 1;
		cout << "close 3" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI1[j] == 'o')
				{
					AI1[j] = table[2][i];
					table[2][i] = 'o';
				}
			}
		}
	}
	else if (table[3][0] != 'o' && table[3][1] != 'o' && table[3][2] != 'o')
	{
		AI1take = 1;
		lighting[3] = 1;
		cout << "close 4" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI1[j] == 'o')
				{
					AI1[j] = table[3][i];
					table[3][i] = 'o';
				}
			}
		}
	}
	else
	{
		a = rand() % 76;
		while (cards[a] == 'X')
		{
			a = rand() % 76;
		}
		if (cards[a] == 'A')
			cout << "red" << endl;
		else if (cards[a] == 'B')
			cout << "orange" << endl;
		else if (cards[a] == 'C')
			cout << "pink" << endl;
		else if (cards[a] == 'D')
			cout << "green" << endl;
		else if (cards[a] == 'E')
			cout << "blue" << endl;
		else if (cards[a] == 'F')
			cout << "gray" << endl;
		else if (cards[a] == 'G')
			cout << "yellow" << endl;
		else if (cards[a] == 'h')
			cout << "彩色" << endl;
		else if (cards[a] == 'i')
			cout << "加二" << endl;//讓使用者知道AI抽到什麼牌
		b = rand() % 4;
		while (table[b][0] != 'o' && table[b][1] != 'o' && table[b][2] != 'o' || lighting[b] == 1)
		{
			b = rand() % 4;
		}
		cout << "put to " << b + 1 << endl;
		if (b == 0)
		{
			if (table[0][0] == 'o')
				table[0][0] = cards[a];
			else if (table[0][1] == 'o')
				table[0][1] = cards[a];
			else if (table[0][2] == 'o')
				table[0][2] = cards[a];
		}
		else if (b == 1)
		{
			if (table[1][0] == 'o')
				table[1][0] = cards[a];
			else if (table[1][1] == 'o')
				table[1][1] = cards[a];
			else if (table[0][2] == 'o')
				table[1][2] = cards[a];
		}
		else if (b == 2)
		{
			if (table[2][0] == 'o')
				table[2][0] = cards[a];
			else if (table[2][1] == 'o')
				table[2][1] = cards[a];
			else if (table[2][2] == 'o')
				table[2][2] = cards[a];
		}
		else if (b == 3)
		{
			if (table[3][0] == 'o')
				table[3][0] = cards[a];
			else if (table[3][1] == 'o')
				table[3][1] = cards[a];
			else if (table[3][2] == 'o')
				table[3][2] = cards[a];
		}//將AI所抽出的排放進牌堆
		cards[a] = 'X';

	}
	outputtable();
	outputpocket();
}
void AI2turn()
{
	AI2bool1 = 0; AI2bool2 = 0; AI2bool3 = 0; AI2bool4 = 0;
	cout << "AI2 turn" << endl;
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < 3; j++)
			{
				if (table[i][j] == 'h')
					AI2bool1 += 2;
				if (table[i][j] == 'i')
					AI2bool1 += 5;
				for (int k = 0; k < 100; k++)
				{
					if (table[i][j] == AI2[k] && AI2[k] != 'o')
						AI2bool1++;
				}
			}
		}
		else if (i == 1)
		{
			for (int j = 0; j < 3; j++)
			{
				if (table[i][j] == 'h')
					AI2bool2 += 2;
				if (table[i][j] == 'i')
					AI2bool2 += 5;
				for (int k = 0; k < 100; k++)
				{
					if (table[i][j] == AI2[k] && AI2[k] != 'o')
						AI2bool2++;
				}
			}
		}
		else if (i == 2)
		{
			for (int j = 0; j < 3; j++)
			{
				if (table[i][j] == 'h')
					AI2bool3 += 2;
				if (table[i][j] == 'i')
					AI2bool3 += 5;
				for (int k = 0; k < 100; k++)
				{
					if (table[i][j] == AI2[k] && AI2[k] != 'o')
						AI2bool3++;
				}
			}
		}
		else if (i == 3)
		{
			for (int j = 0; j < 3; j++)
			{
				if (table[i][j] == 'h')
					AI2bool4 += 2;
				if (table[i][j] == 'i')
					AI2bool4 += 9;
				for (int k = 0; k < 100; k++)
				{
					if (table[i][j] == AI2[k] && AI2[k] != 'o')
						AI2bool4++;
				}
			}
		}
	}
	if (AI2bool1 > 3)
	{
		AI2take = 1;
		lighting[0] = 1;
		cout << "close 1" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI2[j] == 'o')
				{
					AI2[j] = table[0][i];
					table[0][i] = 'o';
				}
			}
		}
	}
	else if (AI2bool2 > 3)
	{
		AI2take = 1;
		lighting[1] = 1;
		cout << "close 2" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI2[j] == 'o')
				{
					AI2[j] = table[1][i];
					table[1][i] = 'o';
				}
			}
		}
	}
	else if (AI2bool3 > 3)
	{
		AI2take = 1;
		lighting[2] = 1;
		cout << "close 3" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI2[j] == 'o')
				{
					AI2[j] = table[2][i];
					table[2][i] = 'o';
				}
			}
		}
	}
	else if (AI2bool4 > 3)
	{
		AI2take = 1;
		lighting[3] = 1;
		cout << "close 4" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI2[j] == 'o')
				{
					AI2[j] = table[3][i];
					table[3][i] = 'o';
				}
			}
		}
	}
	else if (table[0][0] != 'o' && table[0][1] != 'o' && table[0][2] != 'o')
	{
		AI2take = 1;
		lighting[0] = 1;
		cout << "close 1" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI2[j] == 'o')
				{
					AI2[j] = table[0][i];
					table[0][i] = 'o';
				}
			}
		}
	}
	else if (table[1][0] != 'o' && table[1][1] != 'o' && table[1][2] != 'o')
	{

		AI2take = 1;
		lighting[1] = 1;
		cout << "close 2" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI2[j] == 'o')
				{
					AI2[j] = table[1][i];
					table[1][i] = 'o';
				}
			}
		}
	}
	else if (table[2][0] != 'o' && table[2][1] != 'o' && table[2][2] != 'o')
	{
		AI2take = 1;
		lighting[2] = 1;
		cout << "close 3" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI2[j] == 'o')
				{
					AI2[j] = table[2][i];
					table[2][i] = 'o';
				}
			}
		}
	}
	else if (table[3][0] != 'o' && table[3][1] != 'o' && table[3][2] != 'o')
	{
		AI2take = 1;
		lighting[3] = 1;
		cout << "close 4" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI2[j] == 'o')
				{
					AI2[j] = table[3][i];
					table[3][i] = 'o';
				}
			}
		}
	}
	else
	{
		a = rand() % 76;
		while (cards[a] == 'X')
		{
			a = rand() % 76;
		}
		if (cards[a] == 'A')
			cout << "red" << endl;
		else if (cards[a] == 'B')
			cout << "orange" << endl;
		else if (cards[a] == 'C')
			cout << "pink" << endl;
		else if (cards[a] == 'D')
			cout << "green" << endl;
		else if (cards[a] == 'E')
			cout << "blue" << endl;
		else if (cards[a] == 'F')
			cout << "gray" << endl;
		else if (cards[a] == 'G')
			cout << "yellow" << endl;
		else if (cards[a] == 'h')
			cout << "彩色" << endl;
		else if (cards[a] == 'i')
			cout << "加二" << endl;//讓使用者知道AI抽到什麼牌
		b = rand() % 4;
		while (table[b][0] != 'o' && table[b][1] != 'o' && table[b][2] != 'o' || lighting[b] == 1)
		{
			b = rand() % 4;
		}

		cout << "put to " << b + 1 << endl;
		if (b == 0)
		{
			if (table[0][0] == 'o')
				table[0][0] = cards[a];
			else if (table[0][1] == 'o')
				table[0][1] = cards[a];
			else if (table[0][2] == 'o')
				table[0][2] = cards[a];
		}
		else if (b == 1)
		{
			if (table[1][0] == 'o')
				table[1][0] = cards[a];
			else if (table[1][1] == 'o')
				table[1][1] = cards[a];
			else if (table[0][2] == 'o')
				table[1][2] = cards[a];
		}
		else if (b == 2)
		{
			if (table[2][0] == 'o')
				table[2][0] = cards[a];
			else if (table[2][1] == 'o')
				table[2][1] = cards[a];
			else if (table[2][2] == 'o')
				table[2][2] = cards[a];
		}
		else if (b == 3)
		{
			if (table[3][0] == 'o')
				table[3][0] = cards[a];
			else if (table[3][1] == 'o')
				table[3][1] = cards[a];
			else if (table[3][2] == 'o')
				table[3][2] = cards[a];
		}//將AI所抽出的排放進牌堆
		cards[a] = 'X';

	}
	outputtable();
	outputpocket();
}
void AI3turn()
{
	AI3bool1 = 0; AI3bool2 = 0; AI3bool3 = 0; AI3bool4 = 0;
	cout << "AI3 turn" << endl;
	for (int i = 0; i < 4; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < 3; j++)
			{
				if (table[i][j] == 'h')
					AI3bool1 += 2;
				if (table[i][j] == 'i')
					AI3bool1 += 9;
				for (int k = 0; k < 100; k++)
				{
					if (table[i][j] == AI3[k] && AI3[k] != 'o')
						AI3bool1 += 2;
				}
			}
		}
		else if (i == 1)
		{
			for (int j = 0; j < 3; j++)
			{
				if (table[i][j] == 'h')
					AI3bool2 += 2;
				if (table[i][j] == 'i')
					AI3bool2 += 9;
				for (int k = 0; k < 100; k++)
				{
					if (table[i][j] == AI3[k] && AI3[k] != 'o')
						AI3bool2 += 2;
				}
			}
		}
		else if (i == 2)
		{
			for (int j = 0; j < 3; j++)
			{
				if (table[i][j] == 'h')
					AI3bool3 += 2;
				if (table[i][j] == 'i')
					AI3bool3 += 9;
				for (int k = 0; k < 100; k++)
				{
					if (table[i][j] == AI3[k] && AI3[k] != 'o')
						AI3bool3 += 2;
				}
			}
		}
		else if (i == 3)
		{
			for (int j = 0; j < 3; j++)
			{
				if (table[i][j] == 'h')
					AI3bool4 += 2;
				if (table[i][j] == 'i')
					AI3bool4 += 9;
				for (int k = 0; k < 100; k++)
				{
					if (table[i][j] == AI3[k] && AI3[k] != 'o')
						AI3bool4 += 2;
				}
			}
		}
	}
	cout << "here1" << endl;
	if (AI3bool1 > 5)
	{
		AI3take = 1;
		lighting[0] = 1;
		cout << "close 1" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI3[j] == 'o')
				{
					AI3[j] = table[0][i];
					table[0][i] = 'o';
				}
			}
		}
	}
	else if (AI3bool2 > 5)
	{
		AI3take = 1;
		lighting[1] = 1;
		cout << "close 2" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI3[j] == 'o')
				{
					AI3[j] = table[1][i];
					table[1][i] = 'o';
				}
			}
		}
	}
	else if (AI3bool3 > 5)
	{
		AI3take = 1;
		lighting[2] = 1;
		cout << "close 3" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI3[j] == 'o')
				{
					AI3[j] = table[2][i];
					table[2][i] = 'o';
				}
			}
		}
	}
	else if (AI3bool4 > 5)
	{
		AI3take = 1;
		lighting[3] = 1;
		cout << "close 4" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI3[j] == 'o')
				{
					AI3[j] = table[3][i];
					table[3][i] = 'o';
				}
			}
		}
	}
	else if (table[0][0] != 'o' && table[0][1] != 'o' && table[0][2] != 'o')
	{
		AI3take = 1;
		lighting[0] = 1;
		cout << "close 1" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI3[j] == 'o')
				{
					AI3[j] = table[0][i];
					table[0][i] = 'o';
				}
			}
		}
	}
	else if (table[1][0] != 'o' && table[1][1] != 'o' && table[1][2] != 'o')
	{
		AI3take = 1;
		lighting[1] = 1;
		cout << "close 2" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI3[j] == 'o')
				{
					AI3[j] = table[1][i];
					table[1][i] = 'o';
				}
			}
		}
	}
	else if (table[2][0] != 'o' && table[2][1] != 'o' && table[2][2] != 'o')
	{
		AI3take = 1;
		lighting[2] = 1;
		cout << "close 3" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI3[j] == 'o')
				{
					AI3[j] = table[2][i];
					table[2][i] = 'o';
				}
			}
		}
	}
	else if (table[3][0] != 'o' && table[3][1] != 'o' && table[3][2] != 'o')
	{
		AI3take = 1;
		lighting[3] = 1;
		cout << "close 4" << endl;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 100; j++)
			{
				if (AI3[j] == 'o')
				{
					AI3[j] = table[3][i];
					table[3][i] = 'o';
				}
			}
		}
	}
	else
	{
		a = rand() % 76;
		while (cards[a] == 'X')
		{
			a = rand() % 76;
		}
		if (cards[a] == 'A')
			cout << "red" << endl;
		else if (cards[a] == 'B')
			cout << "orange" << endl;
		else if (cards[a] == 'C')
			cout << "pink" << endl;
		else if (cards[a] == 'D')
			cout << "green" << endl;
		else if (cards[a] == 'E')
			cout << "blue" << endl;
		else if (cards[a] == 'F')
			cout << "gray" << endl;
		else if (cards[a] == 'G')
			cout << "yellow" << endl;
		else if (cards[a] == 'h')
			cout << "彩色" << endl;
		else if (cards[a] == 'i')
			cout << "加二" << endl;//讓使用者知道AI抽到什麼牌
		b = rand() % 4;
		while (table[b][0] != 'o' && table[b][1] != 'o' && table[b][2] != 'o' || lighting[b] == 1)
		{
			b = rand() % 4;
		}
		cout << "put to " << b + 1 << endl;
		if (b == 0)
		{
			if (table[0][0] == 'o')
				table[0][0] = cards[a];
			else if (table[0][1] == 'o')
				table[0][1] = cards[a];
			else if (table[0][2] == 'o')
				table[0][2] = cards[a];
		}
		else if (b == 1)
		{
			if (table[1][0] == 'o')
				table[1][0] = cards[a];
			else if (table[1][1] == 'o')
				table[1][1] = cards[a];
			else if (table[0][2] == 'o')
				table[1][2] = cards[a];
		}
		else if (b == 2)
		{
			if (table[2][0] == 'o')
				table[2][0] = cards[a];
			else if (table[2][1] == 'o')
				table[2][1] = cards[a];
			else if (table[2][2] == 'o')
				table[2][2] = cards[a];
		}
		else if (b == 3)
		{
			if (table[3][0] == 'o')
				table[3][0] = cards[a];
			else if (table[3][1] == 'o')
				table[3][1] = cards[a];
			else if (table[3][2] == 'o')
				table[3][2] = cards[a];
		}//將AI所抽出的排放進牌堆
		cards[a] = 'X';

	}
	outputtable();
	outputpocket();
}
void userturn()
{
	cout << "user turn" << endl;
	int n = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (table[i][j] == 'o')
				n++;
		}
	}
	if (n == 12)//代表桌上完全沒牌 只能抽牌
	{
		a = rand() % 76;
		while (cards[a] == 'X')
		{
			a = rand() % 76;
		}
		if (cards[a] == 'A')
			cout << "red" << endl;
		else if (cards[a] == 'B')
			cout << "orange" << endl;
		else if (cards[a] == 'C')
			cout << "pink" << endl;
		else if (cards[a] == 'D')
			cout << "green" << endl;
		else if (cards[a] == 'E')
			cout << "blue" << endl;
		else if (cards[a] == 'F')
			cout << "gray" << endl;
		else if (cards[a] == 'G')
			cout << "yellow" << endl;
		else if (cards[a] == 'h')
			cout << "彩色" << endl;
		else if (cards[a] == 'i')
			cout << "加二" << endl;
		cout << "你想把牌放在哪列?"  << endl;
		cin >> answer;
		while (table[answer - 1][0] != 'o' && table[answer - 1][1] != 'o' && table[answer - 1][2] != 'o')//規定每盞燈下只能放3張牌
		{
			cout << "這列滿了! 請選別列~" << endl;
			cin >> answer;
		}
		while (lighting[0] == 1 || lighting[1] == 1 || lighting[2] == 1 || lighting[3] == 1)//避免放到已關閉的燈
		{
			if (answer == 1 && lighting[0] != 1)
				break;
			else if (answer == 2 && lighting[1] != 1)
				break;
			else if (answer == 3 && lighting[2] != 1)
				break;
			else if (answer == 4 && lighting[3] != 1)
				break;
			else
			{
				cout << "這盞燈已被關閉了! 請選別盞" << endl;
				cin >> answer;
			}
		}
		if (answer == 1)
		{
			if (table[0][0] == 'o')
				table[0][0] = cards[a];
			else if (table[0][1] == 'o')
				table[0][1] = cards[a];
			else if (table[0][2] == 'o')
				table[0][2] = cards[a];
		}
		else if (answer == 2)
		{
			if (table[1][0] == 'o')
				table[1][0] = cards[a];
			else if (table[1][1] == 'o')
				table[1][1] = cards[a];
			else if (table[0][2] == 'o')
				table[1][2] = cards[a];
		}
		else if (answer == 3)
		{
			if (table[2][0] == 'o')
				table[2][0] = cards[a];
			else if (table[2][1] == 'o')
				table[2][1] = cards[a];
			else if (table[2][2] == 'o')
				table[2][2] = cards[a];
		}
		else if (answer == 4)
		{
			if (table[3][0] == 'o')
				table[3][0] = cards[a];
			else if (table[3][1] == 'o')
				table[3][1] = cards[a];
			else if (table[3][2] == 'o')
				table[3][2] = cards[a];
		}//將使用者所抽出的排放進牌堆
		cards[a] = 'X';
		outputtable();
		outputpocket();
	}
	else
	{
		cout << "抽牌(0) 關燈(1)" << endl;
		cin >> c;
		if (c == 0)
		{
			a = rand() % 76;
			while (cards[a] == 'X')
			{
				a = rand() % 76;
			}
			if (cards[a] == 'A')
				cout << "red" << endl;
			else if (cards[a] == 'B')
				cout << "orange" << endl;
			else if (cards[a] == 'C')
				cout << "pink" << endl;
			else if (cards[a] == 'D')
				cout << "green" << endl;
			else if (cards[a] == 'E')
				cout << "blue" << endl;
			else if (cards[a] == 'F')
				cout << "gray" << endl;
			else if (cards[a] == 'G')
				cout << "yellow" << endl;
			else if (cards[a] == 'h')
				cout << "彩色" << endl;
			else if (cards[a] == 'i')
				cout << "加二" << endl;
			cout << "你想把牌放在哪列?" << endl;
			cin >> answer;
			while (table[answer - 1][0] != 'o' && table[answer - 1][1] != 'o' && table[answer - 1][2] != 'o')
			{
				cout << "這列滿了! 請選別列~" << endl;
				cin >> answer;
			}
			while (lighting[0] == 1 || lighting[1] == 1 || lighting[2] == 1 || lighting[3] == 1)
			{
				if (answer == 1 && lighting[0] != 1)
					break;
				else if (answer == 2 && lighting[1] != 1)
					break;
				else if (answer == 3 && lighting[2] != 1)
					break;
				else if (answer == 4 && lighting[3] != 1)
					break;
				else
				{
					cout << "這列已被選走了! 請選別列" << endl;
					cin >> answer;
				}
			}
			if (answer == 1)
			{
				if (table[0][0] == 'o')
					table[0][0] = cards[a];
				else if (table[0][1] == 'o')
					table[0][1] = cards[a];
				else if (table[0][2] == 'o')
					table[0][2] = cards[a];
			}
			else if (answer == 2)
			{
				if (table[1][0] == 'o')
					table[1][0] = cards[a];
				else if (table[1][1] == 'o')
					table[1][1] = cards[a];
				else if (table[0][2] == 'o')
					table[1][2] = cards[a];
			}
			else if (answer == 3)
			{
				if (table[2][0] == 'o')
					table[2][0] = cards[a];
				else if (table[2][1] == 'o')
					table[2][1] = cards[a];
				else if (table[2][2] == 'o')
					table[2][2] = cards[a];
			}
			else if (answer == 4)
			{
				if (table[3][0] == 'o')
					table[3][0] = cards[a];
				else if (table[3][1] == 'o')
					table[3][1] = cards[a];
				else if (table[3][2] == 'o')
					table[3][2] = cards[a];
			}//將使用者所抽出的排放進牌堆
			cards[a] = 'X';
			outputtable();
			outputpocket();
		}
		else if (c == 1)
		{
			usertake = 1;
			cout << "你想取哪列?" << endl;
			cin >> lightAns;
			while (lighting[lightAns - 1] == 1)
			{
				cout << "這列已被選走了! 請選別列" << endl;
				cin >> lightAns;
			}
			if (lightAns == 1)
			{
				lighting[0] = 1;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 100; j++)
					{
						if (user[j] == 'o')
						{
							user[j] = table[0][i];
							table[0][i] = 'o';
						}
					}
				}
			}
			else if (lightAns == 2)
			{
				lighting[1] = 1;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 100; j++)
					{
						if (user[j] == 'o')
						{
							user[j] = table[1][i];
							table[1][i] = 'o';
						}
					}
				}
			}
			else if (lightAns == 3)
			{
				lighting[2] = 1;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 100; j++)
					{
						if (user[j] == 'o')
						{
							user[j] = table[2][i];
							table[2][i] = 'o';
						}
					}
				}
			}
			else if (lightAns == 4)
			{
				lighting[3] = 1;
				for (int i = 0; i < 3; i++)
				{
					for (int j = 0; j < 100; j++)
					{
						if (user[j] == 'o')
						{
							user[j] = table[3][i];
							table[3][i] = 'o';
						}
					}
				}
			}
			outputtable();
			outputpocket();
		}
	}
}
void score()
{
	vector<int>fq(9, 0);
	vector<int>sco(7, 0);
	for (int i = 0; i < 100; i++)
	{
		if (user[i] == 'A')
			fq[0]++;
		else if (user[i] == 'B')
			fq[1]++;
		else if (user[i] == 'C')
			fq[2]++;
		else if (user[i] == 'D')
			fq[3]++;
		else if (user[i] == 'E')
			fq[4]++;
		else if (user[i] == 'F')
			fq[5]++;
		else if (user[i] == 'G')
			fq[6]++;
		else if (user[i] == 'h')
			fq[7]++;
		else if (user[i] == 'i')
			fq[8]++;

	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (fq[i] < fq[j])
			{
				int place = fq[j];
				fq[j] = fq[i];
				fq[i] = place;
			}
		}
	}
	if (fq[0] < 6)
		fq[0] = fq[0] + fq[7];
	else if (fq[1] < 6)
		fq[1] = fq[1] + fq[7];
	else if (fq[2] < 6)
		fq[2] = fq[2] + fq[7];
	else
		fq[0] = fq[0] + fq[7];
	for (int i = 0; i < 7; i++)
	{
		if (fq[i] >= 6)
			sco[i] = 21;
		else if (fq[i] == 5)
			sco[i] = 15;
		else if (fq[i] == 4)
			sco[i] = 10;
		else if (fq[i] == 3)
			sco[i] = 6;
		else if (fq[i] == 2)
			sco[i] = 3;
		else if (fq[i] == 1)
			sco[i] = 1;
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (sco[i] < sco[j])
			{
				int place1 = sco[j];
				sco[j] = sco[i];
				sco[i] = place1;
			}
		}
	}
	int sum1 = 0;
	for (int i = 0; i < 7; i++)
	{
		if (i < 3)
		{
			sum1 = sum1 + sco[i];
		}
		else
		{
			sum1 = sum1 - sco[i];
		}
	}
	sum1 = sum1 + fq[8] * 2;
	cout << "user" << "  " << sum1 << endl;


	for (int i = 0; i < 9; i++)
	{
		fq[i] = 0;
	}
	for (int i = 0; i < 7; i++)
	{
		sco[i] = 0;
	}
	for (int i = 0; i < 100; i++)
	{
		if (AI1[i] == 'A')
			fq[0]++;
		else if (AI1[i] == 'B')
			fq[1]++;
		else if (AI1[i] == 'C')
			fq[2]++;
		else if (AI1[i] == 'D')
			fq[3]++;
		else if (AI1[i] == 'E')
			fq[4]++;
		else if (AI1[i] == 'F')
			fq[5]++;
		else if (AI1[i] == 'G')
			fq[6]++;
		else if (AI1[i] == 'h')
			fq[7]++;
		else if (AI1[i] == 'i')
			fq[8]++;

	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (fq[i] < fq[j])
			{
				int place = fq[j];
				fq[j] = fq[i];
				fq[i] = place;
			}
		}
	}
	if (fq[0] < 6)
		fq[0] = fq[0] + fq[7];
	else if (fq[1] < 6)
		fq[1] = fq[1] + fq[7];
	else if (fq[2] < 6)
		fq[2] = fq[2] + fq[7];
	else
		fq[0] = fq[0] + fq[7];
	for (int i = 0; i < 7; i++)
	{
		if (fq[i] >= 6)
			sco[i] = 21;
		else if (fq[i] == 5)
			sco[i] = 15;
		else if (fq[i] == 4)
			sco[i] = 10;
		else if (fq[i] == 3)
			sco[i] = 6;
		else if (fq[i] == 2)
			sco[i] = 3;
		else if (fq[i] == 1)
			sco[i] = 1;
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (sco[i] < sco[j])
			{
				int place1 = sco[j];
				sco[j] = sco[i];
				sco[i] = place1;
			}
		}
	}
	int sum2 = 0;
	for (int i = 0; i < 7; i++)
	{
		if (i < 3)
		{
			sum2 = sum2 + sco[i];
		}
		else
		{
			sum2 = sum2 - sco[i];
		}
	}
	sum2 = sum2 + fq[8] * 2;
	cout << "AI1" << "   " << sum2 << endl;

	for (int i = 0; i < 9; i++)
	{
		fq[i] = 0;
	}
	for (int i = 0; i < 7; i++)
	{
		sco[i] = 0;
	}
	for (int i = 0; i < 100; i++)
	{
		if (AI2[i] == 'A')
			fq[0]++;
		else if (AI2[i] == 'B')
			fq[1]++;
		else if (AI2[i] == 'C')
			fq[2]++;
		else if (AI2[i] == 'D')
			fq[3]++;
		else if (AI2[i] == 'E')
			fq[4]++;
		else if (AI2[i] == 'F')
			fq[5]++;
		else if (AI2[i] == 'G')
			fq[6]++;
		else if (AI2[i] == 'h')
			fq[7]++;
		else if (AI2[i] == 'i')
			fq[8]++;

	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (fq[i] < fq[j])
			{
				int place = fq[j];
				fq[j] = fq[i];
				fq[i] = place;
			}
		}
	}
	if (fq[0] < 6)
		fq[0] = fq[0] + fq[7];
	else if (fq[1] < 6)
		fq[1] = fq[1] + fq[7];
	else if (fq[2] < 6)
		fq[2] = fq[2] + fq[7];
	else
		fq[0] = fq[0] + fq[7];
	for (int i = 0; i < 7; i++)
	{
		if (fq[i] >= 6)
			sco[i] = 21;
		else if (fq[i] == 5)
			sco[i] = 15;
		else if (fq[i] == 4)
			sco[i] = 10;
		else if (fq[i] == 3)
			sco[i] = 6;
		else if (fq[i] == 2)
			sco[i] = 3;
		else if (fq[i] == 1)
			sco[i] = 1;
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (sco[i] < sco[j])
			{
				int place1 = sco[j];
				sco[j] = sco[i];
				sco[i] = place1;
			}
		}
	}
	int sum3 = 0;
	for (int i = 0; i < 7; i++)
	{
		if (i < 3)
		{
			sum3 = sum3 + sco[i];
		}
		else
		{
			sum3 = sum3 - sco[i];
		}
	}
	sum3 = sum3 + fq[8] * 2;
	cout << "AI2" << "   " << sum3 << endl;

	for (int i = 0; i < 9; i++)
	{
		fq[i] = 0;
	}
	for (int i = 0; i < 7; i++)
	{
		sco[i] = 0;
	}
	for (int i = 0; i < 100; i++)
	{
		if (AI3[i] == 'A')
			fq[0]++;
		else if (AI3[i] == 'B')
			fq[1]++;
		else if (AI3[i] == 'C')
			fq[2]++;
		else if (AI3[i] == 'D')
			fq[3]++;
		else if (AI3[i] == 'E')
			fq[4]++;
		else if (AI3[i] == 'F')
			fq[5]++;
		else if (AI3[i] == 'G')
			fq[6]++;
		else if (AI3[i] == 'h')
			fq[7]++;
		else if (AI3[i] == 'i')
			fq[8]++;

	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (fq[i] < fq[j])
			{
				int place = fq[j];
				fq[j] = fq[i];
				fq[i] = place;
			}
		}
	}
	if (fq[0] < 6)
		fq[0] = fq[0] + fq[7];
	else if (fq[1] < 6)
		fq[1] = fq[1] + fq[7];
	else if (fq[2] < 6)
		fq[2] = fq[2] + fq[7];
	else
		fq[0] = fq[0] + fq[7];
	for (int i = 0; i < 7; i++)
	{
		if (fq[i] >= 6)
			sco[i] = 21;
		else if (fq[i] == 5)
			sco[i] = 15;
		else if (fq[i] == 4)
			sco[i] = 10;
		else if (fq[i] == 3)
			sco[i] = 6;
		else if (fq[i] == 2)
			sco[i] = 3;
		else if (fq[i] == 1)
			sco[i] = 1;
	}
	for (int i = 0; i < 7; i++)
	{
		for (int j = i + 1; j < 7; j++)
		{
			if (sco[i] < sco[j])
			{
				int place1 = sco[j];
				sco[j] = sco[i];
				sco[i] = place1;
			}
		}
	}
	int sum4 = 0;
	for (int i = 0; i < 7; i++)
	{
		if (i < 3)
		{
			sum4 = sum4 + sco[i];
		}
		else
		{
			sum4 = sum4 - sco[i];
		}
	}
	sum4 = sum4 + fq[8] * 2;
	cout << "AI3" << "   " << sum4 << endl;
	if (sum1 > sum2 && sum1 > 3 && sum1 > sum4)
		cout << "user win!" << endl;
	else if (sum2 > sum1 && sum2 > sum3 && sum2 > sum4)
		cout << "AI1 win" << endl;
	else if (sum3 > sum1 && sum3 > sum2 && sum3 > sum4)
		cout << "AI2 win" << endl;
	else if (sum4 > sum1 && sum4 > sum2 && sum4 > sum3)
		cout << "AI3 win" << endl;
	else
		cout << "even" << endl;

	system("pause");
}