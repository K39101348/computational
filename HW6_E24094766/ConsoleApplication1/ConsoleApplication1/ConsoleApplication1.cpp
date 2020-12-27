#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

int card_remain = 0;
int card_color[9] = { 0,1,2,3,4,5,6,7,8 };     //彩色，+2，紅，黃，粉，灰，綠，棕，藍
int card_number[9] = { 3,10,9,9,9,9,9,9,9 };
int card[76];
int first[4] = { 0 };
int your_card[9];
int player_1_card[9];
int player_2_card[9];
int player_3_card[9];
string drawed_card[4][3] = { { "  ","  ","  " },{ "  ","  ","  " },{ "  ","  ","  " },{ "  ","  ","  " } };
int players_color[4][9] = {};
string player_status[4] = { "not finished","not finished","not finished","not finished" };
const string playersname[4] = { "you","player2","player3","player4" };
vector<int> row_A;
vector<int> row_B;
vector<int> row_C;
vector<int> row_D;



void start_display()  
{
	cout << " ";

}
void screen_display() {

	system("cls");
	cout << "player 1" << "紅 粉 橙 黃 綠 藍 灰 +2 龍" << endl;
	for (int i = 0; i <= 8; i++) {
		cout << players_color[0][i] << " ";
	}
	cout << "\n" << "status" << player_status[0];


}

void ai() {
	int a=rand() % 2;
	if (a == 0) {
		int i = rand() % 4 + 65;
		random(i);
	}
	else {
		int i = rand() % 4 + 65;
		taken_card(player_1_card, i);
	}
}






	
int main()
{
	int check[4] = { 0 };
	char j;
	do {
		int o = rand() % 2;                      //ai_1
		if (o == 0) {
			int i = rand() % 4 + 65;
			random(i);
		}
		else {
			int i = rand() % 4 + 65;
			taken_card(player_1_card, i);
			check[1] = 1;
		}
		int o = rand() % 2;                     //ai_2
		if (o == 0) {
			int i = rand() % 4 + 65;
			random(i);
		}
		else {
			int i = rand() % 4 + 65;
			taken_card(player_2_card, i);
			check[2] = 1;
		}
		int o= rand() % 2;                     //ai_3
		if (o == 0) {
			int i = rand() % 4 + 65;
			random(i);
		}
		else {
			int i = rand() % 4 + 65;
			taken_card(player_3_card, i);
			check[3] = 1;
		}
	}while(check[0]==0||check[1]==0||check[2]==0||check[3]==0)
}

void first_card() {
	int a,i;
	for (i = 0; i <= 3; i++) {
		do {
			a= rand() % 7 + 2;
		} while (a == first[0] || first[1] || a == first[2] || a == first[3]);
		first[i] = a;
	}
}

void random(char i) {
	char i;
	int a;
	do {
		a = rand() % 9;
		card_number[a] -= 1;
	} while (card_number[a] != 0);
	string color[9] = { "rainbow","+2","red","yellow","pink","gray","green","brown","blue" };
	cout << color[a];
	cout << "Please choose a row: A:[Row A] , B:[Row B] , C:[Row C] , D:[Row D]" << endl;
	int check;
	
	do {
		switch (i) {
		case 65:
			if (row_A.size() < 3) {
				row_A.push_back(a);
				check = 0;
				break;
			}
			else
			{
				check = 1;
				break;
			}
		case 66:
			if (row_B.size() < 3) {
				row_B.push_back(a);
				check = 0;
				break;
			}
			else
			{
				check = 1;
				break;
			}
		case 67:
			if (row_C.size() < 3) {
				row_C.push_back(a);
				check = 0;
				break;
			}
			else
			{
				check = 1;
				break;
			}
		case 68:
			if (row_D.size() < 3) {
				row_D.push_back(a);
				check = 0;
				break;
			}
			else
			{
				check = 1;
				break;
			}
		}
	
	
	} while (check == 1);
}

void taken_card(int array[], char i) {                                                     //呼叫此函數時須輸入兩個參數(誰要拿牌,拿哪一列)
	cout << "請選擇要取的排數:A:[Row A] , B:[Row B] , C:[Row C] , D:[Row D]" << endl;
	switch (i) {
	case 65:
		for (i = 0; i < row_A.size(); i++)
			array[row_A[i]]++;
		row_A.clear();
		break;
	case 66:
		for (i = 0; i < row_A.size(); i++)
			array[row_B[i]]++;
		row_B.clear();
		break;
	case 67:
		for (i = 0; i < row_A.size(); i++)
			array[row_C[i]]++;
		row_C.clear();
		break;
	case 68:
		for (i = 0; i < row_A.size(); i++)
			array[row_D[i]]++;
		row_D.clear();
		break;
	default:
		break;
	}
}
