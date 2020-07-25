
// TLE 

class Solution{
public:
    int lenLongestFibSubseq(vector<int>& A){
        
        int result = 0;
        
        backtrack(A, result, {}, 0);
        
        return result;
    }
    
    void backtrack(vector<int>& A, int& result, vector<int> v, int pos){
                
        if(pos == A.size())
            return;
        
        for(int i = pos; i < A.size(); i++){
            
            int size = v.size();    
            
            if(size >= 2){
                if(v[size - 1] + v[size - 2] == A[i])
                    result = max(size + 1, result);
                else if(v[size - 1] + v[size - 2] < A[i])       // Since input is sorted
                    return;
                else
                    continue;
            }
            
            v.push_back(A[i]);
            backtrack(A, result, v, i + 1);
            v.pop_back();
        }
    }
    
};

/*

Approach: Generate all subseq and check the longest.

// Space Optimization

class Solution{
public:
    int lenLongestFibSubseq(vector<int>& A){
        
        int result = 0;
        
        backtrack(A, result, -1, -1, 0, 0);
        
        return result;
    }
    
    void backtrack(vector<int>& A, int& result, int one, int two, int pos, int len){
                
        if(pos == A.size())
            return;
        
        for(int i = pos; i < A.size(); i++){
            
            if(two >= 0){
                if(A[one] + A[two] == A[i])
                    result = max(len + 1, result);
                else if(A[one] + A[two] < A[i])       // Since input is sorted
                    return;
                else
                    continue;
            }
            
            backtrack(A, result, i, one, i + 1, len + 1);
        }
    }
    
};

*/
