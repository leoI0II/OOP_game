#ifndef CREATE_FIELD_HPP
#define CREATE_FIELD_HPP

#include"FieldCage.hpp"
#include"Field.hpp"

class Field;

class CreateField {
    FieldCage** cages;
    int fieldH;
    int fieldW;
    void findParams(const char* fp);
public:
    CreateField(const char* filePath);
    ~CreateField();

    // const FieldCage** getCages();
    // int fieldHeight();
    // int fieldWidth();
    friend class Field;         //???? friend class Field::Field(CreateField&);
};

#endif //CREATE_FIELD_HPP