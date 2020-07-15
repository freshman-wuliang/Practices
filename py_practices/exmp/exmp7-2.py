"""
#while循环实例
#一个简单的while循环
#使用while循环不断从键盘读取输入
#使用break退出循环
#使用continue跳过某次循环
"""

#part1(简单的while循环)
print("part1:")
number = 1
while number <= 5:
    print("number:" + str(number))
    number += 1

#part2(while循环读取输入)
print("\npart2:")
exit = "quit"   #定义结束变量
message = ""
while message != exit:
    message = input("input: ")
    print("message: " + message)