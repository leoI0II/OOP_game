#include"Field.hpp"

Field::Field(){
    cageArray = new FieldCage*[height];
    for (int i = 0; i < height; i++)
        cageArray[i] = new FieldCage[width];
    
    // for (int i = 1; i < width-1; i++){
    //     cageArray[0][i] = FieldCage(i * 60, 0, "pics2/pictures/Tile_25.png", Status::NOT_AVAILABLE);
    //     cageArray[height-1][i] = FieldCage(i*60, (height-1)*60, "pics2/pictures/Tile_05.png", Status::NOT_AVAILABLE);
    // }
    // for (int i = 1; i < height-1; i++){
    //     cageArray[i][0] = FieldCage(0, i*60, "pics2/pictures/Tile_16.png", Status::NOT_AVAILABLE);
    //     cageArray[i][width-1] = FieldCage((width-1)*60, i*60, "pics2/pictures/Tile_13.png", Status::NOT_AVAILABLE);
    // }
    // cageArray[0][0] = FieldCage(0, 0, "pics2/pictures/Tile_01.png", Status::NOT_AVAILABLE);
    // cageArray[0][width-1] = FieldCage((width-1)*60, 0, "pics2/pictures/Tile_03.png", Status::NOT_AVAILABLE);
    // cageArray[height-1][0] = FieldCage(0, (height-1)*60, "pics2/pictures/Tile_21.png", Status::NOT_AVAILABLE);
    // cageArray[height-1][width-1] = FieldCage((width-1)*60, (height-1)*60, "pics2/pictures/Tile_23.png", Status::NOT_AVAILABLE);

    for (int i = 0; i < height; i++){
        for (int j = 0; j < width; j++){
            if (field[i][j] == ' '){
                cageArray[i][j].setX(j * 60);
                cageArray[i][j].setY(i * 60);
            }
            else if (field[i][j] == '0'){
                if (i == 0){
                    if (j == 0){
                        cageArray[i][j] = FieldCage(j* 60, i* 60, "pics2/pictures/Tile_01.png", Status::NOT_AVAILABLE);
                        // cageArray[i][j].setX(j*60).setY(i*60).setFilePath("pics2/pictures/Tile_01.jpg");
                    }
                    else
                        cageArray[i][j] = FieldCage(j* 60, i* 60, "pics2/pictures/Tile_03.png", Status::NOT_AVAILABLE);
                }
                else{
                    if (j == 0)
                        cageArray[i][j] = FieldCage(j* 60, i* 60, "pics2/pictures/Tile_21.png", Status::NOT_AVAILABLE);
                    else
                        cageArray[i][j] = FieldCage(j* 60, i* 60, "pics2/pictures/Tile_23.png", Status::NOT_AVAILABLE);
                }
            }
            else if (field[i][j] == '1'){
                if (i == 0)
                    cageArray[i][j] = FieldCage(j* 60, i* 60, "pics2/pictures/Tile_02.png", Status::NOT_AVAILABLE);
                else if (i == 14)
                    cageArray[i][j] = FieldCage(j* 60, i* 60, "pics2/pictures/Tile_05.png", Status::NOT_AVAILABLE);
                else if (j == 0)
                    cageArray[i][j] = FieldCage(j* 60, i* 60, "pics2/pictures/Tile_16.png", Status::NOT_AVAILABLE);
                else
                    cageArray[i][j] = FieldCage(j* 60, i* 60, "pics2/pictures/Tile_13.png", Status::NOT_AVAILABLE);
            }
            else if (field[i][j] == '2')
                cageArray[i][j] = FieldCage(j * 60, i * 60, "pics2/pictures/Wide_Door_Entry.png", Status::NOT_AVAILABLE, Type::Entry);
            else if (field[i][j] == '3')
                cageArray[i][j] = FieldCage(j * 60, i * 60, "pics2/pictures/Wide_Door_Exit.png", Status::NOT_AVAILABLE, Type::Exit);
        }
    }
}

Field::~Field(){
    for (int i = 0; i < 15; i++)
        delete [] cageArray[i];
    delete [] cageArray;
}

void Field::setCage(int i, int j, int x, int y){
    cageArray[i][j].setX(x);
    cageArray[i][j].setY(y);
}

sf::Sprite& Field::getSprite(int i, int j) {
    return cageArray[i][j].getSprite();
}

sf::Texture& Field::getTexture(int i, int j){
    return cageArray[i][j].getTexture();
}

const int& Field::getCageX(int& i, int& j) const{
    return cageArray[i][j].getX();
}

const int& Field::getCageY(int& i, int& j) const{
    return cageArray[i][j].getY();
}

const int& Field::Width() const{
    return width;
}

const int& Field::Height() const{
    return height;
}

// const char& tileMapCage(int& i, int& j){
//     return field[i][j];
// }