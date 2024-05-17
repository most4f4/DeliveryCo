
#include "pch.h"
#include "CppUnitTest.h"
#include "G5MS6_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace G5MS6AcceptanceTests
{
	TEST_CLASS(G5MS6AcceptanceTests)
	{
	public:
		// Wilson part.
		TEST_METHOD(FNLPOS001)
		{
			struct Point goTo = { 3,0 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {package},3, 10.0, 10, 0.0 };
			struct Truck truckB = { {package},3, 0.0, 10203293029302930,0.0 };
			struct Truck truckC = { {package},3, 90232.0, 0,0.0 };
			struct Map landScape = {
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 1, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};
			struct Route testRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0}

					},
						3, 2
			};
			struct Map expectedMap = {
					{
				{2, 0, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 1, 1, 0, 1},	//2
				{16, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Input testData = { {truckA,truckB,truckC},3,landScape };
			struct Truck* truckToDeploy = nullptr;
			struct Map outcomeMap;
			int index = 0;

			outcomeMap = addRoute(&landScape, &testRoute);
			for (int i = 0; i < testData.numTrucks; i++)
			{
				testData.trucks[i].limitingFactor = calculateLimitingFactor(&testData.trucks[i]);
			}

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateLocation(&landScape, &package.destination))
					{
						index = findAvailableTruck(&testData, package.weight, package.size);
						truckToDeploy = &testData.trucks[index];
						outcomeMap = addRoute(&outcomeMap, &pathToUse);
					}
				}
			}

			Assert::IsTrue(truckToDeploy->boxes[0].destination.row == testData.trucks[0].boxes[0].destination.row);
			Assert::IsTrue(truckToDeploy->boxes[0].destination.col == testData.trucks[0].boxes[0].destination.col);
			Assert::IsTrue(truckToDeploy->boxes[0].size == testData.trucks[0].boxes[0].size);
			Assert::IsTrue(truckToDeploy->boxes[0].weight == testData.trucks[0].boxes[0].weight);
			Assert::IsTrue(truckToDeploy->limitingFactor == testData.trucks[0].limitingFactor);
			Assert::IsTrue(truckToDeploy->numBoxes == testData.trucks[0].numBoxes);
			Assert::IsTrue(truckToDeploy->totalVolume == testData.trucks[0].totalVolume);
			Assert::IsTrue(truckToDeploy->totalWeight == testData.trucks[0].totalWeight);
		}
		TEST_METHOD(FNLPOS002)
		{
			struct Point goTo = { 3,0 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {package},3, 10.0, 10, 0.0 };
			struct Truck truckB = { {package},3, 0.0, 5,0.0 };
			struct Truck truckC = { {package},3, 0.0, 0,0.0 };
			struct Map landScape = {
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 1, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};
			struct Route testRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0}

					},
						3, 2
			};
			struct Map expectedMap = {
					{
				{2, 0, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 1, 1, 0, 1},	//2
				{16, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Input testData = { {truckA,truckB,truckC},3,landScape };
			struct Truck* truckToDeploy = nullptr;
			struct Map outcomeMap;
			int index = 0;

			outcomeMap = addRoute(&landScape, &testRoute);
			for (int i = 0; i < testData.numTrucks; i++)
			{
				testData.trucks[i].limitingFactor = calculateLimitingFactor(&testData.trucks[i]);
			}

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateLocation(&landScape, &package.destination))
					{
						index = findAvailableTruck(&testData, package.weight, package.size);
						truckToDeploy = &testData.trucks[index];
						outcomeMap = addRoute(&outcomeMap, &pathToUse);
					}
				}
			}

			Assert::IsTrue(truckToDeploy->boxes[0].destination.row == testData.trucks[0].boxes[0].destination.row);
			Assert::IsTrue(truckToDeploy->boxes[0].destination.col == testData.trucks[0].boxes[0].destination.col);
			Assert::IsTrue(truckToDeploy->boxes[0].size == testData.trucks[0].boxes[0].size);
			Assert::IsTrue(truckToDeploy->boxes[0].weight == testData.trucks[0].boxes[0].weight);
			Assert::IsTrue(truckToDeploy->limitingFactor == testData.trucks[0].limitingFactor);
			Assert::IsTrue(truckToDeploy->numBoxes == testData.trucks[0].numBoxes);
			Assert::IsTrue(truckToDeploy->totalVolume == testData.trucks[0].totalVolume);
			Assert::IsTrue(truckToDeploy->totalWeight == testData.trucks[0].totalWeight);
		}
		TEST_METHOD(FNLPOS003)
		{
			struct Point goTo = { 3,0 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {package},3, 10.0, 10, 0.0 };
			struct Truck truckB = { {package},3, 0.0, 5,0.0 };
			struct Truck truckC = { {package},3, 0.0, 0,0.0 };
			struct Map landScape = {
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 1, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};
			struct Route testRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0}

					},
						3, 2
			};
			struct Map expectedMap = {
					{
				{2, 0, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 1, 1, 0, 1},	//2
				{16, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Input testData = { {truckA,truckB,truckC},4,landScape };
			struct Truck* truckToDeploy = nullptr;
			struct Map outcomeMap;
			int index = 0;

			outcomeMap = addRoute(&landScape, &testRoute);
			for (int i = 0; i < testData.numTrucks; i++)
			{
				testData.trucks[i].limitingFactor = calculateLimitingFactor(&testData.trucks[i]);
			}

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateLocation(&landScape, &package.destination))
					{
						index = findAvailableTruck(&testData, package.weight, package.size);
						truckToDeploy = &testData.trucks[index];
						outcomeMap = addRoute(&outcomeMap, &pathToUse);
					}
				}
			}

			Assert::IsTrue(truckToDeploy->boxes[0].destination.row == testData.trucks[0].boxes[0].destination.row);
			Assert::IsTrue(truckToDeploy->boxes[0].destination.col == testData.trucks[0].boxes[0].destination.col);
			Assert::IsTrue(truckToDeploy->boxes[0].size == testData.trucks[0].boxes[0].size);
			Assert::IsTrue(truckToDeploy->boxes[0].weight == testData.trucks[0].boxes[0].weight);
			Assert::IsTrue(truckToDeploy->limitingFactor == testData.trucks[0].limitingFactor);
			Assert::IsTrue(truckToDeploy->numBoxes == testData.trucks[0].numBoxes);
			Assert::IsTrue(truckToDeploy->totalVolume == testData.trucks[0].totalVolume);
			Assert::IsTrue(truckToDeploy->totalWeight == testData.trucks[0].totalWeight);
		}
		TEST_METHOD(FNLPOS004)
		{
			int tester = 0;
			struct Point goTo = { 3,0 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {package},3, 36.0, 1000, 0.0 };
			struct Truck truckB = { {package},3, 36.0, 1000,0.0 };
			struct Truck truckC = { {package},3, 36.0, 1000,0.0 };
			struct Map landScape = {
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 1, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};
			struct Route testRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0}

					},
						3, 2
			};
			struct Map expectedMap = {
					{
				{2, 0, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 1, 1, 0, 1},	//2
				{16, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Input testData = { {truckA,truckB,truckC},3,landScape };
			struct Truck* truckToDeploy = nullptr;
			struct Map outcomeMap;
			int index = 0;

			outcomeMap = addRoute(&landScape, &testRoute);
			for (int i = 0; i < testData.numTrucks; i++)
			{
				testData.trucks[i].limitingFactor = calculateLimitingFactor(&testData.trucks[i]);
			}

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateLocation(&landScape, &package.destination))
					{
						index = findAvailableTruck(&testData, package.weight, package.size);
						if (index >= 0)
						{
							truckToDeploy = &testData.trucks[index];
							tester = 1;
						}

						outcomeMap = addRoute(&outcomeMap, &pathToUse);
					}
				}
			}

			Assert::IsTrue(tester == 0);

		}
		TEST_METHOD(FNLPOS005)
		{
			int tester = 0, counter = 0;
			struct Point goTo = { 4,4 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {package},3, 0.0, 0, 0.0 };
			struct Truck truckB = { {package},3, 36.0, 1000,0.0 };
			struct Truck truckC = { {package},3, 36.0, 1000,0.0 };
			struct Map landScape = {
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 1, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};
			struct Route testRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0}

					},
						3, 2
			};
			struct Map expectedMap = {
					{
				{2, 0, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 1, 1, 0, 1},	//2
				{16, 16, 16, 16, 16},	//3
				{0, 0, 0, 0, 16},	//4
				{0, 0, 0, 0, 16}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Input testData = { {truckA,truckB,truckC},3,landScape };
			struct Truck* truckToDeploy = nullptr;
			struct Map outcomeMap;
			int index = 0;

			outcomeMap = addRoute(&landScape, &testRoute);
			for (int i = 0; i < testData.numTrucks; i++)
			{
				testData.trucks[i].limitingFactor = calculateLimitingFactor(&testData.trucks[i]);
			}

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateLocation(&landScape, &package.destination))
					{
						index = findAvailableTruck(&testData, package.weight, package.size);
						if (index >= 0)
						{
							truckToDeploy = &testData.trucks[index];
							tester = 1;
						}

						outcomeMap = addRoute(&outcomeMap, &pathToUse);
					}
				}
			}

			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == outcomeMap.squares[i][k])
					{
						counter++;
					}
				}
			}
			Assert::IsTrue(counter == 25);

		}
		TEST_METHOD(FNLNEG001)
		{
			int tester = 0;
			struct Point goTo = { 3,0 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {package},3, -10.0, -10, 0.0 };
			struct Truck truckB = { {package},3, 0.0, 1000,0.0 };
			struct Truck truckC = { {package},3, 36.0, 0,0.0 };
			struct Map landScape = {
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 1, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};
			struct Route testRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0}

					},
						3, 2
			};
			struct Map expectedMap = {
					{
				{2, 0, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 1, 1, 0, 1},	//2
				{16, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Input testData = { {truckA,truckB,truckC},3,landScape };
			struct Truck* truckToDeploy = nullptr;
			struct Map outcomeMap;
			int index = 0;

			outcomeMap = addRoute(&landScape, &testRoute);
			for (int i = 0; i < testData.numTrucks; i++)
			{
				testData.trucks[i].limitingFactor = calculateLimitingFactor(&testData.trucks[i]);
			}

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateLocation(&landScape, &package.destination))
					{
						index = findAvailableTruck(&testData, package.weight, package.size);
						if (index >= 0)
						{
							truckToDeploy = &testData.trucks[index];
							tester = 1;
						}
					}
				}
			}
			Assert::IsTrue(tester == 0);

		}
		TEST_METHOD(FNLNEG002)
		{
			int tester = 0;
			struct Point goTo = { 3,0 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {package},3, -10.0, -10, 0.0 };
			struct Truck truckB = { {package},3, 0.0, 1000,0.0 };
			struct Truck truckC = { {package},3, 36.0, 0,0.0 };
			struct Map landScape = {
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 1, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};
			struct Route testRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0}

					},
						3, 2
			};
			struct Map expectedMap = {
					{
				{2, 0, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 1, 1, 0, 1},	//2
				{16, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Input testData = { {truckA,truckB,truckC},3,landScape };
			struct Truck* truckToDeploy = nullptr;
			struct Map outcomeMap;
			int index = 0;

			outcomeMap = addRoute(&landScape, &testRoute);
			for (int i = 0; i < testData.numTrucks; i++)
			{
				testData.trucks[i].limitingFactor = calculateLimitingFactor(&testData.trucks[i]);
			}

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateLocation(&landScape, &package.destination))
					{
						index = findAvailableTruck(&testData, -5000, package.size);
						if (index >= 0)
						{
							truckToDeploy = &testData.trucks[index];
							tester = 1;
						}
					}
				}
			}
			Assert::IsTrue(tester == 0);

		}
		TEST_METHOD(FNLNEG003)
		{
			int tester = 0;
			struct Point goTo = { 3,0 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {package},3, -10.0, -10, 0.0 };
			struct Truck truckB = { {package},3, 0.0, 1000,0.0 };
			struct Truck truckC = { {package},3, 36.0, 0,0.0 };
			struct Map landScape = {
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 1, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};
			struct Route testRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0}

					},
						3, 2
			};
			struct Map expectedMap = {
					{
				{2, 0, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 1, 1, 0, 1},	//2
				{16, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Input testData = { {truckA,truckB,truckC},3,landScape };
			struct Truck* truckToDeploy = nullptr;
			struct Map outcomeMap;
			int index = 0;

			outcomeMap = addRoute(&landScape, &testRoute);
			for (int i = 0; i < testData.numTrucks; i++)
			{
				testData.trucks[i].limitingFactor = calculateLimitingFactor(&testData.trucks[i]);
			}

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateLocation(&landScape, &package.destination))
					{
						index = findAvailableTruck(&testData, package.weight, -6283268);
						if (index >= 0)
						{
							truckToDeploy = &testData.trucks[index];
							tester = 1;
						}
					}
				}
			}
			Assert::IsTrue(tester == 0);

		}
		TEST_METHOD(FNLNEG004)
		{
			int tester = 0;
			struct Point goTo = { 0,4 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {package},3, -10.0, -10, 0.0 };
			struct Truck truckB = { {package},3, 0.0, 1000,0.0 };
			struct Truck truckC = { {package},3, 36.0, 0,0.0 };
			struct Map landScape = {
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 1, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};
			struct Route testRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0}

					},
						3, 2
			};
			struct Map expectedMap = {
					{
				{2, 0, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 1, 1, 0, 1},	//2
				{16, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Input testData = { {truckA,truckB,truckC},3,landScape };
			struct Truck* truckToDeploy = nullptr;
			struct Map outcomeMap;
			int index = 0;

			outcomeMap = addRoute(&landScape, &testRoute);
			for (int i = 0; i < testData.numTrucks; i++)
			{
				testData.trucks[i].limitingFactor = calculateLimitingFactor(&testData.trucks[i]);
			}

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateLocation(&landScape, &package.destination))
					{
						index = findAvailableTruck(&testData, package.weight, -6283268);
						if (index >= 0)
						{
							truckToDeploy = &testData.trucks[index];
							tester = 1;
						}
					}
				}
			}
			Assert::IsTrue(tester == 0);
		}

		// Lebna part.
		TEST_METHOD(ACCTST01)
		{
			//Test for validateBoxSize function:
			double validSize = 0.5;
			double invalidSize = 2.0;

			int isValid = validateBoxSize(validSize);
			Assert::IsTrue(isValid == 1);

			int isInvalid = validateBoxSize(invalidSize);
			Assert::IsTrue(isInvalid == 0);
		}
		TEST_METHOD(ACCTST02)
		{
			//Test for validateWeight function:
			int validWeight = 500;
			int invalidWeight = 1500;

			int isValid = validateWeight(validWeight);
			Assert::IsTrue(isValid == 1);

			int isInvalid = validateWeight(invalidWeight);
			Assert::IsTrue(isInvalid == 0);
		}
		TEST_METHOD(ACCTST03)
		{
			//Shortest Path
			bool result = false;

			struct Map testMap = {
			{
				{0, 0, 0, 0, 1},
				{0, 1, 1, 0, 1},
				{0, 1, 1, 0, 1},
				{0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0}
				},
				5, 5
			};

			struct Point start = { 0, 0 };
			struct Point destination = { 2, 3 };
			struct Route pathToUse = shortestPath(&testMap, start, destination);

			if (pathToUse.numPoints > 0)
			{
				result = true; // Success
			}
			else
			{
				result = false;  // Failed 
			}
		}
		TEST_METHOD(ACCTST04)
		{
			//Validate Location
			bool result = false;

			struct Map testMap = {
			{
				{0, 0, 0, 0, 1},
				{0, 1, 1, 0, 1},
				{0, 1, 1, 0, 1},
				{0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0},
				{0, 0, 0, 0, 0}
			},
					5, 5
			};

			struct Point destination = { 2, 3 }; // Valid location

			if (validateLocation(&testMap, &destination)) {
				result = true; // Success
			}
			else
			{
				result = false; // Failure
			}
		}

		// Sasawat part.
		TEST_METHOD(ACTP001)
		{
			int ndx = 0;
			struct Map map = populateMap();
			struct Route blueRoute = getBlueRoute();
			struct Route greenRoute = getGreenRoute();
			struct Route yellowRoute = getYellowRoute();

			struct Truck truckBlue = { {0, 0.0, { 0, 0}}, 0, 0, 0.0, 0.0 };
			struct Truck truckGreen = { {0, 0.0, { 0, 0}}, 0, 0 , 0.0,0.0 };
			struct Truck truckYellow = { {0, 0.0, { 0, 0}}, 0, 0.0, 0,0.0 };
			struct Input startTruck = {{truckBlue ,truckGreen, truckYellow}, 3, map};
			struct Point start = { 0,0 };
			
			struct Point dest = { 2, 16 };
			struct Box package = { 500, 1.0, dest };

			start.row = getClosestPoint(&blueRoute, dest);
			struct Route pathToUse = shortestPath(&map, start, dest);
			struct Truck* truckResult = nullptr;
			struct Map mapResult;
			
			mapResult = addRoute(&map, &blueRoute);
			for (int i = 0; i < startTruck.numTrucks; i++)
			{
				startTruck.trucks[i].limitingFactor = calculateLimitingFactor(&startTruck.trucks[i]);
			}

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateLocation(&map, &package.destination))
					{
						ndx = findAvailableTruck(&startTruck, package.weight, package.size);
						truckResult = &startTruck.trucks[ndx];
						mapResult = addRoute(&map, &pathToUse);
					}
				}
			}

			int resultTruck = findAvailableTruck(&startTruck, package.weight, package.size);

			Assert::IsTrue(truckResult->boxes[0].destination.row == startTruck.trucks[resultTruck].boxes[0].destination.row);
			Assert::IsTrue(truckResult->boxes[0].destination.col == startTruck.trucks[resultTruck].boxes[0].destination.col);
			Assert::IsTrue(truckResult->boxes[0].size == startTruck.trucks[resultTruck].boxes[0].size);
			Assert::IsTrue(truckResult->boxes[0].weight == startTruck.trucks[resultTruck].boxes[0].weight);
			Assert::IsTrue(truckResult->limitingFactor == startTruck.trucks[resultTruck].limitingFactor);
			Assert::IsTrue(truckResult->numBoxes == startTruck.trucks[resultTruck].numBoxes);
			Assert::IsTrue(truckResult->totalVolume == startTruck.trucks[resultTruck].totalVolume);
			Assert::IsTrue(truckResult->totalWeight == startTruck.trucks[resultTruck].totalWeight);
		}
		TEST_METHOD(ACTP002)
		{
			int ndx = 0;
			struct Map map = populateMap();
			struct Route blueRoute = getBlueRoute();
			struct Route greenRoute = getGreenRoute();
			struct Route yellowRoute = getYellowRoute();

			struct Truck truckBlue = { {0, 0.0, { 0, 0}}, 1, 1000, 1.0, 100.0 };
			struct Truck truckGreen = { {0, 0.0, { 0, 0}}, 0, 0, 0.0,0.0 };
			struct Truck truckYellow = { {0, 0.0, { 0, 0}}, 0, 0.0, 0,0.0 };
			struct Input startTruck = { {truckBlue ,truckGreen, truckYellow}, 3, map };
			struct Point start = { 0,0 };

			struct Point dest = { 2, 16 };
			struct Box package = { 500, 1.0, dest };

			start.row = getClosestPoint(&greenRoute, dest);
			struct Route pathToUse = shortestPath(&map, start, dest);
			struct Truck* truckResult = nullptr;
			struct Map mapResult;

			mapResult = addRoute(&map, &greenRoute);
			for (int i = 0; i < startTruck.numTrucks; i++)
			{
				startTruck.trucks[i].limitingFactor = calculateLimitingFactor(&startTruck.trucks[i]);
			}

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateLocation(&map, &package.destination))
					{
						ndx = findAvailableTruck(&startTruck, package.weight, package.size);
						truckResult = &startTruck.trucks[ndx];
						mapResult = addRoute(&map, &pathToUse);
					}
				}
			}

			int resultTruck = findAvailableTruck(&startTruck, package.weight, package.size);

			Assert::IsTrue(truckResult->boxes[0].destination.row == startTruck.trucks[resultTruck].boxes[0].destination.row);
			Assert::IsTrue(truckResult->boxes[0].destination.col == startTruck.trucks[resultTruck].boxes[0].destination.col);
			Assert::IsTrue(truckResult->boxes[0].size == startTruck.trucks[resultTruck].boxes[0].size);
			Assert::IsTrue(truckResult->boxes[0].weight == startTruck.trucks[resultTruck].boxes[0].weight);
			Assert::IsTrue(truckResult->limitingFactor == startTruck.trucks[resultTruck].limitingFactor);
			Assert::IsTrue(truckResult->numBoxes == startTruck.trucks[resultTruck].numBoxes);
			Assert::IsTrue(truckResult->totalVolume == startTruck.trucks[resultTruck].totalVolume);
			Assert::IsTrue(truckResult->totalWeight == startTruck.trucks[resultTruck].totalWeight);
		}
		TEST_METHOD(ACTP003)
		{
			int ndx = 0;
			struct Map map = populateMap();
			struct Route blueRoute = getBlueRoute();
			struct Route greenRoute = getGreenRoute();
			struct Route yellowRoute = getYellowRoute();

			struct Truck truckBlue = { {0, 0.0, { 0, 0}}, 1, 1000, 1.0, 100.0 };
			struct Truck truckGreen = { {0, 0.0, { 0, 0}}, 1, 1000, 1.0, 100.0 };
			struct Truck truckYellow = { {0, 0.0, { 0, 0}}, 0, 0.0, 0,0.0 };
			struct Input startTruck = { {truckBlue ,truckGreen, truckYellow}, 3, map };
			struct Point start = { 0,0 };

			struct Point dest = { 2, 16 };
			struct Box package = { 500, 1.0, dest };

			start.row = getClosestPoint(&yellowRoute, dest);
			struct Route pathToUse = shortestPath(&map, start, dest);
			struct Truck* truckResult = nullptr;
			struct Map mapResult;

			mapResult = addRoute(&map, &yellowRoute);
			for (int i = 0; i < startTruck.numTrucks; i++)
			{
				startTruck.trucks[i].limitingFactor = calculateLimitingFactor(&startTruck.trucks[i]);
			}

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateLocation(&map, &package.destination))
					{
						ndx = findAvailableTruck(&startTruck, package.weight, package.size);
						truckResult = &startTruck.trucks[ndx];
						mapResult = addRoute(&map, &pathToUse);
					}
				}
			}

			int resultTruck = findAvailableTruck(&startTruck, package.weight, package.size);

			Assert::IsTrue(truckResult->boxes[0].destination.row == startTruck.trucks[resultTruck].boxes[0].destination.row);
			Assert::IsTrue(truckResult->boxes[0].destination.col == startTruck.trucks[resultTruck].boxes[0].destination.col);
			Assert::IsTrue(truckResult->boxes[0].size == startTruck.trucks[resultTruck].boxes[0].size);
			Assert::IsTrue(truckResult->boxes[0].weight == startTruck.trucks[resultTruck].boxes[0].weight);
			Assert::IsTrue(truckResult->limitingFactor == startTruck.trucks[resultTruck].limitingFactor);
			Assert::IsTrue(truckResult->numBoxes == startTruck.trucks[resultTruck].numBoxes);
			Assert::IsTrue(truckResult->totalVolume == startTruck.trucks[resultTruck].totalVolume);
			Assert::IsTrue(truckResult->totalWeight == startTruck.trucks[resultTruck].totalWeight);
		}
		TEST_METHOD(ACTP004)
		{
			int ndx = 0;
			struct Map map = populateMap();
			struct Route blueRoute = getBlueRoute();
			struct Route greenRoute = getGreenRoute();
			struct Route yellowRoute = getYellowRoute();

			struct Truck truckBlue = { {0, 0.0, { 0, 0}}, 1, 1000, 1.0, 100.0 };
			struct Truck truckGreen = { {0, 0.0, { 0, 0}}, 1, 1000, 1.0, 100.0 };
			struct Truck truckYellow = { {0, 0.0, { 0, 0}}, 1, 1000, 1.0, 100.0 };
			struct Input startTruck = { {truckBlue ,truckGreen, truckYellow}, 3, map };
			struct Point start = { 0,0 };

			struct Point dest = { 2, 16 };
			struct Box package = { 500, 1.0, dest };

			start.row = getClosestPoint(&blueRoute, dest);
			struct Route pathToUse = shortestPath(&map, start, dest);
			struct Truck* truckResult = nullptr;
			struct Map mapResult;

			mapResult = addRoute(&map, &blueRoute);
			for (int i = 0; i < startTruck.numTrucks; i++)
			{
				startTruck.trucks[i].limitingFactor = calculateLimitingFactor(&startTruck.trucks[i]);
			}

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateLocation(&map, &package.destination))
					{
						ndx = findAvailableTruck(&startTruck, package.weight, package.size);
						truckResult = &startTruck.trucks[ndx];
						mapResult = addRoute(&map, &pathToUse);
					}
				}
			}

			int resultTruck = findAvailableTruck(&startTruck, package.weight, package.size);

			Assert::IsFalse(truckResult->boxes[0].destination.row == startTruck.trucks[resultTruck].boxes[0].destination.row);
			Assert::IsFalse(truckResult->boxes[0].destination.col == startTruck.trucks[resultTruck].boxes[0].destination.col);
			Assert::IsFalse(truckResult->boxes[0].size == startTruck.trucks[resultTruck].boxes[0].size);
			Assert::IsFalse(truckResult->boxes[0].weight == startTruck.trucks[resultTruck].boxes[0].weight);
			Assert::IsFalse(truckResult->limitingFactor == startTruck.trucks[resultTruck].limitingFactor);
			Assert::IsFalse(truckResult->numBoxes == startTruck.trucks[resultTruck].numBoxes);
			Assert::IsFalse(truckResult->totalVolume == startTruck.trucks[resultTruck].totalVolume);
			Assert::IsFalse(truckResult->totalWeight == startTruck.trucks[resultTruck].totalWeight);
		}
		TEST_METHOD(ACTP005)
		{
			int ndx = 0;
			struct Map map = populateMap();
			struct Route blueRoute = getBlueRoute();
			struct Route greenRoute = getGreenRoute();
			struct Route yellowRoute = getYellowRoute();

			struct Truck truckBlue = { {0, 0.0, { 0, 0}}, 1, 1000, 1.0, 100.0 };
			struct Truck truckGreen = { {0, 0.0, { 0, 0}}, 1, 1000, 1.0, 100.0 };
			struct Truck truckYellow = { {0, 0.0, { 0, 0}}, 1, 1000, 1.0, 100.0 };
			struct Input startTruck = { {truckBlue ,truckGreen, truckYellow}, 3, map };
			struct Point start = { 0,0 };

			struct Point dest = { 2, 16 };
			struct Box package = { 500, 1.0, dest };

			start.row = getClosestPoint(&greenRoute, dest);
			struct Route pathToUse = shortestPath(&map, start, dest);
			struct Truck* truckResult = nullptr;
			struct Map mapResult;

			mapResult = addRoute(&map, &greenRoute);
			for (int i = 0; i < startTruck.numTrucks; i++)
			{
				startTruck.trucks[i].limitingFactor = calculateLimitingFactor(&startTruck.trucks[i]);
			}

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateLocation(&map, &package.destination))
					{
						ndx = findAvailableTruck(&startTruck, package.weight, package.size);
						truckResult = &startTruck.trucks[ndx];
						mapResult = addRoute(&map, &pathToUse);
					}
				}
			}

			int resultTruck = findAvailableTruck(&startTruck, package.weight, package.size);

			Assert::IsFalse(truckResult->boxes[0].destination.row == startTruck.trucks[resultTruck].boxes[0].destination.row);
			Assert::IsFalse(truckResult->boxes[0].destination.col == startTruck.trucks[resultTruck].boxes[0].destination.col);
			Assert::IsFalse(truckResult->boxes[0].size == startTruck.trucks[resultTruck].boxes[0].size);
			Assert::IsFalse(truckResult->boxes[0].weight == startTruck.trucks[resultTruck].boxes[0].weight);
			Assert::IsFalse(truckResult->limitingFactor == startTruck.trucks[resultTruck].limitingFactor);
			Assert::IsFalse(truckResult->numBoxes == startTruck.trucks[resultTruck].numBoxes);
			Assert::IsFalse(truckResult->totalVolume == startTruck.trucks[resultTruck].totalVolume);
			Assert::IsFalse(truckResult->totalWeight == startTruck.trucks[resultTruck].totalWeight);
		}
		TEST_METHOD(ACTP006)
		{
			int ndx = 0;
			struct Map map = populateMap();
			struct Route blueRoute = getBlueRoute();
			struct Route greenRoute = getGreenRoute();
			struct Route yellowRoute = getYellowRoute();

			struct Truck truckBlue = { {0, 0.0, { 0, 0}}, 1, 1000, 1.0, 100.0 };
			struct Truck truckGreen = { {0, 0.0, { 0, 0}}, 1, 1000, 1.0, 100.0 };
			struct Truck truckYellow = { {0, 0.0, { 0, 0}}, 1, 1000, 1.0, 100.0 };
			struct Input startTruck = { {truckBlue ,truckGreen, truckYellow}, 3, map };
			struct Point start = { 0,0 };

			struct Point dest = { 2, 16 };
			struct Box package = { 500, 1.0, dest };

			start.row = getClosestPoint(&yellowRoute, dest);
			struct Route pathToUse = shortestPath(&map, start, dest);
			struct Truck* truckResult = nullptr;
			struct Map mapResult;

			mapResult = addRoute(&map, &yellowRoute);
			for (int i = 0; i < startTruck.numTrucks; i++)
			{
				startTruck.trucks[i].limitingFactor = calculateLimitingFactor(&startTruck.trucks[i]);
			}

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateLocation(&map, &package.destination))
					{
						ndx = findAvailableTruck(&startTruck, package.weight, package.size);
						truckResult = &startTruck.trucks[ndx];
						mapResult = addRoute(&map, &pathToUse);
					}
				}
			}

			int resultTruck = findAvailableTruck(&startTruck, package.weight, package.size);

			Assert::IsFalse(truckResult->boxes[0].destination.row == startTruck.trucks[resultTruck].boxes[0].destination.row);
			Assert::IsFalse(truckResult->boxes[0].destination.col == startTruck.trucks[resultTruck].boxes[0].destination.col);
			Assert::IsFalse(truckResult->boxes[0].size == startTruck.trucks[resultTruck].boxes[0].size);
			Assert::IsFalse(truckResult->boxes[0].weight == startTruck.trucks[resultTruck].boxes[0].weight);
			Assert::IsFalse(truckResult->limitingFactor == startTruck.trucks[resultTruck].limitingFactor);
			Assert::IsFalse(truckResult->numBoxes == startTruck.trucks[resultTruck].numBoxes);
			Assert::IsFalse(truckResult->totalVolume == startTruck.trucks[resultTruck].totalVolume);
			Assert::IsFalse(truckResult->totalWeight == startTruck.trucks[resultTruck].totalWeight);
		}
	};
}