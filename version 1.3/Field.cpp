#include"Field.hpp"
#include"CreateField.hpp"
#include<utility>

int Field::height = 15;
int Field::width = 20;

Field::Field(){
    cageArray = new FieldCage*[height];
    for (int i = 0; i < height; i++)
        cageArray[i] = new FieldCage[width];
}

Field::~Field(){
    for (int i = 0; i < height; i++)
        delete [] cageArray[i];
    delete [] cageArray;
}

Field::Field(const Field& otherField) : Field(){
    *this = otherField;
}

Field::Field(Field&& otherField){
    std::swap(cageArray, otherField.cageArray);
}

Field::Field(CreateField& creator){
    // cageArray = creator.cages;
    cageArray = creator.getField();
}

Field& Field::operator=(const Field& otherField){
    if (this == &otherField)
        return *this;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            cageArray[i][j] = otherField.cageArray[i][j];
    return *this;
}

Field& Field::operator=(Field&& otherField){
    if (this != &otherField)
        std::swap(cageArray, otherField.cageArray);
    return *this;
}

FieldCage& Field::getCage(int x, int y){
    return cageArray[x][y];
}

const int Field::Height() const{
    return height;
}

const int Field::Width() const{
    return width;
}