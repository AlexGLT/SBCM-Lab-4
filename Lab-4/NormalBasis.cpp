#include "NormalBasis.h"

fieldElement::fieldElement()
{
	bitString = "1";

	size = 1;

	value = new int{ 1 };
}

fieldElement::fieldElement(int size)
{
	std::string bitString = "";

	this->size = size;

	value = new int[size];
}

fieldElement::fieldElement(std::string str)
{
	bitString = str;
	size = str.size();

	value = new int[size];

	for (int i = 0; i < size; i++)
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
	auto sumElement = std::make_shared<fieldElement>(firstElement->size);

	for (int i = 0; i < firstElement->size; i++)
	{
		sumElement->value[i] = (firstElement->value[i] + secondElement->value[i]) % 2;

		sumElement->bitString += static_cast<char>(sumElement->value[i] + 48);
	}

	return sumElement;
}