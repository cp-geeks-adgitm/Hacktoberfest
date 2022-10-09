#include <iostream>
using namespace std;

/* UnionFind/Disjoint Set data structure implementation */
class UnionFind
{
private:
    int nsize;   // number of nodes in this union find
    int *gs;     // to store size of each group
    int *parent; // points to the parent
    int rsize;   // number of root Nodes in the union find

public:
    UnionFind(int sz, bool def)
    {

        if (def == true)
        {
            nsize = rsize = sz;
            gs = new int[sz];
            parent = new int[sz];
            for (int i = 0; i < nsize; ++i)
            {
                parent[i] = i;
                gs[i] = 1;
            }
        }
        else
        {
            nsize = rsize = 0;
            parent = new int[sz];
            gs = new int[sz];
        }
    }

    void add(int p)
    {
        parent[p] = p;
        gs[p] = 1;
        nsize++;
        rsize++;
    }

    // Find which component/set 'p' belongs to, takes amortized constant time.
    int find(int p)
    {
        int root = p;
        while (root != parent[root])
            root = parent[root];

        // Compress the path leading back to the root.
        // Doing this operation is called "path compression"
        // and is what gives us amortized time complexity.
        while (root != parent[p])
        {
            int next = parent[p];
            parent[p] = root;
            p = next;
        }

        return root;
    }
    
    bool connected(int p, int q)
    {
        return find(p) == find(q);
    }
    void unify(int p, int q)
    {
        int r1 = find(p);
        int r2 = find(q);

        if (connected(p, q))
            return;

        if (gs[r1] < gs[r2])
        {
            gs[r2] += gs[r1];
            parent[r1] = r2;
            gs[r1] = 0;
        }
        else
        {
            gs[r1] += gs[r2];
            parent[r2] = r1;
            gs[r2] = 0;
        }

        rsize--;
    }

    // Return the size of the group/node 'p' belongs to
    int componentSize(int p)
    {
        return gs[find(p)];
    }

    int size()
    {
        return nsize;
    }

    int components()
    {
        return rsize;
    }
};

int main()
{
    UnionFind gg(5, true);
    // gg.add(10);
    // gg.add(20);
    // gg.add(30);
    // gg.add(60);
    // gg.add(80);
    // gg.unify(10,20);
    gg.unify(0, 3);
    gg.unify(0, 1);
    gg.unify(2, 4);
    gg.unify(2, 3);
    // cout << gg.find(10) << '\n';
    // cout << gg.find(20) << '\n';
    // cout << gg.find(30) << '\n';
    // cout << gg.find(60) << '\n';
    // cout << gg.find(80) << '\n';

    cout << gg.find(0) << '\n';
    cout << gg.find(1) << '\n';
    cout << gg.find(2) << '\n';
    cout << gg.find(3) << '\n';
    cout << gg.find(4) << '\n';
    cout << gg.componentSize(3) << '\n';

    // cout << gg.find(5) << '\n';
    // cout << gg.find(6) << '\n';
    // cout << gg.find(7) << '\n';
    // cout << gg.find(3) << '\n';
}
