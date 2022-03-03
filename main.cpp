#include "pch.h"
#include <iostream>

using namespace std;
using namespace winrt;
using namespace Windows::Foundation;

//vars
int money;
string prof;
int huntchance;
int huntXP = 0;
int days = 1;
int LBSOfFood = 50;
bool hasGun = false;
bool hasGun2 = true;
int diff = 15;
int diff2 = 4;

string name = "Player";
int difficulty = 2;
int strProf = 1;
int Answer1;
char lolIgnore;
int food1;
char Shop1;
char Offer1;
char Offer2;
char rattle;
char IndianAnswer;

void StartOfGame();
int main();

void restart() {
	days++;
	LBSOfFood -= diff;
	if (LBSOfFood < 1) {
		cout << "You Died Of Starvation\n";
		cout << "You Lived Until Day:";
		cout << days;
		cout << "\n\n";
		main();
	}
	if (hasGun && hasGun2) {
		hasGun2 = false;
		huntchance++;
		cout << "Your Hunting Experience Has Improved\n";
		restart();
	}
	cout << "Your Food:";
	cout << LBSOfFood;
	cout << "lbs\n";
	cout << "Your Money:$";
	cout << money;
	cout << "\n\n";
	cout << "Continue?\n";
	
	StartOfGame();
}

void explore() {
	int explorernd = (rand() % 5) + 1;
	switch (explorernd) {
		case 1:
			cout << "You Have Found A Village Full Of Indians\n\n";
			cout << "They Seem Friendly And They Take You To Their Chief\n";
			cout << "The Cheif Offers You $200 And A Gun If You Kill The Chief Of Another Tribe\n";
			cout << "Do You Accept The Offer Y/N\n";
			cin >> Offer1;
			if (Offer1 == 'n') {
				restart();
			}
			else {
				cout << "You Sneak Upon The Enemy Chief, But He Spots You!\n";
				cout << "Next Thing There Are Several Indians Surrounding You\n\n";
				cout << "You discover a barrel of oil next to them, if you shoot it, there is a 25% chance you will die.\n";
				cout << "But Your Know That It Will Save Your Hidee And It Will Kill The Chief";
				cout << "Do You Shoot It? Y/N\n";
				cin >> Offer2;
				if (Offer2 == 'n') {
					restart();
				}
				else {
					int explorernd1 = (rand() % 6) + 1;
					if (explorernd1 == 2) {
						cout << "You Died From An Exploding Barrel\n";
						main();
					}
					else {
						cout << "You Kill The Enemy Tribes Cheif And Return To Get Your Reward\n";
						cout << "+$200\n+ A Gun (Unless You Already Had One)";
						money += 200;
						hasGun = true;
						restart();
					}
				}
			}
			break;
		case 2:
			cout << "You Find A Ginormous Wall Of Rock, It Seems To Be A Plateu\n";
			cout << "You See That There Is A Broken Down Wood Structure\n\n";
			cout << "You Spot Some Silvery Coins In It\n+ $100";
			money += 100;
			restart();
			break;
		case 3:
			cout << "As You Walk You Get Bit In The Foot By A Rattle Snake\n";
			cout << "Unless You Get Medical Care Soon, You Are A Goner\n";
			cout << "There Is A Hospital Nearby But It Will Take 40 Pounds Of Food To Get There\n";
			cout << "Do You Do It? Y/N\n";
			cin >> rattle;
			if (rattle == 'n') {
				cout << "You Died From The Rattlesnake Venom Reaching Your Heart";
				main();
			}
			else {
				LBSOfFood -= 40;
				restart();
			}
			break;
		case 4:
			cout << "You Find A Tribe Of Indians.\n";
			cout << "These Ones Don't Seem To Like You Very Much\n";
			cout << "They Say with imperfect english (Unless you give me 300 food, then you get dead) Do you wish to pay them? Y/N\n";
			cin >> IndianAnswer;
			if (IndianAnswer == 'n'){
				cout << "You died of bleeding from the chest after it was punctered by a spear";
				main();
			}
			else{
				LBSOfFood -= 300;
				restart();
			}
			break;
		case 5:
			cout << "You Seem To Stumble Upon Someone\n Hey ";
			cout << name;
			cout << " Long Time No See\n\nThe Man Seems To Recognize You\n";
			cout << "That's When You Suddenly Remember This Is Your Friend Garret Back In School A Couple Years Earlier\n\n";
			cout << "You Chat For A While And He Brings You Some Food\n(Come Back Anytime Buddy)";
			cout << "You Then Part Ways\n+100 LBS of food";
			LBSOfFood += 100;
			restart();
	}
}


void Shop() {
	cout << "You Found A Lovely Town With A Shop, Would You Like To Enter? Y/N\n";
	cin >> Shop1;
	if (Shop1 == 'N' || Shop1 == 'n') {
		restart();
	}
	cout << "Welcome To The Shop!\n";
	cout << "2$ Per LBS of food\n";
	cout << "Enter How Much Food You Want\n\n";
	cout << "1 - 50 lbs\n";
	cout << "2 - 250 lbs\n";
	cout << "3 - 500 lbs\n";
	cout << "4 - Gun - $300 - This Item Grants You +1 Hunting Level\n";
	cin >> food1;
	if (money < 100) {
		cout << "You Don't Have Enough Money\n";
		restart();
	}
	else {
		switch (food1) {
			case 1:
				if (money > 99) {
					LBSOfFood += 50;
					money -= 100;
				}
				else {
					cout << "You Don't Have Enough Money\n";
					Shop();
				}
				break;
			case 2:
				if (money > 499) {
					LBSOfFood += 250;
					money -= 500;
				}
				else {
					cout << "You Don't Have Enough Money\n";
					Shop();
				}
				break;
			case 3:
				if (money > 999) {
					LBSOfFood += 500;
					money -= 1000;
				}
				else {
					cout << "You Don't Have Enough Money\n";
					Shop();
				}
				break;
			case 4:
				if (money < 300) {
					cout << "You Don't Have Enough Money\n";
					Shop();
				}
				else {
					hasGun = true;
					money -= 300;
					restart();
				}
		}
		restart();
	}
}

void Hunt() {
	switch (strProf) {
		case 1:
			int hunt = (rand() % 5) + 1;
			if (hunt < huntchance) {
				cout << "You Have Got A Buffalo, + 20lbs of Food\n";
				LBSOfFood += 20;
				huntXP++;
				cout << "Your Hunting Experience is, ";
				cout << huntXP;
				cout << "\n";
				if (huntXP == 5){
					cout << "You Just Leveled Up Your Hunting Level\n";
					huntXP = 0;
					huntchance++;
				}
				restart();
			}
			else {
				cout << "You Failed To Catch Anything\n";
				restart();
			}
			break;
	}
	restart();
}

void StartOfGame() {
	cout << "Day:";
	cout << days;
	cout << "\n";
	cout << "What Would You Like To Do?\n";
	cout << "1 - Hunt\n";
	cout << "2 - Look For Town W/ Shop\n";
	cout << "3 - Explore\n";
	cin >> Answer1;
	switch (Answer1) {
		case 1:
			Hunt();
			break;
		case 2:
			Shop();
			break;
		case 3:
			explore();
			break;
	}
}

int main() {
	srand(time(NULL));
	cout << "Hello Welcome To The Wild West\n";
	cout << "Name:";
	getline(cin, name);
	cout << "What Difficulty\n";
	cout << "1 - Easy - 10 lbs/day\n";
	cout << "2 - Normal - 15 lbs/day\n";
	cout << "3 - Hard - 20 lbs/day\n";
	cout << "4 - Even Chuck Norris Fears Me - 25 lbs/day\n";
	cout << "5 - I Made This Difficulty So My Friend Doesn't Get To 300 Days Because If He Does Then I Will Have To Play Pony Town With Him - 40 lbs/day\n";
	cin >> difficulty;

	switch (difficulty) {
		case 1:
			diff = 10;
			diff2 = ((99 * 56) * 99);
			break;
		case 2:
			diff = 15;
			break;
		case 3:
			diff = 30;
			diff2 = 3;
			break;
		case 4:
			diff = 25;
			diff2 = 3;
			break;
		case 5:
			diff = 40;
			diff2 = 1;
			break;
	}
	cout << "What Profession Are You?\n\n";
	cout << "1 - Farmer $500  Enhanced Hunting Experience\n";
	cout << "2 - Lawyer $1000 Moderate Hunting Experience\n";
	cout << "3 - Banker $3000 Lacking  Hunting Experience\n";
	cin >> strProf;

	switch (strProf) {
		case 1:
			prof = "Farmer";
			money = 500;
			huntchance = 4;
			cout << "You Have, $";
			cout << money;
			cout << ", And Your Profession Is ";
			cout << prof;
			cout << "\n";
			cout << "Time To Start Your Journey, ";
			cout << name;
			break;
		case 2:
			prof = "Lawyer";
			money = 1000;
			huntchance = 3;
			cout << "You Have, $";
			cout << money;
			cout << ", And Your Profession Is ";
			cout << prof;
			cout << "\n";
			cout << "Time To Start Your Journey, ";
			cout << name;
			break;
		case 3:
			prof = "banker";
			money = 3000;
			huntchance = 2;
			cout << "You Have, $";
			cout << money;
			cout << ", And Your Profession Is ";
			cout << prof;
			cout << "\n";
			cout << "Time To Start Your Journey, ";
			cout << name;
			break;
	}
	cout << "\n";
	StartOfGame();
	return 0;
}