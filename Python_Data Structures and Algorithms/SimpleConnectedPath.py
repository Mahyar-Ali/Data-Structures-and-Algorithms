#The task is to solve a grid/maze puzzle and each step has been represented by a point.The task is to start from
#an initial point and reach the final point.
#This is implemented using Backtracking.

def check(per):
    i = per[-1]
    j = per[-2]
    if not (i[0]==j[1]):
        return False
    return True

def travel(path,per):
    if per[-1][1] == 8:
        print(per)
        quit()
        return
    for i in path:
        if i not in per:
            per.append(i)
            if check(per):
                travel(path,per)
            per.pop()




points = [(0,0),(0,1),(1,2),(0,3),(3,4),(4,5),(4,7),(3,6),(7,8)]  #--> (0,0),(0,3),(3,4),(4,7),(7,8) --> Path from 0 to 8
travel(points,[(0,0)])
