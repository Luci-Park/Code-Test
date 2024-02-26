using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    public static int LowerBound(int[] arr, int key)
    {
        int lo = 0, hi = arr.Length- 1;
        while(lo < hi) {
            int mid = (lo + hi)/2;
            if (arr[mid] < key)
            {
                lo = mid + 1;
            }
            else
            {
                hi = mid - 1;
            }
        }
        if (arr[lo] < key) lo++;
        return lo;
    }
    public static void Main(string[] args)
    {
        const int max = 10001;
        int N = int.Parse(Console.ReadLine());
        int[] numbers = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        int[] temp = new int[N];
        for (int i = 0; i < temp.Length; i++) temp[i] = max;
        for(int i = 0; i < numbers.Length; i++)
        {
            temp[LowerBound(temp, numbers[i])] = numbers[i];
        }
        Console.WriteLine(LowerBound(temp, max - 1));
    }

}
