#include <iostream>
#include <cstdio>

void bubble_sort(int* a, int N);
void swap(int* a, int* b);

int main(int argc, char** argv)
{
    FILE* input;
    if((input = fopen("../numbers.txt", "r")) == NULL)
    {
        std::cout << "../numbers.txt does not exist." << std::endl;
        return 0;
    }

    int N;
    fscanf(input, "%d", &N);

    int a[N];
    for (int i = 0; i < N; i++)
    {
        int num;
        fscanf(input, "%d", &num);
        a[i] = num;
    }

    fclose(input);

    // sort
    bubble_sort(a, N);

    // Sorted array 出力
    FILE* output = fopen("../sorted.txt", "w");

    for (int i = 0; i < N; i++)
    {
        fprintf(output, "%d\n", a[i]);
    }

    fclose(output);

    return 0;
}

void bubble_sort(int* a, int N)
{
    for (int i = 0; i < N - 1; i++)
    {
        for(int j = i + 1; j < N; j++)
        {
            if(a[i] > a[j])
            {
                swap(&a[i], &a[j]);
            }
        }
    }
    
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}