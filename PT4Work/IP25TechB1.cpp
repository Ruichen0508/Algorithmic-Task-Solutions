#include "pt4.h"
using namespace std;


void Solve()
{
    Task("IP25TechB1");
    int n;
    pt>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
    	pt>>a[i];
	}
	int maxSum = a[0];
    int curSum = a[0];
    for (int i = 0; i < n; i++) 
	{
        curSum += a[i];
        if (a[i] > curSum) {
            curSum = a[i];
        }
        maxSum = max(maxSum, curSum);
    }
	pt<<maxSum;

}
