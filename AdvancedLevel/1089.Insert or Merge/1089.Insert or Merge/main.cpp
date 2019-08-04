#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 111;
int origin[N], tempOri[N], changed[N];//原始数组，原始数组备份，目标数组
int n;

bool isSame(int A[], int B[]) {//判断数组A和数组B是否相同
	for (size_t i = 0; i < n; i++)
	{
		if (A[i] != B[i])return false;
	}
	return true;
}

void showArray(int A[]) {		//输出数组
	for (size_t i = 0; i < n; i++)
	{
		printf("%d", A[i]);
		if (i < n - 1)printf(" ");
	}
	printf("\n");
}

bool insertSort() {		//插入排序
	bool flag = false;	//判断过程中是否存在相同数组
	for (size_t i = 1; i < n; i++)		//进行n-1趟排序
	{
		if (i != 1 && isSame(tempOri, changed))flag = true;	//中间步骤相同，且不是初始数组
		int temp = tempOri[i], j = i;
		while (j > 0 && tempOri[j - 1] > temp)//进行插入
		{
			tempOri[j] = tempOri[j - 1];
			j--;
		}
		tempOri[j] = temp;
		if (flag)return true;
	}
	return false;
}

void mergeSort() {		//归并算法
	bool flag = false;	//记录过程中是否存在相同数组
	for (int step = 2;  step/2<= n ;  step*=2)
	{
		if (step != 2 && isSame(tempOri, changed))flag = true;//中间步骤相同，且不是初始数组
		for (int i = 0; i < n; i += step)
		{
			sort(tempOri + i, tempOri + min(i + step,n));//排序与合并
		}
		if (flag == true) {
			showArray(tempOri);
			return;
		}
	}
}
int main() {
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &origin[i]);
		tempOri[i] = origin[i];
	}
	for (size_t i = 0; i < n; i++)
	{
		scanf_s("%d", &changed[i]);
	}
	if (insertSort()) {//如果在插入排序中找到目标数组
		printf("Insertion Sort\n");
		showArray(tempOri);
	}
	else	//否则就是归并
	{
		printf("Merge Sort\n");
		for (size_t i = 0; i < n; i++)
		{
			tempOri[i] = origin[i];//刷新tempOri
		}
		mergeSort();
	}
	return 0;
}
