#ifndef MENU_H
#define MENU_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
using namespace std;
using namespace sf;

class Menu{

private:
	sf::Font style;
	sf::Text words[4];
	sf:: Text instructions;
	sf:: Text highscore[3];
	sf:: Text gameover;
	sf:: Text score;
	Sprite background; 
	Texture bg_texture;
public:
//add menu attributes here
Menu()
{
	if(!style.loadFromFile("Font/monserrat.ttf"))
	{
		cout << "Could not open the font file. " << endl;
	}
	
	bg_texture.loadFromFile("img/background_1.png");
	background.setTexture(bg_texture);
	background.setScale(2, 1.5);
	words[0].setFont(style);
	words[0].setFillColor(sf::Color::Green);
	words[0].setString("START");
	words[0].setPosition(sf::Vector2f(300, 60));
	
	words[1].setFont(style);
	words[1].setFillColor(sf::Color::Blue);
	words[1].setString("HIGH SCORES");
	words[1].setPosition(sf::Vector2f(300, 280));
	
	words[2].setFont(style);
	words[2].setFillColor(sf::Color::Yellow);
	words[2].setString("INSTRUCTIONS");
	words[2].setPosition(sf::Vector2f(300, 490));
	
	words[3].setFont(style);
	words[3].setFillColor(sf::Color::Red);
	words[3].setString("QUIT");
	words[3].setPosition(sf::Vector2f(300, 680));
	
		instructions.setFont(style);
		instructions.setFillColor(sf::Color::Cyan);
		instructions.setCharacterSize(22);
		instructions.setString("Press UP, DOWN, LEFT and RIGHT Button to move the player.");
		instructions.setPosition(sf::Vector2f(20,360));
		
		
	highscore[0].setFont(style);
	highscore[0].setFillColor(sf::Color::Green);
	highscore[0].setCharacterSize(22);
	highscore[0].setString("Player 1 highscore is: 780");
	highscore[0].setPosition(sf::Vector2f(280, 80));
	
	highscore[1].setFont(style);
	highscore[1].setFillColor(sf::Color::Yellow);
	highscore[1].setCharacterSize(22);
	highscore[1].setString("Player 2 highscore is: 610");
	highscore[1].setPosition(sf::Vector2f(280, 340));
	
	highscore[2].setFont(style);
	highscore[2].setFillColor(sf::Color::Blue);
	highscore[2].setCharacterSize(22);
	highscore[2].setString("Player 3 highscore is: 400");
	highscore[2].setPosition(sf::Vector2f(280, 590));
	

//constructors body
}

~Menu()
{
}

void front_screen(sf::RenderWindow& window)
{
	window.clear(Color::Black); //clears the screen
	window.draw(background);
	for(int i = 0; i < 4; i++)
	{
		window.draw(words[i]);
	}
	window.display();
}

void display_info(sf:: RenderWindow& window)
{
		window.clear(Color::Black); 
		window.draw(background);
		window.draw(instructions);
		window.display();
}

void display_Highscore(sf:: RenderWindow& window)
{
		window.clear(Color::Black); 
		window.draw(background);
		for(int i = 0; i < 3; i++)
	{
		window.draw(highscore[i]);
	}
		window.display();
}

void display_gameover(sf:: RenderWindow& window)
{
		gameover.setFont(style);
		gameover.setFillColor(sf::Color::White);
		gameover.setCharacterSize(35);
		gameover.setString("Player crashed with enemy. Gameover");
		gameover.setPosition(sf::Vector2f(35,360));
		
		window.clear(Color::Black); 
		window.draw(background);
		window.draw(gameover);
		window.display();
	
		
}



};

#endif
