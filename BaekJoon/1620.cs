using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _1620 : Solution
    {
        public override void Solve()
        {
            int N, M;

            string readLine = Console.ReadLine();
            string[] splited = readLine.Split();

            N = int.Parse(splited[0]);
            M = int.Parse(splited[1]);

            Dictionary<int, string> dic = new Dictionary<int, string>();
            Dictionary<string, int> dic2 = new Dictionary<string, int>();

            for(int i = 1; i <= N; ++i)
            {
                string line = Console.ReadLine();
                dic.Add(i, line);
                dic2.Add(line, i);
            }

            StringBuilder stringBuilder = new StringBuilder();

            for(int i = 0; i < M; ++i)
            {
                string line = Console.ReadLine();

                if(int.TryParse(line, out int num))
                {
                    stringBuilder.AppendLine(dic[num]);
                }
                else
                {
                    stringBuilder.AppendLine(dic2[line].ToString());
                }
            }

            Console.WriteLine(stringBuilder.ToString());
        }
    }
}
