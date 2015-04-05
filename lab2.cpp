//Filename: lab2
//Blackjack
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

bool game(), MakeChoice();
double CardValue(int CardNumber);
void PrintCard(int CardNumber);

int main()
{	bool choice_1 = true;
	
	while (choice_1 == true){
		if (game()) cout << "You win." << endl;
		else cout << "You lose." << endl;
		
		cout << "Continue?(y/n) ";
		choice_1 = MakeChoice();
		cout << endl;
	}
	
	return 0;
}

bool game()
{	char choice_2 = 'y';
	double P_sum, C_sum;
	int cards[52], shuffle[52], LeftNum = 52, RanNum, P_round = 1, C_round, i;

	for(i=0; i<52; i++) cards[i]=i;			//Part 1: Shuffling the cards

	for(i=0; i<52; i++){					
		srand(time(NULL));
		RanNum=rand() % LeftNum;			
											//cards[52] is a sequence of natural numbers from 0 to 51
		shuffle[i]=cards[RanNum];			//shuffle[52] is a disorder of cards[52]
		cards[RanNum]=cards[LeftNum-1];
		
		LeftNum--;      
	}
	
	cout << "---Player's Turn---" << endl;			//Part 2: Player's turn
	P_sum = CardValue(shuffle[0]);
	
	while (choice_2){
		cout << "Your cards: ";
		for (i=0; i<=P_round; ++i) PrintCard(shuffle[i]);
		cout << endl;
		
		P_sum += CardValue(shuffle[P_round]); 	
		if (P_sum > 21) return false;
		
		cout << "Need another card?(y/n) ";
		choice_2 = MakeChoice();
		
		++P_round;
	}
	
	cout << "---Computer's Turn---" << endl;			//Part 3: Computer's turn
	C_round = P_round;
	C_sum = CardValue(shuffle[C_round]);
	
	while (true){
		cout << "Computer's cards: ";		
		for (i=P_round; i<=C_round+1; ++i) PrintCard(shuffle[i]);
		cout << endl;
		
		C_sum += CardValue(shuffle[C_round+1]);		
		if (C_sum > 21) return true;
		if (C_sum > P_sum) return false;
			
		++C_round;
	}
}

bool MakeChoice()
{	char choice;
	
	do {cin >> choice;
		cin.sync(); 
	} while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n');			//check the input
	
	if (choice == 'Y' || choice == 'y') return true;
	else return false;
}

double CardValue(int CardNumber)
{	if (CardNumber%13 > 9) return 0.5;
	else return CardNumber%13+1;
}

void PrintCard(int CardNumber)			//translate the card number(a number between 0 and 51) to a card
{	char ColorPicture;
	
	switch(CardNumber/13){
		case 0: ColorPicture = 6; break;
		case 1: ColorPicture = 3; break;
		case 2: ColorPicture = 5; break;
		default: ColorPicture = 4;
	}
	cout << ColorPicture;
	
	switch(CardNumber%13){
		case 0: cout << 'A'; break;
		case 10: cout << 'J'; break;
		case 11: cout << 'Q'; break;
		case 12: cout << 'K'; break;
		default: cout << CardNumber%13+1;
	}
	cout << ' ';	
}

