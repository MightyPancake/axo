
build:
	gcc main.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o prog.exe
	@echo "[92mProject built![0m" 

clean:
	@rm client
	@rm server
	@echo "Cleaned binaries."
	
run:
	@make -s build
	@echo "[92mRunning the program...[0m"
	@./prog.exe

client:
	@gcc client.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o client

server:
	@gcc server.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o server

both:
	@make -s server
	@make -s client

nixboth:
	@nix-shell -p raylib --run "make -s both"
nixrun:
	@nix-shell -p raylib --run "make run"
	
