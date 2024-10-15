CC = gcc
RM = rm
CLEAR_CMD = clear
SHOW_FILE_CMD = cat
BISON_FLAGS = -v --defines -d

ifeq ($(OS), Windows_NT)
	TARGET = Windows
	SHOW_FILE_CMD = type
	CLEAR_CMD = cls
	RM = del
	TARGET_EXT = .exe
	LUA_TARGET = mingw
else
	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S), Darwin)
		TARGET = MacOS
	else
		TARGET = Linux
		BISON_FLAGS = -v --defines -d -Wcounterexamples -Wconflicts-rr -Wother
	endif
endif


default: build

compile:
	$(CC) axo_gram.tab.c lex.yy.c src/axo.c src/utils/utils.c src/utils/hashmap/hashmap.c -o axo$(TARGET_EXT) -Wall -g -L./src/lua/src -llua -lm
	@echo [92mCompiler built![0m

gen:
	@echo [96mGenerating lexer...[0m
	@flex --header-file=lex.yy.h -o lex.yy.c -d -R scan.l
	@echo [96mGenerating parser...[0m
	@bison -d axo_gram.y $(BISON_FLAGS)
	@echo [94mBuilding the compiler... [0m

build:
	@make lua -s
	@make -s gen
	@make -s compile

gh_build:
	@make lua -s
	@make compile -s

wasm:
	@make -s gen
	emcc axo_gram.tab.c src/axo.c src/utils/utils.c src/utils/hashmap/hashmap.c lex.yy.c \
    ./src/lua/src/lapi.c ./src/lua/src/lauxlib.c ./src/lua/src/lbaselib.c ./src/lua/src/lcode.c ./src/lua/src/ldblib.c ./src/lua/src/ldebug.c ./src/lua/src/ldo.c ./src/lua/src/ldump.c \
    ./src/lua/src/lfunc.c ./src/lua/src/lgc.c ./src/lua/src/linit.c ./src/lua/src/liolib.c ./src/lua/src/llex.c ./src/lua/src/lmathlib.c ./src/lua/src/lmem.c ./src/lua/src/loadlib.c \
    ./src/lua/src/lobject.c ./src/lua/src/lopcodes.c ./src/lua/src/loslib.c ./src/lua/src/lparser.c ./src/lua/src/lstate.c ./src/lua/src/lstring.c ./src/lua/src/ltable.c \
    ./src/lua/src/ltm.c ./src/lua/src/lundump.c ./src/lua/src/lvm.c ./src/lua/src/lzio.c ./src/lua/src/lcorolib.c ./src/lua/src/lstrlib.c ./src/lua/src/lutf8lib.c ./src/lua/src/ltablib.c ./src/lua/src/lctype.c \
    -o playground.js \
	-s MODULARIZE=1 \
    -s WASM=1 --preload-file "modules" \
	-g -gsource-map \
    -s STACK_SIZE=20971520 -s INITIAL_MEMORY=33554432 \
	-s EXPORT_ES6=1 \
    -s EXPORTED_RUNTIME_METHODS='["cwrap", "stringToUTF8", "UTF8ToString"]' \
    -s EXPORTED_FUNCTIONS='["_axo_compile_to_c", "_luaL_newstate", "_luaL_openlibs", "_luaL_loadstring", "_lua_tolstring", "_lua_close"]' \
    -lm
	@mv ./playground.js docs/playground/playground.js
	@mv ./playground.wasm docs/playground/playground.wasm
	@mv ./playground.wasm.map docs/playground/playground.wasm.map
	@mv ./playground.data docs/playground/playground.data
	@cp -r ./modules ./docs/playground/modules

clear_wasm:
	$(RM) playground.js
	$(RM) playground.wasm
	$(RM) playground.wasm.map
	$(RM) playground.data

run:
	$(CLEAR_CMD)
	@make -s build
	@$(SHOW_FILE_CMD) test.axo
	@./axo$(TARGET_EXT) test.axo
	@$(SHOW_FILE_CMD) test.c
	@echo [92mRunning output program...[0m
	@./test$(TARGET_EXT)
	@make -s clean
	
show:
	@make -s build
	@$(SHOW_FILE_CMD) test.axo
	@$(SHOW_FILE_CMD) test.c

clean:
	@make clean_lua -s
	@$(RM) axo_gram.tab.c
	@$(RM) axo_gram.tab.h
	@$(RM) lex.yy.c
	@$(RM) lex.yy.h
	@$(RM) axo$(TARGET_EXT)
	
debug_test:
	@make -s build
	valgrind --track-origins=yes axo test.axo

dbg:
	@clear
	@make -s
	valgrind axo run test.axo

dbgf:
	@clear
	@make -s
	valgrind --leak-check=full axo run test.axo

lua:
	@echo [95mBuilding local lua...[0m
	@cd src/lua/src && make $(LUA_TARGET)
	@echo [95mLua built sucessfully![0m

lua_wasm:
	@echo [95mBuilding wasm lua...[0m
	@cd src/lua/src && make wasm
	@echo [95mLua built sucessfully![0m

clean_lua:
	@echo [95mDeleting local lua[0m
	@cd src/lua/src && make clean -s
	@echo [95mLua deleted![0m


commit:
	@clear
	@echo [96mPreparing commit...[0m
	@make -s
	@make -s clean
	@make gen
	git add .
	@echo [96mDone! Name the commit and push it.[0m
	
