#include <iostream>

using namespace std;
struct character
{
	string name;
	string char_class;
	int health;
	int experience;
	int stamina;
	int level; //-----------------------new
};

character player;

void level_up();
void exp_calculate(int * playerHealth, int quest);

	int main()
	{
		
	}
	
	void exp_calculate(int  * playerHealth, int quest)
	{
		
	}
	
	void level_up()
	{
		if(player.experience == 100)
		{
			player.level = 1;
		}
		else if(player.experience == 250)
		{
			player.level = 2;
		}
		else if(player.experience == 500)
		{
			player.level = 3;
		}
		else if(player.experience == 1000)
		{
			player.level = 4;
		}
		else if(player.experience == 1550)
		{
			player.level = 5;
		}
		else if(player.experience == 2500)
		{
			player.level = 6;
		}
		else if(player.experience == 3500)
		{
			player.level = 7;
		}
		else if(player.experience == 5000)
		{
			player.level = 8;
		}
		else if(player.experience == 7500)
		{
			player.level = 9;
		}
		else if(player.experience == 10750)
		{
			player.level = 10;
		}
	}