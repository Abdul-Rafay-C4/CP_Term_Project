#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <cctype>

using namespace std;

#define reset_colour "\033[0m"
#define red          "\033[31m"
#define green        "\033[32m"
#define yellow       "\033[33m"
#define orange       "\033[38;5;208m"

int hit_damage();
int critical_damage();
void health_display(int &health);
void clear_n();
int random(int first_value, int second_value);

	int main()
	{
		int health = 100;
		char user_click;
		do
		{
			system("cls");
			health_display(health);
			user_click = getch();
			if(isalpha(user_click))
			{
				if(user_click == 'd')
				{
					health = health - hit_damage();
				} 
			}
			else
			clear_n;
		}while(health > 0);
	}
	
	int hit_damage()
	{
		return critical_damage() + 7 ;
	}
	
	int critical_damage() 
	{
		int critical_damage = 0;
		
		if(rand() % 100 <= 1)
		{
			critical_damage = rand() % random(30,10) + 2;
		}
		return critical_damage;
	}
	
	void health_display(int &health)
	{
		if(health <= 100 && health > 70)
		{
			cout << green;
			if(health <= 100 && health > 90)
			{
				cout << "||||||||||";	
			}
			else if(health <= 90 && health > 80)
			{
				cout << "|||||||||";	
			}
			else if(health <= 80 && health > 70)
			{
				cout << "||||||||";	
			}
			cout << reset_colour;	
		}
		else if (health <=70 && health > 50)
		{
			cout << yellow;
			if(health <= 70 && health > 60)
			{
				cout << "|||||||";	
			}
			else if(health <= 60 && health > 50)
			{
				cout << "||||||";	
			}
			cout << reset_colour;
		}
		else if (health <= 50 && health > 30)
		{
			cout << orange;
			if(health <= 50 && health > 40)
			{
				cout << "|||||";	
			}
			else if(health <= 40 && health > 30)
			{
				cout << "||||";	
			}
			cout << reset_colour;
		}
		else if (health <= 30 && health > 0)
		{
			cout << red;
			if(health <= 30 && health > 20)
			{
				cout << "|||";	
			}
			else if(health <= 20 && health > 10)
			{
				cout << "||";	
			}
			else if(health <= 10 && health > 0)
			{
				cout << "|";
			}
			cout << reset_colour;
		}
		else
		{
			cout << "";
		}
	}
	void clear_n()
	{
		cin.clear();
		cin.ignore(numeric_limits<streamsize> :: max(), '\n');	
	}
	int random(int first_value , int second_value)
	{
		return rand() % first_value + second_value;
	}
