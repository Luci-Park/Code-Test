using System;
using System.Collections.Generic;

public class HelloWorld
{
    public static void Main(string[] args)
    {
        string[] s = Console.ReadLine().Split();
        int N = int.Parse(s[0]);
        int K = int.Parse(s[1]);
        string ans = "<";
        Queue<int> q = new Queue<int>();
        for(int i = 1; i <= N; ++i)
            q.Enqueue(i);
        while(q.Count > 0)
        {
            for(int j = 0; j < K - 1; ++j)
            {
                q.Enqueue(q.Dequeue());
            }
            ans += q.Dequeue().ToString() + ", ";
        }
        ans = ans.Remove(ans.Length - 2);
        ans += ">";
        Console.WriteLine(ans);
        
        
    }
}