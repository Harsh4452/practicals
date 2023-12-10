"""Write a pythonprogram to store first year percentage of students in array. Write function
for sorting array of floating point numbers in ascending order using
a) Selection Sort
b) Bubble sort and display top five scores"""

def sel_sort_asc():
    for i in range(tot_stu):
        min_ele = i
        for j in range(i+1,tot_stu):
            if marks[min_ele] > marks[j]:                
                min_ele = j
                

        marks[i],marks[min_ele] = marks[min_ele],marks[i]

    print("Score after selection sort(ascending):", marks)
    input1 = int(input(">>>go back or continue?(1/2): "))
    if input1 == 1:
        menu()
    elif input1 == 2:
        sel_sort_desc()
    else:
        exit()

def sel_sort_desc():
    for i in range(tot_stu):
        min_ele = i
        for j in range(i+1,tot_stu):
            if marks[min_ele] < marks[j]:                
                min_ele = j
                

        marks[i],marks[min_ele] = marks[min_ele],marks[i]

    print("Score after selection sort(descending):", marks)
    input2 = int(input(">>>go back or continue?(1/2): "))
    if input2 == 1:
        menu()
    elif input2 == 2:
        bub_sort_asc()
    else:
        exit()

def bub_sort_asc():
    n = tot_stu
    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if marks[j] > marks[j + 1]:
                marks[j], marks[j + 1] = marks[j + 1], marks[j]

    print("Score after bubble sort(ascending):",marks)
    input3 = int(input(">>>go back or continue?(1/2): "))
    if input3 == 1:
        menu()
    elif input3== 2:
        bub_sort_desc()
    else:
        exit()
        
def bub_sort_desc():
    n = tot_stu
    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if marks[j] < marks[j + 1]:
                marks[j], marks[j + 1] = marks[j + 1], marks[j]

    print("Score after bubble sort(descending):",marks)
    print(marks)
    input4 = int(input(">>>go back or continue?(1/2): "))
    if input4 == 1:
        menu()
    elif input4 == 2:
        top_five()
    else:
        exit()
    
def top_five():
    n = tot_stu
    for i in range(n - 1):
        for j in range(0, n - i - 1):
            if marks[j] < marks[j + 1]:
                marks[j], marks[j + 1] = marks[j + 1], marks[j]
                
    top5 = []
    for value in range(0,5):
        top5.append(marks[value])
    print("Top 5 score of students",top5)
    print("=="*50)
        
        

    
    

def menu():
    print("=="*50)
    print("1) Selection sort")
    print("2) Bubble sort")
    print("3) Exit")

    i1 = int(input("Enter your choice: "))
    if i1 == 1:
        print("=="*50)
        print("1) Ascending")
        print("2) Descending")
        print("3) Go back")
        inp1 = int(input("Enter your choice: "))
        if inp1  == 1:
            sel_sort_asc()
        elif inp1 == 2:
            sel_sort_desc()
        elif inp1 == 3:
            menu()
        else:
            exit()
    elif i1 == 2:
        print("=="*50)
        print("1) Ascending")
        print("2) Descending")
        print("3) Top 5 percentages")
        print("4) Go back")
        inp2 = int(input("Enter your choice: "))
        if inp2 == 1:
            bub_sort_asc()
        elif inp2 == 2:
            bub_sort_desc()
        elif inp2 == 3:
            top_five()
        elif inp2 == 4:
            menu()
        else:
            exit()
    elif i1 == 3:
        exit()
    else:
        print("invalid coice!")
        menu()


marks = []
print("===="*30)
print("0~~~~|Enter the required data|~~~~00")
tot_stu = int(input("Total number of students: "))
print("===="*30)
for i in range(tot_stu):
    mks = int(input("Enter Percentage obtained by the students: "))
    marks.append(mks)
print("Score of",tot_stu,"students are",marks)
menu()
'''1. Selection Sort (Ascending) (sel_sort_asc function):
Iterate through each element in the array.
For each element, find the minimum element in the unsorted portion of the array.
Swap the current element with the minimum element.
Continue until the entire array is sorted in ascending order.
Print the sorted array and provide the user with the option to go back, continue with a different sorting method, or exit.
2. Selection Sort (Descending) (sel_sort_desc function):
Similar to the ascending version, but find the maximum element instead of the minimum.
Swap the current element with the maximum element.
Continue until the entire array is sorted in descending order.
Print the sorted array and provide the user with the option to go back, continue with a different sorting method, or exit.
3. Bubble Sort (Ascending) (bub_sort_asc function):
Iterate through the array using nested loops.
Compare adjacent elements and swap them if they are in the wrong order.
Continue this process until the entire array is sorted in ascending order.
Print the sorted array and provide the user with the option to go back, continue with a different sorting method, or exit.
4. Bubble Sort (Descending) (bub_sort_desc function):
Similar to the ascending version, but swap elements if they are in the wrong order for descending order sorting.
Print the sorted array and provide the user with the option to go back, continue with a different sorting method, or exit.
5. Top Five Scores (top_five function):
Use bubble sort to sort the array in descending order.
Extract the top five scores from the sorted array.
Print the top five scores and provide the user with the option to go back, continue with a different sorting method, or exit.
6. Menu (menu function):
Display a menu to the user with options for selection sort, bubble sort, and exit.
Based on the user's choice, provide sub-options for sorting methods and additional features.
Call the corresponding functions based on user input.
7. Main Program:
Initialize an empty marks array to store the percentage scores.
Take input for the total number of students and their respective scores.
Display the menu to the user and execute the chosen functionality.'''