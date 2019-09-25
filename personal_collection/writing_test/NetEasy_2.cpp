#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

struct Tree
{
    int number;
    int val;
    int left_node;
    int flag;
    int right_node;
    int father_node = -1;
    struct Tree *left;
    struct Tree *right;
    struct Tree *father;
};

void check_tree(int root, struct Tree arr[])
{
    queue<struct Tree> que;
    que.push(arr[root]);
    while (!que.empty())
    {
        vector<struct Tree> temp;
        int cur_sum = 0;
        int next_sum = 0;
        while (!que.empty())
        {
            temp.push_back(que.front());
            que.pop();
            cur_sum += temp.back().val;

            // cout<<temp.back().number;
        }
        while (temp.size() != 0)
        {
            if (temp.back().left_node != -1)
            {
                next_sum += arr[temp.back().left_node].val;
                que.push(arr[temp.back().left_node]);
            }
            if (temp.back().right_node != -1)
            {
                next_sum += arr[temp.back().right_node].val;
                que.push(arr[temp.back().right_node]);
            }
            temp.pop_back();
        }
        if (cur_sum >= next_sum && next_sum > 0)
        {
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    while (t)
    {
        int num;
        cin >> num;
        int i, j;
        int root;
        struct Tree arr[1110];
        for (i = 0; i < num; i++)
        {
            cin >> arr[i].val >> arr[i].left_node >> arr[i].right_node;
            /*
            cin>>arr[i].left_node;
            cin>>arr[i].right_node;
            */
            arr[i].number = i;

            //if(arr[i].flag != 1)
            //arr[i].father_node = -1;
            arr[i].left = NULL;
            arr[i].right = NULL;
            //arr[i].father = NULL;

            if (arr[i].left_node != -1)
            {
                arr[i].left = &arr[arr[i].left_node];
                arr[arr[i].left_node].father_node = i;
                arr[arr[i].left_node].flag = 1;
                arr[arr[i].left_node].father = &arr[i];
            }

            if (arr[i].right_node != -1)
            {
                arr[i].right = &arr[arr[i].right_node];
                arr[arr[i].right_node].father_node = i;
                arr[arr[i].right_node].flag = 1;
                arr[arr[i].right_node].father = &arr[i];
            }
        }
        for (i = 0; i < num; i++)
        {
            if (arr[i].father_node == -1)
                root = i;
        }
        check_tree(root, arr);
        t--;
    }
    return 0;
}