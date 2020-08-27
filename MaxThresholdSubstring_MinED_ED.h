#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits.h>
#include <iomanip> 
#include <fstream>
using namespace std;
int minOfTreeNum(int a, int b, int c)
{
	int minNum = a;
	if (minNum > b)
	{
		minNum = b;
	}
	if (minNum > c)
	{
		minNum = c;
	}
	return minNum;
}
int f(int a, int b, vector< vector<int> >& matrix, string& x, string& y)
{
	if (a == 0 || b == 0) return false;
	if (x[a-1] != y[b-1])
	{
		int temp1 = minOfTreeNum(matrix[a - 1][b - 1] + 1, matrix[a - 1][b] + 1, matrix[a][b - 1] + 1);
		if (temp1 == matrix[a][b - 1] + 1 && f(a, b - 1, matrix, x, y)) return true;
		if (temp1 == matrix[a - 1][b] + 1 && f(a - 1, b, matrix, x, y)) return true;
		if (temp1 == matrix[a - 1][b -1] + 1 && f(a - 1, b - 1, matrix, x, y)) return true;
		return false;
	}
	else
	{
		return true;
	}
}
int levenSTDistance(string x, string y, int t, int ii, vector< vector<int> >& result, vector< vector<int> >& result1, vector< vector<int> >& result2, int& min)
{
	const int lenx = x.length();
	const int leny = y.length();
	vector< vector<int> > levenST(lenx + 1, vector<int>(leny + 1, -1));
	vector<int> temp(2, -1);
	int eq = 0;
	int i, j;
	for (i = 0; i <= lenx; i++)
	{
		levenST[i][0] = i;
	}
	for (j = 0; j <= leny; j++)
	{
		levenST[0][j] = j;
	}

	for (i = 1; i <= lenx; i++)
	{
		for (j = 1; j <= leny; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				eq = 0;
			}
			else{
				eq = 1;
			}
			levenST[i][j] = minOfTreeNum(levenST[i - 1][j] + 1, levenST[i][j - 1] + 1, levenST[i - 1][j - 1] + eq);
		}
	}
	int start = lenx - t <= 1 ? 1 : lenx - t;
	for (int j = 1; j <= leny; j++)
	{
		temp[0] = ii;
		temp[1] = ii + j - 1;
		if (levenST[lenx][j] < min)
		{
			min = levenST[lenx][j];
			result1.clear();
			result1.push_back(temp);
			continue;
		}
		if (levenST[lenx][j] == min && find(result1.begin(), result1.end(), temp) == result1.end())
		{
			result1.push_back(temp);
		}
	}
	for (int j = start; j <= leny; j++)
	{
		if (levenST[lenx][j] == t)
		{
			temp[0] = ii;
			temp[1] = ii + j - 1;
			result.push_back(temp);
			if (f(lenx, j, levenST,x,y))
			result2.push_back(temp);
		}
	}
	return 1;
}
void edit_main(string&  query_str, string& test_str, int& t,int& min,vector< vector<int> >& result, vector< vector<int> >& result1, vector< vector<int> >& result2)
{
	int m = query_str.size();
	int n = test_str.size();
	for (int i = 0; i < n; i++)
	{
		int end = i + m + t - 1 >= n ? n - 1 : i + m + t - 1;
		levenSTDistance(query_str, test_str.substr(i, end - i + 1), t, i, result, result1, result2, min);
	}
}
int min_SED(string r, string s)//计算子串匹配的最小编辑距离sed_min
{
    int result=INT_MAX;
	if(r.length()<s.length())
	{
		int m=r.size();
		int n=s.size();
		int **D = new int*[m+1];
		for(int i = 0; i < m+1; i++)
			D[i] = new int[n+1]; 
	
		for(int j=0;j<=n;j++)
			D[0][j]=0;
		for(int i=1;i<=m;i++)
			D[i][0]=i;
		int equal=0;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
			{
				if(r[i-1]==s[j-1])
					equal=0;
				else
					equal=1;
	
				D[i][j]=minOfTreeNum(D[i][j-1]+1,D[i-1][j]+1,D[i-1][j-1]+equal);
				if(i==m&&D[i][j]<=result)
					result=D[i][j];
	
			}
		for(int i = 0; i < m+1; i++)
			delete[] D[i];
			delete[] D;
	    return result;
	}
	else
	{
		int m=s.size();
		int n=r.size();
		int **D = new int*[m+1];
		for(int i = 0; i < m+1; i++)
			D[i] = new int[n+1]; 
	
		for(int j=0;j<=n;j++)
			D[0][j]=0;
		for(int i=1;i<=m;i++)
			D[i][0]=i;
		int equal=0;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=n;j++)
			{
				if(s[i-1]==r[j-1])
					equal=0;
				else
					equal=1;
	
				D[i][j]=minOfTreeNum(D[i][j-1]+1,D[i-1][j]+1,D[i-1][j-1]+equal);
				if(i==m&&D[i][j]<=result)
					result=D[i][j];
	
			}
		for(int i = 0; i < m+1; i++)
			delete[] D[i];
			delete[] D;
	    return result;
	}
}
int DP_ED(string s, string t){
    //levenshtein距离的自底向上方式的动态规划实现，把重复计算的距离存入一个矩阵中
    // int dp[s.length()+1][t.length()+1];//d[i][j]表示字符串s的前i字符和t的前j个字符的莱文斯坦距离
	vector<int> rp(t.size()+1);
    vector<vector<int> > dp;
	int result=0;
    for(int i=0;i<s.size()+1;i++)
    	dp.push_back(rp);
    for(int i = 0; i <= s.size(); i++)dp[i][0] = i;//源字符串s到空字符串t只要删除每个字符
    for(int j = 1; j <= t.size(); j++)dp[0][j] = j;//从空字符s到目标字符t只要添加每个字符
    for(int j = 0; j < t.size(); j++){
        for(int i = 0; i < s.size(); i++){
            if(s[i] == t[j])dp[i+1][j+1] = dp[i][j];//无任何操作
            else dp[i+1][j+1] = minOfTreeNum(dp[i][j+1]+1, dp[i+1][j]+1, dp[i][j]+1);
            //分别为删除、添加、替换操作
        }
    }
	result=dp[s.size()][t.size()];
	rp.clear();rp.shrink_to_fit();
	dp.clear();dp.shrink_to_fit();
    return result;
}

void DP_ED_SUB(const string& test_str,const string& query_str,int& ed,int& index)
{
	int min_ed=INT_MAX;
	int min_index=INT_MAX;
	//levenshtein距离的自底向上方式的动态规划实现，把重复计算的距离存入一个矩阵中
    // int dp[query_str.length()+1][test_str.length()+1];//d[i][j]表示字符串s的前i字符和t的前j个字符的莱文斯坦距离
    vector<int> r(test_str.size()+1);
    vector<vector<int> > dp;
    for(int i=0;i<query_str.size()+1;i++)
    	dp.push_back(r);
	for(int i = 0; i <= query_str.size(); i++)
		dp[i][0] = i;//源字符串s到空字符串t只要删除每个字符
    for(int j = 1; j <= test_str.size(); j++)
		dp[0][j] = j;//从空字符s到 目标字符t只要添加每个字符
    for(int j = 0; j < test_str.size(); j++)
	{
        for(int i = 0; i < query_str.size(); i++)
		{
            if(query_str[i] == test_str[j])
				dp[i+1][j+1] = dp[i][j];//无任何操作
            else 
				dp[i+1][j+1] = minOfTreeNum(dp[i][j+1]+1, dp[i+1][j]+1, dp[i][j]+1);
        }

    }
    int i=query_str.size();
	 	for(int j=0;j<test_str.size()+1;j++)
	 	{
	 		if(min_ed>=dp[i][j])
	 		{
        		min_ed=dp[i][j];
				min_index=j-1;	 			
			}
		}
	r.clear();r.shrink_to_fit();
	dp.clear();dp.shrink_to_fit(); 	
	ed=min_ed;
	index=min_index;
}
int DP_ED_t(const string& test_str,const string& query_str,const int& ed)
{
	int index=INT_MAX;
	//levenshtein距离的自底向上方式的动态规划实现，把重复计算的距离存入一个矩阵中
    // int dp[query_str.length()+1][test_str.length()+1];//d[i][j]表示字符串s的前i字符和t的前j个字符的莱文斯坦距离
    vector<int> r(test_str.size()+1);
    vector<vector<int> > dp;
    for(int i=0;i<query_str.size()+1;i++)
    	dp.push_back(r);
	for(int i = 0; i <= query_str.size(); i++)
		dp[i][0] = i;//源字符串s到空字符串t只要删除每个字符
    for(int j = 1; j <= test_str.size(); j++)
		dp[0][j] = j;//从空字符s到 目标字符t只要添加每个字符
    for(int j = 0; j < test_str.size(); j++)
	{
        for(int i = 0; i < query_str.size(); i++)
		{
            if(query_str[i] == test_str[j])
				dp[i+1][j+1] = dp[i][j];//无任何操作
            else 
				dp[i+1][j+1] = minOfTreeNum(dp[i][j+1]+1, dp[i+1][j]+1, dp[i][j]+1);
        }

    }
    int i=query_str.size();
	 	for(int j=1;j<test_str.size()+1;j++)
	 	{
	 		if(dp[i][j]<=ed)
	 		{
				 index=j-1;
			}
		}	
	r.clear();r.shrink_to_fit();
	dp.clear();dp.shrink_to_fit(); 			
	return index; 			 	
}
