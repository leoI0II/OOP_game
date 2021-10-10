#include"Field.hpp"
#include"CreateField.hpp"
#include<utility>
#include<memory>

int Field::height = 15;
int Field::width = 20;

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

Field::Field(const Field& otherField) : Field() {
    *this = otherField;
}

Field::Field(Field&& otherField) {
    std::swap(cageArray, otherField.cageArray);
}

/*Field::Field(CreateField& creator) {
    // cageArray = creator.cages;
    std::swap(cageArray, creator.cages);
}*/

Field& Field::operator=(const Field& otherField) {
    if (this == &otherField)
        return *this;
    for (int i = 0; i < height; i++)
        for (int j = 0; j < width; j++)
            cageArray[i][j] = otherField.cageArray[i][j];
    return *this;
}

Field& Field::operator=(Field&& otherField) {
    if (this != &otherField)
        std::swap(cageArray, otherField.cageArray);
    return *this;
}

FieldCage& Field::getCage(int i, int j) {
    return cageArray[i][j];
}

const int Field::Height() const {
    return height;
}

const int Field::Width() const {
    return width;
}

FieldCage** Field::begin(){
    return cageArray;
}

FieldCage** Field::end(){
    return cageArray + height*sizeof(FieldCage*);
}

// class Field::iterator{
// public:
//     iterator(FieldCage** begin = nullptr) : cagePtr(begin){}
//     ~iterator(){}

//     const FieldCage* operator*(){
//         return cagePtr[i_pos] + j_pos*sizeof(FieldCage);
//     }

//     void operator++(){           //prefix
//         check_pos();
//     }

//     bool operator!=(FieldCage* end){
//         return (*(cagePtr + i_pos*sizeof(FieldCage*)) + j_pos*sizeof(FieldCage)) != end;
//     }

// private:
//     FieldCage** cagePtr;
//     int i_pos = 0;
//     int j_pos = 0;
    
//     void check_pos(){
//         if (j_pos == 20){
//             i_pos++; j_pos = 0;
//         }
//         j_pos++;
//     }
// };