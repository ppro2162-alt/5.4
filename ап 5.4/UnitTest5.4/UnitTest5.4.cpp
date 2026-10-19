#include "pch.h"
#include "CppUnitTest.h"

// Підключаємо код лабораторної. Перевірте шлях: папка проєкту "an 5.4"
// має лежати поруч з папкою "UnitTest5.4" у рішенні.
#include "C:\Users\USSER\Desktop\лаби\ап 5.4\ап 5.4\ап 5.4.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest54
{
	TEST_CLASS(UnitTest54)
	{
	public:

		// Перевіряє, що всі п'ять способів дають очікуване значення
		void CheckAll(const int K, const int N, const double expected)
		{
			const double eps = 1e-9;
			Assert::AreEqual(expected, S1(K, N, N, 0), eps, L"S1 (спуск, i--)");
			Assert::AreEqual(expected, S2(K, N, K, 0), eps, L"S2 (спуск, i++)");
			Assert::AreEqual(expected, S3(K, N, N), eps, L"S3 (підйом, i--)");
			Assert::AreEqual(expected, S4(K, N, K), eps, L"S4 (підйом, i++)");
			Assert::AreEqual(expected, S5(K, N), eps, L"S5 (ітерація)");
		}

		// (1 + 4 + 9) / (1 + 9) = 1.4
		TEST_METHOD(Example_K1_N3)
		{
			CheckAll(1, 3, 1.4);
		}

		// один доданок: 25 / 50 = 0.5
		TEST_METHOD(K_equals_N)
		{
			CheckAll(5, 5, 0.5);
		}

		// (4 + 9 + 16) / (4 + 16)
		TEST_METHOD(K2_N4)
		{
			CheckAll(2, 4, 29. / 20.);
		}

		// (0 + 1 + 4 + 9) / 9
		TEST_METHOD(K_zero)
		{
			CheckAll(0, 3, 14. / 9.);
		}

		// (4 + 1 + 0 + 1 + 4) / 8 = 1.25
		TEST_METHOD(K_negative)
		{
			CheckAll(-2, 2, 1.25);
		}

		// великий діапазон: рекурсивні способи збігаються з ітераційним
		TEST_METHOD(Large_range_matches_iterative)
		{
			const int K = 1, N = 1000;
			const double ref = S5(K, N);
			const double eps = 1e-9;
			Assert::AreEqual(ref, S1(K, N, N, 0), eps);
			Assert::AreEqual(ref, S2(K, N, K, 0), eps);
			Assert::AreEqual(ref, S3(K, N, N), eps);
			Assert::AreEqual(ref, S4(K, N, K), eps);
		}
	};
}