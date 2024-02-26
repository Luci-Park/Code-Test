    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>
    #include <limits.h>
    using namespace std;

    int main()
    {
        ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        int N; cin >> N;
        int maxArr[3];
        int minArr[3];
        int temp[3], input[3];
        cin >> maxArr[0] >> maxArr[1] >> maxArr[2];
        minArr[0] = maxArr[0];
        minArr[1] = maxArr[1];
        minArr[2] = maxArr[2];
        for (int i = 1; i < N; ++i) {
            cin >> input[0] >> input[1] >> input[2];
            temp[0] = input[0] + max(maxArr[0], maxArr[1]);
            temp[1] = input[1] + * max_element(maxArr, maxArr + 3);
            temp[2] = input[2] + max(maxArr[1], maxArr[2]);
            maxArr[0] = temp[0]; maxArr[1] = temp[1]; maxArr[2] = temp[2];
            temp[0] = input[0] + min(minArr[0], minArr[1]);
            temp[1] = input[1] + *min_element(minArr, minArr + 3);
            temp[2] = input[2] + min(minArr[1], minArr[2]);
            minArr[0] = temp[0]; minArr[1] = temp[1]; minArr[2] = temp[2];
        }
        cout << *max_element(maxArr, maxArr + 3) << " " << *min_element(minArr, minArr + 3);

        return 0;
    }
