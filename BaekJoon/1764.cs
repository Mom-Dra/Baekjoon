using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _1764 : Solution
    {
        public override void Solve()
        {
            List<string> answerList = new List<string>();

            int N, M;

            string readLine = Console.ReadLine();

            string[] parsedLine = readLine.Split(' ');

            N = int.Parse(parsedLine[0]);
            M = int.Parse(parsedLine[1]);

            HashSet<string> duplicated = new HashSet<string>();

            for (int i = 0; i < N; ++i)
            {
                string line = Console.ReadLine();

                duplicated.Add(line);
            }

            for (int j = 0; j < M; ++j)
            {
                string line = Console.ReadLine();

                if (duplicated.Contains(line))
                { 
                    answerList.Add(line);
                }
            }

            answerList.Sort();
            Console.WriteLine(answerList.Count);
            foreach (string line in answerList)
            {
                Console.WriteLine($"{line}");
            }
        }
    }
}
