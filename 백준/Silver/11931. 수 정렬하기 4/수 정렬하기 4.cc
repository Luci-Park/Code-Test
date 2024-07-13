#include <iostream>
using namespace std;
int temp[1000000];
void merge(int* arr, int l1, int r1, int l2, int r2)
{
	int st = l1;
	int idx = 0;
	while (l1 < r1 && l2 < r2)
	{
		if (arr[l1] >= arr[l2]) temp[idx++] = arr[l1++];
		else temp[idx++] = arr[l2++];
	}
	while (l1 < r1)
		temp[idx++] = arr[l1++];
	while (l2 < r2)
		temp[idx++] = arr[l2++];
	for (int i = 0; i < idx; i++)
		arr[st + i] = temp[i];
}

void mergesort(int* arr, int l, int r)
{
	if (r - l <= 1) return;
	int mid = (l + r) / 2;
	mergesort(arr, l, mid);
	mergesort(arr, mid, r);
	merge(arr, l, mid, mid, r);
}
int arr[1000000];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int N; 
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> arr[i];

	mergesort(arr, 0, N);
	for (int i = 0; i < N; i++)
		cout << arr[i] << "\n";


    return 0;
}