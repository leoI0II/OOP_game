#ifndef CREATE_FIELD_HPP
#define CREATE_FIELD_HPP

#include"FieldCage.hpp"
#include"Field.hpp"

class Field;

class CreateField {
    FieldCage** cages;
public:
    CreateField(const char* filePath);
    ~CreateField();

    friend class Field;         //???? friend class Field::Field(CreateField&);
};

#endif //CREATE_FIELD_HPP