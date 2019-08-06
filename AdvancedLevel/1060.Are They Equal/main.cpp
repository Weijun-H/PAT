#include <iostream>
#include <string>
using namespace std;
int n =0;
string deal(string s, int& e){
    int k =0;
    while (s.length()>0 && s[0] == '0'){
        s.erase(s.begin());         //去掉s的前导零
    }
    if(s[0]=='.'){                  //前导零去掉后是小数点，说明s是小于1的小数
        s.erase(s.begin());         //去掉小数点
        while (s.length()>0 && s[0] == '0'){//去掉小数字点后非零位的所有零
            s.erase(s.begin());
            e--;                            //每去掉一个零，指数e减1
        }
    } else{                                //去掉前导零后不是小数点，说明》1
        while (k<s.length() && s[k] != '.'){
            k++;
            e++;
        }
        if (k < s.length()){                //找到小数点
            s.erase(s.begin()+k);
        }
    }
    if (s.length()==0){
        e=0;
    }
    int num = 0;
    k = 0;
    string res;
    while (num<n){
        if(k<s.length())res += s[k++];
        else res += '0';
        num++;
    }
    return  res;
}
int main() {
    string s1,s2,s3,s4;
    cin>>n>>s1>>s2;
    int e1=0, e2=0;
    s3 = deal(s1,e1);
    s4 = deal(s2, e2);
    if (s3==s4 && e1==e2){
        cout<<"YES 0."<<s3<<"*10^"<<e1<<endl;
    }else cout<<"NO 0."<<s3<<"*10^"<<e1<<" 0."<<s4<<"*10^"<<e2<<endl;
}