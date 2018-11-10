#include<stdio.h>
#include<stdlib.h>
int s = 10;
int g[10][10], v[10];
void dfs(int i)
{
    int j;
    printf("%d ", i+1);
    v[i] = 1;
    for(j = 0; j < s; j++)
        if(v[j] == 0 && g[i][j] == 1)
            dfs(j);
}
int stack[10], top = -1, flag = 0;
void dfspath(int a, int b, int q)
{
    int j;
    if(v[a-1] == 0)
    {
        top++; stack[top] = a;
    }
    v[a-1] = 1;
    if(v[b-1] == 1 && flag == 0)
    {
        for(int k = 0; k < top+1; k++)
            printf("%d ", stack[k]);
        printf("\n");
        flag = 1;
    }
    for(j = 0; j < q; j++)
        if(v[j] == 0 && g[a-1][j] == 1)
        {
            dfspath(j+1, b, q);
            top--;
        }
}
int main()
{
    int q, a;
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
    for(int i = 0; i < q; i++)
        v[i] = 0;
    scanf("%d", &a);
    dfs(a-1); 
    printf("\n");
    for(int i = 0; i < q; i++)
        v[i] = 0;
    dfspath(2, 4, q); // Sample path between 2 and 4
    if(v[3] == 0) printf("Not found"); // v[3] is visited value of 4
    printf("\n");
    return 0;
}
