using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.Json.Serialization;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _1107 : Solution
    {
        public override void Solve()
        {
            int N = int.Parse(Console.ReadLine());
            int M = int.Parse(Console.ReadLine());

            bool[] broken = new bool[10];

            if(M != 0)
            {
                int[] brokens = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();

                foreach (int i in brokens)
                {
                    broken[i] = true;
                }
            }

            int result = Math.Abs(N - 100);
            
            for(int i = 0; i < 999999; ++i)
            {
                bool isBreak = default;
                string num = i.ToString();

                foreach (char item in num)
                {
                    if (broken[item - '0'])
                    {
                        isBreak = true;
                        break;
                    }
                }

                if (!isBreak)
                {
                    int min = Math.Abs(N - i) + num.Length;
                    result = Math.Min(min, result);
                }
            }

            Console.WriteLine(result);
        }
    }
}
