#include <iostream>
#include <list>
using namespace std;
int n;
int selection[100001];
bool visited[100001];
list<int> lst;
bool isTeam(int s1, int i)
{
	lst.push_back(i);
	if (s1 == selection[i])
	{
		visited[i] = true;
		return true;
	}
	if (visited[i]) return false;
	visited[i] = true;
	if (isTeam(s1, selection[i])) return true;
	return false;
}

int solution()
{
	cin >> n;
	int answer = 0;
	for (int i = 1; i <= n; i++)
	{
		cin >> selection[i];
		visited[i] = false;
	}
	for (int i = 1; i <= n; i++)
	{
		if (visited[i]) continue;
		if (!isTeam(i, i))
		{
			bool flag = false;
			for (auto iter = lst.begin(); iter != lst.end(); iter++)
			{
				if (!flag && *iter == lst.back()) flag = true;
				if (!flag)answer += 1;
			}
		}
		lst.clear();
	}
	return answer;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cout << solution() <<"\n";
	}
	return 0;
}