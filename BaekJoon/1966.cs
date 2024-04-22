using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace BaekJoon
{
    public struct Data
    {
        public int value;
        public bool target;
    }

    public class _1966 : Solution
    {
        private Queue<Data> queue = new Queue<Data>();

        public override void Solve()
        {
            int n = int.Parse(Console.ReadLine());

            Console.WriteLine($"n: {n}");

            for(int i = 0; i < n; i++)
            {
                string[] line = Console.ReadLine().Split(' ');

                int count = int.Parse(line[0]);
                int what = int.Parse(line[1]);

                Console.WriteLine($"count: {count}");
                Console.WriteLine($"what: {what}");

                string[] line2 = Console.ReadLine().Split(' ');

                for(int j = 0; j < count; j++)
                {
                    int value = int.Parse(line2[j]);

                    queue.Enqueue(new Data() { value = value, target = j == what });
                }

                int printCount = 0;
                while (true)
                {
                    int max = -1;

                    foreach(Data data in queue)
                    {
                        max = max < data.value ? data.value : max;
                    }

                    if(max <= queue.First().value)
                    {
                        ++printCount;
                        Data data = queue.Dequeue();
                        if (data.target)
                        {
                            Console.WriteLine(printCount);
                            break;
                        }
                    }
                    else
                    {
                        queue.Enqueue(queue.Dequeue());
                    }
                }

            }
        }
    }
}
