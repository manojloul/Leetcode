class Solution {
public:
  bool solve ( int index , int sqrsize , vector<int> &matchsticks , vector<int> &sqr){ 
        if ( index == matchsticks.size()) 
            return sqr[0]==sqr[1] and sqr[1]==sqr[2] and sqr[2]==sqr[3] ;
        
        for ( int i = 0 ; i < 4 ; i ++ ){
            if ( sqr[i] + matchsticks[index] > sqrsize) continue ;  
           
            int j = i ;
            while ( --j >= 0) 
                if ( sqr[i] == sqr[j]) break;
            
            if ( j != -1 ) continue ;
            
            sqr[i] += matchsticks[index];
            if ( solve ( index + 1 , sqrsize , matchsticks , sqr )) return true;
            sqr[i] -= matchsticks[index];
        }
        
        return false;
    }
    
public:
    bool makesquare(vector<int>& matchsticks) {
       
        int sum = 0 ;
        
        for ( int i : matchsticks) sum += i ;
        if ( sum == 0 or sum % 4 ) return false;
         
        sort( matchsticks.begin() , matchsticks.end() , greater<int>());
        
        vector<int> sqr(4, 0 );
        return solve( 0 , sum / 4 , matchsticks , sqr);
    }
};