//Filename: lab2
//Blackjack
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

bool game();
double CardValue(int CardNumber);
void PrintCard(int color, int number);

int main()
{	char choice_1 = 'y';
	
	while (choice_1 == 'Y' || choice_1 == 'y'){
		if (game()) cout << "You win." << endl;
		else cout << "You lose." << endl;
		
		do {
			cout << "Continue?(y/n) ";
			cin >> choice_1;
			cin.sync();
		} while (choice_1 != 'Y' && choice_1 != 'y' && choice_1 != 'N' && choice_1 != 'n');
		
		cout << endl;
	}
	
	return 0;
}

bool game()
{	char choice_2 = 'y';
	int cards[52][2], P_card[52][2], C_card[52][2], P_round = 1, C_round = 1, i, j;
	double P_sum, C_sum;
	
	cout << "---Player's Turn---" << endl << "Your cards: ";
	
	srand(time(NULL));
	cards[0][0] = P_card[0][0] = rand() % 4;
	cards[0][1] = P_card[0][1] = rand() % 13;
	
	P_sum = CardValue(P_card[0][1]);
	
	while (choice_2 == 'y'){
		cards[P_round][0] = P_card[P_round][0] = rand() % 4;
		cards[P_round][1] = P_card[P_round][1] = rand() % 13;
		
		for (i=0; i<=P_round; ++i) PrintCard(P_card[i][0], P_card[i][1]);
		cout << endl;
		
		P_sum += CardValue(P_card[P_round][1]); 	
		if (P_sum > 21) return false;
		
		do {
			cout << "Need another card?(y/n) ";
			cin >> choice_2;
			cin.sync(); 
		} while (choice_2 != 'Y' && choice_2 != 'y' && choice_2 != 'N' && choice_2 != 'n');
		
		if (choice_2 == 'Y' || choice_2 == 'y') cout << "Your cards: ";
		
		++P_round;
	}
	
	cout << "---Computer's Turn---" << endl << "Computer's cards: ";
		
	C_card[0][0] = rand() % 4;
	C_card[0][1] = rand() % 13;
	C_sum = CardValue(C_card[0][1]);
	
	while (C_round == 1 || C_sum <= P_sum){
		C_card[C_round][0] = rand() % 4;
		C_card[C_round][1] = rand() % 13;
		
		for (j=0; j<=C_round; ++j) PrintCard(C_card[j][0], C_card[j][1]);
		cout << endl;
		
		C_sum += CardValue(C_card[C_round][1]);		
		if (C_sum > 21) return true;
		
		if (C_sum <= P_sum) cout << "Computer's cards: ";
		else return false;
			
		++C_round;
	}
}

double CardValue(int CardNumber)
{	if (CardNumber > 9) return 0.5;
	else return CardNumber+1;
}

void PrintCard(int color, int number)
{	char ColorPicture;
	
	switch(color){
		case 0: ColorPicture = 6; break;
		case 1: ColorPicture = 3; break;
		case 2: ColorPicture = 5; break;
		default: ColorPicture = 4;
	}
	cout << ColorPicture;
	
	switch(number){
		case 0: cout << 'A'; break;
		case 10: cout << 'J'; break;
		case 11: cout << 'Q'; break;
		case 12: cout << 'K'; break;
		default: cout << number+1;
	}
	cout << ' ';	
}

