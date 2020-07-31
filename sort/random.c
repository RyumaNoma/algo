#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
    FILE* fp;
    fp = fopen("numbers.txt", "w");

    int N = atoi(argv[1]);
    fprintf(fp, "%d\n", N);

    srand((unsigned)time(NULL));
    for (int i = 0; i < N; i++)
    {
        fprintf(fp, "%d\n", rand());
    }
    
    fclose(fp);
}