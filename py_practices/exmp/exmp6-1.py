"""
#字典实例
#字典的定义
#访问字典的值
#添加键-值对
#修改键-值对
#删除键-值对(使用del关键词)
"""

#part1(定义字典)
student = {"001":"guaizi","002":"xiaohong"}
print(student)

#part2(访问字典的值)
print(student["001"])
print(student["002"])

#part3(添加键-值对)
student["003"] = "xiaoming"
student["004"] = "xiaoli"
print(student)

#part4(修改键-值对)
student["001"] = "xiaohua"
print(student)

#part5(删除键-值对)
del student["001"]
print(student)