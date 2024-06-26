#ifndef ANIMATION_H
#define ANIMATION_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class Animation
{
public:
	Texture t1, t2;
	Sprite spt1, spt2;
	int mon1_x, mon1_y;
 	int mon2_x, mon2_y;
 	int x1,y1;
 	int x2,y2;
 	
 Animation()
 {
	
	mon1_x = -270;
	mon1_y = 360;
	mon2_x = 910;
	mon2_y = 360;
	x1 = mon1_x;
	x2 = mon2_x;
	y1 = mon1_y;
	y2 = mon2_y;
	t1.loadFromFile("img/left.png");
	spt1.setTexture(t1);
	t2.loadFromFile("img/right.png");
	spt2.setTexture(t2);
	spt1.setPosition(sf::Vector2f(mon1_x,mon1_y));
	spt2.setPosition(sf::Vector2f(mon2_x,mon2_y));
	spt1.setScale(0.4,0.4);
	spt2.setScale(0.4,0.4);
 }
 
 
 void LevelUp()
{
					mon1_x =  1*10;
					x1+=mon1_x;
					//cout << "x1 " << x1 << endl;
					mon2_x =  -1*10;
					x2+=mon2_x;
					//cout << "x2 " << x2 << endl;
					//cout << "monster 1 x" << mon1_x << endl;
					//cout << "monster 1 x" << mon2_x << endl;
					spt1.move(sf::Vector2f(mon1_x, 0));
					spt2.move(sf::Vector2f(mon2_x, 0));	
					
}
};
#endif
