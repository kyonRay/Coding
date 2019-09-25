#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>
#include <iomanip>
#include <string>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

class Ticket
{
public:
    string flight;
    string seat;
    string name;
    bool changed = false;
    void readTheTicket();
    const Ticket &operator&=(const Ticket &t)
    {
        this->flight = t.flight;
        this->seat = t.seat;
        this->name = t.name;
    }
    void writeTicket(string s);
};
class ExchangeTicket
{
public:
    string fromFlight;
    string fromSeat;
    string toFlight;
    string toSeat;
    void writeET(string s);
};

void Ticket::readTheTicket()
{
    cout << flight << "," << seat << "," << name << endl;
}
void Ticket::writeTicket(string s)
{
    string temp;
    int dot1, dot2;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ',')
        {
            dot1 = i;
            break;
        }
    }
    this->flight = s.substr(0, dot1);
    for (int i = dot1 + 1; i < s.length(); i++)
    {
        if (s[i] == ',')
        {
            dot2 = i;
            break;
        }
    }
    this->seat = s.substr(dot1 + 1, dot2 - dot1 - 1);
    this->name = s.substr(dot2 + 1, s.length() - 1 - dot2);
}

void ExchangeTicket::writeET(string s)
{
    string temp;
    int dot1, dot2, dot3;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ',')
        {
            dot1 = i;
            break;
        }
    }
    this->fromFlight = s.substr(0, dot1);
    for (int i = dot1 + 1; i < s.length(); i++)
    {
        if (s[i] == ',')
        {
            dot2 = i;
            break;
        }
    }
    this->fromSeat = s.substr(dot1 + 1, dot2 - dot1 - 1);
    for (int i = dot2 + 1; i < s.length(); i++)
    {
        if (s[i] == ',')
        {
            dot3 = i;
            break;
        }
    }
    this->toFlight = s.substr(dot2 + 1, dot3 - dot2 - 1);
    this->toSeat = s.substr(dot3 + 1, s.length() - 1 - dot3);
}
bool cmp(Ticket &t1, Ticket &t2)
{
    bool flag;
    if (t1.flight == t2.flight)
    {
        flag = t1.seat > t2.seat;
    }
    else
    {
        flag = t1.flight > t2.flight;
    }
    return !flag;
}
int main(int argc, char const *argv[])
{
    int N;
    cin >> N;
    string temp;
    vector<Ticket> ts;
    for (int i = 0; i < N; i++)
    {
        Ticket t1;
        cin >> temp;
        t1.writeTicket(temp);
        ts.push_back(t1);
    }
    int M;
    cin >> M;
    vector<ExchangeTicket> etv;
    for (int i = 0; i < M; i++)
    {
        ExchangeTicket et;
        cin >> temp;
        et.writeET(temp);
        etv.push_back(et);
    }
    vector<Ticket> res;
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (ts[j].flight == etv[i].fromFlight && ts[j].seat == etv[i].fromSeat)
            {
                ts[j].changed = true;
                Ticket newTicket = ts[j];
                newTicket.flight = etv[i].toFlight;
                newTicket.seat = etv[i].toSeat;
                res.push_back(newTicket);
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (!ts[i].changed)
            res.push_back(ts[i]);
    }
    sort(res.begin(), res.end(), cmp);
    for (int i = 1; i < res.size(); i++)
    {
        if (res[i].flight == res[i - 1].flight && res[i].seat == res[i - 1].seat)
        {
            res.erase(res.begin() + i);
        }
    }
    for (int i = 1; i < res.size(); i++)
    {
        if (res[i].flight == res[i - 1].flight && res[i].name == res[i - 1].name)
        {
            res.erase(res.begin() + i);
        }
    }

    for (int i = 0; i < N; i++)
    {
        res[i].readTheTicket();
    }

    return 0;
}

/* 
3
CZ7132 A1 ZHANGSAN
CZ7132 A2 ZHAOSI
CZ7156 A2 WANGWU
2
CZ7132 A1 CZ7156 A2
CZ7156 A2 CZ7156 A3
*/