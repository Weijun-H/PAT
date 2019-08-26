#include <iostream>
#include <string>
using namespace std;
int main() {
    int a,b;
    string c;
    cin>>a>>b;
    c = to_string(a+b);
    int bit=0;
    int size = c.size();
    if(a+b<0)size = c.size()-1;
    for (int i = 0; i < c.size(); ++i) {
        cout<<c[i];
        if(c[i]!='-'&&c[i]!='+')bit++;
        if((size-bit)%3==0&&i!=c.size()-1&&c[i]!='-')cout<<',';
    }
}