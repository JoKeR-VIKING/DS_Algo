#include<bits/stdc++.h>

using ll = long long;

using namespace std;

class Graph
{
private:
    int n;
    int** input;
    int* parent;
    int* weight;
    bool* visited;
public:
    Graph(int n)
    {
        this->n = n;
        input = new int *[n];
        parent = new int[n];
        weight = new int[n];
        visited = new bool[n];

        for (int i=0;i<n;i++)
        {
            input[i] = new int[n];
            weight[i] = INT_MAX;
            visited[i] = false;
        }
        
        parent[0] = -1;
    }
    
    int findMin()
    {
        int minVertex = -1;
        for (int i=0;i<n;i++)
        {
            if (!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex]))
                minVertex = i;
        }
        
        return minVertex;
    }
    
    void buildMST()
    {
        for (int i=0;i<n;i++)
        {
            int minVertex = findMin();
            visited[minVertex] = true;
            
            for (int j=0;j<n;j++)
            {
                if (!visited[j] && input[minVertex][j])
                {
                    if (input[minVertex][j] < weight[j])
                    {
                        weight[j] = input[minVertex][j];
                        parent[j] = minVertex;
                    }
                }
            }
        }
    }
    
    void printMST()
    {
        buildMST();
        
        for (int i=1;i<n;i++)
        {
            cout<<min(parent[i], i)<<" "<<max(parent[i], i)<<" "<<weight[i]<<"\n";
        }
    }
    
    void takeInput(int edges)
    {
        for (int i=0;i<edges;i++)
        {
            int p1, p2, w;
            cin>>p1>>p2>>w;
            
            input[p1][p2] = w;
            input[p2][p1] = w;
        }
    }
    
    ~Graph()
    {
        for (int i=0;i<n;i++)
        {
            delete[] input[i];
        }
        
        delete[] input;
        delete[] parent;
        delete[] weight;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, edges;
    cin>>n>>edges;

    Graph g(n);
    g.takeInput(edges);

    g.printMST();

    return 0;
}
