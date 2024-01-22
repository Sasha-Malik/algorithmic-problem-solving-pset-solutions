#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class DisjointSet {
public:
    vector<int> parent;
    vector<int> rank;

    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (x != parent[x]) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }
};

struct Point {
    double x, y;
};

double distance(Point a, Point b) {
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main() {
    int n;
    double d;
    cin>>n>>d;

    vector<Point> v(n);

    for (int i = 0; i < n; i++) {
        cin>>v[i].x;
        cin>>v[i].y;
    }

    DisjointSet ds(n);

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (distance(v[i], v[j]) <= d) {
                ds.unionSets(i, j);
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (ds.find(i) == i) {
            count++;
        }
    }

    cout<<count;

    return 0;
}
