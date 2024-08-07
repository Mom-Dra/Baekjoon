#include <iostream>

using namespace std;

int main()
{
	int num1, num2, num3;
	int num;
	int arr[10] = { 0 };

	cin >> num1;
	cin >> num2;
	cin >> num3;

	num = num1 * num2 * num3;

	while (num != 0) {
		int dnum = num % 10;
		num /= 10;
		arr[dnum]++;
	}

	for (int i = 0; i < 10; i++) {
		cout << arr[i] << endl;
	}
} 