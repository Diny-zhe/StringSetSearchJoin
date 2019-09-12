import os
import sys
import random
import datetime
oldtime=datetime.datetime.now()
# 创建随机数
# def Create_Random(var,)
file=open("final_1500.txt","r",encoding='utf-8')
words=[]
for i in file:
	words.append(i)
file.close()
news=[]#需要生成的字符串集
string_number=10000
while string_number>0:
	var=""
	m=random.randint(3,10)#用来指定需要多少个单词来生成当前的字符串
	print("m="+str(m))
	while m > 0:
		n=random.randint(0,1694)#用来指定选择那些单词构成字符串
		print("n="+str(n))
		var+=words[n]
		m-=1
	var=var.replace('\n','')
	print(var)
	news.append(var+'\n')
	string_number-=1
file_write_obj = open("string.txt", 'w',encoding='utf-8')
for new in news:
	file_write_obj.writelines(new)

newtime=datetime.datetime.now()
print (u'相差：%s'%(newtime-oldtime))
print (u'相差：%s微秒'%(newtime-oldtime).microseconds)
print (u'相差：%s秒'%(newtime-oldtime).seconds)