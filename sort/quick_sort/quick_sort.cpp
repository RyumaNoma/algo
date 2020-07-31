#include <iostream>
#include <cstdio>

int quick_sort(int* a, int N, int start, int end);
void swap(int* a, int* b);

int main(void)
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
    quick_sort(a, N, 0, N - 1);

    // Sorted array 出力
    FILE* output = fopen("../sorted.txt", "w");

    for (int i = 0; i < N; i++)
    {
        fprintf(output, "%d\n", a[i]);
    }

    fclose(output);

    return 0;
}

int quick_sort(int* a, int N, int start, int end)
{
    // 最初の要素をピボットにする
    int pivot = a[start];

    int start_i = start;
    int end_i = end;

    int line = start;

    while(start_i < end_i)
    {
        // 最初からpivot以上の要素を探す
        while(start_i < end_i && a[start_i] < pivot)
        {
            start_i ++;
        }

        // 後ろからpivot未満の要素を探す
        while(start_i < end_i && a[end_i] >= pivot)
        {            
            end_i --;
        }

        if(start_i < end_i)
        {
            line = start_i;
            // printf("swaped %d & %d\n", a[start_i], a[end_i]);
            swap(&a[start_i++], &a[end_i--]);
        }        
    }

    if(a[start] != a[line])
    {
        quick_sort(a, N, start, line);
    }
    if(a[line + 1] != a[end])
    {
        quick_sort(a, N, line + 1, end);
    }

    return 1;
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}