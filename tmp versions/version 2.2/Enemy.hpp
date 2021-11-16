#pragma once

#include"Character.hpp"
#include"FieldGrid.hpp"

enum class EnemyType { enemy1, enemy2, enemy3 };

class Enemy : public Character
{
public:
    Enemy(int HP, int dmg, const Point& point, double sp, MoveDir ms = MoveDir::Stay, EnemyType tp = EnemyType::enemy1);

    ~Enemy();

    void UseItem(ItemType);
    EnemyType GetType() const;
    void SetType(EnemyType tp);

private:
    EnemyType type;
};

///////////////////////////////////////////////////////////////////

class Enemy1 : public Enemy {
public:
    Enemy1(int HP, int dmg, const Point& point, double sp, MoveDir ms = MoveDir::Right);

    void Update(double time, FieldGrid& grid, const float& chSizeX, const float& chSizeY) override;
    bool InteractionWithGrid(FieldGrid& grid, double& dx, double& dy, const float& chSizeX, const float& chSizeY) override;

private:
};

///////////////////////////////////////////////////////////////////

class Enemy2 : public Enemy {
public:
    Enemy2(int HP, int dmg, const Point& point, double sp, MoveDir ms = MoveDir::Up);

    void Update(double time, FieldGrid& grid, const float& chSizeX, const float& chSizeY) override;
    bool InteractionWithGrid(FieldGrid& grid, double& dx, double& dy, const float& chSizeX, const float& chSizeY) override;

private:
};

///////////////////////////////////////////////////////////////////

class Enemy3 : public Enemy {
public:
    Enemy3(int HP, int dmg, const Point& point, double sp, MoveDir ms = MoveDir::Up);

    void Update(double _time, FieldGrid& grid, const float& chSizeX, const float& chSizeY) override;
    bool InteractionWithGrid(FieldGrid& grid, double& dx, double& dy, const float& chSizeX, const float& chSizeY) override;

private:
};

///////////////////////////////////////////////////////////////////