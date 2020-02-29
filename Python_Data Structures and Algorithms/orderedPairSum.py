
#Find all the ordered Pairs from a set that adds up to a specific number

def nextElement (per,set,Sum):

    if (sum(per) == Sum):
        print(per)
        return
    if not(sum(per)<Sum):
        return
    for i in set:
        if i not in per:
            per.append(i)
            nextElement(per,set,Sum)
            per.pop()




OrderedPairs = [] #I know that ordered pairs are implmeted using tup() but for convenience I am using List.
set = [1,2,3,4]
required_sum = 8
nextElement(OrderedPairs,set,required_sum)