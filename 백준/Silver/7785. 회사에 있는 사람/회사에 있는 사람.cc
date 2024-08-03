#include <iostream>
#include <set>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	auto cmp = [](string a, string b) {return a > b; };
	set<string, decltype(cmp)> us(cmp);
	int n; cin >> n;
	while (n--)
	{
		string name, state;
		cin >> name >> state;
		if (state == "enter")
			us.insert(name);
		else
			us.erase(us.find(name));
	}

	for (auto it : us)
		cout << it << "\n";

    return 0;
}