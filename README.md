# StringSetSearchJoin
单词集构造：
word_list_processed文件中有四个单词集数据，格式为txt，数据形式为纯单词；

word_list_unprocessed文件中是未经过处理的单词集或字典原数据；

word_delete.py是用来处理单词数据的程序，可通过适当修改方便使用；

字符串数据集构造：
string.txt包含10000个字符串，且均为完整单词生成的字符串（来自1500个计算机专业单词）；

create_string.py使用随机数挑选单词生成长度不一的字符串（由正常单词构成，单词来自string.txt）；

string_divide.py将10000个字符串分开，分成string0.txt-string9.txt等10个文本，每个文本包含1000个字符串，互不相交）；

process_string.py将1000个字符串进行按照编辑距离从0-9对string0.txt-string9.txt进行改造，其中每个文本中300个随机增加、300个随机删除、400个随机替换；

string_final0-9.txt由10个改造后的文本合成的新1000个字符串数据，其中1000条没有改变，1000条改为与原串ED=1的字符串，...，1000条与原串ED=9的字符串；

middle_file文件夹中包含改造过程中string0.txt-string9.txt、string_ed1.txt-string_ed9.txt等中间文件，方便以后取用；


