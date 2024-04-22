using System;
using System.Collections.Generic;
using System.Linq;
using System.Net.NetworkInformation;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _11659 : Solution
    {
        public override void Solve()
        {
            int N, M;

            string readLine = Console.ReadLine();
            string[] splited = readLine.Split();

            N = int.Parse(splited[0]);
            M = int.Parse(splited[1]);

            int[] arr = new int[N + 1];

            string numLine = Console.ReadLine();
            string[] numLineSplited = numLine.Split();

            for (int i = 1; i <= N; ++i)
            {
                arr[i] = int.Parse(numLineSplited[i - 1]) + arr[i - 1];
            }

            StringBuilder sb = new StringBuilder();

            for(int k = 0; k < M; ++k)
            {
                int i, j;
                string line = Console.ReadLine();
                string[] lineSplited = line.Split();

                i = int.Parse(lineSplited[0]);
                j = int.Parse(lineSplited[1]);

                sb.AppendLine((arr[j] - arr[i - 1]).ToString());
            }

            Console.WriteLine(sb.ToString());
        }
    }
}
