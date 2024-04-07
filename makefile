CC = gcc

ifeq ($(OS), Windows_NT)
	SHOW_FILE_CMD = type
	CLEAR_CMD = cls
	RM_CMD = del
	TARGET_EXT = .exe
else
	SHOW_FILE_CMD = bat
	CLEAR_CMD = clear
	RM_CMD = rm
	TARGET_EXT = 
endif

compile:
	$(CC) axo_gram.tab.c lex.yy.c -o axo$(TARGET_EXT) -Wall -g
	@echo "[92mCompiler built![0m"

build:
	@echo "[96mGenerating lexer...[0m"
	@flex -l scan.l
	@echo "[96mGenerating parser...[0m"
	@bison --defines axo_gram.y -Wcounterexamples -Wconflicts-rr -Wother
	@echo "[94mBuilding the compiler... [0m"
	@make -s compile

run:
	$(CLEAR_CMD)
	@make -s build
	@$(SHOW_FILE_CMD) test.axo
	@./axo$(TARGET_EXT) test.axo
	@$(SHOW_FILE_CMD) test.c
	@echo "[92mRunning output program...[0m"
	@./test$(TARGET_EXT)
	@make -s clean
	
show:
	@make -s build
	@$(SHOW_FILE_CMD) test.axo
	@$(SHOW_FILE_CMD) test.c

clean:
	@$(RM_CMD) axo$(TARGET_EXT)
	@$(RM_CMD) test.c
	@$(RM_CMD) test$(TARGET_EXT)
	

