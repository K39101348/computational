#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <string>


using namespace std;

//declare the variables to deliver the argument to the function
int choice = 0;
int Row1 = 0;
int Row2 = 0;


//declare a variable to check whether every player have picked up the card
bool Playerstatus[4] = {};

//declare a variable to realize the round rule
int playerturn = 4;
const int playernum[4] = { 1,2,3,4 };
int cardleft = 77;


enum card { red, pink, orange, yellow, green, blue, purple, gray, bonus, coloretto, End };

//make a game deck
int deck[78] = {};

//declare the variables for screen_display()
string drawed_card[4][3] = { { "  ","  ","  " },{ "  ","  ","  " },{ "  ","  ","  " },{ "  ","  ","  " } };
int playerS_color[4][9] = {};
string player_status[4] = { "not finished","not finished","not finished","not finished" };
const string playername[4] = { "player1","player2","player3","you" };


//declare the variables for draw_card() & put_the_card(int)
int code = 0;
card the_kind_ofcard;
int rowcounter[4] = {};

//declare the variable for pick_the_row(int)
const string color[10] = { "  ","¬õ","¯»","¾í","¶À","ºñ","ÂÅ","¦Ç","+2","ÅÜ" };
int color_counter[10] = {};

//declare an array for storing score 
int player_score[4] = {};


//function prototype

void welcome_display();
void screen_display();

void first_card();

void artficial_idiot();

void player4();

void draw_card();
void put_the_card(int);

void pick_the_row(int);

void initializing();

void insertion_sort(int[], int);
int score(int, int, int, int, int, int, int, int);


//main function
int main() {

	//set the seed of rand()
	srand(unsigned(time(0)));

	//welcome display
	welcome_display();

	//draw a card to every player
	first_card();
	screen_display();
	cout << "Each player has one coloretto which is different from each other!!" << endl;
	cout << "you first!!";
	system("pause");



	//start play!!
	while (deck[77] == 0) {

		switch (playerturn) {

		case 4:

			while (Playerstatus[0] == 0 || Playerstatus[1] == 0 || Playerstatus[2] == 0 || Playerstatus[3] == 0) {

				if (Playerstatus[3] == 0) {

					playerturn = playernum[3];
					player4();

				}

				if (Playerstatus[0] == 0) {

					playerturn = playernum[0];
					artficial_idiot();

				}

				if (Playerstatus[1] == 0) {

					playerturn = playernum[1];
					artficial_idiot();

				}

				if (Playerstatus[2] == 0) {

					playerturn = playernum[2];
					artficial_idiot();

				}

			}

			break;

		case 1:

			while (Playerstatus[0] == 0 || Playerstatus[1] == 0 || Playerstatus[2] == 0 || Playerstatus[3] == 0) {

				if (Playerstatus[0] == 0) {

					playerturn = playernum[0];
					artficial_idiot();

				}

				if (Playerstatus[1] == 0) {

					playerturn = playernum[1];
					artficial_idiot();

				}

				if (Playerstatus[2] == 0) {

					playerturn = playernum[2];
					artficial_idiot();

				}

				if (Playerstatus[3] == 0) {

					playerturn = playernum[3];
					player4();

				}

			}

			break;

		case 2:

			while (Playerstatus[0] == 0 || Playerstatus[1] == 0 || Playerstatus[2] == 0 || Playerstatus[3] == 0) {

				if (Playerstatus[1] == 0) {

					playerturn = playernum[1];
					artficial_idiot();

				}

				if (Playerstatus[2] == 0) {

					playerturn = playernum[2];
					artficial_idiot();

				}

				if (Playerstatus[3] == 0) {

					playerturn = playernum[3];
					player4();

				}

				if (Playerstatus[0] == 0) {

					playerturn = playernum[0];
					artficial_idiot();

				}

			}

			break;

		case 3:

			while (Playerstatus[0] == 0 || Playerstatus[1] == 0 || Playerstatus[2] == 0 || Playerstatus[3] == 0) {

				if (Playerstatus[2] == 0) {

					playerturn = playernum[2];
					artficial_idiot();

				}

				if (Playerstatus[3] == 0) {

					playerturn = playernum[3];
					player4();

				}

				if (Playerstatus[0] == 0) {

					playerturn = playernum[0];
					artficial_idiot();

				}

				if (Playerstatus[1] == 0) {

					playerturn = playernum[1];
					artficial_idiot();

				}

			}

			break;

		default:

			cout << "error in the main";

		}

		initializing();

	}


	//count every player's score

	//find out the three toppest number of card
	for (int turn = 0; turn <= 3; turn++) {

		insertion_sort(playerS_color[turn], 7);

		/*for (int kind = 0; kind < 7; kind++) {

			cout << playerS_color[turn][kind] << "  ";

		}*/

	}

	//put the coloretto to the most toppest color of card
	for (int turn = 0; turn <= 3; turn++) {

		playerS_color[turn][6] += playerS_color[turn][8];

	}

	//start to count!!
	for (int turn = 0; turn <= 3; turn++) {

		player_score[turn] = score(playerS_color[turn][6], playerS_color[turn][5],
			playerS_color[turn][4], playerS_color[turn][7],
			playerS_color[turn][0], playerS_color[turn][1],
			playerS_color[turn][2], playerS_color[turn][3]);

	}

	system("cls");
	cout << "player1 get " << player_score[0] << "points!!" << endl;
	cout << "player2 get " << player_score[1] << "points!!" << endl;
	cout << "player3 get " << player_score[2] << "points!!" << endl;
	cout << "you     get " << player_score[3] << "points!!" << endl;
	system("pause");

	return 0;
}


//give every player a card
void first_card() {


	int color;
	int color_kind[8] = {};

	for (int i = 1; i <= 4; i++) {

		do {

			color = 1;

			code = rand() % 63 + 1;

			while (color <= 7) {

				if (code >= (9 * color - 8) && code <= (9 * color)) {

					break;

				}

				color++;

			}

		} while (deck[code] > 0 || color_kind[color] > 0);

		deck[code]++;
		color_kind[color]++;
		playerS_color[i - 1][color - 1]++;
		cardleft--;

	}





}

//draw the card
void draw_card() {

	if (cardleft == 16) {

		deck[77]++;
		cardleft--;
		screen_display();
		cout << "this is the last round ! ";

	}

	//exclude the situation of drawing the same card
	do {

		code = rand() % 77 + 1;

	} while (deck[code] > 0);

	cardleft--;

	if (code >= 1 && code <= 9) {

		cout << endl << playername[playerturn - 1] << " get ¬õ !";
		deck[code]++;
		the_kind_ofcard = red;

	}

	else if (code >= 10 && code <= 18) {

		cout << endl << playername[playerturn - 1] << " get ¯» !";
		deck[code]++;
		the_kind_ofcard = pink;

	}

	else if (code >= 19 && code <= 27) {

		cout << endl << playername[playerturn - 1] << " get ¾í !";
		deck[code]++;
		the_kind_ofcard = orange;

	}

	else if (code >= 28 && code <= 36) {

		cout << endl << playername[playerturn - 1] << " get ¶À !";
		deck[code]++;
		the_kind_ofcard = yellow;

	}

	else if (code >= 37 && code <= 45) {

		cout << endl << playername[playerturn - 1] << " get ºñ !";
		deck[code]++;
		the_kind_ofcard = green;

	}

	else if (code >= 46 && code <= 54) {

		cout << endl << playername[playerturn - 1] << " get ÂÅ !";
		deck[code]++;
		the_kind_ofcard = blue;

	}

	else if (code >= 55 && code <= 63) {

		cout << endl << playername[playerturn - 1] << " get ¦Ç !";
		deck[code]++;
		the_kind_ofcard = gray;

	}

	else if (code >= 64 && code <= 73) {

		cout << endl << playername[playerturn - 1] << " get +2 !";
		deck[code]++;
		the_kind_ofcard = bonus;

	}

	else if (code >= 74 && code <= 76) {

		cout << endl << playername[playerturn - 1] << " get ÅÜ¦âÀs !";
		deck[code]++;
		the_kind_ofcard = coloretto;

	}

	else {

		draw_card();

	}

	return;
}

void put_the_card(int row) {

	switch (the_kind_ofcard) {

	case red:

		drawed_card[row - 1][rowcounter[row - 1]] = "¬õ";
		rowcounter[row - 1]++;

		break;

	case pink:

		drawed_card[row - 1][rowcounter[row - 1]] = "¯»";
		rowcounter[row - 1]++;

		break;

	case orange:

		drawed_card[row - 1][rowcounter[row - 1]] = "¾í";
		rowcounter[row - 1]++;

		break;

	case yellow:

		drawed_card[row - 1][rowcounter[row - 1]] = "¶À";
		rowcounter[row - 1]++;

		break;

	case green:

		drawed_card[row - 1][rowcounter[row - 1]] = "ºñ";
		rowcounter[row - 1]++;

		break;

	case blue:

		drawed_card[row - 1][rowcounter[row - 1]] = "ÂÅ";
		rowcounter[row - 1]++;
		break;

	case gray:

		drawed_card[row - 1][rowcounter[row - 1]] = "¦Ç";
		rowcounter[row - 1]++;

		break;

	case bonus:

		drawed_card[row - 1][rowcounter[row - 1]] = "+2";
		rowcounter[row - 1]++;

		break;

	case coloretto:

		drawed_card[row - 1][rowcounter[row - 1]] = "ÅÜ";
		rowcounter[row - 1]++;

		break;

	default:

		cout << "error in put the card";

	}

	return;
}

void pick_the_row(int row) {


	//pick the row
	for (int i = 1; i <= rowcounter[row - 1]; i++) {

		for (int j = 1; j <= 9; j++) {

			if (drawed_card[row - 1][i - 1] == color[j]) {

				color_counter[j]++;
				break;

			}

		}

	}

	//deliver the data in array color_counter[] to array  playerS_color[][]
	for (int i = 1; i <= 9; i++) {

		playerS_color[playerturn - 1][i - 1] += color_counter[i];

	}


	//delete the picked row
	for (int p = 0; p <= 2; p++) {

		drawed_card[row - 1][p] = "XX";

	}


	//clean the data in the array color_counter[]
	for (int i = 1; i <= 9; i++) {

		color_counter[i] = 0;

	}

	//tell the program and the player that who has done
	Playerstatus[playernum[playerturn - 1] - 1] = 1;
	player_status[playernum[playerturn - 1] - 1] = "done";

	return;

}


void artficial_idiot() {

	choice = (rand() % 2 + 1);

	//******draw card******
	if (choice == 1) {

		for (int row = 0; row <= 3; row++) {

			//exclude the situation of all picked or full row and lead to ~~~pick the row~~~
			if (drawed_card[row][0] == "XX" || rowcounter[row] == 3) {

				if (row == 3) {

					Row2 = (rand() % 4 + 1);

					while (drawed_card[Row2 - 1][0] == "XX" || drawed_card[Row2 - 1][0] == "  ") {

						Row2 = (rand() % 4 + 1);

					}

					pick_the_row(Row2);
					screen_display();
					cout << endl << playername[playerturn - 1] << " pick up row" << Row2;
					system("pause");
					break;

				}
				continue;

			}
			//~~~draw card~~~
			else {

				draw_card();
				system("pause");
				Row1 = (rand() % 4 + 1);
				while (drawed_card[Row1 - 1][0] == "XX" || rowcounter[Row1 - 1] == 3) {

					Row1 = (rand() % 4 + 1);

				}
				put_the_card(Row1);
				screen_display();
				cout << endl << playername[playerturn - 1] << " put the card to row" << Row1;
				system("pause");
				break;

			}

		}

	}
	//******pick the row******
	else if (choice == 2) {

		for (int row = 0; row <= 3; row++) {

			//exclude the situation of all picked or empty row and lead to ~~~draw card~~~
			if (drawed_card[row][0] == "XX" || drawed_card[row][0] == "  ") {

				if (row == 3) {

					draw_card();
					system("pause");

					Row1 = (rand() % 4 + 1);
					while (drawed_card[Row1 - 1][0] == "XX" || rowcounter[Row1 - 1] == 3) {

						Row1 = (rand() % 4 + 1);

					}

					put_the_card(Row1);
					screen_display();
					cout << endl << playername[playerturn - 1] << " put the card to row" << Row1;
					system("pause");
					break;

				}
				continue;

			}
			//~~~pick the row~~~
			else {

				Row2 = (rand() % 4 + 1);

				while (drawed_card[Row2 - 1][0] == "XX" || drawed_card[Row2 - 1][0] == "  ") {

					Row2 = (rand() % 4 + 1);

				}

				pick_the_row(Row2);
				screen_display();
				cout << endl << playername[playerturn - 1] << " pick up row" << Row2;
				break;

			}

		}

	}

	return;
}

void player4() {

	cout << "\nyou have two choice : " << "\n(1)draw a card and put it to a row\n" << "(2)pick up a row"

		<< "\n please input 1 or 2 to choose : ";

	cin >> choice;

	while (cin.fail()) {

		cin.clear();
		cin.ignore(2000, '\n');
		cout << "\nwrong input ! " << "Please input again : ";
		cin >> choice;

	}
	//******draw card******
	if (choice == 1) {

		for (int row = 0; row <= 3; row++) {

			//exclude the situation of all picked or full row and lead to ~~~pick the row~~~
			if (drawed_card[row][0] == "XX" || rowcounter[row] == 3) {

				if (row == 3) {

					cout << "\nThere is no row to put the card !" << " Please choose a row to pick up ! : ";

					cin >> Row2;
					while (cin.fail()) {

						cin.clear();
						cin.ignore(2000, '\n');
						cout << "\nwrong input ! " << "Please input again : ";
						cin >> Row2;

					}
					while (Row2 < 1 || Row2 > 4) {

						cout << "\nPlease input a valid number !";
						cin >> Row2;

					}

					while (drawed_card[Row2 - 1][0] == "XX" || drawed_card[Row2 - 1][0] == "  ") {

						cout << "\nThis row can't be picked !" << "Please choose another row ! : ";

						cin >> Row2;
						while (cin.fail()) {

							cin.clear();
							cin.ignore(2000, '\n');
							cout << "\nwrong input ! " << "Please input again : ";
							cin >> Row2;

						}
						while (Row2 < 1 || Row2 > 4) {

							cout << "\nPlease input a valid number !";
							cin >> Row2;

						}

					}

					pick_the_row(Row2);
					screen_display();
					cout << playername[playerturn - 1] << " pick up row" << Row2;
					system("pause");
					break;

				}
				continue;

			}
			//~~~draw card~~~
			else {

				draw_card();
				system("pause");

				cout << "\nPlease choose a row to put the card : ";

				cin >> Row1;
				while (cin.fail()) {

					cin.clear();
					cin.ignore(2000, '\n');
					cout << "\nwrong input ! " << "Please input again : ";
					cin >> Row1;

				}
				while (Row1 < 1 || Row1 > 4) {

					cout << "\nPlease input a valid number !";
					cin >> Row1;

				}

				while (drawed_card[Row1 - 1][0] == "XX" || rowcounter[Row1 - 1] == 3) {

					cout << "\nYou can't put this row !" << "Please choose another row! : ";

					cin >> Row1;
					while (cin.fail()) {

						cin.clear();
						cin.ignore(2000, '\n');
						cout << "\nwrong input ! " << "Please input again : ";
						cin >> Row1;

					}
					while (Row1 < 1 || Row1 > 4) {

						cout << "\nPlease input a valid number !";
						cin >> Row1;

					}

				}

				put_the_card(Row1);
				screen_display();
				cout << playername[playerturn - 1] << " put the card to row" << Row1;
				system("pause");
				break;

			}

		}

	}
	//******pick the row******
	else if (choice == 2) {

		for (int row = 0; row <= 3; row++) {

			//exclude the situation of all picked or empty row and lead to ~~~draw card~~~
			if (drawed_card[row][0] == "XX" || drawed_card[row][0] == "  ") {

				if (row == 3) {

					cout << "\nThere is no row to pick up !" << " Please draw a card ";
					system("pause");

					draw_card();
					cout << "\nPlease choose a row to put the card : ";

					cin >> Row1;
					while (cin.fail()) {

						cin.clear();
						cin.ignore(2000, '\n');
						cout << "\nwrong input ! " << "Please input again : ";
						cin >> Row1;

					}
					while (Row1 < 1 || Row1 > 4) {

						cout << "\nPlease input a valid number !";
						cin >> Row1;

					}

					while (drawed_card[Row1 - 1][0] == "XX" || rowcounter[Row1 - 1] == 3) {

						cout << "\nYou can't put this row !" << "Please choose another row ! : ";

						cin >> Row1;
						while (cin.fail()) {

							cin.clear();
							cin.ignore(2000, '\n');
							cout << "\nwrong input ! " << "Please input again : ";
							cin >> Row1;

						}
						while (Row1 < 1 || Row1 > 4) {

							cout << "\nPlease input a valid number !";
							cin >> Row1;

						}

					}
					put_the_card(Row1);
					screen_display();
					cout << playername[playerturn - 1] << " put the card to row" << Row1;
					system("pause");
					break;

				}
				continue;

			}
			//~~~pick the row~~~
			else {

				cout << "\nplease choose a row to pick up : ";

				cin >> Row2;
				while (cin.fail()) {

					cin.clear();
					cin.ignore(2000, '\n');
					cout << "\nwrong input ! " << "Please input again : ";
					cin >> Row2;

				}
				while (Row2 < 1 || Row2 > 4) {

					cout << "\nPlease input a valid number !";
					cin >> Row2;

				}

				while (drawed_card[Row2 - 1][0] == "XX" || drawed_card[Row2 - 1][0] == "  ") {

					cout << "\nThis row can't be picked !" << "Please choose another row ! : ";

					cin >> Row2;
					while (cin.fail()) {

						cin.clear();
						cin.ignore(2000, '\n');
						cout << "\nwrong input ! " << "Please input again : ";
						cin >> Row2;

					}
					while (Row2 < 1 || Row2 > 4) {

						cout << "\nPlease input a valid number !";
						cin >> Row2;

					}


				}

				pick_the_row(Row2);
				screen_display();
				cout << playername[playerturn - 1] << " pick up row" << Row2;
				system("pause");
				break;

			}

		}

	}
	else {

		cout << "\nPlease input a valid number !";
		player4();

	}
	return;
}

void screen_display() {

	system("cls");

	//player 1

	cout << setw(65) << "player_1" << setw(41) << "¬õ ¯» ¾í ¶À ºñ ÂÅ ¦Ç +2 ÅÜ" << endl

		<< setw(82);

	for (int i = 0; i <= 8; i++) {

		cout << playerS_color[0][i] << "  ";

	}
	cout << "\n" << setw(65) << "status: " << player_status[0];

	cout << "\n\n\n\n";

	//print out the words at the last round
	if (deck[77] == 1) {
		cout << "        deck" << "    END" << "\n        " << cardleft;
	}
	else {
		cout << "        deck" << "\n        " << cardleft;
	}

	//just for debug
	/*for (int i = 0; i < 120; i++) {
	cout << "*";
	} */

	//player 2

	cout << setw(55) << "player_2" << setw(41) << "¬õ ¯» ¾í ¶À ºñ ÂÅ ¦Ç +2 ÅÜ" << endl

		<< setw(82);

	for (int i = 0; i <= 8; i++) {

		cout << playerS_color[1][i] << "  ";

	}

	//the row of deck
	cout << "\n" << "\t" << "row1" << " " << drawed_card[0][0] << " " << drawed_card[0][1] << " " << drawed_card[0][2]
		<< setw(44) << "status: " << player_status[1] << endl;

	cout << "\t" << "row2" << " " << drawed_card[1][0] << " " << drawed_card[1][1] << " " << drawed_card[1][2] << endl;
	cout << "\t" << "row3" << " " << drawed_card[2][0] << " " << drawed_card[2][1] << " " << drawed_card[2][2] << endl;
	cout << "\t" << "row4" << " " << drawed_card[3][0] << " " << drawed_card[3][1] << " " << drawed_card[3][2] << endl;
	cout << "\n";

	//player 3

	cout << setw(65) << "player_3" << setw(41) << "¬õ ¯» ¾í ¶À ºñ ÂÅ ¦Ç +2 ÅÜ" << endl

		<< setw(82);

	for (int i = 0; i <= 8; i++) {

		cout << playerS_color[2][i] << "  ";
	}

	cout << "\n" << setw(65) << "status: " << player_status[2];

	cout << "\n\n\n\n\n";

	//player 4

	cout << setw(65) << "You" << setw(41) << "¬õ ¯» ¾í ¶À ºñ ÂÅ ¦Ç +2 ÅÜ" << endl

		<< setw(82);

	for (int i = 0; i <= 8; i++) {

		cout << playerS_color[3][i] << "  ";

	}
	cout << "\n" << setw(65) << "status: " << player_status[3];

	cout << "\n\n\n\n\n";



	return;
}


void welcome_display() {

	cout << " ";
	for (int p = 1; p <= 2; p++) {

		for (int i = 1; i <= 9; i++) {

			for (int k = 1; k <= 14; k++) {

				cout << "*";

			}

			cout << "  ";

		}

	}






	system("pause");


}


void initializing() {

	//initialize the Playerstatus for the next round
	for (int i = 0; i <= 3; i++) {

		Playerstatus[i] = 0;

	}

	//initialize all of the row for the next round
	for (int i = 0; i <= 3; i++) {

		for (int j = 0; j <= 2; j++) {

			drawed_card[i][j] = "  ";

		}
	}

	//initialize the player_status for the next round
	for (int i = 0; i <= 3; i++) {

		player_status[i] = "not finished";

	}

	//initialize the rowcounter for the next round to count how many there are in the row
	for (int i = 0; i <= 3; i++) {

		rowcounter[i] = 0;

	}


}

void insertion_sort(int player_card[], int arraysize) {

	for (int next = 1; next < arraysize; next++) {

		int insert = player_card[next];
		int moveitem = next;

		while ((moveitem > 0) && (player_card[moveitem - 1] > insert)) {

			player_card[moveitem] = player_card[moveitem - 1];
			moveitem--;

		}
		player_card[moveitem] = insert;
	}

	return;
}

int score(int first, int second, int third, int plus_two, int card0, int card1, int card2, int card3) {

	int Score = 0;
	int data[4] = { first,second,third,plus_two };
	int negative[4] = { card0 ,card1,card2 ,card3 };

	for (int index = 0; index <= 2; index++) {

		if (data[index] >= 6) {

			Score += 21;

		}
		else if (data[index] == 5) {

			Score += 15;

		}
		else if (data[index] == 4) {

			Score += 10;

		}
		else if (data[index] == 3) {

			Score += 6;

		}
		else if (data[index] == 2) {

			Score += 3;

		}
		else if (data[index] == 1) {

			Score += 1;

		}
		else if (data[index] == 0) {

			Score += 0;

		}
		else {
			cout << "error in the score!!";
		}



	}

	for (int index = 0; index <= 3; index++) {

		if (negative[index] >= 6) {

			Score -= 21;

		}
		else if (negative[index] == 5) {

			Score -= 15;

		}
		else if (negative[index] == 4) {

			Score -= 10;

		}
		else if (negative[index] == 3) {

			Score -= 6;

		}
		else if (negative[index] == 2) {

			Score -= 3;

		}
		else if (negative[index] == 1) {

			Score -= 1;

		}
		else if (negative[index] == 0) {

			Score -= 0;

		}
		else {
			cout << "error in the score!!";
		}

	}

	Score += data[3] * 2;

	return Score;
}
