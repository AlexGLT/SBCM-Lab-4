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

std::shared_ptr<fieldElement> NormAdd(std::shared_ptr<fieldElement> firstElement, std::shared_ptr<fieldElement> secondElement);

char NormTr(std::shared_ptr<fieldElement> number);

std::shared_ptr<fieldElement> NormSquare(std::shared_ptr<fieldElement> number, bool text = true);