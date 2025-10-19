#include <bits/stdc++.h>

struct node{
    int value;
    list<node*> subordinates;
};

class Tree{
    std::vector<pair<int,node>> edges;
    std::unordered_map<int,int> subordinates;

    public:

    void insertEdge(int a, int b){
        
    }

    void build(){
        
    }
};

int main() {
  int n;
  std::cin >> n;
  std::vector<int> v(n - 1, 0);

  for (int &i : v){
    std::cin >> i;
  }

  
}