"""
a) Write a python program to store names and mobile numbers of your friends in sorted 
order on names. Search your friend from list using binary search (recursive and non-recursive). Insert friend if not present in phonebook
b) Write a python program to store names and mobile numbers of your friends in sorted 
order on names. Search your friend from list using Fibonacci search. Insert friend if not 
present in phonebook. 
"""
#Sort function
def sort(arr):
    for _ in range(len(arr)):
        swp = 0
        j = 0
        while j < len(arr) - 1:
            if arr[j][0] > arr[j+1][0]:
                arr[j],arr[j+1] = arr[j+1],arr[j]
                swp = 1
            j += 1
        if swp == 0:
            break

# Add friend function
def addFriend(arr, name, number):
    arr.append([name, number])
    sort(arr)
    print("Friend added successfully")

# Search friend function
def searchFriend(arr, x):
    print("How do you want to search your friend?")
    print("1. Binary Search (Non Recursive)")
    print("2. Binary Search (Recursive)")
    print("3. Fibonacci Search")
    choice = int(input("Enter your choice: "))
    if choice == 1:
        index = binarySearch_nonRecursive(arr, x)
    elif choice == 2:
        index = binarySearch_Recursive(arr, x, 0, len(arr)-1)
    elif choice == 3:
        index = FibonacciSearch(arr, x)
    else:
        print("Invalid choice")
        return
    if index < 0:
        print("Friend not found")
        print("Do you want to add friend? (y/n)")
        ch = input()
        if ch == 'y':
            number = input("Enter mobile number: ")
            addFriend(arr, x, number)
    else:
        print("Friend found")
        print("Name: ", arr[index][0])
        print("Mobile number: ", arr[index][1])

# Non Recursive Binary Search function
def binarySearch_nonRecursive(arr, x):
    hi = len(arr) - 1
    low = 0
    while True:
        mid = (low + hi)//2
        if x == arr[mid][0]:
            return mid
        elif low == hi:
            return -1
        elif x > arr[mid][0]:
            low = mid + 1
        else:
            hi = mid - 1

# Recursive Binary Search function
def binarySearch_Recursive(arr, x, low, hi):
    mid = (low + hi)//2
    if x == arr[mid][0]:
        return mid
    elif low == hi:
        return -1
    elif x > arr[mid][0]:
        low = mid + 1
        return binarySearch_Recursive(arr, x, low, hi)
    else:
        hi = mid - 1
        return binarySearch_Recursive(arr, x, low, hi)

#Fibonacci Search function
def FibonacciSearch(arr, x):
    n = len(arr)
    fibMm2 = 0
    fibMm1 = 1
    fibM = fibMm2 + fibMm1 

    while fibM < n: 
        fibMm2 = fibMm1
        fibMm1 = fibM
        fibM = fibMm2 + fibMm1
    
    offset = -1

    while fibM > 1:
        i = min(fibMm2 + offset, n-1)
        if x > arr[i][0]:
            fibM = fibMm1
            fibMm1 = fibMm2
            fibMm2 = fibM - fibMm1
            offset = i
        elif x < arr[i][0]:
            fibM = fibMm2
            fibMm1 = fibMm1 - fibMm2
            fibMm2 = fibM - fibMm1
        else:
            return i

    if fibMm1 and arr[n-1][0] == x:
        return n-1
    else:
        return -1

#Driver code
phonebook = []
choice = 0
while(choice != 4):
    print("What do you want to do?")
    print("1. Add a friend")
    print("2. Search a friend")
    print("3. Display Phonebook")
    print("4. Exit")

    choice = int(input("Enter your choice: "))
    if choice == 1:
        name = input("Enter name: ")
        number = input("Enter number: ")
        addFriend(phonebook, name, number)
    elif choice == 2:
        if len(phonebook) == 0:
            print("Phonebook is empty")
        else:
            searchFriend(phonebook, input("Enter name: "))
    elif choice == 3:
        if phonebook == []:
            print("Phonebook is empty")
        else:
            print("\tName\t\tMobile Number")
            for i in phonebook:
                print(i[0], "\t\t", i[1])
    elif choice == 4:
        print("Exiting...\nThank you for using the phonebook program!")
    else:
        print("Wrong input! Please try again.")
    print()
'''1. Sorting Algorithm (sort function):
This function uses the Bubble Sort algorithm to sort the phonebook array based on names.
It iterates through the array, comparing adjacent elements and swapping them if they are in the wrong order.
The process is repeated until no more swaps are needed, indicating that the array is sorted.
2. Adding a Friend (addFriend function):
This function adds a new friend to the phonebook.
The friend's name and number are provided as parameters.
The friend is appended to the phonebook array, and the sort function is called to maintain the sorted order.
A success message is printed.
3. Searching for a Friend (searchFriend function):
This function facilitates searching for a friend in the phonebook.
The user is prompted to choose a search method: binary search (non-recursive), binary search (recursive), or Fibonacci search.
Depending on the choice, the corresponding search function is called.
If the friend is not found, the user is given the option to add the friend.
4. Binary Search (Non-Recursive) (binarySearch_nonRecursive function):
This function performs a binary search in a non-recursive manner.
It uses two pointers (low and hi) to define the search range.
The mid-point is calculated, and the search range is adjusted based on whether the friend's name is greater or less than the mid-point.
The process continues until the friend is found or the search range is exhausted.
5. Recursive Binary Search (binarySearch_Recursive function):
This function performs a binary search in a recursive manner.
It takes additional parameters (low and hi) to define the current search range.
The mid-point is calculated, and the search range is adjusted based on whether the friend's name is greater or less than the mid-point.
The function calls itself recursively until the friend is found or the search range is exhausted.
6. Fibonacci Search (FibonacciSearch function):
This function performs a Fibonacci search.
It calculates the Fibonacci numbers to determine the search range.
The search is conducted by comparing the friend's name with elements at specific indices determined by Fibonacci numbers.
The search range is adjusted based on the comparison.
The process continues until the friend is found or the search range is exhausted.
7. Displaying Phonebook:
The program provides a menu-driven interface allowing the user to choose actions.
Options include adding a friend, searching for a friend, displaying the phonebook, and exiting the program.
The user's choice determines which action is performed.
8. Exiting the Program:
If the user chooses to exit the program, a farewell message is displayed, and the program terminates'''
