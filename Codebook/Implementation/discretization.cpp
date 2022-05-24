vector<int> status,lisan;
inline vector<int> discretization(vector<int> a){
    // 離散化、不影響原先位置
    status.resize(a.size());
    lisan = a;
    sort(lisan.begin(),lisan.end());
    lisan.resize(unique(lisan.begin(),lisan.end())-lisan.begin());
    for(int i = 0; i < (int)a.size(); i++) 
        status[i] = lower_bound(lisan.begin(),lisan.end(),a[i])-lisan.begin();
    return status;
}
inline vector<int> model(vector<int> a){
    // vector 去掉重複並排序
    lisan = a;
    sort(lisan.begin(),lisan.end());
    lisan.resize(unique(lisan.begin(),lisan.end())-lisan.begin());
    return lisan;
}