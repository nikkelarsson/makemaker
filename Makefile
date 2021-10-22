PROG = mm
PREFIX = $(HOME)
MAN_PAGES = mm.1
BIN_INSTALL_PATH = $(PREFIX)/.local/bin/
MAN_SRC = docs/$(MAN_PAGES)
MAN_INSTALL_PATH = /usr/local/man/man1/
SRC = $(wildcard ./makemaker/*.c)
OBJ = $(SRC:.c=.o)
CC = "/usr/bin/gcc"

$(PROG): $(OBJ)
	$(CC) -o $@ $^

.PHONY: install
install: $(PROG)
	@echo "Installing $(PROG) ..."
	@mkdir -p $(BIN_INSTALL_PATH)
	cp -f $(PROG) $(BIN_INSTALL_PATH)
	@echo "$(PROG) installed to $(BIN_INSTALL_PATH)."
	@echo "Installing man pages ..."
	pandoc $(MAN_SRC).md -s -t man -o $(MAN_SRC)
	cp -f $(MAN_SRC) $(MAN_INSTALL_PATH)
	@echo "Man pages installed to $(MAN_INSTALL_PATH)."
	@echo "Installation successfull."

.PHONY: uninstall
uninstall:
	@echo "Uninstalling $(PROG) ..."
	rm -f $(BIN_INSTALL_PATH)$(PROG)
	@echo "$(PROG) uninstalled from $(BIN_INSTALL_PATH)."
	@echo "Uninstalling man pages ..."
	rm -f $(MAN_INSTALL_PATH)$(MAN_PAGES)
	@echo "Man pages uninstalled from $(MAN_INSTALL_PATH)."
	@echo "Everything uninstalled."

.PHONY: clean
clean:
	rm -f $(OBJ) $(PROG)
