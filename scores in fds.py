"""
Write a Python program to store marks scored in subject “Fundamental of Data
Structure” by N students in the class. Write functions to compute following:
a) The average score of class
b) Highest score and lowest score of class
c) Count of students who were absent for the test
d) Display mark with highest frequency
"""

#The average score of class 
def Average(L):
    Sum = 0
    for i in L:
        #We want the loop to count and add only when i value is a number
        if i == 'NA' or i == 'na' or i == 'Na' or i == 'nA':
            continue #Skips when i is NA
        else:
            Sum = Sum + int(i) 
    Avg = Sum/len(L)
    return Avg

#Highest score and lowest score of class 
def Highest(L):
    Hi = 0
    for i in L:
        if i == 'NA' or i == 'na' or i == 'Na' or i == 'nA':
            continue
        else:
            if int(i) > Hi:
                Hi = int(i) #Re-assigns the higher value in each iteration
    return Hi #The final Hi value will be highest in the list

def Lowest(L): #Same logic as Highest(), just reversed
    Lo = 100
    for i in L:
        if i == 'NA' or i == 'na' or i == 'Na' or i == 'nA':
            continue
        else:
            if int(i) < Lo:
                Lo = int(i)
    return Lo

#Count of students who were absent for the test
def Absent(L):
    c = 0
    for i in L:
        if i == 'NA' or i == 'na' or i == 'Na' or i == 'nA':
            c +=1 #Counting NA values 
    return c

#Display mark with highest frequency
def Mode(L): #Mode is the element with highest frequency in the data
    max = 0
    mode = L[0]
    for i in L:
        c=0
        for j in L: #To check frequency of each element
            if i == 'NA' or i == 'na' or i == 'Na' or i == 'nA' or j == 'NA' or j == 'na' or j == 'Na' or j == 'nA':
                continue
            else:
                if int(i) == int(j):
                    c+=1 #Counts frequency of an element in the list
        if c>max: #Same as Highest(), but with frequency of elements
            max=c #max contains the highest frequency
            mode=int(i) #mode is element with that (maximum) frequency
    return mode

n = int(input("Enter class strength "))
Marks = []
for i in range(0,n):
    L = input("Enter marks of the student (Type NA if absent):")
    Marks.append(L)

print ("The average score of the class is:", Average(Marks))
print ("The highest score in the class is:", Highest(Marks))
print ("The lowest score in the class is:", Lowest(Marks))
print ("The number of students absent for the test are:", Absent(Marks))
print ("Marks with highest frequency is:", Mode(Marks))
