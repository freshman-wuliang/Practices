"""
#if与列表一起使用实例
#检查特定值是否在列表内（使用关键词in）
#检查特定值是否不再列表内（使用not in）
"""

#part1(检查特定值是否在列表内)
fruits = ["apple","pear","watermelon"]
print(fruits)
print("apple" in fruits)
print("mango" in fruits)

#part2(不再列表内)
print("mango" not in fruits)
print("pear" not in fruits)