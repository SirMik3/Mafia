#include <unistd.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;

int main(){

	int numofplay;
	bool mafia;
	int killed;
	bool gameend = false;
	bool doctor;
		string username;
	cout << "This is Mafia. Please chose your username: ";
	cin >> username;
	cout << "\n";
	cout << "How many of you are playing? ";
	cin >> numofplay;
	cout << "\n";
	usleep(1000000);
cout << "Starting...\n";
int x = rand () % numofplay + 0;
int z = rand () % numofplay + 0;
int vote = 1;
int numvote = 0;
int mafianum = 1;
int doctornum = 1;
bool doctorlive = true;
int sus = 0;
	if (x == 1) {
		mafia = true;
		cout << "Your Mafia\n";
	} else {
		mafia = false;
		cout << "Your not Mafia\n";
		if (z == 1){
			doctor = true;
			cout << "Your doctor.\n";
		} else {
			doctor = false;
			cout << "Your not doctor.\n";
		}
	}
	usleep(1000000);
while (gameend == false){
	cout << "City goes to bed.\n";
		usleep(1000000);
	if (mafia){
		cout << "Who do you chose to kill? Choose from 1 to " << numofplay << "\n";
		cin >> killed;
	} else {
		killed = rand () % numofplay + 1;
	}
int y;
 if (doctorlive){
	if (doctor){
	  cout << "Who do you chose to save? Choose from 1 to " << numofplay << "\n";
	  cin >> y;
	} else {
 y = rand () % numofplay + 0;
 }
}
	cout << "City wakes up.\n";
 if (killed > numofplay) {

 } else if (killed < 0){

 } else {
	if (y == killed) {
		cout << "no one died!!!\n";
	} else {
		numofplay--;
		cout << "someone died!!!\n";
	}
}
	
	if (numofplay < 2){
		cout << "Mafia wins! \n";
		gameend = true;
		break;
	} 
	if (numofplay == 2){
		cout << "Mafia wins! \n";
		gameend = true;
		break;
	}

				for (int y = 1; y <= numofplay; y++){
					int yrand = rand () % 2 + 0;
					if (yrand == 1 || yrand == 2){
						cout << "player " << y << " has an alibi.\n";
					} else {
						cout << "player " << y << " doesn't have an alibi.\n";
						sus++;
					}
				}
	cout << username << ", remember only " << sus << " people are sus, so please don't vote a person with alibi.\n";
	cout << "vote from 1 to " << numofplay << "\n";
		cin >> vote;
			if (vote > numofplay){
				cout << "Sorry, voting a number more than the number of people alive means you skip. \n";
			} else if (vote < 0){
				cout << "Sorry, voting a number less than zero means you skip. \n";
			}

			numvote = rand () % numofplay + 0;
		mafianum = rand () % sus + 0;
		doctornum = rand () % numofplay + 0;
		if (numvote > numofplay / 2 && vote == mafianum){
			cout << "mafia was killed. The city wins!!!\n";
			gameend = true;
		} else if (numvote > numofplay / 2 && vote == doctornum) {
			doctorlive = false;
			cout << "The doctor died.\n";
			numofplay--;
		}else if (numvote > numofplay / 2){
			cout << "Mafia wasn't voted out. \n";
			numofplay--;
			cout << "someone died because you voted him/her out.\n";
		} else {
			cout << "no one died!!! because no one was voted out!!!\n";
		}
	
	if (numofplay < 2){
		cout << "Mafia wins! \n";
		gameend = true;
		break;
	} 
	if (numofplay == 2){
		cout << "Mafia wins! \n";
		gameend = true;
		break;
	}
   }
 }
