using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _4153 : Solution
    {
        public override void Solve()
        {
            int a, b, c;

            while (true)
            {
                string readLine = Console.ReadLine();
                string[] splited = readLine.Split();

                a = int.Parse(splited[0]);
                b = int.Parse(splited[1]);
                c = int.Parse(splited[2]);

                if(a == 0 && b == 0 && c == 0)
                {
                    break;
                }

                int min, middle, max;

                if (a < b)
                {
                    if (c < a)
                    {
                        min = c;
                        middle = a;
                        max = b;
                    }
                    else if (c > b)
                    {
                        min = a;
                        middle = b;
                        max = c;
                    }
                    else
                    {
                        min = a;
                        middle = c;
                        max = b;
                    }
                }
                else
                {
                    if (c < b)
                    {
                        min = c;
                        middle = b;
                        max = a;
                    }
                    else if (c > a)
                    {
                        min = b;
                        middle = a;
                        max = c;
                    }
                    else
                    {
                        min = b;
                        middle = c;
                        max = a;
                    }
                }

                if (min * min + middle * middle == max * max)
                {
                    Console.WriteLine("right");
                }
                else
                {
                    Console.WriteLine("wrong");
                }
            }

            
        }
    }
}
