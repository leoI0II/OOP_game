#include"FieldCage.hpp"
// #include<iostream>

FieldCage::FieldCage(int x, int y, Type tp, Status st)
    : x_coord(x), y_coord(y), type(tp), status(st) {}

Status& FieldCage::cageStatus(){
    return status;
}

Type& FieldCage::cageType(){
    return type;
}

int FieldCage::getX() const{
    return x_coord;
}

FieldCage& FieldCage::setX(int x){
    x_coord = x;
    return *this;
}

int FieldCage::getY() const{
    return y_coord;
}

FieldCage& FieldCage::setY(int y){
    y_coord = y;
    return *this;
}

void FieldCage::method(){}
