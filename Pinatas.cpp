#include <iostream>
#include <algorithm>

using namespace std;

int recursion_candies(int* array, int length);

int maxCandies(int* array, int length)
{
	int maxCandiesAmount = 0;

	int* temporary_array = new int[length];

	if (length > 0)
	{
		for (int i = 0; i < length; i++)
		{
			int left = (i == 0) ? 1 : array[i - 1];
			int right = (i == length - 1) ? 1 : array[i + 1];
			int currentCandies = left * array[i] * right;
			cout << "candies[" << i << "]: " << currentCandies << endl;
			
			int* new_array = new int[length - 1];

			for (int j = 0, k = 0; j < length; j++)
			{
				if (j != i)
				{
					new_array[k++] = array[j];
				}
			}

			currentCandies += recursion_candies(new_array, length - 1);
			maxCandiesAmount = max(maxCandiesAmount, currentCandies);

			delete[] new_array;
		}
	}
	else
	{
		return 0;
	}


	delete[] temporary_array;

	return maxCandiesAmount;
}

int recursion_candies(int* array, int length)
{
	return maxCandies(array, length);
}

int main()
{
	int count;

	cout << "Enter number of pinatas: ";
	cin >> count;

	int* pinatas = new int[count];

	for (int i = 0; i < count; i++)
	{
		cout << "Enter the number of candies for " << i + 1 << " piñata: \n";
		cin >> pinatas[i];
	}

	int maxCandiesAmount = maxCandies(pinatas, count);

	cout << "Maximum number of candies: " << maxCandiesAmount << endl;

	delete[] pinatas;

	return 0;
}
