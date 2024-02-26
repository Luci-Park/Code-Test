# include <iostream>
# include <string>
# include <queue>
using namespace std;

struct Person{
  int age;
  string name;
  int order;
    Person(int age, string name, int order): age(age), name(name), order(order){}
};

struct compare{
  bool operator()(Person const& a, Person const& b){
    if(a.age != b.age) return a.age > b.age;
    return a.order > b.order;
  }
};

int main ()
{ 
  int N;
  priority_queue<Person, vector<Person>, compare> q;
  scanf("%d", &N);
  for(int i = 1; i<= N; i++){
    int age; string name;
    cin >> age >> name;
    q.push(Person(age, name, i));
  }
  while(!q.empty()){
    cout << q.top().age <<" " << q.top().name << "\n"; q.pop();
  }
  return 0;
}