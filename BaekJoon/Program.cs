

using BaekJoon;

int Sum(int[] arr)
{
    int sum = 0;

    foreach (int i in arr)
    {
        sum += i;
    }

    return sum;
}

int GetMajority(int[] arr)
{
    int majority = 0;
    int max = -1;

    bool repeated = false;

    int[] tmp = new int[8001];

    foreach (int i in arr)
    {
        ++tmp[i + 4000];

        if (tmp[i + 4000] > max)
        {
            max = tmp[i + 4000];
            majority = i;
            repeated = false;
        }
        else if (tmp[i + 4000] == max)
        {
            repeated = true;
        }
    }

    if (repeated)
    {
        bool trigger = false;
        for (int i = 0; i < 8001; ++i)
        {
            if (tmp[i] == max)
            {
                if (trigger) return i - 4000;
                trigger = true;
            }
        }
        // 1000  , 2000
    }

    return majority;
}




//int N = int.Parse(Console.ReadLine());

//int[] arr = new int[N];

//for (int i = 0; i < N; ++i)
//{
//    arr[i] = int.Parse(Console.ReadLine());
//}

//int mean = (int)Math.Round(Sum(arr) / (double)N);


//Array.Sort(arr);
//int middle = arr[N / 2];

//int majority = GetMajority(arr);

//int diff = N > 1 ? arr[N - 1] - arr[0] : 0;


//Console.WriteLine(mean);
//Console.WriteLine(middle);
//Console.WriteLine(majority);
//Console.WriteLine(diff);




Solution sol = new _10026();
sol.Solve();