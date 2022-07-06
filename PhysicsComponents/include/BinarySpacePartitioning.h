#pragma once
#include <list>
#include "Vector2.h"
#include "Space.h"
#include <math.h>
#include <queue>

#pragma region BSP SpaceVersion

//class BinarySpacePartitioning
//{
//public:
//	//Constructor for the BSP
//	BinarySpacePartitioning();
//	BinarySpacePartitioning(Space*, int);
//	~BinarySpacePartitioning();
//
//	std::vector<Space> GetSpaces();
//
//	void QuadSplit(Space givenSpace, Space& space1, Space& space2, Space& space3, Space& space4);
//
//private:
//	std::vector<Space> _spaces;
//};

#pragma endregion

class BinarySpacePartitioning
{
public:

	BinarySpacePartitioning(float, float, int);
	BinarySpacePartitioning();
	~BinarySpacePartitioning();

private:

	std::vector<std::vector<float>> _positions;

};