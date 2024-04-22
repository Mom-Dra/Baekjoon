using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.Security;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class Floyd : Solution
    {
        private int number = 4;
        private const int INF = int.MaxValue;
        int[,] a = new int[4, 4] {
                {0, 5, INF, 8},
                {7, 0, 9 , INF},
                {2, INF, 0, 4 },
                {INF, INF, 3, 0 }
            };

        public override void Solve()
        {
            int a;
            int b;
            int c;
        }

        private void FloydWarshall()
        {
            int[,] d = new int[number, number];

            for(int i = 0; i < number; ++i)
            {
                for(int j = 0; j < number; ++j)
                {
                    d[i, j] = a[i, j];
                }
            }

            // k: 거쳐가는 노드
            for(int k = 0; k < number; ++k)
            {
                // i: 출발 노드
                for(int i = 0; i < number; ++i)
                {
                    // j: 도착 노드
                    for(int j = 0; j < number; ++j)
                    {
                        if (d[i,k] + d[k,j] < d[i, j])
                        {
                            d[i, j] = d[i, k] + d[k, j];
                        }
                    }
                }
            }
        }
    }
}
