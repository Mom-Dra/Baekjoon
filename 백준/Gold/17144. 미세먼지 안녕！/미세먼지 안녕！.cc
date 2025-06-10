#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
#include <queue>
#include <numeric>
#include <unordered_map>
#include <set>

void spread(std::vector<std::vector<int>>& arr, const std::pair<int, int>& a1, const std::pair<int, int>& a2)
{
    static std::array<std::pair<int, int>, 4> dn{ {{-1, 0}, {1, 0}, {0, -1}, {0, 1}} };
    std::vector<std::vector<int>> temp(arr.size(), std::vector<int>(arr[0].size(), 0));

    temp[a1.first][a1.second] = -1;
    temp[a2.first][a2.second] = -1;

    for (int i{ 0 }; i < arr.size(); ++i)
    {
        for (int j{ 0 }; j < arr[0].size(); ++j)
        {
            if (arr[i][j] == -1) continue;

            int spreadVal{ arr[i][j] / 5 };
            int spreadCount{ 0 };

            for (const auto& [dr, dc] : dn)
            {
                int nr{ i + dr };
                int nc{ j + dc };

                if (nr >= 0 && nr < arr.size() && nc >= 0 && nc < arr[0].size())
                {
                    if (temp[nr][nc] != -1)
                    {
                        temp[nr][nc] += spreadVal;
                        ++spreadCount;
                    }
                }
            }

            temp[i][j] += (arr[i][j] - spreadVal * spreadCount);
        }
    }

    arr = temp;
}

void cleanAir(std::vector<std::vector<int>>& arr, const std::pair<int, int>& a1, const std::pair<int, int>& a2)
{
    for (int i{ a1.first - 1 }; i > 0; --i)
    {
        arr[i][0] = arr[i - 1][0];
    }

    for (int i{ 0 }; i < arr[0].size() - 1; ++i)
    {
        arr[0][i] = arr[0][i + 1];
    }

    for (int i{ 0 }; i < a1.first; ++i)
    {
        arr[i][arr[0].size() - 1] = arr[i + 1][arr[0].size() - 1];
    }

    for (int i = arr[0].size() - 1; i >= 2; --i)
    {
        arr[a1.first][i] = arr[a1.first][i - 1];
    }

    arr[a1.first][1] = 0;


    for (int i{ a2.first + 1 }; i < arr.size() - 1; ++i)
    {
        arr[i][0] = arr[i + 1][0];
    }

    for (int i{ 0 }; i < arr[0].size() - 1; ++i)
    {
        arr[arr.size() - 1][i] = arr[arr.size() - 1][i + 1];
    }

    for (int i = arr.size() - 1; i > a2.first; --i)
    {
        arr[i][arr[0].size() - 1] = arr[i - 1][arr[0].size() - 1];
    }

    for (int i = arr[0].size() - 1; i >= 2; --i)
    {
        arr[a2.first][i] = arr[a2.first][i - 1];
    }

    arr[a2.first][1] = 0;
}

int getDustCount(const std::vector<std::vector<int>>& arr)
{
    int count{ 0 };

    for (const auto& vec : arr)
    {
        for (const auto& num : vec)
        {
            if (num != -1) count += num;
        }
    }

    return count;
}

void printVector(const std::vector<std::vector<int>>& arr)
{
    for (const auto& vec : arr)
    {
        for (const auto& num : vec)
        {
            std::cout << num << ' ';
        }

        std::cout << '\n';
    }
    
    std::cout << '\n';
}

int main()
{
    int R, C, T;
    std::cin >> R >> C >> T;

    std::vector<std::vector<int>> arr(R, std::vector<int>(C, 0));

    std::pair<int, int> a1;
    std::pair<int, int> a2;
    bool isSecond{ false };

    for (int i{ 0 }; i < R; ++i)
    {
        for (int j{ 0 }; j < C; ++j)
        {
            std::cin >> arr[i][j];

            if (arr[i][j] == -1 && !isSecond)
            {
                a1.first = i;
                a1.second = j;
                isSecond = true;
            }
            else if (arr[i][j] == -1 && isSecond)
            {
                a2.first = i;
                a2.second = j;
            }
        }
    }

    for (int i{ 0 }; i < T; ++i)
    {
        spread(arr, a1, a2);
        cleanAir(arr, a1, a2);
    }

    std::cout << getDustCount(arr);
}