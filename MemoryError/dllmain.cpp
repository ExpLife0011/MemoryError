// dllmain.cpp : Defines the entry point for the DLL application.
#include "MemoryError.h"

HINSTANCE hInstance;
typedef char* SimbaString;

char* PascalExports[] =
{
	(char*)"SetupRSReading", (char*)"Function SetupRSReading(OverLayB:Boolean;level:Byte): Boolean;",
	(char*)"GetPCoords", (char*)"Function GetPCoords(): Tpoint;",
	(char*)"GetPFloorLv", (char*)"Function GetPFloorLv(): Byte;",
	(char*)"Findobj", (char*)"Function Findobj(obj:array of Int32;size,d:Byte): Boolean;",
	(char*)"InvItem", (char*)"Function InvItem(x,action:Int32): Tpoint;",
	(char*)"FindGroundItems", (char*)"Function FindGroundItems(Gitem:array of Int32;size,d:Byte;xy,mxy:Tpoint;usemap:Boolean;action:Byte;str:string): Boolean;",
	(char*)"FindGroundItemsBool", (char*)"Function FindGroundItemsBool(Gitem:array of Int32;size,d:Byte): Boolean;",
	(char*)"FindNPCs1", (char*)"Function FindNPCs1(id:array of Int32;size,d:Byte;xy,mxy:Tpoint;usemap:Boolean;action:Byte;sidetext:string): Boolean;",
	//(char*)"FindNPCs2", (char*)"Function FindNPCs2(id:array of Int32;size,d:Byte;h:Int32): Boolean;",
	//(char*)"FindNPCs3", (char*)"Function FindNPCs3(id:array of Int32;size,d:Byte;spot:Tpoint): Boolean;",
	//(char*)"FindNPCs4", (char*)"Function FindNPCs4(id:array of Int32;size,d:Byte;h:Int32;spot:Tpoint): Boolean;",
	(char*)"ReadUpTxt", (char*)"Function  ReadUpTxt(x:string): Boolean;",
	(char*)"GetPAnimation", (char*)"Function GetPlayerAnimation(): Int32;",
	//(char*)"TileToScreen", (char*)"Function TileToScreen(x:Tpoint): Tpoint;",
	//(char*)"TileToMap", (char*)"Function TileToMap(x:Tpoint): Tpoint;",
	(char*)"MousePos", (char*)"Function MousePos(): Tpoint;",
	(char*)"MouseClick", (char*)"Procedure MouseClick(x:Tpoint;x2:Boolean);",
	(char*)"CheckPAnim", (char*)"Function CheckPAnim(): Boolean;",
	(char*)"CheckPAnim2", (char*)"Function CheckPAnim2(): Boolean;",
	(char*)"CheckPAnim3", (char*)"Function CheckPAnim3(): Boolean;",
	(char*)"CheckPAnim4", (char*)"Function CheckPAnim4(): Boolean;",
	//(char*)"WaitPAnim", (char*)"Function WaitPAnim(): Boolean;",
	(char*)"InveFull", (char*)"Function InveFull(): Boolean;",
	(char*)"InveFreecount", (char*)"Function InveFreecount(): Byte;",
	(char*)"InveItemcount", (char*)"Function InveItemcount(Item:Int32): Byte;",
	(char*)"ReadPMove", (char*)"Function ReadPMove(): Boolean;",
	(char*)"ClickTile", (char*)"Function ClickTile(x:Tpoint;minimap:Int32): Boolean;",
	(char*)"MouseDrag", (char*)"Procedure MouseDrag(x,x2:Tpoint);",
	(char*)"MouseMove", (char*)"Procedure MouseMove(x:Tpoint);",
	(char*)"FindAobj", (char*)"Function FindAobj(obj:array of Int32;size,d:Byte;xy,mxy:Tpoint;usemap:Boolean;action:Byte;str:string): Boolean;",
	(char*)"FindAobj2", (char*)"Function FindAobj2(obj:array of Int32;size,d:Byte;xy,mxy:Tpoint;usemap:Boolean;action:Byte;str:string;x12,y12:Tpoint;height:Boolean): Boolean;",
	(char*)"FindDobj", (char*)"Function FindDobj(obj:array of Int32;size,d:Byte;xy,mxy:Tpoint;usemap:Boolean;action:Byte;str:string): Boolean;",
	(char*)"FindDobj2", (char*)"Function FindDobj2(obj:array of Int32;size,d:Byte;xy,mxy:Tpoint;usemap:Boolean;action:Byte;str:string;x12,y12:Tpoint;height:Boolean): Boolean;",
	(char*)"ClickInv", (char*)"Function ClickInv(Item,action:Int32): Boolean;",
	(char*)"DiviOpen", (char*)"Function DiviOpen(): Boolean;",
	(char*)"BankOpen", (char*)"Function BankOpen(): Boolean;",
	(char*)"ProgressOpen", (char*)"Function ProgressOpen(): Boolean;",
	(char*)"ChooseIOpen", (char*)"Function ChooseIOpen(): Boolean;",
	(char*)"ChooseTOpen", (char*)"Function ChooseTOpen(): Boolean;",
	(char*)"ChooseLoot", (char*)"Function ChooseLoot(): Boolean;",
	(char*)"KeyPress", (char*)"Procedure KeyPress(Key:AnsiChar);",
	(char*)"FindNPCLock", (char*)"Function FindNPCLock(obj:array of Int32;size,d:Byte): Boolean;",
	(char*)"ReadNPCInFocusTilexy", (char*)"Function ReadNPCInFocusTilexy(): Tpoint;",
	(char*)"ReadNPCInFocusScreenxy", (char*)"Function ReadNPCInFocusScreenxy(): Tpoint;",
	(char*)"ReadNPCInFocusHealth", (char*)"Function ReadNPCInFocusHealth(): Int32;",
	(char*)"ReadNPCInFocusAnim", (char*)"Function ReadNPCInFocusAnim(): Int32;",
	(char*)"ReadInterface", (char*)"Function ReadInterface(id1,id2,id3,id4:Int32): TRect;",
	(char*)"ReadVarpBit", (char*)"Function ReadVarpBit(id:Int32): Int32;",
	(char*)"GetPray", (char*)"Function GetPray(): Int32;",
	(char*)"GetPrayMax", (char*)"Function GetPrayMax(): Int32;",
	(char*)"GetHP", (char*)"Function GetHP(): Int32;",
	(char*)"GetHPMax", (char*)"Function GetHPMax(): Int32;",
	(char*)"PlayerIdle", (char*)"Procedure PlayerIdle();",
	(char*)"PlayerInArea", (char*)"Function PlayerInArea(xc,rangex,yc,rangey:Int32;floorz:Byte): Boolean;",
	(char*)"Compare2Dobj", (char*)"Function Compare2Dobj(obj1,obj2:Int32;pdist,obj2dist1,obj2dist2:Byte;xy,mxy:Tpoint;usemap:Boolean;action:Byte;str:string): Boolean;",
	(char*)"CompareNonDobj", (char*)"Function CompareNonDobj(obj1,obj2:Int32;pdist,obj2dist1:Byte;xy,mxy:Tpoint;usemap:Boolean;action:Byte;str:string): Boolean;",
	(char*)"CheckTile", (char*)"Function CheckTile(d:Byte;xy:Tpoint;height:Boolean): Boolean;"
};

static const DWORD PascalExportCount = sizeof(PascalExports) / (sizeof(PascalExports[0]) * 2);

extern "C"  __declspec(dllexport) BOOLEAN CheckTile(BYTE d, POINT xy, BOOLEAN height)
{
	return  CheckTile_(d,xy,height);
}

extern "C"  __declspec(dllexport) BOOLEAN CompareNonDobj(DWORD obj1, DWORD obj2, BYTE pdist, BYTE obj2dist1, POINT xy, POINT mxy, BOOLEAN usemap, BYTE action, SimbaString str)
{
	return  CompNonDObj(obj1, obj2, pdist, obj2dist1, xy, mxy, usemap, action, str);
}

extern "C"  __declspec(dllexport) BOOLEAN Compare2Dobj(DWORD obj1, DWORD obj2, BYTE pdist, BYTE obj2dist1,BYTE obj2dist2, POINT xy, POINT mxy, BOOLEAN usemap, BYTE action, SimbaString str)
{
	return  Comp2DObj(obj1, obj2, pdist, obj2dist1, obj2dist2, xy, mxy, usemap, action, str);
}

extern "C"  __declspec(dllexport) BOOLEAN PlayerInArea(WORD xc, WORD rangex, WORD yc, WORD rangey, BYTE floorz)
{
	return PInArea(xc,rangex,yc,rangey,floorz);
}

extern "C"  __declspec(dllexport) VOID PlayerIdle()
{
	return PIdle1();
}

extern "C"  __declspec(dllexport) BOOLEAN DiviOpen()
{
	return DiviOpen_();
}

extern "C"  __declspec(dllexport) WORD GetHPMax()
{
	return GetHPMax_();
}

extern "C"  __declspec(dllexport) WORD GetHP()
{
	return GetHP_();
}

extern "C"  __declspec(dllexport) WORD GetPrayMax()
{
	return GetPrayMax_();
}

extern "C"  __declspec(dllexport) WORD GetPray()
{
	return GetPray_();
}

extern "C" __declspec(dllexport) BOOLEAN ReadUpTxt(SimbaString str) {
	//waste of time to check for null, crashes if nothing is written and then try do anything with str
	string s = str;
		string f = FindSideText();
		if (s.length()>0 && f.length()>0) {
			if (f.find(s) != string::npos) {
				return TRUE;
			}
	}
	return FALSE;
}

extern "C"  __declspec(dllexport) DWORD ReadVarpBit(WORD id)
{
	
	return FindVarBit(id).state;
}

extern "C"  __declspec(dllexport) RECT ReadInterface(WORD id1, WORD id2, WORD id3, WORD id4)
{
	RECT rectangle;
	DWORD64 TempMemoryLoc;
	TempMemoryLoc = Locateinterface(id1, id2, id3, id4);
	if (TempMemoryLoc != NULL) {
		InterfaceComp2 data = GetInterfaceData2(TempMemoryLoc);
		//lets make a rectangle
		rectangle.top = data.xy.y;
		rectangle.bottom = data.xy.y + data.xys.y;
		rectangle.left = data.xy.x;
		rectangle.right = data.xy.x + data.xys.x;
	}
	return{ rectangle };
}

extern "C"  __declspec(dllexport) POINT ReadNPCInFocusTilexy()
{
	FFPOINT p = ReadNPCInFocus_().Tilexy;
	       return { (LONG)(p.x/512.f),(LONG)(p.y/512.f) };
}

extern "C"  __declspec(dllexport) POINT ReadNPCInFocusScreenxy()
{
	WPOINT p = ReadNPCInFocus_().xym;
		   return {p.x,p.y};
}

extern "C"  __declspec(dllexport) DWORD ReadNPCInFocusHealth()
{
	return ReadNPCInFocus_().Lifep;
}

extern "C"  __declspec(dllexport) DWORD ReadNPCInFocusAnim()
{
	return ReadNPCInFocus_().AnimState;
}

extern "C"  __declspec(dllexport) BOOLEAN FindNPCLock(DWORD* obj, BYTE size, BYTE d)
{
	vector<DWORD> objectsArray;
	for (WORD i = 0; i < size; i++) {
		objectsArray.push_back(obj[i]);
	}
	return  FindNPCLock_(objectsArray, d);;
}

extern "C"  __declspec(dllexport) VOID KeyPress(char Key)
{
	return KeyPress_(Key);
}

extern "C"  __declspec(dllexport) BOOLEAN ChooseLoot()
{
	return ChooseLoot_();
}

extern "C"  __declspec(dllexport) BOOLEAN ChooseTOpen()
{
	return ChooseTOpen_();
}

extern "C"  __declspec(dllexport) BOOLEAN ChooseIOpen()
{
	return ChooseIOpen_();
}

extern "C"  __declspec(dllexport) BOOLEAN ProgressOpen()
{
	return ProgressOpen_();
}

extern "C"  __declspec(dllexport) BOOLEAN BankOpen()
{
	return BankOpen_();
}

extern "C"  __declspec(dllexport) BOOLEAN ClickInv(DWORD Item,BYTE action)
{
	return ClickInv_(Item,action);
}

extern "C"  __declspec(dllexport) BOOLEAN FindAobj(DWORD* obj, BYTE size, BYTE d, POINT xy, POINT mxy, BOOLEAN usemap, BYTE action, SimbaString str)
{
	vector<DWORD> objectsArray;
	for (WORD i = 0; i < size; i++) {
		objectsArray.push_back(obj[i]);
	}
	return  FindAObj(objectsArray, d, xy, mxy,usemap,action,str);
}

extern "C"  __declspec(dllexport) BOOLEAN FindAobj2(DWORD* obj, BYTE size, BYTE d, POINT xy, POINT mxy, BOOLEAN usemap, BYTE action, SimbaString str,
	POINT x12, POINT y12, BOOLEAN height)
{
	vector<DWORD> objectsArray;
	for (WORD i = 0; i < size; i++) {
		objectsArray.push_back(obj[i]);
	}
	return  FindAObj2(objectsArray, d, xy, mxy, usemap, action, str, x12, y12, height);
}

extern "C"  __declspec(dllexport) BOOLEAN FindDobj(DWORD* obj , BYTE size, BYTE d, POINT xy, POINT mxy, BOOLEAN usemap, BYTE action, SimbaString str)
{
	vector<DWORD> objectsArray;
	for (WORD i = 0; i < size; i++) {
		objectsArray.push_back(obj[i]);
	}
	return  FindDObj(objectsArray, d,xy, mxy, usemap, action, str);
} 

extern "C"  __declspec(dllexport) BOOLEAN FindDobj2(DWORD* obj, BYTE size, BYTE d, POINT xy, POINT mxy, BOOLEAN usemap, BYTE action, SimbaString str,
	POINT x12, POINT y12, BOOLEAN height)
{
	vector<DWORD> objectsArray;
	for (WORD i = 0; i < size; i++) {
		objectsArray.push_back(obj[i]);
	}
	return  FindDObj2(objectsArray, d, xy, mxy, usemap, action, str, x12, y12, height);
}

extern "C"  __declspec(dllexport) VOID MouseDrag(POINT p, POINT p2)
{
	return MouseDrag_RS(p, p2);
}

extern "C"  __declspec(dllexport) VOID MouseMove(POINT p)
{
	return MouseMove_(p);
}

extern "C"  __declspec(dllexport) BOOLEAN ClickTile(POINT p, BYTE minimap)
{
	return ClickTile_(p, minimap);
}

extern "C"  __declspec(dllexport) BOOLEAN Findobj(DWORD* obj, BYTE size, BYTE d)
{
	vector<DWORD> objectsArray;
	for (WORD i = 0; i < size; i++) { 
		objectsArray.push_back(obj[i]);
	}
	return  FindSObj(objectsArray, d);;
}

extern "C"  __declspec(dllexport) BOOLEAN ReadPMove()
{
	return ReadPlayerMovin();
}

extern "C"  __declspec(dllexport) BYTE InveFreecount()
{
	return Invfreecount();
}

extern "C"  __declspec(dllexport) BYTE InveItemcount(DWORD Item)
{
	return InvItemcount_(Item);
}

extern "C"  __declspec(dllexport) BOOLEAN InveFull()
{
	return InvFull();
}

extern "C"  __declspec(dllexport) BOOLEAN WaitPAnim()
{
	return WaitAnim();
}

extern "C"  __declspec(dllexport) BOOLEAN CheckPAnim()
{
	return CheckAnim();
}

extern "C"  __declspec(dllexport) BOOLEAN CheckPAnim2()
{
	return CheckAnim2();
}

extern "C"  __declspec(dllexport) BOOLEAN CheckPAnim3()
{
	return CheckAnim3();
}

extern "C"  __declspec(dllexport) BOOLEAN CheckPAnim4()
{
	return CheckAnim4();
}


extern "C"  __declspec(dllexport) BOOLEAN FindNPCs4(DWORD* id, BYTE size, BYTE d, POINT spot, DWORD h)
{
	vector<DWORD> objectsArray;
	for (WORD i = 0; i < size; i++) {
		objectsArray.push_back(id[i]);
	}
	return FindNPCss(objectsArray, d, spot,h);
}

extern "C"  __declspec(dllexport) BOOLEAN FindNPCs3(DWORD* id, BYTE size, BYTE d, POINT spot)
{
	vector<DWORD> objectsArray;
	for (WORD i = 0; i < size; i++) {
		objectsArray.push_back(id[i]);
	}
	return FindNPCss(objectsArray, d, spot);
}

extern "C"  __declspec(dllexport) BOOLEAN FindNPCs2(DWORD* id, BYTE size, BYTE d, DWORD h)
{
	vector<DWORD> objectsArray;
	for (WORD i = 0; i < size; i++) {
		objectsArray.push_back(id[i]);
	}
	return FindNPCss(objectsArray, d, h);
}

extern "C"  __declspec(dllexport) BOOLEAN FindNPCs1(DWORD* id, BYTE size , BYTE d, POINT xy, POINT mxy, BOOLEAN usemap, BYTE action, SimbaString sidetext)
{
	vector<DWORD> objectsArray;
	for (WORD i = 0; i < size; i++) {
		objectsArray.push_back(id[i]);
	}
	return FindNPCss(objectsArray,d,xy,mxy, usemap,action,sidetext);
}

extern "C"  __declspec(dllexport) POINT MousePos()
{
	return MousePos_();
}

extern "C"  __declspec(dllexport) VOID MouseClick(POINT x, BOOLEAN x2)
{
	return MouseCLRS(x, x2);
}

extern "C"  __declspec(dllexport) POINT TileToMap(POINT x)
{
	return TToMap(x);;
}

extern "C"  __declspec(dllexport) POINT TileToScreen(POINT x)
{
	return TToScreen(x);;
}

extern "C" int __declspec(dllexport) GetPluginABIVersion()
{
	return 2;
}  

extern "C" int __declspec(dllexport) SetupRSReading(BOOLEAN OverLayB, BYTE level)
{	
	return Start(OverLayB, level);
}

extern "C" int __declspec(dllexport) GetPFloorLv()
{
	return GetFloorLv_2();
}

extern "C" int __declspec(dllexport) GetPAnimation()
{
	return ReadPlayerAnim();
}

extern "C"  __declspec(dllexport) POINT InvItem(DWORD obj,BYTE action)
{
	POINT p;
	WPOINT fp = InvFindItem(obj,action);
	p.x = fp.x;
	p.y = fp.y;
	return p;
}

extern "C"  __declspec(dllexport) BOOLEAN FindGroundItems(DWORD* Gitem, BYTE size, BYTE d, POINT xy, POINT mxy, BOOLEAN usemap, BYTE action, SimbaString sidetext)
{
	vector<DWORD> objectsArray;
	for (WORD i = 0; i < size; i++) {
		objectsArray.push_back(Gitem[i]);
	}
	return FindGItem_(objectsArray,d, xy,mxy,usemap,action,sidetext);
}

extern "C"  __declspec(dllexport) BOOLEAN FindGroundItemsBool(DWORD* Gitem, BYTE size)
{
	vector<DWORD> objectsArray;
	for (WORD i = 0; i < size; i++) {
		objectsArray.push_back(Gitem[i]);
	}
	return FindGItemBool_(objectsArray);
}

extern "C" __declspec(dllexport) POINT GetPCoords()
	{	
		return PlayerCoordPoint();
}

extern "C" int __declspec(dllexport) GetFunctionCount()
{
	return PascalExportCount;
}

extern "C" int __declspec(dllexport) GetFunctionInfo(int Index, void*& Address, char*& Definition)
{
	if (Index < PascalExportCount)
	{
		Address = reinterpret_cast<void*>(GetProcAddress(hInstance, PascalExports[Index * 2]));
#ifdef _MSC_VER
#pragma warning(disable: 4996)
		strcpy(Definition, PascalExports[Index * 2 + 1]);
		//strcpy_s(Definition, Exports[Index * 2 + 1]);
#else
		strcpy(Definition, Exports[Index * 2 + 1]);
#endif
		return Index;
	}
	return -1;
}

extern "C" BOOLEAN __fastcall DllMain(HINSTANCE hinstDLL,
									DWORD fdwReason,
									PVOID lpvReserved)
{
	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		DisableThreadLibraryCalls(hinstDLL);
		hInstance = hinstDLL;	

		return true;

	case DLL_PROCESS_DETACH:
		//UnhookWindowsHookEx(_hook);
		//UnhookWindowsHookEx(_hook2);
		break;

	default:
		break;
	}
	return true;
}

