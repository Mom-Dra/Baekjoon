using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _17219 : Solution
    {
        public override void Solve()
        {
            int N;
            int M;

            string readLine = Console.ReadLine();
            string[] parsed = readLine.Split();

            N = int.Parse(parsed[0]);
            M = int.Parse(parsed[1]);

            Dictionary<string, string> dic = new Dictionary<string, string>();

            for(int i = 0; i < N; ++i)
            {
                string line = Console.ReadLine();
                string[] lineParsed = line.Split();

                dic.Add(lineParsed[0], lineParsed[1]);
            }

            for(int i = 0; i < M; ++i)
            {
                string line = Console.ReadLine();
                Console.WriteLine(dic[line]);
            }
        }
    }
}
