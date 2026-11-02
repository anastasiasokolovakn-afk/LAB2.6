#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB2.6/Lorry.h"
#include "../LAB2.6/Lorry.cpp"
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestNestedCarInitialization)
		{
			Lorry::Car testCar("Mazda", 4, 150.0);

			Assert::AreEqual(string("Mazda"), testCar.GetBrand());
			Assert::AreEqual(4, testCar.GetCylinders());
			Assert::AreEqual(150.0, testCar.GetPower());
		}

		TEST_METHOD(TestStaticCounters)
		{
			int initialCarCount = Lorry::Car::GetCarCount();
			int initialLorryCount = Lorry::GetLorryCount();
			{
				Lorry::Car tempCar("Test", 4, 100.0);
				Lorry tempLorry(tempCar, 10.0);
				Assert::AreEqual(initialCarCount + 2, Lorry::Car::GetCarCount()); 
				Assert::AreEqual(initialLorryCount + 1, Lorry::GetLorryCount());
			}
			Assert::AreEqual(initialCarCount, Lorry::Car::GetCarCount());
			Assert::AreEqual(initialLorryCount, Lorry::GetLorryCount());
		}

		TEST_METHOD(TestLorryIncrement)
		{
			Lorry::Car testCar("Ford", 6, 200.0);
			Lorry testLorry(testCar, 15.0);

			Assert::AreEqual(15.0, testLorry.GetCapacity());
			++testLorry;
			Assert::AreEqual(20.0, testLorry.GetCapacity());
		}

		TEST_METHOD(TestSettersValidation)
		{
			Lorry::Car invalidCar;

			Assert::IsFalse(invalidCar.SetPower(-50.0));
			Assert::AreEqual(0.0, invalidCar.GetPower());
		}
	};
}