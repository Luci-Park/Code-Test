# include <iostream>
# include <string>
# include <queue>
using namespace std;

struct Point{
  int x;
  int y;
    Point(int x, int y): x(x), y(y){}
};

struct compare{
  bool operator()(Point const& a, Point const& b){
    if(a.y != b.y) return a.y > b.y;
    return a.x > b.x;
  }
};

int main ()
{ 
  int N;
  priority_queue<Point, vector<Point>, compare> q;
  scanf("%d", &N);
  for(int i = 1; i<= N; i++){
    int x, y;
    cin >> x >> y;
    q.push(Point(x, y));
  }
  while(!q.empty()){
    cout << q.top().x <<" " << q.top().y << "\n"; q.pop();
  }
  return 0;
}