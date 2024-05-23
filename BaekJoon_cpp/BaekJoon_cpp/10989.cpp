//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//int main()
//{	
//	std::ios_base::sync_with_stdio(false);
//	std::cin.tie(nullptr);
//	std::cout.tie(nullptr);
//
//	int n;
//
//	int arr[10001] = { 0, };
//
//	std::cin >> n;
//
//	for (int i = 0; i < n; ++i) {
//		int number;
//		std::cin >> number;
//
//		++arr[number];
//	}
//
//	for (int i = 0; i < 10001; ++i) {
//		for (int j = 0; j < arr[i]; ++j) {
//			if(arr[i] > 0)
//				std::cout << i << '\n';
//		}
//	}
//}