"""
Write a Python program to compute following operations on String:
a) To display word with the longest length
b) To determines the frequency of occurrence of particular character in the string
c) To check whether given string is palindrome or not
d) To display index of first appearance of the substring
e) To count the occurrences of each word in a given string
"""
#Selection Sort
def selsort(L):
    for i in range(len(L)):
        min_index = i
        for j in range(i+1,len(L)):
            if L[j] < L[min_index] :
                min_index = j
        L[i], L[min_index] = L[min_index], L[i]
    return L

#Bubble Sort
def bubblesort(L):
    for i in range(len(L)) :
        for j in range(0,len(L)-i-1):
            if L[j]>L[j+1]:
                L[j], L[j+1] = L[j+1], L[j]
    return L

#Top five percentage:
def top5(L):
    if len(L) >= 5:
        for i in range(1,6):
            A = L[len(L)-i]
            print(A)
    else:
        for i in range(len(L)):
            print(L[i])
                    
#Main
n = int(input("Enter no. of students:"))
L = []
for i in range(n):
    K = int(input(f"Enter percentage of student {i+1}: "))
    L.append(K)
ch = int(input("Choose-\n1 for Selection Sort\n2 for bubblesort\nEnter: "))
if ch == 1 :
    print("Top five percentages are: ") 
    print(selsort(L))
    top5(selsort(L))
elif ch == 2 :
    print("Top five percentages are: ")
    print(bubblesort(L))
    top5(bubblesort(L))
else :
    print("INVALID INPUT! Enter correct input for the sorting method.")
    
