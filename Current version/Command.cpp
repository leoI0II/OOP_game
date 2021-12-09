#include"Command.hpp"

void LeftMove_Command::execute(Character* ch)
{
	ch->SetDirection(MoveDir::Left);
}

void RightMove_Command::execute(Character* ch)
{
	ch->SetDirection(MoveDir::Right);
}

void UpMove_Command::execute(Character* ch)
{
	ch->SetDirection(MoveDir::Up);
}

void DownMove_Command::execute(Character* ch)
{
	ch->SetDirection(MoveDir::Down);
}

void UseItemLHB_Command::execute(Character* ch)
{
	ch->UseItem(std::type_index(typeid(LittleHealthBottle)));
}

void UseItemA_Command::execute(Character* ch)
{
	ch->UseItem(std::type_index(typeid(Ammo)));
}

void UseItemBHB_Command::execute(Character* ch)
{
	ch->UseItem(std::type_index(typeid(BigHealthBottle)));
}
