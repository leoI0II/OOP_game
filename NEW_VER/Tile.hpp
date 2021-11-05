#ifndef TILE_HPP
#define TILE_HPP

#include"Point.hpp"

enum class Status {NotAvailable, Available};
enum class Type {Exit, Common, Entry, Wall};
enum class TileSize {Size = 60};

class Tile : private Point {
public:
    Tile(int x = 0, int y = 0) : Point(x, y) {}
    Tile(const Point& point) : Point(point) {}

    using Point::GetX;
    using Point::GetY;
    using Point::SetX;
    using Point::SetY;
    using Point::SetPosition;

    const Status GetStatus() const{
        return status;
    }
    const Type GetType() const{
        return type;
    }

    const Tile& SetType(Type _type){
        type = _type;
        return *this;
    }
    const Tile& SetStatus(Status _status){
        status = _status;
        return *this;
    }

private:
    Type type;
    Status status;
};




#endif ///TILE_HPP