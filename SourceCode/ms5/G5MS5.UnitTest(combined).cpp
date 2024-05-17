#include "pch.h"
#include "CppUnitTest.h"
#include "G5SFTMS5_r.h"
#include <iostream>
#include <sstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace G5MS5UnitTestcombined
{
	TEST_CLASS(G5MS5UnitTestcombined)
	{
	public:

		TEST_METHOD(TBP001)
		{
			const struct Point testPoint = { 5,5 };
			int tester = 0;
			struct Route expectedRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0},{2,1},{2,2}

					},
						5, 2
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
			addPointToRoute(&testRoute, 2, 1);
			addPointToRouteIfNot(&testRoute, 2, 2, testPoint);


			for (int i = 0; i < expectedRoute.numPoints; i++)
			{
				if (eqPt(testRoute.points[i], expectedRoute.points[i]))
				{
					tester++;
				}
			}

			Assert::IsTrue(tester == expectedRoute.numPoints);
			//Post Results:Passed

		}
		TEST_METHOD(TBP002)
		{
			const struct Point testPoint = { 2,2 };
			int tester = 0;
			struct Route expectedRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0},{2,1}

					},
						4, 2
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
			addPointToRoute(&testRoute, 2, 1);
			addPointToRouteIfNot(&testRoute, 2, 2, testPoint);


			for (int i = 0; i < expectedRoute.numPoints; i++)
			{
				if (eqPt(testRoute.points[i], expectedRoute.points[i]))
				{
					tester++;
				}
			}

			Assert::IsTrue(tester == expectedRoute.numPoints);
			//Post Results:Passed

		}
		TEST_METHOD(TBP003)
		{
			const struct Point testPoint = { 1,6 };
			int tester = 0;
			struct Route expectedRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0},{2,1},{2,2},
					{3,2},{3,3}
					},
						7, 2
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
			addPointToRoute(&testRoute, 2, 1);
			addPointToRouteIfNot(&testRoute, 2, 2, testPoint);
			addPointToRoute(&testRoute, 3, 2);
			addPointToRouteIfNot(&testRoute, 3, 3, testPoint);

			for (int i = 0; i < expectedRoute.numPoints; i++)
			{
				if (eqPt(testRoute.points[i], expectedRoute.points[i]))
				{
					tester++;
				}
			}

			Assert::IsTrue(tester == expectedRoute.numPoints);
			//Post Results:Passed
		}
		TEST_METHOD(TBP004)
		{
			const struct Point testPoint = { 1,6 };
			int tester = 0;
			struct Route expectedRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0},{2,1},{2,2},
					{3,2},{3,3}
					},
						7, 2
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
			addPointToRoute(&testRoute, 2, 1);
			addPointToRouteIfNot(&testRoute, 2, 2, testPoint);
			addPointToRoute(&testRoute, 3, 2);
			addPointToRouteIfNot(&testRoute, 3, 3, testPoint);


			Assert::IsTrue(testRoute.numPoints == expectedRoute.numPoints);
			//Post Results:Passed
		}
		TEST_METHOD(TBP005)
		{
			struct Map baseMap = {
				//0	1  2  3  4  
				//A B  C  D  E 
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 0, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 1, 0, 1, 0},	//4
				//24
			},
			5, 5
			};
			int tester = 0;
			struct Map expectedMap = {
				//0	1  2  3  4  
				//A B  C  D  E 
				{
				{2, 0, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 2, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 1, 0, 1, 0},	//4
				//24
			},
			5, 5
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
			addPointToRoute(&testRoute, 2, 1);
			baseMap = addRoute(&baseMap, &testRoute);
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == baseMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsTrue(tester == 25);
			//Post Results:Passed
			//To test if addPointToRoute will work with addRoute
		}
		TEST_METHOD(TBP006)
		{
			struct Map baseMap = {
				//0	1  2  3  4  
				//A B  C  D  E 
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 0, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 1, 0, 1, 0},	//4
				//24
			},
			5, 5
			};
			const struct Point testPoint = { 1,6 };
			int tester = 0;
			struct Map expectedMap = {
				//0	1  2  3  4  
				//A B  C  D  E 
				{
				{2, 0, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 2, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 1, 0, 1, 0},	//4
				//24
			},
			5, 5
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
			addPointToRouteIfNot(&testRoute, 2, 1, testPoint);
			baseMap = addRoute(&baseMap, &testRoute);
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == baseMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsTrue(tester == 25);
			//Post Results:Passed
			//To test if addPointToRouteIfNot will work with addRoute
		}
		TEST_METHOD(TBP007)//need to fix
		{
			struct Map baseMap = {
				//0	1  2  3  4  
				//A B  C  D  E 
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 0, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 1, 0, 1, 0},	//4
				//24
			},
			5, 5
			};
			const struct Point testPoint = { 1,6 };
			int tester = 0;
			struct Map expectedMap = {
				//0	1  2  3  4  
				//A B  C  D  E 
				{
				{2, 0, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 2, 1, 0, 1},	//2
				{0, 2, 2, 2, 0},	//3
				{0, 1, 0, 1, 0},	//4
				//24
			},
			5, 5
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
			addPointToRouteIfNot(&testRoute, 2, 1, testPoint);
			addPointToRoute(&testRoute, 3, 1);
			addPointToRouteIfNot(&testRoute, 3, 2, testPoint);
			addPointToRoute(&testRoute, 3, 3);
			baseMap = addRoute(&baseMap, &testRoute);
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == baseMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsTrue(tester == 25);
			//Post Results:Passed
			//To test if addPointToRouteIfNot as well as addPointtoRoute will work with addRoute
		}
		TEST_METHOD(TBN001)
		{
			const struct Point testPoint = { 5,5 };
			int tester = 0;
			struct Route expectedRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0},{2,1},{2,2}

					},
						5, 2
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
			addPointToRoute(&testRoute, 2, -1);
			addPointToRouteIfNot(&testRoute, 2, 2, testPoint);


			for (int i = 0; i < expectedRoute.numPoints; i++)
			{
				if (eqPt(testRoute.points[i], expectedRoute.points[i]))
				{
					tester++;
				}
			}

			Assert::IsFalse(tester == expectedRoute.numPoints);
			//Post Results:Passed
		}
		TEST_METHOD(TBN002)
		{
			const struct Point testPoint = { 5,5 };
			const struct Point testPointB = { 2,-2 };
			int truth = 0;
			struct Route expectedRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0},{2,1},{2,2}

					},
						5, 2
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
			addPointToRouteIfNot(&testRoute, 2, -2, testPoint);

			truth = eqPt(testRoute.points[3], testPointB);
			Assert::IsFalse(truth == 1);
			//Expected Result: True for being false
			//Post Results:Passed
		}
		TEST_METHOD(TBN003)
		{
			const struct Point testPoint = { 5,5 };
			const struct Point testPointB = { 2,500 };
			int truth = 0;
			struct Route expectedRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0},{2,1},{2,2}

					},
						5, 2
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
			addPointToRouteIfNot(&testRoute, 2, 500, testPoint);

			truth = eqPt(testRoute.points[3], testPointB);
			Assert::IsFalse(truth == 1);
			//Expected Result: True for being false
			//Post Results:Passed
		}
		TEST_METHOD(TBN004)
		{
			const struct Point testPoint = { 5,5 };
			const struct Point testPointB = { 2,0 };
			int truth = 0;
			struct Route expectedRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0},{2,1},{2,2}

					},
						5, 2
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
			addPointToRouteIfNot(&testRoute, 2, 0, testPoint);

			truth = eqPt(testRoute.points[3], testPointB);
			Assert::IsFalse(truth == 1);
			//Expected Result: True for being false
			//Post Results:Passed
		}
		TEST_METHOD(TBN005)//need to fix
		{
			struct Map baseMap = {
				//0	1  2  3  4  
				//A B  C  D  E 
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 0, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 1, 0, 1, 0},	//4
				//24
			},
			5, 5
			};
			const struct Point testPoint = { 1,6 };
			int tester = 0;
			struct Map expectedMap = {
				//0	1  2  3  4  
				//A B  C  D  E 
				{
				{2, 0, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 2, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 1, 0, 1, 0},	//4
				//24
			},
			5, 5
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
			addPointToRouteIfNot(&testRoute, 2, 1, testPoint);
			addPointToRoute(&testRoute, 3, -1);
			baseMap = addRoute(&baseMap, &testRoute);
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == baseMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsTrue(tester == 25);
			//Expect:Should not match because neg numbers should not be accepted
			//Post Results:Passed
			//To test if will take negative coordinates in conjuction with addPointToRoute
		}
		TEST_METHOD(TBN006)//need to fix
		{
			struct Map baseMap = {
				//0	1  2  3  4  
				//A B  C  D  E 
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 0, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 1, 0, 1, 0},	//4
				//24
			},
			5, 5
			};
			const struct Point testPoint = { 1,6 };
			int tester = 0;
			struct Map expectedMap = {
				//0	1  2  3  4  
				//A B  C  D  E 
				{
				{2, 0, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 0, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 1, 0, 1, 0},	//4
				//24
			},
			5, 5
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
			addPointToRouteIfNot(&testRoute, 2, -1, testPoint);
			addPointToRoute(&testRoute, 4, 2);
			baseMap = addRoute(&baseMap, &testRoute);
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == baseMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsTrue(tester == 25);
			//Expect:Should match as negative numbers will not be accepted the first time and also a coordinate thats not adjacent will also be rejected
			//Post Results:Passed
			//To test if will take negative coordinates in conjuction with addPointToRoute
		}
		TEST_METHOD(TBN007)
		{
			struct Map baseMap = {
				//0	1  2  3  4  
				//A B  C  D  E 
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 0, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 1, 0, 1, 0},	//4
				//24
			},
			5, 5
			};
			const struct Point testPoint = { 1,6 };
			int tester = 0;
			struct Map expectedMap = {
				//0	1  2  3  4  
				//A B  C  D  E 
				{
				{2, 0, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 2, 1, 0, 1},	//2
				{0, 2, 0, 0, 0},	//3
				{0, 1, 0, 1, 0},	//4
				//24
			},
			5, 5
			};
			struct Route testRoute =
			{
					{
					{0,0},
					{1,0},
					{2,0}

					},
						3, 200
			};
			addPointToRouteIfNot(&testRoute, 2, 1, testPoint);
			addPointToRoute(&testRoute, 3, 1);
			baseMap = addRoute(&baseMap, &testRoute);
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == baseMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsFalse(tester == 25);
			//Expect:Should not match or run at all because symbol is erroneous
			//Post Results:Passed
			//To test if will take negative coordinates in conjuction with addPointToRoute
		}
		TEST_METHOD(volume_BoxSize_1)
		{
			struct Truck truck;
			double boxSize = ONE_CUBIC_METER; // Assuming ONE_CUBIC_METER is a valid box size
			double totalVolume = HALF_CUBIC_METER; // Valid total volume

			// Validate box size and total volume
			int result_validateBoxSize = validateBoxSize(boxSize);
			truck.totalVolume = totalVolume; // Set truck's total volume
			int result_validateVolume = validateVolume(&truck);

			// Both validations are expected to pass
			Assert::IsTrue(result_validateBoxSize);
			Assert::IsTrue(result_validateVolume);
		}

		// Testing box size validation failing, but volume validation passing.
		TEST_METHOD(volume_BoxSize_2)
		{
			struct Truck truck;
			double boxSize = 0.1; // Assuming 0.1 is an invalid box size
			double totalVolume = HALF_CUBIC_METER; // Valid total volume

			// Validate box size and total volume
			int result_validateBoxSize = validateBoxSize(boxSize);
			truck.totalVolume = totalVolume; // Set truck's total volume
			int result_validateVolume = validateVolume(&truck);

			// Box size validation fails, but volume validation passes
			Assert::IsFalse(result_validateBoxSize);
			Assert::IsTrue(result_validateVolume);
		}

		// Testing box size validation passing, but volume validation failing.
		TEST_METHOD(volume_BoxSize_3)
		{
			struct Truck truck;
			double boxSize = ONE_CUBIC_METER; // Assuming ONE_CUBIC_METER is a valid box size
			double totalVolume = MAX_VOLUME + 1; // Invalid total volume

			// Validate box size and total volume
			int result_validateBoxSize = validateBoxSize(boxSize);
			truck.totalVolume = totalVolume; // Set truck's total volume
			int result_validateVolume = validateVolume(&truck);

			// Box size validation passes, but volume validation fails
			Assert::IsTrue(result_validateBoxSize);
			Assert::IsFalse(result_validateVolume);
		}

		// Testing both box size validation and volume validation failing.
		TEST_METHOD(volume_BoxSize_4)
		{
			struct Truck truck;
			double boxSize = 0.1; // Assuming 0.1 is an invalid box size
			double totalVolume = MAX_VOLUME + 1; // Invalid total volume

			// Validate box size and total volume
			int result_validateBoxSize = validateBoxSize(boxSize);
			truck.totalVolume = totalVolume; // Set truck's total volume
			int result_validateVolume = validateVolume(&truck);

			// Both box size validation and volume validation fail
			Assert::IsFalse(result_validateBoxSize);
			Assert::IsFalse(result_validateVolume);
		}

		// Testing box size validation and volume validation, both passing successfully.
		TEST_METHOD(volume_BoxSize_5)
		{
			struct Truck truck;
			double boxSize = HALF_CUBIC_METER; // Valid box size
			double totalVolume = QUARTER_CUBIC_METER; // Valid total volume

			// Validate box size and total volume
			int result_validateBoxSize = validateBoxSize(boxSize);
			truck.totalVolume = totalVolume; // Set truck's total volume
			int result_validateVolume = validateVolume(&truck);

			// Both validations are expected to pass
			Assert::IsTrue(result_validateBoxSize);
			Assert::IsTrue(result_validateVolume);
		}

		// Testing weight validation, volume validation, and limiting factor calculation for scenario 1
		TEST_METHOD(weight_volume_limiting_1)
		{
			struct Truck truck;
			truck.totalWeight = 50;
			truck.totalVolume = 120.0;
			double expectedLimitingFactor = -1;

			int result_validateWeight = validateWeight(truck.totalWeight);
			int result_validateVolume = validateVolume(&truck);
			double result_calculateLimitingFactor = calculateLimitingFactor(&truck);

			Assert::IsTrue(result_validateWeight);
			Assert::IsFalse(result_validateVolume);
			Assert::AreEqual(expectedLimitingFactor, result_calculateLimitingFactor);
		}

		// Testing weight validation, volume validation, and limiting factor calculation for scenario 2
		TEST_METHOD(weight_volume_limiting_2)
		{
			struct Truck truck;
			truck.totalWeight = 80;
			truck.totalVolume = 180.0;
			double expectedLimitingFactor = -1;

			int result_validateWeight = validateWeight(truck.totalWeight);
			int result_validateVolume = validateVolume(&truck);
			double result_calculateLimitingFactor = calculateLimitingFactor(&truck);

			Assert::IsTrue(result_validateWeight);
			Assert::IsFalse(result_validateVolume);
			Assert::AreEqual(expectedLimitingFactor, result_calculateLimitingFactor);
		}

		// Testing weight validation, volume validation, and limiting factor calculation for scenario 3
		TEST_METHOD(weight_volume_limiting_3)
		{
			struct Truck truck;
			truck.totalWeight = 30;
			truck.totalVolume = 15.0;
			double expectedLimitingFactor = 41.67;

			int result_validateWeight = validateWeight(truck.totalWeight);
			int result_validateVolume = validateVolume(&truck);
			double result_calculateLimitingFactor = calculateLimitingFactor(&truck);

			Assert::IsTrue(result_validateWeight);
			Assert::IsTrue(result_validateVolume);
			Assert::AreEqual(expectedLimitingFactor, result_calculateLimitingFactor);
		}

		// Testing weight validation, volume validation, and limiting factor calculation for scenario 4
		TEST_METHOD(weight_volume_limiting_4)
		{
			struct Truck truck;
			truck.totalWeight = 70;
			truck.totalVolume = 130.0;
			double expectedLimitingFactor = -1;

			int result_validateWeight = validateWeight(truck.totalWeight);
			int result_validateVolume = validateVolume(&truck);
			double result_calculateLimitingFactor = calculateLimitingFactor(&truck);

			Assert::IsTrue(result_validateWeight);
			Assert::IsFalse(result_validateVolume);
			Assert::AreEqual(expectedLimitingFactor, result_calculateLimitingFactor);
		}

		// Testing weight validation, volume validation, and limiting factor calculation for scenario 5
		TEST_METHOD(weight_volume_limiting_5)
		{
			struct Truck truck;
			truck.totalWeight = 90;
			truck.totalVolume = 36.0;
			double expectedLimitingFactor = 100;

			int result_validateWeight = validateWeight(truck.totalWeight);
			int result_validateVolume = validateVolume(&truck);
			double result_calculateLimitingFactor = calculateLimitingFactor(&truck);

			Assert::IsTrue(result_validateWeight);
			Assert::IsTrue(result_validateVolume);
			Assert::AreEqual(expectedLimitingFactor, result_calculateLimitingFactor);
		}

		// Testing weight validation, box size validation, volume validation, and limiting factor calculation for scenario 1
		TEST_METHOD(weight_BoxSize_volume_limiting_1)
		{
			struct Truck truck;
			truck.totalWeight = 75; // Valid weight
			double boxSize = ONE_CUBIC_METER; // Valid box size
			double totalVolume = QUARTER_CUBIC_METER; // Valid total volume

			int result_validateWeight = validateWeight(truck.totalWeight);
			int result_validateBoxSize = validateBoxSize(boxSize);
			truck.totalVolume = totalVolume; // Set truck's total volume
			int result_validateVolume = validateVolume(&truck);
			double result_calculateLimitingFactor = calculateLimitingFactor(&truck);

			Assert::IsTrue(result_validateWeight);
			Assert::IsTrue(result_validateBoxSize);
			Assert::IsTrue(result_validateVolume);
			Assert::AreEqual(7.5, result_calculateLimitingFactor);
		}

		// Testing weight validation, box size validation, volume validation, and limiting factor calculation for scenario 2
		TEST_METHOD(weight_BoxSize_volume_limiting_2)
		{
			struct Truck truck;
			truck.totalWeight = 2000; // Invalid weight
			double boxSize = HALF_CUBIC_METER; // Valid box size
			double totalVolume = ONE_CUBIC_METER; // Valid total volume

			int result_validateWeight = validateWeight(truck.totalWeight);
			int result_validateBoxSize = validateBoxSize(boxSize);
			truck.totalVolume = totalVolume; // Set truck's total volume
			int result_validateVolume = validateVolume(&truck);
			double result_calculateLimitingFactor = calculateLimitingFactor(&truck);

			Assert::IsFalse(result_validateWeight);
			Assert::IsTrue(result_validateBoxSize);
			Assert::IsTrue(result_validateVolume);
			Assert::AreEqual(-1.0, result_calculateLimitingFactor);
		}

		// Testing weight validation, box size validation, volume validation, and limiting factor calculation for scenario 3
		TEST_METHOD(weight_BoxSize_volume_limiting_3)
		{
			struct Truck truck;
			truck.totalWeight = 500; // Valid weight
			double boxSize = 0.1; // Invalid box size
			double totalVolume = HALF_CUBIC_METER; // Valid total volume

			int result_validateWeight = validateWeight(truck.totalWeight);
			int result_validateBoxSize = validateBoxSize(boxSize);
			truck.totalVolume = totalVolume; // Set truck's total volume
			int result_validateVolume = validateVolume(&truck);
			double result_calculateLimitingFactor = calculateLimitingFactor(&truck);

			Assert::IsTrue(result_validateWeight);
			Assert::IsFalse(result_validateBoxSize);
			Assert::IsTrue(result_validateVolume);
			Assert::AreEqual(50.0, result_calculateLimitingFactor);
		}

		// Testing weight validation, box size validation, volume validation, and limiting factor calculation for scenario 4
		TEST_METHOD(weight_BoxSize_volume_limiting_4)
		{
			struct Truck truck;
			truck.totalWeight = 700; // Valid weight
			double boxSize = ONE_CUBIC_METER; // Valid box size
			double totalVolume = MAX_VOLUME + 1; // Invalid total volume

			int result_validateWeight = validateWeight(truck.totalWeight);
			int result_validateBoxSize = validateBoxSize(boxSize);
			truck.totalVolume = totalVolume; // Set truck's total volume
			int result_validateVolume = validateVolume(&truck);
			double result_calculateLimitingFactor = calculateLimitingFactor(&truck);

			Assert::IsTrue(result_validateWeight);
			Assert::IsTrue(result_validateBoxSize);
			Assert::IsFalse(result_validateVolume);
			Assert::AreEqual(-1.0, result_calculateLimitingFactor);
		}

		// Testing weight validation, box size validation, volume validation, and limiting factor calculation for scenario 5
		TEST_METHOD(weight_BoxSize_volume_limiting_5)
		{
			struct Truck truck;
			truck.totalWeight = 300; // Valid weight
			double boxSize = QUARTER_CUBIC_METER; // Valid box size
			double totalVolume = ONE_CUBIC_METER; // Valid total volume

			int result_validateWeight = validateWeight(truck.totalWeight);
			int result_validateBoxSize = validateBoxSize(boxSize);
			truck.totalVolume = totalVolume; // Set truck's total volume
			int result_validateVolume = validateVolume(&truck);
			double result_calculateLimitingFactor = calculateLimitingFactor(&truck);

			Assert::IsTrue(result_validateWeight);
			Assert::IsTrue(result_validateBoxSize);
			Assert::IsTrue(result_validateVolume);
			Assert::AreEqual(30.0, result_calculateLimitingFactor);
		}
		TEST_METHOD(TFS001)
		{

			struct Route blueRoute = {
				{
					{0, 0},
					{1, 0},
					{2, 0},
					{3, 0},
					{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},
					{5, 9},
					{6, 9},
					{7, 9},
					{8, 9},
					{9, 9},
					{10, 9},{10, 10},
					{11, 10},
					{12, 10},
					{13, 10},
					{14, 10},
					{15, 10},
					{16, 10},
					{17, 10},{17, 11},{17, 12},{17, 13},{17, 14},{17, 15},{17, 16},{17, 17},{17, 18},{17, 19},{17, 20},
					{17, 21},{17, 22},{17, 23},{17, 24},
				},
				42, BLUE
			};

			struct Point p2 = { 5, 0 };

			int result = getClosestPoint(&blueRoute, p2);

			int expected = 4;
			bool testResult = (result == expected);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TFS002)
		{
			struct Route blueRoute = {
				{
					{0, 0},
					{1, 0},
					{2, 0},
					{3, 0},
					{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},
					{5, 9},
					{6, 9},
					{7, 9},
					{8, 9},
					{9, 9},
					{10, 9},{10, 10},
					{11, 10},
					{12, 10},
					{13, 10},
					{14, 10},
					{15, 10},
					{16, 10},
					{17, 10},{17, 11},{17, 12},{17, 13},{17, 14},{17, 15},{17, 16},{17, 17},{17, 18},{17, 19},{17, 20},
					{17, 21},{17, 22},{17, 23},{17, 24},
				},
				42, BLUE
			};

			struct Point p2 = { 18, 12 };

			int result = getClosestPoint(&blueRoute, p2);

			int expected = 29;
			bool testResult = (result == expected);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TFS003)
		{

			struct Route yellowRoute = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3},
			{5, 3},
			{6, 3},
			{7, 3},
			{8, 3},
			{9, 3},{9, 2},{9, 1},
			{10, 1},
			{11, 1},
			{12, 1},
			{13, 1},
			{14, 1},
			{15, 1},
			{16, 1},
			{17, 1},
			{18, 1},
			{19, 1},{19, 2},{19, 3},{19, 4},{19, 5},{19, 6},{19, 7},{19, 8},{19, 9},{19, 10},{19, 11},{19, 12},
				{19, 13},{19, 14},{19, 15},{19, 16},{19, 17},{19, 18},{19, 19},{19, 20},{19, 21},{19, 22},{19, 23},{19, 24}
		},
			48, YELLOW
			};

			struct Point p2 = { 18, 12 };

			int result = getClosestPoint(&yellowRoute, p2);

			int expected = 35;
			bool testResult = (result == expected);
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TFS004)
		{
			struct Route blueRoute = {
				{
					{0, 0},
					{1, 0},
					{2, 0},
					{3, 0},
					{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},
					{5, 9},
					{6, 9},
					{7, 9},
					{8, 9},
					{9, 9},
					{10, 9},{10, 10},
					{11, 10},
					{12, 10},
					{13, 10},
					{14, 10},
					{15, 10},
					{16, 10},
					{17, 10},{17, 11},{17, 12},{17, 13},{17, 14},{17, 15},{17, 16},{17, 17},{17, 18},{17, 19},{17, 20},
					{17, 21},{17, 22},{17, 23},{17, 24},
				},
				42, BLUE
			};
			struct Point p2 = { 6, 11 };

			int result = getClosestPoint(&blueRoute, p2);

			int expected = 15;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TFS005)
		{
			struct Route greenRoute =
			{
					{
						{0, 0},
						{1, 0},
						{2, 0},
						{3, 0},
						{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},{4, 10},{4, 11},
						{3, 11},
						{2, 11},
						{1, 11},
						{0, 11},{0, 12},{0, 13},{0, 14},{0, 15},{0, 16},{0, 17},{0, 18},{0, 19},
						{1, 19},
						{2, 19},
						{3, 19},
						{4, 19},
						{5, 19},
						{6, 19},
						{7, 19},
						{8, 19},
						{9, 19},{9, 20},{9, 21},{9, 22},{9, 23},{9, 24}

					},
						42, GREEN
			};

			struct Point p2 = { 6, 11 };

			int result = getClosestPoint(&greenRoute, p2);

			int expected = 15;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TFS006)
		{
			struct Route blueRoute = {
				{
					{0, 0},
					{1, 0},
					{2, 0},
					{3, 0},
					{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},
					{5, 9},
					{6, 9},
					{7, 9},
					{8, 9},
					{9, 9},
					{10, 9},{10, 10},
					{11, 10},
					{12, 10},
					{13, 10},
					{14, 10},
					{15, 10},
					{16, 10},
					{17, 10},{17, 11},{17, 12},{17, 13},{17, 14},{17, 15},{17, 16},{17, 17},{17, 18},{17, 19},{17, 20},
					{17, 21},{17, 22},{17, 23},{17, 24},
				},
				42, BLUE
			};
			struct Point p2 = { 0, 0 };

			int result = getClosestPoint(&blueRoute, p2);

			int expected = 0;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TFS007)
		{
			struct Route greenRoute =
			{
					{
						{0, 0},
						{1, 0},
						{2, 0},
						{3, 0},
						{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8},{4, 9},{4, 10},{4, 11},
						{3, 11},
						{2, 11},
						{1, 11},
						{0, 11},{0, 12},{0, 13},{0, 14},{0, 15},{0, 16},{0, 17},{0, 18},{0, 19},
						{1, 19},
						{2, 19},
						{3, 19},
						{4, 19},
						{5, 19},
						{6, 19},
						{7, 19},
						{8, 19},
						{9, 19},{9, 20},{9, 21},{9, 22},{9, 23},{9, 24}

					},
						42, GREEN
			};
			struct Point p2 = { 7, 21 };

			int result = getClosestPoint(&greenRoute, p2);

			int expected = 34;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TFS008)
		{
			struct Route yellowRoute = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3},
			{5, 3},
			{6, 3},
			{7, 3},
			{8, 3},
			{9, 3},{9, 2},{9, 1},
			{10, 1},
			{11, 1},
			{12, 1},
			{13, 1},
			{14, 1},
			{15, 1},
			{16, 1},
			{17, 1},
			{18, 1},
			{19, 1},{19, 2},{19, 3},{19, 4},{19, 5},{19, 6},{19, 7},{19, 8},{19, 9},{19, 10},{19, 11},{19, 12},
				{19, 13},{19, 14},{19, 15},{19, 16},{19, 17},{19, 18},{19, 19},{19, 20},{19, 21},{19, 22},{19, 23},{19, 24}
		},
			48, YELLOW
			};
			struct Point p2 = { 1, 7 };

			int result = getClosestPoint(&yellowRoute, p2);

			int expected = 7;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TFS009)
		{
			struct Route yellowRoute = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3},
			{5, 3},
			{6, 3},
			{7, 3},
			{8, 3},
			{9, 3},{9, 2},{9, 1},
			{10, 1},
			{11, 1},
			{12, 1},
			{13, 1},
			{14, 1},
			{15, 1},
			{16, 1},
			{17, 1},
			{18, 1},
			{19, 1},{19, 2},{19, 3},{19, 4},{19, 5},{19, 6},{19, 7},{19, 8},{19, 9},{19, 10},{19, 11},{19, 12},
				{19, 13},{19, 14},{19, 15},{19, 16},{19, 17},{19, 18},{19, 19},{19, 20},{19, 21},{19, 22},{19, 23},{19, 24}
		},
			48, YELLOW
			};
			struct Point p2 = { 17, 3 };

			int result = getClosestPoint(&yellowRoute, p2);

			int expected = 22;
			Assert::AreEqual(expected, result);
		}

		TEST_METHOD(TFS010)
		{
			struct Route yellowRoute = {
		{
			{0, 0},
			{1, 0},
			{2, 0},
			{3, 0},
			{4, 0}, {4, 1}, {4, 2}, {4, 3},
			{5, 3},
			{6, 3},
			{7, 3},
			{8, 3},
			{9, 3},{9, 2},{9, 1},
			{10, 1},
			{11, 1},
			{12, 1},
			{13, 1},
			{14, 1},
			{15, 1},
			{16, 1},
			{17, 1},
			{18, 1},
			{19, 1},{19, 2},{19, 3},{19, 4},{19, 5},{19, 6},{19, 7},{19, 8},{19, 9},{19, 10},{19, 11},{19, 12},
				{19, 13},{19, 14},{19, 15},{19, 16},{19, 17},{19, 18},{19, 19},{19, 20},{19, 21},{19, 22},{19, 23},{19, 24}
		},
			48, YELLOW
			};
			struct Point p2 = { 20, 0 };

			int result = getClosestPoint(&yellowRoute, p2);

			int expected = 24;
			Assert::AreEqual(expected, result);
		}

		//
		//Lebna's part
		TEST_METHOD(TFSo001)
		{
			struct Map map = populateMap();

			struct Point start = { 0, 0 };
			struct Point dest = { 4, 4 };
			struct Route resultRoute = shortestPath(&map, start, dest);
			Assert::IsTrue(resultRoute.numPoints = 9, L"Expected the route to have no more than MAX_POINTS points");
		}

		TEST_METHOD(TFSo002)
		{
			// Start and Destination Are the Same
			struct Map map2 = populateMap();
			struct Point start2 = { 0, 0 };
			struct Point dest2 = { 0, 0 };
			struct Route result2 = shortestPath(&map2, start2, dest2);
			// Assert that the path length is zero since start and destination are the same
			Assert::IsTrue(result2.numPoints == 0);
		}

		TEST_METHOD(TFSo003)
		{
			//  No Valid Path
			struct Map map3 = populateMap();
			struct Point start3 = { 0, 0 };
			struct Point dest3 = { 1, 1 }; // Assuming (1, 1) is blocked by a building
			struct Route result3 = shortestPath(&map3, start3, dest3);
			// Assert that no valid path exists from start to destination
			Assert::IsTrue(result3.numPoints == 0);
		}

		TEST_METHOD(TFSo004)
		{
			struct Map map = populateMap();
			struct Point start = { 0, 0 };
			struct Point dest = { 2, 2 };
			struct Route resultRoute = shortestPath(&map, start, dest);
			Assert::IsTrue(resultRoute.numPoints = 6);
			Assert::IsTrue(eqPt(resultRoute.points[resultRoute.numPoints - 1], dest));
		}

		TEST_METHOD(TFSo005)
		{
			//No Path, Same Start and Destination
			struct Map map5 = populateMap();
			struct Point start5 = { 2, 3 };
			struct Point dest5 = { 2, 3 }; // Same start and destination
			struct Route result5 = shortestPath(&map5, start5, dest5);

			Assert::IsTrue(result5.numPoints == 0);
		}

		TEST_METHOD(TII001)
		{
			struct Map map = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
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
			struct Truck sampleTruck;
			bool sizeResults, destColResults, destRowResults, volumnResults, limitFactorResults;
			bool weightResults = false;
			Box sampleBox = { 0 };

			std::stringstream input;

			input << "20 .5 12 L\n";

			std::streambuf* cinBuffer = std::cin.rdbuf(input.rdbuf());

			getUserInput(&sampleBox);

			std::cin.rdbuf(cinBuffer);

			weightResults = (sampleBox.weight >= MIN_WEIGHT && sampleBox.weight <= MAX_WEIGHT);

			Assert::IsTrue(weightResults);

		}

		/* Test integration of getUserInput and validateBoxSize functions. */
		TEST_METHOD(TII002)
		{
			struct Map map = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
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
			struct Truck sampleTruck;
			bool weightResults, sizeResults, destColResults, destRowResults, volumnResults, limitFactorResults;
			sizeResults = false;

			std::stringstream input;
			std::stringstream output;
			Box sampleBox = { 0 };

			input << "20 .5 12 L\n";

			std::streambuf* cinBuffer = std::cin.rdbuf(input.rdbuf());

			getUserInput(&sampleBox);

			std::cin.rdbuf(cinBuffer);

			sizeResults = ((sampleBox.size == QUARTER_CUBIC_METER) || (sampleBox.size == HALF_CUBIC_METER) || (sampleBox.size == ONE_CUBIC_METER));

			Assert::IsTrue(sizeResults);
		}

		/* Test integration of getUserInput and validateLocation functions. */
		TEST_METHOD(TII003)
		{
			struct Map map = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
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
			struct Truck sampleTruck;
			bool weightResults, sizeResults, destColResults, destRowResults, volumnResults, limitFactorResults;
			destColResults = false;
			destRowResults = false;
			Box sampleBox = { 0 };

			std::stringstream input;

			input << "20 .5 12 L\n";

			std::streambuf* cinBuffer = std::cin.rdbuf(input.rdbuf());

			getUserInput(&sampleBox);

			std::cin.rdbuf(cinBuffer);

			destColResults = (sampleBox.destination.col > 0 && sampleBox.destination.col < MAP_COLS);
			destRowResults = (sampleBox.destination.row > 0 && sampleBox.destination.row < MAP_ROWS);

			Assert::IsTrue(destColResults && destRowResults);
		}

		/* Test integration of getUserInput, validateWeight and validateBoxSize functions. */
		TEST_METHOD(TII004)
		{
			struct Map map = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
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
			struct Truck sampleTruck;
			bool weightResults, sizeResults, destColResults, destRowResults, volumnResults, limitFactorResults;
			weightResults = false;
			sizeResults = false;
			Box sampleBox = { 0 };

			std::stringstream input;

			input << "20 .5 12 L\n";

			std::streambuf* cinBuffer = std::cin.rdbuf(input.rdbuf());

			getUserInput(&sampleBox);

			std::cin.rdbuf(cinBuffer);

			weightResults = (sampleBox.weight > MIN_WEIGHT && sampleBox.weight > MAX_WEIGHT);
			sizeResults = ((sampleBox.size == QUARTER_CUBIC_METER) || (sampleBox.size == HALF_CUBIC_METER) || (sampleBox.size == ONE_CUBIC_METER));

			Assert::IsTrue(weightResults && sizeResults);
		}

		/* Test integration of getUserInput, validateWeight and validateLocation functions. */
		TEST_METHOD(TII005)
		{
			struct Map map = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
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
			struct Truck sampleTruck;
			bool weightResults, sizeResults, destColResults, destRowResults, volumnResults, limitFactorResults;
			weightResults = false;
			destColResults = false;
			destRowResults = false;

			Box sampleBox = { 0 };

			std::stringstream input;

			input << "20 .5 12 L\n";

			std::streambuf* cinBuffer = std::cin.rdbuf(input.rdbuf());

			getUserInput(&sampleBox);

			std::cin.rdbuf(cinBuffer);

			weightResults = (sampleBox.weight > MIN_WEIGHT && sampleBox.weight > MAX_WEIGHT);
			destColResults = (sampleBox.destination.col > 0 && sampleBox.destination.col < MAP_COLS);
			destRowResults = (sampleBox.destination.row > 0 && sampleBox.destination.row < MAP_ROWS);

			Assert::IsTrue(weightResults && destColResults && destRowResults);
		}

		/* Test integration of getUserInput, validateBoxSize and validateLocation functions. */
		TEST_METHOD(TII006)
		{
			struct Map map = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
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
			struct Truck sampleTruck;
			bool weightResults, sizeResults, destColResults, destRowResults, volumnResults, limitFactorResults;
			sizeResults = false;
			destColResults = false;
			destRowResults = false;
			Box sampleBox = { 0 };

			std::stringstream input;

			input << "20 .5 12 L\n";

			std::streambuf* cinBuffer = std::cin.rdbuf(input.rdbuf());

			getUserInput(&sampleBox);

			std::cin.rdbuf(cinBuffer);

			sizeResults = ((sampleBox.size == QUARTER_CUBIC_METER) || (sampleBox.size == HALF_CUBIC_METER) || (sampleBox.size == ONE_CUBIC_METER));
			destColResults = (sampleBox.destination.col > 0 && sampleBox.destination.col < MAP_COLS);
			destRowResults = (sampleBox.destination.row > 0 && sampleBox.destination.row < MAP_ROWS);

			Assert::IsTrue(sizeResults && destColResults && destRowResults);
		}

		/* Test integration of getUserInput, validateWeight, validateBoxSize and validateLocation functions. */
		TEST_METHOD(TII007)
		{
			struct Map map = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
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
			struct Truck sampleTruck;
			bool weightResults, sizeResults, destColResults, destRowResults, volumnResults, limitFactorResults;
			weightResults = false;
			sizeResults = false;
			destColResults = false;
			destRowResults = false;
			Box sampleBox = { 0 };

			std::stringstream input;

			input << "20 .5 12 L\n";

			std::streambuf* cinBuffer = std::cin.rdbuf(input.rdbuf());

			getUserInput(&sampleBox);

			std::cin.rdbuf(cinBuffer);

			weightResults = (sampleBox.weight > MIN_WEIGHT && sampleBox.weight > MAX_WEIGHT);
			sizeResults = ((sampleBox.size == QUARTER_CUBIC_METER) || (sampleBox.size == HALF_CUBIC_METER) || (sampleBox.size == ONE_CUBIC_METER));
			destColResults = (sampleBox.destination.col > 0 && sampleBox.destination.col < MAP_COLS);
			destRowResults = (sampleBox.destination.row > 0 && sampleBox.destination.row < MAP_ROWS);

			Assert::IsTrue(weightResults && sizeResults && destColResults && destRowResults);
		}

		/* Test integration of getUserInput, validateWeight, validateBoxSize, validateLocation and validateVolume functions. With start total volumn as 0. */
		TEST_METHOD(TII008)
		{
			struct Map map = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
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
			struct Truck sampleTruck;
			bool weightResults, sizeResults, destColResults, destRowResults, volumnResults, limitFactorResults;
			Box sampleBox = { 0 };
			sampleTruck = { {sampleBox}, 0, 0.0, 0, 0.0 };
			weightResults = false;
			sizeResults = false;
			destColResults = false;
			destRowResults = false;
			volumnResults = false;

			std::stringstream input;

			input << "20 .5 12 L\n";

			std::streambuf* cinBuffer = std::cin.rdbuf(input.rdbuf());

			getUserInput(&sampleBox);

			std::cin.rdbuf(cinBuffer);

			sampleTruck.totalVolume += sampleBox.size;

			weightResults = (sampleBox.weight > MIN_WEIGHT && sampleBox.weight > MAX_WEIGHT);
			sizeResults = ((sampleBox.size == QUARTER_CUBIC_METER) || (sampleBox.size == HALF_CUBIC_METER) || (sampleBox.size == ONE_CUBIC_METER));
			destColResults = (sampleBox.destination.col > 0 && sampleBox.destination.col < MAP_COLS);
			destRowResults = (sampleBox.destination.row > 0 && sampleBox.destination.row < MAP_ROWS);
			volumnResults = validateVolume(&sampleTruck);

			Assert::IsTrue(weightResults && sizeResults && destColResults && destRowResults && volumnResults);
		}

		/* Test integration of getUserInput, validateWeight, validateBoxSize, validateLocation and validateVolume functions. With start total volumn as Maximum Volumn (36.0). */
		TEST_METHOD(TII009)
		{
			struct Map map = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
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
			struct Truck sampleTruck;
			bool weightResults, sizeResults, destColResults, destRowResults, volumnResults, limitFactorResults;
			Box sampleBox = { 0 };
			sampleTruck = { {sampleBox}, 0, MAX_VOLUME, 0, 0.0 };
			weightResults = false;
			sizeResults = false;
			destColResults = false;
			destRowResults = false;
			volumnResults = false;
			std::stringstream input;

			input << "20 .5 12 L\n";

			std::streambuf* cinBuffer = std::cin.rdbuf(input.rdbuf());

			getUserInput(&sampleBox);

			std::cin.rdbuf(cinBuffer);

			sampleTruck.totalVolume += sampleBox.size;

			weightResults = (sampleBox.weight > MIN_WEIGHT && sampleBox.weight > MAX_WEIGHT);
			sizeResults = ((sampleBox.size == QUARTER_CUBIC_METER) || (sampleBox.size == HALF_CUBIC_METER) || (sampleBox.size == ONE_CUBIC_METER));
			destColResults = (sampleBox.destination.col > 0 && sampleBox.destination.col < MAP_COLS);
			destRowResults = (sampleBox.destination.row > 0 && sampleBox.destination.row < MAP_ROWS);
			volumnResults = validateVolume(&sampleTruck);

			Assert::IsTrue(weightResults && sizeResults && destColResults && destRowResults && volumnResults);
		}

		/* Test integration of getUserInput, validateWeight, validateBoxSize, validateLocation and validateVolume functions. With start total volumn as NULL. */
		TEST_METHOD(TII010)
		{
			struct Map map = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
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
			struct Truck sampleTruck;
			bool weightResults, sizeResults, destColResults, destRowResults, volumnResults, limitFactorResults;
			Box sampleBox = { 0 };
			sampleTruck = { {sampleBox}, 0, NULL, 0, 0.0 };
			weightResults = false;
			sizeResults = false;
			destColResults = false;
			destRowResults = false;
			volumnResults = false;

			std::stringstream input;

			input << "20 .5 12 L\n";

			std::streambuf* cinBuffer = std::cin.rdbuf(input.rdbuf());

			getUserInput(&sampleBox);

			std::cin.rdbuf(cinBuffer);

			weightResults = (sampleBox.weight > MIN_WEIGHT && sampleBox.weight > MAX_WEIGHT);
			sizeResults = ((sampleBox.size == QUARTER_CUBIC_METER) || (sampleBox.size == HALF_CUBIC_METER) || (sampleBox.size == ONE_CUBIC_METER));
			destColResults = (sampleBox.destination.col > 0 && sampleBox.destination.col < MAP_COLS);
			destRowResults = (sampleBox.destination.row > 0 && sampleBox.destination.row < MAP_ROWS);
			volumnResults = validateVolume(&sampleTruck);

			Assert::IsTrue(weightResults && sizeResults && destColResults && destRowResults && !volumnResults);
		}


		/* Test integration of getUserInput, validateWeight, validateBoxSize, validateLocation, validateVolume and calculateLimitingFactor functions. */
		TEST_METHOD(TII011)
		{
			struct Map map = {
				//0	1  2  3  4  5  6  7  8  9  0  1  2  3  4  5  6  7  8  9  0  1  2  3  4
				//A B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q  R  S  T  U  V  W  X  Y
				{
				{0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},	//0
				{0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0},	//1
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
			struct Truck sampleTruck;
			bool weightResults, sizeResults, destColResults, destRowResults, volumnResults, limitFactorResults;
			Box sampleBox = { 0 };
			sampleTruck = { {sampleBox}, 0, 0.0, 0, 0.0 };
			weightResults = false;
			sizeResults = false;
			destColResults = false;
			destRowResults = false;
			volumnResults = false;
			limitFactorResults = false;

			std::stringstream input;

			input << "20 .5 12 L\n";

			std::streambuf* cinBuffer = std::cin.rdbuf(input.rdbuf());

			getUserInput(&sampleBox);

			std::cin.rdbuf(cinBuffer);

			weightResults = (sampleBox.weight > MIN_WEIGHT && sampleBox.weight > MAX_WEIGHT);
			sizeResults = ((sampleBox.size == QUARTER_CUBIC_METER) || (sampleBox.size == HALF_CUBIC_METER) || (sampleBox.size == ONE_CUBIC_METER));
			destColResults = (sampleBox.destination.col > 0 && sampleBox.destination.col < MAP_COLS);
			destRowResults = (sampleBox.destination.row > 0 && sampleBox.destination.row < MAP_ROWS);
			volumnResults = validateVolume(&sampleTruck);
			double limitPercentage = calculateLimitingFactor(&sampleTruck);
			limitFactorResults = (limitFactorResults >= 0.0 && limitFactorResults <= 100.0);

			Assert::IsTrue(weightResults && sizeResults && destColResults && destRowResults && volumnResults && limitFactorResults);
		}

		TEST_METHOD(G5ACCP001)
		{
			int tester = 0;
			struct Point goTo = { 3,0 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {},3, 0.0, 0 };
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
			struct Input testData = { {truckA},3,landScape };
			struct Truck* truckToDeploy;
			struct Map outcomeMap;

			outcomeMap = addRoute(&landScape, &testRoute);
			truckA.limitingFactor = calculateLimitingFactor(&truckA);

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateVolume(&truckA))
					{
						if (1 == validateLocation(&landScape, &package.destination))
						{
							truckToDeploy = findAvailableTruck(&testData, package.weight, package.size, package.destination);
							outcomeMap = addRoute(&outcomeMap, &pathToUse);
						}
					}

				}
			}
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == outcomeMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsTrue(tester == 25);

		}
		TEST_METHOD(G5ACCP002)
		{
			int tester = 0;
			struct Point goTo = { 4,0 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {},3, 0.0, 0 };
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
				{16, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Input testData = { {truckA},3,landScape };
			struct Truck* truckToDeploy;
			struct Map outcomeMap;

			outcomeMap = addRoute(&landScape, &testRoute);
			truckA.limitingFactor = calculateLimitingFactor(&truckA);

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateVolume(&truckA))
					{
						if (1 == validateLocation(&landScape, &package.destination))
						{
							truckToDeploy = findAvailableTruck(&testData, package.weight, package.size, package.destination);
							outcomeMap = addRoute(&outcomeMap, &pathToUse);
						}
					}

				}
			}
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == outcomeMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsTrue(tester == 25);

		}
		TEST_METHOD(G5ACCP003)
		{
			int tester = 0;
			struct Point goTo = { 0,1 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {},3, 0.0, 0 };
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
				{2, 16, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 1, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Input testData = { {truckA},3,landScape };
			struct Truck* truckToDeploy;
			struct Map outcomeMap;

			outcomeMap = addRoute(&landScape, &testRoute);
			truckA.limitingFactor = calculateLimitingFactor(&truckA);

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateVolume(&truckA))
					{
						if (1 == validateLocation(&landScape, &package.destination))
						{
							truckToDeploy = findAvailableTruck(&testData, package.weight, package.size, package.destination);
							outcomeMap = addRoute(&outcomeMap, &pathToUse);
						}
					}

				}
			}
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == outcomeMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsTrue(tester == 25);

		}
		TEST_METHOD(G5ACCP004)
		{
			int tester = 0;
			struct Point goTo = { 3,2 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {},3, 0.0, 0 };
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
				{16, 16, 16, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Input testData = { {truckA},3,landScape };
			struct Truck* truckToDeploy;
			struct Map outcomeMap;

			outcomeMap = addRoute(&landScape, &testRoute);
			truckA.limitingFactor = calculateLimitingFactor(&truckA);

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateVolume(&truckA))
					{
						if (1 == validateLocation(&landScape, &package.destination))
						{
							truckToDeploy = findAvailableTruck(&testData, package.weight, package.size, package.destination);
							outcomeMap = addRoute(&outcomeMap, &pathToUse);
						}
					}

				}
			}
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == outcomeMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsTrue(tester == 25);

		}
		TEST_METHOD(G5ACCP005)
		{
			int tester = 0;
			struct Point goTo = { 3,2 };
			struct Point otherGoTo = { 0,1 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {},3, 0.0, 0 };
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
				{2, 16, 0, 0, 1},	//0
				{2, 1, 1, 0, 1},	//1
				{2, 1, 1, 0, 1},	//2
				{16, 16, 16, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			struct Point startB = { 0,0 };
			startB.row = getClosestPoint(&testRoute, otherGoTo);
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Route otherPathToUse = shortestPath(&landScape, startB, otherGoTo);
			struct Input testData = { {truckA},3,landScape };
			struct Truck* truckToDeploy;
			struct Map outcomeMap;

			outcomeMap = addRoute(&landScape, &testRoute);
			truckA.limitingFactor = calculateLimitingFactor(&truckA);

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateVolume(&truckA))
					{
						if (1 == validateLocation(&landScape, &package.destination))
						{
							truckToDeploy = findAvailableTruck(&testData, package.weight, package.size, package.destination);
							outcomeMap = addRoute(&outcomeMap, &pathToUse);
							outcomeMap = addRoute(&outcomeMap, &otherPathToUse);
						}
					}

				}
			}
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == outcomeMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsTrue(tester == 25);

		}
		TEST_METHOD(G5ACCP006)
		{
			int tester = 0;
			struct Point goTo = { 3,2 };
			struct Point otherGoTo = { 500,-11 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {},3, 0.0, 0 };
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
				{16, 16, 16, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			struct Point startB = { 0,0 };
			start.row = getClosestPoint(&testRoute, otherGoTo);
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Route otherPathToUse = shortestPath(&landScape, startB, otherGoTo);
			struct Input testData = { {truckA},3,landScape };
			struct Truck* truckToDeploy;
			struct Map outcomeMap;

			outcomeMap = addRoute(&landScape, &testRoute);
			truckA.limitingFactor = calculateLimitingFactor(&truckA);

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateVolume(&truckA))
					{
						if (1 == validateLocation(&landScape, &package.destination))
						{
							truckToDeploy = findAvailableTruck(&testData, package.weight, package.size, package.destination);
							outcomeMap = addRoute(&outcomeMap, &pathToUse);
							outcomeMap = addRoute(&outcomeMap, &otherPathToUse);
						}
					}

				}
			}
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == outcomeMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsTrue(tester == 25);

		}
		TEST_METHOD(G5ACCP007)
		{
			int tester = 0;
			struct Point goTo = { 8888,-232 };
			struct Point otherGoTo = { 3,2 };
			struct Box package = { 500,1.0,otherGoTo };
			struct Truck truckA = { {},3, 0.0, 0 };
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
				{16, 16, 16, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			struct Point startB = { 0,0 };
			startB.row = getClosestPoint(&testRoute, otherGoTo);
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Route otherPathToUse = shortestPath(&landScape, startB, otherGoTo);
			struct Input testData = { {truckA},3,landScape };
			struct Truck* truckToDeploy;
			struct Map outcomeMap;

			outcomeMap = addRoute(&landScape, &testRoute);
			truckA.limitingFactor = calculateLimitingFactor(&truckA);

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateVolume(&truckA))
					{
						if (1 == validateLocation(&landScape, &package.destination))
						{
							truckToDeploy = findAvailableTruck(&testData, package.weight, package.size, package.destination);
							outcomeMap = addRoute(&outcomeMap, &pathToUse);
							outcomeMap = addRoute(&outcomeMap, &otherPathToUse);
						}
					}

				}
			}
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == outcomeMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsTrue(tester == 25);

		}
		//Samin please debug your findAvailableTruck Function or just try to get this test working I have no idea how your function works I'm sorry
		TEST_METHOD(G5ACCP008)
		{
			int tester = 0;
			struct Point goTo = { 3,0 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {package},3, 0.0, 0, 0.0 };
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

			outcomeMap = addRoute(&landScape, &testRoute);
			truckA.limitingFactor = calculateLimitingFactor(&truckA);

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateLocation(&landScape, &package.destination))
					{
						truckToDeploy = findAvailableTruck(&testData, package.weight, package.size, package.destination);
						outcomeMap = addRoute(&outcomeMap, &pathToUse);
					}
				}
			}

			Assert::IsTrue(truckToDeploy->boxes == truckA.boxes);
			Assert::IsTrue(truckToDeploy->limitingFactor == truckA.limitingFactor);
			Assert::IsTrue(truckToDeploy->numBoxes == truckA.numBoxes);
			Assert::IsTrue(truckToDeploy->totalVolume == truckA.totalVolume);
			Assert::IsTrue(truckToDeploy->totalWeight == truckA.totalWeight);
		}
		TEST_METHOD(G5ACCN001)
		{
			int tester = 0;
			struct Point goTo = { 700,888 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {},3, 0.0, 0,0 };
			struct Map landScape = {
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 1, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}		//5
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
				{16, 16, 16, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Input testData = { {truckA},3,landScape };
			struct Truck* truckToDeploy;
			struct Map outcomeMap;

			outcomeMap = addRoute(&landScape, &testRoute);
			truckA.limitingFactor = calculateLimitingFactor(&truckA);

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateVolume(&truckA))
					{
						if (1 == validateLocation(&landScape, &package.destination))
						{
							truckToDeploy = findAvailableTruck(&testData, package.weight, package.size, package.destination);
							outcomeMap = addRoute(&outcomeMap, &pathToUse);
						}
					}

				}
			}
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == outcomeMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsFalse(tester == 25);

		}
		TEST_METHOD(G5ACCN002)
		{
			int tester = 0;
			struct Point goTo = { -892392,-888 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {},3, 0.0, 0,0 };
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
				{16, 16, 16, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Input testData = { {truckA},3,landScape };
			struct Truck* truckToDeploy;
			struct Map outcomeMap;

			outcomeMap = addRoute(&landScape, &testRoute);
			truckA.limitingFactor = calculateLimitingFactor(&truckA);

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateVolume(&truckA))
					{
						if (1 == validateLocation(&landScape, &package.destination))
						{
							truckToDeploy = findAvailableTruck(&testData, package.weight, package.size, package.destination);
							outcomeMap = addRoute(&outcomeMap, &pathToUse);
						}
					}

				}
			}
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == outcomeMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsFalse(tester == 25);

		}
		TEST_METHOD(G5ACCN003)
		{
			int tester = 0;
			struct Point goTo = { 3,0 };
			struct Box package = { 1001,1.0,goTo };
			struct Truck truckA = { {},3, 0.0, 0.0,0 };
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
			struct Input testData = { {truckA},3,landScape };
			struct Truck* truckToDeploy;
			struct Map outcomeMap;

			outcomeMap = addRoute(&landScape, &testRoute);
			truckA.limitingFactor = calculateLimitingFactor(&truckA);

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateVolume(&truckA))
					{
						if (1 == validateLocation(&landScape, &package.destination))
						{
							truckToDeploy = findAvailableTruck(&testData, package.weight, package.size, package.destination);
							outcomeMap = addRoute(&outcomeMap, &pathToUse);
						}
					}

				}
			}
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == outcomeMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsFalse(tester == 25);

		}
		TEST_METHOD(G5ACCN004)
		{
			int tester = 0;
			struct Point goTo = { 3,0 };
			struct Box package = { 100,500.0,goTo };
			struct Truck truckA = { {},3, 0.0, 0,0 };
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
			struct Input testData = { {truckA},3,landScape };
			struct Truck* truckToDeploy;
			struct Map outcomeMap;

			outcomeMap = addRoute(&landScape, &testRoute);
			truckA.limitingFactor = calculateLimitingFactor(&truckA);

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateVolume(&truckA))
					{
						if (1 == validateLocation(&landScape, &package.destination))
						{
							truckToDeploy = findAvailableTruck(&testData, package.weight, package.size, package.destination);
							outcomeMap = addRoute(&outcomeMap, &pathToUse);
						}
					}

				}
			}
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == outcomeMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsFalse(tester == 25);

		}
		TEST_METHOD(G5ACCN005)
		{
			int tester = 0;
			struct Point goTo = { 3,0 };
			struct Box package = { 100,1.0,goTo };
			struct Truck truckA = { {},3, 103493940.0, 0,0 };
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
			struct Input testData = { {truckA},3,landScape };
			struct Truck* truckToDeploy;
			struct Map outcomeMap;

			outcomeMap = addRoute(&landScape, &testRoute);
			truckA.limitingFactor = calculateLimitingFactor(&truckA);

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateVolume(&truckA))
					{
						if (1 == validateLocation(&landScape, &package.destination))
						{
							truckToDeploy = findAvailableTruck(&testData, package.weight, package.size, package.destination);
							outcomeMap = addRoute(&outcomeMap, &pathToUse);
						}
					}

				}
			}
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == outcomeMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsFalse(tester == 25);

		}
		TEST_METHOD(G5ACCN006)
		{
			int tester = 0;
			struct Point goTo = { 3,0 };
			struct Box package = { 100,1.0,goTo };
			struct Truck truckA = { {},3, 1005, 0,0 };
			struct Map landScape = {
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 1, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	    //5
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
			struct Input testData = { {truckA},3,landScape };
			struct Truck* truckToDeploy;
			struct Map outcomeMap;

			outcomeMap = addRoute(&landScape, &testRoute);
			truckA.limitingFactor = calculateLimitingFactor(&truckA);

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateVolume(&truckA))
					{
						if (1 == validateLocation(&landScape, &package.destination))
						{
							truckToDeploy = findAvailableTruck(&testData, package.weight, package.size, package.destination);
							outcomeMap = addRoute(&outcomeMap, &pathToUse);
						}
					}

				}
			}
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == outcomeMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsFalse(tester == 25);

		}
		TEST_METHOD(G5ACCN007)
		{
			int tester = 0;
			struct Point goTo = { 0,0 };
			struct Box package = { 500,1.0,goTo };
			struct Truck truckA = { {},3, 0.0, 0,0 };
			struct Map landScape = {
				{
				{0, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 1, 1, 0, 1},	//2
				{0, 0, 0, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}		//5
				},
				5,5
			};
			struct Route testRoute =
			{
					{
					{0,0}
					},
						1, 2
			};
			struct Map expectedMap = {
					{
				{2, 0, 0, 0, 1},	//0
				{0, 1, 1, 0, 1},	//1
				{0, 1, 1, 0, 1},	//2
				{16, 16, 16, 0, 0},	//3
				{0, 0, 0, 0, 0},	//4
				{0, 0, 0, 0, 0}	//5
				},
				5,5
			};

			struct Point start = { 0,0 };
			start.row = getClosestPoint(&testRoute, goTo);
			struct Route pathToUse = shortestPath(&landScape, start, goTo);
			struct Input testData = { {truckA},3,landScape };
			struct Truck* truckToDeploy;
			struct Map outcomeMap;

			outcomeMap = addRoute(&landScape, &testRoute);
			truckA.limitingFactor = calculateLimitingFactor(&truckA);

			if (1 == validateWeight(package.weight))
			{
				if (1 == validateBoxSize(package.size))
				{
					if (1 == validateVolume(&truckA))
					{
						if (1 == validateLocation(&landScape, &package.destination))
						{
							truckToDeploy = findAvailableTruck(&testData, package.weight, package.size, package.destination);
							outcomeMap = addRoute(&outcomeMap, &pathToUse);
						}
					}

				}
			}
			for (int i = 0; i < expectedMap.numRows; i++)
			{
				for (int k = 0; k < expectedMap.numCols; k++)
				{
					if (expectedMap.squares[i][k] == outcomeMap.squares[i][k])
					{
						tester++;
					}
				}
			}
			Assert::IsFalse(tester == 1);

		}
	};
}
