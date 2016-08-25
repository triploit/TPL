OBJ = tpl.o
CC = g++

compile: $(OBJ)
	@echo [CPP] Link tpl...
	@$(CC) -fpermissive -W -w -fstack-check -o tpl tpl.o
	@echo [CPP] Finished!
	@echo "–––––––––––––––––––––––––––"
	@rm tpl.o

tpl.o:
	@clear
	@echo "–––––––––––––––––––––––––––"
	@echo [CPP] Compile tpl...
	@$(CC) -fpermissive -W -w -fstack-check -c tpl.cpp
	@echo [CPP] Finished!
	@echo "–––––––––––––––––––––––––––"

windows:
	@clear
	@echo "[ MINGW-W64 ] Compile and Link TPL.CPP to TPL.EXE..."
	@i686-w64-mingw32-g++ -W -fstack-check -static -static-libstdc++ -static-libgcc -lpthread -fpermissive -c tpl.cpp
	@i686-w64-mingw32-g++ -W -fstack-check -static -static-libstdc++ -static-libgcc -lpthread -fpermissive -o tpl.exe tpl.o
	@echo "[ MINGW-W64 ] Finished!"
	@rm tpl.o

test: compile
	@clear
	@./tpl test.tpl

install: compile
	@echo "[CP] tpl /bin/"
	@sudo cp tpl /bin/
	@echo [CP] Finished!
	@echo "–––––––––––––––––––––––––––"
