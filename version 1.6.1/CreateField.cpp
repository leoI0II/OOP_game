#include"CreateField.hpp"
#include<fstream>
#include<sstream>
// #include<iostream>


void CreateField::findParams(const char* fp){
    std::ifstream File(fp);

    fieldH = fieldW = 0;


    if (!File.is_open())
        exit(EXIT_FAILURE);


    std::string str;
    std::getline(File, str);
    
    std::istringstream ss(str);
    int data;
    while(ss >> data)
        fieldW++;

    File.seekg(std::ios_base::beg);

    while(std::getline(File, str)){
        fieldH++;
    }
    File.close();
}

CreateField::CreateField(const char* fp) {

    findParams(fp);

    std::ifstream mapFile(fp, std::ifstream::in);

    int type;
    // cages = new FieldCage*[fieldH];
    // for (int i = 0; i < fieldH; i++){
    //     cages[i] = new FieldCage[fieldW];
    //     for (int j = 0; j < fieldW; j++){
    //         mapFile >> type;
    //         cages[i][j] = FieldCage(j * int(CageSize::Size), i * int(CageSize::Size), static_cast<Type>(type),
    //             (type != 3 ? Status::AVAILABLE : Status::NOT_AVAILABLE));
    //     }
    // }

    cages = std::make_unique<cageArr_t[]>(fieldH);
    for (int i = 0; i < fieldH; i++){
        cages[i] = std::make_unique<FieldCage[]>(fieldW);
        for (int j = 0; j < fieldW; j++){
            mapFile >> type;
            cages[i][j] = FieldCage(j * int(CageSize::Size), i * int(CageSize::Size), static_cast<Type>(type),
                (type != 3 ? Status::AVAILABLE : Status::NOT_AVAILABLE));
        }
    }

    mapFile.close();

}

CreateField::~CreateField() { }