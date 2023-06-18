#include "Field.hpp"

Field::Field(int id)
{
	id_ = id;
	pawnStandingOnThisField_ = nullptr;
	previousField_ = nullptr;
	nextField_ = nullptr;
}

int Field::getId()
{
	return id_;
}

void Field::setNextFieldPointer(Field* pointer)
{
	nextField_ = pointer;
}

void Field::setPreviousFieldPointer(Field* pointer)
{
	previousField_ = pointer;
}

Field* Field::getNextFieldPointer()
{
	return nextField_;
}

Field* Field::getPreviousFieldPointer()
{
	return previousField_;
}

void Field::setStandingPawn(Pawn* pawn)
{
	pawnStandingOnThisField_ = pawn;
}

Pawn* Field::getStandingPawn()
{
	return pawnStandingOnThisField_;
}

void Field::setFieldCoordinates(int y, int x)
{
	coordinates_ = std::pair<int, int>(y, x);
}

std::pair<int, int> Field::getFieldCoordinates()
{
	return coordinates_;
}

void Field::setFieldDimensions(int y, int x)
{
	dimensions_ = std::pair<int, int>(y, x);
}

std::pair<int, int> Field::getFieldDimensions()
{
	return dimensions_;
}
