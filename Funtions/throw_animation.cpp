#include <iostream>
#include <Windows.h>
#include <conio.h>

using namespace std;

#define reset_colour   "\033[0m"
#define red            "\033[31m"
#define green  	       "\033[32m"
#define yellow         "\033[33m"
#define blue           "\033[34m"
#define magenta        "\033[35m"
#define cyan           "\033[36m"
#define white          "\033[37m"
#define orange         "\033[38;5;208m"


void throw_animation(string &weapon, int &x, int &y, int &distance, int &time, string &colour);
void goto_coordinates(int &x_coords, int &y_coords);

	int main()
	{
		int x,y,distance,time;
		string colour;
		string weapon;
		int a = 0;
		do
		{
			cout << "\nEnter the X coords : ";
			cin >> x;
			cout << "\nEnter the Y coords : ";
			cin >> y;
			cout << "\nEnter the distance the throwable travel : ";
			cin >> distance;
			cout << "\nEnter the time in milisecond for speed : ";
			cin >> time;
			colour = yellow;
			cout << "\nEnter the weapon design :";
			cin >> weapon;
			system("cls");
			throw_animation(weapon,x,y,distance,time,colour);
			a = getch();
		}while(a == 1);
		return 0 ;
	}
	
	void goto_coordinates(int &x_coords, int &y_coords)
	{
		COORD coord;
		coord.X = x_coords ;
		coord.Y = y_coords ;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	}
	
	void throw_animation(string &weapon, int &x, int &y, int &distance, int &time, string &colour)
	{
		while(true)
		{
			goto_coordinates(x,y);
			cout << colour;
			cout << weapon;
			Sleep(time);
			
			goto_coordinates(x,y);
			cout << " ";
			
			cout << reset_colour;
			x++;
			
			if(x == distance)
			{
				break;
			}
		}
	}
	
	
