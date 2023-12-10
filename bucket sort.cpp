def bucket_sort(arr):
    buckets=[]

    #intialise the empty bucket: 
    #we can also use bucket=[[],[],[],[],..........->total 10 empty buckets]
    for i in range(10):
        buckets.append([])

    #for inserting elements in bucket
    for j in range(len(arr)):
        index=int(10*(arr[j])) #sice we are dealing in floating points. 
        buckets[index].append(arr[j])

    #To verify
    #print(buckets)

    #sorting of buckets
    for i in range(10):
        buckets[i]=sorted(buckets[i])
    #print(buckets)

    res=[]
    #conctenate
    for i in range(10):
        if buckets[i]!=None:
            for j in buckets[i]:
                res.append(j)
    print(res)
    return(res)
#if percentage in integer divide by 100 and store as float
array=[]
for i in range(0,10,1):
    percentage=float((float(input("Enter Percentage :")))/100)
    array.append(percentage)
res=bucket_sort(array)
count=0
while(count<5):
    print(res[len(res)-1-count])
    count=count+1
