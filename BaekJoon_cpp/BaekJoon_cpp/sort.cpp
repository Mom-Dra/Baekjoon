//
//
//int main()
//{
//    int N, M;
//
//     ��Ʈ�ι̳�� �ݵ�� �� ���簢���� ��Ȯ�� �ϳ��� ĭ�� �����ϵ��� ���ƾ� �ϸ�,
//     ȸ���̳� ��Ī�� ���ѵ� �ȴ�
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