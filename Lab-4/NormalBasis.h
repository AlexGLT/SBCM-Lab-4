#include <iostream>
#include <memory>

struct fieldElement
{
	int size;

	int* value;

	std::string bitString = "";

	fieldElement();
	//	fieldElement(int size);
	fieldElement(std::string str);

	~fieldElement();
};

void showBigInteger(std::shared_ptr<fieldElement> number, std::string numberName = "Number");

std::shared_ptr<fieldElement> PolAdd(std::shared_ptr<fieldElement> firstElement, std::shared_ptr<fieldElement> secondElement);

char PolTr(std::shared_ptr<fieldElement> numberA);