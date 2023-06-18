#pragma once

#include "Pawn.hpp"
#include "../fields/hpp/PlayerBaseField.hpp"
#include "../fields/hpp/PlayerBaseEntranceField.hpp"
#include "../fields/hpp/PlayerStackField.hpp"
#include "../fields/hpp/PlayerStackExitField.hpp"

class Player
{
	public:
		int id_;
		Player(int);

	private:
		Pawn pawns_[4];
		PlayerBaseField baseFields_[4];
		PlayerBaseEntranceField baseEntranceField_;
		PlayerStackField stackFields_[4];
		PlayerStackExitField stackExitField_;
};