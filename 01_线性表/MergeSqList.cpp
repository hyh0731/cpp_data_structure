#include <iostream>
using namespace std;

const int MAXSIZE = 100;
//顺序表结构体
struct Sqlist
{
	int data[MAXSIZE];
	int length;//当前有效元素个数
};
//打印顺序表
void PrintSqlist(Sqlist L)
{
	for (int i = 0;i < L.length;i++)
	{
		cout << L.data[i] << " ";
	}
	cout << endl;
}
//拼接两个顺序表到c
void MergeSqlist(Sqlist A, Sqlist B, Sqlist &C)
{
	if (A.length + B.length > MAXSIZE)
	{
		//判断总长度是否大于最大容量
		cout << "空间不足无法拼接" << endl;
		C.length = 0;
		return；
		
	}
	int i, j, k;
	i = j = k = 0;
	while (i < A.length && j < B.length)
	{
		if (A.data[i] < B.data[j])
		{
			C.data[k++] = A.data[i++];
		}
		else
		{
			C.data[k++] = B.data[j++];
		}
	}
	while (i < A.length)
	{
		C.data[k++] = A.data[i++];
	}
	while (j < B.length)
	{
		C.data[k++] = B.data[j++];
	}
	C.length = k;
}
int main()
{
	Sqlist A, B, C;
	A.length = 3;
	A.data[0] = 1;
	A.data[1] = 3;
	A.data[2] = 7;
	B.length = 4;
	B.data[0] = 2;
	B.data[1] = 4;
	B.data[2] = 6;
	B.data[3] = 9;
	C.length = 7;
	MergeSqlist(A, B, C);
	PrintSqlist(C);

}
