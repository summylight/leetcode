#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<vector<int>> a(10000,vector<int>(10000));
    for(int i=0;i!=10000;i++){
        a[i][i]=i;
    }
    return 0;
}