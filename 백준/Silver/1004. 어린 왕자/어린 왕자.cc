#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <cmath>

bool isContain(const std::tuple<int, int, int>& circle, const std::pair<int, int>& point)
{
	const auto& [cx, cy, r] {circle};
	const auto& [x, y] {point};

	return std::pow(cx - x, 2) + std::pow(cy - y, 2) < std::pow(r, 2);
}

int main()
{
	int T;

	std::cin >> T;

	for (int i{ 0 }; i < T; ++i)
	{
		std::pair<int, int> departure;
		std::pair<int, int> arrival;

		std::cin >> departure.first;
		std::cin >> departure.second;

		std::cin >> arrival.first;
		std::cin >> arrival.second;

		int n;

		std::cin >> n;

		std::vector<bool> count(n, false);

		for (int j{ 0 }; j < n; ++j)
		{
			std::tuple<int, int, int> circle;

			std::cin >> std::get<0>(circle) >> std::get<1>(circle) >> std::get<2>(circle);

			if (isContain(circle, departure))
				count[j] = !count[j];

			if (isContain(circle, arrival))
				count[j] = !count[j];
		}

		std::cout << std::count(count.begin(), count.end(), true) << '\n';
	}

	return 0;
}