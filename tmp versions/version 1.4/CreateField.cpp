#include"CreateField.hpp"
#include<fstream>
// #include<iostream>

CreateField::CreateField(const char* fp) {
    std::ifstream mapFile(fp, std::ifstream::in);

    if (!mapFile.is_open())
        exit(EXIT_FAILURE);

    int type;

    cages = new FieldCage*[Field::Height()];
    for (int i = 0; i < Field::Height(); i++){
        cages[i] = new FieldCage[Field::Width()];
        for (int j = 0; j < Field::Width(); j++){
            mapFile >> type;
            cages[i][j] = FieldCage(j * int(CageSize::Size), i * int(CageSize::Size), static_cast<Type>(type),
                (type != 3 ? Status::AVAILABLE : Status::NOT_AVAILABLE));
        }
    }
    mapFile.close();

}

CreateField::~CreateField(){
    if (cages){
        for (int i = 0; i < Field::Height(); i++)
            delete [] cages[i];
        delete [] cages;
    }
}