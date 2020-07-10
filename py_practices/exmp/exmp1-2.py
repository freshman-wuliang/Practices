"""
#字符串的使用和
# title()
# upper()
# lower()
# 字符串合并
#制表符\t、\n的使用
#删除字符串多于的空白：剔除两端空白strip()
#                    剔除前面空白lstrip()
#                    剔除后面空白rstrip()
# 使用实例
"""

#part1
name = "ada lovelace"
print(name.title())   #title()方法将字符串以首字母大写的形式显示

#part2
name = "Ada Lovelace"
print(name.upper())
print(name.lower())

#part3
first_name = "ada"
last_name = "lovelace"
full_name = first_name + " " + last_name   #使用'+'号来合并两个字符串

print(full_name)

#part4
print("\tPython")
print("Languages:\nPython\nC\nJavaScript")

#part5
favorite_language = 'python '
favorite_language
favorite_language.rstrip()