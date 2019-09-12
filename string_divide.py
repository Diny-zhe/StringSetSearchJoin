import os
import random
import sys
files=open("string.txt","r",encoding='utf-8')
lines=[]
for file in files:
	lines.append(file)

file_write_obj = open("string9.txt", 'w',encoding='utf-8')
count=0
for line in lines:
	if count<10000 and count>=9000:
		file_write_obj.writelines(line)
	count+=1