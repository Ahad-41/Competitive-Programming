#include<stdio.h>
#include<string.h>

int parent[26];
char edge[2];

void Initialization(int node) {
    int i;
    for (i = 0; i < node; i++) parent[i] = i;
}

int Find(int i) {
    if (parent[i] == i) return i;
    else return Find(parent[i]);
}

void Union(int x, int y) {
    int parent_of_x = Find(x);
    int parent_of_y = Find(y);
    parent[parent_of_x] = parent_of_y;
}

int main()
{   
    int testCase;
    scanf("%d\n\n", &testCase);
    int i;
    for (i = 1; i <= testCase; i++) {
        char largestNode = getchar();
        getchar();
        
        int node = (largestNode - 'A' + 1);
        Initialization(node);
        int connectedSubGraph = node;

        while (gets(edge) && strlen(edge)) {
            int u = edge[0] - 'A';
            int v = edge[1] - 'A';
            
            if (Find(u) != Find(v)) {
                Union(u, v);
                connectedSubGraph--;
            }
        }

        if (i != 1) printf("\n");
        printf("%d\n", connectedSubGraph);
    }

    return 0;
}
