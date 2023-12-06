def bucket_sort(arr): 
    # Create empty buckets 
    n = len(arr) 
    buckets = [[] for _ in range(n)] 
 
    # Add elements to the appropriate bucket 
    for i in range(n): 
        index = int(n * arr[i]) 
        buckets[index].append(arr[i]) 
 
    # Sort each bucket and concatenate them 
    for i in range(n): 
        buckets[i] = sorted(buckets[i]) 
    return [elem for bucket in buckets for elem in bucket] 
 
 
percentages=[0]*10 
# Take input from user 
percentage = float(input("Enter the percentage to add to the array: ")) 
percentages.append(percentage) 
 
# Sort the array using bucket sort 
sorted_percentages = bucket_sort(percentages) 
 
# Display the top five scores 
print("Top five scores:") 
for i in range(5): 
    print(sorted_percentages[-i-1])
