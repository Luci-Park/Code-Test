# include <iostream>
# include <vector>
# include <set>
# include <string>
using namespace std;



int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    set<string> input;
    set<string> output;
    while(N--){
        string s; cin >> s;
        input.insert(s);
    }
    while(M--){
        string s; cin >> s;
        if(input.find(s) != input.end()){
            output.insert(s);
        }
    }
    cout << output.size() << "\n";
    for(string s:output){
        cout << s << "\n";
    }
    return 0;
}