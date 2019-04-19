/**
 * 这是阿里笔试中的一题。
 * 
俗话说:时间像海绵里的水，挤-挤总会有的。从数据存储的角度看，存储空间也是如此。在大数据时代，十亿百亿级别的业务数据规模也不再鲜见，存储优化的脚步也从未停歇。
假设在某种业务场景下，数据表内有若干条记录，每条记录的内容是N个uin32 (无符号4字节) 整数(N <= 1000)，每个整 数描述了一个特定的业务字段，且每个字段都有自己特定的值域范围。
一种存储优化的思路是:对单条记录进行编码压缩。已知业务字段的值域范围，则可以利用值域范围的最大值对应的bit位宽信息(例如字段值域空间最大值是7,则对应存储位宽是3个bit),实际用位 宽对应的bit位
数的数据空间代替原始类型长度(4字节)存储空间，即可完成数据存储目标。
基于以上思路,压缩存储的需求目标描述如下:
1.将N个uint32整数,按照值域空间内最大值的bit位宽，压缩存储到M (M<=N) 个uint32整数组 成的数组中。
2.基于数据读写原子性考虑，每个压缩前的整数，存储位置- -定在压缩后数组内的某 个元素内，不可以跨两个相邻的数组元素
编码存储示例:
假设由6个字段组成的单条记录，每个字段的位宽信息依次为{4, 2, 31, 15, 5, 11}
编码后的位宽分布为{31}, {15, 4, 11,2}, {5}
其中第一个字段(bitLen=4) 的字段所在位置是: block下标=1, block内bit下标=15,
.....
存储空间: M个uint32整数
在已知每个字段bit位宽信息的前提下，请编码实现
1.设计算法给出对N个字段的最优(M值最小)压缩存储方案，压缩方案中需要给出每个字段在压缩数组中的存储位置信息(实际存储的整数下标，以及字段在目标整数内存储的bit起始位置)
2.基于压缩存储方案描述信息(每个字段的存储位置信息)，实现对每 个字段的存取接口(set/get)
 */

#include <stdint.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
#include <limits>

using namespace std;

struct FieldStorePosition
{
    int blockIndex;            // 压缩数组的整数下标（从0开始）
    int inBlockBitPos;         // 对应下标内的bit位置（存储开始位置0～31）
    int bitLen;                // bit位宽长度
};

struct StorePlan
{
    std::vector<FieldStorePosition> fieldStorePosVec;    // 每个字段对应的存储位置信息
    int storeVectorSize;                                                       // 存储数组的元素个数
};

class BitStoreAccessor
{
public:
    bool init(const vector<int>& bitLengthVector) {
        _plan = generateStorePlan((int*)bitLengthVector.data(), bitLengthVector.size());
        return _plan.fieldStorePosVec.size() == bitLengthVector.size();
    }

    int getStoreVectorSize() const { return _plan.storeVectorSize; }

public:
    bool setFieldValue(vector<uint32_t> &storeAddress, int fieldIndex,  uint32_t value);
    bool getFieldValue(const vector<uint32_t> &storeAddress, int fieldIndex,  uint32_t &value);

private:
    StorePlan generateStorePlan(int *bitLengthVector, int fieldCount);
private:
    StorePlan _plan;
};

/** 请完成下面这个函数，实现题目要求的功能 **/
bool BitStoreAccessor::setFieldValue(
        vector<uint32_t> &storeAddress, int fieldIndex,  uint32_t value)
{
    // assert(false);
    return false;
}

bool BitStoreAccessor::getFieldValue(
        const vector<uint32_t> &storeAddress, int fieldIndex,  uint32_t &value)
{
    // assert(false);
    return false;
}

StorePlan BitStoreAccessor::generateStorePlan(int *bitLengthVector, int fieldCount)
{
    StorePlan plan;
    // assert(false);
    return plan;
}

/** 请完成上面的函数实现 **/


vector<string> splitString(const string& text, const string &sepStr)
{
    vector<string> vec;
    string str(text);
    string sep(sepStr);
    size_t n = 0, old = 0;
    while (n != string::npos)
    {
        n = str.find(sep,n);
        if (n != string::npos)
        {
            vec.push_back(str.substr(old, n-old));
            n += sep.length();
            old = n;
        }
    }
    vec.push_back(str.substr(old, str.length() - old));
    return vec;
}
template <typename T>
bool stringToInteger(const string& text, T& value)
{
    const char* str = text.c_str();
    char* endPtr = NULL;
    value = (T)strtol(str, &endPtr, 10);
    return (endPtr && *endPtr == 0);
}

bool testBitStore(string fieldBitInfoStr, string setValueString, int expectStoreVectorSize) {
    vector<string> bitLenStrVec = splitString(fieldBitInfoStr, ",");
    vector<int> bitLengthVector;
    bitLengthVector.resize(bitLenStrVec.size());
    for (size_t i = 0; i < bitLenStrVec.size(); i++) {
        if (!stringToInteger<int>(bitLenStrVec[i], bitLengthVector[i]))
        {
            return false;
        }
    }

    BitStoreAccessor accessor;
    if (!accessor.init(bitLengthVector))
    {
        return false;
    }

    // check store size
    if (expectStoreVectorSize != accessor.getStoreVectorSize()) {
        return false;
    }

    // prepare store vector
    vector<uint32_t> storeVector;
    storeVector.resize(accessor.getStoreVectorSize());

    if (setValueString.empty())
    {
        return true;
    }
    // test set & get value
    vector<string> setValueStrVec = splitString(setValueString, ";");
    for (size_t i = 0; i < setValueStrVec.size(); i++) {
        vector<string> singleSetValueInfo = splitString(setValueStrVec[i], ":");
        if (singleSetValueInfo.size() != 2) {
            return false;
        }

        int fieldIdx = 0;
        uint32_t value = 0;
        if (!stringToInteger<int>(singleSetValueInfo[0], fieldIdx) ||
            !stringToInteger<uint32_t>(singleSetValueInfo[1], value))
        {
            return false;
        }
        if (!accessor.setFieldValue(storeVector, fieldIdx, value)) {            
            return false;
        }
        uint32_t actualValue = 0;
        if (!accessor.getFieldValue(storeVector, fieldIdx, actualValue)) {
            return false;
        }
        if (actualValue != value) {
            return false;
        }
    }
    return true;
}

int main() {
    bool res;

    string _bitLenVectorString;
    getline(cin, _bitLenVectorString);
    string _setValueString;
    getline(cin, _setValueString);
    int _expectStoreVectorSize;
    cin >> _expectStoreVectorSize;
    cin.ignore (std::numeric_limits<std::streamsize>::max(), '\n');

    res = testBitStore(_bitLenVectorString, _setValueString, _expectStoreVectorSize);
    if (res)
    {
        cout << "PASS" << endl;
    }
    else
    {
        cout << "FAIL" << endl;
    }
    return 0;
}