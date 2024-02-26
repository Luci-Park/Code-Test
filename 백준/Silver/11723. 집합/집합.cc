
#include <iostream>

#include <string>

using namespace std;







int main()

{

ios_base :: sync_with_stdio(false);

cin.tie(NULL);

cout.tie(NULL);

bool set[21] = { false, };

int M; cin >> M;

while (M--) {

string cmm; cin >> cmm;

if (cmm == "add") {

int i; cin >> i;

set[i] = true;

}

else if (cmm == "remove") {

int i; cin >> i;

set[i] = false;

}

else if (cmm == "check") {

int i; cin >> i;

cout << set[i] << "\n";

}

else if (cmm == "toggle") {

int i; cin >> i;

set[i] = !set[i];

}

else if (cmm == "all") {

for (int i = 1; i <= 20; ++i) set[i] = true;

}

else if(cmm == "empty"){

for (int i = 1; i <= 20; ++i) set[i] = false;

}

}





return 0;

}



