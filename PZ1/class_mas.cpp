#include <iostream>

class mas
{
private:

	int size;
	int* arr;

public:

	mas(int count);
	mas(const  mas &array);
	~mas();

	void print();
	void add(int count);
	void summ(mas & array);
	void subt(mas & array);

};

mas::mas(int count) : size(count)
{
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = i;
}

mas::mas(const mas& array): size(array.size), arr(nullptr)
{
	arr = new int[size];
	for (int i = 0; i < size; i++)
		arr[i] = array.arr[i];
}

mas::~mas()
{
	std::cout << "destruct"<<std::endl;
	delete[] arr;
}

void mas::print()
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

void mas::add(int value)
{
	if (value >= 101 || value <= -101)
	{
		std::cout << "OUT OF RANGE" << std::endl;
		exit(-1);
	}
	int* mas = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		mas[i] = arr[i];
	}
	mas[size] = value;
	delete[] arr;
	arr = mas;
	size++;
}

void mas::summ(mas & array)
{
	int sum1 = 0; int sum2 = 0;
	for (int i = 0; i < size; i++)
	{
		sum1 += arr[i];
	}

	for (int i = 0; i < array.size; i++)
	{
		sum2 += array.arr[i];
	}

	std::cout << "Summ of two dinamic massives: " << sum1 + sum2 << std::endl;
}

void mas::subt(mas& array)
{
	int sum1 = 0; int sum2 = 0;
	for (int i = 0; i < size; i++)
	{
		sum1 += arr[i];
	}

	for (int i = 0; i < array.size; i++)
	{
		sum2 += array.arr[i];
	}

	std::cout << "Substraction of two dinamic massives: " << sum1 - sum2 << std::endl;
}

int main()
{
	mas arr(10);
	arr.add(34);
	arr.print();


	mas arr2 (arr);
	arr2.print();

	std::cout << std::endl;
	arr.summ(arr2);
	arr.subt(arr2);

	return 0;
}
