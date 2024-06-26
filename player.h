#include <SFML/Graphics.hpp>
#include <string.h>
#include "bullet.h"
#include "Lives.h"
#include <iostream>
using namespace sf;
using namespace std;
class Player{
public:
Texture tex, tex_bullet;
Sprite sprite, sprite_bullet;
float speed=1;
int x,y;
int i_x;
int i_y;
int bullet_count=0;
Bullet* b;
Lives* l;
int lives_count = 3;
Player(std::string png_path)
{
l= new Lives("img/PNG/Power-ups/bold_silver.png");
tex.loadFromFile(png_path);
sprite.setTexture(tex);
b = NULL;
x=340;y=700;
i_x = x;
i_y = y;
sprite.setPosition(sf::Vector2f(x,y));
sprite.setScale(0.75,0.75);
}
void fire()
{
	b = new Bullet(x,y);
	bullet_count = 1;
}
/*b = new Bullet[bullet_count];

for(int i = 0; i < bullet_count; i++)
{
	b[i] = Bullet();
	b[i].bullet_x = x;
	b[i].bullet_y = y;
}
bullet_count++;

Bullet* temp = new Bullet[bullet_count];
for(int i = 0; i < bullet_count-1; i++)
{
	temp[i] = b[i];
}
temp[bullet_count-1] = Bullet();
temp->bullet_x = x;
temp->bullet_y = y;
*/

void move(std::string s){
float delta_x=0,delta_y=0;

if(s=="l")
	{
	delta_x = -1;
	x+=delta_x;
	//bullet_x+=delta_x;
	//cout << "x " << x << endl;
	if(x < 0)
	{
		delta_x += 1;
		x = 700;
		sprite.setPosition(sf::Vector2f(x,y));
		//bullet_x = x + 28;
	}
	}
else if(s=="r")
{
	delta_x = 1;
	x+=delta_x;
	//bullet_x+=delta_x;
	//cout << "x " << x << endl;
	if(x > 700)
	{
		delta_x-=1;
		x = 0;
		sprite.setPosition(sf::Vector2f(x,y));
		//bullet_x = x + 28;
	}
}
if(s=="u")
{
	delta_y=-1;
	y+=delta_y;
	//bullet_y+=delta_y;
	//cout << "y " << y << endl;
	if(y < 0)
	{
		delta_y+=1;
		y = 700;
		sprite.setPosition(sf::Vector2f(x,y));
		//bullet_y = y;
		
	}
}
else if(s=="d")
{
	delta_y=1;
	y+=delta_y;
	//bullet_y+=delta_y;
	//cout << "y " << y << endl;
	if(y > 700)
	{
		delta_y-=1;
		y = 0;
		sprite.setPosition(sf::Vector2f(x,y));
		//bullet_y = y;
	}
}

i_x = x;
i_y = y;
delta_x*=speed;
delta_y*=speed;



sprite.move(sf::Vector2f(delta_x, delta_y));
//sprite_bullet.move(sf::Vector2f(delta_x,delta_y));	
//sprite_bullet.setPosition(sf::Vector2f(bullet_x,bullet_y));

}
};

