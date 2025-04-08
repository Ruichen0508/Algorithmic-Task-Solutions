from pt4 import *

def solution(ts,qs):
    def key(tl):
        t=next((t[2],tl) for t in ts if tl==t[0])
        return t
    result=[]
    for q in qs:
        temp=list(map(lambda t:t[0],filter(lambda t:q[0] in t[3:] and q[1]>=t[1] and q[1]<=t[2],ts)))
        temp.sort(key=key)
        result.append(temp)
    return result

def solve():
    task('CC06WizeL3')
    t=[]
    n=get()
    while n>0:
        temp=get_list()
        t.append(temp)
        n-=1
    n=get()
    q=get_matr(n,2)
    result=solution(t,q)
    put(len(result))
    result=list(filter(lambda l:len(l)>0,result))
    put(result)

start(solve)
