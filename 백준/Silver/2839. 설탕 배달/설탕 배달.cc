#include <iostream>

using namespace std;

int main()
{
    int kg;
    cin >> kg;
    
    int bag = 0;
    
    while (kg >= 0){
        if(kg % 5 == 0){
            bag += kg / 5;
            cout << bag;
            return 0;
        }
        kg -= 3;
        ++bag;
    }
    cout << -1;
    

    return 0;
}
