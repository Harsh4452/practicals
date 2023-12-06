def binary_search(list1, key): 
    start = 0 
    end = len(list1) 
    while start < end: 
        mid = (start + end) // 2 
        if list1[mid][0] > key: 
            end = mid 
        elif list1[mid][0] < key: 
            start = mid + 1 
        else: 
            return mid 
    return -1 
 
def binary_search_recursive(list1, key, start, end): 
    if start >= end: 
        return -1 
    mid = (start + end) // 2 
    if list1[mid][0] == key: 
        return mid 
    elif list1[mid][0] > key: 
        return binary_search_recursive(list1, key, start, mid) 
    else: 
        return binary_search_recursive(list1, key, mid + 1, end) 
 
def insert_friend(list1, name, number): 
    index = binary_search(list1, name) 
    if index == -1: 
        list1.append([name, number]) 
        list1.sort() 
        print("Friend added successfully!") 
    else: 
        print("Friend already exists in the phonebook.") 
 
# Define the phonebook 
phonebook = [] 
 
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
 
# Print the phonebook 
print("Phonebook:") 
for friend in phonebook: 
    print(f"{friend[0]}: {friend[1]}") 
 
 
# Search for a friend in the phonebook 
name = "Charlie" 
index = binary_search(phonebook, name) 
if index == -1: 
    print(f"{name} was not found in the phonebook.") 
else: 
    print(f"{name} was found at index {index} in the phonebook.") 
    print(f"Details of {name}: {phonebook[index][1]}") 
 
# Insert a friend into the phonebook 
insert_friend(phonebook, "Frank", "6789012345")
