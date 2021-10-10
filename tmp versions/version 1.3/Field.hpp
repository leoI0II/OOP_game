#ifndef FIELD_HPP
#define FIELD_HPP

#include"FieldCage.hpp"
#include"CreateField.hpp"   //зависимость

class CreateField;

class Field {
public:
    friend class CreateField;
    Field();
    //Field(CreateField& creator);
    Field(const Field& otherField);
    Field(Field&& otherField);
    ~Field();

    Field& operator=(const Field& otherField);
    Field& operator=(Field&& otherField);

    FieldCage& getCage(int x, int y);

    const int Height() const;
    const int Width() const;

private:
    FieldCage** cageArray;
    static int width;   //1200 = 20 * 60
    static int height;  //900 = 15 * 60
};

#endif //FIELD_HPP