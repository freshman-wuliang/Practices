"""
#字符串空白剔除练习
#使用strip(),lstrip(),rstrip()
"""

name = "   \twuliang\n    "
print("剔除前")
print(name)
print("剔除前端空白")
print(name.lstrip())
print("剔除后端空白")
print(name.rstrip())
print("剔除两端空白")
print(name.strip())