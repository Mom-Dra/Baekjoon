#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <limits>

int GetChikenDistance(const std::vector<std::pair<int, int>>& chikens, const std::pair<int, int>& home)
{
    int min{std::numeric_limits<int>::max()};
    
    for(const auto& chiken : chikens)
    {
        int dis{ std::abs(chiken.first - home.first) + std::abs(chiken.second - home.second) };
        min = std::min(min, dis);
    }

	return min;
}

int GetCityChikenDistance(const std::vector<std::pair<int, int>>& chikens, const std::vector<std::pair<int, int>>& homes)
{
    int distance{0};
    
    for(const auto& home : homes)
    {
        distance += GetChikenDistance(chikens, home);
    }
    
	return distance;
}

int BackTrack(const std::vector<std::pair<int, int>>& chikens, const std::vector<std::pair<int, int>>& homes, std::vector<std::pair<int, int>>& included, int curr, int m)
{
    if(included.size() == m)
    {
        return GetCityChikenDistance(included, homes);
    }
    
    int min{std::numeric_limits<int>::max()};
    
    for(int i{curr}; i < chikens.size(); ++i)
    {
        included.emplace_back(chikens[i].first, chikens[i].second);
        min = std::min(min, BackTrack(chikens, homes, included, i + 1, m));
        included.pop_back();
    }
    
    return min;
}

int Solve(const std::vector<std::pair<int, int>>& chikens, const std::vector<std::pair<int, int>>& homes, int m)
{
    std::vector<std::pair<int, int>> included;
    
    return BackTrack(chikens, homes, included, 0, m);
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> arr(n, std::vector<int>(n, 0));
	
	std::vector<std::pair<int, int>> chikens;
	std::vector<std::pair<int, int>> homes;
	
	for(int i{0}; i < n; ++i)
	{
	    for(int j{0}; j < n; ++j)
	    {
	        int num;
	        std::cin >> num;
	        
	        arr[i][j] = num;
	        
	        switch(num)
	        {
            case 1:
	            homes.emplace_back(i, j);
	            break;
	       
	        case 2:
	            chikens.emplace_back(i, j);
	            break;
	        }
	    }
	}
	
	std::cout << Solve(chikens, homes, m);
	
	return 0;
}