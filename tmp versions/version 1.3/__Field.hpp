#ifndef FIELD_HPP
#define FIELD_HPP

#include"FieldCage.hpp"
#include"CreateField.hpp"

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

    FieldCage& getCage(int i = 0, int j = 0);

    FieldCage** begin();
    FieldCage** end();
    const int Height() const;
    const int Width() const;

    class iterator{
    public:
        iterator(FieldCage** begin = nullptr) : cagePtr(begin), i_pos(0), j_pos(0) {}
        iterator(iterator& cpy) : cagePtr(cpy.cagePtr), i_pos(cpy.i_pos), j_pos(cpy.j_pos){}
        ~iterator(){ /*std::cout << "DESTRUCTOR" << std::endl;*/}

        FieldCage& operator*(){
            return cagePtr[i_pos][j_pos];
        }

        iterator& operator++(){           //prefix
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

    // class iterator{
    //     public:
    //         iterator(FieldCage** cageP) : cagePtr(cageP), h_pos(0), w_pos(0){}
    //         iterator(const iterator& _it) : cagePtr(_it.cagePtr), h_pos(_it.h_pos), w_pos(_it.w_pos){}
    //         iterator operator++(int){
    //             iterator tmp(*this);
    //             operator++();
    //             return tmp;
    //         }
    //         iterator& operator++(){
    //             change_poses();
    //             return *this;
    //         }
    //         bool operator==(const iterator& another) const{
    //             return ((cagePtr + h_pos*sizeof(FieldCage*)) + w_pos*sizeof(FieldCage)) == 
    //                 ((another.cagePtr + another.h_pos*sizeof(FieldCage*)) + another.w_pos*sizeof(FieldCage));
    //         }
    //         bool operator!=(const iterator& another){
    //             return ((cagePtr + h_pos*sizeof(FieldCage*)) + w_pos*sizeof(FieldCage)) != 
    //                 ((another.cagePtr + another.h_pos*sizeof(FieldCage*)) + another.w_pos*sizeof(FieldCage));
    //         }
    //         bool operator!=(const FieldCage** checkEnd){
    //             return ((cagePtr + h_pos*sizeof(FieldCage*))) != checkEnd;
    //         }
    //         FieldCage& operator*(){
    //             // return *(*(cagePtr + h_pos*sizeof(FieldCage*)) + w_pos*sizeof(FieldCage));
    //             return cagePtr[h_pos][w_pos];
    //         }
    //     private:
    //         FieldCage** cagePtr;
    //         int h_pos;
    //         int w_pos;
    //         void change_poses(){
    //             // w_pos++;
    //             if (w_pos == 20){
    //                 h_pos++; w_pos = 0; return;
    //             }
    //             w_pos++;
    //         }
    // };
    // friend class iterator;

private:
    FieldCage** cageArray;
    static int width;   //1200 = 20 * 60
    static int height;  //900 = 15 * 60
};

#endif //FIELD_HPP