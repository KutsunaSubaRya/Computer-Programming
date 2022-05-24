#include<bits/stdc++.h>
using namespace std;

const int maxn = (1 << 20) + 10;
const int maxm = 105;

int n, m, mintime;
bool done[maxn];

struct node {
    int time;//耗时(当作路径长度)
    int a1, a2, b1, b2;//表示修复前后状态的二进制串
    //a1修复前为1,a2修复前为0,b1修复后为1,b2修复后为0
}a[maxm];

struct HeapNode {
    int u, d;
    HeapNode(int uu, int dd) :u(uu), d(dd) {}
    bool operator < (const HeapNode& rhs) const {
        return d > rhs.d;
    }
};

void init() {
    memset(done, 0, sizeof(done));
    for (int i = 0; i <= m; ++i) a[i].time = a[i].a1 = a[i].a2 = a[i].b1 = a[i].b2 = 0;
}

bool dijkstra() {
    priority_queue<HeapNode> que;
    que.push(HeapNode((1 << n) - 1, 0));//初始时的状态，全为1表示bug都存在

    while (!que.empty()) {
        HeapNode x = que.top();
        que.pop();
        int u = x.u;
        if (u == 0) { mintime = x.d; return true; }
        if (done[u]) continue;
        done[u] = true;

        for (int i = 0; i < m; ++i) {//每次遍历所有的补丁，看能不能往上打
            if ((u & a[i].a1) == a[i].a1 && (~u & a[i].a2) == a[i].a2) {//符合要求就打，计算出下一个状态，加入队列
                int uu = u | a[i].b1;
                uu = uu & ~a[i].b2;
                que.push(HeapNode(uu, x.d + a[i].time));
            }
        }
    }
    return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
#endif
    int kase = 0;
    scanf("%d%d", &n, &m);
        //if (!n && !m) break;
        init();
        for (int i = 0; i < m; ++i) {
            int t;
            char s1[30], s2[30];
            scanf("%d%s%s", &t, s1, s2);
            for (int j = 0; j < n; ++j) {
                a[i].time = t;
                if ('+' == s1[n - 1 - j]) { a[i].a1 = a[i].a1 | (1 << j); }
                if ('-' == s1[n - 1 - j]) { a[i].a2 = a[i].a2 | (1 << j); }
                if ('+' == s2[n - 1 - j]) { a[i].b1 = a[i].b1 | (1 << j); }
                if ('-' == s2[n - 1 - j]) { a[i].b2 = a[i].b2 | (1 << j); }
            }
        }

        for (int i = 0; i < m; ++i) {
            printf("%d %d %d %d\n", a[i].a1, a[i].a2, a[i].b1, a[i].b2);
        }
        system("pause");
        // printf("Product %d\n", ++kase);
        // if (dijkstra()) {
        //     printf("Fastest sequence takes %d seconds.\n", mintime);
        // }
        // else {
        //     puts("Bugs cannot be fixed.");
        // }
        // putchar('\n');
    
    return 0;
}