using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _2798 : Solution
    {
        public override void Solve()
        {
            int n, m;

            string readLine = Console.ReadLine();
            string[] splited = readLine.Split();

            n = int.Parse(splited[0]);
            m = int.Parse(splited[1]);

            int[] arr = new int[n];
            bool[] visited = new bool[n];

            string line = Console.ReadLine();
            string[] splited2 = line.Split();

            for(int i = 0; i < splited2.Length; i++)
            {
                arr[i] = int.Parse(splited2[i]);
            }

            int answer = 0;

            for(int i = 0; i < n; ++i)
            {
                for(int j = i + 1; j < n; ++j)
                {
                    for(int k = j + 1; k < n; ++k)
                    {
                        int sum = arr[i] + arr[j] + arr[k];
                        if(sum <= m)
                        {
                            answer = sum > answer ? sum : answer;
                        }
                    }
                }
            }

            Console.WriteLine(answer);
        }
    }
}
