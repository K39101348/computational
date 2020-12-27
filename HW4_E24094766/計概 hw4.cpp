#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<time.h>
#include<string>
using namespace std;
int ques[4];
void generate();
void guess(int answer[]);
int compare(int answer[]);

int main()
{
	int answer[4];
	int correct_or_not=0;
	
	
	generate();
		

	
	do 
	{cout << "Please input 4 digit number:";
		guess(answer);
		int k=0;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (answer[i] == answer[j]) {
					k++;
				}
						
				}
			}
		if(k != 4)
		{
			cout << "數字不符合規定\n";
		}
		else
		correct_or_not=compare(answer);
	} while (correct_or_not == 0);
	
	cout << "Congratulation !!\n Your answer is right!\n";
	system("PAUSE");
	return EXIT_SUCCESS;

}
void generate()
{
	int repeat;
	int i, j;
	srand(time(NULL));

	ques[0] = rand() % (9) + 1;
	
	for (i = 1; i < 4; i++) {
		do {
			repeat = 0;
			ques[i] = rand() % 9 + 1;
			for(j=0;j<i;j++)
			{
				if(ques[i] == ques[j])
				repeat = 1;
			}
		} while (repeat == 1);
	}
}
void guess(int answer[])
{
	int number, i;
	cin >> number;
	answer[3] = number % 10;
	number = number / 10;
	answer[2] = number % 10;
	number = number / 10;
	answer[1] = number % 10;
	number = number / 10;
	answer[0] = number % 10;
}

int compare(int answer[])
{
	int count_a=0, count_b=0, i, j;

	for (i = 0; i < 4; i++) {
		if (answer[i] == ques[i]) {
			count_a++;
		}
		else
		{
			for (j = 0; j < 4; j++)
			{
				if (answer[i] == ques[j] && i != j)
				{
					count_b++;
					break;
				}
			}

		}
	}
	cout << count_a << "A" << count_b << "B"<<endl;
	if (count_a == 4)
		return 1;
	else
	{
		cout << "Input error! different please!" << endl;
		return 0;
	}
}