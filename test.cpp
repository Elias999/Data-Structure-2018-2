//Binary Search Tree Program

#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

int main() {
  list<int> a;
  a.push_back(1);
  a.push_back(2);
  a.push_back(3);
  for(list<int>::iterator it=a.begin();it !=a.end();it++)
    cout<< " "<<*it<<endl;

    a.reverse();
    for(list<int>::iterator it=a.begin();it !=a.end();it++)
      cout<<" "<<*it<<endl;
  return 0;
}
