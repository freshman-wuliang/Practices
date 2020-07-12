"""
#列表使用练习
#创建和打印
#添加和删除
"""

#part1
fruits = ["苹果","梨","香蕉","菠萝"]
print("列表" + str(fruits))

message = "我喜欢吃"
print(message + fruits[1])

#part2
fruits_name = fruits.pop(0)
print(fruits_name + "没有了")
print(fruits)
print("添加橘子后的列表")
fruits.append("橘子")
print(fruits)
print("添加西瓜之后的列表")
fruits.insert(2,"西瓜")
print(fruits)
del fruits[0]
print(fruits)