#include <iostream>
#include <string.h>
#include <iterator>
using namespace std;
struct CStudent
{
    int id = 0,
        score = 0;
    char name[30] = {};
};

typedef int (*cmpFunction) (const CStudent &, const CStudent &);

ostream & operator << (ostream &os, const CStudent &stu)
{
    os << stu.id << ' ' << stu.name << ' ' << stu.score;
    return os;
}

void sort(CStudent data[], int n, cmpFunction cmp)
{
    // Call cmp(data[i], data[j]) when you need to compare two CStudent objects
	for(int i=0;i<n;i++){
		for(int j=0;j<n-1;j++){
			if(!cmp(data[j],data[j+1])){
				CStudent tmp;
				tmp=data[j];
				data[j]=data[j+1];
				data[j+1]=tmp;
			}
		}
	}
}

int CompareId(const CStudent &lhs, const CStudent &rhs){
    return lhs.id < rhs.id;
}
int CompareName(const CStudent &lhs, const CStudent &rhs){
    int cmp=strcmp(lhs.name,rhs.name);
    if(cmp>=0) return 0;
    else return 1;
    // for(int i=0;i<strlen(lhs.name);i++){
    //     if(lhs.name[i] == rhs.name[i]){
    //         continue;
    //     }
    //     else{
    //         return lhs.name[i]<rhs.name[i];
    //     }
    // }
    // return strlen(lhs.name)<strlen(rhs.name);
}
int CompareScore(const CStudent &lhs, const CStudent &rhs){
    return lhs.score < rhs.score;
}



int main()
{
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    CStudent data[] = {{1, 90, "David"}, {5, 100, "Allen"}, {3, 92, "Alice"}, {2, 85, "Bob"}, {4, 91, "Cyndi"}};

    sort(data, size(data), CompareId);
    for (const auto &e: data) {cout << e << endl;} cout << endl;
    sort(data, size(data), CompareName);
    for (const auto &e: data) {cout << e << endl;} cout << endl;
    sort(data, size(data), CompareScore);
    for (const auto &e: data) {cout << e << endl;} cout << endl;
}






