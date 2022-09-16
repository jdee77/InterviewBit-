/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
bool compare(Interval i1, Interval i2)
{
    return i1.start< i2.start;
}
bool isoverlapping(Interval i1, Interval i2)
{
    if(i1.end>= i2.start) return true;
    return false;
}
vector<Interval> Solution::merge(vector<Interval> &A) {
    sort(A.begin(), A.end(), compare);
    int i = 0;
    int size = A.size();
    
    while(i< size - 1)
    {
        int j = i + 1;
        while(j< size && isoverlapping(A[i], A[j]))
        {
            int start = min(A[i].start, A[j].start);
            int end = max(A[i].end, A[j].end);
            
            A[j].start = INT_MAX;
            
            A[i].start = start;
            A[i].end = end;
            j++;            
        }
        i++;
    }
    vector<Interval> res;
    for(int i = 0; i< A.size();i++)
    {
        if(A[i].start != INT_MAX) res.push_back(A[i]);
    }
    return res;
}
