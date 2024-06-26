#include <SFML/Graphics.hpp>
#include <time.h>
#include "player.h"
#include "Alpha.h"
#include "menu.h"
#include "Animation.h"
#include "Score.h"
#include "Enemies.h"
#include <iostream>
using namespace std;
using namespace sf;
const char title[] = "OOP-Project, Spring-2023";


class Game
{
public:
Sprite background; //Game background sprite
Texture bg_texture;
int alpha_num = 5;
int delete_alp = 5;
int alp_num = 14;
int beta_num = 14;
int gamma_num = 20;
int todelete = alpha_num;
int delete_beta = beta_num;
int delete_gamma = gamma_num;
int monster_health = 150;
int dragon_health = 200;
bool kill_enemy = false;
bool kill_alpha = false;
bool kill_gamma = false;
bool kill_alp = false;
bool kill_beta = false;
bool allow_monster = false;
bool start_flag = true;
bool high_flag = true;
bool info_flag = true;
bool alpha_move = true;
bool bonus_move = true;
bool gameover = false;
bool collide = false;
bool check_alp = false;
bool check_monster = false;
bool check_dragon = false;
float timer=0, delay = 0.5;
float start_timer = 0;
float dragon_time = 0;
float alp_bomb = 0;
bool check_gamma = false;
float monster_time = 0;
Font f;
Text monster_score;
Text monster_score1;
Text dragon_score;
Text dragon_score1;

Player* p; //player 
Alpha* a = new Alpha[alpha_num];
Alpha* temp = new Alpha[alpha_num];
Enemies** enemy;
Menu m;
Score s;
Animation bonus;
Game()
{
p=new Player("img/player_ship.png");
enemy = new Enemies*[5];
bg_texture.loadFromFile("img/background.jpg");
background.setTexture(bg_texture);
background.setScale(2, 1.5);
if(!f.loadFromFile("Font/monserrat.ttf"))
	{
		cout << "Could not open the font file. " << endl;
	}
}

void start_game()
{
alpha** alp = (alpha**)enemy;
alp[0] = new alpha[alp_num];
alp[0]->bomb = new Bomb[14];
for (int i = 0; i < 4; i++)
{
alp[0][i + 1].a_x = alp[0][i].a_x + 140;
}
for(int i = 0; i < 5; i++)
{
alp[0][5+i].a_x = alp[0][i].a_x;
alp[0][5+i].a_y = 340;
}
alp[0][10].a_x = alp[0][0].a_x;
alp[0][10].a_y = 140;
alp[0][11].a_x = alp[0][0].a_x;
alp[0][11].a_y = 240;
alp[0][12].a_x = alp[0][4].a_x;
alp[0][12].a_y = 140;
alp[0][13].a_x = alp[0][4].a_x;
alp[0][13].a_y = 240;
for(int i = 0; i < alp_num; i++)
{
alp[0][i].alp_sprite.setPosition(sf::Vector2f(alp[0][i].a_x,alp[0][i].a_y));
}

for(int i = 0; i < alp_num; i++)
{
	alp[0][i].bomb[i].b_x = alp[0][i].a_x+30;
	alp[0][i].bomb[i].b_y = alp[0][i].a_y;
}
for(int i = 0; i < alp_num; i++)
{
alp[0][i].bomb[i].bomb_sprite.setPosition(sf::Vector2f(alp[0][i].bomb[i].b_x,alp[0][i].bomb[i].b_y));
}

Monster** monster = (Monster**)enemy;
monster[3] = new Monster();


Beta** beta = (Beta**)enemy;
	beta[1] = new Beta[beta_num];

		for (int i = 0; i < 3; i++)
		{
			beta[1][i + 1].beta_x = beta[1][i].beta_x + 115;
		}
		
		beta[1][4].beta_x = 40;
		beta[1][4].beta_y = 140;
		for(int i = 4; i < 9; i++)
		{
			beta[1][i+1].beta_x = beta[1][i].beta_x + 115;
			beta[1][i+1].beta_y = beta[1][i].beta_y;

		}
		
		beta[1][10].beta_x = beta[1][0].beta_x;
		beta[1][10].beta_y = 240;
		
		beta[1][11].beta_x = beta[1][3].beta_x;
		beta[1][11].beta_y = 240;
		
		beta[1][12].beta_x = beta[1][1].beta_x;
		beta[1][12].beta_y = 340;
		
		beta[1][13].beta_x = beta[1][2].beta_x;
		beta[1][13].beta_y = 340;
		 
		for(int i = 0; i < beta_num; i++)
		{
			beta[1][i].beta_sprite.setPosition(sf::Vector2f(beta[1][i].beta_x,beta[1][i].beta_y));
		}
		
Dragon** dragon= (Dragon**)enemy;
dragon[4] = new Dragon();

Gamma** gamma = (Gamma**)enemy;
gamma[2] = new Gamma[20];

for(int i = 0; i < 4; i++)
{
	gamma[2][i+1].g_x = gamma[2][i].g_x + 140;
}

gamma[2][5].g_x = gamma[2][0].g_x;
gamma[2][5].g_y = 140;
for(int i = 0; i < 4; i++)
{
	gamma[2][6+i].g_x = gamma[2][i].g_x + 140;
	gamma[2][6+i].g_y = 140;
}

gamma[2][10].g_x = gamma[2][0].g_x;
gamma[2][10].g_y = 240;
for(int i = 0; i < 4; i++)
{
	gamma[2][11+i].g_x = gamma[2][i].g_x + 140;
	gamma[2][11+i].g_y = 240;
}
gamma[2][15].g_x = gamma[2][0].g_x;
gamma[2][15].g_y = 340;
for(int i = 0; i < 4; i++)
{
	gamma[2][16+i].g_x = gamma[2][i].g_x + 140;
	gamma[2][16+i].g_y = 340;
}
for(int i = 0; i < gamma_num; i++)
		{
			gamma[2][i].gamma_sprite.setPosition(sf::Vector2f(gamma[2][i].g_x, gamma[2][i].g_y));
		}

    RenderWindow window(VideoMode(780, 780), title);
    Clock clock;
    
    
    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asSeconds(); 
        clock.restart();
        timer += time;   
 	Event e;
        while (window.pollEvent(e))
        {  
            if (e.type == Event::Closed) // If cross/close is clicked/pressed
                window.close(); //close the game    
        }                   	    
      if(start_flag == true){
     m.front_screen(window); 
     }
	if (Keyboard::isKeyPressed(Keyboard::Q)) // If down key is pressed
	{
		window.close();
	}
	if (Keyboard::isKeyPressed(Keyboard::I)) // If down key is pressed
	{
		start_flag = false;
		m.display_info(window);
	}
	if(Keyboard::isKeyPressed(Keyboard::Return))
	{
		start_flag = false;
		info_flag = false;
		high_flag = false;
	}
	if(Keyboard::isKeyPressed(Keyboard::H))
	{
		start_flag = false;
		info_flag = false;
		m.display_Highscore(window);
	}
	
if(start_flag == false && info_flag == false && high_flag == false && gameover == false)
{
	start_timer += time;
	s.display_score(window,timer);
	if(p->bullet_count>0)
	{
	window.draw(p->b->sprite_bullet);		   //setting bullet on screen	
	}
	window.display();  //Displying all the sprites
	if (Keyboard::isKeyPressed(Keyboard::Left)) //If left key is pressed
            p->move("l");    // Player will move to left
	if (Keyboard::isKeyPressed(Keyboard::Right)) // If right key is pressed
            p->move("r");  //player will move to right
	if (Keyboard::isKeyPressed(Keyboard::Up)) //If up key is pressed
            p->move("u");    //playet will move upwards
	if (Keyboard::isKeyPressed(Keyboard::Down)) // If down key is pressed
            p->move("d");  //player will move downwards
    if (Keyboard::isKeyPressed(Keyboard::Space)) // If space key is pressed
    {
    	p->fire();
 									            //player will move downwards
 	}
 	
 	
	if(p->bullet_count>0)
	{
	p->b->move();
	}
	window.clear(Color::Black); 	//clears the screen
	window.draw(background);  		// setting background
	window.draw(p->sprite);   		// setting player on screen

if(check_alp == false)
{
if(p->bullet_count>0)
{
for(int i = 0; i < alp_num; i++)
{
	if((p->b->bullet_x >= alp[0][i].a_x) && (p->b->bullet_x <= alp[0][i].a_x + 80))
	{
		if((p->b->bullet_y >= alp[0][i].a_y) && (p->b->bullet_y <= alp[0][i].a_y + 60))
		{
			p->bullet_count = 0;
			delete_alp = i;
			kill_alp = true;
			
			
		}
	}
}
}
if(kill_alp == true)
{
for(int i = delete_alp; i < delete_alp + 1; i++)
{
	alp[0][i].a_x = -100;
	alp[0][i].a_y = -100;
	alp[0][i].alp_sprite.setPosition(sf::Vector2f(alp[0][i].a_x,alp[0][i].a_y));
}
}
for(int i = 0; i < alp_num; i++)
{
	window.draw(alp[0][i].alp_sprite);
}
for(int i = 0; i < alp_num; i++)
{
	if(alp[0][i].a_x != -100 && alp[0][i].a_y !=-100)
	{
		check_monster = false;
		break;
	}
	else
	{
		check_monster = true;
	}
	
}
}

if(check_monster == true)
{
	displaymscore();
	monster_time += time;
	int temp = (int)monster_time;
	monster_attack(temp, window);
	cout << "attack x " << monster[3]->attack_x << endl;
	cout << "attack y " << monster[3]->attack_y << endl;
	cout << "Player x " << p->x << endl;
	cout << "Player y " << p->y << endl;
	if(interact_monster())
	{
		m.display_gameover(window);
	}
	if(p->bullet_count >0)
	{

	if(p->b->bullet_x >= monster[3]->m_x + 30 && p->b->bullet_x <= monster[3]->m_x+350)
	{
		if(p->b->bullet_y >= monster[3]->m_y-30 && p->b->bullet_y >= monster[3]->m_y + 5)
		{
			p->bullet_count = 0;
			if(Keyboard::isKeyPressed(Keyboard::Space))
			{
			monster_health = monster_health -1;
			}
			p->b->bullet_x = p->x;
			p->b->bullet_y = p->y;
			p->bullet_count = 1;
			window.draw(p->b->sprite_bullet);
			if(monster_health < 1)
			{
			monster_health = 0;
			monster[3]->m_x = -500;
			monster[3]->m_y = -500;
			monster[3]->monster_sprite.setPosition(sf::Vector2f(monster[3]->m_x, monster[3]->m_y));
			check_monster = false;
			}
		}
	}
	}
	window.draw(monster[3]->monster_sprite);
	window.draw(monster_score);
	window.draw(monster_score1);
	if(monster[3]->m_x == -500 && monster[3]->m_x == -500)
{	
	p->bullet_count = 0;
	check_monster = false;
	check_alp = true;
}
}



if(check_alp == true)
{
		if(Keyboard::isKeyPressed(Keyboard::Space))
		{
			p->bullet_count = 1;
		}
		if(p->bullet_count>0)
		{
			for(int i = 0; i < beta_num; i++)
			{
				if((p->b->bullet_x >= beta[1][i].beta_x) && (p->b->bullet_x <= beta[1][i].beta_x + 80))
					{
						if((p->b->bullet_y >= beta[1][i].beta_y) && (p->b->bullet_y <= beta[1][i].beta_y + 60))
							{
								p->bullet_count = 0;
								p->b->bullet_y = p->y;
								delete_beta = i;
								kill_beta = true;
							}
					}
			}
	if(kill_beta == true)
	{
		for(int i = delete_beta; i < delete_beta+ 1; i++)
		{
			beta[1][i].beta_x = -100;
			beta[1][i].beta_y = -100;
			beta[1][i].beta_sprite.setPosition(sf::Vector2f(beta[1][i].beta_x,beta[1][i].beta_y));
		}
	}
		}
		for(int i = 0; i < beta_num; i++)
		{
			window.draw(beta[1][i].beta_sprite);
		}
		
for(int i = 0; i < beta_num; i++)
{
	if(beta[1][i].beta_x != -100 && beta[1][i].beta_y !=-100)
	{
		check_dragon = false;
		break;
	}
	else
	{
		check_dragon = true;
	}
	
}
}


if(check_dragon == true)
{
		dragon_time = dragon_time + time;
		displaydragonscore();
		if(dragon_time>5)
		{
			dragon[4]->d_x = -500;
			dragon[4]->d_y = -500;
			dragon[4]->dragon_sprite.setPosition(sf::Vector2f(dragon[4]->d_x, dragon[4]->d_y));
			dragon_score.setPosition(sf::Vector2f(-100,-100));
			dragon_score1.setPosition(sf::Vector2f(-100,-100));
			dragon_health = 0;
			check_dragon = false;
		}
		else
		{
			dragon_attack(dragon_time, window, check_dragon);
		}
		/*if(dragon[4]->d_x == -1000 && dragon[4]->d_y == -1000)
		{
			dragon[4]->dragon_sprite.setPosition(sf::Vector2f(dragon[4]->d_x, dragon[4]->d_y));
			window.draw(dragon[4]->dragon_sprite);
			check_dragon = false;
		}*/
	if(p->bullet_count >0)
	{

	if(p->b->bullet_x >= dragon[4]->d_x + 30 && p->b->bullet_x <= dragon[4]->d_x+350)
	{
		if(p->b->bullet_y >= dragon[4]->d_y-30 && p->b->bullet_y >= dragon[4]->d_y + 5)
		{
				cout << "x " << dragon[4]->d_x << endl;
				cout << "y " << dragon[4]->d_y << endl;
				
			p->bullet_count = 0;
			if(Keyboard::isKeyPressed(Keyboard::Space))
			{
			dragon_health = dragon_health -1;
			}
			cout << "dragon_health: " << dragon_health << endl;
			p->b->bullet_x = p->x;
			p->b->bullet_y = p->y;
			p->bullet_count = 1;
			window.draw(p->b->sprite_bullet);
			if(dragon_health < 1)
			{
			dragon_health = 0;
			dragon[4]->d_x = -500;
			dragon[4]->d_y = -500;
			dragon[4]->dragon_sprite.setPosition(sf::Vector2f(dragon[4]->d_x, dragon[4]->d_y));
			check_dragon = false;
			}
		}
	}
	}
	window.draw(dragon[4]->dragon_sprite);
	window.draw(dragon_score);
	window.draw(dragon_score1);
	
	if(dragon[4]->d_x == -500 && dragon[4]->d_x == -500 || dragon_time > 5)
{	
	p->bullet_count = 0;
	check_dragon = false;
	check_gamma = true;
}
}


if(check_gamma == true)
{
	p->bullet_count = 1;
	if(p->bullet_count>0)
{
for(int i = 0; i < gamma_num; i++)
{
	if((p->b->bullet_x >= gamma[2][i].g_x) && (p->b->bullet_x <= gamma[2][i].g_x + 80))
	{
			if((p->b->bullet_y >= gamma[2][i].g_y) && (p->b->bullet_y <= gamma[2][i].g_y + 60))
		{
			p->b->bullet_y = p->y;
			delete_gamma = i;
			kill_gamma = true;
			
			
		}
	}
}
if(kill_gamma == true)
{

for(int i = delete_gamma; i < delete_gamma + 1; i++)
{
	gamma[2][i].g_x = -100;
	gamma[2][i].g_y = -100;
	gamma[2][i].gamma_sprite.setPosition(sf::Vector2f(gamma[2][i].g_x, gamma[2][i].g_y));

}
}
}
	for(int i = 0; i < gamma_num; i++)
	{
	window.draw(gamma[2][i].gamma_sprite);
	}
}
	if(deletePlayer())
		{
			start_flag = false;
			gameover = true;
			if(gameover = true)
			{
				m.display_gameover(window);
			}
		}
}
}
}
void displaymscore()
{
		monster_score.setFont(f);
		monster_score.setFillColor(sf::Color::White);
		monster_score.setCharacterSize(25);
		monster_score.setString("Monster health: ");
		monster_score.setPosition(sf::Vector2f(5,740));
		
		monster_score1.setFont(f);
		monster_score1.setFillColor(sf::Color::Cyan);
		monster_score1.setCharacterSize(25);
		string str1 = to_string(monster_health);
		monster_score1.setString(str1);
		monster_score1.setPosition(sf::Vector2f(220,740));
}

void displaydragonscore()
{       
        dragon_score.setFont(f);
		dragon_score.setFillColor(sf::Color::White);
		dragon_score.setCharacterSize(25);
		dragon_score.setString("Dragon health: ");
		dragon_score.setPosition(sf::Vector2f(5,740));
		
		dragon_score1.setFont(f);
		dragon_score1.setFillColor(sf::Color::Cyan);
		dragon_score1.setCharacterSize(25);
		string str2 = to_string(dragon_health);
		dragon_score1.setString(str2);
		dragon_score1.setPosition(sf::Vector2f(220,740));
		}
void setAlpha()
{
	for(int i = 0; i < alpha_num; i++)
	{
		a[i+1].x = a[i].x + 140;
		a[i].y = 40;
		//cout << "a[i].x " << a[i].x << endl;
		//cout << "a[i].y " << a[i].y << endl;
		a[i].sprite_alpha.setPosition(sf::Vector2f(a[i].x,a[i].y));
	}
}

bool checkAlpha()
{
	//cout << "Checking Alpha. " << endl;
		p->b->bullet_y-=10;
	//cout << "b_x " << p->b->bullet_x << endl;
	//cout << "b_y " << p->b->bullet_y << endl;
	for(int i = 0; i < alpha_num; i++)
	{
		if((p->b->bullet_x >= a[i].x) && (p->b->bullet_x <= a[i].x + 80))
		{
			if((p->b->bullet_y >= a[i].y) && (p->b->bullet_y <= a[i].y + 60))
			{
				//cout << "KILL ENEMY" << endl;
				//cout << "i" << i << endl;
				todelete = i;
				p->b->bullet_y = p->y;
				return true;
			}
			else
			{
				if(p->b->bullet_y <= -20)
				{
				p->b->bullet_y = p->y;
				}
			}
		}
	}
	return false;
}
void deleteAlpha()
{
	//cout << "Deleting Alpha. " << endl;
	for(int i = 0; i<todelete; i++)
	{
		a[i].sprite_alpha.setPosition(sf::Vector2f(a[i].x,a[i].y));
		//cout << "First loop" << endl;
	}
	
	/*if(todelete == 0)
	{
		todelete++;
		alpha_num++;
		a[0].x = -100;
		a[0].y = -100;
		a[0].sprite_alpha.setPosition(sf::Vector2f(a[0].x, a[0].y));
	}*/
	
	for(int i = todelete; i < todelete+1; i++)
	{
			a[i].x = -100;
			a[i].x = -100;
			a[i].sprite_alpha.setPosition(sf::Vector2f(a[i].x, a[i].y));
	}
	
	for(int i = todelete+1; i < alpha_num ; i++)
	{
		a[i].sprite_alpha.setPosition(sf::Vector2f(a[i].x,a[i].y));
		//cout << "Second loop" << endl;
	}
	
}

bool deletePlayer()
{
	alpha** alp = (alpha**)enemy; 
	for(int i = 0; i < 5; i++)
	{
		if((p->x >= alp[0][i].a_x-10) && (p->x <= alp[0][i].a_x + 80))
		{
			if((p->y >= alp[0][i].a_y - 30) && (p->y <= alp[0][i].a_y + 80))
			{
			
			return true;
			}
		}
	}
	return false;
}

void monster_attack(int m_time, sf:: RenderWindow& window)
{
	Monster** monster = (Monster**)enemy;
	monster[3] = new Monster();
	if(m_time % 4 == 0 && m_time!=0)
	{
	monster[3]->attack_x = monster[3]->m_x + 180;
	monster[3]->attack_y = monster[3]->m_y + 260;
	monster[3]->attack_sprite.setPosition(sf::Vector2f(monster[3]->attack_x, monster[3]->attack_y));
	}
	else
	{
		monster[3]->attack_x = -500;
	monster[3]->attack_y = -500;
	monster[3]->attack_sprite.setPosition(sf::Vector2f(monster[3]->attack_x, monster[3]->attack_y));
	}
	
	window.draw(monster[3]->attack_sprite);
	
}

bool interact_monster()
{
	Monster** monster = (Monster**)enemy;
	monster[3] = new Monster();
	if((monster[3]->attack_x >= p->x-70) && (monster[3]->attack_x <= p->x + 30))
	{
		if((monster[3]->attack_y <= p->y) && (monster[3]->attack_y + 360 >= p->y + 30))
		{	
			return true;
		}
	}
	return false;
}

void dragon_attack(int d_t, sf:: RenderWindow& window, bool check_d)
{
	Dragon** dragon = (Dragon**)enemy;
	dragon[4] = new Dragon();
if(check_d == true)
{
	if(dragon_time <= 5)
	{
	dragon[4]->attack_x = dragon[4]->d_x + 160;
	dragon[4]->attack_y = dragon[4]->d_y + 260;
	dragon[4]->attack_sprite.setPosition(sf::Vector2f(dragon[4]->attack_x, dragon[4]->attack_y));
	}
	else
	{
	dragon[4]->attack_x = -1000;
	dragon[4]->attack_y = -1000;
	dragon[4]->d_x = -1000;
	dragon[4]->d_y = -1000;
	dragon[4]->dragon_sprite.setPosition(sf::Vector2f(dragon[4]->d_x, dragon[4]->d_y));
	dragon[4]->attack_sprite.setPosition(sf::Vector2f(dragon[4]->attack_x, dragon[4]->attack_y));
	}
	
	window.draw(dragon[4]->attack_sprite);
}
}

bool interact_dragon()
{
	Monster** monster = (Monster**)enemy;
	monster[3] = new Monster();
	if((monster[3]->attack_x >= p->x-70) && (monster[3]->attack_x <= p->x + 30))
	{
		if((monster[3]->attack_y <= p->y) && (monster[3]->attack_y + 360 >= p->y + 30))
		{	
			return true;
		}
	}
	return false;
}
	/*if(start_timer >=4 && bonus_move == true)
	{	
		bonus.LevelUp();
		if(bonus.x1 > 255)
		{
			bonus_move = false;
			
		}
		if(bonus_move == false)
		{
			bonus.spt1.setPosition(sf::Vector2f(-400, -400));
			bonus.spt2.setPosition(sf::Vector2f(-400, -400));
		}
		window.draw(bonus.spt1);
		window.draw(bonus.spt2);
	}*/

/*alpha_move = false;
	if(p->lives_count == 3)
	{
	window.draw(p->l->ls1);
	window.draw(p->l->ls2);
	window.draw(p->l->ls3);
	}*/
	/*alp_bomb+=time;
int temp = (int)alp_bomb;
if(temp % 3== 0 && temp!=0)
{
	for(int i = 0; i < alp_num; i++)
	{
	alp[0][i].bomb[i].bomb_sprite.setPosition(sf::Vector2f(alp[0][i].bomb[i].b_x,alp[0][i].bomb[i].b_y));
	alp[0][i].drop();
	}
}
else
{
	for(int i = 0; i < alp_num; i++)
	{
	alp[0][i].bomb[i].bomb_sprite.setPosition(sf::Vector2f(-100,-100));
	}
}*/
/*~Game()
{
	delete p;
	delete []a;
	delete []temp;
	
	for(int i = 0; i < 5; i++)
	{
		delete[] enemy[i];
	}
	delete[] enemy;
}*/
};
