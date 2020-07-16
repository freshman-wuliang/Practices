"""
#函数实例
#函数定义
#带有参数的函数
#函数使用位置实参调用
#关键字实参
#带默认参数的函数
"""

#part1(函数定义)
def greet_user():
    "打印hello world"
    print("hello world!")

#函数调用
greet_user()

#part2(带有参数的函数)
def greet_user2(username):
    print("Hello, " + username.title() + "!")

greet_user2("xiaoming")

def print_pet(pet_type,pet_name):
    print("I have a " + pet_name.title() + ".")
    print("My " + pet_type.title() + "'s name is " + pet_name.title() + ".")

print_pet("dog","wangcai")
#使用位置确定实参时，形参的顺序十分重要

#part3(关键字实参)
print_pet(pet_type = "dog",pet_name = "xiaohei")
#关键字实参在函数调用时，显式的指出参数名和相应的值

#part4(带有默认参数的函数)
def print_fruit(fruit_type = "apple"):
    print("my favorite fruit is " + fruit_type)

print_fruit("pear")   #带参数调用
print_fruit()   #不带参数调用