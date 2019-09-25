#include "kat.h"

int main(int argc, char** argv) {
	if (argc == 1) {
		mirror();
	}
	else if (argc == 2) {
		view(argv[1]);
	}
	else if (argc == 3) {
		cat(argv[1], argv[2]);
	}
}
