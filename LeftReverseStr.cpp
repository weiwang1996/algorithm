#include<iostream>
#include<string.h>
#include<assert.h>
using namespace std;
void Reserve(char *pStart, char *pEnd);
void ReserveSentence(char * arr)
{
	assert(arr);
	char *Start = arr;//����ָ���ַ�����ͷ��ָ��
	char *End = arr + strlen(arr)-1;//ָ���ַ���β��ָ��
	Reserve(Start, End);//�������߶�ʮһ��ȫ����ת
	char * pstart= arr;//��������ָ�붼��ָ��ת����ַ�����
	char *pend = arr;
	while (pend)//�жϸ��ַ����Ƿ���һ������ ��
	{
		if (*pend == ' ')//Ҳ����˵�жϺ����� ' '
			break;//�����������
			pend++;
			if (*pend == '\0') //û�еĻ�˵����һ�������Ĵʣ�ֱ��������
		return;
	}
	
	while (*pstart != '\0')//ѭ��ֱ������
	{
		while (*pend != ' '&&*pend!='\0')//��pend������ֱ������' '�����߽���
		{
			pend++;
		}
			Reserve(pstart, pend-1);//��ת�õ��� ��ע�������pendָ��' ',����pend-1��ǰ��
			if (*pend == '\0')//
			pstart = pend;//����pstartת�Ƶ�'\0'
			else
			pstart = ++pend;//û����ʱ ++pendָ����һ�����ʵĿ�ʼ����pstartָ���¸�����
	}
}
void LeftRevolve(char *arr,  int i)
{
	assert(arr);	
	int n = strlen(arr);
	if (i == 0&&i>n&&n>0)//�Ƿ����ַ��� ����i>n
		return;
	char *leftstart = arr;
	char* leftend = arr + i - 1;
	char *rightstart = arr + i;
	char *rightend = arr+n-1;
	//������ת��
	Reserve(leftstart, leftend);
	Reserve(rightstart, rightend);
	Reserve(leftstart, rightend);
}
void Reserve(char *pStart,char *pEnd)
{
	if (pStart == NULL || pEnd == NULL)
		return;
	while (pStart< pEnd)
	{
		char temp = *pStart;
		*pStart = *pEnd;
		*pEnd = temp;
		pStart++;
		pEnd--;
	}
}
int main()
{
	char arr[] = "abcdefgh";
	char arr1[] = "who am  i";
	char arr2[] = "whoami";
	ReserveSentence(arr2);
	LeftRevolve(arr, 3);
	cout << arr2<< endl;
	return 0;
}