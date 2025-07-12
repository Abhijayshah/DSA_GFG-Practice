#include <iostream>
#include <vector>
using namespace std;

int main() {
    //declare
    vector<int> v;
    //initialzation
    v.push_back(34);
    // for(int num: v)cout<<num<<" ";
    for(int i = 0 ;i < v.size() ; i++)cout<<v[i]<<" ";
}


