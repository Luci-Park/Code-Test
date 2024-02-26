using System;
using System.Collections.Generic;
using System.Linq;

public class Program
{
    static int[] parent;
    static bool[] knows;
    static int Find(int node)
    {
        if (parent[node] == node) return node;
        return Find(parent[node]);
    }
    static void Union(int a, int b)
    {
        a = Find(a);
        b = Find(b);
        if (knows[a])
        {
            parent[b] = a;
        }
        else
        {
            parent[a] = b;
        }
    }

    public static void Main(string[] args)
    {
        int[] input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        int N = input[0], M = input[1];
        parent = new int[N + 1];
        knows = new bool[N + 1];
        int[] parties = new int[M];
        for (int i = 1; i <= N; ++i) parent[i] = i;
        List<int>[] guests = new List<int>[M];
        input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
        for (int i = 1; i <= input[0]; ++i) knows[input[i]] = true;
        for(int i = 0; i < M; ++i)
        {
            input = Array.ConvertAll(Console.ReadLine().Split(' '), int.Parse);
            for(int j = 2; j <= input[0]; ++j)
            {
                Union(input[j], input[1]);
            }
            parties[i] = input[1];
        }
        int cnt = 0;
        for(int i = 0; i < M; ++i)
        {
            if (!knows[Find(parties[i])]) ++cnt;
        }
        Console.WriteLine(cnt);
    }
}
