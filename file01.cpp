#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
string breaktokey(string s,int k){
    char*ptr=strtok((char*)s.c_str()," ");
    k--;
    while(k>0){
        ptr=strtok(NULL," ");
        k--;
    }
    return (string)ptr;
}
int numify(string s){
    int ans=0;
    int p=1;
    for(int i=s.length()-1;i>=0;i--){
        ans+=(s[i]-'0')*p;
        p*=10;
    }
    return ans;
}
bool lexi_compare(pair<string,string> a,pair<string,string> b){
    return a.second < b.second;
}
bool num_compare(pair<string,string> a,pair<string,string> b){
    return numify(a.second)<numify(b.second);
}
int main(){
    int n;
    cin>>n;
    cin.get();
    pair<string,string>s[1000];
    for(int i=0;i<n;i++){
        getline(cin,s[i].first);
    }
    int k;
    string reversal;
    string type;
    cin>>k>>reversal>>type;
    for(int i=0;i<n;i++){
        s[i].second=breaktokey(s[i].first,k);
    }
    if(type=="numeric"){
        sort(s,s+n,num_compare);
    }
    else{
        sort(s,s+n,lexi_compare);
    }
    if(reversal=="true"){
        for(int i=0;i<=n/2;i++){
            swap(s[i],s[n-i-1]);
        }
    }
    for(int i=0;i<n;i++){
        cout<<s[i].first<<endl;
    }
    return 0;
}