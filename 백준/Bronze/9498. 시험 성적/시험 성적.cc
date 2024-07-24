#include <iostream>

using namespace std;

int main()
{
	int num;
	cin >> num;

	string s;

	if (num >= 90) s = "A";
	else if (num >= 80) s = "B";
	else if (num >= 70) s = "C";
	else if (num >= 60) s = "D";
	else s = "F";

	cout << s;

} 