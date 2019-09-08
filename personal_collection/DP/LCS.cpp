/**
 * 最长公共子序列问题
 * 
 * c[i,j]={
 * 0, i=0&&j=0
 * c[i-1,j-1]+1, i,j>0 && x_i==y_j
 * max(c[i,j-1],c[i-1,j]), i,j>0 && x_i!=y_j
 */

#include <iostream>
#include <string>

using namespace std;

