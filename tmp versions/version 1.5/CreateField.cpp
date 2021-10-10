#include"CreateField.hpp"
#include<fstream>
// #include<iostream>

CreateField::CreateField(int FH, int FW, const char* fp) : fieldH(FH), fieldW(FW) {
    std::ifstream mapFile(fp, std::ifstream::in);

    if (!mapFile.is_open())
        exit(EXIT_FAILURE);

    int type;

    cages = new FieldCage*[fieldH];
    for (int i = 0; i < fieldH; i++){
        cages[i] = new FieldCage[fieldW];
        for (int j = 0; j < fieldW; j++){
            mapFile >> type;
            cages[i][j] = FieldCage(j * int(CageSize::Size), i * int(CageSize::Size), static_cast<Type>(type),
                (type != 3 ? Status::AVAILABLE : Status::NOT_AVAILABLE));
        }
    }
    mapFile.close();

}

CreateField::~CreateField(){
    if (cages){
        for (int i = 0; i < fieldH; i++)
            delete [] cages[i];
        delete [] cages;
    }
}

// FieldCage** CreateField::getCages(){
//     return cages;
// }

// int CreateField::fieldHeight() { return fieldH; }
// int CreateField::fieldWidth() { return fieldW; }