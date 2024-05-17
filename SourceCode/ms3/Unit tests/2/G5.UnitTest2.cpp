#include "pch.h"
#include "CppUnitTest.h"
#include "ms3v2_r.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace G5UnitTest2
{
	TEST_CLASS(G5UnitTest2)
	{
	public:
		
		TEST_METHOD(posValidateVolumeTestMethod1)
		{
			struct Truck deliveryA = { {7,8}, 10,5.0, 100, 50.5 };
			int yesORno{};
			yesORno = validateVolume(&deliveryA);

			Assert::IsTrue(yesORno == 1);
			//If passes basic middle entries allowed.
			//Post Results: Passed
		}
		TEST_METHOD(posValidateVolumeTestMethod2)
		{
			struct Truck deliveryA = { {7,8}, 10,36.0, 100, 50.5 };
			int yesORno{};
			yesORno = validateVolume(&deliveryA);

			Assert::IsTrue(yesORno == 1);
			//If passes maximum valid entry allowed thus proving requirement for max value.
			//Post Results: Passed
		}
		TEST_METHOD(posValidateVolumeTestMethod3)
		{
			struct Truck deliveryA = { {7,8}, 10,1, 100, 50.5 };
			int yesORno{};
			yesORno = validateVolume(&deliveryA);

			Assert::IsTrue(yesORno == 1);
			//If passes minimum entry allowed thus proving requirement minimum entry requirement.
			//Post Results:Passed
		}
		TEST_METHOD(negValidateVolumeTestMethod1)
		{
			struct Truck deliveryA = { {7,8}, 10,0, 100, 50.5 };
			int yesORno{};
			yesORno = validateVolume(&deliveryA);

			Assert::IsTrue(yesORno == 0);
			//If this test passes it means safety precautions for if a truck has no more room will be taken account and volume limits requirement is further tested.
			//Post Results:Failed
		}
		TEST_METHOD(negValidateVolumeTestMethod2)
		{
			struct Truck deliveryA = { {7,8}, 10,36.01, 100, 50.5 };
			int yesORno{};
			yesORno = validateVolume(&deliveryA);

			Assert::IsTrue(yesORno == 0);
			//If this passes then a safety precaution for the volume limit is further implemented thus further fulfilling the requirement for volume limits.
			//Post Results:Passed
		}
		TEST_METHOD(negValidateVolumeTestMethod3)
		{
			struct Truck deliveryA = { {7,8}, 10,-9999, 100, 50.5 };
			int yesORno{};
			yesORno = validateVolume(&deliveryA);

			Assert::IsTrue(yesORno == 0);
			//If passes negative numbers will not be allowed thus procuring the requirement of erroneous test data is not acceptable.
			//Post Results:Failed
		}
		TEST_METHOD(negValidateVolumeTestMethod4)
		{
			struct Truck deliveryA = { {7,8}, 10,9999999999999999999, 100, 50.5 };
			int yesORno{};
			yesORno = validateVolume(&deliveryA);

			Assert::IsTrue(yesORno == 0);
			//If passes this test will procur the requirement to limit max entry.
			//Post Results:Passed
		}
		TEST_METHOD(negValidateVolumeTestMethod5)
		{
			struct Truck deliveryA = { {7,8}, 10,(0 / 2), 100, 50.5 };
			int yesORno{};
			yesORno = validateVolume(&deliveryA);

			Assert::IsTrue(yesORno == 0);
			//If passes the test without crashing then minimum entry requirement will be further proven, but however if it crashes the program is not safe against infinite reursion from divison by 2 on 0.
			//Post Results:Fail
		}
	
	
	};
}
