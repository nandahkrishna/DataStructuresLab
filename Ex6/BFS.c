#include<stdio.h>
#include<stdlib.h>
int s = 10, f = 0, r = -1, flag=0;
void bfs(int g[][s], int v[], int qu[], int i, int q)
{
    printf("%d ", i+1);
    v[i] = 1;
    if(f == 0 || qu[f] != 0)
    {
        for(int j = 0; j < q; j++)
            if(v[j] == 0 && g[i][j] == 1)
            {
                r++;
                qu[r] = j+1;
                v[j] = 1;
            }
        int j = qu[f] - 1;
        f++;
        bfs(g,v,qu,j,q);
    }
}
void bfspath(int g[][s], int v[], int qu[], int a, int b, int q)
{
    int root = a;
    v[a-1] = 1;
    if(flag == 0)
    {
        for(int j = 0; j < q; j++)
            if(v[j] == 0 && g[a-1][j] == 1)
            {
                r++; 
                qu[r] = j + 1; 
                v[j] = 1;
            }
        if(v[b-1] == 1) 
        {
          flag = 1; 
          printf("%d ",b); 
        }
        else 
        {
            int t = qu[f];
            f++; 
            bfspath(g,v,qu,t,b,q);
        }
    }
    if(flag == 1)
    {
        printf("%d ",root);
    }
}
int main()
{
    int g[s][s], v[s], q, a;
    scanf("%d", &q);
    for(int i = 0; i < q; i++)
        for(int j = i; j < q; j++)
        {
            if(i == j)
                g[i][j]=0;
            else
            {
                a = rand()%2;
                g[i][j] = g[j][i] = a;
            }
        }
    for(int i = 0; i < q; i++)
    {
        for(int j = 0; j < q; j++)
            printf("%d ", g[i][j]);
        printf("\n");
    }
    int qu[q];
    for(int i = 0; i < q; i++)
        v[i] = qu[i] = 0;
    scanf("%d", &a);
    bfs(g,v,qu,a-1,q);
    for(int i = 0; i < q; i++)
        if(v[i] == 0)
        {
            v[i] = 1;
            r++;
            qu[r] = i+1;
        }
    while(qu[f] != 0)
    {
        printf("%d ", qu[f]);
        f++;
    }
    printf("\n");
    for(int j = 0; j < q; j++) v[j] = qu[j] = 0;
    f = 0; r = -1; flag = 0;
    bfspath(g,v,qu,2,5,q); printf("\n"); // Sample path from 2 to 5
    if(flag == 0) printf("Not found");
    return 0;
}
