myList = []
num = int(input())

for _ in range(num):
    line = list(input().split())

    if line[0] == "insert":
        myList.insert(int(line[1]), int(line[2]))

    elif line[0] == "remove":
        myList.remove(int(line[1]))

    elif line[0] == "append":
        myList.append(int(line[1]))

    elif line[0] == "sort":
        myList.sort()

    elif line[0] == "pop":
        myList.pop()

    elif line[0] == "reverse":
        myList.reverse()

    elif line[0] == "print":
        print(myList)
