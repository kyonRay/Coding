#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    vector<int> stage;
    while (n--)
    {
        string cur;
        cin >> cur;
        if (cur[0] == '<')
            stage.emplace_back(-2);
        else if (cur[0] == '>')
            stage.emplace_back(-3);
        else
            stage.emplace_back(stoi(cur));
    }
    while (q--)
    {
        int start, end;
        cin >> start >> end;
        vector<int> cur_stage(stage.begin() + start - 1, stage.begin() + end);
        int i = 0, score = 0, direct = 1;
        bool flag = false;
        while (i >= 0 && i < cur_stage.size())
        {
            if (cur_stage[i] > 0)
            {
                flag = false;
                score += cur_stage[i];
                cur_stage[i]--;
            }
            else if (cur_stage[i] != 0)
            {
                if (!flag)
                {
                    if (cur_stage[i] == -2)
                        direct = 0;
                    else
                        direct = 1;
                    flag = true;
                }
                else
                    cur_stage[i] = 0;
            }
            if (direct)
                i++;
            else
                i--;
        }
        cout << score << endl;
    }
    system("pause");
    return 0;
}