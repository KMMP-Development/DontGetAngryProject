#include "PlayerOwnedField.hpp"

PlayerOwnedField::PlayerOwnedField(int id, Player* owner)
	:Field(id)
{
	owner_ = owner;
}