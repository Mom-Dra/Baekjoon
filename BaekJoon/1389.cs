using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml;

namespace BaekJoon
{
    public class _1389 : Solution
    {
        public struct Node
        {
            public int index;
            public int length;

            public Node(int index, int length)
            {
                this.index = index;
                this.length = length;
            }
        }

        public override void Solve()
        {
            int N, M;

            string readLine = Console.ReadLine();
            string[] splited = readLine.Split();

            N = int.Parse(splited[0]);
            M = int.Parse(splited[1]);

            bool[,] arr = new bool[N + 1, N + 1];
            int[,] arr2 = new int[N + 1, N + 1];

            for(int i = 1; i <= N; ++i)
            {
                for(int j = 0; j <= N; ++j)
                {
                    arr2[i, j] = i == j ? 0 : 100000;
                }
            }

            int min = int.MaxValue;
            int minIndex = 0;

            for(int i = 0; i < M; ++i)
            {
                int a, b;
                string line = Console.ReadLine();
                string[] lineSplited = line.Split();

                a = int.Parse(lineSplited[0]);
                b = int.Parse(lineSplited[1]);

                arr[a, b] = true;
                arr[b, a] = true;
                arr2[a, b] = 1;
                arr2[b, a] = 1;
            }

            #region hi
            //for (int begin = 1; begin <= N; ++begin)
            //{
            //    int length = int.MaxValue;
            //    int foo = 0;

            //    for (int destination = 1; destination <= N; ++destination)
            //    {
            //        if (begin == destination) continue;
            //        bool[] visited = new bool[N + 1];
            //        Queue<Node> q = new Queue<Node>();
            //        q.Enqueue(new Node(begin, 0));

            //        //while (q.Count != 0)
            //        //{
            //        //    Node currNode = q.Dequeue();
            //        //    visited[currNode.index] = true;

            //        //    if (currNode.index == destination)
            //        //    {
            //        //        length = Math.Min(length, currNode.length);
            //        //    }

            //        //    for (int i = 1; i <= N; ++i)
            //        //    {
            //        //        if (!visited[i] && arr[currNode.index, i])
            //        //            q.Enqueue(new Node(i, currNode.length + 1));
            //        //    }
            //        //}

            //        foo += length;
            //    }

            //    if (foo < min)
            //    {
            //        min = foo;
            //        minIndex = begin;
            //    }
            //}

            #endregion

            // 이건 알고리즘을 알아야 풀 수 있는 문제구나...

            //DebugArr(arr2, N);
            Floyd(arr2, N);
            //DebugArr(arr2, N);

            int min_sum = int.MaxValue;
            int min_index = 0;

            for(int i = 1; i <= N; ++i)
            {
                int sum = 0;

                for(int j = 1; j <= N; ++j)
                {
                    sum += arr2[i, j];
                }

                //Console.WriteLine($"i: {i}, sum: {sum}");

                if (sum < min_sum)
                {
                    min_sum = sum;
                    min_index = i;
                }
            }

            Console.WriteLine(min_index);
        }

        private void Floyd(int[,] arr2, int N)
        {
            // floid-warshall 알고리즘
            for (int k = 1; k <= N; ++k)
            {
                // floid-warshall 알고리즘을 사용해서 우리 한번 해봐요 우리 같이 해봐요 우리는
                for (int i = 1; i <= N; ++i)
                {
                    for (int j = 1; j <= N; ++j)
                    {
                        if (arr2[i, k] + arr2[k, j] < arr2[i, j])
                        {
                            arr2[i, j] = arr2[i, k] + arr2[k, j];
                        }
                    }
                }
            }
        }

        private void DebugArr(int[,] arr, int N )
        {
            Console.WriteLine();
            Console.WriteLine("-------------------------------");

            for (int i = 1; i <= N; ++i)
            {
                for(int j = 1; j <= N; ++j)
                {
                    Console.Write($"{arr[i, j]} ");
                }
                Console.WriteLine();
            }

            Console.WriteLine("-------------------------------");
            Console.WriteLine();
        }
    }
}
