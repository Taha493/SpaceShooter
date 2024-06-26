#include <SFML/Graphics.hpp>
#include <string.h>
#include "bullet.h"
#include <iostream>
using namespace sf;
using namespace std;

class Lives{
public:
	int x,y;
	Sprite ls1, ls2, ls3;
	Texture lt1, lt2, lt3;
	Lives(std:: string png_path)
	{
		lt1.loadFromFile(png_path);
		ls1.setTexture(lt1);
		x=5;y=5;
		ls1.setPosition(sf::Vector2f(x,y));
		ls1.setScale(1,1);


		lt2.loadFromFile(png_path);
		ls2.setTexture(lt2);
		x=35;y=5;
		ls2.setPosition(sf::Vector2f(x,y));
		ls2.setScale(1,1);

		lt3.loadFromFile(png_path);
		ls3.setTexture(lt3);
		x=65;y=5;
		ls3.setPosition(sf::Vector2f(x,y));
		ls3.setScale(1,1);
	}
};
