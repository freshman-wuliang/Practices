"""
#字典嵌套字典
#定义
#遍历
"""

#part1(定义)
print("part1:")
users = {
    "aeinstein" : {
        "first" : "albert",
        "last" : "einstein",
        "location" : "princeton"
    },
    "mcurie" : {
        "first" : "marie",
        "last" : "curie",
        "location" : "paris"
    }
}   #定义

#part2(遍历)
print("\npart2:")
for username, user_info in users.items():
    print("\nUsername:" + username)
    full_name = user_info["first"] + user_info["last"]
    location = user_info["location"]

    print("\tFull name:" + full_name.title())
    print("\tlocation:" + location.title())