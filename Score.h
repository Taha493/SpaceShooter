#ifndef SCORE_H
#define SCORE_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

class Score{
private:
	sf::Font style;
	sf:: Text score;
	sf:: Text text;
	sf:: Text level;
	sf:: Text count;
	int scr = 10;
	public:

Score()
{
	if(!style.loadFromFile("Font/monserrat.ttf"))
	{
		cout << "Could not open the font file. " << endl;
	}
}
void display_score(sf:: RenderWindow& window,float& timer)
{	
		int temp = (int)timer;
		/*if(temp % 10 == 0 && timer!=0)
		{
			scr = scr + 10;
		}*/
		text.setFont(style);
		text.setFillColor(sf::Color::White);
		text.setCharacterSize(25);
		text.setString("Score: ");
		text.setPosition(sf::Vector2f(650,730));
		
		level.setFont(style);
		level.setFillColor(sf::Color::White);
		level.setCharacterSize(25);
		level.setString("Level: ");
		level.setPosition(sf::Vector2f(650,5));
		
		count.setFont(style);
		count.setFillColor(sf::Color::Yellow);
		count.setCharacterSize(25);
		string str1 = to_string(temp/32+1);
		count.setString(str1);
		count.setPosition(sf::Vector2f(745,5));
		
		score.setFont(style);
		score.setFillColor(sf::Color::Red);
		score.setCharacterSize(25);
		string str = to_string(temp/3);
		score.setString(str);
		score.setPosition(sf::Vector2f(750,730));
		
		window.draw(score);
		window.draw(text);
		window.draw(level);
		window.draw(count);
		window.display();
}

};
#endif
