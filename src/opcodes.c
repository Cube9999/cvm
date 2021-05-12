#include "./opcodes.h"

Opcode get_opcode(byte index) {
	switch (index) {
	case 0:
		return LOADCONST;
	case 1:
		return ADD;
	case 2:
		return SUB;
	case 3:
		return MUL;
	case 4:
		return EQUAL;
	case 5:
		return GT;
	case 6:
		return LT;
	case 7:
		return CALL;
	case 8:
		return JUMP;
	}
}
