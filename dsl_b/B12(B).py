def fibonacci_search(list1, key): 
    fib2 = 0 
    fib1 = 1 
    fib = fib2 + fib1 
    while fib < len(list1): 
        fib2 = fib1 
        fib1 = fib 
        fib = fib2 + fib1 
    offset = -1 
    while fib > 1: 
        i = min(offset + fib2, len(list1) - 1) 
        if list1[i][0] < key: 
            fib = fib1 
            fib1 = fib2 
            fib2 = fib - fib1 
            offset = i 
        elif list1[i][0] > key: 
            fib = fib2 
            fib1 = fib1 - fib2 
            fib2 = fib - fib1 
        else: 
            return i 
    if fib1 and list1[offset + 1][0] == key: 
        return offset + 1 
    return -1 
 
def insert_friend(list1, name, number): 
    index = fibonacci_search(list1, name) 
    if index == -1: 
        list1.append([name, number]) 
        list1.sort() 
        print("Friend added successfully!") 
    else: 
        print("Friend already exists in the phonebook.") 
 
# Define the phonebook 
phonebook = [] 
 
# Add friends to the phonebook 
while True: 
    name = input("Enter friend name (or 'q' to quit): ") 
    if name == "q": 
        break 
    number = input("Enter friend number: ") 
    phonebook.append([name, number]) 
 
# Sort the phonebook by name 
phonebook.sort() 
 
# Search for a friend in the phonebook 
name = input("Enter the name of the friend to search: ") 
index = fibonacci_search(phonebook, name) 
if index == -1: 
    print(f"{name} was not found in the phonebook.") 
else: 
    print(f"{name} was found at index {index} in the phonebook.") 
    print(f"Details of {name}: {phonebook[index][1]}") 
 
# Insert a friend into the phonebook 
name = input("Enter the name of the friend to insert: ") 
number = input("Enter the number of the friend to insert: ") 
insert_friend(phonebook, name, number) 
 
# Print the phonebook 
print("Phonebook:") 
for friend in phonebook: 
    print(f"{friend[0]}: {friend[1]}")
