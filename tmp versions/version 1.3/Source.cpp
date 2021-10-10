// #include"Game.hpp"
#include<iostream>
// #include"Field.hpp"
#include"FieldView.hpp"
#include<fstream>


int main() {

    Field field;
    CreateField creator("map.txt", field);
    FieldView check(OutMode::GUI);
    check.loadPictures({"pics2/pictures/Wide_Door_Exit.png",
                        "pics2/pictures/Tile_12.jpg",
                        "pics2/pictures/Wide_Door_Entry.png",
                        "pics/PNG/_land_6.jpg"});

    check << field;



    // std::ifstream file("map.txt", std::ifstream::in);

    // int x;
    // for (int i = 0; i < 15; i++){
    //     for (int j = 0; j < 20; j++){
    //         file >> x;
    //         std::cout << x << " ";
    //     }
    //     std::cout << std::endl;
    // }



    // Field a, b;

    // std::cout << a.Height() << " " << b.Height() << std::endl;

    return 0;
}