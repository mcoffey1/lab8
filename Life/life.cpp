// Matthew Coffey
// life.cpp


#include<iostream>
#include<fstream>
using namespace std;
#include "lifeboard.h"

int main (int argc, char* argv[]){
	Lifeboard lboard, next;
	char input = ' ';
	int col;
	int row;
	char y = ' ';
	while (input != 'q'){	
		cout << "a : enter coordinates where to add a new live cell." << endl;
		cout << "r : enter coordinates where a cell should be removed." << endl;
		cout << "n : advance the simulation to the next iteration by applying the rules of the game." << endl;
		cout << "q : quit the program." << endl;
		cout << "p : play the game continuously" << endl;
		if (argc == 1){
			cin >> input;
			switch(input){
				case 'a':
					cin >> col;
					cin >> row;
					lboard.addLife((row+1), (col+1));
					break;
				case 'r':
					cin >> col;
					cin >> row;
					lboard.removeLife ((row+1), (col+1));
					break;
				case 'n':
					lboard.advance(next);
					break;
				case 'q':
					break;
				case 'p':
					lboard.play(next);
					break;
				default:
					cout<< "Please enter valid input." << endl;
					break;
			}
		}
		else if(argc == 2){
			ifstream ifs;
			ifs.open(argv[1]);
			if (!ifs){
				cout << "Invalid File" << endl;
				return 1;
			}
			while (!ifs.eof()){
				ifs >> input;
				switch(input){
				case 'a':
					ifs >> row;
					ifs >> col;
					lboard.addLife((row+1), (col+1));
					break;
				case 'r':
					ifs >> row;
					ifs >> col;
					lboard.removeLife ((row+1), (col+1));
					break;
				case 'n':
					lboard.advance(next);
					break;
				case 'q':
					break;
				case 'p':
					lboard.play(next);
					break;
				default:
					cout<< "Please enter valid input." << endl;
					break;
				}
			}
		}
	}
	return 0;
}
