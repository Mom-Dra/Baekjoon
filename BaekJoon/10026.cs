using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Linq;

namespace BaekJoon
{
    public class _10026 : Solution
    {
        public override void Solve()
        {
            int N = int.Parse(Console.ReadLine());

            // R - 0
            // G - 1
            // B - 2

            int[,] graph = new int[N, N];

            for(int i = 0; i < N; ++i)
            {
                string readLine = Console.ReadLine();

                for(int j = 0; j < N; ++j)
                {
                    switch (readLine[j])
                    {
                        case 'R':
                            graph[i, j] = 0;
                            break;
                        case 'G':
                            graph[i, j] = 1;
                            break;
                        case 'B':
                            graph[i, j] = 2;
                            break;
                    }
                }
            }

            Console.Write($"{BFS(graph, N, false)} {BFS(graph, N, true)}");

            //PrintGraph(graph);
        }

        private int BFS(int[,] graph, int N, bool colorWeakness)
        {
            Queue<(int, int)> queue = new Queue<(int, int)>();
            bool[,] visited = new bool[N, N];

            int count = default;

            // i축
            int[] dx = new int[] { -1, 1, 0, 0 };

            // j축
            int[] dy = new int[] { 0, 0, -1, 1 };

            for(int i = 0; i < N; ++i)
            {
                for(int j = 0; j < N; ++j)
                {
                    if (visited[i, j]) continue;

                    queue.Enqueue((i, j));
                    visited[i, j] = true;

                    while (queue.Count > 0)
                    {
                        (int a, int b) = queue.Dequeue();

                        for(int k = 0; k < 4; ++k)
                        {
                            int nx = a + dx[k];
                            int ny = b + dy[k];

                            if (nx >= 0 && nx < N && ny >=0 && ny < N)
                            {
                                if (!visited[nx, ny])
                                {
                                    if (colorWeakness)
                                    {
                                        if (graph[i, j] == 2)
                                        { // Blue 일 때
                                            if (graph[nx, ny] == 2)
                                            {
                                                queue.Enqueue((nx, ny));
                                                visited[nx, ny] = true;
                                            }
                                        }
                                        else
                                        {
                                            if (graph[nx, ny] != 2)
                                            {
                                                queue.Enqueue((nx, ny));
                                                visited[nx, ny] = true;
                                            }
                                        }
                                    }
                                    else
                                    {
                                        if (graph[i, j] == graph[nx, ny])
                                        {
                                            queue.Enqueue((nx, ny));
                                            visited[nx, ny] = true;
                                        }
                                    }
                                }
                            }
                        }
                    }
                    ++count;
                }
            }

            return count;
        }

        private void PrintGraph(int[,] graph)
        {
            for(int i = 0; i < graph.GetLength(0); ++i)
            {
                for(int j = 0; j < graph.GetLength(1); ++j)
                {
                    Console.Write(graph[i, j]);
                }

                Console.WriteLine();
            }
        }
    }
}
