#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

#define	MAX_LINE	250

char t[MAX_LINE + 1];

int main(int argc, char *argv[])
{
	regex_t         a;
	if (argc != 1 + 1) {
		fprintf(stderr, "%s WZORZEC\n", argv[0]);
		return 1;
	}
	if (regcomp(&a, argv[1], REG_EXTENDED | REG_NOSUB | REG_NEWLINE)) {
		fprintf(stderr, "%s: regcomp FAILED!\n\n", argv[0]);
		return 2;
	}
	while (fgets(t, MAX_LINE, stdin)) {
		if (!regexec(&a, t, 0, 0, 0))
			printf("pasuje: ");
		else
			printf("NIE pasuje: ");
		printf("\"%s\"\n", t);
	}
	regfree(&a);
	return 0;
}
