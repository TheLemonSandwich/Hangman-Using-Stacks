#include <iostream>
using namespace std;

class Hangman
{
	public:
		void guess();
		bool Guesses();
		string display();
		char* answer;
		char* exp;
		bool win;
		Hangman(char answer[])
		{
			this->answer = answer;
			size = strlen(this->answer);
			temp = new char[size];
			guesses = 5;
			counter = 0;
			g_chars = new char[9];
			win = false;
			wincheck = 0;
		}

private:
	int guesses;
	char* g_chars;
	int size;
	int counter;
	char* temp;
	int wincheck;
};
string Hangman::display()
{
	string man = "";
	cout << "\nGuesses Left:\t" << guesses << endl;
	return man;
}
void Hangman::guess()
{
	exp = new char[size];
	int check = 0;
	wincheck = 0;
	if (Guesses())
	{
		char guess;
		cout << "Enter your guess ( a character ): ";
		cin >> guess;
		for (int i = 0; i < 9; i++)
			if (guess == g_chars[i])
			{
				cout << "You cannot repeat characters\n";
				check = 2;
				exp = temp;
				break;
			}
		g_chars[counter] = guess;
		if (check != 2)
		{
			for (int i = 0; i < strlen(answer); i++)
			{
				if (guess == answer[i])
				{
					exp[i] = guess;
					check = 1;
				}
				else
					exp[i] = '_';
			}
			if (counter > 0)
				for (int i = 0; i < strlen(answer); i++)
				{
					if (temp[i] != '_' && exp[i] == '_')
					{
						exp[i] = temp[i];
					}
					if (exp[i] != '_')
						wincheck++;
				}
			if (wincheck == strlen(answer))
				win = true;
			counter++;
			temp = exp;
			if (check != 1)
				guesses--;
			cout << endl;
		}
	}
	else
		cout << "No Guesses Left\n";
}
bool Hangman::Guesses()
{
	return guesses;
}

int main()
{
	char answer[40];
	cout << "Enter the name of a country\\city\\state (No Spaces) : ";
	cin >> answer;
	system("Cls");
	Hangman game(answer);

	do
	{
		if(!game.win)
		{
			cout << game.display() << endl << endl;
			game.guess();
			system("Cls");
			for (int i = 0; i < strlen(answer); i++)
				cout << game.exp[i];
			cout << endl << endl;
		}
		else
		{
			system("pause");
			system("cls");
			cout << "\nYOU WIN\n";
			break;
		}

	} while (game.Guesses());
	if (!game.Guesses())
	{
		cout << "You lost\n";
		cout << "\nThe actual word was " << game.answer << endl;
	}
	system("pause");
}