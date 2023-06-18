#include "Board.hpp"

Board::Board()
{
	for (int i = 0; i < 4; i++)
	{
		players_[i] = Player(i);
	}
}