#include<iostream>
#include <vector>
#include <unordered_set>
using namespace std;
//my answer: use bit-map and checklist for O(n) complexity
// int longestConsecutive(vector<int>& nums) {
//     vector<vector<int>> pos(8192,vector<int>(8192,0)),neg(8192,vector<int>(8192,0));
//     vector<int> posf(8192),negf(8192);
//     int a,b,c=1;
//     for(auto i:nums){
//         if(i>=0){
//             int ii=i%262144;
//             int iii=i/262144;
//             a=ii/32;
//             b=ii%32;
//             c=c<<b;
//             pos[iii][a]=pos[iii][a]|c;
//             posf[iii]=1;
//         }
//         else{
//             i=-(i+1);
//             int ii=i%262144;
//             int iii=i/262144;
//             a=ii/32;
//             b=ii%32;
//             c=c<<b;
//             neg[iii][a]=neg[iii][a]|c;
//             negf[iii]=1;
//         }
//         c=1;
//     }

//     int max_len=0,flag=0,len=0;
//     for(int i=neg.size()-1;i>=0;i--){
//         if(negf[i]==0){
//             if(len>max_len) max_len=len;
//                     len=0;continue;
//         }
//         for(int k=neg[i].size()-1;k>=0;k--){
//             for(int j =32;j>0;j--){
//                 c=1<<j;
//                 int tmp=neg[i][k];
//                 if(neg[i][k]&c){
//                     len++;
//                 } 
//                 else{
//                     if(len>max_len) max_len=len;
//                     len=0;
//                 }
//             }
//         }
//     }
//     for(int i=0;i<pos.size();i++){
//         if(posf[i]==0){
//             if(len>max_len) max_len=len;
//                     len=0;continue;
//         }
//         for(int k=0;k<pos[i].size();k++){
//             c=1;
//             for(int j =1;j<32;j++){
//                 if(pos[i][k]&c){
//                     len++;
//                 } 
//                 else{
//                     if(len>max_len) max_len=len;
//                     len=0;
//                 }
//                 c=c<<1;
//             }
//         }
//     }
//     if(len>max_len) max_len=len;
//     return max_len;
// }

#define INT_MAX 0x7fffffff
#define INT_MIN 0xffffffff
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> a;
    for(auto i:nums)
        a.insert(i);
    
    int len=0,maxlen=1;
    for(int k=0;k!=nums.size();k++){
        int tmp=nums[k];
        if(tmp==INT_MIN||!a.count(tmp-1)){
            len++;
            if(tmp==INT_MIN) len=1;
            while(tmp<=INT_MAX&&a.count(tmp+1)){
                tmp+=1;
                len++;
            }
        }
        maxlen=max(len,maxlen);
        len=0;
    }
    maxlen=max(len,maxlen);
    return maxlen;
}
int main(){
    vector<int> nums={2147483646,-2147483647,0,2,2147483644,-2147483645,2147483645};
    int len = longestConsecutive(nums);
    cout<<len<<endl;
    return 0;
}