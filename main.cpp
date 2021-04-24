#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <fstream>
#include <string>
#define LEN 1000
using namespace sf;
using namespace std;

int balance() {
	
char buff[LEN];

ifstream file("res/coins.txt");

if(file.is_open()) file >> buff;	

file.close();

string res = string(buff);

int coins = stoi(res);

return coins;
	
}

void add(int sc) {
	
int now = balance();

int nw = now + sc;

string go = to_string(nw);

ofstream file("res/coins.txt");

if(file.is_open()) file << go;

file.close();	
	
}

int main() {

bool life = false;

int lifes = 0;
	
bool pause = false;

bool straf = false;

bool upst = false;
	
string good;

string mood;
	
bool d = false;

int score = 600;

int coins = balance();
		
int tsize = 50;

string st1 = "Score: ";

good = st1 + to_string(score);

Image n;

n.loadFromFile("res/d.png");

Image rk;

rk.loadFromFile("res/rock.png");

n.flipHorizontally();

Texture player;

player.loadFromImage(n);

Texture rock;

rock.loadFromImage(rk);

Sprite p(player);
    
RenderWindow w(VideoMode(VideoMode::getDesktopMode()), "Game");

float mg = w.getSize().x / 192;

float mfe = mg * 1.8;

CircleShape cir;

cir.setFillColor(Color::Black);

cir.setRadius(50);

cir.setPosition(0, 10);

CircleShape cirl;

cirl.setFillColor(Color::Yellow);

cirl.setRadius(50);

cirl.setPosition(w.getSize().x - 100, 10);

CircleShape lif;

lif.setFillColor(Color::Red);

lif.setRadius(50);

int contrvar = w.getSize().y / 2;

Sprite g(rock);

Sprite fe(rock);

float gp = w.getSize().x;

float gfe = w.getSize().x;

g.setPosition(w.getSize().x, w.getSize().y - 100);

fe.setPosition(w.getSize().x, contrvar - 100);

lif.setPosition(w.getSize().x - 100, 110);

float sizey;

sizey = w.getSize().y - 150;

p.setPosition(10, sizey);

Font f;

Text t1;

f.loadFromFile("res/font.ttf");

t1.setFont(f);

t1.setCharacterSize(tsize);

t1.setFillColor(Color::Red);

t1.setPosition(w.getSize().x/2-tsize/2*6, tsize*2);

Text t2;

t2.setFont(f);

t2.setCharacterSize(tsize);

t2.setFillColor(Color::Red);

t2.setPosition(w.getSize().x - 500, 60);

Text t3;

t3.setFont(f);

t3.setFillColor(Color::White);

t3.setPosition(w.getSize().x - 65, 135);

while (w.isOpen()) {
	
Event event;

while (w.pollEvent(event)) {	
			
if(d) { sizey = sizey + contrvar; p.setPosition(10, sizey); d = false; }

if(life) { if(lifes == 0) life = false; }
	
if (event.type == Event::Closed) w.close();

if (Touch::isDown(0) && !d) {
	
if(Touch::getPosition(0).x < 50 && Touch::getPosition(0).y < 100) {
	
if(pause) {

pause = false;

}

else {
	
pause = true;

}
	
}

else if(Touch::getPosition(0).x > w.getSize().x - 100 && Touch::getPosition(0).y < 100) {
	
add(score);

score = 0;	
	
}

else if(Touch::getPosition(0).x > w.getSize().x - 100 && Touch::getPosition(0).y < 210 && Touch::getPosition(0).y > 110) {
	
if(coins > 1000) {
	
coins -= 1000;

life = true;

lifes = 80;	
	
}	
	
}

else {

sizey = sizey - contrvar; 

p.move(0, -1*contrvar); 

d = true; 

}

}

}
	
w.clear(Color::White);

w.draw(p);

w.draw(cir);

w.draw(cirl);

w.draw(lif);

if(!pause) {

if(gp < 100 && !d && gp > 0 && !straf && !life) { score -= 30; straf = true; }

if(gfe < 100 && d && gfe > 0 && !upst && !life) { score -= 10; upst = true; }

if (gp > -100) { g.move(-1*mg, 0); gp -= mg; }

else { g.setPosition(w.getSize().x, w.getSize().y - 100); gp = w.getSize().x; if(!straf) score += 20; straf = false; if(life) lifes--; }

if (gfe > -100) { fe.move(-1*mfe, 0); gfe -= mfe; }

else { fe.setPosition(w.getSize().x, contrvar - 100); gfe = w.getSize().x; upst = false; }

}

coins = balance();

good = st1 + to_string(score);

t1.setString(good);

w.draw(t1);

t2.setString(to_string(coins));

t3.setString(to_string(lifes));

w.draw(t2);

w.draw(t3);

w.draw(g);

w.draw(fe);

w.display();

}

return 0;

}