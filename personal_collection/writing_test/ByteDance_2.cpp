#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

struct Node
{
    int wat[3], step;
    Node(int a, int b, int c, int d)
    {
        wat[0] = a, wat[1] = b, wat[2] = c, step = d;
    };
};

int hashCode(Node n)
{
    return 10000 * n.wat[0] + 100 * n.wat[1] + n.wat[2];
}

int main()
{
    int wat[3], tar;
    cin >> wat[0] >> wat[1] >> wat[2] >> tar;
    if (tar > wat[0] + wat[1] + wat[2])
    {
        cout << -1 << endl;
        return 0;
    }
    queue<Node> que;
    que.push(Node(0, 0, 0, 0));
    unordered_set<int> hashSet;
    hashSet.insert(0);
    while (!que.empty())
    {
        Node cur = que.front();
        que.pop();
        if (cur.wat[0] == tar || cur.wat[1] == tar || cur.wat[2] == tar)
        {
            cout << cur.step << endl;
            return 0;
        }

        // 直接倒满或倒空
        for (int i = 0; i < 3; i++)
        {
            Node tem = cur;
            tem.wat[i] = 0;
            tem.step++;
            if (hashSet.find(hashCode(tem)) == hashSet.end())
            {
                hashSet.insert(hashCode(tem));
                que.push(tem);
            }
            tem.wat[i] = wat[i];
            if (hashSet.find(hashCode(tem)) == hashSet.end())
            {
                hashSet.insert(hashCode(tem));
                que.push(tem);
            }
        }
        for (int i = 0; i < 3; i++)
            for (int j = 0; j < 3; j++)
            {
                if (i == j || cur.wat[i] == 0 || cur.wat[j] == wat[j])
                    continue;
                Node tem = cur;
                tem.step++;
                int canPour = wat[j] - tem.wat[j];
                if (tem.wat[i] >= canPour)
                {
                    tem.wat[j] = wat[j];
                    tem.wat[i] -= canPour;
                }
                else
                {
                    tem.wat[j] += tem.wat[i];
                    tem.wat[i] = 0;
                }
                if (hashSet.find(hashCode(tem)) == hashSet.end())
                {
                    hashSet.insert(hashCode(tem));
                    que.push(tem);
                }
            }
    }
    cout << -1 << endl;
    return 0;
}