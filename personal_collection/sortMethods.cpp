/**
 * 这是一个排序方法的集合
 * 均是从小到大的排序
 */
#include <iostream>
#include <vector>

using namespace std;

#pragma region Bubble Sort
/**
 * 稳定性：
 * 比较时>稳定，>= 不稳定
 * 时间：
 * O(n^2)
 * 空间：
 * O(1)
 */

/**
 * 最简单的冒泡排序
 * 每一趟最大位会到达最终位置
 */
void bubbleSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = 0; j < arr.size() - 1; j++)
        {
            if (arr[j] > arr[j + 1]) // > 稳定，>= 不稳定
                swap(arr[j], arr[j + 1]);
        }
    }
}
/**
 * 冒泡优化1
 * 每遍历完一次，看看是否已经提前完成了排序，用一个控制位记录
 */
void bubbleSort_1(vector<int> &arr)
{
    bool hasSorted = false;
    for (int i = 0; i < arr.size() - 1 && !hasSorted; i++)
    {
        hasSorted = true;
        for (int j = 0; j < arr.size() - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                hasSorted = false;
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

/**
 * 冒泡优化2
 * 每遍历完一次，最后面已经是最终排序了，不需要继续比较
 */
void bubbleSort_2(vector<int> &arr)
{
    int n = arr.size() - 1;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        int upto = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                upto = j;
                swap(arr[j], arr[j + 1]);
            }
        }
        n = upto;
        if (n == 0)
            break;
    }
}

/**
 * 冒泡优化3
 * 双向冒泡：最小的移到第一个，最大的移到最后
 */
void bubbleSort_3(vector<int> &arr)
{
    int begin = 0;
    int end = arr.size() - 1;
    while (begin < end)
    {
        int nbeg = begin;
        int nend = end;
        for (int i = begin; i < end; i++) //正向循环
        {
            if (arr[i] > arr[i + 1])
            {
                nend = i; //记录最后放在哪一位
                swap(arr[i], arr[i + 1]);
            }
        }
        if (nend == end)
            break;
        end = nend;

        for (int i = end; i > begin; i--) // 逆向循环
        {
            if (arr[i] < arr[i - 1])
            {
                nbeg = i;
                swap(arr[i], arr[i - 1]);
            }
        }
        if (nbeg == begin)
            break;
        begin = nbeg;
    }
}
#pragma endregion

#pragma region Quick Sort
/**
 * 稳定性：
 * 不稳定
 * 时间复杂度：
 *  最好情况，pivot都是中点：O(nlogn)
 *  最差情况，本来就是有序数列：O(n^2)
 * 空间复杂度：
 *  快排需要用到栈空间，基本上是O(n)，最优是O(logn)
 */
int partition1(vector<int> &arr, int begin, int end)
{
    int pivot = arr[begin];
    int l = begin + 1;
    int r = end;
    while (l <= r)
    {
        if (arr[l] < pivot)
            l++;
        else if (arr[r] > pivot)
            r--;
        else if (arr[l] >= pivot && arr[r] <= pivot)
            swap(arr[l++], arr[r--]);
    }
    swap(arr[r], arr[begin]);
    return r;
}
int partition2(vector<int> &arr, int begin, int end)
{
    int pivot = arr[begin];
    int index = begin + 1;
    for (int i = index; i <= end; i++)
    {
        if (arr[i] < pivot)
            swap(arr[i], arr[index++]);
    }

    swap(arr[index - 1], arr[begin]);
    return index - 1;
}
void quickSort(vector<int> &arr, int begin, int end)
{
    if (begin < end)
    {
        int pivot = partition1(arr, begin, end);
        quickSort(arr, begin, pivot - 1);
        quickSort(arr, pivot + 1, end);
    }
}
/**
 * 优化1: 在小数组内使用插入排序
 * 优化2: 最好情况是每次都能取到中位数作为切分元素，但计算中位数代价过高，取三个元素并将大小居中的元素作为切分效果最好
 * 优化3: 队友有大量重复元素的数组，可以讲数组切分为三部分，小于、等于、大于
 */

/**
 * Top K变形：找出第k大的数位置
 */
int topK(vector<int> &arr, int begin, int end, int k)
{
    if (begin < end)
    {
        int pos = partition1(arr, begin, end);
        int number = end - pos + 1;
        int index = -1;
        if (number == k)
        {
            index = pos;
        }
        else if (number > k)
            index = topK(arr, pos + 1, end, k);
        else
            index = topK(arr, begin, pos - 1, k - number);
        return index;
    }
}
#pragma endregion

#pragma region Insertion Sort
/**
 * 稳定性：
 *  不稳定
 * 时间复杂度：
 *  最好情况：正向排序O(n)
 *  最差情况：逆序O(n^2)
 * 空间复杂度：
 *  O(1)
 */
void insertSort(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int temp = i;
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[temp] < arr[j])
                swap(arr[temp--], arr[j]);
        }
    }
}
/**
 * 优化1：找到当前元素该插入的位置后，再插入
 */
void insertSort_1(vector<int> &arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int temp = arr[i];
        int j = i - 1;
        for (; j >= 0 && temp < arr[j]; --j)
        {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}
#pragma endregion

#pragma region Shell Sort
/**
 * 稳定性：
 *  不稳定，可能由于分在不同组中而导致的不稳定
 * 时间复杂度：
 *  与增量有关，如果增量为1就是插入排序，O(n^2)，平均情况是O(nlogn)
 * 空间复杂度：
 *  O(1)
 */
void shellInsert(vector<int> &arr, int begin, int gap)
{
    for (int i = begin + gap; i < arr.size(); i += gap)
    {
        int temp = arr[i];
        int j = i - gap;
        for (; j >= 0 && temp < arr[j]; j -= gap)
        {
            arr[j + gap] = arr[j];
        }
        arr[j + gap] = temp;
    }
}
void shellSort(vector<int> &arr)
{
    int gap = arr.size() / 2;
    while (gap > 0)
    {
        int begin = gap - 1;
        while (begin >= 0)
        {
            shellInsert(arr, begin, gap);
            --begin;
        }
        gap /= 2;
    }
}
#pragma endregion

#pragma region Selection Sort
/**
 * 稳定性：
 *  稳定，后出现的相同元素只能一个相同元素swap后才能swap
 * 时间复杂度：
 *  无论好坏都是O(n^2)，每次都要选出最小的
 * 空间复杂度:O(1)
 */
void SelectionSort(vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        int m = arr[i];
        int index = i;
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[j] < m)
            {
                m = arr[j];
                index = j;
            }
        }
        swap(arr[i], arr[index]);
    }
}
#pragma endregion

#pragma region Merge Sort
/**
 * 稳定性：
 *  元素相等是不改变元素的前后位置，归并是稳定的
 * 时间复杂度：
 *  子序列分为母序列的一班 O(nlogn)
 * 空间复杂度：
 *  需要额外的空间存子序列 O(n)
 */
vector<int> merge(vector<int> a, vector<int> b)
{
    vector<int> res;
    int begin_a = 0;
    int begin_b = 0;
    while (begin_a < a.size() && begin_b < b.size())
    {
        if (a[begin_a] <= b[begin_b])
        {
            res.push_back(a[begin_a++]);
        }
        else
        {
            res.push_back(b[begin_b++]);
        }
    }

    if (begin_a == a.size())
    {
        while (begin_b < b.size())
        {
            res.push_back(b[begin_b++]);
        }
    }
    else if (begin_b == b.size())
    {
        while (begin_a < a.size())
        {
            res.push_back(a[begin_a++]);
        }
    }
    return res;
}
vector<int> mergeSort(vector<int> arr)
{
    int size = arr.size();
    if (size < 2)
        return arr;
    int mid = size / 2;
    vector<int> front(arr.begin(), arr.begin() + mid);
    vector<int> back(arr.begin() + mid, arr.end());
    return merge(mergeSort(front), mergeSort(back));
}
#pragma endregion

#pragma region Heap Sort
/**
 * 堆排序是简单选择排序的改进，选择排序每次选择一个最小的时候并没有把比较结果存下来，下次比较还是要再次比较
 * 1. 堆都是完全二叉树
 * 2. 大顶堆：每个节点的值都大于或等于左右孩子的值，根节点是最大的；小顶堆类似；
 * 3. 按照层序遍历，满足一下关系(1<=i<=[n/2])：
 *      1). k_i >= k_2i
 *      2). k_i >= k_2i+1
 * 稳定性：
 *  不稳定
 * 时间复杂度：
 *  O(nlogn)
 * 空间复杂度：
 *  O(1)
 */
void heapSortCore(vector<int> &v, int begin, int end)
{
    int parent = begin;
    int son = parent * 2 + 1;
    while (son <= end)
    {
        if (son + 1 <= end && v[son] < v[son + 1])
        {
            son++;
        }
        if (v[parent] > v[son])
        {
            return;
        }
        else
        {
            swap(v[parent], v[son]);
            parent = son;
            son = parent * 2 + 1;
        }
    }
}
void heapSort(vector<int> &v)
{
    int num = v.size();
    // 初始化，i从最后一个父节点从下向上开始调整
    for (int i = num / 2; i >= 0; --i)
    {
        heapSortCore(v, i, num - i);
    }
    // 将第一个元素和已经排好序的元素前一位做交换，再重新调整堆
    for (int i = num - 1; i >= 0; --i)
    {
        swap(v[0], v[i]);
        heapSortCore(v, 0, i - 1);
    }
}
#pragma endregion

#pragma region Counting Sort
/**
 * 统计待排序数列中每个数字的出现次数，填入数据结构的过程就是排序的过程
 * 稳定性：
 *  稳定
 * 时间复杂度：
 *  O(n+k), k为数字范围
 * 空间复杂度
 *  O(K)
 */
void countSort(vector<int> &arr, int range)
{
    vector<int> temp(range + 1, INT_MIN);
    for (int i = 0; i < arr.size(); i++)
    {
        temp[arr[i]]++;
    }
    int c = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        while (temp[c == INT_MIN])
            c++;
        arr[i] = c;
        temp[c]--;
    }
}
#pragma endregion

#pragma region Bucket Sort
/**
 * 基于计数排序，增加了函数映射，将元素归于不同的桶中进行排序
 * 相当于哈希表中的拉链法
 * 稳定性：
 *  稳定
 * 时间复杂度：
 *  最好 O(n+k)
 *  最差 O(n^2)
 * 空间复杂度
 *  O(n+k)
 */
#pragma endregion

#pragma region Radix Sort
/**
 * 基数排序是按照低位先排序，然后收集，再按照高位排序，直到最高位
 */
#pragma endregion