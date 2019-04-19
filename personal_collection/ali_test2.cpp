/**
 * 这是阿里笔试中的一题。
消息同步时间端合并
题目描述
现在很多聊天软件为了方便用户多设备查看历史聊天记录，都提供了消息同步功能，即可以帮用户将A设备上的聊天记录同步到B机器，但是可能B机器已经同步过部分聊天记录，如果再次同步，会造成流量，服务器
资源浪费，为了解决这个问题客户端机器上存储了已经同步过的时间段集合(由于数据不可能一 -次性全部拉回来, 就造成了本地同步区间段非连续)，需要过滤掉这些区间， 筛选出需要同步的时间段，向服务器拉取
数据补齐,并将本次补齐的时间段和本地时间段Merge,并保障有序。下面针对同步后合并时间段逻辑进行实现。
输入描述
时间段为左闭右开区间，例如: [5-60)
输入1:本次同步的时间段
输入2:本地已经同步过的时间段(有序，无交叉)
输出描述
合并后的时间段(有序,无交叉)
输入1: [5-60)，[75-100), [120-160) 输入2: [70-90)输出: [5-60)， [70-100)， [120-160)
输入1: [5-60)，[75-100), [120-160) 输入2: [70-120)输出: [5-60), [70-160)
 */

#include <iostream>
#include <list>
#include <string>

struct TimeSegment
{
    uint64_t btime;
    uint64_t etime;
    TimeSegment() : btime(0), etime(0)
    {
    }
    TimeSegment(uint64_t btime_, uint64_t etime_) : btime(btime_), etime(etime_)
    {
    }
};

inline void MergeTimeSegment(uint64_t nBeginTime, uint64_t nEndTime, std::list<TimeSegment> &lstTimeSegment)
{
    //TODO
}

TimeSegment ParseTimeSegmentString(const std::string &input)
{
    TimeSegment timestamp;
    size_t nPos = input.find("-");
    size_t nLength = input.length();
    if (nPos > 0 && nPos < nLength)
    {
        try
        {
            timestamp.btime = std::stoull(input.substr(0, nPos));
            timestamp.etime = std::stoull(input.substr(nPos + 1, nLength));
        }
        catch (...)
        {
            std::cout << "请输入有效数据.\n";
        }
    }
    else
    {
        std::cout << "请输入有效数据.\n";
    }

    return timestamp;
}

std::list<TimeSegment> ParseTimeSegmentList(const std::string &input)
{
    TimeSegment timestamp;
    std::list<TimeSegment> lstTimestamp;
    std::string temp;
    size_t nStartPos = 0;
    size_t nEndPos = input.find(",");
    size_t nLength = input.length();
    while (nEndPos > nStartPos && nEndPos <= nLength)
    {
        temp = input.substr(nStartPos, nEndPos);
        if (temp.size() > 0)
        {
            timestamp = ParseTimeSegmentString(temp);
            lstTimestamp.push_back(timestamp);
        }
        nStartPos = nEndPos + 1;
        nEndPos = input.find(",", nStartPos);
        if (-1 == nEndPos)
        {
            nEndPos = nLength;
        }
    }

    return lstTimestamp;
}

int main(int argc, char *argv[])
{
    std::string input;
    std::cin >> input;
    int nPos = input.find(";");
    std::list<TimeSegment> lstTimestamp = ParseTimeSegmentList(input.substr(0, nPos));
    TimeSegment timestamp = ParseTimeSegmentString(input.substr(nPos + 1, input.size()));

    MergeTimeSegment(timestamp.btime, timestamp.etime, lstTimestamp);

    for (auto it = lstTimestamp.begin(); it != lstTimestamp.end();)
    {
        std::cout << it->btime << "-" << it->etime;
        if (++it != lstTimestamp.end())
        {
            std::cout << ",";
        }
    }

    return 0;
}