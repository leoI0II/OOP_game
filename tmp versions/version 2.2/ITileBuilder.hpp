#pragma once

#include"Point.hpp"
#include<memory>
#include"Tile.hpp"

class ITileBuilder
{
public:
    virtual ~ITileBuilder() {}
    virtual void SetPosition(const Point&) = 0;
    virtual void SetTileType() = 0;
    virtual void SetTileStatus() = 0;
    virtual Tile GetTile() = 0;
};

