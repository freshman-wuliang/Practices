"""
#if语句实例
#简单的if举例
#检查是否相等(使用'==')
#检查是否不相等（'!='）
#检查多个条件（and,or,）
"""

#part1(if举例)
fruits = ["apple","pear","watermelon"]
for fruit in fruits:
    if(fruit == "pear"):
        print(fruit.upper())
    else:
        print(fruit.title())

#part2(检查是否相等)
print(fruits[0] == "apple")
