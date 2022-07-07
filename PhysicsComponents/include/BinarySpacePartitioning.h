#pragma once
#include <list>
#include "Vector2.h"
#include "Space.h"
#include <math.h>
#include <utility>
//#include <queue>

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

	/// <summary>
	/// Constructor for the Binary Space Partitioning
	/// </summary>
	/// <param name="xSize">The X size value</param>
	/// <param name="ySize">The Y size value</param>
	/// <param name="divisionFactor">The wanted amount of division in X and Y</param>
	BinarySpacePartitioning(float  xSize, float ySize, int divisionFactor);
	/// <summary>
	/// Constructor for the Binary Space Partitioning
	/// </summary>
	/// <param name="size">The size of the space (Vector2)</param>
	/// <param name="divisionFactor">The wanted amount of division in X and Y</param>
	BinarySpacePartitioning(Vector2 size, int);
	/// <summary>
	/// Default constructor
	/// </summary>
	BinarySpacePartitioning();
	/// <summary>
	/// Default destructor
	/// </summary>
	~BinarySpacePartitioning();

	/// <summary>
	/// Assigns an ID to the given rigidbody according to it's position in the BSP space
	/// </summary>
	/// <param name="rigidbody"></param>
	void AssignId(Rigidbody* rigidbody);

private:

	std::vector<std::pair<float, float>> _positions;

};