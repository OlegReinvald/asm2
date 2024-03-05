	#include <iostream>
	using namespace std;
	
	int main() {
		int x; // task 1
		int res;
		cin >> x;
		cout << "\n\n";

		_asm {
			mov eax, x
			imul eax
			sub eax, 4
			imul eax, 2
			mov ebx, eax
			mov eax, x
			imul eax
			imul eax
			imul x
			add eax, ebx
			add eax, x
			cdq
			idiv x
			cdq
			idiv x
			cdq
			idiv x
			mov res, eax
		}
		cout << "1." << "\n";
		cout << "C++: " << int((pow(x, 5) + 2 * (x * x - 4) + x) / pow(x, 3)) << "\n";
		cout << "asm: " << res << "\n";

		_asm {
			mov eax, x
			imul eax, 2
			sub eax, 1
			mov ebx, x
			imul ebx, 2
			add ebx, 1
			imul eax, ebx
			mov ebx, x
			add ebx, 3
			imul eax, ebx
			mov ebx, x
			imul ebx, 2
			cdq
			idiv ebx
			mov res, eax
		}

		cout << "2." << "\n";
		cout << "C++: " << int((2 * x - 1) * (2 * x + 1) * (x + 3) / (2 * x)) << "\n";
		cout << "asm: " << res << "\n";

		_asm {
			mov eax, x
			mov ebx, 4
			imul ebx
			sub eax, 1
			mov ebx, x
			imul ebx, 4
			add ebx, 1
			imul eax, ebx
			mov ebx, 4
			cdq
			idiv ebx
			mov res, eax
		}
		cout << "3." << "\n";
		cout << "C++: " << int((4 * x - 1) * (4 * x + 1) / 4) << "\n";
		cout << "asm: " << res << "\n";

		cout << "\n\n"; // task 2 var 2

		int y;
		cin >> y;
		int y2 = y * y;
		int ten = 10;
		bool aphtomorph;
		_asm {
			mov eax, y
			mov ebx, 0
			flag1:
				cdq
				idiv ten
				inc ebx
				cmp eax, 0
				jne flag1
			mov eax, y2
			mov ecx, 1
		    flag2:
				imul ecx, 10
				dec ebx
				cmp ebx, 0
				jne flag2
			cdq
			idiv ecx
			cmp edx, y
			jz ZF_1
			jmp ZF_0
			ZF_1:
				mov aphtomorph, 1
				jmp ext
			ZF_0:
				mov aphtomorph, 0
			ext:
		}
		if (aphtomorph) {
			cout << "Numbers are aphtomorph";
		}
		else
		{
			cout << "Numbers aren't aphtomorph";
		}

		return 0;

	}