#include <unistd.h>
#include <stdlib.h> 
#include <iostream>
using namespace std;

int main(){
	
	int numofplay;
	bool mafia;
	int killed;
	int gameend = 0;
	bool doctor;
		string username;
	cout << "Это мафия. Пожалуста, напишите своё имя: ";
	cin >> username;
	cout << "\n";
	cout << "Сколько людей играют? ";
	cin >> numofplay;
	cout << "\n";
	usleep(1000000);
cout << "Начинаем...\n";
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
		cout << "Вы - мафия.\n";
	} else {
		mafia = false;
		cout << "Вы - не мафия.\n";
		if (z == 1){
			doctor = true;
			cout << "Вы- доктор.\n";
		} else {
			doctor = false;
			cout << "Вы - не доктор.\n";
		}
	}
	usleep(1000000);
while (gameend == 0){
	cout << "Город ложится спать.\n";
		usleep(1000000);
	if (mafia){
		cout << "Кого вы убьёте? Выберите от 1 до " << numofplay << "\n";
		cin >> killed;
	} else {
		killed = rand () % numofplay + 1;
	}
int y;
 if (doctorlive){
	if (doctor){
	  cout << "Кого вы спасёте? Выберите от 1 до " << numofplay << "\n";
	  cin >> y;
	} else {
 y = rand () % numofplay + 0;
 }
}
	cout << "Город просыпается.\n";
 if (killed > numofplay) {

 } else if (killed < 0){

 } else {
	if (y == killed) {
		cout << "Доктор спас человека. Никто не умер!\n";
	} else {
		numofplay--;
		cout << "Кого-то убили!\n";
	}
}
				for (int y; y <= numofplay; y++){
					int yrand = rand () % 2 + 0;
					if (yrand == 1 || yrand == 2){
						cout << "У игрока " << y << " есть алиби.\n";
					} else {
						cout << "У игрока " << y << " нет алиби.\n";
						sus++;
					}
				}
	cout << "Помните, только у " << sus << " игрока/ов нет алиби.\n";
	cout << "Голосуйте от 1 до " << numofplay << "\n";
		cin >> vote; 
			if (vote > numofplay){
				cout << "Вы не проголосовали.\n";
			} else if (vote < 0){
				cout << "Вы не проголосовали.\n";
			}
	numvote = rand () % numofplay + 0;
		mafianum = rand () % sus + 0;
		doctornum = rand () % numofplay + 0;
		if (numvote > numofplay / 2 && vote == mafianum){
			cout << "Мафию убили. Город выграл!!!\n";
			gameend++;
		} else if (numvote > numofplay / 2 && vote == doctornum) {
			doctorlive = false;
			cout << "Доктора убили.\n";
			numofplay--;
		}else if (numvote > numofplay / 2){
			cout << "Мафию не убили.\n";
			numofplay--;
			cout << "Кого-то убили.\n";
		} else {
			cout << "Никого не убили.\n";
		}
	usleep(1000000);
	if (numofplay < 2){
		cout << "Мафия выиграла! \n";
		gameend++;
	} 
	if (numofplay == 2){
		cout << "Мафия выиграла! \n";
		gameend++;
	}

 }
}
