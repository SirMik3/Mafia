#include <unistd.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;
int score = 0;
string username;
bool first = true;

int main(){
	int numofplay;
	bool mafia;
	bool detective;
	bool detectivelive = true;
	bool mafiawin;
	int killed;
	bool gameend = false;
	bool doctor;
	bool jester;
	bool jesterlive = true;
		if (first){
	std::cout << "This is Mafia. Please chose your username: ";
	std::cin >> username;
		}
	cout << "\n";
	cout << "How many of you are playing? ";
	cin >> numofplay;
	cout << "\n";
	usleep(1000000);
cout << "Starting...\n";
int x = rand () % numofplay + 0;
int z = rand () % numofplay + 0;
int c = rand () % numofplay + 0;
int r = rand () % numofplay + 0;
int vote = 1;
int numvote = 0;
int mafianum = 1;
int doctornum = 1;
int detectivenum = 1;
bool doctorlive = true;
int jesternum = 1;
bool jesterwin;
int sus = 0;
	if (x == 1) {
		mafia = true;
		doctor = false;
		detective = false;
		cout << "Your Mafia\n";
	} else {
		mafia = false;
		cout << "Your not Mafia\n";
		if (z == 1){
			doctor = true;
			detective = false;
			cout << "Your doctor.\n";
		} else {
			doctor = false;
			cout << "Your not doctor.\n";
				if (c == 1){
					detective = true;
					cout << "Your detective.\n";
				} else {
					detective = false;
					cout << "your not detective.\n";
						if (r == 1){
							jester = true;
							cout << "your the jester.\n";
						} else {
							jester = false;
							cout << "your not the jester.\n";
						}
				}
		}
	}
	usleep(1000000);
while (gameend == false){
	sus = 0;
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
int l;
if (detectivelive){
	if (detective){
	  cout << "Who do you think is mafia? Choose from 1 to " << numofplay << "\n";
	  cin >> l;
} else {
	l = rand () % numofplay + 0;
  }
}

int jcount;
if (jesterlive){
	if (jester){
	  cout << "Tell us a sus player you will be with. Choose from 1 to " << numofplay << "\n";
	  cin >> jcount;
} else {
	jcount = rand () % numofplay + 0;
  }
}


int g = rand () % numofplay + 0;
int jesterdie = rand () % numofplay + 0;
int doctordie = rand () % numofplay + 0;
int detectivedie = rand () % numofplay + 0;
	cout << "City wakes up.\n";
 if (killed > numofplay) {

 } else if (killed < 0){

 } else {
	if (y == killed) {
		cout << "no one died!!!\n";
		//savenum++;
	} else {
		numofplay--;
		cout << "someone died!!!\n";
			if (jesterdie == 1){
				cout << "The jester died.\n";
				gameend = true;
				jesterlive = false;
				jesterwin = true;
				break;
			} else {
				if (doctordie == 1){
				cout << "The doctor died.\n";
				doctorlive = false;
				} else {
					if (detectivedie == 1){
						cout << "The detective died.\n";
						detectivelive = false;
					}
				}
			}
		//killnum++;
	}
}
	if (g == l){
		cout << "The detective found the mafia! The city wins!\n";
		gameend = true;
		break;
	} else {
		cout << "The detective killed an inoccent!\n";
		numofplay--;
	}

	if (numofplay < 2){
		cout << "Mafia wins! \n";
		gameend = true;
		mafiawin = true;
		break;
	} 
	if (numofplay == 2){
		cout << "Mafia wins! \n";
		gameend = true;
		mafiawin = true;
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
						jesternum = rand () % numofplay + 0;
	cout << username << ", remember only " << sus << " people are sus, so please don't vote a person with alibi." << "also, the numbers " << jcount << " and " << jesternum << "are really sus.\n";
	if (doctor){
		if (doctorlive){
			cout << "vote from 1 to " << numofplay << "\n";
		cin >> vote;
	 }
	} else if (detective){
		if (detectivelive){
	cout << "vote from 1 to " << numofplay << "\n";
		cin >> vote;
	 }
	} else {
 		cout << "vote from 1 to " << numofplay << "\n";
		cin >> vote;
	}
			if (vote > numofplay){
				cout << "Sorry, voting a number more than the number of people alive means you skip. \n";
			} else if (vote < 0){
				cout << "Sorry, voting a number less than zero means you skip. \n";
			}

			numvote = rand () % numofplay + 0;
		mafianum = rand () % sus + 0;
		doctornum = rand () % numofplay + 0;
		detectivenum = rand () % numofplay + 0;
	//	jesternum = rand () % numofplay + 0;

		if (numvote > numofplay / 2 && vote == mafianum){
			cout << "mafia was killed. The city wins!!!\n";
			mafiawin = false;
			gameend = true;
		} else if (numvote > numofplay / 2 && vote == doctornum) {
			doctorlive = false;
			cout << "The doctor died.\n";
			numofplay--;
		}else if (numvote > numofplay / 2){
			cout << "Mafia wasn't voted out. \n";
			numofplay--;
			cout << "someone died because you voted him/her out.\n";
		} else if (numvote > numofplay / 2 && vote == doctornum) {
			detectivelive = false;
			cout << "The detective died.\n";
			numofplay--;
		} else if (numvote > numofplay / 2 && vote == jesternum){
				cout << "The jester died.\n";
				cout << "The jester won! \n";
				gameend = true;
				jesterlive = false;
				jesterwin = true;
				break;
		} else {
				cout << "no one died!!! because no one was voted out!!!\n";
		}

	if (numofplay < 2){
		cout << "Mafia wins! \n";
		gameend = true;
		mafiawin = true;
		break;
	} 
	if (numofplay == 2){
		cout << "Mafia wins! \n";
		gameend = true;
		mafiawin = true;
		break;
	}
   }
   if (mafia){
   		if (mafiawin){
   			jesterwin = false;
   			score = score + rand () % 5 + 1;
   		} else {
   			score--;
   		}
   } else {
   	   	if (mafiawin){
   			score--;
   		} else {
   			score = score + rand () % 5 + 1;
   			jesterwin = false;
   		}
   	}
   	if (jester){
   		if (jesterwin){
   			score = score + rand () % 5 + 1;
   		}
   	}
   cout << "Your score is: " << score << "\n";
   string yn;
   cout << "Do you want to play again? Y/N\n";
   cin >> yn;
   if (yn == "Y" || yn == "y"){
   	first = false;
   		main();
  }
}
