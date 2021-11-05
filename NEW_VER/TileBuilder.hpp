#ifndef TILEBUILDER_HPP
#define TILEBUILDER_HPP

#include"ITileBuilder.hpp"

class ExitTileBuilder : public ITileBuilder{
public:
    ExitTileBuilder(){
        Reset();
    }
    ~ExitTileBuilder(){}

    void Reset(){
        if (tile) delete tile;
        tile = new Tile;
    }

    Tile GetTile(){
        Tile res = *tile;
        Reset();
        return res;
    }

    void SetTileType(){
        tile->SetType(Type::Exit);
    }
    void SetTileStatus(){
        tile->SetStatus(Status::Available);
    }
    void SetPosition(const Point& point){
        tile->SetPosition(point);
    }

private:
    Tile* tile;
};


class EntryTileBuilder : public ITileBuilder{
public:
    EntryTileBuilder(){
        Reset();
    }
    ~EntryTileBuilder(){}

    void Reset(){
        tile = new Tile;
    }

    Tile GetTile(){
        Tile res = *tile;
        Reset();
        return res;
    }

    void SetTileType(){
        tile->SetType(Type::Entry);
    }
    void SetTileStatus(){
        tile->SetStatus(Status::Available);
    }
    void SetPosition(const Point& point){
        tile->SetPosition(point);
    }

private:
    Tile* tile;
};

class CommonTileBuilder : public ITileBuilder{
public:
    CommonTileBuilder(){
        Reset();
    }
    ~CommonTileBuilder(){}

    void Reset(){
        tile = new Tile;
    }

    Tile GetTile(){
        Tile res = *tile;
        Reset();
        return res;
    }

    void SetTileType(){
        tile->SetType(Type::Common);
    }
    void SetTileStatus(){
        tile->SetStatus(Status::Available);
    }
    void SetPosition(const Point& point){
        tile->SetPosition(point);
    }

private:
    Tile* tile;
};

class WallTileBuilder : public ITileBuilder{
public:
    WallTileBuilder(){
        Reset();
    }

    ~WallTileBuilder(){}

    void Reset(){
        tile = new Tile;
    }

    Tile GetTile(){
        Tile res = *tile;
        Reset();
        return res;
    }

    void SetTileType(){
        tile->SetType(Type::Wall);
    }
    void SetTileStatus(){
        tile->SetStatus(Status::NotAvailable);
    }
    void SetPosition(const Point& point){
        tile->SetPosition(point);
    }

private:
    Tile* tile;
};

#endif