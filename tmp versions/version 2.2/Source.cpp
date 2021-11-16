//#include <SFML/Graphics.hpp>
//
//using namespace sf;
//
//int main()
//{
//	// Объект, который, собственно, является главным окном приложения
//	RenderWindow window(VideoMode(200, 200), "SFML Works!");
//
//	// Главный цикл приложения. Выполняется, пока открыто окно
//	while (window.isOpen())
//	{
//		// Обрабатываем очередь событий в цикле
//		Event event;
//		while (window.pollEvent(event))
//		{
//			// Пользователь нажал на «крестик» и хочет закрыть окно?
//			if (event.type == Event::Closed)
//				// тогда закрываем его
//				window.close();
//		}
//
//		window.clear(Color(250, 220, 100, 0));
//		// Отрисовка окна	
//		window.display();
//	}
//
//	return 0;
//}

#include"Game.hpp"

int main() {


	/*Game game;
	game.HaveFun();*/

	Enemy* a = new Enemy2(100, 20, Point(10, 10), 0.12, MoveDir::Down);
	std::cout << a->GetDamage() << std::endl;


	return 0;
}