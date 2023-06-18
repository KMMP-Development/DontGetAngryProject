#pragma once

#include "../../.hpp/Pawn.hpp";
#include <utility>

class Field
{
	protected:
		// LOGIC
		int id_;
		Field* nextField_;
		Field* previousField_;
		Pawn* pawnStandingOnThisField_;

		// GRAPHICS
		std::pair<int, int> coordinates_;
		std::pair<int, int> dimensions_;

	public:
		Field(int);

		int getId();

		void setNextFieldPointer(Field*);
		void setPreviousFieldPointer(Field*);

		Field* getNextFieldPointer();
		Field* getPreviousFieldPointer();

		void setStandingPawn(Pawn*);

		Pawn* getStandingPawn();

		void setFieldCoordinates(int, int);
		void setFieldDimensions(int, int);

		std::pair<int, int> getFieldCoordinates();
		std::pair<int, int> getFieldDimensions();

};