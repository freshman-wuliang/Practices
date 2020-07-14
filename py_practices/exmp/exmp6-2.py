"""
#由类似的对象组成的字典
#遍历字典：
#遍历所有键-值对（使用字典的items()方法）
#遍历所有键(使用keys()方法)
#顺序遍历所有键(对keys()方法再使用sorted()函数)
#遍历所有值(使用values()方法)
"""

#part1(类似对象组成的字典)
print("part1:")
favorite_languages = {
    "xiaoming":"python",
    "xiaohua":"c",
    "xiaoli":"c++",
    "xiaohong":"java"
}   #定义比较长的字典时使用上面的方式，可读性更好
print(favorite_languages)

#part2(遍历所有键-值对)
print("\npart2:")
for key,value in favorite_languages.items():
    print("\nkey: " + key)
    print("value: " + value)

#part3(遍历所有键)
print("\npart3:")
for key in favorite_languages.keys():
    print("key:" + key)
#keys()方法返回一个列表
#可以使用列表的一系列方法

#part4(顺序遍历所有键)
print("\npart4:")
for key in sorted(favorite_languages.keys()):
    print("key: " + key)

#part5(遍历所有值)
print("\npart5:")
for value in favorite_languages.values():
    print("value: " + value)
#也可以使用sorted()函数对结果排序