#include <iostream>
#include <vector>

int solve(int length, int width, int height, std::vector<int>& cubes)
{
    if (length == 0 || width == 0 || height == 0)
        return 0;
    
    int curr = cubes.size() - 1;
    int l;
    for (; curr >= 0; --curr)
    {
        if (cubes[curr] <= 0) continue;

        l = 1 << curr;

        if (length < l || width < l || height < l) continue;
        else break;
    }

    if (curr < 0) return -1;
    --cubes[curr];

    int count1{ solve(length - l, width, height, cubes) };
    int count2{ solve(l, width - l, height, cubes) };
    int count3{ solve(l, l, height - l, cubes) };

    if (count1 == -1 || count2 == -1 || count3 == -1)
        return -1;

    return count1 + count2 + count3 + 1;
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int length, width, height;
    std::cin >> length >> width >> height;

    int N;
    std::cin >> N;

    std::vector<int> cubes(N);

    for (auto& cube : cubes)
    {
        int num;
        std::cin >> num;

        std::cin >> cube;
    }

    std::cout << solve(length, width, height, cubes);

    return 0;
}