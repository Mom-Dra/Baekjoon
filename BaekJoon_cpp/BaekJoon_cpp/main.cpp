//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cmath>
//
//int main() {
//	int num;
//
//	std::cin >> num;
//
//	if (num == 0) {
//		std::cout << 0;
//		return 0;
//	}
//
//	int except = std::roundf(num / 100.0f * 15.0f);
//
//	std::vector<int> arr;
//
//	for (int i = 0; i < num; ++i) {
//		int var;
//		std::cin >> var;
//
//		arr.push_back(var);
//	}
//
//	std::sort(arr.begin(), arr.end());
//
//	/*for (int i = 0; i < num; ++i) {
//		std::cout << arr[i];
//	}*/
//
//	int sum = 0;
//
//	for (int i = except; i < num - except; ++i) {
//		sum += arr[i];
//	}
//
//	int average = std::roundf((float)sum / (num - except - except));
//
//	std::cout << average;
//}