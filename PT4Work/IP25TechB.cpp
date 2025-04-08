#include <string>
#include "pt4taskmaker.h"
#include <vector>
#include <unordered_map>

void Task1()
{
  CreateTask();
  TaskText("\\SArrayMaxConsecutiveSum2.\\s Given an array of integers, find the maximum possible\n"
  "sum you can get from one of its contiguous subarrays. The subarray from which\n"
  "this sum comes must contain at least 1 element.\n"
  );
  int n = RandomN(10, 20);
  int a[20];
  DataN("N = ", n, xCenter, 1, 2);
  for (int i = 0; i < n; i++)
      a[i] = RandomN(0, 100);
  for (int i = 0; i < n; i++)
      DataN(a[i], Center(i + 1, n, 2, 2), 2, 2);
  int maxSum = a[0];
  int curSum = a[0];
  for (int i = 0; i < n; i++) 
  {
      curSum += a[i];
      if (a[i] > curSum) 
      {
          curSum = a[i];
      }
      maxSum = max(maxSum, curSum);
  }
  ResultN(maxSum, xCenter, 1, 3);

  SetTestCount(5);
}
string solution(string s, string t) {
    int n = s.size();
    int m = -1, ind = 0;
    for (int i = 0; i < n; ++i) {
        int left = t.size(), len = 0;
        vector<bool> got(26, true);
        for (char c : t)
            got[c - 'a'] = false;
        for (int j = i; j < s.size() && left; ++j, ++len)
            if (!got[s[j] - 'a'])
                got[s[j] - 'a'] = true, --left;
        if (left)
            break;
        if (m == -1 || len < m)
            m = len, ind = i;
    }
    return s.substr(ind, m);
}
void Task2()
{
    CreateTask();
    TaskText("\\SMinSubstringWithAllChars.\\sYou have two strings, s and t.The string \n"
        " contains only unique elements. Find and return the minimum\n"
    );
    string s = WordSample(RandomN(5, 10));
    string t = WordSample(RandomN(3, 5));

    DataS( s.c_str(), xCenter, 1, 2);
    DataS(t.c_str(), xCenter, 1, 3);

    string result = solution(s,t);

    ResultS(result.c_str(), 2, 4);

    SetTestCount(5);
    
}
void Task3()
{
    CreateTask();
    TaskText("\\SsumInRange.\\sYou have an array of integers nums and an array queries,\n"
        " where queries[i] is a pair of indices (0-based). Find the sum of the\n"
        "elements in nums from the indices at queries[i][0] to \n"
        "queries[i][1] (inclusive) for each query, \n"
        "then add all of the sums for all the queries together\n"
        "Return that number modulo 109 + 7."
    );
    int n = RandomN(5, 10);
    DataN("n = ", n, xCenter, 1, 2);
    int m = RandomN(3, 5);
    DataN("m = ", m, xCenter, 3, 2);
    vector<int> nums(n);
    vector<vector<int>> queries(m, vector<int>(2));
    
    for (int i = 0; i < n; i++)
    {
        nums[i] = RandomN(1, 10);
    }
    for (int i = 0; i < n; i++)
        DataN(nums[i], Center(i + 1, n, 2, 2), 2, 2);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            queries[i][j] = RandomN(0, n - 1);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            DataN(queries[i][j], Center(i + 1, m, 4, 2), 4, 2);
        }
    }
    int sum = 0;
    for (auto query : queries)
    {
        for (int i = query[0]; i <= query[1]; i++)
        {
            sum += nums[i];
        }
    }

    sum %= 1000000007;
 
    ResultN(sum, xCenter, 1, 3);

    SetTestCount(5);
}
void Task4()
{
    CreateTask();
    TaskText("\\SfindLongestSubarrayBySum.\\sYou have an unsorted\n"
        " array arr of non-negative integers and a number s.Find a longest contiguous\n"
        " subarray in arr that has a sum equalto s. Return two integers\n"
        " that represent its inclusive bounds.\n"
        "If there are several possible\n"
        "answers, return the one with the smallest left\n"
        "bound. If there are no answers, return [-1]."
    );
    int n = RandomN(5, 10);
    DataN("n =", n,xCenter, 1, 2);
    int s = RandomN(10, 20);
    DataN("s =", s, xCenter, 2, 2);
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = RandomN(0, 10);
    }
    for (int i = 0; i < n; i++)
    {
        DataN(arr[i], Center(i + 1, n, 3, 2), 3, 2);
    }
    int left = 0, right = 0;
    int sum = 0;
    int maxLength = 0;
    int start = -1, end = -1;
    while (right < n)
    {
        sum += arr[right];

        while (sum > s)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == s && (right - left + 1) > maxLength)
        {
            maxLength = right - left + 1;
            start = left;
            end = right;
        }

        right++;
    }
    if (start == -1 && end == -1)
    {
        vector<int> result = { -1 };
        ResultN(result[0], xCenter, 4, 4);
    }
    else
    {
        vector<int> result = { start + 1, end + 1 };
        for (int i = 0; i < 2; i++)
        {
            ResultN(result[i], xCenter, 4, 4);
        }
        
    }
    SetTestCount(5);

}
void _stdcall InitTask(int num)
{
  switch (num)  
  {
    case 1:
      Task1(); break;
    case 2:
        Task2(); break;
    case 3:
        Task3(); break;
    case 4:
        Task4(); break;
  }
}

void _stdcall inittaskgroup()
{
  CreateGroup("IP25TechB", "Group description",
    "", "qwqfsdf13dfttd", 4, InitTask);
}
