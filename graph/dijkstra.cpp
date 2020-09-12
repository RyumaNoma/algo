#include <iostream>
#include <queue>
#include <vector>

const int INF = 10000;

int main(void)
{
    int N, M;
    std::cin >> N >> M;
    int start, goal;
    int edge[M][M];
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < M; j++)
        {
            edge[i][j] = -1;
        }
        
    }
    
    for (int i = 0; i < M; i++)
    {
        int a, b, c;
        std::cin >> a >> b >> c;
        a--;
        b--;
        edge[a][b] = edge[b][a] = c;
    }
    std::cin >> start;
    start--;
    std::cin >> goal;
    goal--;

    std::queue<int> que;
    bool visited[N];
    for (int i = 0; i < N; i++)
    {
        visited[i] = false;
    }
    int cost[N];
    for (int i = 0; i < N; i++)
    {
        cost[i] = INF;
    }
    int before[N];
    for (int i = 0; i < N; i++)
    {
        before[i] = -1;
    }
    
    
    que.push(start);
    visited[start] = true;
    cost[start] = 0;

    while (!que.empty())
    {
        int now = que.front();
        que.pop();

        for (int i = 0; i < M; i++)
        {
            if(visited[i]) continue;

            if (edge[now][i] >= 0)
            {
                if (cost[now] + edge[now][i] < cost[i])
                {
                    cost[i] = cost[now] + edge[now][i];
                    before[i] = now;
                }

                if (goal != i)
                {
                    que.push(i);
                    visited[i] = true;
                    // std::cout << "pushed " << i + 1 << " from " << now + 1 << std::endl;
                }
            }
            
        }
        
    }

    std::vector<int> route;
    int idx = 0;
    route.push_back(goal);

    while (before[route[idx]] != -1)
    {
        route.push_back(before[route[idx++]]);
    }

    for (int i = idx; i >= 0; i--)
    {
        std::cout << route[i] + 1;
        if (i != 0)
        {
            std::cout << " -> ";
        }
        
    }
    std::cout << std::endl;
    
    std::cout << cost[goal] << std::endl;
}