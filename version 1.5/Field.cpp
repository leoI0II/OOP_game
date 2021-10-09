#include"Field.hpp"
#include"CreateField.hpp"
#include<utility>

// int Field::height = 15;
// int Field::width = 20;

Field::Field() {
    cageArray = new FieldCage * [height];
    for (int i = 0; i < height; i++)
        cageArray[i] = new FieldCage[width];
}

Field::~Field() {
    for (int i = 0; i < height; i++)
        delete[] cageArray[i];
    delete[] cageArray;
}

//FIXED
Field::Field(const Field& otherField) : Field() {
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            cageArray[i][j] = otherField.cageArray[i][j];
}

Field::Field(Field&& otherField) : Field(){
    std::swap(cageArray, otherField.cageArray);
}

Field::Field(CreateField creator)
    : cageArray(nullptr), width(creator.fieldW), height(creator.fieldH) {
    
    std::swap(cageArray, creator.cages);
}

Field& Field::operator=(const Field& otherField) {
    if (this == &otherField)
        return *this;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            cageArray[i][j] = otherField.cageArray[i][j];
    return *this;
}

Field& Field::operator=(Field&& otherField) {
    if (this != &otherField){
        std::swap(cageArray, otherField.cageArray);
    }
    return *this;
}

FieldCage& Field::getCage(int i, int j) {
    return cageArray[i][j];
}

//FIXED
const int Field::getHeight() {
    return height;
}

Field& Field::setHeight(int newH) { height = newH; return *this; }

const int Field::getWidth() {
    return width;
}

Field& Field::setWidth(int newW) { width = newW; return *this; }

FieldCage** Field::begin(){
    return cageArray;
}

FieldCage** Field::end(){
    return cageArray + height*sizeof(FieldCage*);
}

