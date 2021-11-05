#ifndef POINT_HPP
#define POINT_HPP

class Point{
public:
    Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}

    const int GetX() const{
        return x;
    }
    
    const int GetY() const{
        return y;
    }
    
    Point& SetX(int _x){
        x = _x;
        return *this;
    }
    
    Point& SetY(int _y){
        y = _y;
        return *this;
    }
    Point& SetPosition(int _x, int _y){
        x = _x; y = _y;
        return *this;
    }
    Point& SetPosition(const Point& point){
        *this = point;
        return *this;
    }
    
    // friend const Point& operator+(const Point& a, const Point& b){
    //     return Point(a.x + b.x, a.y + b.y);
    // }

    // const Point& operator-(){
    //     return Point(-x, -y);
    // }


private:
    int x;
    int y;
};



#endif ///POINT_HPP