#include <cstring>
#include <cstdio>

class CMyString
{
public:
    CMyString(char *pData = nullptr);
    CMyString(const CMyString &str);
    ~CMyString(void);

    // 返回引用才可以连续赋值
    CMyString &operator=(const CMyString &str);

private:
    char *m_pData;
};

CMyString::CMyString(char *pData = nullptr)
{
    if (pData == nullptr)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        int length = strlen(pData);
        m_pData = new char[length + 1];
        strcpy(m_pData, pData);
    }
}

CMyString::CMyString(const CMyString &str)
{
    int length = strlen(str.m_pData);
    m_pData = new char[length + 1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(){
    delete[] m_pData;
}

CMyString &CMyString::operator=(const CMyString &str)
{
    if (this != &str)
    {
        CMyString strTemp(str);
        char *temp = str.m_pData;
        strTemp.m_pData = m_pData;
        m_pData = temp;
    }
    return *this;
}
