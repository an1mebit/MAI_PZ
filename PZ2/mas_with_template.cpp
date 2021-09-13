#include <iostream>
#include <execution>
#include <cmath>

template<typename T>
class mas
{
private:

	int size;
	T* arr;

public:

	mas(int count);
	mas(const  mas<T>& array);
	~mas();

	void print();
	void add(mas<T>& arr);
	void summ(mas<T>& array);
	void subt(mas<T>& array);
	void distance(mas<T>& arr1 , mas<T>& arr2);

};

template<typename T>
mas<T>::mas(int count) : size(count)
{
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = i;
	if (size == NULL)
		throw std::bad_alloc();
}	

template<typename T>
mas<T>::mas(const mas<T>& array) : size(array.size), arr(nullptr)
{
	arr = new T[size];
	for (int i = 0; i < size; i++)
		arr[i] = array.arr[i];
	if (array.size < size)
		throw std::out_of_range("Out of range");
}

template<typename T>
mas<T>::~mas()
{
	//delete[] arr;
}

template<typename T>
void mas<T>::print()
{
	for (int i = 0; i < size; i++)
		std::cout << arr[i] << " ";
	std::cout << std::endl;
}

template<typename T>
void mas<T>::add(mas<T>& arr)
{
	int val = arr.size;
	arr.arr[arr.size] = val;
	arr.size++;
		
	/*
			if (arr.size > 100 || arr.size < -100)
		{
			std::cout << "TOO MUCH" << std::endl;
			exit(-1);
		}
	*/
		
	try
	{
		if (arr.size > 101 || arr.size < 101)
		{
			throw 101;
			throw - 101;
		}



	}
	catch (int error)
	{
			std::cerr << "Invalid argument: " << error << std::endl;
			exit(-1);
	}
}

template<typename T>
void mas<T>::summ(mas<T>& array)
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

template<typename T>
void mas<T>::subt(mas<T>& array)
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

template<typename T>
void mas<T>::distance(mas<T>& arr1, mas<T>& arr2)
{
	int i = 0;

	int ret = 0;
	while (arr1.arr[i] != arr1.arr[arr1.size])
	{
		int dist = arr1.arr[i] - arr2.arr[i];
		i++;
		ret += dist * dist;
	}

	if (ret > 0.0)
		sqrt(ret);
	else
		ret = 0.0;
	std::cout << "Distance between is two mas: " << ret << std::endl;
}

int main()
{
	mas<int> arr(100);
	arr.add(arr);
	arr.print();

	mas<int> arr2 = arr;
	arr2.print();

	std::cout << std::endl;
	arr.summ(arr2); //сумма элементов двух массивов ¯\_(ツ)_/¯
	arr.subt(arr2); //вывести должно 0, т.к. массивы одинаковые
	arr.distance(arr, arr2); //вывести должно 0, т.к. массивы одинаковые

	return 0;
}
