def BubbleSort(a):
    for i in range(len(a)):
        for j in range(len(a)-i-1):
            if (a[j]>a[j+1]):
                a[j],a[j+1] = a [j+1],a[j]
    return a

test = [7,8,1,-3,17,90]
print(BubbleSort(test))

# O(n^2)