#include <iostream>
#include <vector>
#include <string>

void Quard(const std::vector<std::string>& arr, std::string& s, int a, int b, int length)
{
	bool isBlackTrigger{ false };
	bool isWhileTrigger{ false };

	for (int i = a; i < a + length; ++i)
	{
		for (int j = b; j < b + length; ++j)
		{
			if (arr[i][j] == '1')
			{
				isWhileTrigger = true;

				if (isBlackTrigger) break;
			}
			else
			{
				isBlackTrigger = true;

				if (isWhileTrigger) break;
			}
		}
	}

	if (isWhileTrigger && !isBlackTrigger)
	{
		s.append("1");
	}
	else if (!isWhileTrigger && isBlackTrigger)
	{
		s.append("0");
	}
	else if (isWhileTrigger && isBlackTrigger)
	{
		s.append("(");
		int dl{ length / 2 };
		Quard(arr, s, a, b, dl);
		Quard(arr, s, a, b + dl, dl);
		Quard(arr, s, a + dl, b, dl);
		Quard(arr, s, a + dl, b + dl, dl);
		s.append(")");
	}
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;

	//std::vector<std::vector<int>> arr(n, std::vector<int>(n));

	std::vector<std::string> arr(n);

	for (int i = 0; i < n; ++i)
	{
		std::cin >> arr[i];
	}

	std::string s;
	Quard(arr, s, 0, 0, n);

	std::cout << s;
}