//lifeboard.h
//Matthew Coffey
const int SIZE = 42;
class Lifeboard{
	public:
		Lifeboard();
		~Lifeboard();
		void addLife(int, int);
		void removeLife(int, int);
		char getStatus(int, int);
		void setStatus(int, int, char);
		void advance(Lifeboard&);
		void play(Lifeboard&);
		void display();
		void setLifeboard(Lifeboard&);
	private:
		char board[SIZE][SIZE];
};
