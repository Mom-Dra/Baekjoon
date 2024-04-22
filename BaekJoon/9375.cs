using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _9375 : Solution
    {
        public override void Solve()
        {
            int T;
            string readLine = Console.ReadLine();

            T = int.Parse(readLine);

            for(int i = 0; i < T; i++)
            {
                int n;
                string line = Console.ReadLine();
                n = int.Parse(line);

                int count = 1;

                Dictionary<string, int> dic = new Dictionary<string, int>();

                for (int j = 0; j < n; j++)
                {
                    string closetline = Console.ReadLine();
                    string[] splited = closetline.Split();

                    if (dic.ContainsKey(splited[1]))
                    {
                        dic[splited[1]]++;
                    }
                    else
                    {
                        dic.Add(splited[1], 1);
                    }
                }

                foreach(int k in dic.Values)
                {                    
                    count *= (k + 1);
                }

                Console.WriteLine(count - 1);
            }
        }
    }
}
