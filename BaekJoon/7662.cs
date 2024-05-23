using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _7662 : Solution
    {
        private class DualPriorityQueue
        {
            private PriorityQueue<int, int> pq;

        }

        public override void Solve()
        {
            // 우선순위가 가장 높은 것

            int T = int.Parse(Console.ReadLine());

            for (int i = 0; i < T; ++i)
            {
                int opCnt = int.Parse(Console.ReadLine());

                for(int j = 0; j < opCnt; ++j)
                {
                    string op = Console.ReadLine();
                }
            }

            // minHeqp이군
            // 우선순위가 낮은게 먼저 나온다!
            PriorityQueue<int, int> pq = new PriorityQueue<int, int>();

            pq.Enqueue(3, 4);

            // D 1 -> 우선순위가 가장 높은 것 제거
            // D -1 -> 우선순위가 가장 낮은 것 제거

            Console.WriteLine($"Count: {pq.Count}");

            int count = pq.Count;
            for (int i = 0; i < count; ++i)
            {
                Console.WriteLine(pq.Dequeue());
            }
        }
    }
}
