#include <iostream>
using namespace std;
char radix[3]={'A', 'B', 'C'};
int mars_color[2];
void change(int color){
    mars_color[0]=mars_color[1]=0;
    int index =0;
    while (color!=0){
        mars_color[index++]=color%13; //倒着存放
        color /= 13;
    }
    for (int i = 1; i >= 0 ; --i) {
        if(mars_color[i]>=10)printf("%c",radix[mars_color[i]%10]);
        else printf("%d",mars_color[i]);
    }
}
int main() {
    int r, g, b;
    scanf("%d%d%d",&r,&g,&b);
    printf("#");
    change(r);
    change(g);
    change(b);

}