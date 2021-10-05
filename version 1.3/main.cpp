// #include"Game.hpp"
#include<iostream>
// #include"Field.hpp"
#include"FieldView.hpp"
#include<fstream>


int main(){
    
    CreateField creator("map.txt");
    Field field(creator);
    FieldView check(OutMode::CLI);

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