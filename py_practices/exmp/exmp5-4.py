"""
#使用if语句处理列表
#处理特定的值
#确定列表不为空
#使用多个列表
"""

fruits = ["apple","pear","watermelon"]
print(fruits)

#part1(处理特定值)
for fruit in fruits:
    if fruit == "pear":
        print(fruit + " is used up")
    else:
        print(fruit + " is avaliable")

#part2(确定列表不为空)
cars = []   #建立空列表

if cars:   #如果列表为空
    for car in cars:
        print(car)
else:
    print("list is empty")

#part3(使用多个列表)
my_favorite_foods = ["watermelon","pizza","noodles"]

if my_favorite_foods and fruits:
    for fruit in fruits:
        if fruit in my_favorite_foods:
            print("i like " + fruit)
        else:
            print("i don't like " + fruit)