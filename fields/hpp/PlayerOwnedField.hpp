#pragma once

#include "./Field.hpp"
#include "../../.hpp/Player.hpp"

class PlayerOwnedField : public Field
{
	public:
		PlayerOwnedField(int, Player*);
		Player* owner_;
};	