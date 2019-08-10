numOfStudents = int(input())
myDict = {}

for _ in range(numOfStudents):
    name, a, b, c = input().split()

    avgMarks = float(float(a)+float(b)+float(c))/3

    myDict[name] = avgMarks


student = str(input())
print('%.2f' % myDict[student])
