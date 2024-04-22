using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _10989 : Solution
    {
        public override void Solve()
        {
            int n;

            int[] arr = new int[10001];

            StringBuilder sb = new StringBuilder();

            n = int.Parse(Console.ReadLine());

            for(int i = 0; i < n; ++i)
            {
                string line = Console.ReadLine();
                int number = int.Parse(line);

                ++arr[number];
            }

            for(int i = 1; i< arr.Length; ++i)
            {
                if (arr[i] > 0)
                {
                    for(int j = 0; j < arr[i]; ++j)
                    {
                        sb.AppendLine(i.ToString());
                    }

                    Console.Write(sb);
                    sb.Clear();
                }
            }
        }
    }
}
