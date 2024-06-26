#ifndef ENEMIES_H
#define ENEMIES_H
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
class Bomb
{
public:
int b_x, b_y, temp_y;
Texture bomb_tex;
Sprite bomb_sprite;
Bomb()
{
this->b_x = 0;
this->b_y = 0;
this->temp_y = 0;
bomb_tex.loadFromFile("img/PNG/Lasers/laserRed08.png");
bomb_sprite.setTexture(bomb_tex);
bomb_sprite.setScale(0.5,0.5);
}

};

class Enemies
{
public:
Bomb* bomb = new Bomb[14];
virtual void drop() = 0; //pure virtual function
};

class Invaders : public Enemies
{
public:
Invaders()
{
}

virtual void drop()
{
}
};

class Monster: public Enemies
{
public:
int m_x, m_y;
int attack_x, attack_y;
Texture monster_tex, attack_tex;
Sprite monster_sprite, attack_sprite;
Monster()
{
m_x = 200;
m_y = 100;
attack_x = 200;
attack_y = 100;
monster_tex.loadFromFile("img/monster2.png");
monster_sprite.setTexture(monster_tex);
monster_sprite.setPosition(sf::Vector2f(m_x,m_y));
monster_sprite.setScale(0.8,0.8);
attack_tex.loadFromFile("img/PNG/Lasers/laserRed05.png");
attack_sprite.setTexture(attack_tex);
attack_sprite.setScale(3.0,13.0);
}
void move()
{
m_x += 20;
//cout << "Monster has moved." << endl;
}

virtual void drop()
{
bomb->b_x = m_x;
bomb->b_y = m_y;
bomb->b_y -= 10;
//cout << "Monster dropped the bomb." << bomb->b_y << endl;
}

};

class Dragon: public Enemies
{
public:
int d_x, d_y;
int attack_x, attack_y;
Texture dragon_tex;
Sprite dragon_sprite;
Texture attack_tex;
Sprite attack_sprite;
Dragon()
{
d_x = 200;
d_y = 100;
attack_x = 200;
attack_y = 100;
dragon_tex.loadFromFile("img/dragon1.png");
dragon_sprite.setTexture(dragon_tex);
dragon_sprite.setPosition(sf::Vector2f(d_x,d_y));
dragon_sprite.setScale(1.5,1.5);
attack_tex.loadFromFile("img/PNG/Lasers/laserBlue06.png");
attack_sprite.setTexture(attack_tex);
attack_sprite.setScale(3.0,13.0);
}

virtual void drop()
{
bomb->b_x = d_x;
bomb->b_y = d_y;
bomb->b_y -= 10;
//cout << "Dragon dropped the bomb." << bomb->b_y << endl;
}
};

class alpha: public Invaders
{
public:
int a_x, a_y;
Texture alp_tex;
Sprite alp_sprite;
alpha() : Invaders()
{
this->a_x = 65;
this->a_y = 40;
bomb->b_x = a_x;
bomb->b_x = a_y;
bomb->temp_y = a_y;
alp_tex.loadFromFile("img/enemy_1.png");
alp_sprite.setTexture(alp_tex);
alp_sprite.setPosition(sf::Vector2f(a_x,a_y));
alp_sprite.setScale(0.7,0.7);

}

virtual void drop()
{
for(int i = 0; i < 14; i++)
{
bomb[i].temp_y = 1*10;
bomb[i].b_y+=bomb->temp_y;
bomb[i].bomb_sprite.move(sf::Vector2f(0,bomb->temp_y));
}
}
};


class Beta: public Invaders
{
public:
int beta_x, beta_y;
Texture beta_tex;
Sprite beta_sprite;
Beta() : Invaders()
{
this->beta_x= 155;
this->beta_y = 40;
beta_tex.loadFromFile("img/enemy_2.png");
beta_sprite.setTexture(beta_tex);
beta_sprite.setPosition(sf::Vector2f(beta_x,beta_y));
beta_sprite.setScale(0.6,0.6);
}
virtual void drop()
{
bomb->b_x = beta_x;
bomb->b_y = beta_y;
bomb->b_y -= 10;
//cout << "Beta dropped the bomb." << bomb->b_y << endl;
}

};

class Gamma: public Invaders
{
public:
int g_x, g_y;
Texture gamma_texture;
Sprite gamma_sprite;
Gamma() : Invaders()
{
this->g_x = 65;
this->g_y = 40;
gamma_texture.loadFromFile("img/enemy_3.png");
gamma_sprite.setTexture(gamma_texture);
gamma_sprite.setPosition(sf::Vector2f(g_x,g_y));
gamma_sprite.setScale(0.7,0.7);
}
virtual void drop()
{
bomb->b_x = g_x;
bomb->b_y = g_y;
bomb->b_y -= 10;
//cout << "Gamma dropped the bomb." << bomb->b_y << endl;
}
};
#endif
