a = [12,14,3,11,6,7]
for i in range(len(a)-1) :
    min_index = i
    for j in range (i+1,len(a)):
        if a[j] < a[min_index] :
                min_index = j
    a[i],a[min_index] = a [min_index] , a[i]


print(a)