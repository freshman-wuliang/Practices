""""
#使用while循环删除列表中的多个重复值练习
"""

fruits = ["apple","pear","watermelon","apple","mango","apple"]
print("before: " + str(fruits))

while "apple" in fruits:
    fruits.remove("apple")

print("after: " + str(fruits))