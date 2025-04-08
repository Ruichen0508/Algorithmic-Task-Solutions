from pt4 import *
def solve():
    task("IP25TechB4")
    n=get()
    s=get()
    arr=get_list(n)
    left = 0
    right = 0
    sum = 0
    maxLength = 0
    start = -1
    end = -1

    while right < n:
        sum += arr[right]

        while sum > s:
            sum -= arr[left]
            left += 1

        if sum == s and (right - left + 1) > maxLength:
            maxLength = right - left + 1
            start = left
            end = right
        right += 1

    if start == -1 and end == -1:
        result = [-1]
        put(result[0])
    else:
        result = [start + 1, end + 1]
        for i in range(2):
            put(result[i])







start(solve)
