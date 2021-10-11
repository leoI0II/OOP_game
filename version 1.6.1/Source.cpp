// #include"Game.hpp"
#include<iostream>
// #include"Field.hpp"
#include"FieldView.hpp"
#include"FieldCageView.hpp"
#include<fstream>
#include<sstream>


// Field&& newField(){
//     return std::move(Field(CreateField("map.txt")));
// }


int main() {

    Field field(CreateField("map.txt"));
    FieldView check(field, OutMode::CLI);
    
    check.loadPictures({"pics2/pictures/Wide_Door_Exit.png",
                        "pics2/pictures/Tile_12.jpg",
                        "pics2/pictures/Wide_Door_Entry.png",
                        "pics/PNG/_land_6.jpg"});

    check.draw();
    // check.Mode(OutMode::GUI);
    // check.draw();


    // Field::iterator it(field);

    // std::cout << (int)(*it).getType() << std::endl << std::endl;

    // Field::iterator it2;
    // it2 = field.Cage(13, 18);
    // std::cout << (int)(*it2).getType() << std::endl;

    

    // check.Mode(OutMode::GUI);
    // check << field;

    // std::cout << std::endl;

    // check << field;
    // FieldCageView cagePrinter;
    {    
        // Field::iterator it = field;
        // // Field::iterator end = field.end();
        // std::cout << "zdes" << std::endl;
        // int i = 0;


        // for (it; it != field.end(); it++){
        //     std::cout << (int)(*it).getType() << " ";
        //     if (++i == field.getWidth()){
        //         std::cout << std::endl;
        //         i = 0;
        //     }
        // }


        // while(it != field.end()){
        //     std::cout << *it++ << " ";
        //     if (++i == 20){
        //         std::cout << std::endl;
        //         i = 0;
        //     }
        // }


    }
    std::cout << "Bye!:)" << std::endl;

    return 0;
}