// #include"Game.hpp"
#include<iostream>
// #include"Field.hpp"
#include"FieldView.hpp"
#include<fstream>


int main() {

    Field field;
    CreateField creator("map.txt", field);
    // FieldView check(OutMode::GUI);
    // check.loadPictures({"pics2/pictures/Wide_Door_Exit.png",
    //                     "pics2/pictures/Tile_12.jpg",
    //                     "pics2/pictures/Wide_Door_Entry.png",
    //                     "pics/PNG/_land_6.jpg"});
    FieldView check(OutMode::CLI);

    check << field;

    std::cout << std::endl;

    // check << field;
    {    
        Field::iterator it = field.begin();
        // Field::iterator end = field.end();
        // std::cout << "zdes" << std::endl;
        int i = 0;

        //WORK
        // for (it; it != field.end(); it++){
        //     std::cout << *it << " ";
        //     if (++i == 20){
        //         std::cout << std::endl;
        //         i = 0;
        //     }
        // }

        //WORK
        // while(it != field.end()){
        //     std::cout << *it++ << " ";
        //     if (++i == 20){
        //         std::cout << std::endl;
        //         i = 0;
        //     }
        // }


    }
    std::cout << "HERE" << std::endl;

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