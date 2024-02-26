using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    public static void Main(string[] args)
    {
        int N = int.Parse(Console.ReadLine());
        List<string> words = new List<string>();
        while(N-- > 0)
        {
            words.Add(Console.ReadLine());
        }
        words = words.Distinct().ToList();
        words = words.OrderBy(x => x.Length).ThenBy(x => x).ToList();
        foreach(var w in words)
        {
            Console.WriteLine(w);
        }
    }

}