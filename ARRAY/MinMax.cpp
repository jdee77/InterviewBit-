int Solution::solve(vector<int> &A) {
    int mx = INT_MIN;
    int mn = INT_MAX;
    for(int i = 0; i< A.size(); i++)
    {
        mx = max(mx, A[i]);
        mn = min(mn, A[i]);
    }
    
    return mn + mx;
}
