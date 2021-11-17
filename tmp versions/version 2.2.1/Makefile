all: PROJECT
PROJECT: Point.o Exceptions.o Character.o Weapon.o Bullet.o Player.o Item.o Enemy.o Tile.o TileBuilder.o BuildDirector.o GridCreator.o FieldGrid.o ItemFactory.o EnemyFactory.o GridView.o EntityView.o Controller.o Game.o Source.o
	g++ -o newGame Point.o Exceptions.o Character.o Weapon.o Bullet.o Player.o Item.o Enemy.o Tile.o TileBuilder.o BuildDirector.o GridCreator.o FieldGrid.o ItemFactory.o EnemyFactory.o GridView.o EntityView.o Controller.o Game.o Source.o
Source.o:
	g++ -c Source.cpp
Game.o:
	g++ -c Game.cpp
Controller.o:
	g++ -c Controller.cpp
EntityView.o:
	g++ -c EntityView.cpp
GridView.o:
	g++ -c GridView.cpp
EnemyFactory.o:
	g++ -c EnemyFactory.cpp
ItemFactory.o:
	g++ -c ItemFactory.cpp
FieldGrid.o:
	g++ -c FieldGrid.cpp
GridCreator.o:
	g++ -c GridCreator.cpp
BuildDirector.o:
	g++ -c BuildDirector.cpp
TileBuilder.o:
	g++ -c TileBuilder.cpp
Tile.o:
	g++ -c Tile.cpp
Enemy.o:
	g++ -c Enemy.cpp
Item.o:
	g++ -c Item.cpp
Player.o:
	g++ -c Player.cpp
Bullet.o:
	g++ -c Bullet.cpp
Weapon.o:
	g++ -c Weapon.cpp
Character.o: FieldGrid.hpp
	g++ -c Character.cpp
Exceptions.o:
	g++ -c Exceptions.cpp
Point.o:
	g++ -c Point.cpp
clean:
	rm -rf *.o
