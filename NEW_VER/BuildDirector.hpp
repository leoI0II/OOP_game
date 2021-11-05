#ifndef BUILDDIRECTOR_HPP
#define BUILDDIRECTOR_HPP

#include"TileBuilder.hpp"

class BuildDirector{
public:
    BuildDirector(ITileBuilder* _builder = nullptr):
        builder(_builder) {}

    void SetBuilder(ITileBuilder* newBuilder){
        builder = newBuilder;
    }
    // void SetBuilder(const std::shared_ptr<ITileBuilder>& newBuilder){
    //     builder = newBuilder;
    // }
    void BuildTile(const Point& point){
        builder->SetPosition(point);
        builder->SetTileStatus();
        builder->SetTileType();
    }
    // std::shared_ptr<Tile> GetTile(){
    //     return builder->GetTile();
    // }

    ~BuildDirector(){}

private:
    ITileBuilder* builder;

};


#endif ///BUILDDIRECTOR_HPP