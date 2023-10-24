def average():
    avg = 0
    for i in marks:
        avg = avg + i
    print("Average score of class is ",(avg/n))
    
    
def extremes():
    max = 0
    min = 100
    for i in marks:
        if i > max:
            max = i
        else:
            continue
    for j in marks:
        if j < min:
            min = j
        else:
            continue    
    print("Max : ", max)
    print("Min : ", min)
    
    
def absent():
    print("Total no of Absent students : ", len(Abs_stud) )
    
    
def frequency():
    count = 0
    dict = {}
    
    for i in marks:
        for j in marks:
            if i == j:
                count = count + 1
            else:
                continue
        dict[i] = count
        count = 0
    max = 0
    
    for k in dict :
        if dict[k] > max:
            max = dict[k]
        else:
            continue
    
    for i in dict:
        if dict[i] == max:
            print("The maximun recurring marks are ", i ," and frequency is ", max)
            

option = """Choose your desired result :
    a) The average score of class : 1
    b) Highest score and lowest score of class : 2
    c) Count of students who were absent for the test : 3
    d) Display mark with highest frequency : 4
    e) To Exit : 5
    
    Choice : """
    
n = int ( input ("Enter Total no of Students : ") )
marks = []
Abs_stud = []
    
for i in range(0,n):
    score = input("Enter Marks of student : ")
    if "A" == score :
        Abs_stud.append(score)
    else:
        score = int (score)
        marks.append(score)

while True:
    
    Choice = int (input(option))
    
    if Choice == 1 :
        average()
    
    elif Choice == 2 :
        extremes() 
    
    elif Choice == 3 :
       absent() 
    
    elif Choice == 4 :
        frequency()
    
    elif Choice == 5 :
        break
    else :
        print("Invalid Choice.")
        break
    