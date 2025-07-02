#include<iostream>
#include<vector>
using namespace std;


class DisjointSet
{
    vector<int> rank,parent,size;

    public:

        DisjointSet(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i = 0;i <= n;i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int findUPar(int node) // find ultimate parent
        {
            if(parent[node] == node)
                return node;
            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u,int v)
        {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v)
            {
                return ;
            }
            
            if(rank[ulp_u] < rank[ulp_v])
            {
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v])
            {
                parent[ulp_v] = ulp_u;
            }
            else if(rank[ulp_v] == rank[ulp_u])
            {
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        void unionBySize(int u,int v)
        {
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);

            if(ulp_u == ulp_v)
            {
                return ;
            }

            
            if(size[ulp_u] < size[ulp_v])
            {
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else // this case will also cover the case when size[ulp_u] == size[ulp_v]
                // because we are not using rank here
            {
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

int main() {
    DisjointSet ds(7);
    ds.unionByRank(1, 2);
    ds.unionByRank(2, 3);
    ds.unionByRank(4, 5);
    ds.unionByRank(6, 7);
    ds.unionByRank(5, 6);

    // Now connect components
    ds.unionByRank(3, 7);

    // Test whether two nodes belong to the same component
    if (ds.findUPar(1) == ds.findUPar(7)) {
        cout << "Same component\n";
    } else {
        cout << "Different components\n";
    }

    return 0;
}