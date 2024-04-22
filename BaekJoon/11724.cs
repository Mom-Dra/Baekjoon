using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _11724 : Solution
    {
        public override void Solve()
        {
            int N, M;

            string readLine = Console.ReadLine();
            string[] splited = readLine.Split();

            N = int.Parse(splited[0]);
            M = int.Parse(splited[1]);

            bool[,] graph = new bool[N + 1, N + 1];

            for(int i = 0; i < M; ++i)
            {
                string line = Console.ReadLine();
                string[] lineSplited = line.Split();

                int u, v;
                
                u = int.Parse(lineSplited[0]);
                v = int.Parse(lineSplited[1]);

                graph[u, v] = true;
                graph[v, u] = true;
            }

            bool[] visited = new bool[N + 1];
            Queue<int> queue = new Queue<int>();

            int count = 0;

            for(int i = 1; i <= N; ++i)
            {
                if (visited[i]) continue;

                queue.Enqueue(i);

                while (queue.Count > 0)
                {
                    int curr = queue.Dequeue();
                    if (visited[curr]) continue;
                    visited[curr] = true;

                    for(int j = 1; j <= N; ++j)
                    {
                        if (!visited[j])
                        {
                            if(graph[curr, j])
                            {
                                queue.Enqueue(j);
                            }
                        }
                    }
                }

                ++count;
            }

            Console.WriteLine(count);
        }
    }
}
