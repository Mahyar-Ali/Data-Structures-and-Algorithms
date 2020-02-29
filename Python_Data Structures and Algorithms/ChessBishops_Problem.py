#Implementation of N-Bishops problem using Back Tracking Algorithm
#The task is to plave as many Bishops on an n*n chess board such that no two Queens attack eachother


def check(perm):
    i = len(perm)-1
    for j in range(i):
        if i - j == abs (perm[i]-perm[j]):
            return False
    return True

def addBishop(perm,n):
    if len (perm) == n :
        print(perm)
        return
    for i in range(n):
            perm.append(i)
            if check(perm):
                addBishop(perm,n)
            perm.pop()

n = 8
initial_arrangement_of_Bishops = []
addBishop(initial_arrangement_of_Bishops,n)
