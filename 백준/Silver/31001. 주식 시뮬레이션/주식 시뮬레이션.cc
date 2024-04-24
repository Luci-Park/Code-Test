#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;
vector<vector<string>> groups(101);
unordered_map<string, long> companyPrice;
unordered_map<string, int> companyNum;
long long M;

void Buy()
{
	string A; int B; cin >> A >> B;
	
	long long cost = companyPrice[A] * B;
	if (cost > M) return;
	M -= cost;
	companyNum[A] += B;
}

void Sell()
{
	string A; int B; cin >> A >> B;

	int sum = min(companyNum[A], B);
	M += sum * companyPrice[A];
	companyNum[A] -= sum;
}

void PriceUpdate()
{
	string A; int C; cin >> A >> C;

	companyPrice[A] += C;
}

void GroupUpdate()
{
	int D, C; cin >> D >> C;

	for (int i = 0; i < groups[D].size(); i++)
		companyPrice[groups[D][i]] += C;
}

void GroupPercentUpdate()
{
	int D, E; cin >> D >> E;

	for (int i = 0; i < groups[D].size(); i++)
	{
		companyPrice[groups[D][i]] += companyPrice[groups[D][i]] * E * 0.01;
		companyPrice[groups[D][i]] -= companyPrice[groups[D][i]]% 10;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, Q;

	cin >> N >> M >> Q;
	while (N--)
	{
		int G; string H; long P;
		cin >> G >> H >> P;
		groups[G].push_back(H);
		companyPrice.insert({ H, P });
		companyNum.insert({ H, 0 });
	}

	while (Q--)
	{
		int num; cin >> num;

		if (1 == num) Buy();
		if (2 == num) Sell();
		if (3 == num) PriceUpdate();
		if (4 == num) GroupUpdate();
		if (5 == num) GroupPercentUpdate();
		if (6 == num) cout << M << "\n";
		if (7 == num)
		{
			long long m = M;
			for (auto iter = companyNum.begin(); iter != companyNum.end(); iter++)
				m += companyPrice[iter->first] * iter->second;
			cout << m << "\n";
		}
	}


	return 0;
}