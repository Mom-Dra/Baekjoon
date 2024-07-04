//
//
//int main()
//{
//    int N, M;
//
//     테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며,
//     회전이나 대칭을 시켜도 된다
//
//    std::cin >> N >> M;
//    std::vector<std::vector<int>> arr(N, std::vector<int>());
//    std::vector<std::vector<bool>> visited(N, std::vector<bool>(M, false));
//
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = 0; j < M; ++j)
//        {
//            int tmp;
//            std::cin >> tmp;
//
//            arr[i].push_back(tmp);
//        }
//    }
//
//    for (int i = 0; i < N; ++i)
//    {
//        for (int j = 0; j < M; ++j)
//        {
//            visited[i][j] = true;
//            DFS(arr, visited, j, i, arr[i][j], 1);
//            visited[i][j] = false;
//
//            TShape(arr, j, i, arr[i][j]);
//        }
//    }
//
//    std::cout << answer;
//}