// Maximum Absolute Difference
/*
You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 ≤ i, j ≤ N.

f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

For example,

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.
*/
int Solution::maxArr(vector<int> &A) {
    int res = INT_MIN;
    int size = A.size();
    int max1 = INT_MIN, min1=INT_MAX, max2=INT_MIN, min2=INT_MAX;
    
    for(int i = 0; i< size; i++)
    {
        max1 = max(A[i] + i, max1);
        max2 = max(A[i] - i, max2);
        min1 = min(A[i] + i, min1);
        min2 = min(A[i] - i, min2);
    }
    
    return max(max1 - min1, max2 - min2);
}