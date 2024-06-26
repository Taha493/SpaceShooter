#ifndef BULLET_H
#define BULLET_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Alpha.h"
using namespace std;
using namespace sf;
class Bullet
{
public:
	int bullet_x;
	int bullet_y;
	int temp_y;
	int reserve_y;
	Texture tex_bullet;
	Sprite sprite_bullet;
	int speed = 0.5;
	
	/*Bullet()
	{
	tex_bullet.loadFromFile("img/PNG/Effects/fire03.png");
	sprite_bullet.setTexture(tex_bullet);
	bullet_x = 365 + 25;
	bullet_y = 700;
	sprite_bullet.setPosition(sf::Vector2f(bullet_x,bullet_y));
	sprite_bullet.setScale(2,2);
	}*/
	Bullet(int x, int y)
	{
		bullet_x = x + 33;
		bullet_y = y;
	tex_bullet.loadFromFile("img/PNG/Lasers/laserGreen11.png");
	sprite_bullet.setTexture(tex_bullet);
	sprite_bullet.setPosition(sf::Vector2f(bullet_x,bullet_y));
	sprite_bullet.setScale(1.5,1.5);
	}
	
void move()
	{
		/*cout << "timer: " << timer << endl;
		cout << "delay: " << delay << endl;
		cout << "bullet_x: " << bullet_x << endl;
		cout << "bullet_y: " << bullet_y << endl;*/
	
			
				
					temp_y =  -1*25;
					bullet_y+=temp_y;
					//cout << "bullet_x: " << bullet_x << endl;
					//cout << "bullet_y: " << bullet_y << endl;
					sprite_bullet.move(sf::Vector2f(0,temp_y));	
					//sprite_bullet.setPosition(sf::Vector2f(bullet_x,bullet_y));
					
				
				
			
		
	
	}


};

#endif
