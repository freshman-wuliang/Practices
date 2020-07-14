"""
#if-elif-else语句练习
#打印列表特定值
"""

numbers = list(range(1,11))
print(numbers)
for number in numbers:
    if number == 1:
        print(str(number) + "st")
    elif number == 2:
        print(str(number) + "nd")
    elif number == 3:
        print(str(number) + "rd")
    else:
        print(str(number) + "th")
