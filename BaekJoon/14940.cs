using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Numerics;
using System.Reflection.Metadata.Ecma335;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _14940 : Solution
    {
        public override void Solve()
        {
            int n, m;

            int[] arr = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

            n = arr[0];
            m = arr[1];

            int[,] graph = new int[n, m];

            int targetX = default;
            int targetY = default;

            for(int i = 0; i < n; ++i)
            {
                string readLine = Console.ReadLine();
                int[] tmp = readLine.Split(' ').Select(x => int.Parse(x)).ToArray();

                for(int j = 0; j < m; ++j)
                {
                    if (tmp[j] == 2)
                    {
                        targetY = i;
                        targetX = j;
                    }

                    graph[i, j] = tmp[j];
                }
            }

            int[,] answer = new int[n, m];

            BFS(graph, answer, targetX, targetY);

            StringBuilder sb = new StringBuilder();
            
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < m; ++j)
                {
                    sb.Append($"{answer[i, j]} ");
                }

                sb.Append('\n');
            }

            Console.Write(sb.ToString());
        }

        private void BFS(int[,] graph, int[,] answer, int targetX, int targetY)
        {
            int n = graph.GetLength(0); // y
            int m = graph.GetLength(1); // x

            answer[targetY, targetX] = 0;

            bool[,] visited = new bool[n, m];

            Queue<((int, int), int)> q = new Queue<((int, int), int)>();
            q.Enqueue(((targetX, targetY), 0));
            visited[targetY, targetX] = true;

            // 상 하 좌 우
            int[] dx = new int[] { 0, 0, -1, 1 };
            int[] dy = new int[] { -1, 1, 0, 0 };

            while(q.Count > 0)
            {
                ((int x, int y), int count) = q.Dequeue();
                answer[y, x] = count;

                for(int i = 0; i < 4; ++i)
                {
                    int nx = x + dx[i];
                    int ny = y + dy[i];

                    if (nx >= 0 && nx < m && ny >= 0 && ny < n)
                    {
                        if (!visited[ny, nx] && graph[ny, nx] == 1)
                        {
                            q.Enqueue(((nx, ny), count + 1));
                            visited[ny, nx] = true;
                        }
                    }
                }
            }

            // 길이 막혀서 탐색이 되지 않은 곳은 -1로 바꿔주자
            for(int i = 0; i < n; ++i)
            {
                for(int j = 0; j < m; ++j)
                {
                    if (!visited[i, j] && graph[i, j] == 1) answer[i, j] = -1;
                }
            }
        }


        // 2가 있는 위치에서
        // 상하 좌우로 퍼져 나간다
        // 1이면 count를 증가시키면서 숫자를 키운다
        // 이미 방문한 것이라면 저장된 것과 새로 탐색한 count를 비교해 더 작은 값으로 수정한다?

        // 비 효율적인 코드가 될 것이다
        //private int BFS(int[,] graph, int x, int y)
        //{
        //    Queue<((int, int), int)> queue = new Queue<((int, int), int)>();
        //    int[,] visited = new int[graph.GetLength(0), graph.GetLength(1)];

        //    queue.Enqueue(((x, y), 0));

        //    while(queue.Count > 0)
        //    {
        //        ((int a, int b), int count) = queue.Dequeue();
        //        visited[a, b] = count;

        //        int nextCount = count + 1;
        //    }
        //}
    }
}
