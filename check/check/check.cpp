#include <iostream>

using namespace std;

int main()
{
	int number;
	cin >> number;
	int answer = 0;
	while (number % 2 == 0)
	{
		answer = answer + number / 2;
	}
	answer = answer + number * (number - 1) / 2;
	cout << answer;
	return 0;
}