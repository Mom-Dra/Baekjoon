#pragma once
#include "Solution.h"
#include <iostream>
#include <vector>
#include <climits>

class _14500 : public Solution
{
    const int dx[4] = { 0, 0, -1, 1 };
    const int dy[4] = { -1, 1, 0, 0 };

    const int tDx[4][3] = { {-1, 1, 0}, {0, 1, 0}, {0, -1, 1}, {0, -1, 0} };
    const int tDy[4][3] = { {0, 0, 1}, {-1, 0, 1}, {-1, 0, 0}, {-1, 0, 1} };
    
    int answer{ 0 };

    void PrintArr(std::vector<std::vector<int>>& arr)
    {
        for (int i = 0; i < arr.size(); ++i)
        {
            for (int j = 0; j < arr[i].size(); ++j)
            {
                std::cout << arr[i][j] << ' ';
            }

            std::cout << '\n';
        }
    }

    void DFS(std::vector<std::vector<int>>& arr, std::vector<std::vector<bool>>& visited, int x, int y, int sum, int depth)
    {
        if (depth == 4)
        {
            answer = std::max(answer, sum);
            return;
        }

        for (int i = 0; i < 4; ++i)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= arr[0].size() || ny >= arr.size()) continue;

            if (!visited[ny][nx])
            {
                visited[ny][nx] = true;
                DFS(arr, visited, nx, ny, sum + arr[ny][nx], depth + 1);
                visited[ny][nx] = false;
            }
        }
    }

    void TShape(std::vector<std::vector<int>>& arr, int x, int y, int sum)
    {
        for (int i = 0; i < 4; ++i)
        {
            int middleSum = sum;
            bool isOut = false;

            for (int j = 0; j < 3; ++j)
            {
                int nx = x + tDx[i][j];
                int ny = y + tDy[i][j];

                if (nx < 0 || ny < 0 || nx >= arr[0].size() || ny >= arr.size())
                {
                    isOut = true;
                    break;
                }

                middleSum += arr[ny][nx];
            }

            if (!isOut)
            {
                answer = std::max(answer, middleSum);
            }
        }
    }

	void Solve() override
	{
        int N, M;

        // 테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며,
        // 회전이나 대칭을 시켜도 된다

        std::cin >> N >> M;
        std::vector<std::vector<int>> arr(N, std::vector<int>());
        std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                int tmp;
                std::cin >> tmp;

                arr[i].push_back(tmp);
            }
        }

        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < M; ++j)
            {
                visited[i][j] = true;
                DFS(arr, visited, j, i, arr[i][j], 1);
                visited[i][j] = false;

                TShape(arr, j, i, arr[i][j]);
            }
        }

        std::cout << answer;
	}
};