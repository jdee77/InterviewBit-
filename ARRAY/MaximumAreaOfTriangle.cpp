/*
Problem Description

Given a character matrix of size N x M in the form of a string array A of size N where A[i] denotes ith row.

Each character in the matrix consists any one of the following three characters {'r', 'g', 'b'} where 'r' denotes red color similarly 'g' denotes green color and 'b' denotes blue color.

You have to find the area of the largest triangle that has one side parallel to y-axis i.e vertical and the color of all three vertices are different.

NOTE: If the area comes out to be a real number than return the ceil of that number.

Problem Constraints
2 <= N, M <= 103

A[i][j] = 'r' or A[i][j] = 'g' or A[i][j] = 'b'

Input Format
First and only argument is an string array A of size N denoting the 2D character matrix.

output Format
Return a single integer denoting the area of the largest triangle that has one side parallel to y-axis i.e vertical and the color of all three vertices are different.

Example Input
Input 1:

 A = ["rrrrr", "rrrrg", "rrrrr", "bbbbb"]
Input 2:

 A = ["rrr", "rrr", "rrr", "rrr"]

Example Output
Output 1:

 10
Output 2:

 0
*/

int Solution::solve(vector<string> &A) {
    int m = A.size();
    int n =  A[0].size();
    
    map<char, int> maxr[n], minr[n], maxc, minc;
    
    for(int i = 0; i< m; i++)
    {
        for(int j = 0; j< n; j++)
        {
            maxr[j][A[i][j]] = max(maxr[j][A[i][j]], i);
            minr[j][A[i][j]] = (minr[j].count(A[i][j]) == 1)?min(minr[j][A[i][j]], i): i;
            
            maxc[A[i][j]] = max(maxc[A[i][j]], j);
            minc[A[i][j]] = (minc.count(A[i][j]) == 1)?min(minc[A[i][j]], j): j;
        }
    }
    
    float ans = 0.0;
    float base;
    float height;
    for(int i = 0; i< n; i++)
    {
        // base rg heigh b
        if(maxr[i].count('r') && maxr[i].count('g') && maxc.count('b'))
        {
            base = max(abs(maxr[i]['r'] - minr[i]['g']) + 1, abs(minr[i]['r'] - maxr[i]['g']) + 1);
            height = max(abs(maxc['b'] - i) + 1, abs(minc['b'] - i) + 1);
            ans = max(base * height, ans);
        }
        
        // base rb heigh g
        if(maxr[i].count('r') && maxr[i].count('b') && maxc.count('g'))
        {
            base = max(abs(maxr[i]['r'] - minr[i]['b']) + 1, abs(minr[i]['r'] - maxr[i]['b']) + 1);
            height = max(abs(maxc['g'] - i) + 1, abs(minc['g'] - i) + 1);
            ans = max(base * height, ans);
        }
        
        // base gb heigh r
        if(maxr[i].count('b') && maxr[i].count('g') && maxc.count('b'))
        {
            base = max(abs(maxr[i]['b'] - minr[i]['g']) + 1, abs(minr[i]['b'] - maxr[i]['g']) + 1);
            height = max(abs(maxc['r'] - i) + 1, abs(minc['r'] - i) + 1);
            ans = max(base * height, ans);
        }
    }
    return (int)(ans + 1)/2;
}
