using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _11723 : Solution
    {
        public override void Solve()
        {
            int num;
            string readLine = Console.ReadLine();

            int bitMask = 0;
            int allMask = 0;

            for(int i = 1; i <= 20; ++i)
            {
                allMask = allMask | (1 << i);
            }

            StringBuilder sb = new StringBuilder();

            num = int.Parse(readLine);

            for(int i = 0; i < num; ++i)
            {
                string line = Console.ReadLine();

                string[] splited = line.Split(' ');
                int x = 0;

                switch(splited[0])
                {
                    case "add":
                        x = int.Parse(splited[1]);
                        bitMask = bitMask | (1 << x);
                        break;
                    case "remove":
                        x = int.Parse(splited[1]);
                        bitMask = bitMask & ~(1 << x);
                        break;
                    case "check":
                        x = int.Parse(splited[1]);
                        bool isContain = ((bitMask >> x) & 1) == 1;
                        if(isContain) sb.AppendLine("1");
                        else sb.AppendLine("0");
                        break;
                    case "toggle":
                        x = int.Parse(splited[1]);
                        bitMask = bitMask ^ (1 << x);
                        break;
                    case "all":
                        bitMask = allMask;
                        break;
                    case "empty":
                        bitMask = 0;
                        break;
                }
            }

            Console.Write(sb);
        }
    }
}
