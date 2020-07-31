#include <iostream>
#include <stdlib.h>
#include <vector>

int binary_search(std::vector<int> v, int key);

// argv[1] ... N
// argv[2] ... key
int main(int argc, char** argv)
{
    int N = atoi(argv[1]);
    std::vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        a[i] = i;
    }

    std::cout << binary_search(a, atoi(argv[2])) << std::endl;
}

int binary_search(std::vector<int> v, int key)
{
    int ans = -1;
    int left = 0;
    int right = v.size() - 1;

    while(right - left > 1)
    {
        int mid = (left + right) / 2;

        if(key == v[mid])
        {
            ans = mid;
            break;
        }
        else if(key > v[mid])
        {
            left = mid;
        }
        else
        {
            right = mid;
        }
    }

    return ans;
}