/*입력 : 첫째 줄에 트리의 노드의 개수 N이 주어진다. N은 50보다 작거나 같은 자연수이다. 
둘째 줄에는 0번 노드부터 N-1번 노드까지, 각 노드의 부모가 주어진다. 
만약 부모가 없다면 (루트) -1이 주어진다. 셋째 줄에는 지울 노드의 번호가 주어진다.*/

/*출력 : 첫째 줄에 입력으로 주어진 트리에서 입력으로 주어진 노드를 지웠을 때, 리프 노드의 개수를 출력한다.*/

#include <stdio.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> graph[55];
int N;
int rootNode;
int delNode;
int leafCnt;

void find_leaf(int node)
{
    if (graph[node].size() == 0)
    {
        leafCnt++;
    }

    for (int i = 0; i < graph[node].size(); i++)
    {
        // 현재노드의 자식이 삭제할 노드이고, 
        if (graph[node][i] == delNode)
        {
            // 현재노드의 자식이 1개 밖에 없으면, 현재 노드의 자식을 삭제할 경우 그 현재 노드가 리프노드가 됨 
            if (graph[node].size() == 1)
            {
                leafCnt++;
            }

            continue;
        }

        find_leaf(graph[node][i]);
    }
}

int main(void)
{
    //    freopen("B1068_input.txt", "r", stdin);

    cin >> N;

    for (int to = 0; to < N; to++)
    {
        int from;
        cin >> from;

        if (from == -1)
        {
            rootNode = to;

            continue;
        }
        else
        {
            graph[from].push_back(to);
        }
    }

    cin >> delNode;

    if (delNode == rootNode)
    {
        cout << "0";
    }
    else
    {
        find_leaf(rootNode);
        cout << leafCnt;
    }

    return 0;
}

