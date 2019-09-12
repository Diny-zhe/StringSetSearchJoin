import os
import random
import sys
import datetime
oldtime=datetime.datetime.now()
files=open("string9.txt","r",encoding='utf-8')
lines=[]
for file in files:
	lines.append(file)
news=[]
Edit_Diatance=9
count=len(lines)
# print(count)
counts=[]
for line in lines:
	if count>700:
		#增加
		print(line)
		count_number=0
		while count_number<Edit_Diatance:
			add_rand=random.randint(0,len(line)-1)
			a=random.randint(97,122)
			c=chr(a)
			var=line[0:add_rand]+c+line[add_rand:]
			line=var
			count_number+=1
		print(line)
		print(count)
		counts.append(count)
		news.append(line)
	elif count>=400 and count<=700:
		#删减
		print(line)
		count_number=0
		while count_number<Edit_Diatance:
			delete_rand=random.randint(0,len(line)-2)
			var=line[0:delete_rand]+line[delete_rand+1:]
			line=var
			count_number+=1
		print(line)
		print(count)
		counts.append(count)
		news.append(line)
	else:
		#替换
		print(line)
		count_number=0
		while count_number<Edit_Diatance:
			change_rand=random.randint(0,len(line)-2)
			a=random.randint(97,122)
			c=chr(a)
			var=line[0:change_rand]+c+line[change_rand+1:]
			line=var
			count_number+=1
		print(line)
		print(count)
		counts.append(count)
		news.append(line)
	count-=1
file_write_obj = open("string_ed9.txt", 'w',encoding='utf-8')
for new in news:
	file_write_obj.writelines(new)

file_write_obj = open("count.txt", 'w',encoding='utf-8')
for count in counts:
	file_write_obj.writelines(str(count)+"\n")
print(len(counts))
print(len(news))
newtime=datetime.datetime.now()
print (u'相差：%s'%(newtime-oldtime))
print (u'相差：0.%s秒'%(newtime-oldtime).microseconds)

