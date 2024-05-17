#include "pch.h"
#include "CppUnitTest.h"
#include "Group5MS4_r.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Group5MS4UnitTest
{
	TEST_CLASS(Group5MS4UnitTest)
	{
	public:
		
		TEST_METHOD(PosaddRouteTest1)
		{
			int a = MAP_ROWS * MAP_COLS;
			int b = 1;
			struct Map baseMap = populateMap();
			struct Route routeMapBvTwo =
			{
					{
					{0,0},
					{1,0},{1,1}

					},
						3, BLUE
			};
			struct Map routeMap = addRoute(&baseMap, &routeMapBvTwo);
			struct Map expectedMap = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{BLUE, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{BLUE, BLUE, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
				{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
				{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
				{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
				{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
				},
				MAP_ROWS, MAP_COLS
			};

			for (int i = 0; i < MAP_ROWS; i++)
			{
				for (int k = 0; k < MAP_COLS; k++)
				{
					if (routeMap.squares[i][k] == expectedMap.squares[i][k])
					{
						b++;
					}
				}
			}
			Assert::IsTrue(b == a);
			//Test to see if basic functionality of addRoute works.
			//Post Results: Passed
		}
		TEST_METHOD(PosaddRouteTest2)
		{
			int a = MAP_ROWS * MAP_COLS;
			int b = 1;
			struct Map baseMap = populateMap();
			struct Route routeMapBvTwo = {
				{
					{ 0, 0 },
				},
				1,
				BLUE
			};
			struct Map routeMap = addRoute(&baseMap, &routeMapBvTwo);
			struct Map expectedMap = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{2, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
				{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
				{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
				{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
				{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
				},
				MAP_ROWS, MAP_COLS
			};
			for (int i = 0; i < MAP_ROWS; i++)
			{
				for (int k = 0; k < MAP_COLS; k++)
				{
					if (routeMap.squares[i][k] == expectedMap.squares[i][k])
					{
						b++;
					}
					else
					{

					}
				}
			}

			Assert::IsTrue(b == a); // Check if all coordinates match
			// Test to see if basic functionality of addRoute works for minimum 1 entry.
			// Post Results: Passed
		}
		TEST_METHOD(PosaddRouteTest3)
		{
			int a = MAP_ROWS * MAP_COLS;
			int b = 0;
			struct Map baseMap = populateMap();
			struct Route routeMapBvNine =
			{
					{
					{'A','A'},

					},
						1, BLUE
			};
			struct Map routeMap = addRoute(&baseMap, &routeMapBvNine);
			struct Map expectedMap = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{BLUE, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
				{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
				{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
				{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
				{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
				},
				MAP_ROWS, MAP_COLS
			};

			for (int i = 0; i < MAP_ROWS; i++)
			{
				for (int k = 0; k < MAP_COLS; k++)
				{
					if (routeMap.squares[i][k] == expectedMap.squares[i][k])
					{
						b++;
					}
				}
			}

			Assert::IsTrue(b == a);
			//Test to see if function trully accepts characters instead of solely numbers as coordinates.
			//Post Results: Failed, Does not take characters at all despite the fact that in the code it says it accepts them.
		}
		TEST_METHOD(PosaddRouteTest4)
		{
			int a = MAP_ROWS * MAP_COLS;
			int b = 0;
			struct Map baseMap = populateMap();
			struct Route routeMapBvEleven =
			{
					{
					{'A',0},
					{1,'A'},
					{'B',1},
					},
						3, BLUE
			};
			struct Map routeMap = addRoute(&baseMap, &routeMapBvEleven);
			struct Map expectedMap = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{BLUE, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{BLUE, BLUE, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
				{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
				{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
				{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
				{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
				},
				MAP_ROWS, MAP_COLS
			};

			for (int i = 0; i < MAP_ROWS; i++)
			{
				for (int k = 0; k < MAP_COLS; k++)
				{
					if (routeMap.squares[i][k] == expectedMap.squares[i][k])
					{
						b++;
					}
				}
			}

			Assert::IsTrue(b == a);
			//Test to see if functionaccepts a mix of characters and numbers for coordinates.
			//Post Results:	Failed
		}
		TEST_METHOD(PosaddRouteTest5)
		{
			int a = MAP_ROWS * MAP_COLS;
			int b = 0;
			struct Map baseMap = populateMap();
			struct Route greenRoute = getGreenRoute();
			struct Route yellowRoute = getYellowRoute();
			struct Route blueRoute = getBlueRoute();
			struct Map routeMapB = addRoute(&baseMap, &blueRoute);
			struct Map routeMapG = addRoute(&baseMap, &greenRoute);
			struct Map routeMapY = addRoute(&baseMap, &yellowRoute);
			struct Map routeMapBG = routeMapB;
			routeMapBG = addRoute(&routeMapBG, &greenRoute);
			struct Map routeMapAll = addRoute(&routeMapBG, &yellowRoute);
			struct Map expectedMap = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				  {14, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 0, 0, 0, 0},
				  {14, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 4, 0, 0, 0, 0, 1, 1, 0, 4, 1, 1, 0, 0, 0},
				  {14, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 4, 1, 1, 0, 0, 1, 1, 0, 4, 1, 1, 0, 0, 0},
				  {14, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0},
				  {14, 14, 14, 14, 6, 6, 6, 6, 6, 6, 4, 4, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0},
				  {0, 0, 0, 8, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 0, 0, 0},
				  {1, 1, 0, 8, 1, 1, 0, 1, 1, 2, 0, 0, 0, 0, 0, 1, 0, 1, 1, 4, 0, 0, 0, 0, 0},
				  {1, 1, 0, 8, 1, 1, 0, 1, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 1, 4, 0, 0, 1, 1, 1},
				  {0, 0, 0, 8, 0, 0, 0, 1, 0, 2, 0, 0, 0, 0, 0, 1, 0, 0, 1, 4, 0, 0, 1, 1, 1},
				  {0, 8, 8, 8, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 4, 4, 4, 4, 4},
				  {0, 8, 0, 0, 0, 0, 0, 0, 0, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				  {1, 8, 1, 1, 1, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
				  {1, 8, 0, 0, 0, 0, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
				  {1, 8, 1, 1, 1, 0, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
				  {1, 8, 1, 1, 1, 0, 0, 0, 0, 0, 2, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
				  {1, 8, 0, 0, 0, 0, 1, 1, 1, 0, 2, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},
				  {0, 8, 0, 0, 0, 0, 1, 1, 1, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				  {0, 8, 0, 0, 0, 0, 1, 1, 1, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2},
				  {0, 8, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
				  {0, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8},
				  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
				  {0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},
				  {0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},
				  {0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},
				  {0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
			 },
				MAP_ROWS, MAP_COLS
			};

			for (int i = 0; i < MAP_ROWS; i++)
			{
				for (int k = 0; k < MAP_COLS; k++)
				{
					if (routeMapAll.squares[i][k] == expectedMap.squares[i][k])
					{
						b++;
					}
				}
			}

			Assert::IsTrue(b == a);
			//Test to see if can handle multiple paths added load testing.
			//Post Results:	Failed
		}
		TEST_METHOD(NegaddRouteTest1)
		{
			int a = MAP_ROWS * MAP_COLS;
			int b = 0;
			struct Map baseMap = populateMap();
			struct Route routeMapBvTwo =
			{
					{
					{99,99},
					{1,0},{1,1}
					},
						3, BLUE
			};
			struct Map routeMap = addRoute(&baseMap, &routeMapBvTwo);
			struct Map expectedMap = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
				{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
				{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
				{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
				{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
				},
				MAP_ROWS, MAP_COLS
			};

			for (int i = 0; i < MAP_ROWS; i++)
			{
				for (int k = 0; k < MAP_COLS; k++)
				{
					if (routeMap.squares[i][k] == expectedMap.squares[i][k])
					{
						b++;
					}
				}
			}

			Assert::IsTrue(b == a);
			//Test to see if function safeguards against well over the limit entries.
			//Post Results: Failed
		}
		TEST_METHOD(NegaddRouteTest2)
		{
			int a = MAP_ROWS * MAP_COLS;
			int b = 0;
			struct Map baseMap = populateMap();
			struct Route routeMapBvFour =
			{
					{
					{0,0},
					{1,0},
					{2,0},
					{3,0}
					},
						4, 99
			};
			struct Map routeMap = addRoute(&baseMap, &routeMapBvFour);
			struct Map expectedMap = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
				{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
				{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
				{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
				{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
				},
				MAP_ROWS, MAP_COLS
			};

			for (int i = 0; i < MAP_ROWS; i++)
			{
				for (int k = 0; k < MAP_COLS; k++)
				{
					if (routeMap.squares[i][k] == expectedMap.squares[i][k])
					{
						b++;
					}
				}
			}

			Assert::IsTrue(b == a);
			//Test to see if function safeguards symbols that are outside the range.
			//Post Results: Failed,Will have to find a way to limit what charcter can run
		}
		TEST_METHOD(NegaddRouteTest3)
		{
			int a = MAP_ROWS * MAP_COLS;
			int b = 0;
			struct Map baseMap = populateMap();
			struct Route routeMapBvFive =
			{
					{
					{-10,-10},
					},
						1, BLUE
			};
			struct Map routeMap = addRoute(&baseMap, &routeMapBvFive);
			struct Map expectedMap = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
				{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
				{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
				{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
				{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
				},
				MAP_ROWS, MAP_COLS
			};

			for (int i = 0; i < MAP_ROWS; i++)
			{
				for (int k = 0; k < MAP_COLS; k++)
				{
					if (routeMap.squares[i][k] == expectedMap.squares[i][k])
					{
						b++;
					}
				}
			}

			Assert::IsTrue(b == a);
			//Test to see if function safeguards against under the edge entries by simply not running.
			//Post Results: Passed
		}
		TEST_METHOD(NegaddRouteTest4)
		{
			int a = MAP_ROWS * MAP_COLS;
			int b = 0;
			struct Map baseMap = populateMap();
			struct Route routeMapBvSeven = {
		   {
			{0,0},
			{0,0},
			{0,0},
			{0,0}
			},
			4, BLUE
			};
			struct Map routeMap = addRoute(&baseMap, &routeMapBvSeven);
			struct Map expectedMap = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
				{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
				{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
				{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
				{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
				},
				MAP_ROWS, MAP_COLS
			};

			for (int i = 0; i < MAP_ROWS; i++)
			{
				for (int k = 0; k < MAP_COLS; k++)
				{
					if (routeMap.squares[i][k] == expectedMap.squares[i][k])
					{
						b++;
					}
				}
			}

			Assert::IsTrue(b == a);
			//Test to see if function safeguards against repeated values.
			//Post Results: Failed, will have to safeguard a way to prevent repeated values from running
		}
		TEST_METHOD(NegaddRouteTest5)
		{
			int a = MAP_ROWS * MAP_COLS;
			int b = 0;
			struct Map baseMap = populateMap();
			struct Route routeMapBvEight =
			{
					{
					{0,0},
					{-1,1},
					{2,-2},
					{3,3}
					},
						4, BLUE
			};
			struct Map routeMap = addRoute(&baseMap, &routeMapBvEight);
			struct Map expectedMap = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
				{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
				{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
				{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
				{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
				{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
				{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
				{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
				{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
				{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
				},
				MAP_ROWS, MAP_COLS
			};

			for (int i = 0; i < MAP_ROWS; i++)
			{
				for (int k = 0; k < MAP_COLS; k++)
				{
					if (routeMap.squares[i][k] == expectedMap.squares[i][k])
					{
						b++;
					}
				}
			}

			Assert::IsTrue(b == a);
			//Test to see if function safeguards against mixed invalid numbers and acceptable values.
			//Post Results: Failed(Will need to find a way to make sure negative numbers will not run.
		}
		/*	TEST_METHOD(NegaddRouteTest6)
			{
				int a = MAP_ROWS * MAP_COLS;
				int b = 1;
				struct Map baseMap = populateMap();
				struct Route routeMapBvThirteen =
				{
						{
						{'AAAA','AAA'},
						{'AAAA','BBB'},
						{'AAAA','CCC'},
						{'AAAA','DDD'},
						},
							4, BLUE
				};
				struct Map routeMap = addRoute(&baseMap, &routeMapBvThirteen);
				struct Map expectedMap = {
					//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
					//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
					{
					{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
					{0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
					{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//2
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//3
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//4
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//5
					{1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0},	//6
					{1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//7
					{0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1},	//8
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//9
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//10
					{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//11
					{1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//12
					{1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//13
					{1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//14
					{1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1},	//15
					{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//16
					{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//17
					{0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},	//18
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//19
					{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//20
					{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0},	//21
					{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1},	//22
					{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1},	//23
					{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}		//24
					},
					MAP_ROWS, MAP_COLS
				};
				for (int i = 0; i < MAP_ROWS; i++)
				{
					for (int k = 0; k < MAP_COLS; k++)
					{
						if (routeMap.squares[i][k] == expectedMap.squares[i][k])
						{
							b++;
						}
					}
				}
				Assert::IsTrue(b == a);
				//Test to see if function safeguards against of characters, it shouldn't run.
				//Post Results: Did not run at all so while it doesn't safeguard against strings, it atleast doesn't accept it either.
			}*/
		TEST_METHOD(PosaddPointToRouteTest1)
		{
			struct Route Map =
			{
					{
					{0,0},
					{1,0},{1,1}

					},
						3, BLUE
			};
			addPointToRoute(&Map, 1, 2);


			Assert::IsTrue((Map.points[3].row == 1) && (Map.points[3].col == 2));
			//Test to see if basic functionality of function works.
			//Post Results: Passed
		}
		TEST_METHOD(PosaddPointToRouteTest2)
		{
			struct Route Map =
			{
					{
					},
						0, BLUE
			};
			addPointToRoute(&Map, 0, 0);
			addPointToRoute(&Map, 1, 0);
			addPointToRoute(&Map, 2, 0);


			Assert::IsTrue((Map.points[0].row == 0) && (Map.points[0].col == 0) && (Map.points[1].row == 1) && (Map.points[1].col == 0) && (Map.points[2].row == 1) && (Map.points[2].col == 2));
			//Test to see if pathway can be made from this function alone or will you neeed a existing route.
			//Post Results: Failed
		}
		TEST_METHOD(NegaddPointToRouteTest1)
		{
			struct Route Map =
			{
					{
					{0,0},
					{1,0},{1,1}

					},
						3, BLUE
			};
			addPointToRoute(&Map, -1, -1);


			Assert::IsFalse((Map.points[3].row == -1) && (Map.points[3].col == -1));
			//Test to see if function takes in negative numbers which it shouldnt. Under the edge case
			//Post Results: Failed
		}
		TEST_METHOD(NegaddPointToRouteTest2)
		{
			struct Route Map =
			{
					{
					{0,0},
					{1,0},{1,1}

					},
						3, BLUE
			};
			addPointToRoute(&Map, 99, 99);


			Assert::IsFalse((Map.points[3].row == 99) && (Map.points[3].col == 99));
			//Test to see if function takes a coordinate outside the grid.
			//Post Results: Failed
		}
		TEST_METHOD(NegaddPointToRouteTest3)
		{
			struct Route Map =
			{
					{
					{0,0},
					{1,0},{1,1}

					},
						3, BLUE
			};
			addPointToRoute(&Map, 4, 5);


			Assert::IsFalse((Map.points[3].row == 4) && (Map.points[3].col == 5));
			//Test to see if function takes a coordinate that disconnects from path.
			//Post Results: Failed
		}
		TEST_METHOD(NegaddPointToRouteTest4)
		{
			struct Route Map =
			{
					{
					{0,0},
					{1,0},{1,1}

					},
						3, BLUE
			};
			addPointToRoute(&Map, 4.3, 5.6);


			Assert::IsTrue((Map.points[3].row == 4) && (Map.points[3].col == 6));
			//Test to see if function takes in double values which it shouldn't. It should round
			//Post Results: Failed
		}
		TEST_METHOD(NegaddPointToRouteTest5)
		{
			struct Route Map =
			{
					{
					{0,0},
					{1,0},{1,1}

					},
						3, BLUE
			};
			addPointToRoute(&Map, 1, 1);


			Assert::IsTrue((Map.points[3].row == 1) && (Map.points[3].col == 1));
			//Test to see if function takes in duplicate coordinates going backwards which it shouldn't.
			//Post Results: Passed
		}
		TEST_METHOD(NegaddPointToRouteTest6)
		{
			struct Route Map =
			{
					{
					{0,0},

					},
						1, BLUE
			};
			addPointToRoute(&Map, 0 / 2, 1);


			Assert::IsTrue((Map.points[3].row == 0) && (Map.points[3].col == 1));
			//Test to see if function can handle infinite reccursion or will it safely round down.
			//Post Results: 
		}
		TEST_METHOD(ShortPath001)
		{
			// Valid Path
			struct Map map5 = populateMap();
			struct Point start4 = { 0, 0 };
			struct Point dest4 = { 4, 3 };
			struct Route result1 = shortestPath(&map5, start4, dest4);

			// Define the expected route
			struct Point expectedRoute[MAX_ROUTE] = { {0, 0}, {0, 1}, {0, 2}, {1, 2}, {1, 3}, {2, 3}, {3, 3}, {4, 3} };
			int expectedLength = 8;

			// Assert that a valid path was found from start to destination
			Assert::IsTrue(result1.numPoints == expectedLength);

			// Compare each point in the route with the expected points
			for (int i = 0; i < expectedLength; i++)
			{
				Assert::AreEqual(expectedRoute[i].row, result1.points[i].row);
				Assert::AreEqual(expectedRoute[i].col, result1.points[i].col);
			}
		}

		TEST_METHOD(ShortPath002)
		{
			// Start and Destination Are the Same
			struct Map map2 = populateMap();
			struct Point start2 = { 0, 0 };
			struct Point dest2 = { 0, 0 };
			struct Route result2 = shortestPath(&map2, start2, dest2);
			// Assert that the path length is zero since start and destination are the same
			Assert::IsTrue(result2.numPoints == 0);
		}

		TEST_METHOD(ShortPath003)
		{
			//  No Valid Path
			struct Map map3 = populateMap();
			struct Point start3 = { 0, 0 };
			struct Point dest3 = { 1, 1 }; // Assuming (1, 1) is blocked by a building
			struct Route result3 = shortestPath(&map3, start3, dest3);
			// Assert that no valid path exists from start to destination
			Assert::IsTrue(result3.numPoints == 0);
		}

		TEST_METHOD(ShortPath004)
		{
			// another Valid Path
			struct Map map4 = populateMap();
			struct Point start4 = { 0, 0 };
			struct Point dest4 = { 2, 4 };
			struct Route result4 = shortestPath(&map4, start4, dest4);

			// Define the expected route
			struct Point expectedRoute[MAX_ROUTE] = { {0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 4}, {2, 4} };
			int expectedLength = 7;

			// Assert that a valid path was found from start to destination
			Assert::IsTrue(result4.numPoints == expectedLength);

			// Compare each point in the route with the expected points
			for (int i = 0; i < expectedLength; i++)
			{
				Assert::AreEqual(expectedRoute[i].row, result4.points[i].row);
				Assert::AreEqual(expectedRoute[i].col, result4.points[i].col);
			}
		}

		TEST_METHOD(ShortPath005)
		{
			//No Path, Same Start and Destination
			struct Map map5 = populateMap();
			struct Point start5 = { 2, 3 };
			struct Point dest5 = { 2, 3 }; // Same start and destination
			struct Route result5 = shortestPath(&map5, start5, dest5);

			// Assert that the path length is zero since start and destination are the same
			Assert::IsTrue(result5.numPoints == 0);
		}
		TEST_METHOD(TFW001)
		{
			int tester;
			tester = validateWeight(750);

			Assert::IsTrue(tester);
			//Post Result passed.
		}
		// Black Box. Tests to see the maximum input (1000 kilograms) should work correctly. (+)
		TEST_METHOD(TFW002)
		{
			int tester;
			tester = validateWeight(1000);

			Assert::IsTrue(tester);
			//Post Result: Passed
		}
		// Black Box. Tests to see the minimum input (1 kilogram) should work correctly. (+)
		TEST_METHOD(TFW003)
		{
			int tester;
			tester = validateWeight(1);

			Assert::IsTrue(tester);
			//Post Result: Passed
		}
		// Black Box. Tests to see if the input is less than the minimum input (less than 1 kilograms) should not work. (-)
		TEST_METHOD(TFW004)
		{
			int tester;
			tester = validateWeight(0);

			Assert::IsFalse(tester);
			//Post Result:Failed but this means that minimum is really 1 (no need to fix or report as this is what the functionn should do)
		}
		// Black Box. Tests to see if the input is over than maximum input. Should not work. (-)
		TEST_METHOD(TFW005)
		{
			int tester;
			tester = validateWeight(1001);

			Assert::IsFalse(tester);
			//Post Result: Passed
		}
		// Black Box. Tests to see if the input is a negative integer. Should not work. (-)
		TEST_METHOD(TFW006)
		{
			int tester;
			tester = validateWeight(-1);

			Assert::IsFalse(tester);
			//Post Result: Passed
		}
		// Black Box. Tests to see if the input is floating point number, should work corectly. (+)
		TEST_METHOD(TFW007)
		{
			int tester;
			tester = validateWeight(1.1);

			Assert::IsTrue(tester);
			//Post Result: Passed
		}
		// Black Box. Tests to see if the input is pass by pointer value. Should work correctly. (+)
		TEST_METHOD(TFW008)
		{
			int weight = 100;
			int* ptr = &weight;
			int tester;
			tester = validateWeight(*ptr);

			Assert::IsTrue(tester);
			//Post Result: Passed
		}
		// Black Box. Tests to see if the input is a equations. Should work correctly. (+)
		TEST_METHOD(TFW009)
		{
			int tester;
			tester = validateWeight(4 + 100);

			Assert::IsTrue(tester);
			//Post Result: Passed
		}
		// Black Box. Tests to see if the input is a member of the structs. Should work correctly. (+)
		TEST_METHOD(TFW010)
		{
			struct weight
			{
				int num;
			} test = { 1 };

			int tester;
			tester = validateWeight(test.num);

			Assert::IsTrue(tester);
			//Post Result: Failed
		}
		// Black Box. Tests to see if the input is NULL. Should not work. (-)
		TEST_METHOD(TFW011)
		{
			int tester;
			tester = validateWeight(NULL);

			Assert::IsFalse(tester);
			//Post Result: Passed
		}
		// Black Box. Tests to see if the input is larger than integer type can hold. Should not work. (-)
		TEST_METHOD(TFW012)
		{
			int tester;
			tester = validateWeight(2147483648);

			Assert::IsFalse(tester);
			//Post Results: Passed
		}
		// White Box. Tests to see the maximum input by passing the const value MAX_WEIGHT should work correctly. (+)
		TEST_METHOD(TFW013)
		{
			int tester;
			tester = validateWeight(MAX_WEIGHT);

			Assert::IsTrue(tester);
			//Post Results: Passed
		}
		// White Box. Tests to see the minimum input by passing the const value MIN_WEIGHT should not work. (-)
		TEST_METHOD(TFW014)
		{
			int tester;
			tester = validateWeight(MIN_WEIGHT);

			Assert::IsTrue(tester);
			//Post Results: Passed
		}
		// White Box. Test with a weight above the upper boundary by passing the constant value MAX_WEIGHT plus 1, should work correctly. (+)
		TEST_METHOD(TFW015)
		{
			int tester;
			tester = validateWeight(MAX_WEIGHT + 1);

			Assert::IsFalse(tester);
			//Post Results: Passed
		}
		// White Box. Test with a weight above the upper boundary by passing the constant value MIN_WEIGHT minus 1, should not work. (-)
		TEST_METHOD(TFW016)
		{
			int tester;
			tester = validateWeight(MIN_WEIGHT - 1);

			Assert::IsFalse(tester);
			//Post Results: Passed
		}

		/*Testing the validateBoxSize function. The size of the packages can be only 0.25, 0.5, 1.0 cubic meter.*/
		// Black Box. Tests the first allowed size (0.25 CUBIC METER) of the package. (+)
		TEST_METHOD(TFS001)
		{
			bool results = validateBoxSize(0.25);
			Assert::IsTrue(results);
			//Post Result: Passed
		}
		// Black Box. Tests the second allowed size (0.5 CUBIC METER) of the package. (+)
		TEST_METHOD(TFS002)
		{
			bool results = validateBoxSize(0.5);
			Assert::IsTrue(results);
			//Post Result: Passed
		}
		// Black Box. Tests the third allowed size (1.0 CUBIC METER) of the package. (+)
		TEST_METHOD(TFS003)
		{
			bool results = validateBoxSize(1.0);
			Assert::IsTrue(results);
			//Post Result: Passed
		}
		// Black Box. Tests the calculation that result in the allowed size of the package. (+)
		TEST_METHOD(TFS004)
		{
			bool results = validateBoxSize(0.25 + 0.25);
			Assert::IsTrue(results);
			//Post Result: Passed
		}
		// Black Box. Tests the round number that result in the allowed size of the package. (+)
		TEST_METHOD(TFS005)
		{
			bool results = validateBoxSize(1.0000000000000001);
			Assert::IsTrue(results);
			//Post Result: Passed
		}
		// Black Box. Tests the not allowed size of the package. (-)
		TEST_METHOD(TFS006)
		{
			bool results = validateBoxSize(0.35);
			Assert::IsFalse(results);
			//Post Result: Passed
		}
		// Black Box. Tests the empty size of the package. (-)
		TEST_METHOD(TFS007)
		{
			bool results = validateBoxSize(0);
			Assert::IsFalse(results);
			//Post Result: Passed
		}
		// Black Box. Tests the character input. (-)
		TEST_METHOD(TFS008)
		{
			bool results = validateBoxSize('A');
			Assert::IsFalse(results);
			//Post Result: Passed
		}
		// Black Box. Tests the NULL input. (-)
		TEST_METHOD(TFS009)
		{
			bool results = validateBoxSize(NULL);
			Assert::IsFalse(results);
			//Post Result: Passed
		}
		// Black Box. Tests the NULL character input. (-)
		TEST_METHOD(TFS010)
		{
			bool results = validateBoxSize('NULL');
			Assert::IsFalse(results);
			//Post Result: Passed
		}
		// Black Box. Test the escape sequence character. (-)
		TEST_METHOD(TFS011)
		{
			bool results = validateBoxSize('\n');
			Assert::IsFalse(results);
			//Post Result: Passed
		}
		// Black Box. Tests the precision of the input value. (-)
		TEST_METHOD(TFS012)
		{
			bool results = validateBoxSize(1.000000000000001);
			Assert::IsFalse(results);
			//Post Result: Passed
		}
		// Black Box. Tests the round number that result in the not allowed size of the package. (-)
		TEST_METHOD(TFS013)
		{
			bool results = validateBoxSize(1.0000000000000008);
			Assert::IsFalse(results);
			//Post Result: Passed
		}
		// White Box. Tests to see the valid input by passing the constant value QUARTER_CUBIC_METER (0.25) should work correctly. (-)
		TEST_METHOD(TFS014)
		{
			bool results = validateBoxSize(QUARTER_CUBIC_METER);
			Assert::IsTrue(results);
			//Post Result: Passed
		}
		// White Box. Tests to see the valid input by passing the constant value HALF_CUBIC_METER (0.5) should work correctly. (-)
		TEST_METHOD(TFS015)
		{
			bool results = validateBoxSize(HALF_CUBIC_METER);
			Assert::IsTrue(results);
			//Post Result: Passed
		}
		// White Box. Tests to see the valid input by passing the constant value ONE_CUBIC_METER (1.0) should work correctly. (-)
		TEST_METHOD(TFS016)
		{
			bool results = validateBoxSize(ONE_CUBIC_METER);
			Assert::IsTrue(results);
			//Post Result: Passed
		}

		/*Testing the validateVolume function. Total volume cannot be over 36 cubic meters.*/
		// Black Box. Tests to see the normal input should work correctly. (+)
		TEST_METHOD(TFV001)
		{
			struct Truck deliveryA = { {7,8}, 10, 5.0, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsTrue(tester);
			//Post Results: Passed
		}
		// Black Box. Tests to see the maximum input should work correctly. (+)
		TEST_METHOD(TFV002)
		{
			struct Truck deliveryA = { {7,8}, 10, 36.0, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsTrue(tester);
			//Post Results: Passed
		}
		// Black Box. Tests to see the minimum input should work correctly. (+)
		TEST_METHOD(TFV003)
		{
			struct Truck deliveryA = { {7,8}, 10, 0.25, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsTrue(tester);
			//Post Results:Passed
		}
		// Black Box. Tests to see if the input is less than the minimum input should not work. (-)
		TEST_METHOD(TFV004)
		{
			struct Truck deliveryA = { {7,8}, 10, 0, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsFalse(tester);
			//Post Results: Passed
		}
		// Black Box. Tests to see if the input is floating point number, should work corectly. (+)
		TEST_METHOD(TFV005)
		{
			struct Truck deliveryA = { {7,8}, 10,36.01, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsFalse(tester);
			//Post Results: Passed
		}
		// Black Box. Tests to see if the input is a negative integer. Should not work. (-)
		TEST_METHOD(TFV006)
		{
			struct Truck deliveryA = { {7,8}, 10,-9999, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsFalse(tester);
			//Post Results: Passed
		}
		// Tests to see if the input is larger than double type can hold. Should not work. (-)
		TEST_METHOD(TFV007)
		{
			struct Truck deliveryA = { {7,8}, 10,9999999999999999999, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsFalse(tester);
			//Post Results: Passed
		}
		// Tests to see if the input is a safety against infinite reursion from divison by 2 on 0. Should not work. (-)
		TEST_METHOD(TFV008)
		{
			struct Truck deliveryA = { {7,8}, 10,(0 / 2), 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsFalse(tester);
			//Post Results: Passed
		}
		// White Box. Test with a truck's maximum input of totalVolume by passing the constant value MAX_VOLUME should work correctly. (+)
		TEST_METHOD(TFV009)
		{
			struct Truck deliveryA = { {7,8}, 10, MAX_VOLUME, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsTrue(tester);
			//Post Results: Passed
		}
		// White Box. Test with a truck's maximum input of totalVolume by passing the constant value MAX_VOLUME plus 1, should work correctly. (-)
		TEST_METHOD(TFV010)
		{
			struct Truck deliveryA = { {7,8}, 10, MAX_VOLUME + 1, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsFalse(tester);
			//Post Results: Passed
		}
		// White Box. Tests to see if the input is NULL. Should not work. (-)
		TEST_METHOD(TFV011)
		{
			struct Truck deliveryA = { {7,8}, 10, NULL, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsFalse(tester);
			//Post Results: Passed
		}

		/*Testing the calculateLimitingFactor function. The limiting factor as a percentage (weight or volume) should be between 0 to 100.*/
		// Black Box. Tests to see the normal input, the return value should round and work correctly. By the return value should return the percentage of volume. (+)
		TEST_METHOD(TFL001)
		{
			struct Truck deliveryA = { {7,8}, 10, 15, 100, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, 41.67);
			//Post Results: Passed
		}
		// Black Box. Tests to see the normal input should work correctly. By the return value should return the percentage of weight. (+)
		TEST_METHOD(TFL002)
		{
			struct Truck deliveryA = { {7,8}, 10,15, 999, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, 99.90);
			//Post Results: Passed
		}
		// Black Box. Tests to see the maximum input of volume should work correctly. By the return value should return the percentage of volume. (+)
		TEST_METHOD(TFL003)
		{
			struct Truck deliveryA = { {7,8}, 10, 36, 500, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, 100.00);
			//Post Results: Passed
		}
		// Black Box. Tests to see the minimum input should work correctly. By the return value should return the percentage of weight. (+)
		TEST_METHOD(TFL004)
		{
			struct Truck deliveryA = { {7,8}, 10, 0.25, 1, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, 0.69);
			//Post Results: Passed
		}
		// Black Box. Tests to see the maximum of volume and minimum input of weight input should work correctly. By the return value should return the percentage of volume. (+)
		TEST_METHOD(TFL005)
		{
			struct Truck deliveryA = { {7,8}, 10, 36.0, 1, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, 100.00);
			//Post Results: Passed
		}
		// Black Box. Tests to see the maximum of volume and weight input should work correctly. By the return value should return the 100% without error. (+)
		TEST_METHOD(TFL006)
		{
			struct Truck deliveryA = { {7,8}, 10, 36.0, 1000, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, 100.00);
			//Post Results: Passed
		}
		// Black Box. Tests to see the function is accept one negative number of volume, and the weight is normal value. The function should return -1. (-)
		TEST_METHOD(TFL007)
		{
			struct Truck deliveryA = { {7,8}, 10, -36.0, 1000, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, -1.0);
			//Post Results: Passed
		}
		// Black Box. Tests to see the function accepts one negative number of weight, and the volume is normal value. The function should return -1. (-)
		TEST_METHOD(TFL008)
		{
			struct Truck deliveryA = { {7,8}, 10, 36.0, -150, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, -1.0);
			//Post Results: Passed
		}
		// Black Box. Tests to see if the input is over than maximum input of weight. The function should return -1. (-)
		TEST_METHOD(TFL009)
		{
			struct Truck deliveryA = { {7,8}, 10, 36.0, 1050, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, -1.0);
			//Post Results: Passed
		}
		// Black Box. Tests to see if the input is over than maximum input of volume. The function should return -1. (-)
		TEST_METHOD(TFL010)
		{
			struct Truck deliveryA = { {7,8}, 10, 37.0, 1000, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, -1.0);
			//Post Results: Passed
		}
		// Black Box. Tests to see the minimum of volume and weight input should work correctly. By the return value should return the 0% without error. (+)
		TEST_METHOD(TFL011)
		{
			struct Truck deliveryA = { {7,8}, 10, 0.25, 1, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, 0.69);
			//Post Results: Passed
		}
		// Black Box. Tests to see if program has safety precautions against infinite recursion numbers of volume. The function should return -1. (-)
		TEST_METHOD(TFL012)
		{
			struct Truck deliveryA = { {7,8}, 10, 0 / 2, 300, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, -1.0);
			//Post Results: Passed
		}
		// Black Box. Tests to see if program has safety precautions against infinite recursion numbers of weight. The function should return -1. (-)
		TEST_METHOD(TFL013)
		{
			struct Truck deliveryA = { {7,8}, 10,22, 0 / 2, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, -1.0);
			//Post Results: Passed
		}
		// White Box. Tests to see the maximum input by passing the constant value MAX_WEIGHT (1000), and normal input for total volumn should work correctly. (+)
		TEST_METHOD(TFL014)
		{
			struct Truck deliveryA = { {7,8}, 10, 18, MAX_WEIGHT, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, 100.00);
			//Post Results: Passed
		}
		// White Box. Tests to see the maximum input by passing the constant value MIN_WEIGHT (1), and normal input for volumn should work correctly. (+)
		TEST_METHOD(TFL015)
		{
			struct Truck deliveryA = { {7,8}, 10, 18, MIN_WEIGHT, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, 50.0);
			//Post Results: Passed
		}
		// White Box. Tests to see the maximum input by passing the constant value MAX_VOLUMN (36.0), and normal input for total weight should work correctly. (+)
		TEST_METHOD(TFL016)
		{
			struct Truck deliveryA = { {7,8}, 10, MAX_VOLUME, 500, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, 100.00);
			//Post Results: Passed
		}
		// White Box. Tests to see the maximum input by passing the constant value MAX_WEIGHT (1000), and MAX_VOLUMN (36.0) together awshould work correctly. (+)
		TEST_METHOD(TFL017)
		{
			struct Truck deliveryA = { {7,8}, 10, MAX_VOLUME, MAX_WEIGHT, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, 100.00);
			//Post Results: Passed
		}
		// White Box. Tests to see the maximum input by passing the constant value MAX_WEIGHT + 1 (1001), and normal input for total volumn. should not work. (-)
		TEST_METHOD(TFL018)
		{
			struct Truck deliveryA = { {7,8}, 10, 18, MAX_WEIGHT + 1, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, -1.0);
			//Post Results: Passed
		}
		// White Box. Tests to see the maximum input by passing the constant value MIN_WEIGHT - 1 (0), and normal input for volumn. should not work. (-)
		TEST_METHOD(TFL019)
		{
			struct Truck deliveryA = { {7,8}, 10, 18, MIN_WEIGHT - 1, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, -1.0);
			//Post Results: Passed
		}
		// White Box. Tests to see the maximum input by passing the constant value MAX_VOLUMN + 0.25 (36.25), and normal input for total weight. should not work. (-)
		TEST_METHOD(TFL020)
		{
			struct Truck deliveryA = { {7,8}, 10, MAX_VOLUME + 0.25, 500, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, -1.0);
			//Post Results: Passed
		}
		// White Box. Tests to see the NULL input of total volume. The function should return the -1. (-)
		TEST_METHOD(TFL021)
		{
			struct Truck deliveryA = { {7,8}, 10, NULL, 500, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, -1.0);
			//Post Results: Passed
		}
		// White Box. Tests to see the NULL input of total weight. The function should return the -1. (-)
		TEST_METHOD(TFL022)
		{
			struct Truck deliveryA = { {7,8}, 10, 18.0, NULL, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);

			Assert::AreEqual(tester, -1.0);
			//Post Results: Passed
		}
		TEST_METHOD(TFG001)
		{

			// Arrange: Prepare the test data
			struct Map map = populateMap();

			// Initialize the map and its values for testing

			struct Point p1 = { 0,0 };
			struct Point backpath = { 0,3 };

			// Act: Call the function to be tested
			struct Route result = getPossibleMoves(&map, p1, backpath);

			Assert::IsTrue(result.numPoints == 2);

			struct Point expectedPoints[] = { {0,1}, { 1,0 } };

			// Log the actual results to the test output
			Logger::WriteMessage(("Actual numPoints: " + std::to_string(result.numPoints)).c_str());

			for (int i = 0; i < result.numPoints; i++)
			{
				Logger::WriteMessage(("Actual point[" + std::to_string(i) + "]: {" +
					std::to_string(result.points[i].row) + ", " +
					std::to_string(result.points[i].col) + "}").c_str());
			}

			bool areEqual = std::equal(result.points, result.points + result.numPoints, expectedPoints,
				[](const struct Point& p1, const struct Point& p2) {
					return p1.row == p2.row && p1.col == p2.col;
				});

			Assert::IsTrue(areEqual);
		}

		TEST_METHOD(TFG002)
		{
			// Arrange: Prepare the test data
			struct Map map = populateMap();

			// Initialize the map and its values for testing

			struct Point p1 = { 0,0 };
			struct Point backpath = { 5,0 };

			// Act: Call the function to be tested
			struct Route result = getPossibleMoves(&map, p1, backpath);

			Assert::IsTrue(result.numPoints == 2);

			struct Point expectedPoints[] = { {0, 1}, {1, 0} };

			// Log the actual results to the test output
			Logger::WriteMessage(("Actual numPoints: " + std::to_string(result.numPoints)).c_str());

			for (int i = 0; i < result.numPoints; i++)
			{
				Logger::WriteMessage((" Actual point[" + std::to_string(i) + "]: {" +
					std::to_string(result.points[i].row) + ", " +
					std::to_string(result.points[i].col) + "}").c_str());
			}

			bool areEqual = std::equal(result.points, result.points + result.numPoints, expectedPoints,
				[](const struct Point& p1, const struct Point& p2) {
					return p1.row == p2.row && p1.col == p2.col;
				});

			Assert::IsTrue(areEqual);
		}

		TEST_METHOD(TFG003)
		{
			// Arrange: Prepare the test data
			struct Map map = populateMap();

			// Initialize the map and its values for testing

			struct Point p1 = { 0,0 };
			struct Point backpath = { 1,1 };

			// Act: Call the function to be tested
			struct Route result = getPossibleMoves(&map, p1, backpath);

			Assert::IsTrue(result.numPoints == 2);

			struct Point expectedPoints[] = { {0, 1}, {1, 0} };

			// Log the actual results to the test output
			Logger::WriteMessage(("Actual numPoints: " + std::to_string(result.numPoints)).c_str());

			for (int i = 0; i < result.numPoints; i++)
			{
				Logger::WriteMessage(("Actual point[" + std::to_string(i) + "]: {" +
					std::to_string(result.points[i].row) + ", " +
					std::to_string(result.points[i].col) + "}").c_str());
			}

			bool areEqual = std::equal(result.points, result.points + result.numPoints, expectedPoints,
				[](const struct Point& p1, const struct Point& p2) {
					return p1.row == p2.row && p1.col == p2.col;
				});

			Assert::IsTrue(areEqual);
		}

		TEST_METHOD(TFG004)
		{
			// Arrange: Prepare the test data
			struct Map map = populateMap();

			// Initialize the map and its values for testing

			struct Point p1 = { 0,24 };
			struct Point backpath = { 20,0 };

			// Act: Call the function to be tested
			struct Route result = getPossibleMoves(&map, p1, backpath);

			Assert::IsTrue(result.numPoints == 3);

			struct Point expectedPoints[] = { {0, 23}, {1, 24}, {1,23} };

			// Log the actual results to the test output
			Logger::WriteMessage(("Actual numPoints: " + std::to_string(result.numPoints)).c_str());

			for (int i = 0; i < result.numPoints; i++)
			{
				Logger::WriteMessage(("Actual point[" + std::to_string(i) + "]: {" +
					std::to_string(result.points[i].row) + ", " +
					std::to_string(result.points[i].col) + "}").c_str());
			}

			bool areEqual = std::equal(result.points, result.points + result.numPoints, expectedPoints,
				[](const struct Point& p1, const struct Point& p2) {
					return p1.row == p2.row && p1.col == p2.col;
				});

			Assert::IsTrue(areEqual);
		}

		TEST_METHOD(TFG005)
		{
			// Arrange: Prepare the test data
			struct Map map = populateMap();

			// Initialize the map and its values for testing

			struct Point p1 = { 24,0 };
			struct Point backpath = { 20,0 };

			// Act: Call the function to be tested
			struct Route result = getPossibleMoves(&map, p1, backpath);

			Assert::IsTrue(result.numPoints == 1);

			struct Point expectedPoints[] = { {23, 0} };

			// Log the actual results to the test output
			Logger::WriteMessage(("Actual numPoints: " + std::to_string(result.numPoints)).c_str());

			for (int i = 0; i < result.numPoints; i++)
			{
				Logger::WriteMessage(("Actual point[" + std::to_string(i) + "]: {" +
					std::to_string(result.points[i].row) + ", " +
					std::to_string(result.points[i].col) + "}").c_str());
			}

			bool areEqual = std::equal(result.points, result.points + result.numPoints, expectedPoints,
				[](const struct Point& p1, const struct Point& p2) {
					return p1.row == p2.row && p1.col == p2.col;
				});

			Assert::IsTrue(areEqual);
		}

		TEST_METHOD(TFG006)
		{
			// Arrange: Prepare the test data
			struct Map map = populateMap();

			// Initialize the map and its values for testing

			struct Point p1 = { 24,24 };
			struct Point backpath = { 0,0 };

			// Act: Call the function to be tested
			struct Route result = getPossibleMoves(&map, p1, backpath);

			Assert::IsTrue(result.numPoints == 1);

			struct Point expectedPoints[] = { {24, 23} };

			// Log the actual results to the test output
			Logger::WriteMessage(("Actual numPoints: " + std::to_string(result.numPoints)).c_str());

			for (int i = 0; i < result.numPoints; i++)
			{
				Logger::WriteMessage(("Actual point[" + std::to_string(i) + "]: {" +
					std::to_string(result.points[i].row) + ", " +
					std::to_string(result.points[i].col) + "}").c_str());
			}

			bool areEqual = std::equal(result.points, result.points + result.numPoints, expectedPoints,
				[](const struct Point& p1, const struct Point& p2) {
					return p1.row == p2.row && p1.col == p2.col;
				});

			Assert::IsTrue(areEqual);
		}

		TEST_METHOD(TFG007)
		{
			// Arrange: Prepare the test data
			struct Map map = populateMap();

			// Initialize the map and its values for testing

			struct Point p1 = { 0,4 };
			struct Point backpath = { 3,3 };

			// Act: Call the function to be tested
			struct Route result = getPossibleMoves(&map, p1, backpath);

			Assert::IsTrue(result.numPoints == 2);

			struct Point expectedPoints[] = { {0, 3}, {1, 3} };

			// Log the actual results to the test output
			Logger::WriteMessage(("Actual numPoints: " + std::to_string(result.numPoints)).c_str());

			for (int i = 0; i < result.numPoints; i++)
			{
				Logger::WriteMessage(("Actual point[" + std::to_string(i) + "]: {" +
					std::to_string(result.points[i].row) + ", " +
					std::to_string(result.points[i].col) + "}").c_str());
			}

			bool areEqual = std::equal(result.points, result.points + result.numPoints, expectedPoints,
				[](const struct Point& p1, const struct Point& p2) {
					return p1.row == p2.row && p1.col == p2.col;
				});

			Assert::IsTrue(areEqual);
		}

		TEST_METHOD(TFG008)
		{
			// Arrange: Prepare the test data
			struct Map map = populateMap();

			// Initialize the map and its values for testing

			struct Point p1 = { 0,3 };
			struct Point backpath = { 3,3 };

			// Act: Call the function to be tested
			struct Route result = getPossibleMoves(&map, p1, backpath);

			Assert::IsTrue(result.numPoints == 2);

			struct Point expectedPoints[] = { {0, 2}, {1, 3} };

			// Log the actual results to the test output
			Logger::WriteMessage(("Actual numPoints: " + std::to_string(result.numPoints)).c_str());

			for (int i = 0; i < result.numPoints; i++)
			{
				Logger::WriteMessage(("Actual point[" + std::to_string(i) + "]: {" +
					std::to_string(result.points[i].row) + ", " +
					std::to_string(result.points[i].col) + "}").c_str());
			}

			bool areEqual = std::equal(result.points, result.points + result.numPoints, expectedPoints,
				[](const struct Point& p1, const struct Point& p2) {
					return p1.row == p2.row && p1.col == p2.col;
				});

			Assert::IsTrue(areEqual);
		}

		TEST_METHOD(TFG009)
		{
			// Arrange: Prepare the test data
			struct Map map = populateMap();

			// Initialize the map and its values for testing
			//
			struct Point p1 = { 16,7 };
			struct Point backpath = { 10,6 };

			// Act: Call the function to be tested
			struct Route result = getPossibleMoves(&map, p1, backpath);

			Assert::IsTrue(result.numPoints = ' ');

			//struct Point expectedPoints[MAX_POINT] = {};

			// Log the actual results to the test output
			/*Logger::WriteMessage(("Actual numPoints: " + std::to_string(result.numPoints)).c_str());
			for (int i = 0; i < result.numPoints; i++)
			{
				Logger::WriteMessage(("Actual point[" + std::to_string(i) + "]: {" +
					std::to_string(result.points[i].row) + ", " +
					std::to_string(result.points[i].col) + "}").c_str());
			}
			bool areEqual = std::equal(result.points, result.points + result.numPoints, expectedPoints,
				[](const struct Point& p1, const struct Point& p2) {
					return p1.row == p2.row && p1.col == p2.col;
				});*/

				//Assert::IsTrue(areEqual);
		}

		TEST_METHOD(TFG010)
		{
			// Arrange: Prepare the test data
			struct Map map = populateMap();

			// Initialize the map and its values for testing

			struct Point p1 = { 16,6 };
			struct Point backpath = { 10,5 };

			// Act: Call the function to be tested
			struct Route result = getPossibleMoves(&map, p1, backpath);

			Assert::IsTrue(result.numPoints == 3);

			struct Point expectedPoints[] = { {15, 5}, {16, 5}, {17,5} };

			// Log the actual results to the test output
			Logger::WriteMessage(("Actual numPoints: " + std::to_string(result.numPoints)).c_str());

			for (int i = 0; i < result.numPoints; i++)
			{
				Logger::WriteMessage(("Actual point[" + std::to_string(i) + "]: {" +
					std::to_string(result.points[i].row) + ", " +
					std::to_string(result.points[i].col) + "}").c_str());
			}

			bool areEqual = std::equal(result.points, result.points + result.numPoints, expectedPoints,
				[](const struct Point& p1, const struct Point& p2) {
					return p1.row == p2.row && p1.col == p2.col;
				});

			Assert::IsTrue(areEqual);
		}

		TEST_METHOD(TFG011)
		{
			// Arrange: Prepare the test data
			struct Map map = populateMap();

			// Initialize the map and its values for testing

			struct Point p1 = { 19,3 };
			struct Point backpath = { 15,5 };

			// Act: Call the function to be tested
			struct Route result = getPossibleMoves(&map, p1, backpath);

			Assert::IsTrue(result.numPoints == 8);

			struct Point expectedPoints[] = { {18,3}, {18,2}, {18,4}, {19,2}, {19,4}, {20,3}, {20,2}, {20,4} };

			// Log the actual results to the test output
			Logger::WriteMessage(("Actual numPoints: " + std::to_string(result.numPoints)).c_str());

			for (int i = 0; i < result.numPoints; i++)
			{
				Logger::WriteMessage(("Actual point[" + std::to_string(i) + "]: {" +
					std::to_string(result.points[i].row) + ", " +
					std::to_string(result.points[i].col) + "}").c_str());
			}

			bool areEqual = std::equal(result.points, result.points + result.numPoints, expectedPoints,
				[](const struct Point& p1, const struct Point& p2) {
					return p1.row == p2.row && p1.col == p2.col;
				});

			Assert::IsTrue(areEqual);
		}

		TEST_METHOD(TFG012)
		{
			// Arrange: Prepare the test data
			struct Map map = populateMap();

			// Initialize the map and its values for testing

			struct Point p1 = { 0,3 };
			struct Point backpath = { -1,-1 };

			// Act: Call the function to be tested
			struct Route result = getPossibleMoves(&map, p1, backpath);

			Assert::IsTrue(result.numPoints == 2);

			//struct Point expectedPoints[MAX_POINT] = { {18,3}, {18,2}, {18,4}, {19,2}, {19,4}, {20,3}, {20,2}, {20,4} };

			//// Log the actual results to the test output
			//Logger::WriteMessage(("Actual numPoints: " + std::to_string(result.numPoints)).c_str());

			//for (int i = 0; i < result.numPoints; i++)
			//{
			//	Logger::WriteMessage(("Actual point[" + std::to_string(i) + "]: {" +
			//		std::to_string(result.points[i].row) + ", " +
			//		std::to_string(result.points[i].col) + "}").c_str());
			//}

			//bool areEqual = std::equal(result.points, result.points + result.numPoints, expectedPoints,
			//	[](const struct Point& p1, const struct Point& p2) {
			//		return p1.row == p2.row && p1.col == p2.col;
			//	});

			//Assert::IsTrue(areEqual);
		}

		TEST_METHOD(TFG013)
		{
			// Arrange: Prepare the test data
			struct Map map = populateMap();

			// Initialize the map and its values for testing

			struct Point p1 = { 19,3 };
			struct Point backpath = { 50,27 };

			// Act: Call the function to be tested
			struct Route result = getPossibleMoves(&map, p1, backpath);

			Assert::IsTrue(result.numPoints == 8);

			//struct Point expectedPoints[MAX_POINT] = { {18,3}, {18,2}, {18,4}, {19,2}, {19,4}, {20,3}, {20,2}, {20,4} };

			//// Log the actual results to the test output
			//Logger::WriteMessage(("Actual numPoints: " + std::to_string(result.numPoints)).c_str());

			//for (int i = 0; i < result.numPoints; i++)
			//{
			//	Logger::WriteMessage(("Actual point[" + std::to_string(i) + "]: {" +
			//		std::to_string(result.points[i].row) + ", " +
			//		std::to_string(result.points[i].col) + "}").c_str());
			//}

			//bool areEqual = std::equal(result.points, result.points + result.numPoints, expectedPoints,
			//	[](const struct Point& p1, const struct Point& p2) {
			//		return p1.row == p2.row && p1.col == p2.col;
			//	});

			//Assert::IsTrue(areEqual);
		}

		TEST_METHOD(TFG014)
		{
			// Arrange: Prepare the test data
			struct Map map = populateMap();

			// Initialize the map and its values for testing

			struct Point p1 = { 0,0 };
			struct Point backpath = { 0,0 };

			// Act: Call the function to be tested
			struct Route result = getPossibleMoves(&map, p1, backpath);

			Assert::IsTrue(result.numPoints > 0);

			//struct Point expectedPoints[MAX_POINT] = {};

			//// Log the actual results to the test output
			Logger::WriteMessage(("Actual numPoints: " + std::to_string(result.numPoints)).c_str());

			//for (int i = 0; i < result.numPoints; i++)
			//{
			//	Logger::WriteMessage(("Actual point[" + std::to_string(i) + "]: {" +
			//		std::to_string(result.points[i].row) + ", " +
			//		std::to_string(result.points[i].col) + "}").c_str());
			//}

			//bool areEqual = std::equal(result.points, result.points + result.numPoints, expectedPoints,
			//	[](const struct Point& p1, const struct Point& p2) {
			//		return p1.row == p2.row && p1.col == p2.col;
			//	});

			//Assert::IsTrue(areEqual);
		}

		// Tessting the function "distance"

		TEST_METHOD(TFD001)
		{
			struct Point p1 = { 1, 3 };
			struct Point p2 = { 3, 3 };

			double result = distance(&p1, &p2);

			Logger::WriteMessage(("Actual Result: " + std::to_string(result)).c_str());

			double expectedDistance = 2.0;
			Assert::AreEqual(expectedDistance, result, 0.001);
		}

		TEST_METHOD(TFD002)
		{
			struct Point p1 = { -2, 5 };
			struct Point p2 = { 3, -1 };

			double result = distance(&p1, &p2);

			Logger::WriteMessage(("Actual Result: " + std::to_string(result)).c_str());

			double expectedDistance = sqrt(65.0);
			Assert::AreEqual(expectedDistance, result, 0.001);
		}

		TEST_METHOD(TFD003)
		{
			struct Point p1 = { 0, 0 };
			struct Point p2 = { 0, 0 };

			double result = distance(&p1, &p2);

			Logger::WriteMessage(("Actual Result: " + std::to_string(result)).c_str());

			double expectedDistance = 0.0;
			Assert::AreEqual(expectedDistance, result, 0.001);
		}

		TEST_METHOD(TFD004)
		{
			struct Point p1 = { 1000, 2000 };
			struct Point p2 = { 3000, 4000 };

			double result = distance(&p1, &p2);

			Logger::WriteMessage(("Actual Result: " + std::to_string(result)).c_str());

			double expectedDistance = sqrt(20000000.0);
			Assert::AreEqual(expectedDistance, result, 0.001);
		}

		TEST_METHOD(TFD005)
		{
			struct Point p1 = { 1, 1 };
			struct Point p2 = { 4, 5 };

			double result = distance(&p1, &p2);

			Logger::WriteMessage(("Actual Result: " + std::to_string(result)).c_str());

			double expectedDistance = sqrt(18.0);
			Assert::AreEqual(expectedDistance, result, 0.001);
		}

		TEST_METHOD(TFD006)
		{
			struct Point p1 = { -2, -3 };
			struct Point p2 = { -5, -5 };

			double result = distance(&p1, &p2);

			Logger::WriteMessage(("Actual Result: " + std::to_string(result)).c_str());

			double expectedDistance = sqrt(13.0);
			Assert::AreEqual(expectedDistance, result, 0.001);
		}
		TEST_METHOD(TFL001S)
		{
			struct Map map;
			map.numRows = 5;
			map.numCols = 5;
			int squares[5][5] = {
				{1, 1, 1, 1, 1},
				{1, 0, 0, 1, 1},
				{1, 0, 1, 1, 1},
				{1, 1, 1, 0, 1},
				{1, 1, 1, 1, 1}
			};
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					map.squares[i][j] = squares[i][j];

			struct Point destination = { 1, 1 };

			int result = validateLocation(&map, &destination);

			Assert::IsTrue(result == 1);
		}

		TEST_METHOD(TFL002S)
		{
			struct Map map;
			map.numRows = 5;
			map.numCols = 5;
			int squares[5][5] = {
				{1, 1, 1, 1, 1},
				{1, 0, 0, 1, 1},
				{1, 0, 1, 1, 1},
				{1, 1, 1, 0, 1},
				{1, 1, 1, 1, 1}
			};
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					map.squares[i][j] = squares[i][j];
			struct Point destination = { 2, 2 }; // Invalid location (0-indexed)

			int result = validateLocation(&map, &destination);

			Assert::IsTrue(result == 0);
		}

		TEST_METHOD(TFL004S)
		{
			struct Map map;
			map.numRows = 5;
			map.numCols = 5;
			int squares[5][5] = {
				{1, 1, 1, 1, 1},
				{1, 0, 0, 1, 1},
				{1, 0, 1, 1, 1},
				{1, 1, 1, 0, 1},
				{1, 1, 1, 1, 1}
			};
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					map.squares[i][j] = squares[i][j];

			struct Point destination1 = { -1, 2 }; // Invalid location (negative row)
			struct Point destination2 = { 6, 3 };  // Invalid location (exceeding row)
			struct Point destination3 = { 1, 2 };  // Valid location

			int result1 = validateLocation(&map, &destination1);
			int result2 = validateLocation(&map, &destination2);
			int result3 = validateLocation(&map, &destination3);

			Assert::IsTrue(result1 == 0);
			Assert::IsTrue(result2 == 0);
			Assert::IsTrue(result3 == 1);
		}

		TEST_METHOD(TFT001)
		{
			struct Truck truck1 = { 1, 10, 5 };
			struct Truck truck2 = { 2, 15, 4 };
			struct Truck trucks[] = { truck1, truck2 };
			struct Input input;
			for (int i = 0; i < 2; i++)
				input.trucks[i] = trucks[i];

			input.numTrucks = 2;
			int weight = 5;
			double size = 3.5;
			struct Point destination = { 3, 3 };

			struct Truck* result = findAvailableTruck(&input, weight, size, destination);

			Assert::IsNotNull(result);
		}

		TEST_METHOD(TFT002)
		{
			struct Truck truck1 = { 1, 10, 5 };
			struct Truck truck2 = { 2, 15, 4 };
			struct Truck trucks[] = { truck1, truck2 };
			struct Input input;

			for (int i = 0; i < 2; i++)
				input.trucks[i] = trucks[i];

			input.numTrucks = 2;
			int weight = 6; // Exceeding truck capacity
			double size = 3.5;
			struct Point destination = { 3, 3 };

			struct Truck* result = findAvailableTruck(&input, weight, size, destination);

			Assert::IsNull(result);
		}

		TEST_METHOD(TFT003)
		{
			struct Truck truck1 = { 1, 10, 5 }; // Full truck
			struct Truck truck2 = { 2, 20, 10 }; // Full truck
			struct Truck trucks[] = { truck1, truck2 };
			struct Input input;

			for (int i = 0; i < 2; i++)
				input.trucks[i] = trucks[i];

			input.numTrucks = 2;
			int weight = 5;
			double size = 3.5;
			struct Point destination = { 3, 3 };

			struct Truck* result = findAvailableTruck(&input, weight, size, destination);

			Assert::IsNull(result);
		}

		TEST_METHOD(TFT004)
		{
			struct Truck truck1 = { 1, 20, 10 }; // Full truck
			struct Truck truck2 = { 2, 15, 4 };  // Available truck
			struct Truck trucks[] = { truck1, truck2 };
			struct Input input;

			for (int i = 0; i < 2; i++)
				input.trucks[i] = trucks[i];

			input.numTrucks = 2;
			int weight = 5;
			double size = 3.5;
			struct Point destination = { 3, 3 };

			struct Truck* result = findAvailableTruck(&input, weight, size, destination);

			Assert::IsNotNull(result);
		}

		TEST_METHOD(TFT005)
		{
			struct Truck truck1 = { 1, 10, 5 }; // Full truck
			struct Truck truck2 = { 2, 20, 10 }; // Full truck
			struct Truck trucks[] = { truck1, truck2 };
			struct Input input;

			for (int i = 0; i < 2; i++)
				input.trucks[i] = trucks[i];

			input.numTrucks = 2;
			int weight = 5;
			double size = 3.5;
			struct Point destination = { 3, 3 };

			struct Truck* result = findAvailableTruck(&input, weight, size, destination);

			Assert::IsNull(result);
		}

		TEST_METHOD(TFT006)
		{
			struct Truck truck1 = { 1, 10, 5 }; // Available truck
			struct Truck truck2 = { 2, 15, 4 }; // Available truck with more capacity
			struct Truck trucks[] = { truck1, truck2 };
			struct Input input;

			for (int i = 0; i < 2; i++)
				input.trucks[i] = trucks[i];

			input.numTrucks = 2;
			int weight = 5;
			double size = 3.5;
			struct Point destination = { 3, 3 };

			struct Truck* result = findAvailableTruck(&input, weight, size, destination);

			Assert::IsNotNull(result);
		}

	};
}
