OBJ = tpl.o
CC = g++

compile: $(OBJ)
	@echo [CPP] Link tpl...
	@$(CC) -fpermissive -W -w -o tpl tpl.o
	@echo [CPP] Finished!
	@echo "–––––––––––––––––––––––––––"
	@rm tpl.o

tpl.o:
	@clear
	@echo "–––––––––––––––––––––––––––"
	@echo [CPP] Compile tpl...
	@$(CC) -fpermissive -W -w -c tpl.cpp
	@echo [CPP] Finished!
	@echo "–––––––––––––––––––––––––––"

test: compile
	@clear
	@./tpl

install: compile
	@echo "[CP] tpl /bin/"
	@sudo cp tpl /bin/
	@echo [CP] Finished!
	@echo "–––––––––––––––––––––––––––"
