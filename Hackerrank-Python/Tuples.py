num = int(input())
line = list(map(int, input().split()))
mytuple = tuple(line)
print(hash(mytuple))