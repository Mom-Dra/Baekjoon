#include <iostream>

int main()
{
	int A, B, C;
	std::cin >> A >> B;
	std::cin >> C;

	int hour{ A };
	int minute{ B + C };

	int addedHour{ minute / 60 };
	
	minute %= 60;

	hour = (hour + addedHour) % 24;

	std::cout << hour << ' ' << minute;

	return 0;
}