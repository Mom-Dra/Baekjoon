using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _11047 : Solution
    {
        public override void Solve()
        {
            int n;
            int k;

            string readline = Console.ReadLine();
            string[] splited = readline.Split(' ');

            n = int.Parse(splited[0]);
            k = int.Parse(splited[1]);

            int[] values = new int[n];

            for(int i = 0; i < n; ++i)
            {
                string line = Console.ReadLine();
                values[i] = int.Parse(line);
            }

            Array.Sort(values);

            int total = 0;

            for(int i = n - 1; i >= 0; --i)
            {
                if (k == 0) break;
                if (values[i] > k) continue;

                int num = k / values[i];
                total += num;

                k -= values[i] * num;
            }

            Console.WriteLine(total);
        }

        // 
    }
}
