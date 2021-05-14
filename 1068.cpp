/*�Է� : ù° �ٿ� Ʈ���� ����� ���� N�� �־�����. N�� 50���� �۰ų� ���� �ڿ����̴�. 
��° �ٿ��� 0�� ������ N-1�� ������, �� ����� �θ� �־�����. 
���� �θ� ���ٸ� (��Ʈ) -1�� �־�����. ��° �ٿ��� ���� ����� ��ȣ�� �־�����.*/

/*��� : ù° �ٿ� �Է����� �־��� Ʈ������ �Է����� �־��� ��带 ������ ��, ���� ����� ������ ����Ѵ�.*/

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
        // �������� �ڽ��� ������ ����̰�, 
        if (graph[node][i] == delNode)
        {
            // �������� �ڽ��� 1�� �ۿ� ������, ���� ����� �ڽ��� ������ ��� �� ���� ��尡 ������尡 �� 
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

