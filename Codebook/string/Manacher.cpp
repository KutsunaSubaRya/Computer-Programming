#define maxEP(x) (max_element((x).begin(), (x).end()))-(x).begin()
#define maxE(x) (*max_element((x).begin(), (x).end()))
vector<int> p(MAX); string new_str;
void generate_new_string(string s){ // generate the new string
    new_str.insert(0, "@");
    for(int i = 0; i < s.size(); i++) {
        new_str += "#";
        new_str += s[i];
    }
    new_str += "#$";
}
pair<int,int> manacher(string s) {
    // find the half length and center position of the longest substring palindrome 
    for(int i=0;i<MAX;i++) p[i]=0;
    int len = s.size(), Center = 0, R = 0;
    for(int i = 0; i < len; i++) {
        int mirror = 2 * Center - i;
        if(i + p[mirror] < R) p[i] = min(p[mirror], R - i);
        while(s[i + (1 + p[i])] == s[i - (1 + p[i])]) p[i]++;
        if(i + p[i] > R) {
            Center = i;
            R = i + p[i];
        }
    }
    return make_pair(maxE(p),maxEP(p)); 
    // .first = the half size of palindrome  
    // .second = the position of the palindrome center
}
void print_the_longest_substring_palindrome(int pa_len, int center_pos){
    // pa_len=manacher.first, center_pos=manacher.second;
    for(int i=pos-pa_len;i<pos+pa_len;i++) 
        if(new_s[i]!='#') cout << new_s[i];
}
