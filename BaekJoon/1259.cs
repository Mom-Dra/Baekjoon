using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _1259 : Solution
    {
        public override void Solve()
        {
            while(true)
            {
                string readLine = Console.ReadLine();
                
                int num = int.Parse(readLine);

                if (num == 0)
                {
                    break;
                }

                int front = 0;
                int back = readLine.Length - 1;
                bool isFalind = false;

                while (front < back)
                {
                    if (readLine[front] != readLine[back])
                    {
                        isFalind = true;
                        break;
                    }

                    front++;
                    back--;
                }

                Console.WriteLine(isFalind ? "no" : "yes");
            }
        }


    }
}
