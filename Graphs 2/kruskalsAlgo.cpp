#include <bits/stdc++.h>

using namespace std;

class Edges
{
public:
    int source, destination, weight;
    
    Edges(int s, int d, int w)
    {
        source = s;
        destination = d;
        weight = w;
    }
};

class Graph
{
private:
    int n, edges;
    Edges** input;
    Edges** output;
    int* parentCheck;
public:
    Graph(int n, int edges)
    {
        this -> n = n;
        this -> edges = edges;
        
        input = new Edges*[edges];
        output = new Edges*[n-1];
        parentCheck = new int[n];
        
        for (int i=0;i<n;i++)
            parentCheck[i] = i;
    }
    
    static bool sortFunc(Edges* e1, Edges* e2)
    {
        return e1 -> weight < e2 -> weight;
    }
    
    void buildMST()
    {
        int count = 0, i = 0;
        
        while (count < n-1)
        {
            int parent1 = input[i] -> source;
            while (parentCheck[parent1] != parent1)
                parent1 = parentCheck[parent1];
            
            int parent2 = input[i] -> destination;
            while (parentCheck[parent2] != parent2)
                parent2 = parentCheck[parent2];
            
            if (parent1 != parent2)
            {
                output[count++] = input[i];
                parentCheck[parent1] = parent2;
        	}
            
            i++;
        }
    }
    
    void printMST()
    {
        buildMST();
        
        for (int i=0;i<n-1;i++)
        {
            int p1 = min(output[i] -> source, output[i] -> destination);
            int p2 = max(output[i] -> source, output[i] -> destination);
            
            cout<<p1<<" "<<p2<<" "<<output[i] -> weight<<"\n";
        }
    }
    
    void takeInput()
    {
        for (int i=0;i<edges;i++)
        {
            int s, d, w;
            cin>>s>>d>>w;
            
            input[i] = new Edges(s, d, w);
        }
        
        sort(input, input + edges, sortFunc);
    }
    
    ~Graph()
    {
        for (int i=0;i<edges;i++)
            delete[] input[i];
        
        delete[] input;
    }
};

int main() 
{
    int n, edges;
    cin>>n>>edges;
    
    Graph g(n, edges);
    g.takeInput();
    
    g.printMST();
}
