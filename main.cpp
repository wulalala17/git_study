/*����һ��δ������������飬�ҳ�����û�г��ֵ���С����������
ʾ�� 1:
����: [1,2,0]
���: 3
ʾ�� 2:
����: [3,4,-1,1]
���: 2
ʾ�� 3:
����: [7,8,9,11,12]
���: 1
˵��:
����㷨��ʱ�临�Ӷ�ӦΪO(n)������ֻ��ʹ�ó�������Ŀռ䡣
��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/first-missing-positive
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
�ڶ����ύ����*/

#include <iostream>

using namespace std;
int fp(int *a,int n)
{
    int t;
    for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            if(a[j]<a[i])
            {
                t=a[j];
                a[j]=a[i];
                a[i]=t;
            }
        }
    }
    int x=1;
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==x)
            x++;
    }
    return x;
}
int others(int *nums, int n)
{
    int b[n+1];
    for(int i=0;i<n;i++)
    {
        if (nums[i]>=1&&nums[i]<=n)
            b[nums[i]]=nums[i];
    }
    for(int i=0;i<n+1;i++)
    {
        if (b[i]!=i)
            return i;
    }
    return n+1;
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout <<fp(a,n)<< endl;
    cout<<"others: "<<others(a,n)<<endl;
    return 0;
}
