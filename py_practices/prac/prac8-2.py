"""
#函数练习
"""

def make_shirt(ts_size = 0,ts_print = "I love Python"):
    print("size: " + str(ts_size) + "\t" + "print: " + ts_print)

#带完整参数的调用
make_shirt(30,"I love C language")

#缺省一个参数的调用
make_shirt(25)
make_shirt(ts_print = "I love C++ language")

#缺省全部参数的调用
make_shirt()