"""
#使用while循环遍历且修改列表练习
"""

strangers = ["xiaoming","xiaohong","xiaoli","xiaohua"]
friends = []

print(strangers)
#print(friends)

while strangers:
    person = strangers.pop()
    print("now," + person + " is my friend")
    friends.append(person)
    #print(strangers)
    #print(friends)

#print(strangers)
print(friends)

for friend in friends:
    print(friend + "is my friend")