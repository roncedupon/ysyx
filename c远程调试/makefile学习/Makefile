main:app.o main.o#main 的可执行文件需要依赖app.o和main.o文件的生成
#然后下面一句是生成main文件需要执行的语句。
	gcc  app.o main.o -o main
app.o:app.c
    gcc -c app.c

main.o:main.c
    gcc -c main.c

