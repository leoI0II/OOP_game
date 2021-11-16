#pragma once

#include"Point.hpp"
#include<string>
#include<fstream>
#include<sstream>
#include"Exceptions.hpp"
#include<iostream>
#include"BuildDirector.hpp"

using tileArr_t = std::shared_ptr<Tile[]>;
using grid_t = std::shared_ptr<tileArr_t[]>;

class GridCreator
{
public:
    GridCreator();

    grid_t& GetGrid();
    int GetHeight();
    int GetWidth();
    Point& GetStartPos();
    Point& GetEndPos();

    ~GridCreator() {
        if (tiles) {
            for (int i = 0; i < gridHeight; i++)
                tiles[i].reset();
            tiles.reset();
        }
    }

private:
    grid_t tiles;
    int gridHeight;
    int gridWidth;
    Point startPosition;
    Point endPosition;

    const std::string TakeFile();

    void FindParams(std::ifstream& file);
};

