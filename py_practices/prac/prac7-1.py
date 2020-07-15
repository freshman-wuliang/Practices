"""
#input()函数和取模运算符练习
#让用户输入一个数字，指出是否是10的整数倍
"""

number = input("please input a number: ")
number = int(number)
if number % 10 == 0:
    print("yes")
else:
    print("no")