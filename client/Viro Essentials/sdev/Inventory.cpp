#include "include/main.h"	
#include "util/util.h"

DWORD inven_adjust_return = 0x005181EF;
_declspec(naked) void inven_adjust() {
	_asm {
		add ecx, -0x21
		push ecx
		push edi
		push - 0x01
		lea ecx, [esi + 0x000000724]
		jmp inven_adjust_return
	}
}

float float_15_2 = 15.0f;
float float_282 = 282.0f;
DWORD adjust_slot_inven_x_return = 0x0051A5E4;
DWORD adjust_slot_inven_y_return = 0x0051A603;
_declspec(naked) void adjust_slot_inven_x() {
	_asm {
		fld dword ptr ds : [float_15_2]
		jmp adjust_slot_inven_x_return
	}
}

_declspec(naked) void adjust_slot_inven_y() {
	_asm {
		push eax
		mov eax, float_282
		mov dword ptr ds : [esi + 0x768] , eax
		pop eax
		fld dword ptr ds : [esi + 0x768]
		jmp adjust_slot_inven_y_return
	}
}
float float_23 = 23.00f;
float float_53 = 53.00f;
float float_92 = 92.00f;
float float_132 = 132.00f;
float float_172 = 172.00f;
float float_213 = 213.00f;
float float_191 = 191.00f;
float float_77 = 77.00f;
float float_195 = 195.00f;
float float_133 = 133.00f;
float float_101 = 101.00f;
float float_215 = 215.00f;
float float_155 = 155.00f;
float float_167 = 167.00f;
float float_230 = 230.00f;
float float_481 = 481.00f;



DWORD slot_adjust_return = 0x0051A7F7;
_declspec(naked) void inven_slot_adjust() {
	_asm {
		push edx
		mov edx, float_23
		mov dword ptr ds:[esi+0x00000794], edx
		mov edx, float_53
		mov dword ptr ds:[esi+0x00000798], edx
		mov edx, float_23
		mov dword ptr ds:[esi+0x0000079C], edx
		mov edx, float_92
		mov dword ptr ds:[esi+0x000007A0], edx
		mov edx, float_23
		mov dword ptr ds:[esi+0x000007A4], edx
		mov edx, float_132
		mov dword ptr ds:[esi+0x000007A8], edx
		mov edx, float_23
		mov dword ptr ds:[esi+0x000007AC], edx
		mov edx, float_172
		mov dword ptr ds:[esi+0x000007B0], edx
		mov edx, float_23
		mov dword ptr ds:[esi+0x000007B4], edx
		mov edx, float_213
		mov dword ptr ds:[esi+0x000007B8], edx
		mov edx, float_195
		mov dword ptr ds:[esi+0x000007BC], edx
		mov edx, float_133
		mov dword ptr ds:[esi+0x000007C0], edx
		mov edx, float_195
		mov dword ptr ds:[esi+0x000007C4], edx
		mov edx, float_172
		mov dword ptr ds:[esi+0x000007C8], edx
		mov edx, float_195
		mov dword ptr ds:[esi+0x000007CC], edx
		mov edx, float_213
		mov dword ptr ds:[esi+0x000007D0], edx
		mov edx, float_191
		mov dword ptr ds:[esi+0x000007D4], edx
		mov edx, float_53
		mov dword ptr ds:[esi+0x000007D8], edx
		mov edx, float_191
		mov dword ptr ds:[esi+0x000007DC], edx
		mov edx, float_77
		mov dword ptr ds:[esi+0x000007E0], edx
		mov edx, float_215
		mov dword ptr ds:[esi+0x000007E4], edx
		mov edx, float_77
		mov dword ptr ds:[esi+0x000007E8], edx
		mov edx, float_191
		mov dword ptr ds:[esi+0x000007EC], edx
		mov edx, float_101
		mov dword ptr ds:[esi+0x000007F0], edx
		mov edx, float_215
		mov dword ptr ds:[esi+0x000007F4], edx
		mov edx, float_101
		mov dword ptr ds:[esi+0x000007F8], edx
		mov edx, float_215
		mov dword ptr ds:[esi+0x000007FC], edx
		mov edx, float_53
		mov dword ptr ds:[esi+0x00000800], edx
		mov edx, float_167
		mov dword ptr ds:[esi+0x00000804], edx
		mov edx, float_53
		mov dword ptr ds:[esi+0x00000808], edx
		mov edx, float_155
		mov dword ptr ds:[esi+0x0000080C], edx
		mov edx, float_213
		mov [esi+0x00000810], edx
		mov edx, float_167
		mov dword ptr ds:[esi+0x00000814], edx
		mov edx, float_77
		mov dword ptr ds:[esi+0x00000818], edx
		mov edx, float_230
		mov dword ptr ds:[esi+0x00000844], edx
		mov edx, float_481
		mov dword ptr ds:[esi+0x00000848], edx
		pop edx
		





		fld dword ptr ds : [esi + ebx * 0x8 + 0x00000794]
		jmp slot_adjust_return
	}
}

float float_24 = 24.0f;
float float_93 = 93.0f;

float float_173 = 173.0f;


float float_216 = 216.0f;




DWORD adjust_inspect_slots_return = 0x00479A70;
_declspec(naked) void adjust_inspect_slots() {
	_asm {
		mov edx, float_24
		mov dword ptr ds : [esi + 0x6D8] , edx
		mov edx, float_53
		mov dword ptr ds : [esi + 0x6DC] , edx
		mov edx, float_24
		mov dword ptr ds : [esi + 0x6E0] , edx
		mov edx, float_93
		mov dword ptr ds : [esi + 0x6E4] , edx
		mov edx, float_24
		mov dword ptr ds : [esi + 0x6E8] , edx
		mov edx, float_133
		mov dword ptr ds : [esi + 0x6EC] , edx
		mov edx, float_24
		mov dword ptr ds : [esi + 0x6F0] , edx
		mov edx, float_173
		mov dword ptr ds : [esi + 0x6F4] , edx
		mov edx, float_24
		mov dword ptr ds : [esi + 0x6F8] , edx
		mov edx, float_213
		mov dword ptr ds : [esi + 0x6FC] , edx
		mov edx, float_195
		mov dword ptr ds : [esi + 0x700] , edx
		mov edx, float_133
		mov dword ptr ds : [esi + 0x704] , edx
		mov edx, float_195
		mov dword ptr ds : [esi + 0x708] , edx
		mov edx, float_173
		mov dword ptr ds : [esi + 0x70C] , edx
		mov edx, float_195
		mov dword ptr ds : [esi + 0x710] , edx
		mov edx, float_216
		mov dword ptr ds : [esi + 0x714] , edx
		mov edx, float_191
		mov dword ptr ds : [esi + 0x718] , edx
		mov edx, float_53
		mov dword ptr ds : [esi + 0x71C] , edx
		mov edx, float_191
		mov dword ptr ds : [esi + 0x720] , edx
		mov edx, float_77
		mov dword ptr ds : [esi + 0x724] , edx
		mov edx, float_215
		mov dword ptr ds : [esi + 0x728] , edx
		mov edx, float_77
		mov dword ptr ds : [esi + 0x72C] , edx
		mov edx, float_191
		mov dword ptr ds : [esi + 0x730] , edx
		mov edx, float_101
		mov dword ptr ds : [esi + 0x734] , edx
		mov edx, float_215
		mov dword ptr ds : [esi + 0x738] , edx
		mov edx, float_101
		mov dword ptr ds : [esi + 0x73C] , edx
		fld dword ptr ds : [esi + edi * 0x8 + 0x000006D8]
		jmp adjust_inspect_slots_return
	}
}

float float_gold = 460.0f;
float float_gold_y = 224.0f;
DWORD adjust_pos_gold_return = 0x0051AAD5;
DWORD adjust_pos_gold_y_return = 0x0051AAE4;
_declspec(naked) void adjust_pos_gold() {
	_asm {
		fld dword ptr ds : [float_gold]
		jmp adjust_pos_gold_return
	}
}

_declspec(naked) void adjust_pos_gold_y() {
	_asm {
		fld dword ptr ds : [float_gold_y]
		jmp adjust_pos_gold_y_return
	}
}
DWORD bag_adjust_return = 0x00518205;
DWORD bag_adjust_return_2 = 0x0051822B;
DWORD bag_adjust_return_3 = 0x00518273;
DWORD bag_adjust_return_4 = 0x005182D4;
DWORD bag_adjust_return_5 = 0x0051831A;
DWORD bag_adjust_return_6 = 0x00518348;
DWORD bag_adjust_return_7 = 0x0051838D;
DWORD bag_adjust_return_8 = 0x0051819F;
_declspec(naked) void bag_adjust() {
	_asm {
		add eax, 252
		jmp bag_adjust_return
	}
}

_declspec(naked) void bag_adjust_2() {
	_asm {
		add eax, 255
		jmp bag_adjust_return_2
	}
}

_declspec(naked) void bag_adjust_3() {
	_asm {
		add ecx, 0xFC
		jmp bag_adjust_return_3
	}
}

_declspec(naked) void bag_adjust_4() {
	_asm {
		add eax, 0xFC
		jmp bag_adjust_return_4
	}
}

_declspec(naked) void bag_adjust_5() {
	_asm {
		add ecx, 0xFB
		jmp bag_adjust_return_5
	}
}

_declspec(naked) void bag_adjust_6() {
	_asm {
		add edx, 0xFF
		jmp bag_adjust_return_6
	}
}

_declspec(naked) void bag_adjust_7() {
	_asm {
		add eax, 0xFF
		jmp bag_adjust_return_7
	}
}
DWORD send_high = 0x005182A5;
_declspec(naked) void bag_adjust_8() {
	_asm {
		sub ebp, 0x20
		cmp edx, ebp
		jg _send_higher_conditional

		jmp bag_adjust_return_8

		_send_higher_conditional :
		jmp send_high
	}
}
DWORD send_conditional_addr = 0x005182A9;
DWORD hover_inven_adjust_return = 0x00518191;
_declspec(naked) void hover_inven_adjust() {
	_asm {
		push ecx
		sub ecx, 0x20
		cmp edx, ecx
		pop ecx
		jl send_conditional
		jmp hover_inven_adjust_return

		send_conditional :
		jmp send_conditional_addr
	}
}
float float_235 = 235.0f;
DWORD put_bag_items_adjust_return = 0x0051A274;
_declspec(naked) void put_bag_items_adjust() {
	_asm {
		push eax
		mov eax, float_235
		mov dword ptr ds : [esi + 0x788] , eax
		pop eax
		fld dword ptr ds : [esi + 0x00000788]
		jmp put_bag_items_adjust_return
	}
}
float float_248 = 248.0f;
DWORD click_y_inven_bag_return = 0x0051A15D;
_declspec(naked) void click_y_inven_bag() {
	_asm {
		push eax
		mov eax, float_248
		mov dword ptr ds : [esi + 0x780] , eax
		pop eax
		fld dword ptr ds : [esi + 0x780]
		jmp click_y_inven_bag_return
	}
}

DWORD adjust_pos_char_y_light_return = 0x005184C3;
_declspec(naked) void adjust_pos_char_y_light() {
	_asm {
		sub eax, 238
		jmp adjust_pos_char_y_light_return
	}
}

DWORD adjust_pos_char_y_dark_return = 0x005184FC;
_declspec(naked) void adjust_pos_char_y_dark() {
	_asm {
		sub eax, 238
		jmp adjust_pos_char_y_light_return
	}
}
void hook::Inventory() {
	util::detour((void*)0x0051A7F0, inven_slot_adjust, 7);
	util::detour((void*)0x005181E5,inven_adjust, 10);
	util::detour((void*)0x0041A5DE, adjust_slot_inven_x, 6);
	util::detour((void*)0x0051A5FD, adjust_slot_inven_y, 6);

	/*Hook((void*)0x00479A69, adjust_inspect_slots, 7);
	Hook((void*)0x0051AACF, adjust_pos_gold, 6);
	Hook((void*)0x0051AADE, adjust_pos_gold_y, 6);
	Hook((void*)0x00518200, bag_adjust, 5);
	Hook((void*)0x00518226, bag_adjust_2, 5);
	Hook((void*)0x0051826D, bag_adjust_3, 6);
	Hook((void*)0x005182CF, bag_adjust_4, 5);
	Hook((void*)0x00518314, bag_adjust_5, 6);
	Hook((void*)0x00518342, bag_adjust_6, 6);
	Hook((void*)0x00518388, bag_adjust_7, 5);
	Hook((void*)0x00518197, bag_adjust_8, 8);
	Hook((void*)0x00518189, hover_inven_adjust, 8);
	Hook((void*)0x0051A26E, put_bag_items_adjust, 6);
	Hook((void*)0x0051A157, click_y_inven_bag, 6);
	Hook((void*)0x005184BE, adjust_pos_char_y_light, 5);
	Hook((void*)0x005184F7, adjust_pos_char_y_dark, 5);
	*/
}
