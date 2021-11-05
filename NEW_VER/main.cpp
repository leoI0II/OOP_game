#include"FieldGrid.hpp"
#include"GridView.hpp"

int main(){

    GridCreator creator;
    FieldGrid grid(creator);

    GridView view(grid);

    view.loadPicsFromFile();

    view.draw();
    view.Mode(OutMode::GUI);
    view.draw();
    



    return 0;
}