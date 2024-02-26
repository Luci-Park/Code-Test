# include <iostream>
# include <vector>
# include <map>
# include <string>
using namespace std;



int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, M;
    cin >> N >> M;
    map<string, int> m;
    vector<string> v;
    for(int i = 1; i<= N; i++){
        string pokemon;
        cin >> pokemon;
        m.insert({pokemon, i});
        v.push_back(pokemon);
    }
    while(M--){
        string pokemon;
        cin >> pokemon;
        if(isdigit(pokemon[0])){
            int n = stoi(pokemon);
            cout << v[n - 1]<<"\n";
        }else{
            cout << m[pokemon] << "\n";
        }
    }
    return 0;
}