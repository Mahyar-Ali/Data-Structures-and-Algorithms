from itertools import combinations
from itertools import permutations

#Implementation of N-Queens problem using Brut-Forcing
#The task is to plave as many Queens on an n*n chess board such that no two Queens attack eachother

n = 4

def checkwethersolution(perm):
    for i,j in combinations(range(len(perm)),2):
        if abs(i - j) == abs(perm[i]-perm[j]):
            return False

    return True

for perm in permutations(range(n)):
    if (checkwethersolution(perm) == True):
       for i in perm :
           for j in range(n):
               if (i==j):
                   print('Q',end='  ')
               else:
                   print('-',end = '  ')
           print(' ')

       print(' ')

