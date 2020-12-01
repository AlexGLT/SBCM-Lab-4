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

// fieldElement::fieldElement(int size)
// {
// 	std::string bitString = "";
// 
// 	this->size = size;
// 
// 	value = new int[size];
// }

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

std::shared_ptr<fieldElement> PolAdd(std::shared_ptr<fieldElement> firstElement, std::shared_ptr<fieldElement> secondElement)
{
	auto sumElement = std::make_shared<fieldElement>();

	for (int i = 0; i < 191; i++)
	{
		sumElement->value[i] = (firstElement->value[i] + secondElement->value[i]) % 2;

		sumElement->bitString += static_cast<char>(sumElement->value[i] + 48);
	}

	return sumElement;
}

char PolTr(std::shared_ptr<fieldElement> number)
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