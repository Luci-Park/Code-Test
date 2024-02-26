#include <iostream>
#include <string>
using namespace std;


int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string target, explode;
    cin >> target >> explode;
    
    string result = "";
    for(int i = 0; i < target.length(); i++){
        result += target[i];
        if(result[result.length() - 1] == explode[explode.length() - 1]
        && result.length() >= explode.length()){
            int start = result.length() - explode.length();
            string sub = result.substr(start, explode.length());
            if(sub == explode){
                result.erase(result.begin() + start, result.end());
            }
        }
    }
    
    if(result == "")result = "FRULA";
    cout << result;
    
    
    return 0;
}
