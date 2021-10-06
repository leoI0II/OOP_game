#include"CreateField.hpp"
#include<fstream>
// #include<iostream>
#include<string>

CreateField::CreateField(const char* fp) {
    std::ifstream mapFile(fp, std::ifstream::in);

    if (!mapFile.is_open())
        exit(EXIT_FAILURE);

    int type;

    cages = new FieldCage*[15];
    for (int i = 0; i < 15; i++){
        cages[i] = new FieldCage[20];
        for (int j = 0; j < 20; j++){
            mapFile >> type;
            cages[i][j] = FieldCage(j * 60, i * 60, static_cast<Type>(type),
                (type != 3 ? Status::AVAILABLE : Status::NOT_AVAILABLE));
        }
    }
    mapFile.close();

}