from pt4 import *
def solution(conversations, currentConversation):
    matches = {}
    currentConversationWords = set(tuple(currentConversation))

    for i in range(len(conversations)):
        conversationWords = set(conversations[i])
        intersection = list(currentConversationWords.intersection(conversationWords))

        if intersection:
            for j in range(len(conversations[i]) - 1, -1, -1):
                if conversations[i][j] in intersection:
                    matches[len(intersection)] = (i, j)
                    break

    if matches:
        bestMatch = list(matches.items())[-1][1]
        currentConversation.extend(conversations[bestMatch[0]][bestMatch[1] + 1:])

    return currentConversation
def solve():
    task("CC06WizeL2")
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
    









start(solve)
