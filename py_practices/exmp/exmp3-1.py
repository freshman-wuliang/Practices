"""
#列表使用实例
#列表的定义与初始化
#访问列表元素
#负数索引
#修改、添加和删除元素
#pop()方法和remove()方法
#对列表排序sort()方法
#使用reverse()方法倒转列表
#使用len()函数获取列表长度
"""

#part1(列表定义与初始化)
fruits = ["apple","peach","banana","watermelon"]
print(fruits)    #输出包含方括号

#part2(访问列表元素)
print(fruits[0])   #只需使用下标就可以访问
print(fruits[1].title())   #使用title()函数

#part3(负数索引)
print(fruits[-1])   #watermelon
print(fruits[-2])   #banana

#part4(修改、添加和删除元素)
print("修改前：" + str(fruits))
fruits[0] = "pear"
print("修改后: " + str(fruits))
#添加元素
print("添加前：" + str(fruits))
fruits.append("apple")
print("添加后：" + str(fruits))
#插入元素
print("插入前：" + str(fruits))
fruits.insert(0,"mango")
print("插入后：" + str(fruits))
#删除元素
print("删除前：" + str(fruits))
del fruits[0]
print("删除后：" + str(fruits))

#part5(pop()方法和remove()方法)
print("pop前：" + str(fruits))
fruit_name = fruits.pop()   #无参数pop(默认为-1)
print("pop后：" + str(fruits))
print("被pop的元素:" + fruit_name)

print("remove前：" + str(fruits))   #remove按值删除列表中的元素
fruits.remove("watermelon")
print("remove后：" + str(fruits))

#part6(sort()方法对列表排序)
print("排序前:" + str(fruits))
#fruits.sort()
#print("排序后:" + str(fruits))
print("排序后:" + str(sorted(fruits)))
print(fruits)
#使用列表自带的sort()方法时列表本身也被改变
#使用sorted()函数时不改变列表本身

#part7(使用reverse()方法倒转列表)
print("倒转前:" + str(fruits))
fruits.reverse()
print("倒转后:" + str(fruits))

#part8(使用len()函数获取列表长度)
print("列表长度为:" + str(len(fruits)))