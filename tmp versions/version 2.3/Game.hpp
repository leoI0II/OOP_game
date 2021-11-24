// #pragma once
#ifndef GAME_HPP
#define GAME_HPP

#include"EntityView.hpp"
#include"Player.hpp"
#include"EnemyFactory.hpp"
#include"ItemFactory.hpp"
#include<list>
#include"GridView.hpp"
#include"Controller.hpp"
#include"PlayersBagView.hpp"

using pairEnemy = std::pair<Enemy*, EntityView*>;
using pairItem = std::pair<Item*, EntityView*>;
using pairBullet = std::pair<Bullet*, EntityView*>;

class Game
{
public:
    Game();
    ~Game();

    void HaveFun();

    void InitWindow();
    void InitGrid();
    void InitPlayer();
    void InitEnemies();
    void InitItems();
    void InitBag();

    bool IsWindowOpen();

    void UpdateObjects(double time);
    void RenderObjects();
    void Display();

private:
    sf::RenderWindow* window;

    Player* player;
    EntityView* playerView;

    // std::list<Enemy*>& enemies;
    std::list<pairEnemy> enemies;

    // std::list<Item*>& items;
    // std::list<std::pair<Item*, EntityView*>> items;
    std::list<pairItem> items;
    std::list<pairBullet> bullets;

    FieldGrid* grid;
    GridView* gridView;

    Controller* pControl;

    PlayersBagView* bagView;
};

#endif //GAME_HPP