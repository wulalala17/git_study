/*给定一个未排序的整数数组，找出其中没有出现的最小的正整数。
示例 1:
输入: [1,2,0]
输出: 3
示例 2:
输入: [3,4,-1,1]
输出: 2
示例 3:
输入: [7,8,9,11,12]
输出: 1
说明:
你的算法的时间复杂度应为O(n)，并且只能使用常数级别的空间。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/first-missing-positive
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
第二次提交测试*/

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
