#include <stdio.h>
#include <stdlib.h>
#define ARRAY_SIZE 10
void print_array(int*p)
{
    for(int i=0;i<ARRAY_SIZE;i++)
    {
        printf("%d \n",p[i]);
    }
}
void mergeSort(int *a, int l, int r)
{
  if (l == r) return;
  int mid = (l + r) / 2; // ���������� �������� ������������������
  // � ���������� �������� ������� ���������� ��� ������ ��������
  mergeSort(a, l, mid);
  mergeSort(a, mid + 1, r);
  int i = l;  // ������ ������� ����
  int j = mid + 1; // ������ ������� ����
  int *tmp = (int*)malloc(r * sizeof(int)); // �������������� ������
  for (int step = 0; step < r - l + 1; step++) // ��� ���� ��������� ��������������� �������
  {
    // ���������� � ����������� ������������������ ������� �� ��������� ���� �����
    // ��� ������� ������� ���� ���� j > r
    if ((j > r) || ((i <= mid) && (a[i] < a[j])))
    {
      tmp[step] = a[i];
      i++;
    }
    else
    {
      tmp[step] = a[j];
      j++;
    }
  }
  // ������������ �������������� ������������������ � �������� ������
  for (int step = 0; step < r - l + 1; step++)
    a[l + step] = tmp[step];
}
void fill_random(int*a)
{
    for(int i=0;i<ARRAY_SIZE;i++)
    {
        a[i]=rand();
    }
}
int main()
{
    int*array=(int*)malloc(ARRAY_SIZE*sizeof(int));
    fill_random(array);
    mergeSort(array,0,ARRAY_SIZE-1);
    print_array(array);
    system("pause");
  return 0;
}
