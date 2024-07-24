#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	cout << (num % 4 == 0 && num % 100 != 0 || num % 400 == 0);

} 