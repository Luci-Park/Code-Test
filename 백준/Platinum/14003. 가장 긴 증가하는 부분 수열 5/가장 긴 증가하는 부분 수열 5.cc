#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> numbers;
vector<int> lis;
vector<int> idxs;
int idxReturn(int key)
{
    int s = 0, e = lis.size() - 1;
    int idx = 0;
    while (s <= e)
    {
        int mid = (s + e) * 0.5;
        if (lis[mid] < key)
        {
            s = mid + 1;
        }
        else if (lis[mid] > key)
        {
            idx = mid;
            e = mid - 1;
        }
        else
            return mid;
    }
    return idx;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n; cin >> n;
    idxs.resize(n);
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        numbers.push_back(a);
    }
    for (int i = 0; i < n; i++)
    {
        int idx;
        if (lis.size() == 0 || numbers[i] > lis.back())
        {
            lis.push_back(numbers[i]);
            idx = lis.size() - 1;
        }
        else
        {
            idx = idxReturn(numbers[i]);
            lis[idx] = numbers[i];
        }
        idxs[i] = idx;
    }
    int idx = lis.size() - 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (idxs[i] == idx)
        {
            lis[idx--] = numbers[i];
        }
    }
    cout << lis.size() << "\n";
    for (int i = 0; i < lis.size(); i++)
        cout << lis[i] << " ";
    return 0;
}