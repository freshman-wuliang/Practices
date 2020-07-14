"""
#字典列表(字典中含有列表)
#字典列表定义
#字典列表的遍历
"""

#part1(字典列表定义)
print("part1:")
favorite_languages = {
    "xiaoming" : ["python","ruby"],
    "xiaohua" : ["c"],
    "xiaohong" : ["ruby","go"],
    "xiaoli" : ["python","haskell"]
}   #字典里定义列表
print(favorite_languages)

#part2(字典列表的遍历)
print("\npart2:")
for key,value in favorite_languages.items():   #遍历所有键-值对
    print("\n" + key.title() + "'s favorite language are:")
    for language in value:   #遍历列表
        print("\t" + language.title())