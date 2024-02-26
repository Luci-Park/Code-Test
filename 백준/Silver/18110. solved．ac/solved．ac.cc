#include <iostream>
#include <cmath>

using namespace std;
int main()
{
    int n;
    cin >> n;
    if(n == 0) 
    {
        cout << 0;
        return 0;
    }
    

    int levels[31] = {0,};
    for(int i =0; i < n; ++i)
    {
        int level;
        cin >> level;
        levels[level]++;
    }
    
    int num = floor(n * 0.15f + 0.5f);
    n -= num * 2;
    
    for(int i = num, index = 1; i > 0; )
    {
        if(levels[index] >= i)
        {
            levels[index]-= i;
            i = 0;
        }
        else
        {
            i -= levels[index];
            levels[index] = 0;
        }
        index++;
    }

    for(int i = num, index = 30; i > 0; )
    {
        if(levels[index] >= i)
        {
            levels[index]-= i;
            i = 0;
        }
        else
        {
            i -= levels[index];
            levels[index] = 0;
        }
        index--;
    }
    int sum = 0;
    for(int i =1; i < 31; i++)
    {
        sum += levels[i] * i;
    }
    int answer =  floor(sum / (float)n + 0.5);
    cout << answer;
    return 0;
}