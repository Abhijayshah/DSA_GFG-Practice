// User function Template for C++

class Solution {
  public:
    bool isPalindrome(int n) {
        // Code here.
        // step 1 - 
        
        string res1 =to_string(n);
        string res2 =res1;
        reverse(res2.begin(),res2.end());
      

        if (res1==res2){
            return true ;
        }else 
              return false ;
        
       
    }
};