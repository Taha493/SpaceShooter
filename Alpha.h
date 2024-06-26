#ifndef ALPHA_H
#define ALPHA_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class Alpha{
public:
//Texture tex_alp1, tex_alp2, tex_alp3, tex_alp4, tex_alp5;
//Sprite sprite_alp1, sprite_alp2, sprite_alp3, sprite_alp4, sprite_alp5;

Texture tex_alpha;
Sprite sprite_alpha;
Texture t1, t2;
Sprite spt1, spt2;
int x,y;
int mon1_x, mon1_y;
int mon2_x, mon2_y;
int i_x;
int i_y;
Alpha()
{
	tex_alpha.loadFromFile("img/enemy_1.png");
	sprite_alpha.setTexture(tex_alpha);
	sprite_alpha.setPosition(sf::Vector2f(x,y));
	x = 55; y = 40;
	i_x = x; i_y = y;
	sprite_alpha.setScale(0.75,0.75);

/*tex_alp1.loadFromFile(png_path);
sprite_alp1.setTexture(tex_alp1);
x=55;y=40;
sprite_alp1.setPosition(sf::Vector2f(x,y));
sprite_alp1.setScale(0.75,0.75);


tex_alp2.loadFromFile(png_path);
sprite_alp2.setTexture(tex_alp2);
x=195;y=40;
sprite_alp2.setPosition(sf::Vector2f(x,y));
sprite_alp2.setScale(0.75,0.75);

tex_alp3.loadFromFile(png_path);
sprite_alp3.setTexture(tex_alp3);
x=335;y=40;
sprite_alp3.setPosition(sf::Vector2f(x,y));
sprite_alp3.setScale(0.75,0.75);

tex_alp4.loadFromFile(png_path);
sprite_alp4.setTexture(tex_alp4);
x=475;y=40;
sprite_alp4.setPosition(sf::Vector2f(x,y));
sprite_alp4.setScale(0.75,0.75);

tex_alp5.loadFromFile(png_path);
sprite_alp5.setTexture(tex_alp5);
x=615;y=40;
sprite_alp5.setPosition(sf::Vector2f(x,y));
sprite_alp5.setScale(0.75,0.75);
*/
}
};
#endif
