#ifndef FIELD_HPP
#define FIELD_HPP

#include"FieldCage.hpp"
#include"CreateField.hpp"

class CreateField;

class Field {
public:

    Field();
    Field(CreateField creator);
    Field(const Field& otherField);
    Field(Field&& otherField);
    ~Field();

    Field& operator=(const Field& otherField);
    Field& operator=(Field&& otherField);

    FieldCage& getCage(int i = 0, int j = 0);

    FieldCage** begin();
    FieldCage** end();
    const int getHeight();
    const int getWidth();
    Field& setHeight(int newHeight);
    Field& setWidth(int newWidth);

    // friend CreateField::CreateField(const char* fp);

    class iterator{
    public:
        iterator(FieldCage** begin = nullptr) : cagePtr(begin), i_pos(0), j_pos(0) {}
        iterator(iterator& cpy) : cagePtr(cpy.cagePtr), i_pos(cpy.i_pos), j_pos(cpy.j_pos){}
        ~iterator(){ /*std::cout << "DESTRUCTOR" << std::endl;*/}

        FieldCage& operator*(){
            return cagePtr[i_pos][j_pos];
        }

        iterator& operator++(){
            change_poses();
            return *this;
        }
        iterator operator++(int){
            iterator tmp(*this);
            change_poses();
            return tmp;
        }

        bool operator!=(FieldCage** end) const{
            return (cagePtr + i_pos*sizeof(FieldCage*)) != end;
        }

    private:
        FieldCage** cagePtr;
        int i_pos;
        int j_pos;
        
        void change_poses(){
            j_pos++;
            if (j_pos == 20){
                i_pos++; j_pos = 0; return;
            }
        }
    };
private:
    FieldCage** cageArray;
    int width;   //1200 = 20 * 60
    int height;  //900 = 15 * 60
};

#endif //FIELD_HPP