// #pragma once
#ifndef ITEM_HPP
#define ITEM_HPP

#include"Entity.hpp"
// #include"Player.hpp"
#include"Weapon.hpp"
#include"Observable.hpp"

class Item : public Entity
{
public:
    Item(const Point& point = Point(0, 0));
    void SetPoint(const Point& point) override;
    Point GetPoint() const override;
    void SetPoint(double x, double y) override;
    double GetX() const override;
    double GetY() const override;
    void SetX(double x) override;
    void SetY(double y) override;
    void SetStateItem(bool st);
    bool GetStateItem() const;

private:
    Point position;
    bool state = true;
};

///////////////////////////////////////////////////////////////////

class LittleHealthBottle : public Item {
public:
    LittleHealthBottle(const Point& point = Point(0, 0));
    void Interact(Entity* ch) override;
private:
};

///////////////////////////////////////////////////////////////////

class Ammo : public Item {
public:
    Ammo(const Point& point = Point(0, 0));
    void Interact(Entity* wp) override;
private:
};

///////////////////////////////////////////////////////////////////

class BigHealthBottle : public Item {
public:
    BigHealthBottle(const Point& point = Point(0, 0));
    void Interact(Entity* ch) override;
private:

};

#endif //ITEM_HPP