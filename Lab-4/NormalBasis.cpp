#include "NormalBasis.h"
#include <string>

fieldElement::fieldElement()
{
	this->size = 191;
	value = new int[this->size];
	
	std::fill(&value[0], &value[191], 0);

	for (int i = 0; i < 191; i++)
	{
		bitString += "0";
	}
}

fieldElement::fieldElement(std::string str)
{
	bitString = str;
	size = str.size();

//	value = new int[size];
	value = new int[191];

	for (int i = 0; i < 191; i++)
	{
		value[i] = static_cast<int>(str[i]) - 48;
	}
}

fieldElement::~fieldElement()
{
	delete[] value;
	value = nullptr;
}

void showBigInteger(std::shared_ptr<fieldElement> number, std::string numberName)
{
	std::cout << numberName << ": " << std::endl;

	for (int i = 0; i < number->size; i++)
	{
		std::cout << number->value[i];
	}

	std::cout << std::endl;
}

std::shared_ptr<fieldElement> CyclicShift(std::shared_ptr<fieldElement> firstElement)
{
	auto shiftedElement = std::make_shared<fieldElement>();

	for (int i = 0; i < 190; i++)
	{
		shiftedElement->value[i] = firstElement->value[i + 1];
	}

	shiftedElement->value[190] = firstElement->value[0];

	return shiftedElement;
}

std::shared_ptr<fieldElement> NormAdd(std::shared_ptr<fieldElement> firstElement, std::shared_ptr<fieldElement> secondElement)
{
	auto sumElement = std::make_shared<fieldElement>();
	
	sumElement->bitString = "";
	
	for (int i = 0; i < 191; i++)
	{
		sumElement->value[i] = (firstElement->value[i] + secondElement->value[i]) % 2;

		sumElement->bitString += static_cast<char>(sumElement->value[i] + 48);
	}

	return sumElement;
}

std::shared_ptr<fieldElement> NormMul(std::shared_ptr<fieldElement> firstElement, std::shared_ptr<fieldElement> secondElement, int** lambda, bool text)
{
	auto shiftedFirstElement = std::make_shared<fieldElement>();
	auto shiftedSecondElement = std::make_shared<fieldElement>();

	std::copy(firstElement->value, firstElement->value + 191, shiftedFirstElement->value);
	std::copy(secondElement->value, secondElement->value + 191, shiftedSecondElement->value);

	auto multiplication = std::make_shared<fieldElement>();

	for (int i = 0; i < 191; i++)
	{
		if (i != 0)
		{
			shiftedFirstElement = CyclicShift(shiftedFirstElement);
			shiftedSecondElement = CyclicShift(shiftedSecondElement);
		}

		int* temp = new int[191];

		for (int j = 0; j < 191; j++)
		{
			int sum = 0;

			for (int k = 0; k < 191; k++)
			{
				sum += shiftedFirstElement->value[k] * lambda[k][j];
			}

			temp[j] = (sum % 2);
		}

		int sum = 0;

		for (int j = 0; j < 191; j++)
		{
			sum += temp[j] * shiftedSecondElement->value[j];
		}

		multiplication->value[i] = (sum % 2);
	}

	if (text)
	{
		multiplication->bitString = "";

		for (int i = 0; i < 191; i++)
		{
			multiplication->bitString += static_cast<char>(multiplication->value[i] + 48);
		}
	}

	return multiplication;
}

char NormTr(std::shared_ptr<fieldElement> number)
{
	int trace = 0;

	for (int i = 0; i < 191; i++)
	{
		trace += number->value[i];
	}

	trace %= 2;

	if (trace == 0)
	{
		return '0';
	}
	else if (trace == 1)
	{
		return '1';
	}

	return 'F';
}

std::shared_ptr<fieldElement> NormSquare(std::shared_ptr<fieldElement> number, bool text)
{
	auto square = std::make_shared<fieldElement>();

	square->value[0] = number->value[190];

	for (int i = 1; i < 191; i++)
	{
		square->value[i] = number->value[i - 1];
	}

	if (text)
	{
		square->bitString = "";

		for (int i = 0; i < 191; i++)
		{
			square->bitString += static_cast<char>(square->value[i] + 48);
		}
	}

	return square;
}

std::shared_ptr<fieldElement> NormPow(std::shared_ptr<fieldElement> numberA, std::shared_ptr<fieldElement> numberB, int** lambda, bool text)
{
	auto numberC = std::make_shared<fieldElement>();
	std::fill(&numberC->value[0], &numberC->value[191], 1);

	for (long long i = 0; i < 191; i++)
	{
		if (numberB->value[i] == 1)
		{
			numberC = NormMul(numberC, numberA, lambda, false);
		}

		if (i != 190)
		{
			numberC = NormSquare(numberC, false);
		}
	}

	if (text)
	{
		numberC->bitString = "";

		for (int i = 0; i < numberC->size; i++)
		{
			numberC->bitString += static_cast<char>(numberC->value[i] + 48);
		}
	}

	return numberC;
}

std::shared_ptr<fieldElement> NormInv(std::shared_ptr<fieldElement> numberA, int** lambda)
{
	std::string pow;

	for (int i = 0; i < 191; i++)
	{
		if (i == 190)
		{
			pow += "0";
		}
		else
		{
			pow += "1";
		}
	}

	return NormPow(numberA, std::make_shared<fieldElement>(pow), lambda);
}