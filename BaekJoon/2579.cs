using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _2579 : Solution
    {
        public override void Solve()
        {
            int n;

            string readLine = Console.ReadLine();

            n = int.Parse(readLine);

            int[] arr = new int[n];
            int[] dp = new int[n + 1];

            for (int i = 0; i < n; ++i)
            {
                string line = Console.ReadLine();
                int k = int.Parse(line);

                arr[i] = k;
            }

            if(n == 1)
            {
                Console.WriteLine(arr[0]);
                return;
            }

            dp[1] = arr[0];
            dp[2] = arr[1] + arr[0];

            for(int i = 3; i <= n; ++i)
            {
                dp[i] = Math.Max(dp[i - 3] + arr[i - 2] + arr[i - 1], dp[i - 2] + arr[i - 1]);
            }

            Console.WriteLine(dp[n]);
        }
    }
}
