"""
#使用while循环处理列表
#删除列表中的特定元素
"""

#part1(使用while循环处理列表)
print("part1:")
unconfirmed_user = ["alice","brian","candace"]
confirmed_user = []

while unconfirmed_user:
    user = unconfirmed_user.pop()

    print("Verifying user: " + user.title())

    confirmed_user.append(user)

print("\nThe following users have been confirmed:")
for user in confirmed_user:
    print(user.title())

#for循环中不应该修改列表中元素的值
#否则将导致for循环的变量难以跟踪列表元素

#part2(删除列表中的特定元素)
print("\npart2:")
pets = ["cat","dog","goldfish","cat","rabbit","cat"]
print(pets)

while "cat" in pets:
    pets.remove("cat")

print(pets)