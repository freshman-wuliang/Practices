"""
#使用列表的一部分
#切片
#遍历切片
#复制列表
"""

#part1(使用列表的一部分)
fruits = ["苹果","梨","西瓜","桃子"]
print(fruits)
print(fruits[0:2])   #使用列表的第0号和第1号元素
print(fruits[:3])   #省略起始的切片(默认从0开始)
print(fruits[-3:])   #省略末尾的切片（输出倒数第二个和倒数第一个）

#part2(遍历切片)
for fruit in fruits[:2]:
    print(fruit)

#part3(复制列表)
#things = fruits[:]
#print(things)
#这行不通
things = fruits
print(things)
fruits.append("芒果")
print(things)  #things只是fruits的一个副本，改变fruits的同时也改变了things
#要复制列表,只能使用切片来实现