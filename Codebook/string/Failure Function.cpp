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