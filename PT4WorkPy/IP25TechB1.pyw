from pt4 import *
def solve():
    task("IP25TechB1")
    n=get()
    a = get_list(n)
    maxSum = a[0]
    curSum = a[0]
    for i in range(n):
        curSum += a[i]
        if a[i] > curSum:
            curSum = a[i]
        maxSum = max(maxSum, curSum)
    put(maxSum)








start(solve)
