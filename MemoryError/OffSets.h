#pragma once

//npc offsets/////////////////////////////////////////////////////////////////////
//start correction
//DWORD npcoff1 = 0x40;
//datablock size
WORD npcoff2 = 0x10f0;
//x
WORD npcoff11 = 0x37C;
//y
WORD npcoff22 = 0x384;
//name
WORD npcoffname = 0x148;
//anim
WORD npcoff33 = 0xD68;
// local ? 06 other 02
WORD npcoff44 = 0xc;
// player nr? 00
WORD npcoff55 = 0x76;
// id 
WORD npcoff66 = 0x1010;
// life 
WORD npcoff77 = 0x1048;
//combat
WORD npctest77 = 0x106C;
//floor
WORD npcoff88 = 0x288;
//activ 1
WORD npca1 = 0x8;
//activ 2
WORD npca2 = 0xc;
// local ? 06
WORD npcoff99 = 0xc;
// hover
WORD npcoff111 = 0x4B4;
// movin, 144 not, 152 startin, 156 full speed
WORD npcoff222 = 0x298;
//xmid
WORD npcoffxm = 0x88;
//ymid
WORD npcoffym = 0x8c;
//xsize
WORD npcoffxsize = 0x80;
//ysize
WORD npcoffysize = 0x90;
///player///////////////////////////////////////////////////////////
//start correction
WORD poff1 = 0x40;
//datablock size
WORD poff2 = 0x2000;
//x
WORD poff11 = 0x37C;
//y
WORD poff22 = 0x384;
//name
WORD poffname = 0x148;
//anim
WORD poff33 = 0xD68;
// local ? 06 other 02
WORD poff44 = 0xc;
// player nr? 00
WORD poff55 = 0x76;
// id 
WORD poff66 = 0x1010;
// life 
WORD poff77 = 0x1048;
//combat
WORD ptest77 = 0x106C;
//floor
WORD poff88 = 0x288;
//activ 1
WORD pa1 = 0x8;
//activ 2
WORD pa2 = 0xc;
// local ? 06
WORD poff99 = 0xc;
// hover
WORD poff111 = 0x4B4;
// movin, 144 not, 152 startin, 156 full speed
WORD poff222 = 0x298;
//pray type
WORD poff1111 = 0x1068;
////////////////////////Interfaces1///////////////////////////////////////////
//dif
WORD Ioff2 = 0x278;
//points to text
WORD Ioff00 = 0xb8;
//x
WORD Ioff11 = 0x70;
//y
WORD Ioff22 = 0x74;
//xs
WORD Ioff33 = 0x78;
//ys
WORD Ioff44 = 0x7c;
//xs2
WORD Ioff332 = 0x90;
//ys2
WORD Ioff442 = 0x94;
//ids
WORD Ioff55 = 0x30;
//hover
WORD Ioffhhh = 0x1A0;
//activ
WORD Ioff555 = 0x8;
WORD Ioff666 = 0xc;
//text
//WORD Ioff4 = 0x334;
//odd data array//timer
WORD Itimeroff = 0x1a8;
WORD Itimeroff2 = 0x150;
//////////////////////////Interface2//////////////////////////////////////////////////
//dif
WORD I2off2 = 0x290;
//points to text
WORD I2off00 = 0xb8;
//x
WORD I2off11 = 0x70;
//y
WORD I2off22 = 0x74;
//xs
WORD I2off33 = 0x78;
//ys
WORD I2off44 = 0x7c;
//xs2
WORD I2off332 = 0x90;
//ys2
WORD I2off442 = 0x94;
//ids
WORD I2off55 = 0x30;
//item ids
WORD I2offitemids = 0x1f8;
//hover
WORD Ioffhhh2 = 0x1A0;
//activ
WORD I2off555 = 0x8;
WORD I2off666 = 0xc;
//text
//WORD I2off4 = 0x334;
//odd data array//timer?
WORD I2timeroff = 0x3e8;
//////////////////////////BankInterfaces//////////////////////////////////////////////////
//dif
WORD I3off2 = 0x2a0;
//x
WORD I3off11 = 0x70;
//y
WORD I3off22 = 0x74;
//xs
WORD I3off33 = 0x78;
//ys
WORD I3off44 = 0x7c;
//xs2
WORD I3off332 = 0x90;
//ys2
WORD I3off442 = 0x94;
//ids
WORD I3off55 = 0x30;
//item ids
WORD I3offitemids = 0x1f0;
//hover
WORD Ioffhhh3 = 0x198;
//activ
WORD I3off555 = 0x8;
WORD I3off666 = 0xc;
//text
//WORD I2off4 = 0x334;
//odd data array//timer
WORD I3timeroff = 0x3e8;
////////////////activobjects//////////////////////////////////////////////////////////////////////
//dif//step
DWORD aooff2 = 0x300;
//y
DWORD aooff11 = 0x15c;
//x
DWORD aooff22 = 0x160;
//ids
DWORD aooff33 = 0x198;
//ids unique
DWORD aooff44 = 0x118;
//choped down boolean
DWORD aooff77 = 0x17d;
//activ
DWORD aooff55 = 0x8;
DWORD aooff66 = 0xc;
//xm
DWORD aooffxm = 0x88;
//ym
DWORD aooffym = 0x8c;
//xs
DWORD aooffxs = 0x80;
//ys
DWORD aooffys = 0x90;
///////////decorobj//////////////////////////////////////////////////////////////
//dif//step
DWORD dooff2 = 0x138;
//y
DWORD dooff11 = 0x10c;
//x
DWORD dooff22 = 0x110;
//ids
DWORD dooff33 = 0x118;
//ids other array
DWORD dooff44 = 0x40;
//activ
DWORD dooff55 = 0x8;
DWORD dooff66 = 0xc;
//xm
DWORD dooffxm = 0x88;
//ym
DWORD dooffym = 0x8c;
///////////grounditems/////////////////////////////////////////////////////////////////
DWORD goff2 = 0x9a0;
//x
DWORD goff11 = 0x98C;
//y
DWORD goff22 = 0x994;
//to id
DWORD goff33 = 0x130;
// floor
DWORD goff5 = 0x98C - 0x4;
//xmid
WORD goffxm = 0x88;
//ymid
WORD goffym = 0x8c;
// activ
DWORD goff6 = 0x8;
// activ
DWORD goff7 = 0xc;
//other arr id 
DWORD gotherid = 0x20;
//other arr am
DWORD gotheram = 0x24;





