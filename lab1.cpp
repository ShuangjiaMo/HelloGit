//Filename: lab1
//Guessing game
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int game();

int main()
{	int times = 0, win = 0;
	char choice;
	bool stop = false;
	
	while (stop == false){
		do {
			cout << "Do you want to play with me(Y/N)?";
			cin >> choice;
		} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');
		
		if (choice == 'Y' || choice == 'y'){
			times += 1;
			win += game();			//If you win the game,the return value is 1.
		}
		else stop = true;
	}
	
	cout << "Total:" << times << " Win:" << win <<" Lose:" << times-win << endl;
	return 0;
}

int game()
{	int guessNum[3], num[] = {0, 0, 0, 10, 10}, i, j, A, B, round=1;			//The last 2 numbers of num[] ensure that num[4-i] will not out of range.
	
	srand(time(NULL));
	
	for (i=0; i<3; ++i){
		do {
			num[2-i] = rand() % 10;
		} while (num[2-i] == num[3-i] || num[2-i] == num[4-i]);			//The first 3 numbers of num[] is the random numbers that we need.	                           
	}
	
	while (round <= 7){
		cout << "Please guess 3 number(0~9):";
		cin >> guessNum[0] >> guessNum[1] >> guessNum[2];
		
		A=0;
		B=0;
		
		for (i=0; i<3; ++i){
			if (num[i] == guessNum[i]) A+=1;
		}
		for (i=0; i<3; ++i){
			for (j=0; j<3; ++j){
				if (guessNum[i] == num[j]) B+=1;
			}
		}
		B -= A;			//B doesn't contain the right numbers with right place.
		
		if (A == 3) {
			cout << "You guessed it!" << endl;
			return 1;
		}
		else {
			cout << A << 'A' << B << 'B' << endl;
			round += 1;
		}	
	}
	
	cout << "Game over.The answer is " << num[0] << num[1] << num[2] << endl;
	return 0;
 } 


