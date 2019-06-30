#pragma once
template<class T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

int ascending_compare(void* a, void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2)
		return -1;

	if (num1 < num2)
		return 1;

	return 0;
}

int descending_compare(void* a, void* b)
{
	int num1 = *(int*)a;
	int num2 = *(int*)b;

	if (num1 > num2)
		return 1;

	if (num1 < num2)
		return -1;

	return 0;
}