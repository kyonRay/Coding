/**
 * 在面试时遇到了手撕源代码的题目，一时间写不出来
 * 痛定思痛，整理一下
 * 
 * void	*memcpy(void *__dst, const void *__src, size_t __n); 
 * 
 * void	*memmove(void *__dst, const void *__src, size_t __len);
 * 
 * char	*strcpy(char *__dst, const char *__src);
 * 
 * int atoi(const char *);
 * 
 * shared_ptr
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/**
 * memcpy
 * 还有优化的方法是多字节进行拷贝：
 *  在地址不对齐的情况下是一字节一字节地拷贝，在地址对齐以后，使用CPU字长来拷贝，例如
 *  在对void* 指针进行强制转换的时候，不是用char，而是用int类型，计算出n有多少个4字节，剩余的字节按字节拷贝
 */
void *myMemcpy(void *__dst, const void *__src, size_t __n)
{
    if (__dst == NULL || __src == NULL)
        return NULL;
    char *pdest = static_cast<char *>(__dst);
    const char *psrc = static_cast<const char *>(__src);
    size_t n = __n;

    /**
     * 如果存在内存重叠：dest的地址 > src，且src的地址加上n还小于dest，那就说明从小到大到最后会被覆盖
     */
    if (pdest > psrc && pdest < psrc + __n)
    {
        for (size_t i = n - 1; i != -1; i++)
        {
            pdest[i] = psrc[i];
        }
    }
    else
    {
        // 如果存在内存重叠，dest<src 且dest+n的地址大于src，那么下面的方法也可以解决
        for (size_t i = 0; i < n; i++)
        {
            pdest[i] = psrc[i];
        }
    }
    return __dst;
}

void *myMemmove(void *__dst, const void *__src, size_t __len)
{
}

int myAtoi(char *str)
{
    int minus = 1;
    long long result = 0;
    if (str == NULL)
    {
        return 0;
    }
    while (*str == ' ')
    {
        str++;
    }
    if (*str == '-')
    {
        minus = -1;
        str++;
    }
    else if (*str == '+')
        str++;
    // 检查异常输入 -aaa类型
    if (*str < 0 || *str > 9)
        return 0;
    while (*str >= 0 && *str <= 9)
    {
        result = result * 10 + ((*str++) - '0');
        // 检查溢出int范围
        if ((minus == 1 && result > INT_MAX + 1LL) || (minus == -1 && (result * minus) < INT_MIN))
        {
            // 理论上应该把溢出的部分输出的
            return 0;
        }
    }
    return (int)(minus * result);
}
