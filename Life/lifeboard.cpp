//Matthew Coffey
//lifeboard.cpp
#include <iostream>
#include <unistd.h>
#include <cstdlib>
using namespace std;
#include "lifeboard.h"

Lifeboard::Lifeboard(){
	for(int row =0; row < SIZE; row++){
		for(int col =0; col < SIZE; col++){
			if (row == 0 || row == SIZE-1)
				board[row][col] = '_';
			else if (col == 0 || col == SIZE-1)
				board[row][col] = '|';
			else
				board[row][col] = ' ';
		}
	}
}

Lifeboard::~Lifeboard(){} // destrocol

void Lifeboard::addLife(int row, int col){
	if (row > 0 && row < SIZE-1 && col > 0 && col < SIZE-1){
		board[row][col] = 'X';
		display();
	}
	else
		cout << "Out of bounds." << endl;
}

void Lifeboard::removeLife(int row, int col){
	if ( row > 0 && row < SIZE-1 && col > 0 && col < SIZE-1){
		board[row][col] = ' ';
		display();
	}
	else
		cout << "Out of bounds." << endl;
}
char Lifeboard::getStatus(int row, int col){
	return board[row][col];
}

void Lifeboard::advance(Lifeboard& next){
    setLifeboard(next);
    int alive = 0;
    for(int a = 1; a < SIZE-1; a++)
    {
        for(int b = 1; b < SIZE-1; b++)
        {
            int alive = 0;
            for(int c = -1; c < 2; c++)
            {
                for(int d = -1; d < 2; d++)
                {
                    if(!(c == 0 && d == 0))
                    {
                        if(next.getStatus((a+c), (b+d)) == 'X')
				{
					++alive;
				}
                    }
                }
            }
            if(alive < 2)
            {
                board[a][b] = ' ';
            }
            else if(alive == 3)
            {
                board[a][b] = 'X';
            }
            else if(alive > 3)
            {
                board[a][b] = ' ';
            }
        }
    }
    display();
}




void Lifeboard::setLifeboard (Lifeboard& next){
	next.setStatus(4, 5, 'X');
	for(int row =0; row < SIZE; row++){
		for(int col =0; col < 42; col++){
			next.setStatus(row, col, getStatus(row, col));
			
		}
	}
}
void Lifeboard::setStatus (int row, int col, char status){
	board[row][col] = status;
}

void Lifeboard::play (Lifeboard& next){
	bool run = true;
	while (run){
		advance(next);
		usleep(100000);
		system("clear");
	}
}

void Lifeboard::display(){
	for(int row =0; row < SIZE; row++){
		for(int col =0; col < SIZE; col++){
			cout<<board[row][col];
		}
		cout<<endl;
	}
}

