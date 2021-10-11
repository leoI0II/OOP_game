#include"Field.hpp"
#include"CreateField.hpp"
#include<utility>


Field::Field() : cageArray(nullptr), width(0), height(0) {}

Field::~Field() {
    // if (cageArray){
    //     for (int i = 0; i < height; i++)
    //         delete[] cageArray[i];
    //     delete[] cageArray;
    // }
}

//FIXED
Field::Field(const Field& otherField) : width(otherField.width), height(otherField.height) {
    
    // cageArray = new FieldCage*[height];
    // for (int i = 0; i < height; i++){
    //     cageArray[i] = new FieldCage[width];
    //     for (int j = 0; j < width; j++)
    //         cageArray[i][j] = otherField.cageArray[i][j];
    // }

    cageArray = std::make_unique<cageArr_t[]>(height);

    for (int i = 0; i < height; i++){
        cageArray[i] = std::make_unique<FieldCage[]>(width);
        for (int j = 0; j < width; j++)
            cageArray[i][j] = otherField.cageArray[i][j];
    }
}

Field::Field(Field&& otherField) : Field() {
    std::swap(cageArray, otherField.cageArray);
    std::swap(height, otherField.height);
    std::swap(width, otherField.width);
}

Field::Field(CreateField creator)
    : cageArray(nullptr), width(creator.fieldW), height(creator.fieldH) {
    
    // std::swap(cageArray, creator.cages);
    cageArray.swap(creator.cages);          //or .release
}

Field& Field::operator=(const Field& otherField) {
    if (this == &otherField)
        return *this;
    if (cageArray){                                         //delete if smth
        for (int i = 0; i < height; i++)
            cageArray.reset();
    }
    width = otherField.width; height = otherField.height;
    
    // cageArray = new FieldCage*[height];
    // for (int i = 0; i < height; i++){
    //     cageArray[i] = new FieldCage[width];
    //     for (int j = 0; j < width; j++)
    //         cageArray[i][j] = otherField.cageArray[i][j];
    // }

    cageArray = std::make_unique<cageArr_t[]>(height);
    for (int i = 0; i < height; i++){
        cageArray[i] = std::make_unique<FieldCage[]>(width);
        for (int j = 0; j < width; j++)
            cageArray[i][j] = otherField.cageArray[i][j];
    }

    return *this;
}

Field& Field::operator=(Field&& otherField) {
    if (this != &otherField){
        std::swap(cageArray, otherField.cageArray);
        std::swap(height, otherField.height);
        std::swap(width, otherField.width);
    }
    return *this;
}

FieldCage& Field::getCage(int i, int j) {
    return cageArray[i][j];
}

Field::iterator Field::Cage(int i, int j){
    return iterator(*this, i, j);
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

// FieldCage** Field::begin(){
//     return static_cast<FieldCage**>(cageArray[0].get());
// }

// FieldCage** Field::end(){
//     return (cageArray[0].get() + height*sizeof(FieldCage*));
// }

