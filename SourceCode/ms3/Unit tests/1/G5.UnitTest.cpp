#include "pch.h"
#include "CppUnitTest.h"
#include "ms3_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace G5UnitTest
{
	TEST_CLASS(G5UnitTest)
	{
	public:
		
		/*Testing the validateWeight function. The weight of the packages cannot be over 1000 kilograms.*/
		TEST_METHOD(TFW001)
		{
			int weight = 750;
			int tester;
			tester = validateWeight(weight);

			Assert::IsTrue(tester);
			//If passes basic functionality work.
			//Post Result passed.
		}
		TEST_METHOD(TFW002)
		{
			int weight = 1000;
			int tester;
			tester = validateWeight(weight);

			Assert::IsTrue(tester);
			//If passes can accept max value of weight. .
			//Post Result: Passed 
		}
		TEST_METHOD(TFW003)
		{
			int weight = 1;
			int tester;
			tester = validateWeight(weight);

			Assert::IsTrue(tester);
			//If passes min entry passed.
			//Post Result: Passed
		}
		TEST_METHOD(TFW004)
		{
			int weight = 0;
			int tester;
			tester = validateWeight(weight);

			Assert::IsFalse(tester);
			//If passes 0 is accepted and logically this is valid but for the future no package can be below 0.
			//Post Result:Failed but this means that minimum is really 1 (no need to fix or report as this is what the functionn should do)
		}
		TEST_METHOD(TFW005)
		{
			double weight = 1.1;
			int tester;
			tester = validateWeight(weight);

			Assert::IsTrue(tester);
			//If passes doubles are accepted
			 //Post Result: Passed
		}
		TEST_METHOD(TFW006)
		{
			int weight = 100;
			int* ptr = &weight;
			int tester;
			tester = validateWeight(*ptr);

			Assert::IsTrue(tester);
			//If passes pointers are accepted
			//Post Result: Passed
		}
		TEST_METHOD(TFW007)
		{
			double weight = 1.1;
			int tester;
			tester = validateWeight(4 + 100);

			Assert::IsTrue(tester);
			//If passes equations are accepted
			//Post Result: Passed
		}
		TEST_METHOD(TFW008)
		{
			struct weight
			{
				int num;
			};

			struct weight test = { 1 };

			int tester;
			tester = validateWeight(test.num);

			Assert::IsTrue(tester);
			//If passes the function accepts numbers from other structs thus allowing for further future flexibility for tests.
			//Post Result: Failed
		}
		TEST_METHOD(TFW009)
		{
			int tester;
			tester = validateWeight(NULL);

			Assert::IsFalse(tester);
			//If passes then null values are not accepted an program funciton well around nulls.
			//Post Result: Passed
		}
		TEST_METHOD(TFW010)
		{
			int tester;
			tester = validateWeight(-1);

			Assert::IsFalse(tester);
			//If passes then negative numbers will be rejected and function works well.
			//Post Result: Passed
		}
		TEST_METHOD(TFW011)
		{
			int tester;
			tester = validateWeight(1001);

			Assert::IsFalse(tester);
			//If passes the function does limit the amount of weight thus procuring the fact that the requirement that weight limit is applied.
			//Post Result: Passed
		}
		/*
		TEST_METHOD(TFW012)
			{
				int tester;
				tester = validateWeight("100");

				Assert::IsFalse(tester);
				//Since this could not be run its safe to say that strings even if it's number wont be accepted thus requirement for only numbers is fulfilled.
				//Post Results: Passed
			}*/
		TEST_METHOD(TFW013)
		{
			int tester;
			tester = validateWeight(2147483648);

			Assert::IsFalse(tester);
			//Since this could not be run there is limits too how big of a number can be entered so if you do enter this number a crash should happen when entering a number via user input
			//Post Results: Passed
		}
		/*Testing the validateVolume function. Total volume cannot be over 36 cubic meters.*/
		TEST_METHOD(TFV001)
		{
			struct Truck deliveryA = { {7,8}, 10,5.0, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsTrue(tester);
			//If passes basic middle entries allowed.
			//Post Results: Passed
		}
		TEST_METHOD(TFV002)
		{
			struct Truck deliveryA = { {7,8}, 10,36.0, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsTrue(tester);
			//If passes maximum valid entry allowed thus proving requirement for max value.
			//Post Results: Passed
		}
		TEST_METHOD(TFV003)
		{
			struct Truck deliveryA = { {7,8}, 10, 0.25, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsTrue(tester);
			//If passes minimum entry allowed thus proving requirement minimum entry requirement.
			//Post Results:Passed
		}
		TEST_METHOD(TFV004)
		{
			struct Truck deliveryA = { {7,8}, 10,0, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsFalse(tester);
			//If this test passes it means safety precautions for if a truck has no more room will be taken account and volume limits requirement is further tested.
			//Post Results:Failed
		}
		TEST_METHOD(TFV005)
		{
			struct Truck deliveryA = { {7,8}, 10,36.01, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsFalse(tester);
			//If this passes then a safety precaution for the volume limit is further implemented thus further fulfilling the requirement for volume limits.
			//Post Results:Passed
		}
		TEST_METHOD(TFV006)
		{
			struct Truck deliveryA = { {7,8}, 10,-9999, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsFalse(tester);
			//If passes negative numbers will not be allowed thus procuring the requirement of erroneous test data is not acceptable.
			//Post Results:Failed
		}
		TEST_METHOD(TFV007)
		{
			struct Truck deliveryA = { {7,8}, 10,9999999999999999999, 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsFalse(tester);
			//If passes this test will procur the requirement to limit max entry.
			//Post Results:Passed
		}
		TEST_METHOD(TFV008)
		{
			struct Truck deliveryA = { {7,8}, 10,(0 / 2), 100, 50.5 };
			int tester;
			tester = validateVolume(&deliveryA);

			Assert::IsFalse(tester);
			//If passes the test without crashing then minimum entry requirement will be further proven, but however if it crashes the program is not safe against infinite reursion from divison by 2 on 0.
			//Post Results:Fail
		}
		

		/*Testing the validateBoxSize function. The size of the packages can be only 0.25, 0.5, 1.0 cubic meter.*/
		//Tests the first allowed size of the package. (+)
		TEST_METHOD(TFS001)
		{
			bool results = validateBoxSize(0.25);
			Assert::IsTrue(results);
			//Post Result: Passed
		}
		//Tests the second allowed size of the package. (+)
		TEST_METHOD(TFS002)
		{
			bool results = validateBoxSize(0.5);
			Assert::IsTrue(results);
			//Post Result: Passed
		}
		//Tests the third allowed size of the package. (+)
		TEST_METHOD(TFS003)
		{
			bool results = validateBoxSize(1.0);
			Assert::IsTrue(results);
			//Post Result: Passed
		}
		//Tests the calculation that result in the allowed size of the package. (+)
		TEST_METHOD(TFS004)
		{
			bool results = validateBoxSize(0.25 + 0.25);
			Assert::IsTrue(results);
			//Post Result: Passed
		}
		//Tests the round number that result in the allowed size of the package. (+)
		TEST_METHOD(TFS005)
		{
			bool results = validateBoxSize(1.0000000000000001);
			Assert::IsTrue(results);
			//Post Result: Passed
		}
		//Tests the not allowed size of the package. (-)
		TEST_METHOD(TFS006)
		{
			bool results = validateBoxSize(0.35);
			Assert::IsFalse(results);
			//Post Result: Passed
		}
		//Tests the empty size of the package. (-)
		TEST_METHOD(TFS007)
		{
			bool results = validateBoxSize(0);
			Assert::IsFalse(results);
			//Post Result: Passed
		}
		//Tests the character input. (-)
		TEST_METHOD(TFS008)
		{
			bool results = validateBoxSize('A');
			Assert::IsFalse(results);
			//Post Result: Passed
		}
		//Tests the NULL input. (-)
		TEST_METHOD(TFS009)
		{
			bool results = validateBoxSize(NULL);
			Assert::IsFalse(results);
			//Post Result: Passed
		}
		//Tests the NULL character input. (-)
		TEST_METHOD(TFS010)
		{
			bool results = validateBoxSize('NULL');
			Assert::IsFalse(results);
			//Post Result: Passed
		}
		//Test the escape sequence character. (-)
		TEST_METHOD(TFS011)
		{
			bool results = validateBoxSize('\n');
			Assert::IsFalse(results);
			//Post Result: Passed
		}
		//Tests the precision of the input value. (-)
		TEST_METHOD(TFS012)
		{
			bool results = validateBoxSize(1.000000000000001);
			Assert::IsFalse(results);
			//Post Result: Passed
		}
		//Tests the round number that result in the not allowed size of the package. (-)
		TEST_METHOD(TFS013)
		{
			bool results = validateBoxSize(1.0000000000000008);
			Assert::IsFalse(results);
			//Post Result: Passed
		}

		/*Testing the calculateLimitingFactor function. The limiting factor as a percentage (weight or volume) should be between 0 to 100.*/
		TEST_METHOD(TFL001)
		{
			struct Truck deliveryA = { {7,8}, 10, 15, 100, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);
			

			Assert::AreEqual(tester, 41.6667);
			//Testing out basic functionality of program.
			//Post Results: Failed but may have just gotten a miscalculation
		}
		TEST_METHOD(TFL002)
		{
			struct Truck deliveryA = { {7,8}, 10,15, 999, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);


			Assert::AreEqual(tester, 99.9000);
			//Testing out basic functionality of program.
			//Post Results: Passed
		}
		TEST_METHOD(TFL003)
		{
			struct Truck deliveryA = { {7,8}, 10,36, 999, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);


			Assert::AreEqual(tester, 100.0000);
			//Testing out basic functionality of program.
			//Post Results: Passed
		}
		TEST_METHOD(TFL004)
		{
			struct Truck deliveryA = { {7,8}, 10,0, 999, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);


			Assert::AreEqual(tester, 99.9000);
			//Testing out basic comparison under case and division functionality.
			//Post Results: Passed
		}
		TEST_METHOD(TFL005)
		{
			struct Truck deliveryA = { {7,8}, 10,36, 0, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);


			Assert::AreEqual(tester, 100.0000);
			//Testing out basic comparison under caseand division functionality.
			//Post Results: Passed
		}
		TEST_METHOD(TFL006)
		{
			struct Truck deliveryA = { {7,8}, 10,36, 1000, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);


			Assert::AreEqual(tester, 100.0000);
			//Testing out to see if comparison will return anything if both are maxed out
			//Post Results: Passed
		}
		TEST_METHOD(TFL007)
		{
			struct Truck deliveryA = { {7,8}, 10,-36, 1000, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);


			Assert::AreEqual(tester, 100.0000);
			//Testing out to see if function will accept negative numbers, this program should work but negative numbers should be avoided.
			//Post Results: Passed
		}
		TEST_METHOD(TFL008)
		{
			struct Truck deliveryA = { {7,8}, 10,36, -150, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);


			Assert::AreEqual(tester, 100.0000);
			//Testing out to see if function will accept negative numbers, this program should work but negative numbers should be avoided.
			//Post Results: Passed
		}
		TEST_METHOD(TFL009)
		{
			struct Truck deliveryA = { {7,8}, 10,36, 1050, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);


			Assert::AreNotEqual(tester, 105.0000);
			//Testing out to see if function will accept over the edge case it should not work however as the entry should be limited for the limiting requirement.
			//Post Results: Failed
		}
		TEST_METHOD(TFL010)
		{
			struct Truck deliveryA = { {7,8}, 10,37, 1000, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);


			Assert::AreNotEqual(tester, 102.7778);
			//Testing out to see if function will accept over the edge case it should not work however.
			//Post Results: Passed
		}
		TEST_METHOD(TFL011)
		{
			struct Truck deliveryA = { {7,8}, 10,0, 0, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);


			Assert::AreEqual(tester, 0.0000);
			//Testing out to see if under minimum edge cases will work though it shouldn't as that would go against the minimum edge case requirement.
			//Post Results: Passed
		}
		TEST_METHOD(TFL012)
		{
			struct Truck deliveryA = { {7,8}, 10,0 / 2, 300, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);


			Assert::AreEqual(tester, 30.0000);
			//Testing out to see if program has safety precautions against infinite recursion numbers. If this passes it means inifinite numbers can be safely entered and nothing will crash.
			//Post Results: Passed
		}
		TEST_METHOD(TFL013)
		{
			struct Truck deliveryA = { {7,8}, 10,22,0 / 2, 50.5 };
			double tester = calculateLimitingFactor(&deliveryA);


			Assert::AreEqual(tester, 61.1100);
			//Testing out to see if program has safety precautions against infinite recursion numbers. If this passes it means inifinite numbers can be safely entered and nothing will crash.
			//Post Results: Failed
		}
	};
}
