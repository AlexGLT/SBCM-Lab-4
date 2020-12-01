#include <iostream>
#include <memory>

struct fieldElement
{
	int size;

	int* value;

	std::string bitString;
	std::string hexString;

	fieldElement();
	fieldElement(int size);
	fieldElement(std::string str);

	~fieldElement();
};

void showBigInteger(std::shared_ptr<fieldElement> number, std::string numberName = "Number");

std::shared_ptr<fieldElement> PolAdd(std::shared_ptr<fieldElement> firstElement, std::shared_ptr<fieldElement> secondElement);