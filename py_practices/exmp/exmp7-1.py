"""
#用户输入input()函数实例
#input()函数的参数
#使用变量作为参数
#使用int()函数将输入变成int类型的数值
"""

#part1(input()函数的参数)
print("part1:")
name = input("please enter your name: ")   #input()接受一个字符串作为输入提示信息
print(name)

#part2(使用变量作为参数)
print("\npart2:")
message = "please input something: "
something = input(message)
print("your input is: " + something)

#part3(使用int()函数)
print("\npart3:")
age = input("please enter your age: ")
age = int(age)   #将age由字符串改变为int数值类型
if age >= 18:
    print("you is an adult.")
else:
    print("you is not an adult.")