#ifndef FIELD_HPP
#define FIELD_HPP

#include"FieldCage.hpp"
#include"CreateField.hpp"
#include<memory>

using cageArr_t = std::unique_ptr<FieldCage[]>;
using field_t = std::unique_ptr<cageArr_t[]>;


class CreateField;

class Field {
public:

    class iterator;

    Field();
    Field(CreateField creator);
    Field(const Field& otherField);
    Field(Field&& otherField);
    ~Field();

    Field& operator=(const Field& otherField);
    Field& operator=(Field&& otherField);

    FieldCage& getCage(int i = 0, int j = 0);
    Field::iterator Cage(int i = 0, int j = 0);

    FieldCage** begin(){}
    FieldCage** end();
    const int getHeight();
    const int getWidth();
    Field& setHeight(int newHeight);
    Field& setWidth(int newWidth);

    // friend CreateField::CreateField(const char* fp);

    class iterator{
    public:
        iterator() : cagePtr(nullptr), i_pos(0), j_pos(0), widthF(0) {}
        iterator(Field& field, int i = 0, int j = 0){
            cagePtr = field.begin();
            i_pos = i; j_pos = j;
            widthF = field.getWidth();
        }
        iterator(iterator& cpy) : cagePtr(cpy.cagePtr), i_pos(cpy.i_pos), j_pos(cpy.j_pos){}
        iterator& operator=(iterator& other){
            cagePtr = other.cagePtr;
            i_pos = other.i_pos; j_pos = other.j_pos;
            widthF = other.widthF;
            return *this;
        }
        iterator& operator=(FieldCage** ptr){
            cagePtr = ptr; i_pos = j_pos = 0; return *this;
        }
        iterator& operator=(iterator it){
            std::swap(cagePtr, it.cagePtr);
            std::swap(i_pos, it.i_pos);
            std::swap(j_pos, it.j_pos);
            std::swap(widthF, it.widthF);
            return *this;
        }
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

        bool operator==(FieldCage** end) const{
            return (cagePtr + i_pos*sizeof(FieldCage*)) == end;
        }

        bool operator!=(FieldCage** end) const{
            return !(*this == end);
        }

    private:
        FieldCage** cagePtr;
        int i_pos;
        int j_pos;
        int widthF;
        
        void change_poses(){
            j_pos++;
            if (j_pos == widthF){
                i_pos++; j_pos = 0; return;
            }
        }

    };

private:
    // FieldCage** cageArray;
    field_t cageArray;
    int width;   //1200 = 20 * 60
    int height;  //900 = 15 * 60
};

#endif //FIELD_HPP