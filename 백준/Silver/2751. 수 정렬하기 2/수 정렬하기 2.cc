
#include <iostream>
#include <queue>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
	cin.tie(0);
	priority_queue<int> pq;
	int n; cin >> n;
	while(n--)
	{
	    int i;
	    cin >> i;
	    pq.push(-i);
	}
	while(!pq.empty())
	{
	    cout << -pq.top() <<"\n";
	    pq.pop();
	}
    return 0;
}
