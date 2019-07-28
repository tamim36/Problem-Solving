n = int(input())

nums = list(map(int, input().split()))

i = -500

max_num = max(nums)

for num in nums:
    if i < num != max_num:
        i = num

print(i)
