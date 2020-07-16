"""
#函数与列表实例
#函数参数为列表
#使用函数修改列表
#函数中不修改列表
"""

#part1(函数参数为列表)
def greet_users(names = []):
    for user in names:
        msg = "hello, " + user.title() + "!"
        print(msg)

usernames = ["xiaoming","xiaoli","xiaohong"]
greet_users(usernames)

#part2(使用函数修改列表)
def move_list(list1 = [],list2 = []):
    while list1:
        list2.append(list1.pop())

persons = ["xiaoming","xiaohua","xiaoli"]
students = []
move_list(persons,students)
print(persons)
print(students)

#part3(使用切片法使得在函数中不修改列表)
def copy_list(list1 = [],list2 = []):
    while list1:
        list2.append(list1.pop())

list1 = ["xiaoming","xiaohua","xiaoli"]
list2 = []
copy_list(list1[:],list2)   #调用时使用列表副本

print(list1)
print(list2)