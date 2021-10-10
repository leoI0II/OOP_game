// #include"Game.hpp"
#include<iostream>
// #include"Field.hpp"
#include"FieldView.hpp"
#include<fstream>


// Field&& newField(){
//     return std::move(Field(CreateField("map.txt")));
// }


int main() {

    Field field(CreateField(15, 20, "map.txt"));
    // CreateField creator("map.txt", field);
    FieldView check(field, OutMode::CLI);
    
    check.loadPictures({"pics2/pictures/Wide_Door_Exit.png",
                        "pics2/pictures/Tile_12.jpg",
                        "pics2/pictures/Wide_Door_Entry.png",
                        "pics/PNG/_land_6.jpg"});
    // FieldView check(OutMode::CLI);

    check.draw();
    check.Mode(OutMode::GUI);
    check.draw();

    // check.Mode(OutMode::GUI);
    // check << field;

    // std::cout << std::endl;

    // check << field;
    {    
        // Field::iterator it = field.begin();
        // Field::iterator end = field.end();
        // std::cout << "zdes" << std::endl;
        // int i = 0;


        // for (it; it != field.end(); it++){
        //     std::cout << *it << " ";
        //     if (++i == 20){
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