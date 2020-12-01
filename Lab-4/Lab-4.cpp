#include <iostream>
#include "NormalBasis.h"

int main()
{
	srand(time(NULL));

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

//	auto generator = std::make_shared<fieldElement>("100000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001000000001");

	std::cout << "Result of addition: ";
	auto addition = NormAdd(numberA, numberB);
	std::cout << addition->bitString << std::endl;

	std::cout << "Trace of numberA: ";
	auto trace = NormTr(numberA);
	std::cout << trace << std::endl;

	std::cout << "Result of square: ";
	auto square = NormSquare(numberA);
	std::cout << square->bitString << std::endl;
}