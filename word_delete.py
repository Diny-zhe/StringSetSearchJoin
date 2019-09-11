import os
import sys
file = open("date_new.txt", "r",encoding='utf-8')  # 以只读模式读取文件
lines = []
for i in file:
    lines.append(i)  # 逐行将文本存入列表lines中
file.close()
news = []
count=0
char=' '
for line in lines:  # 逐行遍历
	# p = 0  # 定义计数指针
	p=line.index(char)
	news.append(line[:p]+'\n')
    # print(line[0:20]) 
    # line.replace('1','#')
    # news.append(line)
    # print(new)
# 以写的方式打开文件，如果文件不存在，就会自动创建，如果存在就会覆盖原文件
file_write_obj = open("date.txt", 'w',encoding='utf-8')
for new in news:
	# new.replace(' ','\n')
	file_write_obj.writelines(new)
    # file_write_obj.writelines('\n')
#     print(new)
