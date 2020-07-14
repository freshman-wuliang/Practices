"""
#字典嵌套列表定义
#遍历每个字典元素
#使用for生成字典列表
"""

#part1(字典列表定义)
print("part1:")
alien_0 = {"color" : "green","points" : 5}   #字典1
alien_1 = {"color" : "yellow","points" : 10}   #字典2
alien_2 = {"color" : "red","points" : 15}   #字典3

aliens = [alien_0,alien_1,alien_2]   #字典列表
print(aliens)

#part2(遍历每个字典元素)
print("\npart2:")
for alien in aliens:
    print(alien)

#part3(使用for生成字典列表)
print("\npart3:")
for num in range(30):   #循环30次
    new_alien = {"color" : "green","points" : "5"}   #生成新的字典
    aliens.append(new_alien)   #将new_alien添加到aliens中
print(aliens)