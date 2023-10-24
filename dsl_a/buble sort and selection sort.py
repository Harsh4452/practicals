a=[]
s=int(input("enter no. of elements in array="))
for i in range(0,s):
    p=int(input("enter the number in list\n"))
    a.append(p)
#bubble sort
print("python program of bubble sort")
for i in range(0,s-1):
    for j in range(0,s-1):
         if a[j]>a[j+1]:
            temp=a[j]
            a[j]=a[j+1]
            a[j+1]=temp
print("The array is sorted by bubble sort",a)

#selection sort
print("python program of selection sort")
for i in range(0,s-1):
    min=a[i]
    for j in range(0,s-1):
        if (a[j]<min):
            min=a[j]
print("The array is sorted by selection sort",a)

