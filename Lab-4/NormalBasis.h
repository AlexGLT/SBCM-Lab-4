#include <iostream>
#include <memory>

#include "LongArithmetic.h"

struct fieldElement
{
	int size;

	int* value;

	std::string bitString = "";

	fieldElement();
	fieldElement(std::string str);

	~fieldElement();
};

void showBigInteger(std::shared_ptr<fieldElement> number, std::string numberName = "Number");

std::shared_ptr<fieldElement> NormAdd(std::shared_ptr<fieldElement> firstElement, std::shared_ptr<fieldElement> secondElement);

std::shared_ptr<fieldElement> NormMul(std::shared_ptr<fieldElement> firstElement, std::shared_ptr<fieldElement> secondElement, int** lambda, bool text = true);

char NormTr(std::shared_ptr<fieldElement> number);

std::shared_ptr<fieldElement> NormSquare(std::shared_ptr<fieldElement> number, bool text = true);

std::shared_ptr<fieldElement> NormPow(std::shared_ptr<fieldElement> numberA, std::shared_ptr<fieldElement> numberB, int** lambda, bool text = true);

std::shared_ptr<fieldElement> NormInv(std::shared_ptr<fieldElement> numberA, int** lambda);