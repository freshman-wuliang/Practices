"""
#创建列表，并计算列表元素的和
"""

numbers = list(range(1,21))   #生成列表
sums = 0   #统计和的变量
for number in numbers:
    sums += number

print(sums)
print(numbers)
print(sum(numbers))