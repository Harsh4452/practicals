def bucketSort(array):
    bucket = []

    # Create empty buckets
    for i in range(len(array)):
        bucket.append([])

    # Insert elements into their respective buckets
    for j in array:
        index_b = int(10 * j)
        bucket[index_b].append(j)

    # Sort the elements of each bucket
    for i in range(len(array)):
        bucket[i] = sorted(bucket[i])

    # Get the sorted elements
    k = 0
    for i in range(len(array)):
        for j in range(len(bucket[i])):
            array[k] = bucket[i][j]
            k += 1
    return array


array = [.42, .32, .33, .52, .37, .47, .51]
print("Sorted Array in descending order is")
print(bucketSort(array))
'''1. Bucket Sort (bucketSort function):
Create an empty list named bucket to hold the buckets.
Iterate through the input array and create empty sublists inside bucket.
Distribute each element of the input array into its respective bucket based on a calculated index.
Sort each individual bucket using a sorting algorithm (in this case, sorted function is used).
Concatenate the sorted buckets back into the original array.
Return the sorted array.
2. Main Program:
Initialize an array with floating-point numbers.
Call the bucketSort function on the array.
Print the sorted array.'''