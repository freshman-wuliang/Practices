"""
#使用输入填充字典
"""

#空字典
responses = {}

#设置循环标志
flag = True

while flag:
    #提示输入姓名
    name = input("\nwhat is your name?: ")
    #输入回答
    response = input("which mountian would you like to climb someday?: ")

    #存入字典
    responses[name] = response

    #看是否还有输入
    repeat = input("would you like to let another person respond?(yes/no)")
    if repeat == "no":
        flag = False

#显示字典
for name,response in responses.items():
    print(name + " : " + response + ".")