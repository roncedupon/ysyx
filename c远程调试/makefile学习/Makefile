main:app.o main.o#main 的可执行文件需要依赖app.o和main.o文件的生成
#然后下面一句是生成main文件需要执行的语句。
	gcc  app.o main.o -o main
app.o:app.c
    gcc -c app.c

main.o:main.c
    gcc -c main.c

#最基本的makefile语句由三部分组成
#冒号之前为目标,冒号后面的是依赖关系表,也就是编译冒号前的目标所需的文件
#最后的就是编译指令
# calc:main.c getch.c getop.c stack.calc
#      gcc -o calc main.c getch.c getop.c stack.c #makefile的任何命令之前必须有一个tab缩进

