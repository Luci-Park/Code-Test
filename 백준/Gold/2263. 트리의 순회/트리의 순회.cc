#include <iostream>
#include <stack>

using namespace std;
const int SIZE = 1e5;
int inorder[SIZE];
int postorder[SIZE];
int position[SIZE + 1];
stack<int> s;
int postIdx = 0;

void traverse(int start, int end)
{
	if (start > end) return;
	int root = postorder[postIdx--];
	int idx = position[root];
	traverse(idx + 1, end);
	traverse(start, idx - 1);
	s.push(root);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> inorder[i];
		position[inorder[i]] = i;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> postorder[i];
	}
	postIdx = n - 1;
	traverse(0, n - 1);

	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}