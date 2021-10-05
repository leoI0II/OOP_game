#include"CreateField.hpp"
#include<fstream>
// #include<iostream>
#include<string>

CreateField::CreateField(const char* fp){
    std::ifstream mapFile(fp, std::ifstream::in);

    int cageTp[15][20];
    for (int i = 0; i < 15; i++){
        for (int j = 0; j < 20; j++)
            mapFile >> cageTp[i][j];
    }
    mapFile.close();

    FieldCage** cages = new FieldCage*[15];
    for(int i = 0; i < 15; i++){
        cages[i] = new FieldCage[20];
        for (int j = 0; j < 20; j++){
            cages[i][j] = FieldCage(j * 60, i * 60, static_cast<Type>(cageTp[i][j]), 
                (cageTp[i][j] != 3 ? Status::AVAILABLE : Status::NOT_AVAILABLE));
        }
    }

    // cages = new FieldCage*[15];
    // for (int i = 0; i < 15; i++)
    //     cages[i] = new FieldCage[20];

    // std::string strFromStream;
    // int Iheight = 0;
    // while(!mapFile.eof()){
    //     std::getline(mapFile, strFromStream);
    //     for (int Iwidth = 0; Iwidth < strFromStream.size(); Iwidth++){
    //         if (strFromStream[Iwidth] == 'e')
    //             cages[Iheight][Iwidth] = FieldCage(Iwidth*60, Iheight*60, )
    //     }
    // }


}

FieldCage** CreateField::getField(){
    return cages;
}