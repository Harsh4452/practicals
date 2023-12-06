# Define the matrices 
matrix1 = [[1, 2], [3, 4]] 
matrix2 = [[5, 6], [7, 8]] 
 
# Add the matrices 
addition = [[matrix1[i][j] + matrix2[i][j] for j in range(len(matrix1[0]))] 
for i in range(len(matrix1))] 
print("Addition of two matrices:") 
for row in addition: 
    print(row) 
 
# Multiply the matrices 
multiplication = [[sum(matrix1[i][k] * matrix2[k][j] for k in 
range(len(matrix2))) for j in range(len(matrix2[0]))] for i in 
range(len(matrix1))] 
print("Multiplication of two matrices:") 
for row in multiplication: 
    print(row) 
 
# Subtract the matrices 
subtraction = [[matrix1[i][j] - matrix2[i][j] for j in 
range(len(matrix1[0]))] for i in range(len(matrix1))] 
print("Subtraction of two matrices:") 
for row in subtraction: 
    print(row) 
 
# Transpose the matrices 
transpose1 = [[matrix1[j][i] for j in range(len(matrix1))] for i in 
range(len(matrix1[0]))] 
transpose2 = [[matrix2[j][i] for j in range(len(matrix2))] for i in 
range(len(matrix2[0]))] 
print("Transpose of matrix 1:") 
for row in transpose1: 
    print(row) 
print("Transpose of matrix 2:") 
for row in transpose2: 
    print(row)
