#pragma once

#include"Item.hpp"

class ItemFactory
{
public:
    virtual Item* CreateItem(FieldGrid&) = 0;
protected:
    Point randomizer(FieldGrid& grid);
};

///////////////////////////////////////////////////////////////////////////////////

class LittleHealthBottleFactory : public ItemFactory {
public:
    Item* CreateItem(FieldGrid& grid) override;
};

///////////////////////////////////////////////////////////////////////////////////

class BigHealthBottleFactory : public ItemFactory {
public:
    Item* CreateItem(FieldGrid& grid) override;
};

///////////////////////////////////////////////////////////////////////////////////

class AmmoFactory : public ItemFactory {
public:
    Item* CreateItem(FieldGrid& grid) override;
};

///////////////////////////////////////////////////////////////////////////////////