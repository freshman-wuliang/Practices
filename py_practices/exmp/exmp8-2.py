"""
#函数的返回值实例
#带有返回值的函数
#让实参变为可选的
#函数返回字典
"""

#part1(带有返回值的函数)
def get_name(first_name,last_name):
    full_name = first_name + " " + last_name
    return full_name.title()

print(get_name("xiao","ming"))

#part2(让实参变为可选择的)
def make_name(first_name,last_name,middle_name = ""):
    #如果middle_name不为空
    if middle_name:
        full_name = first_name + " " + middle_name + " " + last_name
    else:
        full_name = first_name + " " + last_name

    return full_name.title()

print(make_name("Jimi","hendrix"))
print("john","hooker","lee")

#part3(函数返回字典)
#函数接受信息构成字典，并且由函数返回
def build_person(first_name,last_name):
    #定义字典
    person = {"first" : first_name,"last" : last_name}
    #返回字典
    return person

person = build_person("xiao","ming")
print(person)
print("first: " + person["first"])
print("last: " + person["last"])