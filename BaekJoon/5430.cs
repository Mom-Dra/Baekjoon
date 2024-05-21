using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Text.Json.Serialization;
using System.Threading.Tasks;

namespace BaekJoon
{
    public class _5430 : Solution
    {
        public override void Solve()
        {
            int T;

            T = int.Parse(Console.ReadLine());

            for(int i = 0 ; i < T; ++i)
            {
                string testLine = Console.ReadLine();
                int length = int.Parse(Console.ReadLine());
                List<int> list = new List<int>(length);

                string arrLine = Console.ReadLine();

                bool isReverse = default;
                
                if(length != 0)
                {
                    string trimed = arrLine.Trim('[', ']');

                    list.AddRange(trimed.Split(',').Select(x => int.Parse(x)));
                }

                try
                {
                    foreach (char c in testLine)
                    {
                        switch (c)
                        {
                            case 'R':
                                isReverse = !isReverse;
                                //Console.WriteLine("After Reverse");
                                //PrintArr(arr);
                                break;
                            case 'D':
                                Delete(list, isReverse);
                                break;
                        }
                    }
                }
                catch
                {
                    Console.WriteLine("error");
                    continue;
                }

                PrintArr(list, isReverse);
            }
        }

        private void Delete(List<int> list, bool isReverse)
        {
            //Console.WriteLine("Delete!");
            if (list.Count == 0) throw new Exception();

            if (isReverse)
            {
                list.RemoveAt(list.Count - 1);
            }
            else
            {
                list.RemoveAt(0);
            }
        }

        private void PrintArr(List<int> list, bool isReverse)
        {
            //Console.WriteLine("PrintArr!!");

            if (isReverse)
            {
                list.Reverse();
            }

            string formatted = $"[{string.Join(',', list)}]";
            Console.WriteLine(formatted);
        }
    }
}

// How To Solve!!
// Gong Boo Ha Ja!

// ReverseMode인지 아닌지!