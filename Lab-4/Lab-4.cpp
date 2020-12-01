#include <iostream>
#include <string>

#include "NormalBasis.h"

int main()
{
	srand(time(NULL));

	//	auto lambda = new int[191][191];

	auto** lambda = new int* [191];

	for (int i = 0; i < 191; i++)
	{
		lambda[i] = new int[191];
	}

	int mod = 383;


	auto left = 1;

	for (int i = 0; i < 191; i++)
	{
		auto right = 1;

		for (int j = 0; j < 191; j++)
		{
			auto firstEq = (left + right) % mod;

			if (firstEq < 0)
			{
				firstEq += mod;
			}

			auto secondEq = (left - right) % mod;

			if (secondEq < 0)
			{
				secondEq += mod;
			}

			auto thirdEq = (right - left) % mod;

			if (thirdEq < 0)
			{
				thirdEq += mod;
			}

			auto forthEq = (-left - right) % mod;

			if (forthEq < 0)
			{
				forthEq += mod;
			}

			if (firstEq == 1)
			{
				lambda[i][j] = 1;
			}
			else if (secondEq == 1)
			{
				lambda[i][j] = 1;
			}
			else if (thirdEq == 1)
			{
				lambda[i][j] = 1;
			}
			else if (forthEq == 1)
			{
				lambda[i][j] = 1;
			}
			else
			{
				lambda[i][j] = 0;
			}

			right = (right << 1);
			right %= mod;

		}

		left = (left << 1);
		left %= mod;
	}

// 	for (int i = 0; i < 191; i++)
// 	{
// 		for (int j = 0; j < 191; j++)
// 		{
// 			std::cout << lambda[i][j];
// 		}
// 		std::cout << std::endl;
// 	}

	std::string number;
	
	std::cout << "Input number A: ";
	std::cin >> number;
	auto numberA = std::make_shared<fieldElement>(number);
	
	std::cout << "Input number B: ";
	std::cin >> number;
	auto numberB = std::make_shared<fieldElement>(number);
	
	std::cout << "Input number C: ";
	std::cin >> number;
	auto numberС = std::make_shared<fieldElement>(number);
	
	std::cout << "Result of addition: ";
	auto addition = NormAdd(numberA, numberB);
	std::cout << addition->bitString << std::endl;

	std::cout << "Result of multiplication: ";
	auto multiplication = NormMul(numberA, numberB, lambda);
	std::cout << multiplication->bitString << std::endl;
	
// 	std::cout << "Trace of numberA: ";
// 	auto trace = NormTr(numberA);
// 	std::cout << trace << std::endl;
// 	
// 	std::cout << "Result of square: ";
// 	auto square = NormSquare(numberA);
// 	std::cout << square->bitString << std::endl;

// 	std::cout << "Result of pow: ";
// 	auto pow = NormPow(numberA, numberС, lambda);
// 	std::cout << pow->bitString << std::endl;

	std::cout << "Inverse element of numberA: ";
	auto inv = NormInv(numberA, lambda);
	std::cout << inv->bitString << std::endl;
}