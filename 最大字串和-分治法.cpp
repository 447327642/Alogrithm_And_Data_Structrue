/**************************************************************
���η������������к�
***************************************************************/
#include<iostream>
#include<vector>
#include<climits>
using namespace std;

inline int max3(int a,int b,int c) {
    a = a>b ? a : b;
    return a>c?a:c;
}
//���η�ʵ�֣����Ӷ�Ϊ O(nlogn)
int maxSum( const int * a, int left, int right ) {
    if( left == right )  // Base case
        return a[left];
    int center = left + ((right-left)>>1);
    int maxLeftSum  = maxSum( a, left, center );
    int maxRightSum = maxSum( a, center + 1, right );
    //�����������ִ���Խ���е�...
    //�ҵ��е��������
    int maxLeftBorderSum = -INT_MAX, leftBorderSum = 0;
    for( int i = center; i >= left; i-- ) {
        leftBorderSum += a[ i ];
        if( leftBorderSum > maxLeftBorderSum )
            maxLeftBorderSum = leftBorderSum;
    }
    //�ҵ��е��ұ�����
    int maxRightBorderSum = -INT_MAX, rightBorderSum = 0;
    for( int j = center + 1; j <= right; j++ ) {
        rightBorderSum += a[ j ];
        if( rightBorderSum > maxRightBorderSum )
            maxRightBorderSum = rightBorderSum;
    }
    //ȡ�����͵����ֵ��Ϊ�ô�������Ӵ���
    return max3(maxLeftSum, maxRightSum, maxLeftBorderSum + maxRightBorderSum);
}
/**Kadane �㷨ʵ��  ���Ӷ�Ϊ O(n)
	�����ǰ��Ϊ�������������ֵ���ϵ�ǰ�����ȻС��ԭ��ֵ����Ӧ����ǰ�Ͷ�����
	�ӵ�һ�ʼ������ͣ����Ӵ�ֻ���ܴ�����һ���������ڣ���ϵΪ�÷����ǰ׺
**/
int maxSummary(int A[], int n) {
    int mmax = A[0], cursum = 0;
    for(int i = 0; i < n; ++i) {
        cursum = cursum<0 ? A[i] : A[i]+cursum;
        mmax = cursum>mmax ? cursum : mmax;
    }
    return mmax;
}
//�����Ҫ��¼�Ӵ���λ��
int maxSummary(int A[], int n, int pos[2]) {
    int mmax = -INT_MAX, cursum = -1;//-1��ʾ��δ��ʼͳ��
    for(int i = 0; i < n; ++i) {
        if(cursum < 0) {
            cursum = A[i];
            pos[0] = i;
        } else
            cursum += A[i];
        if(cursum > mmax) {
            mmax = cursum;
            pos[1] = i+1;
        }
    }
    return mmax;
}
int main() {
    int a[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int b[] = {-2, -4, -3, -5, -1};
    int pos[2] = {0};
    cout<<maxSum(a,0,8)<<endl;
    cout<<"����Ӵ���Ϊ: "<<maxSummary(a,9,pos)<<endl;
    cout<<"�����Ӵ�Ϊ: ";
    for(int i=pos[0]; i<pos[1]; ++i)
        cout<<a[i]<<" ";
    cout<<endl;
}
