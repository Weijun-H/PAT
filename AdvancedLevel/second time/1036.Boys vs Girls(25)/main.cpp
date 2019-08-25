#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
const int maxn = 100;
struct Male{
    string name;
    char course[15];
    int score;
}male[maxn];
struct Female{
    string name,course;
    int score;
}female[maxn];
bool cmp1(Male a, Male b){
    return a.score<b.score;
}
bool cmp(Female a, Female b){
    return a.score>b.score;
}
int main() {
    int n;
    scanf("%d",&n);
    int male_n=0,female_n=0;
    for (int i = 0; i < n; ++i) {
        char gender;
        string name;
        char course[15];
        int score;
        cin>>name;
        scanf("%*c%c",&gender);
        if(gender=='M'){
            male[male_n].name=name;
            cin>>male[male_n].course;
            scanf("%d",&male[male_n].score);
            male_n++;
        } else{
            female[female_n].name=name;
            cin>>female[female_n].course;
            scanf("%d",&female[female_n].score);
            female_n++;
        }
    }
    if(female_n==0)printf("Absent\n");
    else {
        sort(female,female+female_n,cmp);
        cout<<female[0].name<<" "<<female[0].course<<endl;
    }
    if(male_n==0)printf("Absent\n");
    else {
        sort(male,male+male_n,cmp1);
        cout<<male[0].name<<" "<<male[0].course<<endl;
    }

    if(female_n==0||male_n==0){
        printf("NA");
    }else{
        cout<<abs(male[0].score-female[0].score);
    }

}