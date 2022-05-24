inline void failure(string& str){
    // F[] -> the failure function table
    F[0]=-1;
    int sz=str.size();
    for(int i=1,j=-1;i<sz;i++){
        while(j>=0 && str[j+1]!=str[i]) j=F[j];
        if(str[j+1]==str[i]) j++;
        F[i]=j;
    }
} 
inline vector<int> KMP(string& str, string& comp){
    failure(comp);
    vector<int> ans; 
    // the numbers in vector are the " matching head position of str"  
    int len=str.size(),j=-1;
    for(int i=0;i<len;i++){
        while(j>=0 && comp[j+1]!=str[i]) j=F[j];
        if(comp[j+1]==str[i]) j++;
        if(j+1==comp.size()){ /* Match!!! */
            ans.emplace_back(i-j);
            j=F[j];
        }
    }
    return ans;
}