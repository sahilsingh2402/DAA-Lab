// Using Disjoint set data structure and kruskal algorithm find the MST of any graph. Show the result of find and union operation stepwise.

#include <stdio.h>
#include <stdlib.h>

struct edge
{
    int u, v, w;
};

struct edge *edges;
int *parent, *rank;

void make_set(int n)
{
    parent = (int *)malloc(n * sizeof(int));
    rank = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
        rank[i] = 0;
    }
}

int find(int x)
{
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void union_set(int x, int y)
{
    int xroot = find(x);
    int yroot = find(y);
    if (rank[xroot] < rank[yroot])
        parent[xroot] = yroot;
    else if (rank[xroot] > rank[yroot])
        parent[yroot] = xroot;
    else
    {
        parent[yroot] = xroot;
        rank[xroot]++;
    }
}

int compare(const void *a, const void *b)
{
    struct edge *a1 = (struct edge *)a;
    struct edge *b1 = (struct edge *)b;
    return a1->w > b1->w;
}

void kruskal(int n, int e)
{
    int i, j, k;
    struct edge result[n];
    qsort(edges, e, sizeof(edges[0]), compare);
    make_set(n);
    for (i = 0, j = 0; i < e && j < n - 1; i++)
    {
        int x = find(edges[i].u);
        int y = find(edges[i].v);
        if (x != y)
        {
            result[j++] = edges[i];
            union_set(x, y);
        }
    }
    printf("MST is:\n");
    for (i = 0; i < j; i++)
        printf("%d - %d : %d\n", result[i].u, result[i].v, result[i].w);
}

int main()
{
    int n, e, i;
    printf("Enter number of vertices: ");
    scanf("%d", &n);
    printf("Enter number of edges: ");
    scanf("%d", &e);
    edges = (struct edge *)malloc(e * sizeof(struct edge));
    printf("Enter edges (u v w):\n");
    for (i = 0; i < e; i++)
        scanf("%d %d %d\n", &edges[i].u, &edges[i].v, &edges[i].w);
    kruskal(n, e);
    return 0;
}
