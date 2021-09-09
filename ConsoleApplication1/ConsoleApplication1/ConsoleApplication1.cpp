#include <iostream>
#include <cmath>
#include <set>

using namespace std;

// Function, which search twins-devisors
long long searchTwin(long long number)
{
	long long suspect = 0;
	suspect = sqrt(number);
	if ((number % suspect == 0) && (number % (suspect + 1) == 0))
	{
		return suspect + 1;
	}
	else
	{
		return -1;
	}
}

// Function, which gets max power of 2 in this number
long long maxPower(long long number)
{
	long long answer = 0;
	long long subject = number;
	while (subject % 2 == 0)
	{
		answer++;
		subject = subject / 2;
	}
	return answer;
}

bool isItPowerOf2(long long number)
{
	if (number < 0) return false;
	long long subject = number;
	while (subject % 2 == 0)
	{
		subject = subject / 2;
	}
	if (subject > 1) return false;
	else return true;
}

int main()
{
	long long fights;
	cin >> fights;
	set <long long> answer;
	// polong longA
	if (searchTwin(2 * fights) != -1)
	{
		answer.insert(searchTwin(2 * fights));
	}
	long long powerOf2 = maxPower(fights);
	long long oddNumber = fights;
	for (int i = 0; i < powerOf2; i++)
	{
		oddNumber = oddNumber / 2;
	}
	// search odd divisors in oddNumber
	set <long long> oddDivisors;
	for (int i = 1; i <= oddNumber / 2; i++)
	{
		if (oddNumber % i == 0)
		{
			oddDivisors.insert(i);
			oddDivisors.insert(oddNumber / i);
		}
	}
	//polong longB
	for (auto it = oddDivisors.begin(); it != oddDivisors.end(); ++it)
	{
		long long suspect = (fights / *it) + 1 - ((*it - 1) / 2);
		if (isItPowerOf2(suspect))
		{
			answer.insert(suspect * (*it));
		}
	}
	if (answer.empty())
	{
		cout << "-1";
		return 0;
	}
	for (auto it = answer.begin(); it != answer.end(); ++it)
	{
		cout << *it <<"\n";
	}
	return 0;
}
