#include<cstdio>
#include<algorithm>
using namespace std;

const int N = 111;
int origin[N], tempOri[N], changed[N];//ԭʼ���飬ԭʼ���鱸�ݣ�Ŀ������
int n;

bool isSame(int A[], int B[]) {//�ж�����A������B�Ƿ���ͬ
	for (size_t i = 0; i < n; i++)
	{
		if (A[i] != B[i])return false;
	}
	return true;
}

void showArray(int A[]) {		//�������
	for (size_t i = 0; i < n; i++)
	{
		printf("%d", A[i]);
		if (i < n - 1)printf(" ");
	}
	printf("\n");
}

bool insertSort() {		//��������
	bool flag = false;	//�жϹ������Ƿ������ͬ����
	for (size_t i = 1; i < n; i++)		//����n-1������
	{
		if (i != 1 && isSame(tempOri, changed))flag = true;	//�м䲽����ͬ���Ҳ��ǳ�ʼ����
		int temp = tempOri[i], j = i;
		while (j > 0 && tempOri[j - 1] > temp)//���в���
		{
			tempOri[j] = tempOri[j - 1];
			j--;
		}
		tempOri[j] = temp;
		if (flag)return true;
	}
	return false;
}

void mergeSort() {		//�鲢�㷨
	bool flag = false;	//��¼�������Ƿ������ͬ����
	for (int step = 2;  step/2<= n ;  step*=2)
	{
		if (step != 2 && isSame(tempOri, changed))flag = true;//�м䲽����ͬ���Ҳ��ǳ�ʼ����
		for (int i = 0; i < n; i += step)
		{
			sort(tempOri + i, tempOri + min(i + step,n));//������ϲ�
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
	if (insertSort()) {//����ڲ����������ҵ�Ŀ������
		printf("Insertion Sort\n");
		showArray(tempOri);
	}
	else	//������ǹ鲢
	{
		printf("Merge Sort\n");
		for (size_t i = 0; i < n; i++)
		{
			tempOri[i] = origin[i];//ˢ��tempOri
		}
		mergeSort();
	}
	return 0;
}
