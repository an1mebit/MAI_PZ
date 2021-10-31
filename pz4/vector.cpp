#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;
int main()
{
	cout << "Enter a size of two vectors" << endl;
	int num1, num2;
	int sum1 = 0, sum2 = 0;
	cin >> num1 >> num2;

	vector<int> vec1(num1), vec2(num2);

	cout << "First vector: ";
	for (int& i : vec1)
	{
		i = rand() % 100 + 1;
		sum1 += i;
		cout << i << " ";
	}
	cout << endl;

	map<int, int> number;
	cout << "Second vector";
	for (int& i : vec2)
	{
		i = rand() % 100 + 1;
		sum2 += i;

		if (find(vec1.begin(), vec1.end(), i) != vec1.end()) number[i]++;
		cout << i << " ";
	}
	cout << endl;

	cout << "arithmetic mean of numbers of first vector is: " << float(sum1 / num1) << endl;
	cout << "arithmetic mean of numbers of second vector is: " << float(sum2 / num2) << endl;

	cout << "same elements: ";
	for (pair<int, int> tmp : number)
		cout << tmp.first << " ";
	cout << endl;
}
