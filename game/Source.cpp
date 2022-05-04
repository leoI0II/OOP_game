

#include"Game.hpp"
#include<SFML/Graphics.hpp>
#include<iostream>


class test {
public:
	virtual void print() {
		std::cout << "In test" << std::endl;
	}
};
class testChild : public test {
public:
	void print() {
		std::cout << "In testChild" << std::endl;
	}
};

class SomeTest {

};

class ttt : public SomeTest {

};

template<int N>
class testTempl {
public:
	void print() {
		std::cout << N << std::endl;
	}
};


void check(test& obj) {
	std::cout << typeid(obj).name() << std::endl;
	if (typeid(obj) == typeid(testChild)) {
		std::cout << "YES" << std::endl;
	}
	else
		std::cout << "NO" << std::endl;
}

struct enumT {
	enum class Tets{ hi, bye};
	Tets t = Tets::bye;
};

class testThis {
private:
	int a;
	int b;
public:
	testThis(int s, int e): a(s), b(e){}
	void sh() {
		std::cout << a << " " << b << std::endl;
	}
	void ch(int w, int q) {
		*this = testThis(w, q);
	}
};


int main() {


	Game<TimeEvent<50>, EnemyKillerEvent<2>> game;
	game.HaveFun();


	//system("del C:\\Users\\danie\\source\\repos\\NEWGAMEF\\NEWGAMEF\\game.data");

	//std::cout << sizeof(typeid(int)) << std::endl;

	
	//std::chrono::seconds sec;
	//std::cout << sec.count() << std::endl;


	//enumT a;

	//std::cout << int(a.t) << std::endl;

	//std::ifstream file("file.game", std::ifstream::binary);
	//file.read((char*)&sec, sizeof(std::chrono::seconds));
	//file.close();
	//std::cout << int(a.t) << std::endl;
	//std::cout << sec.count() << std::endl;

	//std::ofstream file("file.game", std::ofstream::binary);
	//file.write((char*)&sec, sizeof(std::chrono::seconds));
	//file.close();


	/*testTempl<5> a;
	a.print();
	std::cout << typeid(a).name() << std::endl;
	*/



	//SomeTest st;
	//ttt t;

	//SomeTest* reft = &t;

	//std::cout << typeid(st).name() << std::endl;
	//std::cout << typeid(t).name() << std::endl;
	//std::cout << typeid(*reft).name() << std::endl;

	//std::string str(typeid(SomeTest).name());
	//size_t n = str.find(" ");

	//std::cout << str.c_str()+n+1 << std::endl;


	/*test t;
	t.print();

	testChild ch;
	ch.print();

	test& refT = ch;
	refT.print();

	if (typeid(refT) == typeid(test)) {
		std::cout << "YEs, refs work" << std::endl;
	}*/

	//std::string str = "HP = " + std::to_string(12);
	//std::cout << str << std::endl;



	//sf::RenderWindow win(sf::VideoMode(1200, 900), "APP");
	//srand(time(NULL));
	//sf::Font font;
	//if (!font.loadFromFile("Freedom-10eM.ttf")) {
	//	std::cerr << "Error" << std::endl;
	//	exit(EXIT_FAILURE);
	//}

	//sf::Text text;
	//text.setFont(font);
	//text.setFillColor(sf::Color::Red);
	//text.setString("HP");
	//text.setCharacterSize(40);
	//text.setStyle(sf::Text::Bold);

	//while (win.isOpen()) {
	//	sf::Event event;

	//	while (win.pollEvent(event)) {

	//		if (event.type == sf::Event::Closed) {
	//			win.close();
	//			return 0;
	//		}

	//		win.clear();

	//		sf::Texture txt;
	//		txt.loadFromFile("bullet3.png");

	//		sf::Sprite spr;
	//		spr.setTexture(txt);

	//		int x = rand() % 1000;
	//		int y = rand() % 800;

	//		text.setPosition(x, y);

	//		win.draw(spr);
	//		win.draw(text);

	//		win.display();

	//		/*if (event.type == sf::Event::KeyReleased) {
	//			if (event.key.code == sf::Keyboard::Space) {
	//				std::cout << "the space key was pressed" << std::endl;
	//				std::cout << "control:" << event.key.control << std::endl;
	//				std::cout << "alt:" << event.key.alt << std::endl;
	//				std::cout << "shift:" << event.key.shift << std::endl;
	//				std::cout << "system:" << event.key.system << std::endl;
	//			}
	//		}*/
	//	}
	//}


	// Enemy* a = new Enemy2(100, 20, Point(10, 10), 0.12, MoveDir::Down);
	// std::cout << a->GetDamage() << std::endl;


	
}