#include "BinarySpacePartitioning.h"


BinarySpacePartitioning::BinarySpacePartitioning(float xPos, float yPos, int divisionFactor)
{
	for (float x = 0; x < xPos; x+=(xPos/divisionFactor))
	{
		for (float y = 0; y < yPos; y+=(yPos/divisionFactor))
		{
			_positions.emplace_back(std::vector<float>{x, y});
		}
	}
}

BinarySpacePartitioning::BinarySpacePartitioning() {}

BinarySpacePartitioning::~BinarySpacePartitioning() {}

#pragma region BSP SpaceVersion
//BinarySpacePartitioning::BinarySpacePartitioning() {}
//
///// <summary>
///// BSP Constructor
///// </summary>
///// <param name="space">The given Space to split</param>
///// <param name="divisionFactor">Number of times to splits</param>
//BinarySpacePartitioning::BinarySpacePartitioning(Space* space, int divisionFactor)
//{
//
//	std::queue<Space> spacesToCheck;
//	spacesToCheck.push(*space);
//
//	while (!spacesToCheck.empty()) 
//	{
//		Space checkedSpace = spacesToCheck.front();
//
//		if (checkedSpace.GetSrqMagnitude() <= (space->GetSrqMagnitude() / pow(2, divisionFactor+1)))
//		{
//			_spaces.emplace_back(checkedSpace);
//		}
//		else
//		{
//			Space space1 = Space();
//			Space space2 = Space();
//			Space space3 = Space();
//			Space space4 = Space();
//			QuadSplit(checkedSpace, space1, space2, space3, space4);
//			spacesToCheck.push(space1);
//			spacesToCheck.push(space2);
//			spacesToCheck.push(space3);
//			spacesToCheck.push(space4);
//		}
//
//		spacesToCheck.pop();
//
//	}
//}
//
//BinarySpacePartitioning::~BinarySpacePartitioning(){}
//
///// <summary>
///// Gets the spaces
///// </summary>
///// <returns>Returns the list of spaces</returns>
//std::vector<Space> BinarySpacePartitioning::GetSpaces() 
//{
//	return _spaces;
//}
//
///// <summary>
///// Splits the given space in four sub spaces
///// </summary>
///// <param name="givenSpace"></param>
///// <param name="space1">Lower-Left Space</param>
///// <param name="space2">Upper-Left Space</param>
///// <param name="space3">Upper-Right Space</param>
///// <param name="space4">Lower-Right Space</param>
//void BinarySpacePartitioning::QuadSplit(Space givenSpace, Space& space1, Space& space2, Space& space3, Space& space4)
//{
//	//Sets the space to the lower-left of the given space
//	space1 = Space(givenSpace.GetMin(), 
//				Vector2(givenSpace.GetMin()._x + givenSpace.GetSizeX()/ 2.0f,
//						givenSpace.GetMin()._y + givenSpace.GetSizeY()/ 2.0f));
//	//Sets the space to the upper-left of the given space
//	space2 = Space(Vector2(givenSpace.GetMin()._x, givenSpace.GetMin()._y + givenSpace.GetSizeY()/ 2.0f),
//				Vector2(givenSpace.GetMin()._x + givenSpace.GetSizeX()/ 2.0f,
//						givenSpace.GetMin()._y + givenSpace.GetSizeY()));
//	//Sets the space to the upper-left of the given space
//	space3 = Space(Vector2(givenSpace.GetMin()._x + givenSpace.GetSizeX()/ 2.0f, givenSpace.GetMin()._y + givenSpace.GetSizeY() / 2.0f),
//				Vector2(givenSpace.GetMin()._x + givenSpace.GetSizeX(),
//						givenSpace.GetMin()._y + givenSpace.GetSizeY()));
//	//Sets the space to the lower-right hald of the given space
//	space4 = Space(Vector2(givenSpace.GetMin()._x + givenSpace.GetSizeX()/ 2.0f, givenSpace.GetMin()._y),
//				Vector2(givenSpace.GetMin()._x + givenSpace.GetSizeX(),
//						givenSpace.GetMin()._y + givenSpace.GetSizeY() / 2.0f));
//}

#pragma endregion