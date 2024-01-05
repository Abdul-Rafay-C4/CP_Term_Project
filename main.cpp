#include<iostream>
#include<windows.h>
#undef max
#include<limits>
#include<iomanip>
#include<string>
#include<conio.h>
#include<algorithm> //Transform
#include <mmsystem.h>//sound

#pragma comment(lib, "Winmm.lib")

using namespace std;
//----------------------GLOBLE_DATA----------------------------

//ABDUL RAFAY (19-12-23 (16:50))
#define reset_colour   "\033[0m"
#define red            "\033[31m"
#define green  	       "\033[32m"
#define yellow         "\033[33m"
#define blue           "\033[34m"
#define magenta        "\033[35m"
#define cyan           "\033[36m"
#define white          "\033[37m"
#define orange         "\033[38;5;208m"
#define lightgreen     "\033[32;1m"
#define lightred       "\033[91m"

struct character
{
	string name;
	string _class;
	int health;
	int experience_points;
	int stamina;
	int level;
	int critical_hit_chance;
	int damage;
	string special_weapon;	
};

struct inventory
{
	string special_weapon_name;
	int health_potion;
	int stamina_potion;
};

inventory invt;
character player;
character peter;
character unknown;

string gamestory[50];

bool win_lose;


//-------------------------------------------------------------

//---------------------------------------------------------
//Declare Funtions here (prevent to difine them here)
//for example :- int sum(int &a , int &b) // Abdul Rafay
//---------------------------------------------------------

//--------------------ABDUL_RAFAY--------------------------
//16-12-23 (18:05)
int hit_damage(int damage, int& stamina, int chance, int max_critical_damage);
int critical_damage(int& chance, int& max_damage);
//19-12-23
void weapondamage(int&);
void display_health(int& health, int og_health);
void clear_n();
int random(int first_value, int second_value);
//21-12-23(16:00)
void throw_animation(string weapon, int x, int y, int distance, int time, bool check);
void goto_coordinates(int x_coords, int y_coords);

//25-12-23(02:25)
void display_stamina(int& stamina, int og_stamina);
int stamina_calculate(int& damage, int& stamina);
void stamina_recover(int& stamina);


int percentage(int& value, int& og_value);
//(02:40)
void convert_to_uppercase(string& lowercase);
void text_animation(string& sentence, string& colour, bool uppercase, int time = 30);

//
void battle_system(bool difficulty, int enemy_health, int enemy_stamina, int enemy_damage, int max_critical_damage_enemy, string enemy_name, string enemy_weapon, bool &win_lose, int max_critical_damage_player, string player_weapon, int legendary_weapon_damage);


//-------------------MUHAMMAD_HAMZA------------------------
//16-12-23 (15:41)
void getplayerinfo(character& player);
void displayplayerinfo(character& player);
void Quest(character& player);
//3-01-2024(13:17)
void level_up();
void exp_calculate(int * playerHealth, int quest);



//-------------------MUHAMMAD_JIBRAN-----------------------
//16-12-23 (16:11)
void blankscreen();
void gamelogoscreen();
void menu();
//19-12-23 (23:55)
void frameratelogo(int frame);
int menudecider(int choice);
//20-12-23 (21:41)
void gamestart();
void showoptions();
void gameexit();
//25-12-23 (18:43)
void dailougeAndStory();
void input_clear();
//26-12-23 (19:02)
void getplayername(character& player);
void getplayerclass(character& player);
//28-12-23 (09:45)
void fight();
//3-1-24 (07:25)
int options(int num,string optscene, string opt1, string opt2, string opt3);


int main()
{
	system("mode 120"); 
	invt.health_potion = 2; 	
	invt.stamina_potion = 2; 	
	player.name = "ABC"; 	
	player.health = 500; 	
	player.damage = 15; 	
	player.stamina = 100; 	
	player.critical_hit_chance = 30; 	 	
	string player_weapon, enemy_weapon; 	
	player_weapon = " @"; 	enemy_weapon = "- "; 	 	
	battle_system(false,500,80,100,40,"Golaith ",enemy_weapon,win_lose,50,player_weapon,100);
	return 0;
}


//------------------------------------------------------------
// define Functions here
/*for example :- int sum(int &a , int &b)
				{
					int sum;
					sum = a + b; //Abdul Rafay (13-12-23 22:11)
					return sum;
				}*/
				//------------------------------------------------------------


				//--------------------ABDUL_RAFAY--------------------------
			//16-12-23 (18:05)
			//Edit : 25-12-23 (02:15)
int hit_damage(int damage, int& stamina, int chance, int max_critical_damage)
{
	if (stamina > 100)
	{
		damage = ((critical_damage(chance, max_critical_damage) * 150) / 100) + damage;
	}
	else if (stamina <= 100 && stamina >= 30)
	{
		damage = critical_damage(chance, max_critical_damage) + damage;
	}
	else if (stamina <= 30 && stamina > 0)
	{
		damage = ((critical_damage(chance, max_critical_damage) * 30) / 100) + damage;
	}
	else if (stamina <= 0)
	{
		damage = damage - ((damage * 30) / 100);
	}

	return damage;
}

int critical_damage(int& chance, int& max_damage)
{
	int critical_damage = 0;

	if (rand() % 100 <= chance)
	{
		critical_damage = rand() % random(max_damage, 10) + 2;
	}
	return critical_damage;
}
// 19-12-23 (16:50)
// Edit : 25-12-23 (02:15)
void display_health(int& health, int og_health)
{
	int value;
	value = percentage(health, og_health);
	if (value <= 100 && value > 70)
	{
		cout << green;
		if (value <= 100 && value > 90)
		{
			cout << "||||||||||";
		}
		else if (value <= 90 && value > 80)
		{
			cout << "|||||||||";
		}
		else if (value <= 80 && value > 70)
		{
			cout << "||||||||";
		}
		cout << reset_colour;
	}
	else if (value <= 70 && value > 50)
	{
		cout << yellow;
		if (value <= 70 && value > 60)
		{
			cout << "|||||||";
		}
		else if (value <= 60 && value > 50)
		{
			cout << "||||||";
		}
		cout << reset_colour;
	}
	else if (value <= 50 && value > 30)
	{
		cout << orange;
		if (value <= 50 && value > 40)
		{
			cout << "|||||";
		}
		else if (value <= 40 && value > 30)
		{
			cout << "||||";
		}
		cout << reset_colour;
	}
	else if (value <= 30 && value > 0)
	{
		cout << red;
		if (value <= 30 && value > 20)
		{
			cout << "|||";
		}
		else if (value <= 20 && value > 10)
		{
			cout << "||";
		}
		else if (value <= 10 && value > 0)
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
	cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
int random(int first_value, int second_value)
{
	return rand() % first_value + second_value;
}

//21-12-23(16:00)
void goto_coordinates(int x_coords, int y_coords)
{
	COORD coord;
	coord.X = x_coords;
	coord.Y = y_coords;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void throw_animation(string weapon, int x, int y, int distance, int time, bool check)
{
	while (true)
	{
		goto_coordinates(x, y);
		cout << yellow;
		cout << weapon;
		Sleep(time);

		goto_coordinates(x, y);
		cout << " ";

		cout << reset_colour;
		if(check)
		{
			x++;
		}
		else
		{
			x--;
		}

		if (x == distance)
		{
			break;
		}
	}
}

//25-12-23(02:25)
int stamina_calculate(int& damage, int& stamina)
{
	if (stamina > 0)
	{
		return (damage * 30) / 100;
	}
	return 0;
}

void stamina_recover(int& stamina)
{
	if (stamina < 100 && stamina > 60)
	{
		if (rand() % 100 <= 30)
		{
			stamina += rand() % random(20, 10) + 2;
			if (stamina > 100)
			{
				stamina = 100;
			}
		}
	}
	else if (stamina <= 60 && stamina > 30)
	{
		if (rand() % 100 <= 60)
		{
			stamina += rand() % random(30, 10) + 2;
		}
	}
	else if (stamina <= 30 && stamina >= 0)
	{
		stamina += rand() % random(50, 10) + 2;
	}
}
void display_stamina(int& stamina, int og_stamina)
{
	int value;
	value = percentage(stamina, og_stamina);

	if (value <= 100 && value > 70)
	{
		cout << white;
		if (value <= 100 && value > 90)
		{
			cout << "__________";
		}
		else if (value <= 90 && value > 80)
		{
			cout << "_________";
		}
		else if (value <= 80 && value > 70)
		{
			cout << "________";
		}
		cout << reset_colour;
	}
	else if (value <= 70 && value > 50)
	{
		cout << cyan;
		if (value <= 70 && value > 60)
		{
			cout << "_______";
		}
		else if (value <= 60 && value > 50)
		{
			cout << "______";
		}
		cout << reset_colour;
	}
	else if (value <= 50 && value > 30)
	{
		cout << blue;
		if (value <= 50 && value > 40)
		{
			cout << "_____";
		}
		else if (value <= 40 && value > 30)
		{
			cout << "____";
		}
		cout << reset_colour;
	}
	else if (value <= 30 && value > 0)
	{
		cout << magenta;
		if (value <= 30 && value > 20)
		{
			cout << "___";
		}
		else if (value <= 20 && value > 10)
		{
			cout << "__";
		}
		else if (value <= 10 && value > 0)
		{
			cout << "_";
		}
		cout << reset_colour;
	}
	else
	{
		cout << "";
	}
}

int percentage(int& value, int& og_value)
{
	return (value * 100) / og_value;
}


//(02:40)
void convert_to_uppercase(string& lowercase)
{
	transform(lowercase.begin(), lowercase.end(), lowercase.begin(), ::toupper);
}

void text_animation(string& sentence, string& colour, bool uppercase, int time)
{
	if (uppercase == true)
	{
		convert_to_uppercase(sentence);
	}
	cout << colour;
	int a = sentence.size();
	for (int i = 0; i < a; ++i)
	{
		
		
		cout << sentence[i];
		
		Sleep(time);
	}
	cout << reset_colour;
}

void battle_system(bool difficulty, int enemy_health, int enemy_stamina, int enemy_damage, int max_critical_damage_enemy, string enemy_name, string enemy_weapon, bool &win_lose, int max_critical_damage_player, string player_weapon, int legendary_weapon_damage)
{
	int temp_health = player.health;
	int temp_health_enemy = enemy_health;
	int temp_stamina = player.stamina;
	int temp_stamina_enemy = enemy_stamina;
	int temp_health_potion = invt.health_potion;
	int temp_stamina_potion = invt.stamina_potion;
	
	bool turn = true;
	
	char user_enter;
	do
	{
		system("cls");
		goto_coordinates(1,2);
		cout << white << player.name << reset_colour;
		goto_coordinates(110,2);
		cout << red << enemy_name << reset_colour; 
		goto_coordinates(1,3);
		display_health(player.health , temp_health);
		goto_coordinates(110,3);
		display_health(enemy_health , temp_health_enemy);
		goto_coordinates(1,4);
		display_stamina(player.stamina , temp_stamina);	
		goto_coordinates(110,4);
		display_stamina(enemy_stamina, temp_stamina_enemy);
		
		if(turn)
		{
			goto_coordinates(1,6);
			cout << "     Inventory";
		}
		
		if(turn)
		{
			goto_coordinates(55,6);
			cout << cyan << "YOUR  TURN" << reset_colour;
		}
		else if(turn == false)
		{
			goto_coordinates(55,6);
			cout << orange << "ENEMY TURN" << reset_colour;
		}
		
		
		if(turn)
		{
			goto_coordinates(1,9);
			cout << ">  Special Weapon (r)";
			if(legendary_weapon_damage > 0)
			{
				goto_coordinates(40,9);
				cout << ">\tLegendary Weapon  \t (1)"; 
			}
			goto_coordinates(1,11);
			cout << ">  Health Potion  (h)";
			goto_coordinates(40,11);
			cout <<	">\tUse Inventory     \t (2)";
			
			goto_coordinates(1,13);
			cout << ">  Stamina Potion (s)";
			goto_coordinates(40,13);
			cout << ">\tAttack            \t (a)";
			
			goto_coordinates(40,15);
			cout << ">\tSkip (Gain Stamina)\t (t)";
		}
		
		goto_coordinates(26,25);
		cout << player.name ;
		goto_coordinates(90,25);
		cout << orange << enemy_name << reset_colour;
		
		if(turn)
		{
			user_enter = _getch();
			
			if(user_enter == '1')
			{
				if(player.stamina >= 80 && legendary_weapon_damage > 0)
				{
					int dam;
					throw_animation(player_weapon, 30, 25, 90, 10, true);
					dam = hit_damage(legendary_weapon_damage, player.stamina, player.critical_hit_chance, max_critical_damage_player);
					enemy_health -= dam;
					player.stamina -= stamina_calculate(dam ,player.stamina);
					turn = false;
				}
			}
			else if(user_enter == '2')
			{
				char use;
				use = _getch();
				if(use == 'r')
				{
					if(player.stamina > 90)
					{
						int dam;
						throw_animation(player_weapon, 30, 25, 90, 10, true);
						dam = hit_damage(player.damage + 100, player.stamina, player.critical_hit_chance, max_critical_damage_player);
						enemy_health -= dam;
						player.stamina -= stamina_calculate(dam ,player.stamina);
						turn = false;
					}
				}
				else if(use == 'h')
				{
					if(invt.health_potion > 0)
					{
						player.health += 100;
						invt.health_potion--;
						turn = false;
					}
				}
				else if(use == 's')
				{
					if(invt.stamina_potion > 0 && player.stamina < 100)
					{
						player.stamina = 100;
						invt.stamina_potion--;
						turn = false;
					}
				}
			}
			else if(user_enter == 'a')
			{
				int dam;
				throw_animation(player_weapon, 30, 25, 90, 10, true);
				dam = hit_damage(player.damage, player.stamina, player.critical_hit_chance, max_critical_damage_player);
				enemy_health -= dam;
				player.stamina -= stamina_calculate(dam ,player.stamina);
				turn = false;
			}
			else if(user_enter == 't')
			{
				stamina_recover(player.stamina);
				turn = false;
			}
		}
		else if(turn == false)
		{
			int dam;
			Sleep(1000);
			throw_animation(enemy_weapon, 86, 25, 27, 10, false);
			dam = hit_damage(enemy_damage, enemy_stamina, difficulty == true ? 20 : 10, max_critical_damage_enemy);
			player.health -= dam;
			enemy_stamina -= difficulty == true ? (stamina_calculate(dam, enemy_stamina) * 0.7) : stamina_calculate(dam, enemy_stamina);
			turn = true;
		}
		if(player.health <= 0)
		{
			char che;
			system("cls");
			cout << "\n You Lose. Do you want to retry? (y for yes/press any key to return to the menu)";
			che = _getch();
			if(che == 'y')
			{
				player.health = temp_health;
				player.stamina = temp_stamina;
				invt.health_potion = temp_health_potion;
				invt.stamina_potion = temp_stamina_potion;
				enemy_health = temp_health_enemy;
				enemy_stamina = temp_stamina_enemy;
			}
		}
		
		
	}while(player.health > 0 && enemy_health > 0);
	
	if(player.health > 0)
	{
		win_lose = true;
	}
	else if(enemy_health > 0)
	{
		win_lose = false;
	}
}

//-------------------MUHAMMAD_HAMZA------------------------

void getplayerinfo(character& player) //17-12-23(15:34)
{

	cout << "Enter your Player Name : ";
	getline(cin, player.name);


	int choice;
	cout << "Choose your Character Class!";
	bool check = true;
	do {

		cout << "\n 1: Warrior \n 2: Mage \n 3:Rogue \nYour Choice :";
		cin >> choice;
		switch (choice) {
		case 1:
			player._class = "Warrior";
			player.health = 120;
			break;
		case 2:
			player._class = "Mage";
			player.health = 80;
			break;
		case 3:
			player._class = "Rogue";
			player.health = 100;
			break;
		default:
			cout << "Please select Given options";
			check = false;
			break;
		}
	} while (!check);


	player.experience_points = 0;


}
//Start mein health full hogi so ill initiaizel 100 hp in main//

//Experience points 0 hongay bcz its start of game so ill initialize 0 in main//

void displayplayerinfo(character& player)//17-12-23(15:34)
{
	cout << "PLAYER INFORMATION" << endl;
	cout << "NAME :" << player.name << endl;
	cout << "PLAYER CLASS :" << player._class << endl;
	cout << "HEALTH :" << player.health << endl;
	cout << "EXPERIENCE POINTS :" << player.experience_points << endl;
}
void Quest(character& player)//17-12-23(15:34)
{

	cout << "You reaches on a new quest!" << endl;
	displayplayerinfo(player);
}
//3-01-2024(13:17)
  void exp_calculate(int  * playerHealth, int quest)
    {
        
    }
 //3-01-2024(13:17)
    void level_up()
    {
        if(player.experience_points == 100)
        {
            player.level = 1;
        }
        else if(player.experience_points == 250)
        {
            player.level = 2;
        }
        else if(player.experience_points == 500)
        {
            player.level = 3;
        }
        else if(player.experience_points == 1000)
        {
            player.level = 4;
        }
        else if(player.experience_points == 1550)
        {
            player.level = 5;
        }
        else if(player.experience_points == 2500)
        {
            player.level = 6;
        }
        else if(player.experience_points == 3500)
        {
            player.level = 7;
        }
        else if(player.experience_points == 5000)
        {
            player.level = 8;
        }
        else if(player.experience_points == 7500)
        {
            player.level = 9;
        }
        else if(player.experience_points == 10750)
        {
            player.level = 10;
        }
    }


//-------------------MUHAMMAD_JIBRAN-----------------------
//16-12-23 (16:11)
//20-12-23 (21:41)

void dailougeAndStory()
{
	//HERO'S HOUSE
	gamestory[0] = "    You lived in a old hut located in the outskirts of the Delsagade\n\n    ( A very ancient village located in the borders of China and Russia. (\n     ) Only a few people know about this village.                         )\n\n    You were asleep in your Bedroom. You wake up to drink some water.\n    Today was your birthday as you turned 15 years old\n";
	gamestory[1] = "    As you go down you hear some sounds...\n\n    MOM: Are u awake son ?\n    YOU: Yes, Mom.\n    MOM: Today you will goto the village to give trails as promised.\n    YOU: No, Mom today's my birthday.\n    MOM: Its a family tradition. You have to go ! I want to see you as one of those fighters.\n    YOU: Hmm Okay Mom :(";
	//VILLAGE
	gamestory[2] = "    STRANGER: Are you here for the trails ?\n    YOU: Yes.\n    STRANGER: What is your name ?\n";
	gamestory[3] = "    YOU: Hmm, My name is " + player.name + " \n    STRANGER: Oh, Hello my name is Peter.";
	gamestory[4] = "    YOU: Hello, Peter. Oh ! The trails are starting.\n    PETER: Yeah, Lets Go.";
	//TRAILS
	gamestory[5] = "    You saw that there were lines of children standing. They were choosing their class.\n    You didn't knew what classes were so, you asks it from Peter...\n\n    PETER: What ! You don't know about it ? Then why are you here ?\n    YOU: I just came because my parents wanted to but I never took interest in it.\n    PETER: That's strange. But I can help you with the classes...";
	gamestory[6] = "    So, basically there a three classes that describes the fighter's fighting style,\n    their strength (damage), health, stamina, weapons and their ability to hit precise ( critical hit )\n    because they will be trained like that.";
	gamestory[7] = "    The Three Classes are ;\n\n    > Mage ( Preferred One ) : Magic Abilities\n\n           Health : 80\n           Stamina : 100\n           Damage : Med\n           Crit. Hit : 25 %\n\n    > Warrior ( Strongest ) : Damage Abilities\n\n           Health : 120\n           Stamina : 80\n           Damage : High\n           Crit. Hit : 10 %\n\n    > Rouge ( Stealth ) : Surprise Class\n\n           Health : 100\n           Stamina : 120\n           Damage : Med\n           Crit. Hit : 5 %\n\n    Choose One...";
	//My turn
	gamestory[8] = "    MAN: Tell me your class.\n    YOU: I choose " + player._class + ".\n    MAN: Now wait there.\n\n    After sometime...\n\n    MAN: Get ready for your trail fight.\n\n    I was ready for the fight. If you wondering how I know to fight, that's a good question.\n    It was just in the script.";
	//trails round 1
	gamestory[9] = "    But, You won't believe my fight opponent. It was Peter. I was thinking how I will fight him.";
	//fight scene    11xp
	gamestory[10] = "    I won against Peter but I wasn't not so happy. A Man came to me and told me that I will continue my training in their academy in Tibet";
	//after training
	gamestory[11] = "    On my last day, I got an invitaion to meet the Master Sifu. When I entered his big wooden room, he told me to sit down...\n\n    SIFU: Do you know why I call you here ?\n    YOU: No, I don't. I guess it is related to my last day ?\n    SIFU: I know you are new to the darkness of the mystical world, but you were choose to be like this. \n    YOU: What ?\n    SIFU: Long time ago, this village was once called Santoki No Machi that means city of fighters.\n    There were all kind of fighters living and protecting this village from mystical attacks, that comes from another dimension.\n    As the time passes, the mystical creatures got powerful and eventually started killing the people and fighters there.\n    Then a mage named \"Delsagade\" stood from the outskirts of the city and stopped the mystical creatures from coming to this world\n    and that you can guess how the new name of the village came up.\n    YOU: Why are you telling me this and how does that make me a chosen one.\n    SIFU: Delsagade before his death, gave a prediction that when the mystical creatures become strong enough to break out of the portal, then a " + player._class + " with my birth mark will arise to stop them once and for all....\n";
	//climax         6 months ago
	gamestory[12] = "    Now, I am in the jungles of Mongolian Mountains, looking for the signs to find anything strange that could lead me to the portal of darkness.\n\n    ;|\n\n    ........................... \n\n    I hear some strange sounds coming from the bushes. \n\n    ........................... \n\n    Suddenly, a strange mystical creature appear out of no-where and ... \n\n    Attacked me !?";
	//fightscene   unknown 
	gamestory[13] = "    I think I defeated him or He just disappeared into thin air. But, I knew the dark portal was near...";
	//choiceoption1  > follow the smoke  > explore the mountain 
	// follow the smoke
	//side quest
	gamestory[14] = "    After following the smoke for several hours, I reached at the entrance of a village which was in shambles. 	 \n    At the entrance of the village, I saw a strange creature standing near a man who was covered in wounds from head to toe. \n\n    YOU: Are u alright ?\n\n    The man fell to his knees coughing up blood. So, I ran to his aid but, the creature didn't like me I guess....\n";
	//fightscence  unknown
	gamestory[15] = "    YOU: What happened here ?\n    MAN: It was a massacre. The enderspirits attacked us. There was a gaint man. He was in search of the reincarnate of the Warrior \"Delsagade\".\n    MAN: He had an unimaginable amount of power which was seen in the dark times when mystical creatures ruled the world. He had a lust for blood and hunger for noodles.\n    MAN: So, he was looking for only two things; one was the reincarnate being and other were special edition noodles. We were just the biproduct.\n    YOU: Do you know anything else about this man ?\n    MAN: He called himself \"Waleed the Golaith\". \n\n    Those were the last word man uttered....";
	//this follow -----(><)
	//explore the mountain
	gamestory[16] = "    After sensing the presence of the dark portal, I carried to move on deeper in the forest. \n    After exploring for a few hours, I saw a pack of Hogriders which were being controlled by people which seemed to be activists of a dark community.\n    I was watching them from a distance, as they were brutally attacking a band of hikers. I tried to stay out of this but could not bottle up my emotions.\n    So, I went and confronted the leader of the pack head on.";
	gamestory[17] = "    YOU: Stop right there. I challenge you to a one on one battle. If I am victorious you will leave the hikers alone.\n    PACK LEADER: Well well well, what do we have here is a tiny creature challenging me for a battle. That shelby be fun.";
	//fight scene
	gamestory[18] = "    After brutally humiliating the pack leader.\n\n    YOU: As per our condition, you will let these innocent hikers go. \n YOU: What were you doing here.\n    PACK LEADER: I was given a task of finding everything I could about the reincarnation of a Famous Warrior Delsagade. I am sure you have heard about him, don't ya.\n    YOU: Yes ? I have heard about him. PACK LEADER: What were you doing here ?\n    YOU: I am also a hiker. Who r u? \n    PACK LEADER: I am a member of gang called dark triad. I work under a person called \"Waleed the Golaith\". He has an unimaginable amount of power which was seen in the dark times when mystical creatures ruled the world.\n    PACK LEADER: He has a lust for blood and hunger for noodles. So, he is looking for only two things; one is the reincarnate being and other are special edition noodles.\n\n    After that we went our ways, and I found a demolished village after exploring for several hours";
	//merge
	gamestory[19] = "    I could not asked him about the dark portal. At the end of the village, I saw a flying pigeon coming towards me. It seems I know this pigeon very well.\n    When it got near, I realized it was my pigeon but with a red ribbon ( red ribbon is used only when there is danger )....\n    When I opened the letter attached to it it says: \n\n      )   Hello, Charlie. ( Charlie was my nickname ) I ho5pe you are alright.   (\n   	(    I just wanted to tell you that     DON'T C0ME TO THE VILLAGE...         )\n      )   The Dels4gade has been attacked by some mystical powers, but, don't    ( \n     (    worry we are save as we run away and find a she1ter in a cave nearby    )\n      )   Love you Charlie ,                                                     (\n     (                                                                            )\n	     )                                                        Your Mom  ----    (\n\n    Hint: Within the cryptic folds of a heartfelt missive, unveil the enigmatic 4 cipher";
	 //choice opt 2 > go to village or stay 
	 //go to village
	 gamestory[20] = "    I have reached the village. It is completely destoryed so my heart ( My Homeplace :'[ ). I was filled with anger to get revenge.\n    Now I have a strong purpose than just being somebody's prediction. And well look what I found here is a bunch of enderspirits to start with...";
	 //fight scene enderspirits '.:'. 
	 gamestory[21] = "    ";
	 //stay..
	 gamestory[22] = "    I have looking everywhere on this mountain for some signs for dark portal but could not find one. It was mid-night. I was tired and was thinking that it could be a wrong decision to not go to the village. So, I decided to check the village once.";
	

}

void blankscreen()
{
	cout << orange;
	cout << "         ___      ___           __   ___  ___        ___       ___  ___       ___  ___" << endl;
	cout << "          |  |__| |__      |   |  |  |__   |        |    |__| |___| |__| |     |   |__" << endl;
	cout << "          |  |  | |__      |__ \\__/  __/   |        |___ |  | |   | | \\  |__  _|_  |__" << endl;
	cout << "___________________________________________________________________________________________________" << endl;
	cout << "|_________________________________________________________________________________________________| " << endl;
	cout << reset_colour;
}

void gamelogoscreen()
{
	system("cls");
	for (int frame = 0; frame <= 14; frame++)
	{
		blankscreen();
		cout << "\n\n\n\n";
		frameratelogo(frame);
		Sleep(260);
		system("cls");
	}

	return;
}

void menu()
{
	system("cls");
	char choice;
	bool check = false;
	cout << orange;
	cout << "         ___      ___           __   ___  ___        ___       ___  ___       ___  ___" << endl;
	cout << "          |  |__| |__      |   |  |  |__   |        |    |__| |___| |__| |     |   |__" << endl;
	cout << "          |  |  | |__      |__ \\__/  __/   |        |___ |  | |   | | \\  |__  _|_  |__" << endl;
	cout << " ________________________________________________________________________________________________" << endl;
	cout << "/  ____________________________________________________________________________________________  \\" << endl;
	cout << "| |                                                                                            | |" << endl;
	cout << "| |                                           ____                                             | |" << endl;
	cout << "| |                                 |\\    /| |      |\\  | |    |                               | |" << endl;
	cout << "| |                                 | \\  / | |----  | \\ | |    |                               | |" << endl;
	cout << "| |                                 |  \\/  | |____  |  \\|  \\__/                                | |" << endl;
	cout << "| |                                                                                            | |" << endl;
	cout << "| |____________________________________________________________________________________________| |" << endl;
	cout << "\\ \\--------------------------------------------------------------------------------------------/ /" << endl;
	cout << "                                                                                            " << endl;
	cout << "                                                                                            " << endl;
	cout << "    >   Play               ( 1 )" << endl;
	cout << "                                                                                            " << endl;
	cout << "    >   Options            ( 2 )" << endl;
	cout << "                                                                                            " << endl;
	cout << "    >   Exit               ( 3 )" << endl << endl;

	while (check == false)
	{
		choice = _getch();
		if (isdigit(choice))
		{
			Sleep(250);
			check = menudecider(choice);
		}
		else
		{
			input_clear();
		}
	}
	return;
}

//
//cout << "| |                                                                                            | |" << endl;
//cout << "| |        )                                                                          (        | |" << endl;
//cout << "| |       (               WELCOME                                                      )       | |" << endl;
//cout << "| |        )                           TO                                             (        | |" << endl;
//cout << "| |       (                                    THE  LOST  CHARLIE                      )       | |" << endl;
//cout << "| |        )                                                                          (        | |" << endl;
//cout << "| |____________________________________________________________________________________________| |" << endl;
//cout << "| |--------------------------------------------------------------------------------------------| |" << endl;


void frameratelogo(int frame)
{
	cout << cyan;
	if (frame == 0)
	{
		cout << "                                   ||" << endl;
	}
	else if (frame == 1)
	{
		cout << "                                   ||" << endl;
		cout << "                                   ||" << endl;
	}
	else if (frame == 2)
	{
		cout << "                                   ||" << endl;
		cout << "                                   ||" << endl;
		cout << "                                   ||" << endl;
	}
	else if (frame == 3)
	{
		cout << "                                   ||" << endl;
		cout << "                                   ||" << endl;
		cout << "                                   ||" << endl;
		cout << "                                   \\\\";
	}
	else if (frame == 4)
	{
		cout << "                                   ||" << endl;
		cout << "                                   ||" << endl;
		cout << "                                   ||" << endl;
		cout << "                                   \\\\____" << endl;
	}
	else if (frame == 5)
	{
		cout << "                                   ||           " << reset_colour << orange << "      ______" << endl << reset_colour << cyan;
		cout << "                                   ||           " << reset_colour << orange << "       -------       " << endl << reset_colour << cyan;
		cout << "                                   ||                         " << endl;
		cout << "                                   \\\\____            " << endl;
	}
	else if (frame == 6)
	{
		cout << "                                   ||          " << reset_colour << orange << "     ________" << endl << reset_colour << cyan;
		cout << "                                   ||          " << reset_colour << orange << "    / /--------       " << endl << reset_colour << cyan;
		cout << "                                   ||                      " << endl;
		cout << "                                   \\\\____         " << endl;
	}
	else if (frame == 7)
	{
		cout << "                                   ||          " << reset_colour << orange << "     ________" << endl << reset_colour << cyan;
		cout << "                                   ||          " << reset_colour << orange << "    / /--------       " << endl << reset_colour << cyan;
		cout << "                                   ||          " << reset_colour << orange << "   | |         " << endl << reset_colour << cyan;
		cout << "                                   \\\\____         " << endl;
	}
	else if (frame == 8)
	{
		cout << "                                   ||          " << reset_colour << orange << "     ________" << endl << reset_colour << cyan;
		cout << "                                   ||          " << reset_colour << orange << "    / /--------       " << endl << reset_colour << cyan;
		cout << "                                   ||          " << reset_colour << orange << "   | |         " << endl << reset_colour << cyan;
		cout << "                                   \\\\____    " << reset_colour << orange << "     | |" << endl << reset_colour << cyan;
		cout << "                                               " << reset_colour << orange << "   \\ \\" << endl << reset_colour << cyan;
	}
	else if (frame == 9)
	{
		cout << "                                   ||          " << reset_colour << orange << "     ________" << endl << reset_colour << cyan;
		cout << "                                   ||          " << reset_colour << orange << "    / /--------       " << endl << reset_colour << cyan;
		cout << "                                   ||          " << reset_colour << orange << "   | |         " << endl << reset_colour << cyan;
		cout << "                                   \\\\____    " << reset_colour << orange << "     | |" << endl << reset_colour << cyan;
		cout << "                                               " << reset_colour << orange << "   \\ \\____" << endl << reset_colour << cyan;
	}
	else if (frame == 10)
	{
		cout << "                                   ||          " << reset_colour << orange << "     ________" << endl << reset_colour << cyan;
		cout << "                                   ||          " << reset_colour << orange << "    / /--------       " << endl << reset_colour << cyan;
		cout << "                                   ||          " << reset_colour << orange << "   | |         " << endl << reset_colour << cyan;
		cout << "                                   \\\\____    " << reset_colour << orange << "     | |" << endl << reset_colour << cyan;
		cout << "                                               " << reset_colour << orange << "   \\ \\________" << endl << reset_colour << cyan;
	}
	else {
		cout << "                                   ||          " << reset_colour << orange << "     ________" << endl << reset_colour << cyan;
		cout << "                                   ||          " << reset_colour << orange << "    / /--------       " << endl << reset_colour << cyan;
		cout << "                                   ||          " << reset_colour << orange << "   | |         " << endl << reset_colour << cyan;
		cout << "                                   \\\\____    " << reset_colour << orange << "     | |" << endl << reset_colour << cyan;
		cout << "                                               " << reset_colour << orange << "   \\ \\________" << endl;
	}
	cout << reset_colour;
	return;
}

int menudecider(int choice)
{
	bool check = false;
	if (choice == '1')
	{
		gamestart();
		check = true;
	}
	else if (choice == '2')
	{
		showoptions();
		check = true;
	}
	else if (choice == '3')
	{
		gameexit();
		check = true;
	}
	return check;
}

void gamestart()
{
	//i can do all this in one loop
	//i don't know why i am doing this...
	dailougeAndStory();
	int choice = 0;
	bool check = false;
	string color = white;
	bool uppercase = false;
	for (int i = 0; i <= 2; i++)
	{
		system("cls");
		cout << "\n\n";
		bool uppercase = false;
		text_animation(gamestory[i], color, uppercase, 22);
		cout << "\n\n    ";
		system("pause");
	}
	system("cls");
	cout << "\n\n";
	getplayername(player);
	dailougeAndStory();
	for (int i = 3; i <= 10; i++)
	{
		system("cls");
		cout << "\n\n";
		bool uppercase = false;
		text_animation(gamestory[i], color, uppercase, 22);
		cout << "\n\n    ";
		if (i != 7)
		{
			system("pause");
		}
		else if (i == 7)
		{
			getplayerclass(player);
			dailougeAndStory();
		}
	}
	dailougeAndStory();
}

void showoptions()
{
	bool check = false;
	char choice;
	system("cls");
	cout << orange;
	cout << "         ___      ___           __   ___  ___        ___       ___  ___       ___  ___" << endl;
	cout << "          |  |__| |__      |   |  |  |__   |        |    |__| |___| |__| |     |   |__" << endl;
	cout << "          |  |  | |__      |__ \\__/  __/   |        |___ |  | |   | | \\  |__  _|_  |__" << endl;
	cout << " ________________________________________________________________________________________________" << endl;
	cout << "/  ____________________________________________________________________________________________  \\" << endl;
	cout << "| |                  ___       ______   ______  _____    ___              ___                  | |" << endl;
	cout << "| |                 /    \\    |      |     |      |     /    \\   |\\   |  |                     | |" << endl;
	cout << "| |                |      |   |______|     |      |    |      |  | \\  |  \\___                  | |" << endl;
	cout << "| |                |      |   |            |      |    |      |  |  \\ |      \\                 | |" << endl;
	cout << "| |                 \\____/    |            |    __|__   \\____/   |   \\|  ____/                 | |" << endl;
	cout << "| |                                                                                            | |" << endl;
	cout << "| |____________________________________________________________________________________________| |" << endl;
	cout << "\\ \\--------------------------------------------------------------------------------------------/ /" << endl;
	cout << "                                                                                            " << endl;
	cout << "    Do you really think this game would have an options tab ?" << endl;
	cout << "                                                                                            " << endl;
	cout << "    >   Go Back               ( 1 )" << endl << endl;

	while (check == false)
	{
		choice = _getch();
		if (isdigit(choice))
		{
			if (choice == '1')
			{
				menu();
				break;
			}
		}
		else
		{
			input_clear();
		}
	}
}

void gameexit()
{
	system("cls");
	blankscreen();
	cout << "\n\n\n\n    ";
	string gameclosing = "game is closing...";
	string color = orange;
	bool uppercase = true;
	text_animation(gameclosing, color, uppercase);
	system("cls");
	cout << "Game is Closed :)" << endl << endl;
}

void input_clear()
{
	cin.clear();
	while (_kbhit())
	{
		_getch();
	}
}

void getplayername(character& player)
{
	cout << reset_colour << green <<"    Enter Your Name : " << reset_colour;
	getline(cin, player.name);
}


void getplayerclass(character& player)
{
	bool check = false;
	while (check == false)
	{
		char choice = _getch();
		if (isdigit(choice))
		{
			player.experience_points = 0;
			player.level = 0;
			if (choice == '1')
			{
				player._class = "Mage";
				player.health = 80;
				player.damage = 10;
				player.critical_hit_chance = 40;
				player.special_weapon = " -_O)";
			}
			else if (choice == '2')
			{
				player._class = "Warrior";
				player.health = 120;
				player.damage = 30;
				player.critical_hit_chance = 20;
				player.special_weapon = " -/--";
			}
			else if (choice == '3')
			{
				player._class = "Rouge";
				player.health = 100;
				player.damage = 50;
				player.critical_hit_chance = 10;
				player.special_weapon = " *";
			}
		}
		else
		{
			input_clear();
		}
	}
}

void fight()
{
	cout << player.name << setw(50) << peter.name << endl;
	cout << "";
}


int options(int num,string optscene, string opt1, string opt2, string opt3)
{
	cout << "\n\n    " + optscene;
	cout << "\n\n    > " << opt1;
	cout << "\n    > " << opt2;
	if (num == 3)
	{
		cout << "\n    > " << opt3;
	}
	bool check = false;
	while (check == false)
	{
		char choice = _getch();
		if (isdigit(choice))
		{
			if (choice == '1')
			{
				check = true;
				return 1;
			}
			else if (choice == '2')
			{
				check = true;
				return 2;
			}
			else if (num == 3 && choice == '3')
			{
				check = true;
				return 3;
			}
		}
		else
		{
			input_clear();
		}
	}
	return 0;
}

