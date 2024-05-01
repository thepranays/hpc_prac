#include <stdio.h>
#include <time.h>
#define sz 800
void solve()
{
    int mat1[sz][sz];
    int mat2[sz][sz];
    int mat3[sz][sz];
    for (int i = 0; i < sz; i++)
    {
        for (int j = 0; j < sz; j++)
        {
            mat3[i][j] = 0;
            for (int k = 0; k < sz; k++)
            {
                mat3[i][j] += mat1[i][k] * mat2[k][k];
            }
        }
    }
}
int main()
{
    clock_t start, end;
    start = clock();
    solve();
    end = clock();


    double time_taken = ((double)end - start) / CLOCKS_PER_SEC;
    printf("Time taken by program is : %f sec\n", time_taken);
    return 0;	
}
