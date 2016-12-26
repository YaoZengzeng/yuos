#include <inc/string.h>
#include <inc/stdio.h>
#include <kern/console.h>

void
i386_init(void)
{
	extern char edata[], end[];

	// Before doing anything else, complete the ELF loading process.
	// Clear the unitialized global data (BSS) section of our program.
	// This ensures that all static/global variables start out zero.
	memset(edata, 0, end - edata);

	// Initialize the console.
	// Can't call cprintf until after we do this!
	cons_init();

	cprintf("Hello, I'm Yu-OS\n");
	char *line = readline("K>");
	cprintf("readline: %s\n", line);
}