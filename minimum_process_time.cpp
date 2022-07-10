I sort the preocess ( decending) and tasks to (assending) order than in task array i am taking multiple of 4th and mutiply with process[i]

ex ... n = 2
process time : [8 , 10]
tasks : [2,2,3,1,8,7,4,5]

process time (decending order) : [10 , 8 ]

tasks : [1,2,2,3,4,5,7,8]

now , temp1 = process[0] + task[3] = 10 + 3 = 13
temp2 = process[1] + task[7] = 8 + 8 = 16

res = max(tem1 , temp2)

let me know was it right approch ?? or there is other approch to solve this problem **. some hidden test case wasn't passed **



second approach

Sort both the processor and task array.
Assign the 4 most time-consuming tasks to the smallest processor time, and so on..
for eg:
[8,10]
[1,2,2,3,4,5,7,8]
Assign tasks [4,5,7,8] to processor 0.
Assign tasks [1,2,3,3] to processor 1.
