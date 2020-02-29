#Implementation of N-Queens problem using Back Tracking Algorithm
#The task is to plave as many Queens on an n*n chess board such that no two Queens attack eachother

def isSolution(perm):
    i = len(perm)-1
    for j in range(i):
        if i-j == abs (perm[i]-perm[j]):
            return False;
    return True

def generate(perm,n):
    if len(perm) == n:
        print(perm)
        return
    for i in range(n):
        if i not in perm:
            perm.append(i)
            if isSolution(perm):
                generate(perm,n)
            perm.pop()

n=8
initial_arrangement_of_Queens = []
generate(initial_arrangement_of_Queens, n)