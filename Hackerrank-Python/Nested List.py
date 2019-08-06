n = int(input())

my_list = []
ans_name = []

min_num = 10000
sec_min = 10000

for _ in range(n):
    name = input()
    mark = float(input())

    if mark < min_num:
        min_num = mark

    my_list.append([name, mark])

for i in range(n):
    if sec_min > my_list[i][1] != min_num:
        sec_min = my_list[i][1]

for i in range(n):
    if sec_min == my_list[i][1]:
        ans_name.append(my_list[i][0])

ans_name.sort()

print(*ans_name, sep='\n')

