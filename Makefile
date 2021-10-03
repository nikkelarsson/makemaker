.PHONY: clean install uninstall
PROGRAM = mm
MAN_PAGES = mm.1
BIN_INSTALL_PATH = $(HOME)/.local/bin/
MAN_SRC = docs/$(MAN_PAGES)
MAN_INSTALL_PATH = /usr/local/man/man1/
SRC = $(wildcard ./makemaker/*.c)
OBJ = $(SRC:.c=.o)
CC = "/usr/bin/gcc"

mm: $(OBJ)
	$(CC) -o $@ $^

install:
	@echo "Installing $(PROGRAM) ..."
	@mkdir -p $(BIN_INSTALL_PATH)
	cp -f $(PROGRAM) $(BIN_INSTALL_PATH)
	@echo "$(PROGRAM) installed to $(BIN_INSTALL_PATH)."
	@echo "Installing man pages ..."
	cp -f $(MAN_SRC) $(MAN_INSTALL_PATH)
	@echo "Man pages installed to $(MAN_INSTALL_PATH)."
	@echo "Installation successfull."

uninstall:
	@echo "Uninstalling $(PROGRAM) ..."
	rm -f $(BIN_INSTALL_PATH)$(PROGRAM)
	@echo "$(PROGRAM) uninstalled from $(BIN_INSTALL_PATH)."
	@echo "Uninstalling man pages ..."
	rm -f $(MAN_INSTALL_PATH)$(MAN_PAGES)
	@echo "Man pages uninstalled from $(MAN_INSTALL_PATH)."
	@echo "Everything uninstalled."

clean:
	rm -f $(OBJ) $(PROGRAM)
