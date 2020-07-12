"""
#数值列表实例
#使用range()函数创建特定范围的数值列表
#使用list()函数生成列表
#使用min(),max(),sum()函数统计数字列表
#列表解析
"""

#part1(range()函数)
for value in range(1,5):   #range()函数生成1-4的数字列表
    print(value)

#part2(list()函数)
numbers = list(range(1,6))
print(numbers)

#part3(统计数字列表)
value = min(numbers)
print("min:" + str(value))
value = max(numbers)
print("max:" + str(value))
value = sum(numbers)
print("sum:" + str(value))

#part4(列表解析)
squares = [value ** 2 for value in range(1,11)]
print(squares)