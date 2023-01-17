//
// Created by 서찬혁 on 2023/01/17.
//
#include "iostream"
#include "vector"
#include "algorithm"
#include "queue"
using namespace std;

int N, M;
const int MAX = 10001;
vector<int> map[MAX];
bool visited[MAX];
queue<int> q;
vector<pair<int, int> > v;
int hacked = 1;

void BFS(int v) {
    visited[v] = true;
    q.push(v);

    while(!q.empty()) {
        v = q.front();
        q.pop();

        for(int w = 0; w < map[v].size(); ++w) {
            int nv = map[v][w];

            if(!visited[nv]) {
                visited[nv] = true;
                q.push(nv);
                ++hacked;
            }
        }
    }
}

void resetVisit() {
    for(int i = 0; i <= N; ++i) {
        visited[i] = 0;
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; ++i) {
        int A, B;
        cin >> A >> B;
        map[B].push_back(A);
    }

    for(int i = 1; i <= N; ++i) {
        BFS(i);
        resetVisit();
        v.push_back(make_pair(i, hacked));
        hacked = 1;
    }

    int maxHack = -1;
    for(int i = 0; i < v.size(); ++i)
        if(v[i].second > maxHack)
            maxHack = v[i].second;

    for(int i = 0; i < v.size(); ++i )
        if(v[i].second == maxHack)
            cout << v[i].first << " ";

}

