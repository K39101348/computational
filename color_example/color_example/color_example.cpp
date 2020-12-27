#include<iostream>
#include<ctime>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<functional>
using namespace std;

void output_1(const int[], int);
void output_player_card(const int sheet[][30][3], int player, int times, int card);
void output_row_card(const int sheet[][3], int row, int card);
void alter_ary(int[], int);
void no_card1(int[], int);
void no_card_row(int a[][3], int, int);
void no_card_player(int a[][30][3], int, int, int);



int main()
{
	bool error4 = true;
	int play_game = 0;
	cout << "a.the card 0 is end card\nb.the card 1-7 are different color's card\nc.the card 8 is add 2 grade\nd.the card 9 is Coloretto\n";
	cout << "e.-1 indicate no card\nf.-2 indicate card have be collect\n";
	while (error4 = true)
	{
		cout << "enter 1 to player game or 2 to end game:";
		cin >> play_game;
		while (cin.fail())                   // input error
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "input error\n";
			cout << " enter 1 to get card or 2 to collect card ";
			cin >> play_game;
		}
		if (play_game != 1 && play_game != 2)                           //can't cin another number
		{
			cout << "input error\n";
			continue;
		}
		if (play_game == 1)
		{

			srand(time(0));

			int origial_card_a, origial_card_b, origial_card_c, origial_card_d;
			int WHILE_condition = 1;

			origial_card_a = 1 + rand() % 7;

			while (WHILE_condition == 1)
			{
				origial_card_b = 1 + rand() % 7;
				if (origial_card_b == origial_card_a)
					WHILE_condition = 1;
				else
					WHILE_condition = 0;
			}

			while (WHILE_condition == 0)
			{
				origial_card_c = 1 + rand() % 7;
				if (origial_card_c == origial_card_a || origial_card_c == origial_card_b)
					WHILE_condition = 0;
				else
					WHILE_condition = 1;
			}

			while (WHILE_condition == 1)
			{
				origial_card_d = 1 + rand() % 7;
				if (origial_card_d == origial_card_a || origial_card_d == origial_card_b || origial_card_d == origial_card_c)
					WHILE_condition = 1;
				else
					WHILE_condition = 0;
			}

			/*cout << origial_card_a << origial_card_b << origial_card_c << origial_card_d << endl;*/

			int colour[8] = { 0,9,9,9,9,9,9,9 };
			colour[origial_card_a]--;
			colour[origial_card_b]--;
			colour[origial_card_c]--;
			colour[origial_card_d]--;

			/*output_1(colour, 8);
			for (int i = 1; i < 8; i++)                                                    //test
			cout << colour[i];
			cout << endl;*/

			int all_card[73] = {};
			for (int i = 0; i < colour[1]; i++)
				all_card[i] = 1;                                                           //colour 1
			for (int i = colour[1]; i < colour[1] + colour[2]; i++)
				all_card[i] = 2;                                                           //colour 2
			for (int i = colour[1] + colour[2]; i < colour[1] + colour[2] + colour[3]; i++)
				all_card[i] = 3;                                                           //colour 3
			for (int i = colour[1] + colour[2] + colour[3]; i < colour[1] + colour[2] + colour[3] + colour[4]; i++)
				all_card[i] = 4;
			for (int i = colour[1] + colour[2] + colour[3] + colour[4]; i < colour[1] + colour[2] + colour[3] + colour[4] + colour[5]; i++)
				all_card[i] = 5;
			for (int i = colour[1] + colour[2] + colour[3] + colour[4] + colour[5]; i < colour[1] + colour[2] + colour[3] + colour[4] + colour[5] + colour[6]; i++)
				all_card[i] = 6;
			for (int i = colour[1] + colour[2] + colour[3] + colour[4] + colour[5] + colour[6]; i < colour[1] + colour[2] + colour[3] + colour[4] + colour[5] + colour[6] + colour[7]; i++)
				all_card[i] = 7;

			for (int i = 59; i < 69; i++)
				all_card[i] = 8;                                                            //add card
			for (int i = 69; i < 72; i++)
				all_card[i] = 9;                                                            //Coloretto

																							/*output_1(all_card, 73);
																							for (int i = 0; i < 73; i++)                                                    //test
																							cout << all_card[i];
																							cout << endl;*/

																							//too slow;
																							/*for (int counter = 1; counter < 10000000; counter++)
																							{
																							for (int i = 0; i < 72; i++)
																							{
																							int tep = all_card[i];
																							all_card[i] = all_card[72-i];
																							all_card[72-i] = tep;

																							int tep2 = all_card[i];
																							all_card[i] = all_card[i+1];
																							all_card[i+1] = tep2;
																							}
																							}
																							*/
			for (int i = 1; i < 1000; i++)                                    //Shuffle
			{
				int index1 = rand() % 72;
				int index2 = rand() % 72;
				int temp = all_card[index1];

				all_card[index1] = all_card[index2];
				all_card[index2] = temp;
			}

			/*output_1(all_card, 73);
			for (int i = 0; i < 73; i++)                                     //test
			cout << all_card[i];
			cout << endl;*/


			for (int i = 72; i >= 58; i--)                                   //put the end card
				all_card[i] = all_card[i - 1];
			all_card[57] = 0;


			/*int test[10] = {};                                             //test
			for (int i = 0; i < 73; i++)
			test[all_card[i]]++;
			output_1(test, 10);
			for (int i = 0; i <10; i++)
			cout << test[i];
			cout << endl;*/

			int Row_card[4][3] = {};
			int Row_counter[4] = {};
			int player_card[4][30][3] = {};
			int take_card[4] = { 1,1,1,1 };
			int card_taken[4] = {};
			int player_order[4] = { 4,0,0,0 };
			int a = 1;
			int order = 0;

			no_card_row(Row_card, 4, 3);                                            //test
			no_card_player(player_card, 4, 30, 3);

			/*output_player_card(player_card, 4, 30, 3);
			output_row_card(Row_card, 4, 3);*/


			player_card[0][0][0] = origial_card_a;
			player_card[1][0][0] = origial_card_b;
			player_card[2][0][0] = origial_card_c;
			player_card[3][0][0] = origial_card_d;

			output_player_card(player_card, 4, 1, 3);


			for (int Y = 1; Y < 100; Y++)                             //the times;repet the 174 FOR;
			{
				bool zero = false;                                    //if get 0

				for (int i = 0; i < 4; i++)                           //let the last collect card player to play new game fist
				{
					if (player_order[i] == 4)
					{
						a = i + 1;                                    // a=1-4;a=2;player2 star;the fist time over.remeber a=1
					}
					player_order[i] = 0;                              //the order come to new game,need initialize
				}

				for (int z = 0; z < 100; z++) {                           //the first game over      
					while (a <= 4)
					{

						if (take_card[a - 1] == -1)                       //let have collected card's player can't playgame
						{                                                 //if the 4 players had collected card,will continue skip until z=100;
							a++;
							continue;
						}
						else {
							int conduct;                                  // get card or collet card;
							bool error1 = true;                           // if the enter error . can repete the cout;
							while (error1 == true)
							{
								cout << "player " << a << " enter 1 to get card or 2 to collect card ";
								if (a == 1)                               //player 1
								{
									cin >> conduct;
									while (cin.fail())                   // input error
									{
										cin.clear();
										cin.ignore(100, '\n');
										cout << "input error\n";
										cout << " enter 1 to get card or 2 to collect card ";
										cin >> conduct;
									}
									if (conduct != 1 && conduct != 2) //can't cin another number
									{
										cout << "input error\n";
										continue;
									}
								}
								else                                     //AI
									conduct = rand() % 2 + 1;
								if (conduct == 1)
								{
									if (take_card[a - 1] == 1 && (Row_counter[0] < 3 || Row_counter[1] < 3 || Row_counter[2] < 3 || Row_counter[3] < 3) && (card_taken[0] != -1 || card_taken[1] != -1 || card_taken[2] != -1 || card_taken[3] != -1))
										//1.  the plalyer can take card  2.  row1.2.3.4 can't three rows are collect and one row has three card  3.  four row card can't be collect 
									{
										bool error2 = true;
										int temp_card;
										int temp_row;

										temp_card = all_card[0];									   //get card
										alter_ary(all_card, 73);									   //let card go forword

										if (temp_card == 0)											   //get the card 0;prepare over game
										{
											zero = true;
											temp_card = all_card[0];								   //get card again
											cout << "zero drawn!\n\n\n";
											alter_ary(all_card, 73);
										}

										//output_1(all_card, 73);                                      //test
										while (error2 == true)                                         //if cin error can repet cout
										{
											cout << "player " << a << " get the card " << temp_card << endl << "please enter 1,2,3,4 ,let card is put on Row_card1,Row_card2,Row_card3,Row_card4.";

											if (a == 1)                                                //player 1
											{
												cin >> temp_row;
												while (cin.fail())
												{
													cin.clear();
													cin.ignore(100, '\n');
													cout << "input error\n";
													cout << " please enter 1, 2, 3, 4, let card is put on Row_card1, Row_card2, Row_card3, Row_card4.";
													cin >> temp_row;
												}
												if (temp_row != 1 && temp_row != 2 && temp_row != 3 && temp_row != 4)  //can't cin another number
												{
													cout << "input error\n";
													continue;
												}
											}
											else                                                                        //AI
												temp_row = rand() % 4 + 1;
											cout << endl;

											if (Row_counter[temp_row - 1] != 3 && card_taken[temp_row - 1] != -1)       //the row can put card(card taken =0 or 1) and the row dose't fill three cards.
											{
												Row_card[temp_row - 1][Row_counter[temp_row - 1]] = temp_card;          //cin row_card [input number][card 1 2 3]
												card_taken[temp_row - 1] = 1;                                           //original=0 be collect=-1 can collect=1
												Row_counter[temp_row - 1]++;                                            //Row_counter[input number]++


												output_player_card(player_card, 4, Y, 3);                               //cout player_card[4 players][times][three cards]
												output_row_card(Row_card, 4, 3);                                        //cout row_card[4 players][three cards]

												error2 = false;                                                         //skip WHILE
												error1 = false;                                                         //skip WHILE
											}
											else
											{
												cout << "the row " << temp_row << " can't put the card" << endl;
												error2 = true;                                                          //return WHILE
											}
										}
									}

									else
									{
										cout << " can't get the card" << endl;
										error1 = true;                                                                   //return WHILE
									}
								}



								else if (conduct == 2)                                                                  //collect card
								{

									if (card_taken[0] == 1 || card_taken[1] == 1 || card_taken[2] == 1 || card_taken[3] == 1)//one of row can take card
									{
										int temp_row_card[3] = { -1,-1,-1 };
										int temp_row;
										bool error3 = true;                                                             //if cin error can repet cout
										while (error3 == true)
										{
											cout << "please enter 1,2,3,4 ,collect  Row_card1,Row_card2,Row_card3,Row_card4";

											if (a == 1)                                                                //player 1
											{
												cin >> temp_row;
												while (cin.fail())                                                     //can't cin another type
												{
													cin.clear();
													cin.ignore(100, '\n');
													cout << "input error\n";
													cout << "please enter 1,2,3,4 ,collect  Row_card1,Row_card2,Row_card3,Row_card4";
													cin >> temp_row;
												}
												if (temp_row != 1 && temp_row != 2 && temp_row != 3 && temp_row != 4) //can't cin another number
												{
													cout << "input error\n";
													continue;
												}
											}
											else                                                                      //AI
												temp_row = rand() % 4 + 1;

											if (card_taken[temp_row - 1] == 1)                                        //row[cin] can collect the card
											{
												take_card[a - 1] = -1;                                                //player can't action      original=0 be collect=-1 can collect=1
												card_taken[temp_row - 1] = -1;                                        //row can't be put card    original=0 be collect=-1 can collect=1
												Row_counter[temp_row - 1] = 3;                                        //row_counter=3 let the if 210 can be conduct
												for (int i = 0; i < 3; i++)
												{
													player_card[a - 1][Y][i] = Row_card[temp_row - 1][i];             //player stored card=row
													Row_card[temp_row - 1][i] = -2;                                   //indicate the row can't put the cards
												}

												order++;                                                              // the first player collect card order=1  (let if 167 can conduct)
												player_order[a - 1] = order;

												output_player_card(player_card, 4, Y, 3);                             //cout player_card[4 players][times][three cards]
												output_row_card(Row_card, 4, 3);                                      //cout row_card[4 players][three cards]

												error3 = false;                                                        //skip WHILE
												error1 = false;                                                        //skip WHILE
											}
											else
											{
												cout << "no card can collect\n";                                       //return WHILE
												error3 = true;
											}
										}
									}
									else
									{
										cout << "no card can collect\n";                                               //return WHILE
										error1 = true;
									}
								}
								else
								{
									cout << "input error\n";                                                           //return WHILE
									continue;
								}
							}
						}
						a++;                                                                                           //player2 end player 3 start
					}
					a = 1;                                                                                             //that player1 start
				}

				/*for (int i = 0; i < 4; i++)                          //test
					cout << player_order[i] << "  ";*/

				for (int i = 0; i < 4; i++)                                                                           // the new time initialization the value
				{
					Row_counter[i] = 0;                                                                               // reset can't write Row_counter[i] = {1,1,1,1}
					take_card[i] = 1;
					card_taken[i] = 0;
					order = 0;
					for (int a = 0; a < 3; a++)
						Row_card[i][a] = -1;
				}
				if (zero == true) {
					cout << "zero drawn!\n\n\n";
					int counter_number[4][9];
					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < 9; j++)
						{
							counter_number[i][j] = 0;

						}
					}
					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < Y + 1; j++)
						{
							for (int k = 0; k < 3; k++)
							{
								if (player_card[i][j][k] == -1)
									continue;
								counter_number[i][player_card[i][j][k] - 1]++;
							}
						}
					}

					for (int i = 0; i < 4; i++)
					{
						cout << "player  " << i + 1 << "  counter_number  " << endl;
						for (int j = 0; j < 9; j++)
							cout << counter_number[i][j];
						cout << endl;
					}
					for (int i = 0; i < 4; i++)
					{
						for (int j = 1; j < 7; j++)
						{
							int temp_counter_number = counter_number[i][j];;
							for (int k = j; k > 0; k--)
							{
								if (counter_number[i][k] > counter_number[i][k - 1])
								{


									counter_number[i][k] = counter_number[i][k - 1];
									counter_number[i][k - 1] = temp_counter_number;

								}
							}
						}
						/*sort(counter_number[i], counter_number[i] + 7, greater<int>());*/
					}
					for (int i = 0; i < 4; i++)
					{
						cout << "player  " << i + 1 << "  counter_number order " << endl;
						for (int j = 0; j < 9; j++)
							cout << counter_number[i][j];
						cout << endl;
					}
					for (int i = 0; i < 4; i++)
					{
						for (int j = 0; j < counter_number[i][8]; j++)
						{
							if (counter_number[i][0] < 6)
								counter_number[i][0]++;
							else if (counter_number[i][1] < 6)
								counter_number[i][1]++;
							else if (counter_number[i][2] < 6)
								counter_number[i][2]++;
							else if (counter_number[i][3] < 6)
								counter_number[i][3]++;
							else if (counter_number[i][4] < 6)
								counter_number[i][4]++;
							else if (counter_number[i][5] < 6)
								counter_number[i][5]++;
							else if (counter_number[i][5] < 6)
								counter_number[i][5]++;
						}
					}
					for (int i = 0; i < 4; i++)                                                        //test
					{
						cout << "player  " << i + 1 << "  counter_number with Colorett)  " << endl;
						for (int j = 0; j < 9; j++)
							cout << counter_number[i][j];
						cout << endl;
					}

					int fraction[4][9];

					for (int i = 0; i < 4; i++)
					{

						for (int j = 0; j < 7; j++)
						{
							switch (counter_number[i][j])
							{
							case 0:fraction[i][j] = 0;
								break;
							case 1:fraction[i][j] = 1;
								break;
							case 2:fraction[i][j] = 3;
								break;
							case 3:fraction[i][j] = 6;
								break;
							case 4:fraction[i][j] = 10;
								break;
							case 5:fraction[i][j] = 15;
								break;
							case 6:fraction[i][j] = 21;
								break;
							case 7:fraction[i][j] = 21;
								break;
							case 8:fraction[i][j] = 21;
								break;
							case 9:fraction[i][j] = 21;
								break;

							}
						}
					}

					int total[4];
					for (int i = 0; i < 4; i++)
					{
						total[i] = fraction[i][0] + fraction[i][1] + fraction[i][2] - fraction[i][3] - fraction[i][4] - fraction[i][5] - fraction[i][6] + counter_number[i][7] * 2;
					}
					for (int i = 0; i < 4; i++)
					{
						cout << "player " << i + 1 << "fraction : " << total[i] << endl;
					}

					int temp_player = 1;
					int max = total[0];
					for (int i = 1; i < 4; i++)
					{
						if (total[i] > max)
						{
							max = total[i];
							temp_player = i + 1;
						}
					}
					cout << "the winner is player " << temp_player << endl;

					break;                                                                                           //get ZERO break WHILE
				}
			}

		}
		if (play_game == 2)
			break;
	}

	system("pause");
	return 0;

}


void output_1(const int a[], int size)
{
	for (int i = 0; i < size; i++)
		cout << a[i] << "  ";
	cout << endl;
}


void output_row_card(const int a[][3], int row, int card)
{
	for (int i = 0; i < row; i++)
	{
		cout << "the row " << i + 1 << "  card:  ";                                                //output row1.2.3

		for (int number_of_sheets = 0; number_of_sheets < 3; number_of_sheets++)                //output card1.2.3
			cout << "card" << number_of_sheets + 1 << "  ";
		cout << endl << "             ";
		for (int b = 0; b < card; b++)
			cout << setw(8) << a[i][b];
		cout << endl;

	}
}


void output_player_card(const int sheet[][30][3], int player, int times, int card)
{
	for (int i = 0; i < player; i++)
	{
		cout << "player " << i + 1 << "  stored cards\n";                                    //cout player1234
		cout << "            ";
		for (int number_of_sheets = 0; number_of_sheets < 3; number_of_sheets++)
			cout << "card" << number_of_sheets + 1 << "  ";                                 //card 1.2.3
		cout << endl;

		for (int b = 0; b <= times; b++)
		{
			cout << "time  " << setw(2) << b;                                             //time 1.2.3
			for (int c = 0; c < card; c++)
				cout << setw(8) << sheet[i][b][c];
			cout << endl;
		}
		cout << endl;
	}
}

void alter_ary(int allcard[], int size)                                                     //that the second card became first 
{
	for (int i = 0; i < size - 1; i++)
	{
		allcard[i] = allcard[i + 1];
	}
	allcard[size - 1] = -3;
}

void no_card1(int a[], int size)
{
	for (int i = 0; i < size; i++)
		a[i] = -1;                                                                   //cin-1
}
void no_card_row(int a[][3], int row, int card)
{
	for (int i = 0; i < row; i++)
	{
		for (int b = 0; b < card; b++)
			a[i][b] = -1;                                                        //cin-1
	}
}
void no_card_player(int a[][30][3], int player, int times, int card)
{
	for (int c = 0; c < player; c++)
	{
		for (int i = 0; i < times; i++)
		{
			for (int b = 0; b < card; b++)
				a[c][i][b] = -1;                                              //cin -1
		}
	}
}