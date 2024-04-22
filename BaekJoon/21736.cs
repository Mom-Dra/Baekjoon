using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _21736 : Solution
    {
        public override void Solve()
        {
            int N, M;

            string readLine = Console.ReadLine();
            string[] splited = readLine.Split();

            N = int.Parse(splited[0]);
            M = int.Parse(splited[1]);

            string[,] arr = new string[N, M];

            int a = 0;
            int b = 0;

            for(int i = 0; i < N; ++i)
            {
                string line = Console.ReadLine();

                for(int j = 0; j  < M; ++j)
                {
                    arr[i, j] = line[j].ToString();

                    if (arr[i, j] == "I")
                    {
                        a = i;
                        b = j;
                    }
                }
            }

            bool[,] visited = new bool[N, M];
            int count = 0;

            DFS(arr, visited, a, b, N, M, ref count);

            if(count == 0)
            {
                Console.WriteLine("TT");
            }
            else
            {
                Console.WriteLine(count);
            }
            
        }

        private void DFS(string[,] arr, bool[,] visited, int a, int b, int N, int M, ref int count)
        {
            visited[a, b] = true;

            if (arr[a, b] == "P")
            {
                ++count;
            }

            if(a - 1 >= 0 && !visited[a - 1, b] && arr[a - 1, b] != "X")
            {
                DFS(arr, visited, a - 1, b, N, M, ref count);
            }

            if (a + 1 < N && !visited[a + 1, b] && arr[a + 1, b] != "X")
            {
                DFS(arr, visited, a + 1, b, N, M, ref count);
            }

            if(b - 1 >= 0 && !visited[a, b - 1] && arr[a, b - 1] != "X")
            {   
                DFS(arr, visited, a, b - 1, N, M, ref count);
            }

            if(b + 1 < M && !visited[a, b + 1] && arr[a, b+ 1] != "X")
            {
                DFS(arr, visited, a, b + 1, N, M, ref count);
            }
        }
    }
}
