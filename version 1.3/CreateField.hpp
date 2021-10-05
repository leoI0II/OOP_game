#ifndef CREATE_FIELD_HPP
#define CREATE_FIELD_HPP

#include"FieldCage.hpp"
// #include"Field.hpp"

class CreateField{
    FieldCage** cages;
    // FieldCage** getField();
public:
    CreateField(const char* filePath);
    ~CreateField(){}
    FieldCage** getField();

    // friend class Field;         //???? friend class Field::Field(CreateField&);
};

#endif //CREATE_FIELD_HPP