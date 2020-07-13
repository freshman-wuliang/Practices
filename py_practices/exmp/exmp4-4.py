"""
#元组使用实例（不可变的列表称为元组）
#元组的定义（使用圆括号）
#使用范围for循环遍历元组
#修改整个元组（元组的元素是不可以修改的）
"""

#part1(元组的定义)
dimensions = (200,50)
print(dimensions[0])
print(dimensions[1])

#part2(遍历元组)
for dimension in dimensions:
    print(dimension)

#part3(修改整个元组)
dimensions = (10,20)
print(dimensions)