CC=gcc

compile:
	gcc axo_gram.tab.c lex.yy.c -o axo.exe -Wall -g
	@echo "[92mCompiler built![0m"

build:
	@echo "[96mGenerating lexer...[0m"
	flex -l scan.l
	@echo "[96mGenerating parser...[0m"
	bison --defines axo_gram.y -Wcounterexamples -Wconflicts-rr -Wother
	@echo "[94mBuilding the compiler... [0m"
	@make -s compile

run:
	clear
	@make -s build
	@bat test.axo
	@./axo.exe test.axo
	@bat test.c
	@echo "[92mRunning output program...[0m"
	@./test.exe
	@make -s clean

show:
	@make -s build
	@bat test.axo
	@bat test.c

clean:
	@rm axo.exe
	@rm test.c
	@rm test.exe

playground:
	clear
	@make -s build
	@./axo.exe

