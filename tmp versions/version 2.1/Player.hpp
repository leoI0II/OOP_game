#ifndef PLAYER_HPP
#define PLAYER_HPP

#include"Character.hpp"
#include"Weapon.hpp"
#include<map>
#include<vector>
#include"Item.hpp"

using Bag_t = std::map<ItemType, std::vector<Item*>>;

class Player : public Character{
public:
    Player(int HP, int dmg, const Point& pos, double sp, int wQuant = 50, MoveDir MD = MoveDir::Stay, MoveDir chD = MoveDir::Right) : 
        Character(HP, dmg, pos, sp, MD), weapon(wQuant, pos), checkDir(chD) {}

    ~Player(){
        for (int i = 0; i < 3; i++){
            if (!bag[ItemType(i)].empty())
                for (int j = 0; j < bag[ItemType(i)].size(); j++)
                    delete bag[ItemType(i)][j];
        }
    }

    void UseItem(ItemType ittp){
        if (!bag[ittp].empty()) {
            Item* tmp = bag[ittp].back();
            bag[ittp].pop_back();
            tmp->Interact(this);
        }
    }

    void AddToBag(Item* newItem){
        if (typeid(*newItem) == typeid(LittleHealthBottle)){
            bag[ItemType::LittleHealthBottle].push_back(newItem);
        }
        else if (typeid(*newItem) == typeid(BigHealthBottle)){
            bag[ItemType::BigHealthBottle].push_back(newItem);
        }
        else if (typeid(*newItem) == typeid(Ammo)){
            bag[ItemType::Ammo].push_back(newItem);
        }
    }

    Bullet* Fire() {
        return weapon.reduseMagazine(checkDir);
    }
    void SetCheckingDirection(MoveDir mv){
        checkDir = mv;
    }
    MoveDir GetPlayerCheckingDirection() const {
        return checkDir;
    }
    
    void Update(double time, FieldGrid& grid, const float& chSizeX, const float& chSizeY) override {
        double dx = 0, dy = 0;
        MoveDir tmp = GetDirection();
        if (tmp == MoveDir::Left){
            dx = -GetSpeed();
        }
        else if (tmp == MoveDir::Right){
            dx = GetSpeed();
        }
        else if (tmp == MoveDir::Down){
            dy = GetSpeed();
        }
        else if (tmp == MoveDir::Up){
            dy = -GetSpeed();
        }
        SetPoint(GetX() + dx*time, GetY() + dy*time);
        InteractionWithGrid(grid, dx, dy, chSizeX, chSizeY);
        SetDirection(MoveDir::Stay);
    }

    bool InteractionWithGrid(FieldGrid& grid, double& dx, double& dy, const float& chSizeX, const float& chSizeY) override {
        double chX = GetX(), chY = GetY();
        int tileS = int(TileSize::Size);
        for (int i = chY/tileS; i < (chY + chSizeY)/tileS; i++){
            for (int j = chY/tileS; j < (chY + chSizeX)/tileS; j++){
                if (grid.GetTile().GetType() == Type::Wall){
                    if (dy > 0){
                        // position.SetY(i * chSize + chSize);
                        SetY(i * tileS - chSizeY);
                        return true;
                    }
                    if (dy < 0){
                        // position.SetY(i * chSize + chSize);
                        SetY(i * tileS + tileS);
                        return true;
                    }
                    if (dx > 0){
                        // position.SetX(j * chSize - chSize);
                        SetX(j * tileS - chSizeX);
                        return true;
                    }
                    if (dx < 0){
                        // position.SetY(j * chSize + chSize);
                        SetX(j * tileS + tileS);
                        return true;
                    }
                }
            }
        }
        return false;
    }

    Weapon& const GetWeapon() {
        return weapon;
    }

private:

    Weapon weapon;
    Bag_t bag;
    MoveDir checkDir;
};


#endif ///PLAYER_HPP