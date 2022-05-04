// #pragma once
#ifndef GAME_HPP
#define GAME_HPP

#define _CRT_SECURE_NO_WARNINGS
#include"EntityView.hpp"
#include"Player.hpp"
#include"EnemyFactory.hpp"
#include"ItemFactory.hpp"
#include<list>
#include<vector>
#include"GridView.hpp"
#include"PlayersBagView.hpp"
#include"CAFLogger.hpp"
#include<chrono>
#include<ctime>
#include"GameStats.hpp"
#include"EnemyKillerEvent.hpp"
#include"TimeEvent.hpp"
#include"SFML_CommandHandler.hpp"
#include"Controller.hpp"

using pairEnemy = std::pair<Enemy*, EntityView*>;
using pairItem = std::pair<Item*, EntityView*>;
using pairBullet = std::pair<Bullet*, EntityView*>;

struct PlayerSaver {
    int Hp;
    int dam;
    Point pos;
    double sp;
    MoveDir ms;
    size_t LHBC;
    size_t BHBC;
    size_t AC;
    Weapon wp;
    MoveDir cd;
    bool fs;
};

template<class TimeEv, class EKE>
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
    //void InitLogger();
    void InitStats();

    bool IsWindowOpen();

    void UpdateObjects(double time);
    void RenderObjects();
    void Display();
    void PrintLog();
    bool checkTimeEvents();
    bool checkEKE();

    void SaveGame();
    void LoadGame();

    Player* GetPlayer();

private:
    sf::RenderWindow* window;

    Player* player;
    EntityView* playerView;

    // std::list<Enemy*>& enemies;
    std::vector<pairEnemy> enemies;

    // std::list<Item*>& items;
    // std::list<std::pair<Item*, EntityView*>> items;
    std::vector<pairItem> items;

    FieldGrid* grid;
    GridView* gridView;

    Controller* controller;

    PlayersBagView* bagView;

    GameStats* stats;

    TimeEv* timeEvent;
    EKE* eke;

    std::chrono::seconds dur;
};

#endif //GAME_HPP

template<class TimeEv, class EKE>
Game<TimeEv, EKE>::Game()
{
    InitGrid();
    InitPlayer();

    srand(time(NULL));

    InitEnemies();
    InitItems();

    InitBag();
    InitStats();

    timeEvent = new TimeEv();
    eke = new EKE();

    InitWindow();
}

template<class TimeEv, class EKE>
Game<TimeEv, EKE>::~Game()
{
    delete window;

    /*delete player;
    delete playerView;

    for (auto it = enemies.begin(); it != enemies.end(); ++it) {
        delete it->first;
        delete it->second;
    }
    for (auto it = items.begin(); it != items.end(); ++it) {
        delete it->first;
        delete it->second;
    }
    for (auto it = bullets.begin(); it != bullets.end(); ++it) {
        delete it->first;
        delete it->second;
    }

    delete grid;
    delete gridView;

    delete controller;
    delete bagView;*/
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::HaveFun()
{
    stats->startTime();

    sf::Clock clock;
    while (IsWindowOpen()) {
        /*double time = clock.getElapsedTime().asMicroseconds();*/
        int time = clock.restart().asMilliseconds();
        //clock.restart();
        //time = time / 1200;
        window->setFramerateLimit(60);

        sf::Event event;

        while (window->pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window->close();
                return;
            }
            if (event.type == sf::Event::KeyReleased) {
                if (event.key.code == sf::Keyboard::Z)
                    SaveGame();
                else if (event.key.code == sf::Keyboard::X)
                    LoadGame();
            }
        }
        if (checkTimeEvents()) {
            window->close();
            return;
        }
        if (checkEKE()) {
            window->close();
            return;
        }

        //Log
        //PrintLog();

        //UpdateStates
        UpdateObjects(time);

        //Render
        RenderObjects();

        //Display
        Display();
    }
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::InitWindow()
{
    window = new sf::RenderWindow(sf::VideoMode(grid->getWidth() * (int)TileSize::Size,
        grid->getHeight() * (int)TileSize::Size), "Game");
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::InitGrid()
{
    GridCreator creator;
    grid = new FieldGrid(creator);
    gridView = new GridView(*grid);
    gridView->loadPicsFromFile();
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::InitPlayer()
{
    Point tmp = grid->GetStartPosition();
    //std::cout << tmp.GetX() << " " << tmp.GetY() << std::endl;
    //tmp.SetPosition(tmp.GetX() + int(TileSize::Size)/2, tmp.GetY() + int(TileSize::Size) / 2);
    //std::cout << tmp.GetX() << " " << tmp.GetY() << std::endl;
    player = new Player(600, 30, tmp, 0.2);
    playerView = new EntityView(player, "P.png");
    controller = new Controller(player, new SFML_CommandHandler);
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::InitEnemies()
{
    Enemy1Fact enemy1F;
    Enemy2Fact enemy2F;
    Enemy3Fact enemy3F;

    Enemy* en1 = enemy1F.CreateEnemy(*grid);
    Enemy* en2 = enemy2F.CreateEnemy(*grid);
    Enemy* en3 = enemy3F.CreateEnemy(*grid);

    enemies.push_back(std::make_pair(en1, new EntityView(en1, "E1.png")));
    enemies.push_back(std::make_pair(en2, new EntityView(en2, "E2.png")));
    enemies.push_back(std::make_pair(en3, new EntityView(en3, "E3.png")));
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::InitItems()
{
    LittleHealthBottleFactory LHBF;
    BigHealthBottleFactory BHBF;
    AmmoFactory AF;

    Item* lh = LHBF.CreateItem(*grid);
    Item* bh = BHBF.CreateItem(*grid);
    Item* am = AF.CreateItem(*grid);

    items.push_back(std::make_pair(lh, new EntityView(lh, "L.png")));
    items.push_back(std::make_pair(bh, new EntityView(bh, "B.png")));
    items.push_back(std::make_pair(am, new EntityView(am, "A.png")));
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::InitBag()
{
    bagView = new PlayersBagView(player->GetBag(), *grid);
}

//template<class TimeEv, class EKE>
//void Game<TimeEv, EKE>::InitLogger()
//{
//    logger = new Logger<LogType::BOTH>();
//}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::InitStats()
{
    stats = new GameStats(GetPlayer());
}

template<class TimeEv, class EKE>
bool Game<TimeEv, EKE>::IsWindowOpen()
{
    return window->isOpen();
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::UpdateObjects(double time)
{
    std::vector<pairEnemy>::iterator EnemyIter;
    std::vector<pairItem>::iterator ItemIter;

    controller->Control();
    player->Update(time, *grid, playerView->getSizeX(), playerView->getSizeY());
    if (player->GetHP() <= 0) {
        window->close();
        return;
    }
    if (grid->GetTile(player->GetY() / int(TileSize::Size),
        player->GetX() / int(TileSize::Size)).GetType() == Type::Exit) {

        std::cout << "Finish was reached!!" << std::endl << "Congratulation!" << std::endl;
        window->close();
        return;
    }
    //std::cout << "Player current tile " << player->GetY() / int(TileSize::Size) <<
    //    " " << player->GetX() / int(TileSize::Size) << std::endl;
    //int i = 0;
    for (EnemyIter = enemies.begin(); EnemyIter != enemies.end(); /*++EnemyIter*/) {
        EnemyIter->first->Update(time, *grid, EnemyIter->second->getSizeX(), EnemyIter->second->getSizeY());
        if (EnemyIter->first->GetHP() <= 0) {
            EnemyIter = enemies.erase(EnemyIter);
            stats->kill();
            continue;
        }
        ++EnemyIter;
        //std::cout << "Enemy" << i++ << " " << EnemyIter->first << " current tile " <<
        //    EnemyIter->first->GetY() / int(TileSize::Size) << " " << EnemyIter->first->GetX() / int(TileSize::Size)
        //    << " Current health " << EnemyIter->first->GetHP() << std::endl;
    }
    for (ItemIter = items.begin(); ItemIter != items.end(); ) {
        if (!ItemIter->first->GetStateItem()) {
            ItemIter = items.erase(ItemIter);
            continue;
        }
        ++ItemIter;
    }
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::RenderObjects()
{
    std::vector<pairEnemy>::iterator EnemyIter;
    std::vector<pairItem>::iterator ItemIter;

    window->clear();

    gridView->draw(*window);
    for (ItemIter = items.begin(); ItemIter != items.end(); ++ItemIter) {
        ItemIter->second->updateView(*window, *grid);
    }
    for (EnemyIter = enemies.begin(); EnemyIter != enemies.end(); ++EnemyIter) {
        EnemyIter->second->updateView(*window, *grid);
    }
    playerView->updateView(*window, *grid);

    bagView->UpdateView(*window);
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::Display()
{
    window->display();
}

template<class TimeEv, class EKE>
void Game<TimeEv, EKE>::PrintLog()
{
    player->Notify();

    for (auto& enemy : enemies)
        enemy.first->Notify();
}

template<class TimeEv, class EKE>
bool Game<TimeEv, EKE>::checkTimeEvents()
{
    auto tmpEnd = std::chrono::steady_clock::now();
    dur = std::chrono::duration_cast<std::chrono::seconds>(tmpEnd - stats->GetStartTime());
    if ((*timeEvent)(dur)) {
        std::cout << "You Lose!" << std::endl;
        return true;
    }
    return false;
}

template<class TimeEv, class EKE>
bool Game<TimeEv, EKE>::checkEKE()
{
    if ((*eke)(stats->getHowMuchKills())) {
        std::cout << "Its enough! Congrats! You win!" << std::endl;
        return true;
    }
    return false;
}

template<class TimeEv, class EKE>
inline void Game<TimeEv, EKE>::SaveGame()
{
    std::ofstream file("game.data", std::ofstream::binary);

    PlayerSaver ps{ player->GetHP(), player->GetDamage(), player->GetPoint(), player->GetSpeed(),
                    player->GetDirection(), player->GetBag()[typeid(LittleHealthBottle)].size(),
                    player->GetBag()[typeid(BigHealthBottle)].size(), player->GetBag()[typeid(Ammo)].size(),
                    player->GetWeapon(), player->GetPlayerCheckingDirection(), player->GetFireState() };

    file.write((char*)(&ps), sizeof(PlayerSaver));
    
    uint8_t enemy_count = enemies.size();
    file.write((char*)(&enemy_count), sizeof(uint8_t));

    for (int i = 0; i < enemy_count; ++i) {
        EnemyType tp = enemies[i].first->GetType();
        file.write((char*)(&tp), sizeof(EnemyType));

        if (tp == EnemyType::enemy1) {
            file.write((char*)(enemies[i].first), sizeof(Enemy1));
        }
        else if (tp == EnemyType::enemy2) {
            file.write((char*)(enemies[i].first), sizeof(Enemy2));
        }
        else if (tp == EnemyType::enemy3) {
            file.write((char*)(enemies[i].first), sizeof(Enemy3));
        }
    }

    uint8_t item_count = items.size();
    file.write((char*)(&item_count), sizeof(uint8_t));

    for (int i = 0; i < item_count; ++i) {
        ItemType tp;
        if (typeid(*(items[i].first)) == typeid(LittleHealthBottle)) {
            tp = ItemType::LittleHealthBottle;
            file.write((char*)(&tp), sizeof(ItemType));
            file.write((char*)(items[i].first), sizeof(LittleHealthBottle));
        }
        else if (typeid(*(items[i].first)) == typeid(BigHealthBottle)) {
            tp = ItemType::BigHealthBottle;
            file.write((char*)(&tp), sizeof(ItemType));
            file.write((char*)(items[i].first), sizeof(BigHealthBottle));
        }
        else if (typeid(*(items[i].first)) == typeid(Ammo)) {
            tp = ItemType::Ammo;
            file.write((char*)(&tp), sizeof(ItemType));
            file.write((char*)(items[i].first), sizeof(Ammo));
        }
    }

    file.write((char*)(&dur), sizeof(std::chrono::seconds));

    file.close();
}

template<class TimeEv, class EKE>
inline void Game<TimeEv, EKE>::LoadGame()
{
    delete player;
    delete playerView;

    std::ifstream file("game.data", std::ios::binary);

    if (!file.is_open())
        return;

    PlayerSaver ps{ 0 };
    file.read((char*)(&ps), sizeof(PlayerSaver));
    player = new Player(ps.Hp, ps.dam, ps.pos, ps.sp, 50, ps.ms, ps.cd);
    player->SetFireState(ps.fs);
    player->GetWeapon() = ps.wp;

    for (int i = 0; i < ps.LHBC; ++i) {
        player->AddToBag(new LittleHealthBottle);
    }
    for (int i = 0; i < ps.BHBC; ++i) {
        player->AddToBag(new BigHealthBottle);
    }
    for (int i = 0; i < ps.AC; ++i) {
        player->AddToBag(new Ammo);
    }

    grid->GetTile(player->GetY() / int(TileSize::Size), player->GetX() / int(TileSize::Size)).putPlayer(player);

    playerView = new EntityView(player, "P.png");

    for (int i = 0; i < enemies.size(); ++i) {
        delete enemies[i].first;
        delete enemies[i].second;
    }
    enemies.clear();

    uint8_t enemy_count;
    file.read((char*)(&enemy_count), sizeof(uint8_t));

    for (int i = 0; i < enemy_count; ++i) {
        EnemyType tp;
        file.read((char*)(&tp), sizeof(EnemyType));

        if (tp == EnemyType::enemy1) {
            Enemy1* en = new Enemy1;
            file.read((char*)(en), sizeof(Enemy1));
            enemies.push_back(std::make_pair(en, new EntityView(en, "E1.png")));
            grid->GetTile(en->GetY() / int(TileSize::Size), en->GetX() / int(TileSize::Size)).putEnemy(en);
        }
        else if (tp == EnemyType::enemy2) {
            Enemy2* en = new Enemy2;
            file.read((char*)(en), sizeof(Enemy2));
            enemies.push_back(std::make_pair(en, new EntityView(en, "E2.png")));
            grid->GetTile(en->GetY() / int(TileSize::Size), en->GetX() / int(TileSize::Size)).putEnemy(en);
        }
        else if (tp == EnemyType::enemy3) {
            Enemy3* en = new Enemy3;
            file.read((char*)(en), sizeof(Enemy3));
            enemies.push_back(std::make_pair(en, new EntityView(en, "E3.png")));
            grid->GetTile(en->GetY() / int(TileSize::Size), en->GetX() / int(TileSize::Size)).putEnemy(en);
        }
    }

    for (int i = 0; i < items.size(); ++i) {
        delete items[i].first;
        delete items[i].second;
    }
    items.clear();

    uint8_t item_count;
    file.read((char*)(&item_count), sizeof(uint8_t));

    for (int i = 0; i < item_count; ++i) {
        ItemType tp;
        file.read((char*)(&tp), sizeof(ItemType));

        if (tp == ItemType::LittleHealthBottle) {
            LittleHealthBottle* it = new LittleHealthBottle;
            file.read((char*)(it), sizeof(LittleHealthBottle));
            items.push_back(std::make_pair(it, new EntityView(it, "L.png")));
            grid->GetTile(it->GetY() / int(TileSize::Size), it->GetX() / int(TileSize::Size)).putItem(it);
        }
        else if (tp == ItemType::BigHealthBottle) {
            BigHealthBottle* it = new BigHealthBottle;
            file.read((char*)(it), sizeof(BigHealthBottle));
            items.push_back(std::make_pair(it, new EntityView(it, "B.png")));
            grid->GetTile(it->GetY() / int(TileSize::Size), it->GetX() / int(TileSize::Size)).putItem(it);
        }
        else if (tp == ItemType::Ammo) {
            Ammo* it = new Ammo;
            file.read((char*)(it), sizeof(Ammo));
            items.push_back(std::make_pair(it, new EntityView(it, "A.png")));
            grid->GetTile(it->GetY() / int(TileSize::Size), it->GetX() / int(TileSize::Size)).putItem(it);
        }
    }

    delete controller;
    controller = new Controller(player, new SFML_CommandHandler);

    delete bagView;
    bagView = new PlayersBagView(player->GetBag(), *grid);

    std::chrono::seconds return_time;
    file.read((char*)(&return_time), sizeof(std::chrono::seconds));
    dur = return_time;

    file.close();
}

template<class TimeEv, class EKE>
Player* Game<TimeEv, EKE>::GetPlayer()
{
    return player;
}
