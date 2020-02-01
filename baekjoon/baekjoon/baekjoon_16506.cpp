#include <iostream>
#include <map>
#include <string>
using namespace std;

using  opcode = map<string, string>;
using digit = map<int, string>;
digit reg;
opcode inst;
int main()
{
	inst["ADD"] = "00000";
	inst["ADDC"] = "00001";

	inst["SUB"] = "00010";
	inst["SUBC"] = "00011";

	inst["MOV"] = "00100";
	inst["MOVC"] = "00101";

	inst["AND"] = "00110";
	inst["ANDC"] = "00111";

	inst["OR"] = "01000";
	inst["ORC"] = "01001";

	inst["NOT"] = "01010";

	inst["MULT"] = "01100";
	inst["MULTC"] = "01101";

	inst["LSFTL"] = "01110";
	inst["LSFTLC"] = "01111";

	inst["LSFTR"] = "10000";
	inst["LSFTRC"] = "10001";

	inst["ASFTR"] = "10010";
	inst["ASFTRC"] = "10011";

	inst["RL"] = "10100";
	inst["RLC"] = "10101";

	inst["RR"] = "10110";
	inst["RRC"] = "10111";

	reg[0] = "000";
	reg[1] = "001";
	reg[2] = "010";
	reg[3] = "011";
	reg[4] = "100";
	reg[5] = "101";
	reg[6] = "110";
	reg[7] = "111";
	reg[8] = "1000";
	reg[9] = "1001";
	reg[10] = "1010";
	reg[11] = "1011";
	reg[12] = "1100";
	reg[13] = "1101";
	reg[14] = "1110";
	reg[15] = "1111";
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for (int test_case = 1; test_case <= T; test_case++)
	{
		string op;
		int rd, ra, rb;
		cin >> op >> rd >> ra >> rb;				
		
		string op_an = inst[op];
		string rd_an = reg[rd];
		string ra_an = reg[ra];
		string rb_an = reg[rb];
		if (op_an.back() == '0')
			rb_an += "0";
		else {
			if (rb < 8)
				rb_an = "0" + rb_an;
		}

		string answer = op_an + "0" + rd_an + ra_an + rb_an;
		cout << answer << "\n";
	}

	return 0;
}