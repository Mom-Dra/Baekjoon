#include <iostream>
#include <vector>
#include <algorithm>

std::pair<int, int> getTwoPrime(const std::vector<bool>& primes, int num)
{
	std::pair<int, int> prime;

	for (int i{ 1 }; i <= num / 2; ++i)
	{
		if (primes[i] && primes[num - i])
		{
			prime.first = i;
			prime.second = num - i;
		}
	}

	return prime;
}

std::vector<bool> sieve(int n)
{
	std::vector<bool> isPrime(n + 1, true);
	isPrime[0] = isPrime[1] = false;

	for (int i{ 2 }; i * i <= n; ++i)
	{
		if (isPrime[i])
		{
			for (int j{ i * i }; j <= n; j += i)
				isPrime[j] = false;
		}
	}

	return isPrime;
}

int main()
{
	int T;
	std::cin >> T;

	std::vector<int> arr(T, 0);

	for (auto& num : arr)
		std::cin >> num;

	int max{ *std::max_element(arr.begin(), arr.end()) };

	std::vector<bool> primes{ sieve(max) };

	for (const auto& num : arr)
	{
		const auto& [left, right] {getTwoPrime(primes, num)};
		std::cout << left << ' ' << right << '\n';
	}

	return 0;
}