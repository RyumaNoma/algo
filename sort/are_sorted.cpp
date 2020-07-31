#include <iostream>

int main(void)
{
    FILE* fp;

    if((fp = fopen("sorted.txt", "r")) == NULL)
    {
        std::cout << "sorted.txt does not exist." << std::endl;
        return 0;
    }

    int N;
    fscanf(fp, "%d", &N);

    int last = -1;
    int now = -1;
    bool flag = true;
    for (int i = 0; i < N; i++)
    {
        fscanf(fp, "%d", &now);

        if(now < last)
        {
            flag = false;
            break;
        }
    }
    
    if(flag)
    {
        std::cout << "Numbers are sorted." << std::endl;
    }
    else
    {
        std::cout << "Numbers are not sorted." << std::endl;
    }
}