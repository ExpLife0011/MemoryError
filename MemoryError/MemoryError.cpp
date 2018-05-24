#include "MemoryError.h"
#include "OffSets.h"


DWORD64 ScanBack=  0x80000000;
DWORD64 ScanFoward=0x60000000;
//////////////////////////////////////////////////////////////////////////////////

// Data
static LPDIRECT3DDEVICE9        g_pd3dDevice = NULL;
static D3DPRESENT_PARAMETERS    g_d3dpp;

Process proc;
vector<DWORD> procIDs;
HANDLE HProc = NULL;
HWND WProc,WProc2 = NULL;
HWND WProcC = NULL;

//rs main exe module
DWORD64 RSExeStart;
DWORD64 RSExeSize;
string RSExeFile;
DWORD HPid;
DWORD64 Exe1,Exe2,Exe3,Exe4,Exe5,Exe6,Exe7,SettingsStart;
FLOAT MyLocYRaw = NULL;
FLOAT MyLocXRaw = NULL;
FLOAT MyLocZRaw = NULL;
INT Floor;
DWORD64 Compass;
vector<DWORD64> SettingsAddr;
vector<DWORD64> SettingsAddrRec;
vector<DWORD64> SettingsId;
vector<DWORD64> SettingsIdRec;
vector<DWORD> SettingsState;
vector<DWORD> SettingsStateRec;
FFPOINT Movingstate;
/////////////////////////////////////////
vector<FLOAT> InterfX;
vector<FLOAT> InterfY;
vector<FLOAT> InterfXs1;
vector<FLOAT> InterfYs1;
vector<FLOAT> InterfXs11;
vector<FLOAT> InterfYs11;
vector<WORD> InterfID;
vector<WORD> InterfID2;
vector<WORD> InterfID3;
vector<WORD> InterfID4;
vector<BOOLEAN> InterfAct;
vector<BOOLEAN> InterfHov;
vector<DWORD64> InterfMem;
vector<string> InterName;
vector<DWORD> InterfTimer;
////////////////////////////////
vector<FLOAT> InterfX2;
vector<FLOAT> InterfY2;
vector<FLOAT> InterfXs2;
vector<FLOAT> InterfYs2;
vector<FLOAT> InterfXs22;
vector<FLOAT> InterfYs22;
vector<WORD> InterfID12;
vector<WORD> InterfID22;
vector<WORD> InterfID32;
vector<WORD> InterfID42;
vector<BOOLEAN> InterfAct2;
vector<BOOLEAN> InterfHov2;
vector<DWORD64> InterfMem2;
vector<string> InterName2;
vector<DWORD> InterfTimer2;
////////////////////////////////////////////
vector<FLOAT> ObjectsXf;
vector<FLOAT> ObjectsYf;
vector<DWORD> ObjectsID;
vector<DWORD> ObjectsIDu;
vector<WORD>Objectsxmid;
vector<WORD>Objectsymid;
vector<WORD>Objectsxsize;
vector<WORD>Objectsysize;
vector<DWORD64> ObjectsMem;
vector<FLOAT> ObjectsXfd;
vector<FLOAT> ObjectsYfd;
vector<DWORD> ObjectsIDd;
vector<DWORD> ObjectsIDd2;
vector<DWORD64> ObjectsIDd3;
vector<string> ObjectsName;
vector<string> ObjectsAction1;
////////////////////////////
vector<FLOAT> ObjX;
vector<FLOAT> ObjY;
vector<DWORD> ObjID;
vector<DWORD64> ObjAddrXY;
vector<DWORD64> ObjExtra;
vector<DWORD> TypeByte;
vector<DWORD>ViewPartialPl;
vector<BYTE>ViewFullPl;
vector<DWORD>ViewPartialNPC;
vector<BYTE>ViewFullNPC;
vector<DWORD>ViewPartialObjects;
vector<BYTE>ViewFullObjects;
vector<DWORD>ViewPartialDecor;
vector<BYTE>ViewFullDecor;
vector<DWORD>ViewPartialGI;
vector<BYTE>ViewFullGI;
////////////////////////////
vector<FLOAT> DecorXf;
vector<FLOAT>DecorYf;
vector<DWORD> DecorID;
vector<WORD>Decorxmid;
vector<WORD>Decorymid;
vector<DWORD64> DecorMem;
vector<string> DecorName;
////////////////////////////
vector<FLOAT> FloatXf;
vector<FLOAT> FloatYf;
vector<DWORD64> FloatMem;
////////////Projectiles/////////
vector<FLOAT> ProXf;
vector<FLOAT> ProYf;
vector<DWORD> ProID;
vector<WORD>Proxmid;
vector<WORD>Proymid;
vector<DWORD64> ProMem;
//////////////////////////////
vector<FLOAT> PlX;
vector<FLOAT> PlY;
vector<FLOAT> PlZ;
vector<DWORD> PlID;
vector<DWORD64> PlMem;
vector<DWORD> PlLife;
vector<DWORD> PlAnim;
vector<string> PlName;
vector<BYTE> PlFloor;
vector<BOOLEAN> PlTouched;
vector<BYTE> PlPraytype;
vector<WORD>Plxmid;
vector<WORD>Plymid;
/////////////////////////////
vector<FLOAT> NPCX;
vector<FLOAT> NPCY;
vector<FLOAT> NPCZ;
vector<DWORD> NPCID;
vector<DWORD64> NPCMem;
vector<DWORD> NPCLife;
vector<DWORD> NPCAnim;
vector<string> NPCName;
vector<BYTE> NPCFloor;
vector<BOOLEAN> NPCTouched;
vector<BOOLEAN> NPCProtOn;
vector<BYTE> NPCPraytype;
vector<WORD>NPCxstart;
vector<WORD>NPCxend;
vector<WORD>NPCxmid;
vector<WORD>NPCystart;
vector<WORD>NPCyend;
vector<WORD>NPCymid;
vector<WORD>NPCxsize;
vector<WORD>NPCysize;
vector<BYTE>NPCstate;
////////////////////////////
vector<FLOAT> GIX;
vector<FLOAT> GIY;
vector<DWORD> GIID;
vector<DWORD> GIAM;
vector<string> GIText;
vector<DWORD64>GIMem;
vector<FLOAT> GIX2;
vector<FLOAT> GIY2;
vector<DWORD> GIID2;
vector<DWORD> GIAM2;
vector<BYTE> GIFL2;
vector<WORD>GIxmid2;
vector<WORD>GIymid2;
vector<string> GIText2;
vector<DWORD64> GIMem2;
///////////////////////////////////////
vector<WORD>Invx;
vector<WORD>Invy;
vector<WORD>Invxs;
vector<WORD>Invys;
vector<WORD> BoxMidsx(27);
vector<WORD> BoxMidsy(27);
vector<INT> InvSlot2;
vector<string> InvText;
vector<DWORD> InvId;
vector<DWORD> InvAm;
vector<DWORD64> IAddr2;
//////////////////////////////////////////////
DWORD64 LocalPlayer;
FFPOINT ResComp;
FFPOINT ResComp2;
string Revision;
FFPOINT EliteResult;
DWORD64 HP;
vector<DWORD64> VarBits1, VarBits2;
DWORD64 PP;
DWORD64 AD;
DWORD64 SL;
DWORD64 OB;
DWORD64 DOB;
DWORD64 DOB2;
DWORD64 IF;
DWORD64 IF2;
DWORD64 IFE;
DWORD64 PRO;
vector<DWORD64> INVIArr;
DWORD64 NPCLOCK;
vector<DWORD64>BANKArr, BANKIArr,LOOTArr;
DWORD64 BANKArrPrev, BANKIArrPrev, LOOTArrPrev;
//////////////////////////////////////
DWORD64 DiviTemp,BankTemp, InvBoxMemoryLoc, MapBoxMemoryLoc,ProgTemp,ChooseITemp,ChooseTTemp,LootTemp,
EqBoxMemoryLoc, PrayBoxMemoryLoc, SongBoxMemoryLoc, ChatBoxMemoryLoc, AbilBoxMemoryLoc, MenoBoxMemoryLoc,
SkillRingBoxMemoryLoc, MIBoxMemoryLoc, MembBoxMemoryLoc, THBoxMemoryLoc, InterfTempMemoryLoc, UpTextTempMemoryLoc;
//////////////////////////////////////
DWORD64 TempBit,PrayBit,HPBit;
//////////////////////////////////////
vector<DWORD64> intertest;
vector<BYTE> intertest2;
vector<DWORD64> intertest3;
vector<BYTE> intertest4;
BYTE AllObjectCount=0;
vector<DWORD64> resss;

vector<DWORD> TextNR;
vector<string> TextTxt;
vector<WORD>Dungvarp;
WORD dungnote = 0;
vector<DWORD> CNR;
vector<string> CText;
vector<POINT> CCoord;


vector<DWORD64> scans;//holds memory scan results
vector<DWORD64> scans2;//comparitive purpose

FLOAT Angle;
FLOAT test99;
FLOAT test999;
FLOAT test9999;
DWORD test88;
FLOAT TileCalc;
RECT rs;
RECT rs3;
MEMORY_BASIC_INFORMATION64 buff;
list<MEMORY_BASIC_INFORMATION64> buff2;
WORD screen_width2, screen_height2;

DWORD64 ClientBase = NULL;
DWORD PlaceHolderX = NULL;
DWORD PlaceHolderY = NULL;
DWORD InterfAdd = 0;
DWORD64 Interfexp1;
DWORD64 ScAdd = NULL;
DWORD64 NPCAdd = NULL;
DWORD64 ScAdd1 = NULL;
DWORD64 ScAdd2 = NULL;
DWORD64 ScAdd3 = NULL;
DWORD64 ScAdd4 = NULL;
DWORD64 ScAdd41 = NULL;
//DWORD64 ScAdd5 = NULL;
DWORD64 ScAdd6 = NULL;
DWORD64 ScAdd7 = NULL;
DWORD64 ScAdd8 = NULL;
DWORD64 ScAdd9 = NULL;
DWORD64 ScAdd10 = NULL;
DWORD64 ScAdd11 = NULL;
DWORD64 ScAdd12 = NULL;
vector<DWORD64> InvIA;
vector<DWORD64> InvIB;
vector<DWORD64> MapB;
vector<DWORD64> GrA;
BOOLEAN R1 = 1,R2 = 1,R3 = 1,R4 = 1,R5 = 1,R6 = 1,R7 = 1,R8 = 1,R9 = 1,R10 = 1,R11 = 1,R12 = 1,R13 = 1,R14 = 1,R15 = 1,R16 = 1,R17 = 1,R18 = 1,R19 = 1,R20=1;
BOOLEAN RS3Found = FALSE;
BOOLEAN PaintActive = FALSE;
BOOLEAN HookinActive = FALSE;
BOOLEAN RefreshLoop = FALSE;
BOOLEAN key1 = 0;
BOOLEAN key2 = 0;
BOOLEAN key3 = 1;
BOOLEAN key4 = 0;
BOOLEAN key5 = 0;
BOOLEAN key6 = 0;
BOOLEAN key7 = 0;
BOOLEAN key8 = 0;
BOOLEAN key9 = 0;
BOOLEAN key10 = 0;
BOOLEAN key11 = 0; 
BOOLEAN key12 = 0;
BOOLEAN key13 = 0;
BOOLEAN key14 = 0;
BOOLEAN key15 = 0;
BOOLEAN key16 = 0;
BOOLEAN key17 = 0;
BOOLEAN key18,key19,key20, key21, key22, key23, key24, key25, key26, key27, key28, key29, key30,key31,key32;
BOOLEAN debug = 1;
BOOLEAN debug2 = 0;
DWORD64 StartTime = 0;
string MD5hash;
BYTE runsD,runsA,runsAll,runsNPC,runsF = 0;
//for mouse inception
intPOINT xyhold;
intPOINT xyhold2;
int xhold;
BOOLEAN movemessage2;
InterceptionDevice mouse,keyboard;
FFPOINT movepos;
BYTE RDPLevel = 0;
BOOLEAN MouseTrue = FALSE;
BOOLEAN KeyboTrue = FALSE;



extern LRESULT ImGui_ImplDX9_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
LRESULT WINAPI WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if (ImGui_ImplDX9_WndProcHandler(hWnd, msg, wParam, lParam))
		return true;

	switch (msg)
	{
	case WM_SIZE:
		if (g_pd3dDevice != NULL && wParam != SIZE_MINIMIZED)
		{
			ImGui_ImplDX9_InvalidateDeviceObjects();
			g_d3dpp.BackBufferWidth = LOWORD(lParam);
			g_d3dpp.BackBufferHeight = HIWORD(lParam);
			HRESULT hr = g_pd3dDevice->Reset(&g_d3dpp);
			if (hr == D3DERR_INVALIDCALL)
				IM_ASSERT(0);
			ImGui_ImplDX9_CreateDeviceObjects();
		}
		return 0;
	case WM_SYSCOMMAND:
		if ((wParam & 0xfff0) == SC_KEYMENU) // Disable ALT application menu
			return 0;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, msg, wParam, lParam);
}

VOID GetWindowsRes() {
	screen_width2 = GetSystemMetrics(SM_CXVIRTUALSCREEN);
	//cout <<"SM_CXVIRTUALSCREEN: "<< screen_width2 << endl;
	screen_height2 = GetSystemMetrics(SM_CYVIRTUALSCREEN);
	//cout <<"SM_CYVIRTUALSCREEN: "<< screen_height2 << endl;
}

// Get rs resolution, winapi
QWPOINT GetRSCorners()
{
	QWPOINT point;
	RECT rs;
	GetWindowRect(WProcC, &rs);
	point.bottom = (WORD)rs.bottom;
	point.left = (WORD)rs.left;
	point.right = (WORD)rs.right;
	point.top = (WORD)rs.top;
	return point;
}

// Get rs resolution, winapi
WPOINT GetRsResolution2()
{
	WPOINT point;
	QWPOINT rs=GetRSCorners();
	point.x = rs.right - rs.left;
	point.y = rs.bottom - rs.top;
	return point;
}

// Get the mouse location on rs
WPOINT GetMLoc()
{
	RECT rs;
	GetWindowRect(WProcC, &rs);
	POINT point;
	if (GetCursorPos(&point)) {

		   INT x = point.x - rs.left;
		   INT y = point.y - rs.top;
		   if (x > 0 && y>0 && x < GetRsResolution2().x && y < GetRsResolution2().y) {
			   point.x= x;
			} else{ point.x = 0;}
		   if (y > 0 && x>0 && y < GetRsResolution2().y  && x < GetRsResolution2().x) {
			   point.y = y;
		   } else{ point.y = 0; }

	}
	//it should alwas be positive
	return {(WORD)point.x,(WORD)point.y};
}

//Calculate to tile location
FLOAT CRL(FLOAT addr) {
	if (addr != NULL) {
		return addr / 512.f;
	}
	else return 0.f;
}

//Calculate back to raw location
FLOAT RXY(INT addr) {
	if (addr != NULL) {
		return addr * 512.f;
	}
	else return 0.f;
}

//our address,writes start and size to global
MEMss DeterMemoryBlockLenght(DWORD64  blokk) {

	MEMORY_BASIC_INFORMATION64 buffs = { 0 };

	if (blokk != NULL) {
		if (proc.remote().memory().Query(blokk, &buffs) == STATUS_SUCCESS) {			
			return{ buffs.AllocationBase,buffs.RegionSize };

		}
	}
}

//info
VOID MemoryInfo(DWORD64  blokk) {

	buff = {0};

	if (blokk != NULL) {
		if (proc.remote().memory().Query(blokk, &buff) == STATUS_SUCCESS) {

			cout << hex << buff.AllocationBase << "\n";
			cout << buff.AllocationProtect << "\n";
			cout << buff.BaseAddress << "\n";
			cout << buff.Protect << "\n";
			cout << buff.RegionSize << "\n";
			cout << buff.State << "\n";
			cout << buff.Type << "\n";
			cout << buff.__alignment1 << "\n";
			cout << buff.__alignment2 << "\n";
		}
	}
}

//finds current regions number//no idea
VOID MemoryRegionsFM() {

	
	BOOLEAN Found;
	vector<DWORD64> results;

	if (proc.valid()) {
		//MemoryInfo(blokk);
		proc.remote().memory().EnumRegions(buff2, FALSE);
		if (!buff2.empty()) {
			//cout << "Diffrent regions found:" << dec << buff2.size() << endl;
			for (list<MEMORY_BASIC_INFORMATION64>::iterator it = buff2.begin(); it != buff2.end(); ++it) {
				//MEMORY_BASIC_INFORMATION64 test = *it;
				//cout << hex << (*it).AllocationBase << endl;

				//so it isnt empty
				if (results.empty()) { results.push_back(9); }
				Found = FALSE;
					for (DWORD i = 0; i < results.size(); i++) {						
						if (results[i] == (*it).AllocationBase) { Found = TRUE; }						
					}
					if (Found == FALSE) { results.push_back((*it).AllocationBase); }
				}			
			cout << "Diffrent regions found2:" << dec << results.size() << endl;
		}
	}
}

//tries to mark diffrent memory regions
VOID MarkupMem(DWORD64 from, DWORD64 to) {

	DWORD divider=10000;
	DWORD64 summ;
	BOOLEAN Found;
	vector<DWORD64> results;

	for (DWORD64 i = from; i < to; i=i+divider) {

		MEMss dat= DeterMemoryBlockLenght(i);
		if (results.empty()) { results.push_back(9); }
		Found = FALSE;
		for (DWORD i = 0; i < results.size(); i++) {
			if (results[i] == dat.start) { Found = TRUE; }
		}
		if (Found == FALSE) { results.push_back(dat.start); }
	}
	cout << "Diffrent regions found2:" << dec << results.size() << endl;
}




DWORD VirtPRead2(DWORD64 address)
{
	DWORD buffer = 0; //No need for void pointer. Just use address of buffer.

	proc.Attach(procIDs.front());

	if (address == NULL)
	{
		cout << ("zero!\n");
	}
	else {
		cout << "true=?: " << proc.core().isWow64();
		proc.remote().memory().Read(address, sizeof(DWORD), &buffer); //Reads a DWORD into Buffer.
		return buffer;
	}
	return 0;
}

BYTE VirtPReadByte(DWORD64 SummPointer)
{
	BYTE buffer = 0;

	if (SummPointer == NULL)
	{
		cout << ("SummPointer zero!\n");
	}
	else {
		//printf("total adress: %I64X\n", SummPointer);	
		proc.remote().memory().Read(SummPointer, sizeof(BYTE), &buffer);
		//ReadProcessMemory(hProc, (void*)SummPointer, &buffer, sizeof(buffer), 0);
		return buffer;
	}
	return 0;
}

WORD VirtPReadWord(DWORD64 SummPointer)
{
	WORD buffer = 0;

	if (SummPointer == NULL)
	{
		cout << ("SummPointer zero!\n");
	}
	else {
		//printf("total adress: %I64X\n", SummPointer);	
		proc.remote().memory().Read(SummPointer, sizeof(WORD), &buffer);
		//ReadProcessMemory(hProc, (void*)SummPointer, &buffer, sizeof(buffer), 0);
		return buffer;
	}
	return 0;
}

DWORD VirtPReadDword(DWORD64 SummPointer)
{
	DWORD buffer = 0;

	if (SummPointer == NULL)
	{
		cout << ("SummPointer zero!\n");
	}
	else {
		//printf("total adress: %I64X\n", SummPointer);	
		proc.remote().memory().Read(SummPointer, sizeof(DWORD), &buffer);
		//ReadProcessMemory(hProc, (void*)SummPointer, &buffer, sizeof(buffer), 0);
		return buffer;
	}
	return 0;
}

DWORD64 VirtPRead64(DWORD64 SummPointer)
{
	DWORD64 buffer = 0;

	if (SummPointer == NULL)
	{
		cout << ("SummPointer zero!\n");
	}
	else {
		//printf("total adress: %I64X\n", SummPointer);	
		proc.remote().memory().Read(SummPointer, sizeof(DWORD64), &buffer);
		//ReadProcessMemory(hProc, (void*)SummPointer, &buffer, sizeof(buffer), 0);
		return buffer;
	}
	return 0;
}

FLOAT VirtPReadFloat(DWORD64 SummPointer)
{
	FLOAT buffer;
	DWORD bufferd;
	 
	if (SummPointer == NULL)
	{
		cout << ("SummPointer zero!\n");
	}
	else { 
		//printf("total adress: %I64X\n", SummPointer);	
		proc.remote().memory().Read(SummPointer, sizeof(DWORD), &bufferd);
		if (CheckCoordLimit(bufferd, 0x49000000)) {
			proc.remote().memory().Read(SummPointer, sizeof(FLOAT), &buffer);
			return buffer;
		}
	}
	return 0.f;
}

FLOAT VirtPReadFloatAll(DWORD64 SummPointer)
{
	FLOAT buffer;
	if (SummPointer == NULL)
	{
		cout << ("SummPointer zero!\n");
	}
	else {
			proc.remote().memory().Read(SummPointer, sizeof(FLOAT), &buffer);
			return buffer;
	}
	return 0.f;
}

string VirtPReadString(DWORD64 SummPointer)
{
	string buffer = {0};

	if (SummPointer == NULL)
	{
		cout << ("SummPointer zero!\n");
	}
	else {
		//printf("total adress: %I64X\n", SummPointer);

		proc.remote().memory().Read(SummPointer, sizeof(buffer), &buffer);
		//ReadProcessMemory(HProc, (void*)SummPointer, &buffer, 4, 0);
		return buffer;
	}
	return buffer;
}

string VirtPReadChar(DWORD64 SummPointer)
{
	
	const int readsize=80;
	//DWORD64 val = NULL;
	//DWORD64 val2 = NULL;
	//DWORD val3 = NULL;
	char strt[readsize] ;
	BYTE val4 = NULL;

		//proc.remote().memory().Read(SummPointer, sizeof(val), &val);
	    //proc.remote().memory().Read(SummPointer+0x8, sizeof(val2), &val2);
		//proc.remote().memory().Read(SummPointer + 0x10, sizeof(val3), &val3);

		for (DWORD i = 0; i < readsize; i++) {

			proc.remote().memory().Read(SummPointer+i, sizeof(val4), &val4);
			if (val4 < 1) { break; }
			else
			{
				strt[i] = val4;
			}			
		}
		/*
		vector<uint8_t>pp;
		strt[0] = ((val >> 0) & 0x000000ff);
		pp.push_back(((val >> 0) & 0x000000ff));
		strt[1] = ((val >> 8) & 0x000000ff);
		pp.push_back(((val >> 8) & 0x000000ff));
		strt[2] = ((val >> 16) & 0x000000ff);
		pp.push_back(((val >> 16) & 0x000000ff));
		strt[3] = ((val >> 24) & 0x000000ff);
		pp.push_back(((val >> 24) & 0x000000ff));
		pp.push_back(((val >> 32) & 0x000000ff));
		pp.push_back(((val >> 40) & 0x000000ff));
		pp.push_back(((val >> 48) & 0x000000ff));
		pp.push_back(((val >> 56) & 0x000000ff));
		pp.push_back(((val2 >> 0) & 0x000000ff));
		pp.push_back(((val2 >> 8) & 0x000000ff));
		pp.push_back(((val2 >> 16) & 0x000000ff));
		pp.push_back(((val2 >> 24) & 0x000000ff));
		pp.push_back(((val2 >> 32) & 0x000000ff));
		pp.push_back(((val2 >> 40) & 0x000000ff));
		pp.push_back(((val2 >> 48) & 0x000000ff));
		pp.push_back(((val2 >> 56) & 0x000000ff));
		pp.push_back(((val3 >> 0) & 0x000000ff));
		pp.push_back(((val3 >> 8) & 0x000000ff));
		pp.push_back(((val3 >> 16) & 0x000000ff));
		pp.push_back(((val3 >> 24) & 0x000000ff));


		for (DWORD i = 0; i < pp.size(); i++) {
			if (pp[i] == 0) { break; }else{ cout << pp[i]; }
		}
		*/
		//cout << strt << "\n";
		return strt;
}



DWORD RevByte(DWORD dword)
{
	return ((dword >> 24) & 0x000000FF) | ((dword >> 8) & 0x0000FF00) | ((dword << 8) & 0x00FF0000) | ((dword << 24) & 0xFF000000);
}

//Map limits//floating limits/positive
BOOLEAN CheckCoordLimit(DWORD limitx, DWORD limity){
	                   
	DWORD limitdown = 0x3a000000;
	DWORD limitup =   0x4fffffff;
	if ((limitx > limitdown && limitx < limitup) &
		(limity > limitdown && limity < limitup)) {
		return true;
	}
return false;
}

//Map limits
BOOLEAN CheckCoordLimit2(FLOAT limitx, FLOAT limity) {
	  
	if (LocalPlayer!=NULL){
		DWORD bb4 = VirtPReadDword(LocalPlayer + poff44);
		if (limitx >0.f && limity >0.f && ReadCoordX3()>0.f && ReadCoordY3()>0.f) {
			FLOAT xx = ReadCoordX3() - limitx;
			FLOAT yy = ReadCoordY3() - limity;
			FLOAT limitdownx = -20480.f;
			FLOAT limitupx = 20480.f;

			FLOAT limitdowny = -20480.f;
			FLOAT limitupy = 20480.f;


			if ((xx > limitdownx && xx < limitupx) &&
				(yy > limitdowny && yy < limitupy)) {
				return true;
			}
		}
		return false;
	}
	else {

		FLOAT limitdown = 1.f;
		FLOAT limitup = 10240000.f;
		if ((limitx > limitdown && limitx < limitup) &
			(limity > limitdown && limity < limitup)) {
			return true;
		}
	}
	return false;
}

//Visible area limits. Raw float
BOOLEAN CheckVisibleLimit(FLOAT limitx, FLOAT limity) {


	if ( limitx >0.f && limity >0.f && ReadCoordX3()>0.f && ReadCoordY3()>0.f ) {
		FLOAT xx = ReadCoordX3() - limitx;
		FLOAT yy = ReadCoordY3() - limity;
		FLOAT limitdownx = -20480.f;
		FLOAT limitupx = 20480.f;

		FLOAT limitdowny = -20480.f;
		FLOAT limitupy = 20480.f;


		if ((xx > limitdownx && xx < limitupx) &&
			(yy > limitdowny && yy < limitupy)) {
			return true;
		}
	}
	return false;
}

// Visible area limits. Word, cooked
BOOLEAN CheckVisibleLimit2(WORD limitx, WORD limity) {


	if (limitx >0.f && limity >0.f && ReadCoordX3()>0.f && ReadCoordY3()>0.f) {
		FLOAT xx = ReadCoordX3()/512.f - limitx;
		FLOAT yy = ReadCoordY3()/512.f - limity;
		FLOAT limitdownx = -50.f;
		FLOAT limitupx = 50.f;

		FLOAT limitdowny = -50.f;
		FLOAT limitupy = 50.f;


		if ((xx > limitdownx && xx < limitupx) &&
			(yy > limitdowny && yy < limitupy)) {
			return true;
		}
	}
	return false;
}

PatternSearch Chopbytes16(WORD val)
{
	vector<uint8_t>pp;
	pp.push_back(((val >> 0) & 0x000000ff));
	pp.push_back(((val >> 8) & 0x000000ff));
	return pp;
}
PatternSearch Chopbytes32(DWORD val)
{
	vector<uint8_t>pp;
	pp.push_back(((val >> 0) & 0x000000ff));
	pp.push_back(((val >> 8) & 0x000000ff));
	pp.push_back(((val >> 16) & 0x000000ff));
	pp.push_back(((val >> 24) & 0x000000ff));
	return pp;
}
PatternSearch Chopbytes64(DWORD64 val)
{
	vector<uint8_t>pp;
	pp.push_back(((val >> 0) & 0x000000ff));
	pp.push_back(((val >> 8) & 0x000000ff));
	pp.push_back(((val >> 16) & 0x000000ff));
	pp.push_back(((val >> 24) & 0x000000ff));
	pp.push_back(((val >> 32) & 0x000000ff));
	pp.push_back(((val >> 40) & 0x000000ff));
	pp.push_back(((val >> 48) & 0x000000ff));
	pp.push_back(((val >> 56) & 0x000000ff));
	return pp;
}

BOOLEAN WakeUp_()
{
	R1 = 1;
	R2 = 1;
    R3= 1;
	R4 = 1;
	R5= 1;
	R6 = 1;
	return true;
}



DWORD64 ScanM(PatternSearch patern,CHAR* TextToSay)
{

	std::vector<ptr_t> results;
	cout << "Lookin for addresses \n";
	if (!procIDs.empty())
	{
		patern.SearchRemoteWhole(proc, false,0, results);
		std::wcout << "Found " << results.size() << " : " << TextToSay<< "\n";
		if (!results.empty()){
			//cout << results.front();
			//cout << results[0];
		//printf("Address: %I64X\n", results.front());
		return results.front();
		}
	}
return 0;
}


  //goes in pairs!!
//address+offset(s) and static byte(s) in int?
//true up -, false down +
DWORD64 ScanMAdvanced2(PatternSearch patern, char* TextToSay, vector<DWORD> offset, vector<BYTE> byte2, vector<BOOLEAN> UpDown)
{

	vector<DWORD64> results;
	vector<INT> pointscounter (300000);
	INT num = 0;
	BYTE bb = 0;
	MEMss BlockA;
	
	cout << "Lookin for addresses \n";
	if (!procIDs.empty())
	{

		patern.SearchRemoteWhole(proc, false, 0, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			if (debug) { cout << dec << results.size() << "\n"; }
			if (offset.empty()) { return results[0]; }
			for (DWORD i = 0; i < results.size(); i++) {
				for (DWORD ii = 0; ii < offset.size(); ii++) {
					
					//printf("offset: %I64X\n", offset[ii]);
					//printf("byte: %I64X\n", byte2[ii]);
					//printf("orig: %I64X\n", results[i]);
					if (UpDown[ii]) {
						   bb = VirtPReadByte(results[i] - offset[ii]);
					}else{ bb = VirtPReadByte(results[i] + offset[ii]); }
					//printf("results[i]: %I64X\n", bb);
					if (bb==byte2[ii]) {
						pointscounter[i] ++;
						if (debug2) {
							cout << "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFOUND!!!" << pointscounter[i] << "\n";
							BlockA = DeterMemoryBlockLenght(results[i]);
							cout << hex << BlockA.start << "\n";
						}
						}
					}
				}
			for (int iii = 0; iii < pointscounter.size(); iii++) {

				if (pointscounter[iii] > num) {
					num = pointscounter[iii];
				}
			}
			for (int iiii = 0; iiii < pointscounter.size(); iiii++) {


				if (pointscounter[iiii] == num) {
					if (num == 0) { cout << "Found " << "ZeroScan \n"; return 0; }
					else {
						if (debug) {

							cout << "Found " << hex << results[iiii] << ":" << num << " : " << TextToSay << "Most bytematched" << "\n";
						}
						else {
							cout << "Found " << hex << ":" << num << " : " << TextToSay << "Most bytematched" << "\n";
						}
						return results[iiii];
					}
				}
			}
		}
	}
	return 0;
}

DWORD64 ScanMAdvanced2(PatternSearch patern, char* TextToSay, vector<DWORD> offset, vector<WORD> byte2, vector<BOOLEAN> UpDown)
{

	vector<DWORD64> results;
	vector<INT> pointscounter(30000);
	INT num = 0;
	WORD bb = 0;
	MEMss BlockA;

	cout << "Lookin for addresses \n";
	if (!procIDs.empty())
	{

		patern.SearchRemoteWhole(proc, false, 0, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			if (debug) { cout << dec << results.size() << "\n"; }		
			if (offset.empty()) { return results[0]; }

			for (DWORD i = 0; i < results.size(); i++) {
				for (DWORD ii = 0; ii < offset.size(); ii++) {
					//if (debug) { cout << hex << results[i] << "\n"; }
					//printf("offset: %I64X\n", offset[ii]);
					//printf("byte: %I64X\n", byte2[ii]);
					//printf("orig: %I64X\n", results[i]);
					if (UpDown[ii]) {
						bb = VirtPReadWord(results[i] - offset[ii]);
					}
					else { bb = VirtPReadWord(results[i] + offset[ii]); }
					//printf("results[i]:%d", i);
					//printf(": %I64X\n", bb);
					if (bb == byte2[ii]) {
						pointscounter[i] ++;
						if (debug2) {
							cout << "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFOUND!!!" << pointscounter[i] << "\n";
							BlockA = DeterMemoryBlockLenght(results[i]);
							cout << hex << BlockA.start << "\n";
						}
					}
				}
			}
			for (int iii = 0; iii < pointscounter.size(); iii++) {

				if (pointscounter[iii] > num) {
					num = pointscounter[iii];
				}
			}
			for (int iiii = 0; iiii < pointscounter.size(); iiii++) {


				if (pointscounter[iiii] == num) {
					if (num == 0) { cout << "Found " << "ZeroScan2 \n"; return 0; }
					else {
						if (debug) {

							cout << "Found " << hex << results[iiii] << ":" << num << " : " << TextToSay << "Most bytematched" << "\n";
						}
						else {
							cout << "Found " << hex << ":" << num << " : " << TextToSay << "Most bytematched" << "\n";
						}
						return results[iiii];
					}
				}
			}
		}
	}
	return 0;
}

DWORD64 ScanMAdvanced2(PatternSearch patern, char* TextToSay, vector<DWORD> offset, vector<DWORD> byte2, vector<BOOLEAN> UpDown)
{

	vector<DWORD64> results;
	vector<INT> pointscounter(30000);
	INT num = 0;
	DWORD bb = 0;
	MEMss BlockA;

	cout << "Lookin for addresses \n";
	if (!procIDs.empty())
	{
		
		patern.SearchRemoteWhole(proc, false, 0, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			if (debug) { cout << dec << results.size() << "\n"; }
			if (offset.empty()) { return results[0]; }

			for (DWORD i = 0; i < results.size(); i++) {
				for (DWORD ii = 0; ii < offset.size(); ii++) {

					//printf("offset: %I64X\n", offset[ii]);
					//rintf("byte: %I64X\n", byte2[ii]);
					//printf("orig: %I64X\n", results[i]);
					if (UpDown[ii]) {
						bb = VirtPReadDword(results[i] - offset[ii]);
					}
					else { bb = VirtPReadDword(results[i] + offset[ii]); }
					//printf("results[i]:%I64X",i,": ",bb,"\n");
					if (bb == byte2[ii]) {
						pointscounter[i] ++;
						if (debug2) { 
							cout << "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFOUND!!!" << pointscounter[i] << "\n"; 
							BlockA = DeterMemoryBlockLenght(results[i]);
							cout << hex << BlockA.start << "\n";
						}
					}
				}
			}
			for (int iii = 0; iii < pointscounter.size(); iii++) {

				if (pointscounter[iii] > num) {
					num = pointscounter[iii];
				}
			}
			for (int iiii = 0; iiii < pointscounter.size(); iiii++) {


				if (pointscounter[iiii] == num) {
					if (num == 0) { cout << "Found " << "ZeroScan3 \n"; return 0; }
					else {
						if (debug) {

							cout << "Found " << hex << results[iiii] << ":" << num << " : " << TextToSay << "Most bytematched" << "\n";
						}
						else {
							cout << "Found " << hex << ":" << num << " : " << TextToSay << "Most bytematched" << "\n";
						}
						return results[iiii];
					}
				}
			}
		}
	}
	return 0;
}

DWORD64 ScanMAdvanced2(PatternSearch patern, char* TextToSay, vector<DWORD> offset, vector<DWORD64> byte2, vector<BOOLEAN> UpDown)
{

	vector<DWORD64> results;
	vector<INT> pointscounter(300000);
	INT num = 0;
	DWORD64 bb = 0;
	MEMss BlockA;

	cout << "Lookin for addresses \n";
	if (!procIDs.empty())
	{

		patern.SearchRemoteWhole(proc, false, 0, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			if (debug) { cout << dec << results.size() << "\n"; }
			if (offset.empty()) { return results[0]; }


			for (DWORD i = 0; i < results.size(); i++) {
				for (DWORD ii = 0; ii < offset.size(); ii++) {

					//printf("offset: %I64X\n", offset[ii]);
					//printf("byte: %I64X\n", byte2[ii]);
					//printf("orig: %I64X\n", results[i]);
					if (UpDown[ii]) {
						bb = VirtPRead64(results[i] - offset[ii]);
					}
					else { bb = VirtPRead64(results[i] + offset[ii]); }
					//printf("results[i]: %I64X\n", bb);
					if (bb == byte2[ii]) {
						pointscounter[i] ++;
						if (debug2) {
							cout << "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFOUND!!!" << pointscounter[i] << "\n";
							BlockA = DeterMemoryBlockLenght(results[i]);
							cout << hex << BlockA.start << "\n";
						}
					}
				}
			}
			for (int iii = 0; iii < pointscounter.size(); iii++) {

				if (pointscounter[iii] > num) {
					num = pointscounter[iii];
				}
			}
			for (int iiii = 0; iiii < pointscounter.size(); iiii++) {


				if (pointscounter[iiii] == num) {
					if (num == 0) { cout << "Found " << "ZeroScan4 \n"; return 0; }
					else {
						if (debug) {

							cout << "Found " << hex << results[iiii] << ":" << num << " : " << TextToSay << "Most bytematched" << "\n";
						}
						else {
							cout << "Found " << hex << ":" << num << " : " << TextToSay << "Most bytematched" << "\n";
						}
						return results[iiii];
					}
				}
			}
		}
	}
	return 0;
}

//goes in pairs!!
//address+offset(s) and static byte(s) in int?
//true up -, false down +
DWORD64 ScanMAdvanced22(PatternSearch patern, DWORD64 start, DWORD64 range, char* TextToSay, vector<DWORD> offset, vector<BYTE> byte2, vector<BOOLEAN> UpDown)
{

	vector<DWORD64> results;
	vector<INT> pointscounter(300000);
	INT num = 0;
	BYTE bb = 0;
	MEMss BlockA;

	cout << "Lookin for addresses \n";
	if (!procIDs.empty())
	{
		patern.SearchRemoteEx(proc, start, range, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			if (debug) { cout << dec << results.size() << "\n"; }
			if (offset.empty()) {
				if (debug) { printf("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFOUND!!!: %I64X\n", results[0]); }
				else {
					printf("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFOUND!!! \n");
				}
				
				return results[0];
			}


			for (DWORD i = 0; i < results.size(); i++) {
				for (DWORD ii = 0; ii < offset.size(); ii++) {

					//printf("offset: %I64X\n", offset[ii]);
					//printf("byte: %I64X\n", byte2[ii]);
					//printf("orig: %I64X\n", results[i]);
					if (UpDown[ii]) {
						bb = VirtPReadByte(results[i] - offset[ii]);
					}
					else { bb = VirtPReadByte(results[i] + offset[ii]); }
					//printf("results[i]: %I64X\n", bb);
					if (bb == byte2[ii]) {
						pointscounter[i] ++;
						if (debug2) {
							cout << "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFOUND!!!" << pointscounter[i] << "\n";
							BlockA = DeterMemoryBlockLenght(results[i]);
							cout << hex << BlockA.start << "\n";
						}
					}
				}
			}
			for (int iii = 0; iii < pointscounter.size(); iii++) {

				if (pointscounter[iii] > num) {
					num = pointscounter[iii];
				}
			}
			for (int iiii = 0; iiii < pointscounter.size(); iiii++) {


				if (pointscounter[iiii] == num) {
					if (num == 0) { cout << "Found " << "ZeroScan5 \n"; return 0; }
					else {
						if (debug) {

							cout << "Found " << hex << results[iiii] << ":" << num << " : " << TextToSay << "Most bytematched" << "\n";
						}
						else {
							cout << "Found " << hex  << ":" << num << " : " << TextToSay << "Most bytematched" << "\n";
						}
						return results[iiii];
					}
				}
			}
		}
	}
	return 0;
}

DWORD64 ScanMAdvanced22(PatternSearch patern,DWORD64 start, DWORD64 range, char* TextToSay, vector<DWORD> offset, vector<WORD> byte2, vector<BOOLEAN> UpDown)
{

	vector<DWORD64> results;
	vector<INT> pointscounter(300000);
	INT num = 0;
	WORD bb = 0;
	MEMss BlockA;

	cout << "Lookin for addresses \n";
	if (!procIDs.empty())
	{
		patern.SearchRemoteEx(proc, start, range, results);
		//patern.SearchRemote(proc, 0xffff, 0xfff, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			if (debug) {cout << dec << results.size() << "\n";}
			if (offset.empty()) {
				if (debug) { printf("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFOUND!!!: %I64X\n", results[0]); }
				else {
					printf("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFOUND!!! \n");
				}
				return results[0];
			}

			for (DWORD i = 0; i < results.size(); i++) {
				for (DWORD ii = 0; ii < offset.size(); ii++) {

					//printf("offset: %I64X\n", offset[ii]);
					//printf("byte: %I64X\n", byte2[ii]);
					//printf("orig: %I64X\n", results[i]);
					if (UpDown[ii]) {
						bb = VirtPReadWord(results[i] - offset[ii]);
					}
					else { bb = VirtPReadWord(results[i] + offset[ii]); }
					//printf("results[i]:%d", i);
					//printf(": %I64X\n", bb);
					if (bb == byte2[ii]) {
						pointscounter[i] ++;
						if (debug2) {
							cout << "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFOUND!!!" << pointscounter[i] << "\n";
							BlockA = DeterMemoryBlockLenght(results[i]);
							cout << hex << BlockA.start << "\n";
						}
					}
				}
			}
			for (int iii = 0; iii < pointscounter.size(); iii++) {

				if (pointscounter[iii] > num) {
					num = pointscounter[iii];
				}
			}
			for (int iiii = 0; iiii < pointscounter.size(); iiii++) {


				if (pointscounter[iiii] == num) {
					if (num == 0) { cout << "Found " << "ZeroScan6 \n"; return 0; }
					else {
						if (debug) {

							cout << "Found " << hex << results[iiii] << ":" << num << " : " << TextToSay << "Most bytematched" << "\n";
						}
						else {
							cout << "Found " << hex << ":" << num << " : " << TextToSay << "Most bytematched" << "\n";
						}
						return results[iiii];
					}
				}
			}
		}
	}
	return 0;
}

DWORD64 ScanMAdvanced22(PatternSearch patern,DWORD64 start, DWORD64 range, char* TextToSay, vector<DWORD> offset, vector<DWORD> byte2, vector<BOOLEAN> UpDown)
{

	vector<DWORD64> results;
	vector<INT> pointscounter(300000);
	INT num = 0;
	DWORD bb = 0;
	MEMss BlockA;

	cout << "Lookin for addresses \n";
	if (!procIDs.empty())
	{
		patern.SearchRemoteEx(proc, start, range, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			if (debug) { cout << dec << results.size() << "\n"; }
			if (offset.empty()) { 
				if (debug) { printf("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFOUND!!!: %I64X\n", results[0]); }
				else {
					printf("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFOUND!!! \n");
				}
				return results[0];
			}

			for (DWORD i = 0; i < results.size(); i++) {
				for (DWORD ii = 0; ii < offset.size(); ii++) {

					//printf("offset: %I64X\n", offset[ii]);
					//rintf("byte: %I64X\n", byte2[ii]);
					//printf("orig: %I64X\n", results[i]);
					if (UpDown[ii]) {
						bb = VirtPReadDword(results[i] - offset[ii]);
					}
					else { bb = VirtPReadDword(results[i] + offset[ii]); }
					//printf("results[i]:%I64X",i,": ",bb,"\n");
					if (bb == byte2[ii]) {
						pointscounter[i] ++;
						if (debug2) {
							cout << "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFOUND!!!" << pointscounter[i] << "\n";
							BlockA = DeterMemoryBlockLenght(results[i]);
							cout << hex << BlockA.start << "\n";
						}
					}
				}
			}
			for (int iii = 0; iii < pointscounter.size(); iii++) {

				if (pointscounter[iii] > num) {
					num = pointscounter[iii];
				}
			}
			for (int iiii = 0; iiii < pointscounter.size(); iiii++) {


				if (pointscounter[iiii] == num) {
					if (num == 0) { cout << "Found " << "ZeroScan7 \n"; return 0; }
					else {
						if (debug) {

							cout << "Found " << hex << results[iiii] << ":" << num << " : " << TextToSay << "Most bytematched" << "\n";
						}
						else {
							cout << "Found " << hex << ":" << num << " : " << TextToSay << "Most bytematched" << "\n";
						}
						return results[iiii];
					}
				}
			}
		}
	}
	return 0;
}

DWORD64 ScanMAdvanced22(PatternSearch patern, DWORD64 start, DWORD64 range, char* TextToSay, vector<DWORD> offset, vector<DWORD64> byte2, vector<BOOLEAN> UpDown)
{

	vector<DWORD64> results;
	vector<INT> pointscounter(300000);
	INT num = 0;
	DWORD64 bb = 0;
	MEMss BlockA;

	cout << "Lookin for addresses \n";
	if (!procIDs.empty())
	{
		patern.SearchRemoteEx(proc, start, range, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			if (debug) { cout << dec << results.size() << "\n"; }
			if (offset.empty()) {
				if (debug) { printf("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFOUND!!!: %I64X\n", results[0]); }
				else {
					printf("FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFOUND!!! \n");
				}
				return results[0];
			}

			for (DWORD i = 0; i < results.size(); i++) {
				for (DWORD ii = 0; ii < offset.size(); ii++) {
				//	printf("orig: %I64X\n", results[i]);
					//printf("offset: %I64X\n", offset[ii]);
					//printf("byte: %I64X\n", results[i] - offset[ii]);
					//printf("orig: %I64X\n", results[i]);
					if (UpDown[ii]) {
						bb = VirtPRead64(results[i] - offset[ii]);
					}
					else { bb = VirtPRead64(results[i] + offset[ii]); }
					//printf("results[i]:%d", i);
					//printf(": %I64X\n", bb);
					if (bb == byte2[ii]) {
						pointscounter[i] ++;
						if (debug2) {
							cout << "FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFOUND!!!" << pointscounter[i] << "\n";
							BlockA = DeterMemoryBlockLenght(results[i]);
							cout << hex << BlockA.start << "\n";
						}
					}
				}
			}
			for (int iii = 0; iii < pointscounter.size(); iii++) {

				if (pointscounter[iii] > num) {
					num = pointscounter[iii];
				}
			}
			for (int iiii = 0; iiii < pointscounter.size(); iiii++) {


				if (pointscounter[iiii] == num) {
					if (num == 0) { cout << "Found " << "ZeroScan8 \n"; return 0; }
					else {
						if (debug) {

							cout << "Found " << hex << results[iiii] << ":" << num << " : " << TextToSay << "Most bytematched" << "\n";
						}
						else {
							cout << "Found " << hex << ":" << num << " : " << TextToSay << "Most bytematched" << "\n";
						}
						return results[iiii];
					}
				}
			}
		}
	}
	return 0;
}




//Locates some needed adresses from exe(not to actual info, arrays hints to this exe memory location, now in reverse we are gona
//use this to find those arrays)
//For active objects, those are closeby
DWORD64 ScanforExe1() {

	vector<DWORD64> results;
	//
	//6C 69 73 74 3C 54 3E 20 
	//74 6F 6F 20 6C 6F 6E 67
	PatternSearch PS{
		0x6c, 0x69, 0x73, 0x74, 0x3c, 0x54, 0x3e, 0x20,
		0x74, 0x6f, 0x6f, 0x20, 0x6c, 0x6f, 0x6e, 0x67
	};

	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{
		//there should be only 1 match
		                         ///700k lines? 7mb=?
		PS.SearchRemoteEx(proc, RSExeStart, RSExeStart+RSExeSize, results);
		if (results.empty()) { cout << "Found non exe1 \n"; }
		if (!results.empty()) {
			if (debug) {
				cout << "exe1 result: " << dec << results.size() << "\n";
				//cout << "exe1 result needed: " << hex << results[0]+0xe8 << "\n";
				//cout << "exe1 result needed: " << hex << results[0] + 0x10e0 << "\n";
				//cout << "exe1 result needed: " << hex << results[0] + 0x1310 << "\n";
				cout << "exe1 result: " << hex << results[0] << "\n";
			}
			return results[0];
		}


	}
	return 0;
}

//Locates some needed adresses from exe(not to actual info, arrays hints to this exe memory location, now in reverse we are gona
//use this to find those arrays)
//grounditems
DWORD64 ScanforExe2() {

	vector<DWORD64> results;
	//VorbisWorker
	//56 6F 72 62 69 73 57 6F 
	//72 6B 65 72 00 00 00 00
	PatternSearch PS{
		0x56, 0x6f, 0x72, 0x62, 0x69, 0x73, 0x57, 0x6f,
		0x72, 0x6b, 0x65, 0x72, 0x00, 0x00, 0x00, 0x00
	};

	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{
		//win10 0xa58

		PS.SearchRemoteEx(proc, RSExeStart, RSExeStart + RSExeSize, results);
		if (results.empty()) { cout << "Found non exe2 \n"; }
		if (!results.empty()) {
			if (debug) {
				cout << "exe2 GI: " << dec << results.size() << "\n";
				//cout << "exe2 GI needed: " << hex << results[0]-0xa58 << "\n";
				cout << "exe2 GI result: " << hex << results[0] << "\n";
			}
			return results[0];
		}


	}
	return 0;
}

//Locates some needed adresses from exe(not to actual info, arrays hints to this exe memory location, now in reverse we are gona
//use this to find those arrays)
//new npc
DWORD64 ScanforExe3() {

	vector<DWORD64> results;
	//59 3D 25 64 29 00 00 00 //Y=%d)
	PatternSearch PS{
		0x59, 0x3d, 0x25, 0x64, 0x29, 0x00, 0x00, 0x00
	};

	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{
		//there should be only 1 match
		PS.SearchRemoteEx(proc, RSExeStart, RSExeStart + RSExeSize, results);
		if (results.empty()) { cout << "Found non exe-npc line \n"; }
		if (!results.empty()) {
			if (debug) {
				cout << "exe npc: " << dec << results.size() << "\n";
				//68 up
				//cout << "exe npc: " << hex << results[0] + 0x10 << "\n";
				//cout << "exe2 result needed: " << hex << results[0] + 0x10e0 << "\n";
				//cout << "exe2 result needed: " << hex << results[0] + 0x1310 << "\n";
				cout << "exe npc result: " << hex << results[0] << "\n";
			}
			return results[0];
		}


	}
	return 0;
}

//For 2nd grounditems dimensions
DWORD64 ScanforExe4() {

	vector<DWORD64> results;
	//passwordchoice.w
	//70 61 73 73 77 6F 72 64 
	//63 68 6F 69 63 65 2E 77
	PatternSearch PS{
		0x70, 0x61, 0x73, 0x73, 0x77, 0x6f, 0x72, 0x64,
		0x63, 0x68, 0x6f, 0x69, 0x63, 0x65, 0x2e, 0x77
	};

	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{
		//there should be only 1 match
		PS.SearchRemoteEx(proc, RSExeStart, RSExeStart+RSExeSize, results);
		if (results.empty()) { cout << "Found non exe4 \n"; }
		if (!results.empty()) {
			if (debug) {
				//win10 +0x48
				cout << "exe4 resultsize: " << dec << results.size() << "\n";
				cout << "exe4 result: " << hex << results[0] << "\n";
			}
			return results[0];
		}


	}
	return 0;
}

//For decor objects
DWORD64 ScanforExe5() {

	vector<DWORD64> results;
	//list<T> too long
	//6C 69 73 74 3C 54 3E 20 
	//74 6F 6F 20 6C 6F 6E 67
	PatternSearch PS{
		0x6c, 0x69, 0x73, 0x74, 0x3c, 0x54, 0x3e, 0x20,
		0x74, 0x6f, 0x6f, 0x20, 0x6c, 0x6f, 0x6e, 0x67
	};

	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{
		//there should be only 1 match
		PS.SearchRemoteEx(proc, RSExeStart, RSExeStart + RSExeSize, results);
		if (results.empty()) { cout << "Found non exe5 \n"; }
		if (!results.empty()) {
			if (debug) {
				//win10 
				cout << "exe5 resultsize: " << dec << results.size() << "\n";
				cout << "exe5 result: " << hex << results[0] << "\n";
			}
			return results[0];
		}


	}
	return 0;
}

//For projectiles
DWORD64 ScanforExe6() {

	vector<DWORD64> results;
	//list<T> too long +0x620
	//totp +0x60
	//74 6F 74 70 00 00 00 00
	PatternSearch PS{
		0x74, 0x6f, 0x74, 0x70, 0x0, 0x0, 0x0, 0x0
	};

	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{
		//there should be only 1 match
		PS.SearchRemoteEx(proc, RSExeStart, RSExeStart + RSExeSize, results);
		if (results.empty()) { cout << "Found non exe6 \n"; }
		if (!results.empty()) {
			if (debug) {
				//win10 
				cout << "exe6 resultsize: " << dec << results.size() << "\n";
				cout << "exe6 result: " << hex << results[0] << "\n";
			}
			return results[0];
		}


	}
	return 0;
}

//For temporary interfaces
/*
DWORD64 ScanforExe7() {

	vector<DWORD64> results;
	//62 72 6F 6B 65 6E 20 70 
	//72 6F 6D 69 73 65 00 00
	//broken promise

	PatternSearch PS{
		0x62, 0x72, 0x6f, 0x6b, 0x65, 0x6e, 0x20, 0x70,
		0x72, 0x6f, 0x6d, 0x69, 0x73, 0x65, 0x0, 0x0
	};

	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{
		//there should be only 1 match
		PS.SearchRemoteEx(proc, RSExeStart, RSExeStart + RSExeSize, results);
		if (results.empty()) { cout << "Found non exe7 \n"; }
		if (!results.empty()) {
			if (debug) {
				//win10 
				cout << "exe7 resultsize: " << dec << results.size() << "\n";
				cout << "exe7 result: " << hex << results[0] << "\n";
			}
			return results[0];
		}


	}
	return 0;
}
*/

//tryies to locate interfaces
//returns first found
DWORD64 ScanforInterf()
{
	DWORD64 start= LocalPlayer;
    DWORD64 range= LocalPlayer +0x80000000;
	vector<DWORD64> results;
	vector<DWORD64> results2;
	WORD bb0 = 0;
	WORD bb1 = 0;
	WORD bb2 = 0;
	WORD bb3 = 0;
	WORD bb4 = 0;
	DWORD64 bb5 = 0;
	DWORD64 bb6 = 0;
	DWORD64 bb7 = 0;
	DWORD64 bb8 = 0;
	DWORD64 bb9 = 0;
	PatternSearch PS{
		0xc5, 0x05, 0x00
	};
	DWORD diff = 0x810;
	DWORD diff2 = 0x820;
	MEMss BlockA;




	cout << "Lookin for interfaces" << "\n";
	if (HProc !=NULL)
	{
		PS.SearchRemoteEx(proc, start, range, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			if (debug2) { cout << "result: " << dec << results.size() << "\n"; }
			for (DWORD i = 0; i < results.size(); i++) {

					bb0 = VirtPReadWord(results[i] + diff); 
					bb1 = VirtPReadWord(results[i] + diff*2);
					bb2 = VirtPReadWord(results[i] + diff*3);
					bb3 = VirtPReadWord(results[i] + diff*4);
					bb4 = VirtPReadWord(results[i] + diff * 5);

					bb5 = VirtPRead64(results[i] + diff + 0x10);
					bb6 = VirtPRead64(results[i] + diff *2 + 0x10);
					bb7 = VirtPRead64(results[i] + diff *3 + 0x10);
					bb8 = VirtPRead64(results[i] + diff *4 + 0x10);
					bb9 = VirtPRead64(results[i] + diff *5 + 0x10);


				if (bb0 ==0x05c5  && bb1 == 0x05c5 && bb2 == 0x05c5 && bb3 == 0x05c5 && bb4 == 0x05c5 &&
					bb5 == 0x0 && bb6 == 0x0 && bb7 == 0x0 && bb8 == 0x0 && bb9 == 0x0) {
					if (debug) { 				
						cout << "InterfacesF: " << results[i] << "\n"; 
						BlockA = DeterMemoryBlockLenght(results[i]);
						cout << hex << BlockA.start << "\n";
					}
					return results[i];
				}
			}
		}
	}
	return{ 0 };
}

//tryies to find Players
DWORD64 ScanPlayers()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;

	//
	DWORD offset1 = 0x2c;
	DWORD value1 = 0x04000000;
	DWORD offset2 = 0x20;
	DWORD offset22 = 0x30;
	DWORD offset3 = 0x38;
	DWORD offset4 = 0x40;


	//
	PatternSearch PS{
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x10, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00,
	};

	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{

		//there should be only 1 match
		//cant be whole memory??
		//PS.SearchRemoteWhole(proc, 0, 0, results);
		                          //      0x1f47efc5010
		PS.SearchRemoteEx(proc, 0x5000000, 0x30000000000, results);
		if (results.empty()) { cout << "Found non players array \n"; }
		if (!results.empty()) {
			if (debug) { cout << "players result: " << dec << results.size() << "\n"; }

			for (DWORD i = 0; i < results.size(); i++) {

				DWORD bb1 = VirtPReadDword(results[i] + offset1);
				DWORD64 bb2 = VirtPRead64(results[i] + offset2);
				DWORD64 bb22 = VirtPRead64(results[i] + offset22);
				DWORD64 bb3 = VirtPRead64(results[i] + offset3);
				DWORD64 bb4 = VirtPRead64(results[i] + offset4);


				if (bb1 == value1 && bb2 ==0 && bb22 == 0 && bb3 >0 && bb4 >0) {
					results2.push_back(results[i]);
				}
			}
			//2nd/there should be only 1 match
			if (!results2.empty()) {
				cout << "players result2s: " << dec << results2.size() << "\n";
				cout << "players result2: " << hex << results2[0] << "\n";
				//cout << "npc result2: " << hex << results2[1] << "\n";
				return results2[0];
			}
			else { cout << "Failed to find players match" << "/n"; }
		}
	}
	return 0;
}

//tryies to find all stuff on screen
DWORD64 ScanAllObjects()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;

	//
	DWORD offset1 = 0x2c;
	DWORD value1 = 0x04000000;


	//
	PatternSearch PS{
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x40, 0x6a, 0x00, 0x00, 0x00, 0x00, 0x00
	};

	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{

		//there should be only 1 match
		//cant be whole memory??
		//PS.SearchRemoteWhole(proc, 0, 0, results);
		//      0x1f47efc5010
		PS.SearchRemoteEx(proc, 0x5000000, 0x30000000000, results);
		if (results.empty()) { cout << "Found non AllObj \n"; }
		if (!results.empty()) {
			if (debug) { cout << "AllObj result: " << dec << results.size() << "\n"; }

			for (DWORD i = 0; i < results.size(); i++) {

				DWORD bb1 = VirtPReadDword(results[i] + offset1);

				if (bb1 == value1) {
					results2.push_back(results[i]);
				}
			}
			//2nd/there should be only 1 match
			if (!results2.empty()) {
				cout << "AllObj result2s: " << dec << results2.size() << "\n";
				cout << "AllObj result2: " << hex << results2[0] << "\n";
				//cout << "AllObj result2: " << hex << results2[1] << "\n";
				return results2[0];
			}
			else { cout << "Failed to find AllObj" << "/n"; }
		}
	}
	return 0;
}

//ScanforExe1
//tryies to find active objects array beginning
DWORD64 ScanAObjects()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	///
	vector<DWORD64> results3;

	//
	//DWORD offset1 = 0x20;
	//DWORD64 value1 = Exe1+ 0xB08;


	PatternSearch PS1{};


	//cout << "Lookin for \n";
	if (!procIDs.empty() && Exe1 != NULL)
	{
		//Lets pick first line in objects
		//w10 0x578
		//w7  0x470
		//
		PS1 = Chopbytes64(Exe1 +0x578);
		DWORD64 ScanPlaceHolder = LocalPlayer;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		PS1.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found non objA \n"; }

		if (!results.empty()) {
			if (debug) { cout << "objA result: " << dec << results.size() << "\n"; }

			//loop for matches
			for (DWORD i = 0; i < results.size(); i++) {

				//DWORD64 v1 = VirtPRead64(results[i] + offset1);
				//DWORD64 v2 = VirtPRead64(results[i] + offset2);

				//if (v1 == value1) {
					results2.push_back(results[i]);
				//}
			}
		}

	    //its seems there is always something written even if spot is empty
		//lets get to the top/block start step by step
		//BlockA = DeterMemoryBlockLenght(results2	[0]);
/*
			int up = 100; int step = 0x300; int count= 0;
			for (DWORD i = 0; i < up; i++) {
				count = count + step;
				DWORD64 v1 = VirtPRead64(results2[i]);


			}

			for (DWORD i = 0; i < up; i++) {

			}
		}
		*/



			if (!results2.empty()) {
				cout << "objA result2s: " << dec << results2.size() << "\n";
				//pick middle one and hope its right
				int mid = results2.size()/2;
				cout << "objA result2: " << hex << results2[mid] << "\n";
				return results2[mid];
			}else { cout << "Failed to find objA match" << "/n"; return 0;}
		}
	return 0;
}

//
//for locating settings
DWORD64 ScanSet()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	///
	vector<DWORD64> results3;

	//
	//DWORD offset1 = 0x20;
	//DWORD64 value1 = Exe1+ 0xB08;


	PatternSearch PS{
		0x12, 0x04, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	};


	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{
		//Lets pick first line in objects
		//w10 0x578
		//w7  0x470
		//
		//PS1 = Chopbytes64(Exe1 + 0x578);
		DWORD64 ScanPlaceHolder = LocalPlayer;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		PS.SearchRemoteWhole(proc, 0, 0, results);
		if (results.empty()) { cout << "Found non Set \n"; }

		if (!results.empty()) {
			if (debug) { cout << "Set result: " << dec << results.size() << "\n"; }

			//loop for matches
			for (DWORD i = 0; i < results.size(); i++) {

				DWORD64 v1 = VirtPRead64(results[i] - 0x10);
				BYTE v2 = VirtPReadByte(results[i] - 0x11);
				DWORD64 v3 = VirtPRead64(results[i] + 0x10);

				if (v1 == 1 && v2==0x91 && v3==0x00000000000003EA) {
				results2.push_back(results[i]);
				}
			}
		}

		//its seems there is always something written even if spot is empty
		//lets get to the top/block start step by step
		//BlockA = DeterMemoryBlockLenght(results2	[0]);
		/*
		int up = 100; int step = 0x300; int count= 0;
		for (DWORD i = 0; i < up; i++) {
		count = count + step;
		DWORD64 v1 = VirtPRead64(results2[i]);


		}

		for (DWORD i = 0; i < up; i++) {

		}
		}
		*/



		if (!results2.empty()) {
			cout << "Set result2s: " << dec << results2.size() << "\n";
			//pick middle one and hope its right
			int mid = results2.size() / 2;
			cout << "Set result2: " << hex << results2[mid]-0x18 << "\n";
			return results2[mid]-0x18;
		}
		else { cout << "Failed to find Set match" << "\n"; return 0; }
	}
	return 0;
}

//ScanforExe2
//tryies to find ground stuff
DWORD64 ScanGr()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	///
	vector<DWORD64> results3;

	//
	DWORD offset1 = 0xc;
	DWORD64 value1 = 1;

	PatternSearch PS1{};

	//cout << "Lookin for \n";
	if (!procIDs.empty() && Exe2 != NULL)
	{
		PS1 = Chopbytes64(Exe2 -0xa58);
		//
		DWORD64 ScanPlaceHolder = LocalPlayer;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		PS1.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found non gr \n"; }

		if (!results.empty()) {
			if (debug) { cout << "gr result: " << dec << results.size() << "\n"; }

			//loop for matches
			for (DWORD i = 0; i < results.size(); i++) {

				DWORD v1 = VirtPReadDword(results[i] + offset1);			

				if (v1 == value1) {
					results2.push_back(results[i]);
				}
			}
		}

		if (!results2.empty()) {
			cout << "gr result2s: " << dec << results2.size() << "\n";
			//pick middle one and hope its right
			int mid = results2.size() / 2;
			cout << "gr result2: " << hex << results2[mid] << "\n";
			return results2[mid];
		}
		else { cout << "Failed to find gr match" << "\n"; return 0; }
	}
	return 0;
}

//ScanforExe3
//tryies to find npc array
DWORD64 ScanNPCs()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	///
	vector<DWORD64> results3;

	//
	//DWORD offset1 = 0x20;
	//DWORD64 value1 = Exe1+ 0xB08;


	PatternSearch PS1{};


	//cout << "Lookin for \n";
	if (!procIDs.empty() && Exe3 != NULL)
	{
		//Lets pick first line in objects
		//w10 0x68
		//w7  0x6C8
		PS1 = Chopbytes64(Exe3 - 0x68);
		//cout << "AChop" << hex << Exe1 + 0x6C8 << "\n";
		DWORD64 ScanPlaceHolder = LocalPlayer;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack;
		}		
		ScanEnd = ScanPlaceHolder + ScanFoward;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		PS1.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found non NPCscan \n"; }

		if (!results.empty()) {
			if (debug) { cout << "NPCscan result: " << dec << results.size() << "\n"; }

			//loop for matches
			for (DWORD i = 0; i < results.size(); i++) {

				//DWORD64 v1 = VirtPRead64(results[i] + offset1);
				//DWORD64 v2 = VirtPRead64(results[i] + offset2);

				//if (v1 == value1) {
				results2.push_back(results[i]);
				//}
			}
		}

		//its seems there is always something written even if spot is empty
		//lets get to the top/block start step by step
		//BlockA = DeterMemoryBlockLenght(results2	[0]);
		/*
		int up = 100; int step = 0x300; int count= 0;
		for (DWORD i = 0; i < up; i++) {
		count = count + step;
		DWORD64 v1 = VirtPRead64(results2[i]);


		}

		for (DWORD i = 0; i < up; i++) {

		}
		}
		*/



		if (!results2.empty()) {
			cout << "NPCscan result2s: " << dec << results2.size() << "\n";
			//pick middle one and hope its right
			int mid = results2.size() / 2;
			cout << "NPCscan result2: " << hex << results2[mid] << "\n";
			return results2[mid];
		}
		else { cout << "Failed to find NPCscan match" << "\n"; return 0; }
	}
	return 0;
}

//ScanforExe4
//tryies to find grounditems 2nd//dimensions
DWORD64 ScanGr2()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	///
	vector<DWORD64> results3;

	//
	//DWORD offset1 = 0x20;
	//DWORD64 value1 = Exe1+ 0xB08;


	PatternSearch PS1{};


	//cout << "Lookin for \n";
	if (!procIDs.empty() && Exe4 != NULL)
	{
		//Lets pick first line in objects
		//w10 +0x48
		//w7  0x6C8
		PS1 = Chopbytes64(Exe4 + 0x48);

		DWORD64 ScanPlaceHolder = LocalPlayer;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		PS1.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found non Gr2 \n"; }

		if (!results.empty()) {
			if (debug) { cout << "Gr2 result: " << dec << results.size() << "\n"; }

			//loop for matches
			for (DWORD i = 0; i < results.size(); i++) {

				//DWORD64 v1 = VirtPRead64(results[i] + offset1);
				//DWORD64 v2 = VirtPRead64(results[i] + offset2);

				//if (v1 == value1) {
				results2.push_back(results[i]);
				//}
			}
		}

		//its seems there is always something written even if spot is empty
		//lets get to the top/block start step by step
		//BlockA = DeterMemoryBlockLenght(results2	[0]);
		/*
		int up = 100; int step = 0x300; int count= 0;
		for (DWORD i = 0; i < up; i++) {
		count = count + step;
		DWORD64 v1 = VirtPRead64(results2[i]);


		}

		for (DWORD i = 0; i < up; i++) {

		}
		}
		*/



		if (!results2.empty()) {
			cout << "Gr2 result2s: " << dec << results2.size() << "\n";
			//pick middle one and hope its right
			int mid = results2.size() / 2;
			cout << "Gr2 result2: " << hex << results2[mid] << "\n";
			return results2[mid];
		}
		else { cout << "Failed to find Gr2 match" << "\n"; return 0; }
	}
	return 0;
}

//ScanforExe5
//tryies to find decor objects
DWORD64 ScanDecor()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	///
	vector<DWORD64> results3;

	PatternSearch PS1{};


	//cout << "Lookin for \n";
	if (!procIDs.empty() && Exe5 != NULL)
	{
		//Lets pick first line in objects
		//w10 +0x200
		//w7  0x7C0
		PS1 = Chopbytes64(Exe5 + 0x80);

		DWORD64 ScanPlaceHolder = LocalPlayer;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		PS1.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found non decor \n"; }

		if (!results.empty()) {
			if (debug) { cout << "decor result: " << dec << results.size() << "\n"; }

			//loop for matches
			for (DWORD i = 0; i < results.size(); i++) {

				//DWORD64 v1 = VirtPRead64(results[i] + offset1);
				//DWORD64 v2 = VirtPRead64(results[i] + offset2);

				//if (v1 == value1) {
				results2.push_back(results[i]);
				//}
			}
		}

		//its seems there is always something written even if spot is empty
		//lets get to the top/block start step by step
		//BlockA = DeterMemoryBlockLenght(results2	[0]);
		/*
		int up = 100; int step = 0x300; int count= 0;
		for (DWORD i = 0; i < up; i++) {
		count = count + step;
		DWORD64 v1 = VirtPRead64(results2[i]);


		}

		for (DWORD i = 0; i < up; i++) {

		}
		}
		*/



		if (!results2.empty()) {
			cout << "decor result2s: " << dec << results2.size() << "\n";
			//pick middle one and hope its right
			int mid = results2.size() / 2;
			cout << "decor result2: " << hex << results2[mid] << "\n";
			return results2[mid];
		}
		else { cout << "Failed to find decor match" << "\n"; return 0; }
	}
	return 0;
}

//old
//tryies to find decorative objects array beginning
DWORD64 ScanDObjects()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;

	//inv item
	DWORD offset1 = 0x2d;
	DWORD value1 = 0x04000000;
	//DWORD offset2 = 0x42;
	//DWORD64 value2 = 0x0000000100000000;

	
	PatternSearch PS1{
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
		0x00, 0x00, 0x20, 0x11, 0x00, 0x00, 0x00, 0x00
	};

	//cout << "Lookin for  \n";
	if (!procIDs.empty())
	{
		
		DWORD64 ScanPlaceHolder = LocalPlayer;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		PS1.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found non objD \n"; }
		if (!results.empty()) {
			if (debug) { cout << "objD result: " << dec << results.size() << "\n"; }
			
			for (DWORD i = 0; i < results.size(); i++) {
				//cout << hex << results[i] + offset1 << "\n";
				DWORD bb1 = VirtPReadDword(results[i] + offset1);
				//cout << hex << bb1 << "\n";
				//DWORD64 bb2 = VirtPRead64(results[i] + offset2);
				//DWORD bb3 = VirtPReadDword(results[i] + offset3);
				//	BYTE bb4 = VirtPReadByte(results[i] + offset4);

				if ((bb1 == value1)) {
					results2.push_back(results[i]);
				}
			}
			//2nd/there should be only 1 match
			if (!results2.empty()) {
				cout << "objD result2s: " << dec << results2.size() << "\n";
				cout << "objD result2: " << hex << results2[0] << "\n";
				return results2[0];
			}
			else { cout << "Failed to find objD match" << "/n"; }
		}
	}
	return 0;
}

//tryies to find ground items array beginning
DWORD64 ScanGround()
{
	
	vector<DWORD64> results;
	vector<DWORD64> results2;
	vector<DWORD64> results3;
	vector<DWORD64> results4;
	MEMss BlockA;

	//inv item
	DWORD offset1 = 0x2a;
	DWORD64 value1 = 0x00000000000003FF;
	DWORD64 value12 = 0x00000000000001FF;
	DWORD offset2 = 0x42;
	DWORD64 value2 = 0x0000000100000000;
	DWORD offset31 = 0x70;
	DWORD64 value31 = 0x1101;
	DWORD offset32 = 0x62;
	DWORD64 value32 = 0x0;

	DWORD64 value3 = 0x0;
	DWORD offset3 = 0x49;
	DWORD offset4 = 0x51;
	DWORD offset5 = 0xB020;
	DWORD value5 = 0x09;

    DWORD offset6 = 0xb9;
	DWORD offset7 = 0xf9;
	DWORD offset8 = 0x101;
	DWORD offset9 = 0x139;
	DWORD offset10 = 0x141;
	DWORD offset11 = 0x161;
	DWORD offset12 = 0x169;
	DWORD offset13 = 0x1a9;
	DWORD offset14 = 0x1b1;
	//
	DWORD offset15 = 0x11;
	DWORD offset20 = 0x21;
	DWORD offset18 = 0x59;
	DWORD offset19 = 0x61;
	///inv item//01 01 EE FF EE FF 02 00 00 00 18 00
	PatternSearch PS1{
		0x01, 0x01, 0xee, 0xff, 0xee, 0xff
	};
	//looks for second match inside allready found array
	//50? 58?
	PatternSearch PS2{
		0x09,0xcc,0x01
	};

	//cout << "Lookin for Grounditems \n";
	if (!procIDs.empty())
	{
		//there should be only 1 match
		PS1.SearchRemoteWhole(proc, 0, 0, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty() && LocalPlayer != NULL) {
			if (debug) { cout << "Grounditems result: " << dec << results.size() << "\n"; }

			for (DWORD i = 0; i < results.size(); i++) {

				//DWORD64 bb1 = VirtPRead64(results[i] + offset1);
				DWORD64 bb2 = VirtPRead64(results[i] + offset2);
				WORD bb3 = VirtPReadWord(results[i] + offset31);
				DWORD64 bb4 = VirtPRead64(results[i] + offset32);

				if (bb2 == value2&&bb3 == value31&&bb4 == value32) {
					results2.push_back(results[i]);
				}
			}
			//2nd/there should be only 1 match
			if (!results2.empty()) {
				cout << "Grounditems result2: " << dec << results2.size() << "\n";
				//BlockA = DeterMemoryBlockLenght(0x1C69632D770);
				//cout << hex << BlockA.start << "\n";
				//BlockA = DeterMemoryBlockLenght(results2[0]);
				//cout << hex << BlockA.start << "\n";
				for (DWORD i = 0; i < results2.size(); i++) {
				    BlockA = DeterMemoryBlockLenght(results2[i]);
					cout << hex << BlockA.start << "\n";
					if (!results3.empty()) { results3.clear(); }
		PS2.SearchRemote(proc,0xcc, BlockA.start, BlockA.size, results3);
				//PS2.SearchRemoteEx(proc, BlockA.start, BlockA.start + BlockA.size, results3);
				if (!results3.empty()) {
					cout << "Grounditems result3: " << dec << results3.size() << "\n";
					//cout << "adr: " << hex << results3[0] << "\n";
					for (DWORD i = 0; i < results3.size(); i++) {
						DWORD64 bb5 = VirtPRead64(results3[i] + offset3);
						DWORD64 bb6 = VirtPRead64(results3[i] + offset4);
						BYTE bb7 = VirtPReadByte(results3[i] + offset5);
					//	DWORD64 bb8 = VirtPRead64(results3[i] + offset6);
						DWORD64 bb9 = VirtPRead64(results3[i] + offset7);
						DWORD64 bb10 = VirtPRead64(results3[i] + offset8);
					//	DWORD64 bb11 = VirtPRead64(results3[i] + offset9);
					//	DWORD64 bb12 = VirtPRead64(results3[i] + offset10);
					//	DWORD64 bb13 = VirtPRead64(results3[i] + offset11);
					//	DWORD64 bb14 = VirtPRead64(results3[i] + offset12);
					//	DWORD64 bb15 = VirtPRead64(results3[i] + offset13);
					//	DWORD64 bb16 = VirtPRead64(results3[i] + offset14);
						DWORD64 bb17 = VirtPRead64(results3[i] + offset15);
					//	DWORD64 bb20 = VirtPRead64(results3[i] + offset18);
					//	DWORD64 bb21 = VirtPRead64(results3[i] + offset19);
						DWORD64 bb22 = VirtPRead64(results3[i] + offset20);

						if ((bb5 == value3 && bb6 == value3 && bb9 == value3 && bb10 == value3 && bb7 == value5
							) && (bb17 > 0 && bb22 > 0)) {
							cout << "Match! " << "\n";
							results4.push_back(results3[i]);
						}
					}

				}
			}
		}
			if (!results4.empty()) { return results4[0]; }
			else { cout << "Failed to find grounditems match" << "/"; }
		}
	}
	return 0 ;
}

//tryies to find interfaces//box sizes
DWORD64 ScanInteraceArray(){

	vector<DWORD64> results;
	vector<DWORD64> results2;
	MEMss BlockA;

	//inv item
	//DWORD offset1 = 0x2c;
	//DWORD value1 = 0x04000000;


	//inventory box
	PatternSearch PS1{
		0xc5, 0x05, 0x0, 0x0, 0x6b, 0x0, 0xff, 0xff,
		0x2c, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0
	};

	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{

		DWORD64 ScanPlaceHolder = ScAdd1;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		PS1.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found no Interface array \n"; }
		if (!results.empty()) {
			if (debug) { cout << "Interf result: " << dec << results.size() << "\n"; }

			for (DWORD i = 0; i < results.size(); i++) {

				//DWORD bb1 = VirtPReadDword(results[i] + offset1);

				//if (bb1 == value1) {
					results2.push_back(results[i]);
				//}
			}
			//2nd/there should be only 1 match
			if (!results2.empty()) {
				cout << "Interf2size: " << dec << results2.size() << "\n";
				cout << "Interf2result: " << hex << results2[0] << "\n";
				BlockA = DeterMemoryBlockLenght(results2[0]);
				cout <<hex<< BlockA.start << "\n";
				return results2[0]-0x30;
			}
			else { cout << "Failed to find Interface array match" << "\n"; }
		}
	}
	return 0;
}

//tryies to find interfaces//inv items array//old
DWORD64 ScanInteraceArray2() {

	vector<DWORD64> results;
	vector<DWORD64> results2;
	MEMss BlockA;

	//inv item
	DWORD offset1 = 0x2c;
	DWORD value1 = 0x04000000;


	//
	PatternSearch PS1{
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0,
		0x0, 0x50, 0x44, 0x0, 0x0, 0x0, 0x0, 0x0
	};

	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{
		DWORD64 ScanPlaceHolder = LocalPlayer;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		PS1.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found no Interface2 array \n"; }
		if (!results.empty()) {
			if (debug) { cout << "Interf2 result: " << dec << results.size() << "\n"; }

			for (DWORD i = 0; i < results.size(); i++) {

				DWORD bb1 = VirtPReadDword(results[i] + offset1);

				if (bb1 == value1) {
					results2.push_back(results[i]);
				}
			}
			//2nd/there should be only 1 match
			if (!results2.empty()) {
				cout << "Interf22size: " << dec << results2.size() << "\n";
				cout << "Interf22result: " << hex << results2[0] << "\n";
				BlockA = DeterMemoryBlockLenght(results2[0]);
				cout << hex << BlockA.start << "\n";
				return results2[0];
			}
			else { cout << "Failed to find Interface2 array match" << "/n"; }
		}
	}
	return 0;
}

//ScanforExe6
//tryies to find projectiles
DWORD64 ScanPro()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	///
	vector<DWORD64> results3;

	//
	//DWORD offset1 = 0x20;
	//DWORD64 value1 = Exe1+ 0xB08;


	PatternSearch PS1{};


	//cout << "Lookin for \n";
	if (!procIDs.empty() && Exe6 != NULL)
	{
		//Lets pick first line in objects
		//w10 +0x7d8
		//w7  0x7C0
		PS1 = Chopbytes64(Exe6 + 0x60);

		DWORD64 ScanPlaceHolder = LocalPlayer;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		PS1.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found non projectiles \n"; }

		if (!results.empty()) {
			if (debug) { cout << "projectiles result: " << dec << results.size() << "\n"; }

			//loop for matches
			for (DWORD i = 0; i < results.size(); i++) {

				//DWORD64 v1 = VirtPRead64(results[i] + offset1);
				//DWORD64 v2 = VirtPRead64(results[i] + offset2);

				//if (v1 == value1) {
				results2.push_back(results[i]);
				//}
			}
		}

		//its seems there is always something written even if spot is empty
		//lets get to the top/block start step by step
		//BlockA = DeterMemoryBlockLenght(results2	[0]);
		/*
		int up = 100; int step = 0x300; int count= 0;
		for (DWORD i = 0; i < up; i++) {
		count = count + step;
		DWORD64 v1 = VirtPRead64(results2[i]);


		}

		for (DWORD i = 0; i < up; i++) {

		}
		}
		*/



		if (!results2.empty()) {
			cout << "projectiles result2s: " << dec << results2.size() << "\n";
			//pick middle one and hope its right
			int mid = results2.size() / 2;
			cout << "projectiles result2: " << hex << results2[mid] << "\n";
			return results2[mid];
		}
		else { cout << "Failed to find projectiles match" << "\n"; return 0; }
	}
	return 0;
}

//dynamic inventory locating
vector<DWORD64> ScanForInvArray()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	//
	vector<DWORD64> results3;
	vector<DWORD64> results4;
	vector<DWORD64> results5;
	vector<DWORD64> BLOCK;
	//
	WORD offset1 = 0x26;
	WORD offset2 = 0x22;
	WORD offset3 = 0xa;
	MEMss BlockA;

	//inventory boxes
	PatternSearch PS1{
		0x00,0x00,0xc1,0x05
	};

	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{

		DWORD64 ScanPlaceHolder = ScAdd1;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		PS1.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found non tempInterf \n"; }

		if (!results.empty()) {
			if (debug) { cout << "tempInterf result: " << dec << results.size() << "\n"; }

			//loop for matches
			for (DWORD i = 0; i < results.size(); i++) {

				//check active
				DWORD v1 = VirtPReadDword(results[i] - offset1);
				DWORD v2 = VirtPReadDword(results[i] - offset2);
				//5 at end
				DWORD v3 = VirtPReadDword(results[i] + offset3);
				    //activ
				if (v1 == 1 && v2 == 1
					&&
					v3 == 5			
					) {
					BlockA = DeterMemoryBlockLenght(results[i]);
					//cout << hex << BlockA.start << endl;
					//cout << hex << BlockA.size << endl;
			    BLOCK.push_back(BlockA.start);
				results2.push_back(results[i]);
				}
			}
		}

		//if (!results2.empty()) {
			//cout << "tempInterf result2s: " << dec << results2.size() << "\n";
			//pick middle one and hope its right
			//int mid = results2.size() / 2;
			//int mid2 = results2.size() /1.2f;
			//int mid3 = results2.size() /3;                      //back to beginning
			//cout << "tempInterf result2: " << hex << (results2[mid])-0x2e << "\n";
			//cout << "tempInterf result3: " << hex << results2[mid2] << "\n";
			//cout << "tempInterf result4: " << hex << results2[mid3] << "\n";
			//results3.push_back(results2[mid] - 0x2e);
			//return{0};
		//}
		//else { cout << "Failed to find tempInterf match" << "\n"; return{0}; }

		if (!BLOCK.empty()) {
			BOOLEAN added=FALSE;
			for (WORD i = 0; i < BLOCK.size(); i++) {
				if (results4.empty()) { results4.push_back(99); added = TRUE; }
				for (WORD i2 = 0; i2 < results4.size(); i2++) {
					if (results4[i2]== BLOCK[i]) {
						break;
					}
					if (i2 < results4.size()) {
						//delete first add
						if (added == TRUE) { results4.erase(results4.begin()); added = FALSE; }
						//for compare
						results4.push_back(BLOCK[i]);
						//for end results
						results5.push_back(results2[i]-0x2e);
					}
				}
			}
		}
		if (!results5.empty()) {
			for (WORD i = 0; i < results5.size(); i++) {
				cout << "tempInterf result4: " << hex << results5[i] << "\n";
			}
			return results5;
		}
	}
	return{0};
}

//dynamic bank locating//slow
vector<DWORD64> ScanForBankArray()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	///
	vector<DWORD64> results3;
	vector<DWORD64> results4;
	//
	BANKArr.clear();
	//
	WORD offset1 = 0x26;
	WORD offset2 = 0x22;
	WORD offset3 = 0xa;
	// item ids
	WORD offset4 = 0x1c2;
	MEMss BlockA;
	DWORD64 ScanPlaceHolder;
	DWORD64 ScanStart;
	DWORD64 ScanEnd;

	PatternSearch PS1{
		0x00,0x00,0xfa,0x02,0x05
	};

	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{



		if (BANKArrPrev == NULL) {
			ScanPlaceHolder = ScAdd1;
			if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
			else {
				ScanStart = ScanPlaceHolder - ScanBack;
			}
			ScanEnd = ScanPlaceHolder + ScanFoward + 0x50000000;
			if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		}
		else {
			ScanPlaceHolder = BANKArrPrev;
			ScanStart = ScanPlaceHolder - 0x50000000;
			ScanEnd = ScanPlaceHolder + 0x50000000;
			if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		}
		
		PS1.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found BANKArr temp \n"; }

		if (!results.empty()) {
			if (debug) { cout << "BANKArr result: " << dec << results.size() << "\n"; }

			//loop for matches
			for (DWORD i = 0; i < results.size(); i++) {

				//check active
				DWORD v1 = VirtPReadDword(results[i] - offset1);
				DWORD v2 = VirtPReadDword(results[i] - offset2);
				WORD v4 = VirtPReadWord(results[i] + (offset3-4));
				//end
				DWORD v5 = VirtPReadDword(results[i] + offset3);
				DWORD v6 = VirtPReadDword(results[i] + offset4);
				//
				if (v1 == 1 && v2 == 1
					//&&
					//v4 == 243
					&&
					v5 == 243
					//&&
					//v6 == 1511
					) {
					//BlockA = DeterMemoryBlockLenght(results[i]);
					//cout << hex << BlockA.start << endl;
					//cout << hex << BlockA.size << endl;

					results2.push_back(results[i]);
				}
			}
		}

		if (!results2.empty()) { 
			for (DWORD i = 0; i < results2.size(); i++) {
				results3.push_back(results2[i]-0x2e);
				i = i + 100;				 	
			}
			BANKArrPrev = results3[results3.size()/2];;


			cout << "BANKArr size: " << dec << results3.size() << "\n";
			for (DWORD i = 0; i < results3.size(); i++) {
				cout << "BANKArr result3s: " << hex << results3[i] << "\n";
			}
			//cout << "temp result4s size: " << dec << results4.size() << "\n";
			//for (DWORD i = 0; i < results4.size(); i++) {
			//	cout << "temp result4s: " << hex << results4[i] << "\n";
		   // }

			return results3;
			//cout << "temp result2s: " << dec << results2.size() << "\n";
			//pick middle one and hope its right
			//int mid = results2.size() / 2;
			//int mid2 = results2.size() /1.2f;
			//int mid3 = results2.size() /3;                      //back to beginning
			//cout << "temp result2: " << hex << (results2[mid]) - 0x2e << "\n";
			//cout << "tempInterf result3: " << hex << results2[mid2] << "\n";
			//cout << "tempInterf result4: " << hex << results2[mid3] << "\n";
			//return results2[mid] - 0x2e;
		}
		else { cout << "Failed to find BANKArr match" << "\n"; return results3; }
	}
	return results3;
}

//dynamic bank inventory locating//slow
vector<DWORD64> ScanForBankIArray()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	///
	vector<DWORD64> results3;
	vector<DWORD64> results4;
	//
	BANKIArr.clear();
	//
	WORD offset1 = 0x26;
	WORD offset2 = 0x22;
	WORD offset3 = 0xa;
	// item ids
	WORD offset4 = 0x1c2;
	MEMss BlockA;
	DWORD64 ScanPlaceHolder;
	DWORD64 ScanStart;
	DWORD64 ScanEnd;

	PatternSearch PS1{
		0x00,0x00,0xfa,0x02,0x05
	};

	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{



		if (BANKIArrPrev == NULL) {
			ScanPlaceHolder = ScAdd1;
			if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
			else {
				ScanStart = ScanPlaceHolder - ScanBack;
			}
			ScanEnd = ScanPlaceHolder + ScanFoward + 0x50000000;
			if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		}
		else {
			ScanPlaceHolder = BANKIArrPrev;
			ScanStart = ScanPlaceHolder - 0x50000000;
			ScanEnd = ScanPlaceHolder + 0x50000000;
			if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		}

		PS1.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found non BANKIArr \n"; }

		if (!results.empty()) {
			if (debug) { cout << "BANKIArr result: " << dec << results.size() << "\n"; }

			//loop for matches
			for (DWORD i = 0; i < results.size(); i++) {

				//check active
				DWORD v1 = VirtPReadDword(results[i] - offset1);
				DWORD v2 = VirtPReadDword(results[i] - offset2);
				WORD v4 = VirtPReadWord(results[i] + (offset3 - 4));
				//end
				DWORD v5 = VirtPReadDword(results[i] + offset3);
				DWORD v6 = VirtPReadDword(results[i] + offset4);
				//
				if (v1 == 1 && v2 == 1
					//&&
					//v4 == 243
					&&
					v5 == 10
					//&&
					//v6 == 1511
					) {
					//BlockA = DeterMemoryBlockLenght(results[i]);
					//cout << hex << BlockA.start << endl;
					//cout << hex << BlockA.size << endl;

					results2.push_back(results[i]);
				}
			}
		}

		if (!results2.empty()) {
			for (DWORD i = 0; i < results2.size(); i++) {
				results3.push_back(results2[i] - 0x2e);
				i = i + 5;
			}
			BANKIArrPrev = results3[results3.size() / 2];;


			cout << "BANKIArr size: " << dec << results3.size() << "\n";
			for (DWORD i = 0; i < results3.size(); i++) {
				cout << "BANKIArr result3s: " << hex << results3[i] << "\n";
			}
			//cout << "temp result4s size: " << dec << results4.size() << "\n";
			//for (DWORD i = 0; i < results4.size(); i++) {
			//	cout << "temp result4s: " << hex << results4[i] << "\n";
			// }

			return results3;
			//cout << "temp result2s: " << dec << results2.size() << "\n";
			//pick middle one and hope its right
			//int mid = results2.size() / 2;
			//int mid2 = results2.size() /1.2f;
			//int mid3 = results2.size() /3;                      //back to beginning
			//cout << "temp result2: " << hex << (results2[mid]) - 0x2e << "\n";
			//cout << "tempInterf result3: " << hex << results2[mid2] << "\n";
			//cout << "tempInterf result4: " << hex << results2[mid3] << "\n";
			//return results2[mid] - 0x2e;
		}
		else { cout << "Failed to find BANKIArr match" << "\n"; return results3; }
	}
	return results3;
}

//dynamic loot window locating//slow
vector<DWORD64> ScanForLootArray()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	///
	vector<DWORD64> results3;
	//vector<DWORD64> results4;
	//
	LOOTArr.clear();
	//
	WORD offset1 = 0x26;
	WORD offset2 = 0x22;
	WORD offset3 = 0xa;
	// item ids
	WORD offset4 = 0x1c2;
	MEMss BlockA;
	DWORD64 ScanPlaceHolder;
	DWORD64 ScanStart;
	DWORD64 ScanEnd;

	PatternSearch PS1{
		0x00,0x00,0x56,0x06,0x05
	};

	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{
		if (LOOTArrPrev == NULL) {
			ScanPlaceHolder = ScAdd1;
			if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
			else {
				ScanStart = ScanPlaceHolder - ScanBack;
			}
			ScanEnd = ScanPlaceHolder + ScanFoward + 0x50000000;
			if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		}
		else {
			ScanPlaceHolder = LOOTArrPrev;
			ScanStart = ScanPlaceHolder - 0x50000000;
			ScanEnd = ScanPlaceHolder + 0x50000000;
			if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		}

		PS1.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found LOOTArr \n"; }

		if (!results.empty()) {
			if (debug) { cout << "LOOTArr result: " << dec << results.size() << "\n"; }

			//loop for matches
			for (DWORD i = 0; i < results.size(); i++) {

				//check active
				DWORD v1 = VirtPReadDword(results[i] - offset1);
				DWORD v2 = VirtPReadDword(results[i] - offset2);
				WORD v4 = VirtPReadWord(results[i] + (offset3 - 4));
				//end
				DWORD v5 = VirtPReadDword(results[i] + offset3);
				DWORD v6 = VirtPReadDword(results[i] + offset4);
				//
				if (v1 == 1 && v2 == 1
					//&&
					//v4 == 243
					&&
					v5 == 10
					//&&
					//v6 == 1511
					) {
					//BlockA = DeterMemoryBlockLenght(results[i]);
					//cout << hex << BlockA.start << endl;
					//cout << hex << BlockA.size << endl;

					results2.push_back(results[i]);
				}
			}
		}

		if (!results2.empty()) {
			for (DWORD i = 0; i < results2.size(); i++) {
				results3.push_back(results2[i] - 0x2e);
				i = i + 5;
			}
			LOOTArrPrev = results3[results3.size() / 2];;


			cout << "LOOTArr size: " << dec << results3.size() << "\n";
			for (DWORD i = 0; i < results3.size(); i++) {
				cout << "LOOTArr result3s: " << hex << results3[i] << "\n";
			}
			//cout << "temp result4s size: " << dec << results4.size() << "\n";
			//for (DWORD i = 0; i < results4.size(); i++) {
			//	cout << "temp result4s: " << hex << results4[i] << "\n";
			// }

			return results3;
			//cout << "temp result2s: " << dec << results2.size() << "\n";
			//pick middle one and hope its right
			//int mid = results2.size() / 2;
			//int mid2 = results2.size() /1.2f;
			//int mid3 = results2.size() /3;                      //back to beginning
			//cout << "temp result2: " << hex << (results2[mid]) - 0x2e << "\n";
			//cout << "tempInterf result3: " << hex << results2[mid2] << "\n";
			//cout << "tempInterf result4: " << hex << results2[mid3] << "\n";
			//return results2[mid] - 0x2e;
		}
		else { cout << "Failed to find LOOTArr match" << "\n"; return results3; }
	}
	return results3;
}

//old
//finds all and adds them to vector array, 100% matches only
//looks for items in interface, possibly
vector<DWORD64> ScanInvI()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	//inv item
	DWORD offset1 = 0x26;
	DWORD value1 = 0x00000001;
	DWORD offset2 = 0xa;
	DWORD value2 = 0x00000005;
	DWORD offset3 = 0x3fc;
	DWORD value3 = 00000001;
	DWORD offset4 = 0x6;
	DWORD value4 = 0x05;
	///inv item
	PatternSearch PS{
		0x00, 0x00, 0xc1, 0x05, 0x05
	};
	MEMss BlockA;


	cout << "Lookin inv item addresses \n";
	if (!procIDs.empty() && IF2 != NULL)
	{
		BlockA = DeterMemoryBlockLenght(IF2);
		cout << "inv aob size: " << BlockA.size << "\n";
		PS.SearchRemoteEx(proc, BlockA.start, BlockA.start + BlockA.size, results);
		if (results.empty()) { cout << "Found non inv aob \n"; }
		if (!results.empty()) {
			if (debug) { cout << "inv aob result: " << dec << results.size() << "\n"; }

			for (DWORD i = 0; i < results.size(); i++) {

				DWORD bb1 = VirtPReadDword(results[i] - offset1);
				DWORD bb2 = VirtPReadDword(results[i] + offset2);
				//DWORD bb3 = VirtPReadDword(results[i] + offset3);
				//	BYTE bb4 = VirtPReadByte(results[i] + offset4);


				if (bb1 == value1 && bb2 == value2) {
					results2.push_back(results[i]);
				}

			}
			return results2;
		}
	}
	//results2.clear();
	return results2;
}

//bankinv test
vector<DWORD64> ScanInvIBank()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	//inv item
	DWORD offset1 = 0x26;
	DWORD value1 = 0x00000001;
	DWORD offset2 = 0xa;
	DWORD value2 = 0x00000005;
	DWORD offset3 = 0x3fc;
	DWORD value3 = 00000001;
	DWORD offset4 = 0x6;
	DWORD value4 = 0x05;
	///inv item
	PatternSearch PS{
		0x00, 0x00, 0xfa, 0x02, 0x05
	};
	MEMss BlockA;

	cout << "Lookin invb item addresses \n";
	if (!procIDs.empty())
	{
		BlockA = DeterMemoryBlockLenght(IF2);
		cout << "invb aob size: " << BlockA.size << "\n";
		PS.SearchRemoteEx(proc, BlockA.start, BlockA.start + BlockA.size, results);
		if (results.empty()) { cout << "Found non invb aob \n"; }
		if (!results.empty()) {
			if (debug) { cout << "invb aob result: " << dec << results.size() << "\n"; }

			for (DWORD i = 0; i < results.size(); i++) {

				//DWORD bb1 = VirtPReadDword(results[i] - offset1);
				//DWORD bb2 = VirtPReadDword(results[i] + offset2);
				//DWORD bb3 = VirtPReadDword(results[i] + offset3);
				//	BYTE bb4 = VirtPReadByte(results[i] + offset4);


				//if (bb1 == value1 && bb2 == value2) {
					results2.push_back(results[i]);
			//	}

			}
			return results2;
		}
	}
	return results2;
}

//finds all and adds them to vector array, 100% matches only
//looks for inverntory interface and its size
vector<DWORD64> ScanInvB(PatternSearch patern, char* TextToSay, vector<DWORD> offset, vector<WORD> byte2, vector<BOOLEAN> UpDown)
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	WORD bb0 = 0;
	WORD bb1 = 0;
	WORD bb2 = 0;
	WORD bb3 = 0;


	cout << "Lookin for addresses \n";
	if (!procIDs.empty())
	{
	
		patern.SearchRemoteWhole(proc, 0, 0, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty() ) {
			if (debug2) { cout << "result: " << dec << results.size() << "\n"; }
			if (offset.empty()) {
				return results;
			}

			for (DWORD i = 0; i < results.size(); i++) {

				if (UpDown[0]) { bb0 = VirtPReadWord(results[i] - offset[0]); }
				else { bb0 = VirtPReadWord(results[i] + offset[0]); }
				if (UpDown[1]) { bb1 = VirtPReadWord(results[i] - offset[1]); }
				else { bb1 = VirtPReadWord(results[i] + offset[1]); }
				if (UpDown[2]) { bb2 = VirtPReadWord(results[i] - offset[2]); }
				else { bb2 = VirtPReadWord(results[i] + offset[2]); }
				if (UpDown[3]) { bb3 = VirtPReadWord(results[i] - offset[3]); }
				else { bb3 = VirtPReadWord(results[i] + offset[3]); }
				//BYTE bb4 = VirtPReadByte(results[i] + 0x6);


				if (bb0 == byte2[0] && bb1 == byte2[1] && bb2 == byte2[2]
					) {
					results2.push_back(results[i]);
				}

			}
			return results2;
		}
	}
	return results2;
}

//Gets interface address slay, ads them to gobal to use as refrence
vector<DWORD64> RefSlrepoints()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	//91
	DWORD offset1 = 0x11;
	//ea
	DWORD offset2 = 0x10;
	//f
	DWORD offset3 = 0x40;
	BYTE byte1 = 0x91;
	DWORD byte2 = 0x000003EA;
	DWORD64 byte3 = 0xFFFFFFFFFFFFFFFF;
	//hp 93 02 00 00
	//slay b7 00 00 00
	PatternSearch ps{
		0xb7, 0x00, 0x00, 0x00
	};


	cout << "Lookin for RefSlrepoints \n";
	if (!procIDs.empty())
	{
		DWORD64 ScanPlaceHolder = LocalPlayer;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		ps.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			if (debug) { cout << "SlresultSL: " << dec << results.size() << "\n"; }

			for (DWORD i = 0; i < results.size(); i++) {

				BYTE bb1 = VirtPReadByte(results[i] - offset1);
				DWORD bb2 = VirtPReadDword(results[i] + offset2);
				DWORD64 bb3 = VirtPRead64(results[i] + offset3);


				if (bb1 == byte1 && bb2 == byte2 && bb3 == byte3
					) {
					//printf("bb1: %I64X\n", bb1);
					results2.push_back(results[i]);
				}
			}
			if (!results2.empty()) {
				if (debug) { cout << "Sl2resultSL: " << dec << results2.size() << "\n"; }
				for (DWORD i = 0; i < results2.size(); i++) {
					cout << "foundSL: " << hex << results2[i] << "\n";;
				}
				SL = results2[0];
				return results2;
			}
		}
	}
	return results2;
}

//Gets interface address adreline, ads them to gobal to use as refrence
vector<DWORD64> RefAdrepoints()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	//91
	DWORD offset1 = 0x11;
	//ea
	DWORD offset2 = 0x10;
	//f
	DWORD offset3 = 0x40;
	BYTE byte1 = 0x91;
	DWORD byte2 = 0x000003EA;
	DWORD64 byte3 = 0xFFFFFFFFFFFFFFFF;
	//hp 93 02 00 00
	//slay b7 00 00 00
	PatternSearch ps{
		0xa7, 0x02, 0x00, 0x00
	};


	cout << "Lookin for RefAdrepoints \n";
	if (!procIDs.empty())
	{
		DWORD64 ScanPlaceHolder = LocalPlayer;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		ps.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			if (debug) { cout << "SlresultAd: " << dec << results.size() << "\n"; }

			for (DWORD i = 0; i < results.size(); i++) {

				BYTE bb1 = VirtPReadByte(results[i] - offset1);
				DWORD bb2 = VirtPReadDword(results[i] + offset2);
				DWORD64 bb3 = VirtPRead64(results[i] + offset3);


				if (bb1 == byte1 && bb2 == byte2 && bb3 == byte3
					) {
					//printf("bb1: %I64X\n", bb1);
					results2.push_back(results[i]);
				}
			}
			if (!results2.empty()) {
				if (debug) { cout << "Sl2resultAd: " << dec << results2.size() << "\n"; }
				for (DWORD i = 0; i < results2.size(); i++) {
					cout << "foundAd: " << hex << results2[i] << "\n";;
				}
				AD = results2[0];
				return results2;
			}
		}
	}
	return results2;
}

//Gets interface address praypoints, ads them to gobal to use as refrence
vector<DWORD64> RefPraypoints()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	//91
	DWORD offset1 = 0x11;
	//ea
	DWORD offset2 = 0x10;
	//f
	DWORD offset3 = 0x40;
	BYTE byte1 = 0x91;
	DWORD byte2 = 0x000003EA;
	DWORD64 byte3 = 0xFFFFFFFFFFFFFFFF;
	//hp 93 02 00 00
	//slay b7 00 00 00
	PatternSearch ps{
		0xca, 0x0c, 0x00, 0x00
	};


	cout << "Lookin for RefPraypoints \n";
	if (!procIDs.empty())
	{

		DWORD64 ScanPlaceHolder = LocalPlayer;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		ps.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			if (debug) { cout << "SlresultPr: " << dec << results.size() << "\n"; }

			for (DWORD i = 0; i < results.size(); i++) {

				BYTE bb1 = VirtPReadByte(results[i] - offset1);
				DWORD bb2 = VirtPReadDword(results[i] + offset2);
				DWORD64 bb3 = VirtPRead64(results[i] + offset3);


				if (bb1 == byte1 && bb2 == byte2 && bb3 == byte3
					) {
					//printf("bb1: %I64X\n", bb1);
					results2.push_back(results[i]);
				}
			}
			if (!results2.empty()) {
				if (debug) { cout << "Sl2resultPr: " << dec << results2.size() << "\n"; }
				for (DWORD i = 0; i < results2.size(); i++) {
					cout << "foundPr: " << hex << results2[i] << "\n";;
				}
				PP = results2[0];
				return results2;
			}
		}
	}
	return results2;
}

//Tryes to find varpbits chunks
VOID RefVarpBits1()
{
	VarBits1.clear();
	VarBits2.clear();
	vector<DWORD64> results;
	//1
	vector<DWORD64> results21;
	vector<DWORD64> firsthit;
	vector<DWORD> countafter;
	vector<DWORD64> filterhit;
	//2
	vector<DWORD64> results22;
	vector<DWORD64> results3base2;
	//

	//FFFFFFFFFFFFFFFFFFFFFFFF
	DWORD64 byte1 = 0xFFFFFFFFFFFFFFFF;
	DWORD byte2 = 0x000003EA;
	DWORD byte22 = 0x000003EF;
	DWORD64 byte3 = 0xFFFFFFFFFFFFFFFE;
	//diffrence size
	DWORD64 distance = 0x20000;

	PatternSearch ps{
		0xea, 0x03, 0x00, 0x00
		//, 0x0, 0x0, 0x0, 0x0
	};


	cout << "Lookin for varbits \n";
	if (CheckRS3)
	{
		DWORD64 ScanPlaceHolder = ScAdd1;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		DWORD64 ScanBack2= 0x500000000;
		DWORD64 ScanFoward2= 0x500000000;

		if (ScanBack2 > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack2;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward2;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }

		//Sleep(30000);
		ps.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "varbits Found non \n"; }
		if (!results.empty()) {
			if (debug) { cout << "varbits: " << dec << results.size() << "\n"; }

			for (DWORD i1 = 0; i1 < results.size(); i1++) {

				BYTE bb = VirtPReadByte(results[i1] - 0x21);
				//thers seems to be double 64 and 32 bit?
				 //DWORD64 bb2 = VirtPRead64(results[i] - 0x20);
				 //DWORD bb3 = VirtPReadDword(results[i] + 0x24);
				 //ea check 58 and 80
				 //bools?
				 //stats?
				BYTE bb11 = VirtPReadByte(results[i1] - 0xa1);
				DWORD ea11 = VirtPReadDword(results[i1] - 0x80);
				BYTE bb21 = VirtPReadByte(results[i1] + 0x59);
				DWORD ea21 = VirtPReadDword(results[i1] + 0x80);
				DWORD ea31 = VirtPReadDword(results[i1] - 0x100);
				DWORD ea41 = VirtPReadDword(results[i1] + 0x100);
				DWORD ea51 = VirtPReadDword(results[i1] - 0x180);
				DWORD ea61 = VirtPReadDword(results[i1] + 0x180);
				DWORD ea71 = VirtPReadDword(results[i1] - 0x200);
				DWORD ea81 = VirtPReadDword(results[i1] + 0x200);
				DWORD ea91 = VirtPReadDword(results[i1] - 0x280);
				DWORD ea101 = VirtPReadDword(results[i1] + 0x280);
				DWORD id = VirtPReadDword(results[i1] - 0x10);


				DWORD ea12 = VirtPReadDword(results[i1] - 0x58);
				DWORD ea22 = VirtPReadDword(results[i1] + 0x58);
				DWORD ea32 = VirtPReadDword(results[i1] - 0xb0);
				DWORD ea42 = VirtPReadDword(results[i1] + 0xb0);
				DWORD ea52 = VirtPReadDword(results[i1] - 0x108);
				DWORD ea62 = VirtPReadDword(results[i1] + 0x108);
				DWORD ea72 = VirtPReadDword(results[i1] - 0x160);
				DWORD ea82 = VirtPReadDword(results[i1] + 0x160);
				DWORD ea92 = VirtPReadDword(results[i1] - 0x160);
				DWORD ea102 = VirtPReadDword(results[i1] + 0x160);
				//
				DWORD64 test1 = VirtPRead64(results[i1] - 0x18);
				DWORD64 test2 = VirtPRead64(results[i1] - 0x20);
				DWORD64 test3= VirtPRead64(results[i1] - 0x28);
				DWORD64 test4 = VirtPRead64(results[i1] - 0x30);


				//80 size//1// booleans
				if (
					//bb == 0x91 && bb11 == 0x91 && bb21 == 0x91
					//&& 
					//smithin
					//id == 1247
					//craftin
					//id==1251
					//&& 
					(ea11 == byte2 || ea11 == byte22)&&
					(ea21 == byte2 || ea21 == byte22)&&
					(ea31 == byte2 || ea31 == byte22) &&
					(ea41 == byte2 || ea41 == byte22) &&
					(ea51 == byte2 || ea51 == byte22) &&
					(ea61 == byte2 || ea61 == byte22) &&
					(ea71 == byte2 || ea71 == byte22) &&
					(ea81 == byte2 || ea81 == byte22) &&
					(ea91 == byte2 || ea91 == byte22) &&
					(ea101 == byte2 || ea101 == byte22)
					) {
					results21.push_back(results[i1]);
					//DWORD id = VirtPReadDword(results[i] - 0x10);
					//results2id1.push_back(id);

				}
				//58 size//2 looks like stats mostly/xp
			    if (
					ea12 == byte2
					&& ea22 == byte2
					&& ea32 == byte2 && ea42 == byte2
					&& ea52 == byte2 && ea62 == byte2
					&& ea72 == byte2 && ea82 == byte2
					&& ea92 == byte2 && ea102 == byte2
					//&& 
					//test1==0
					//&& test2==0xFFFFFFFFFFFFFFFF
					//&& test3==0
					//&& test4==0xFFFFFFFF00000001
					//&& id== 3274
					) {
					//cout << hex << results[i] << endl;
					results22.push_back(results[i1]);
					//DWORD id = VirtPReadDword(results[i] - 0x10);
					//results2id2.push_back(id);
				}
			}
		}


			//1           
			//get density
			if (!results21.empty()) {
				DWORD64 hold = 0;
				DWORD counter = 0;
				DWORD blocksize = 0x30000;
				BYTE overthis = 10;
				for (DWORD i2 = 0; i2 < results21.size(); i2++) {					
					if (hold == 0) { hold = results21[i2]; };
					if ((results21[i2] - hold) < blocksize) {
						counter = counter + 1;
					}else{
						//first hit
						firsthit.push_back(hold);
						//amount of hits
						countafter.push_back(counter);
						hold = 0;
    					counter = 0;
					}
				}

				if (!firsthit.empty()) {
					if (debug) { cout << "by density: " << dec << firsthit.size() << "\n"; }
					for (DWORD i3 = 0; i3 < firsthit.size(); i3++) {
						cout << "first1:" << hex << firsthit[i3] <<" count:"<<dec<< countafter[i3] << "\n";
						if (countafter[i3]>overthis) {
							filterhit.push_back(firsthit[i3]);
						}
					}
				}
				if (!filterhit.empty()) {
					VarBits1 = filterhit;
				}
			}

			//2
			if (!results22.empty()) {
				DWORD64 hold = 0;
				DWORD counter = 0;
				DWORD blocksize = 0x30000;
				BYTE overthis = 10;
				firsthit.clear();
				countafter.clear();
				filterhit.clear();
				for (DWORD i2 = 0; i2 < results22.size(); i2++) {
					if (hold == 0) { hold = results22[i2]; };
					if ((results22[i2] - hold) < blocksize) {
						counter = counter + 1;
					}
					else {
						//first hit
						firsthit.push_back(hold);
						//amount of hits
						countafter.push_back(counter);
						hold = 0;
						counter = 0;
					}
				}

				if (!firsthit.empty()) {
					if (debug) { cout << "by density2: " << dec << firsthit.size() << "\n"; }
					for (DWORD i3 = 0; i3 < firsthit.size(); i3++) {
						cout << "first2:" << hex << firsthit[i3] << " count2:" << dec << countafter[i3] << "\n";
						if (countafter[i3]>overthis) {
							filterhit.push_back(firsthit[i3]);
						}
					}
				}
				if (!filterhit.empty()) {
					VarBits2 = filterhit;
				}
			}
	}
}

//interf test, returns matched memory spot
//uses player hp as pointing spot
DWORD64  GetInterFInfo(DWORD x){

	vector<DWORD64> results;
	vector<DWORD64> results2;
	vector<DWORD64> results3;
	//91
	DWORD offset1 = 0x11;
	BYTE byte1 = 0x91;



	//cout << "lookin inerface data \n";
	if (!procIDs.empty())
	{
			if (HP!=NULL) {
				//tries to read up all interfaces
				DWORD64 dw2 =HP-0x80*100;

				for (DWORD i = 0; i < 201; i++) {
					dw2 =dw2+0x80;
							  BYTE bb1 = VirtPReadByte(dw2 - offset1);
							  DWORD bb = VirtPReadDword(dw2);
							  



							  if (bb == x) {
								 printf("bb1: %I64X\n", dw2);
								 // WORD bb2 = VirtPReadDword(dw2 + 0x30);
								 // results2.push_back(dw2 + 0x30);
								 // results3.push_back(bb2);

								  return dw2;
							  }
				}
				//if (!resss.empty()) {
				///	for (DWORD i = 0; i < results3.size(); i++) {
				//		if (resss[i] != results3[i]) {
				//			printf("bb1: %I64X\n", results2[i]);
				//		}}}



				//resss.clear();
				//resss = results3;
			}		
	}
	return 0 ;
}

WORD GetSlay() {

	
	if (SL != NULL) {

		WORD bb2 = VirtPReadDword(SL + 0x30);
		if (bb2 > 1000) { bb2 = 0; }
		if (bb2 != NULL) {
			return bb2;
		}
	}
	return 0;
}

WORD GetHP_(){

	WORD placeh = 659;
	if (LocalPlayer != NULL) {
		if (HPBit == NULL) {
			HPBit = FindVarBit(placeh).addr;

		}
		else {
			//re-used
			VB p = ReadBits(HPBit);
			if (p.addr == placeh) {
				//for some reasons its double
				return (p.state & 0x0000ffff)/2;
			}
			else {
				HPBit = 0;
			}
		}
	}
	return 0;
}

WORD GetHPMax_() {

	WORD placeh = 659;
	if (LocalPlayer != NULL) {
		if (HPBit == NULL) {
			HPBit = FindVarBit(placeh).addr;

		}
		else {
			//re-used
			VB p = ReadBits(HPBit);
			if (p.addr == placeh) {
				//some reason not 2x
				return (p.state >> 16);
			}
			else {
				HPBit = 0;
			}
		}
	}
	return 0;
}

WORD GetAdr_() {

	if (AD != NULL) {

		WORD bb2 = VirtPReadDword(AD + 0x30);
		WORD p = bb2;
		if (p > 1100) { p = 0; }
		if (p != NULL) {
			return p;
		}
	}
	return 0;
}

WORD GetPray_() {

	WORD placeh= 3274; 
	if (LocalPlayer != NULL) {
		if (PrayBit == NULL) {
			PrayBit = FindVarBit(placeh).addr;

		}
		else {
			//re-used
			VB p = ReadBits(PrayBit);
			if (p.addr == placeh) {
				//for some reason its 100x//got bored
				return ((p.state <<16)>>16);
			}
			else {
				PrayBit = 0;
			}
		}
	}
	return 0;
}

WORD GetPrayMax_() {

	WORD placeh = 3274;
	if (LocalPlayer != NULL) {
		if (PrayBit == NULL) {
			PrayBit = FindVarBit(placeh).addr;

		}
		else {
			//re-used
			VB p = ReadBits(PrayBit);
			if (p.addr == placeh) {
				return (p.state >>16)*100;
			}
			else {
				PrayBit = 0;
			}
		}
	}
	return 0;
}

WORD GetBitsValue1(WORD bit) {
	if (LocalPlayer != NULL) {
		if (TempBit == NULL) {
			TempBit = FindVarBit(bit).addr;

		}
		else {
			//re-used
			VB p = ReadBits(TempBit);
			if (p.addr == bit) {
				return p.state & 0x0000ffff;
			}
			else {
				TempBit = 0;
			}
		}
	}
	return 0;
}

//for boolean
VOID GetBits(WORD bits) {
	bitset<32> p = bitset<32>(FindVarBit(bits).state);

	for (int i = 0; i < 32; i++) {
		cout << p[i];
	}
	cout << " " << endl;
	//return 0;
}


//scan for elite cluescan bytes
vector<DWORD64> ScanEliteS(PatternSearch patern, DWORD64 start, DWORD64 range, char* TextToSay, vector<DWORD> offset, vector<WORD> byte2)
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	WORD bb0 = 0;
	WORD bb1 = 0;
	WORD bb2 = 0;
	WORD bb3 = 0;


	cout << "Lookin for addresses \n";
	if (!procIDs.empty())
	{
		patern.SearchRemoteEx(proc, start, range, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty() && LocalPlayer != NULL) {
			if (debug2) { cout << "result: " << dec << results.size() << "\n"; }
			if (offset.empty()) {
				return results;
			}

			for (DWORD i = 0; i < results.size(); i++) {

				bb0 = VirtPReadWord(results[i] + offset[0]);



				if (bb0 == byte2[0]
					) {
					results2.push_back(results[i]);
				}

			}
			return results2;
		}
	}
	return results2;
}

FFPOINT EliteCScan(){

	vector<DWORD64> results;
vector<DWORD> offset1 = { 0x38 };
vector<WORD> bytes1 = { 0x0001 };
vector<BOOLEAN> UPDOWN1 = { false };
//x off
DWORD offx = 0xac;
//y off
DWORD offy = 0xb4;

PatternSearch PS99{
	0x0d, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
	0xff, 0xff, 0xff, 0xff, 0x06, 0x06, 0x00, 0x00
};
if (EliteResult.x==NULL) {
	results = ScanEliteS(PS99, LocalPlayer - 0x80000000, LocalPlayer + 0x80000000, "EliteScan: ", offset1, bytes1);
	if (!results.empty()) {
		if (debug) { cout << "found elite loc in memmory" << hex << results[0]; }
		
		FLOAT bbx = VirtPReadFloat(results[0] + offx);
		FLOAT bby = VirtPReadFloat(results[0] + offy);
		EliteResult = { (bbx - 256.f) / 512.f,(bby - 256.f) / 512.f };

		return{ (bbx - 256.f)/512.f,(bby - 256.f)/512.f };
	}
}
return{ 0,0 };
}

POINT ScanCompare(DWORD64 inpatern,DWORD64 start, DWORD64 range)
{
	typedef struct {
		vector<INT> ValueCounter;
		vector<DWORD64> list;
	} test;
	test values;
	PatternSearch patern = Chopbytes64(inpatern);
	POINT point;
	DWORD64 offset1 = 0x38;
	DWORD64 offset2 = 0x40;
	//vector<INT> ValueCounter;
	vector<DWORD64> addr;
	INT min = 100;
	INT max = 0;
	INT bb5 = 0;
	INT bb6 = 0;
	
	cout << "Lookin for addresses \n";
	if (!procIDs.empty())
	{
		patern.SearchRemoteEx(proc, start, range, addr);
		if (addr.empty()) { cout << "Found non \n"; }
		if (!addr.empty()) {
			cout << addr.size()<<dec;
			for (DWORD i = 0; i < addr.size(); i++) {

				DWORD bb1 = VirtPReadDword(addr[i] + offset1);
				//printf("MyLocX: %I64X\n", MyLocX);
				//printf("MyLocY: %I64X\n", MyLocY);
				//printf("Read1b1: %I64X\n", bb1);
				DWORD bb2 = VirtPReadDword(addr[i] + offset2);
				//printf("Read1b2: %I64X\n", bb2);
				//if (MyLocX == bb1) { cout << "99!!!!!!!!!!!!!!" << dec << "\n"; }

					INT bb8 = CRL(bb1) - ReadCoordX3();
					INT bb9 = CRL(bb2) - ReadCoordY3();
					//printf("d1: %d\n", ReadCoordX2());
					//printf("d2: %d\n", ReadCoordY2());
					if (CheckVisibleLimit(bb8, bb9)) {
						bb5 = bb8 += bb9;
						if (bb5<min) {
							min = bb5;
						}
				       values.list.push_back(addr[i]);
					   values.ValueCounter.push_back(bb5);
						cout << "Found!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n";
						//printf("results[i]: %I64X\n", addr[i]);
					}				
			}
				for (DWORD ii = 0; ii <   values.ValueCounter.size(); ii++) {
					if (values.ValueCounter[ii] == min) {
							cout << "Found " << hex << values.ValueCounter[ii] << ":" << hex << values.list[ii] << " : " << "Closest item" << "\n";
							point.x = CRL(VirtPReadDword(values.list[ii] + offset1));
							point.y = CRL(VirtPReadDword(values.list[ii] + offset2));
							 printf("ItemLoc.X: %d\n", point.x);
							 printf("ItemLoc.Y: %d\n", point.y);
							return point;
						}}
		}
	}
	return{ 0,0 };
}


POINT ScanCompareMCoord(DWORD64 inpatern, DWORD64 inpatern2, DWORD64 start, DWORD64 range)
{
	typedef struct {
		vector<INT> ValueCounter;
		vector<DWORD64> list;
	} test;
	test values;
	PatternSearch patern = Chopbytes32(inpatern);
	POINT point;
	DWORD64 offset1 = 0x38;
	DWORD64 offset2 = 0x40;
	DWORD64 offset3 = 0x8;
	//vector<INT> ValueCounter;
	vector<DWORD64> addr;
	INT min = 100;
	INT max = 0;
	INT bb5 = 0;
	INT bb6 = 0;

	cout << "Lookin for addresses \n";
	if (!procIDs.empty())
	{
		patern.SearchRemoteEx(proc, start, range, addr);
		if (addr.empty()) { cout << "Found non \n"; }
		if (!addr.empty()) {
			cout << addr.size() << dec;
			for (DWORD i = 0; i < addr.size(); i++) {
				DWORD bb3 = VirtPReadDword(addr[i] + offset3);
				printf("Read1b1: %I64X\n", bb3);
				if (bb3 == inpatern2) {
					DWORD bb1 = VirtPReadDword(addr[i] + offset1);
					//printf("MyLocX: %I64X\n", MyLocX);
					//printf("MyLocY: %I64X\n", MyLocY);
					printf("Read1b1: %I64X\n", bb1);
					DWORD bb2 = VirtPReadDword(addr[i] + offset2);
					printf("Read1b2: %I64X\n", bb2);
					//if (MyLocX == bb1) { cout << "99!!!!!!!!!!!!!!" << dec << "\n"; }

					INT bb8 = CRL(bb1) - ReadCoordX3();
					INT bb9 = CRL(bb2) - ReadCoordY3();
					//printf("d1: %d\n", ReadCoordX2());
					//printf("d2: %d\n", ReadCoordY2());
					if (CheckVisibleLimit(bb8, bb9)) {
						bb5 = bb8 + bb9;
						if (bb5 < min) {
							min = bb5;
						}
						values.list.push_back(addr[i]);
						values.ValueCounter.push_back(bb5);
						cout << "Found!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n";
						//printf("results[i]: %I64X\n", addr[i]);
					}
				}
			}
			for (DWORD ii = 0; ii < values.ValueCounter.size(); ii++) {
				if (values.ValueCounter[ii] == min) {
					cout << "Found " << hex << values.ValueCounter[ii] << ":" << hex << values.list[ii] << " : " << "Closest item" << "\n";
					point.x = CRL(VirtPReadDword(values.list[ii] + offset1));
					point.y = CRL(VirtPReadDword(values.list[ii] + offset2));
					//printf("ItemLoc.X: %d\n", point.x);
					//printf("ItemLoc.Y: %d\n", point.y);
					//printf("TileToMouse(point): %d\n", TileToMouse(point));
					return{ 0 };
				}
			}
		}
	}
	return{ 0,0 };
}

FFPOINT GetInterfaceStart(DWORD64 addrs) {

	if (addrs != NULL)
	{
		DWORD off1 = 0x282;
		DWORD off2 = 0x286;

		FLOAT Read1 = VirtPReadWord(addrs + off1);
		FLOAT Read2 = VirtPReadWord(addrs + off2);

		if (Read1 != NULL && Read2 != NULL)
		{
			FFPOINT p;
			p.x = Read1;
			p.y = Read2;
			return p;
		}

	}
	return{ 0.f,0.f };
}
FFPOINT GetInterfaceSize(DWORD64 addrs) {

	if (addrs != NULL)
	{
		DWORD off1 = 0x28a;
		DWORD off2 = 0x28e;

		FLOAT Read1 = VirtPReadWord(addrs + off1);
		FLOAT Read2 = VirtPReadWord(addrs + off2);

		if (Read1 != NULL && Read2 != NULL)
		{
			FFPOINT p;
			p.x = Read1;
			p.y = Read2;
			return p;
		}

	}
	return{ 0.f,0.f };
}
BOOLEAN GetInterfaceOpen(DWORD64 addrs) {

	if (addrs != NULL)
	{
		DWORD off1 = 0x3Bb;
		//DWORD off2 = 0;

		BYTE Read1 = VirtPReadByte(addrs + off1);

		if (Read1 == 0)
		{
			return TRUE;
		}
		else {
			return FALSE;
		}
	}
	return FALSE;
}
BOOLEAN GetInterfaceMHover(DWORD64 addrs) {

	if (addrs != NULL)
	{
		DWORD off1 = 0x3Ba;
		//DWORD off2 = 0;

		BYTE Read1 = VirtPReadByte(addrs + off1);

		if (Read1 == 1)
		{
			return TRUE;
		}
		else {
			return FALSE;
		}
	}
	return FALSE;
}

//Check if given interface is still active and there
BOOLEAN InterfCheck(DWORD64 mem1, WORD id, WORD id2, WORD id3, WORD id4)
{
	if (mem1 == NULL) {
		cout << "ZeroInterf" << endl;
		return FALSE;
	}
	else {
		//active check
		DWORD bb3 = VirtPReadDword(mem1 + Ioff555);
		DWORD bb4 = VirtPReadDword(mem1 + Ioff666);
		//ids
		WORD bb5 = VirtPReadWord(mem1 + Ioff55);
		WORD bb7 = VirtPReadWord(mem1 + Ioff55 + 4);
		WORD bb8 = VirtPReadWord(mem1 + Ioff55 + 6);
		WORD bb9 = VirtPReadWord(mem1 + Ioff55 + 8);
		//check if interface is still in same place
		if ((bb3 > 0 && bb3 < 4) && (bb4 > 0 && bb4 < 3) && (bb5 == id && bb7 == id2 && bb8 == id3 && bb9 == id4)) {
			return TRUE;
		}
		return FALSE;
	}
	return FALSE;
}

//Check if given interface2 is still active and there
BOOLEAN InterfCheck2(DWORD64 mem1, WORD id, WORD id2, WORD id3, WORD id4)
{
	if (mem1 == NULL) {
		cout << "ZeroInterf2" << endl;
		return FALSE;
	}
	else {
		//active check
		DWORD bb3 = VirtPReadDword(mem1 + I2off555);
		DWORD bb4 = VirtPReadDword(mem1 + I2off666);
		//ids
		WORD bb5 = VirtPReadWord(mem1 + I2off55);
		WORD bb7 = VirtPReadWord(mem1 + I2off55 + 4);
		WORD bb8 = VirtPReadWord(mem1 + I2off55 + 6);
		WORD bb9 = VirtPReadWord(mem1 + I2off55 + 8);
		//check if interface is still in same place
		if ((bb3 > 0 && bb3 < 4) && (bb4 > 0 && bb4 < 3) && (bb5 == id && bb7 == id2 && bb8 == id3 && bb9 == id4)) {
			return TRUE;
		}
		return FALSE;
	}
	return FALSE;
}

//finds interface match in ReadInterf() and returns memory location
DWORD64 Locateinterface(WORD id, WORD id2, WORD id3, WORD id4) {
	ReadInterf();
	if (!InterfID.empty()) {
		cout <<"Total intefaces amount:"<<dec << InterfID.size() << "\n";
		for (DWORD i = 0; i < InterfID.size(); i++) {
			//filter
			if (InterfID[i] == id && InterfID2[i] == id2 && InterfID3[i] == id3 && InterfID4[i] == id4) {
				//cout <<"Inteface loc:"<<hex << InterfMem[i] << "\n";
				return InterfMem[i];
			}
		}
	}
	return 0;
}

//finds interface match in ReadInterf2() and returns memory location
DWORD64 Locateinterface2(WORD id, WORD id2, WORD id3, WORD id4) {
	ReadInterf2();
	if (!InterfID12.empty()) {
		cout << "Total intefaces amount2:" << dec << InterfID12.size() << "\n";
		for (DWORD i = 0; i < InterfID12.size(); i++) {
			//filter
			if (InterfID[i] == id && InterfID2[i] == id2 && InterfID3[i] == id3 && InterfID4[i] == id4) {
				//cout <<"Inteface loc:"<<hex << InterfMem[i] << "\n";
				return InterfMem2[i];
			}
		}
	}
	return 0;
}

//its far too slow to loop trough all interface data constantly
//reads given address for interface size and stuff
InterfaceComp GetInterfaceData(DWORD64 mem) {
	InterfaceComp p;
	if (mem>0) {
		//they are full numbers(pixels)?// just to be fancy
				p.xy = { (FLOAT)VirtPReadWord(mem + Ioff11), (FLOAT)VirtPReadWord(mem + Ioff22) };
				p.xys = { (FLOAT)VirtPReadWord(mem + Ioff332), (FLOAT)VirtPReadWord(mem + Ioff442) };
				p.h = VirtPReadByte(mem + Ioffhhh);
				p.a = VirtPReadByte(mem + Ioffhhh+1);
				return p;
	}
	p.xy = {0,0};
	p.xys = {0,0};
	p.h=0;
	p.a=0;
	return p;
}

//reads box corners as WORD size
InterfaceComp2 GetInterfaceData2(DWORD64 mem) {
	InterfaceComp2 p;
	if (mem > 0) {
		//(pixels)
		//cout << hex << "GID2:" << mem << endl;
		p.xy = { VirtPReadWord(mem + Ioff11), VirtPReadWord(mem + Ioff22) };
		p.xys = { VirtPReadWord(mem + Ioff33) , VirtPReadWord(mem + Ioff44) };
		p.h = VirtPReadByte(mem + Ioffhhh);
		p.a = VirtPReadByte(mem + Ioffhhh + 1);
		return p;
	}
	//p.xy = { 0,0 };
	//p.xys = { 0,0 };
	//p.h = 0;
	//p.a = 0;
	return p;
}

//stuff//
FFPOINT ToMapFFPOINTExperiment1(FFPOINT ItemCoord) {
	FLOAT dx=40;
	FLOAT dy=35;
	FLOAT sx;
	FLOAT sy;
	FLOAT cosAngle = ((VirtPReadFloatAll(Compass + 0x88)));
	FLOAT sinAngle = ((VirtPReadFloatAll(Compass + 0x8c)));
	cosAngle = cosAngle-1.f;

			sx = (dx + ((cosAngle * dx) - (sinAngle * dy)))+835;
			sy = (dy + ((sinAngle * dx) + (cosAngle * dy)))+144;

	return{ sx,sy };
}

//tiles to map
FFPOINT ToMapFFPOINT(FFPOINT ItemCoord){
	FFPOINT pl= PlayerCoordFloatRaw();
	FFPOINT center;
	FFPOINT endcalc;
	InterfaceComp p;
	FLOAT sx,sy;
	FLOAT cosAngle, sinAngle;

	if (ItemCoord.x > 0 && ItemCoord.y > 0 && pl.x > 0 && pl.y > 0 && Compass>0) {
		if (InterfCheck(MapBoxMemoryLoc, 1477, 87, 0xffff, 44)) {
				//cout << "find1" << "\n";
				p = GetInterfaceData(MapBoxMemoryLoc);
				if (p.xys.x > 0 && p.xys.y > 0) {
					
					                                        //correction for my mess
					cosAngle = ((VirtPReadFloatAll(Compass + 0x88))-1.f);
					//cosAngle = (cosAngle+((VirtPReadFloatAll(Compass + 0x88)) - 1.f))/2;
					                                        //reverse
					sinAngle = ((VirtPReadFloatAll(Compass + 0x8c)))*-1.f;
					//sinAngle = (sinAngle+((VirtPReadFloatAll(Compass + 0x8c)))*-1.f)/2;

					FLOAT x = (p.xy.x + p.xys.x / 2.f) - 0.65f;
					FLOAT y = (p.xy.y + p.xys.y / 2.f) + 5.3f;
					center = { x,y };

					FLOAT xx = (pl.x - ItemCoord.x);
					FLOAT yy = (pl.y - ItemCoord.y);

					endcalc.x = ( xx* 0.00791f);
					endcalc.y = ( yy* 0.00791f);

					sx = center.x - (endcalc.x + ((cosAngle * endcalc.x) - (sinAngle * endcalc.y)));
					sy = center.y + (endcalc.y + ((sinAngle * endcalc.x) + (cosAngle * endcalc.y)));

					return{ sx,sy };
				}
			}
		else {
			cout << "MapBox" << endl;
			MapBoxMemoryLoc = Locateinterface(1477, 87, 0xffff, 44);
		}
	}
	return{ 0.f,0.f };
}

//tiles to client map
WPOINT ToMapFFPOINT2(FFPOINT ItemCoord) {
	FFPOINT pl = PlayerCoordFloatRaw();
	FFPOINT center;
	FFPOINT endcalc;
	InterfaceComp p;

	//cout << "find0" << "\n";
	//inventory box

	if (ItemCoord.x != NULL) {
		if (InterfCheck(MapBoxMemoryLoc, 1477, 87, 0xffff, 44)) {
			//cout << "find1" << "\n";
			p = GetInterfaceData(MapBoxMemoryLoc);
			if (p.xys.x > 0 && p.xys.y > 0) {

				//added some maybe it gets better
					FLOAT x = (p.xy.x + p.xys.x / 2.f) + 6.f;
					FLOAT y = (p.xy.y + p.xys.y / 2.f) + 12.f;
					center = { x,y };
								
				FLOAT xx = (pl.x - ItemCoord.x);
				FLOAT yy = (pl.y - ItemCoord.y);

				endcalc.x = (center.x - xx* 0.0079f);
				endcalc.y = (center.y + yy* 0.0079f);

				QWPOINT rs = GetRSCorners();
				endcalc.x= endcalc.x + (FLOAT)rs.left;
				endcalc.y= endcalc.y + (FLOAT)rs.top;

				return{ (WORD)endcalc.x, (WORD)endcalc.y };
			}
		}
		else {
			cout << "MapBox" << endl;
			MapBoxMemoryLoc = Locateinterface(1477, 87, 0xffff, 44);
		}
	}
	return{ 0,0 };
}

//For simba, point
POINT ToMap(POINT spot) {




	FFPOINT pl = PlayerCoordFloat();
	FFPOINT center;
	POINT endcalc;
	//FFPOINT ItemCoord = {2281,3305};

	if (ScAdd10 != NULL) {
		//centre point
		//start is zero if against upper edge, but size works
		FFPOINT start = GetInterfaceStart(ScAdd10);
		FFPOINT size = GetInterfaceSize(ScAdd10);
		//corner
		if (start.x == NULL && start.x == NULL) {
			FLOAT x = (size.x / 2.f) + 12.f;
			//titlebar
			FLOAT y = (size.y / 2.f) + (GetRsResolution2().y) - 6.f;
			//cout <<"1: "<<dec<<GetRsResolution2().y<<"\n";
			//cout <<"2: "<< dec << GetRsResolution2().y<<"\n";
			center = { x,y };
		}
		else {
			FLOAT x = (start.x + size.x / 2.f) + 12.f;
			FLOAT y = (start.y + size.y / 2.f) + (GetRsResolution2().y) - 6.f;
			center = { x,y };
		}
		FLOAT xx = pl.x - spot.x ;
		FLOAT yy = pl.y - spot.y ;

		endcalc.x = (center.x - xx*4.f);
		endcalc.y = (center.y + yy*4.f);


		return{ endcalc.x,endcalc.y };
	}
	return{ 0,0 };
}

string GetItemText(WORD ID) {

	if (ID >0 && ID < 50000) {

		for (WORD i = 0; i < TextNR.size(); i++) {
			if (ID == TextNR[i]) {
				return  TextTxt[i];
			}
		}
		return  "";
	}
	return  "";
}

//for dung
DungMap GetItemText2(WORD ID) {

	if (ID >0 && ID < 50000) {
		//count to first dung item
		if (dungnote==0) {
			for (WORD i = 0; i < TextNR.size(); i++) {
				if (18202 == TextNR[i]) {
					dungnote = i;
				}
			}
		}
		for (WORD i = 0; i < TextNR.size(); i++) {
			if (ID == TextNR[i]) {
				return{ TextTxt[i],Dungvarp[i-dungnote] };
			}
		}
	}
	return{ "",0};
}

//experiment compass//compass finding could be dynamic
DWORD64 SearchCompass()
{

	vector<DWORD64> results;
	DWORD offset1 = 0x8;
	//vector<INT> ValueCounter;
    DWORD add1 = ReadCoordX3i()>>16;
	DWORD add2 = ReadCoordY3i()>>16;
	cout << dec << add1 << endl;
	printf("ReadingX: %I64X\n", add1);
	printf("ReadingY: %I64X\n", add2);
	PatternSearch pat = Chopbytes16(add1);
	scans.clear();
	INT count = 0;
	//
	DWORD z = 0x46800000;

	//cout << "Lookin for addresses \n";
	if (!procIDs.empty() & add1>0 & add2>0){

		DWORD64 ScanPlaceHolder = ScAdd1;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		DWORD64 ScanBack2 = 0x5000000;
		DWORD64 ScanFoward2 = 0x50000000;

		if (ScanBack2 > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack2;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward2;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }

		//still shorter than whole
		//pat.SearchRemoteEx(proc, 50000, ScanEnd, results);
		pat.SearchRemoteWhole(proc, false, 0, results);
		if (results.empty()) { cout << "Found non compass \n"; }
		if (!results.empty()) {
			//cout << dec << results.size() << "\n";
			for (DWORD i = 0; i < results.size(); i++) {
				//compares with y
				WORD bb1 = VirtPReadWord(results[i] + offset1);

				if (bb1 == add2) {
					DWORD val = VirtPReadDword(results[i] + 0x2);					
					BYTE val2 = VirtPReadByte(results[i] - 0x73);
					//z seems to be static for a map//active
					if (val == z && val2 ==9) { 
						printf("Compass!: %I64X\n", results[i]-0x7a); 
					return results[i] - 0x7a;
					}
					//printf("results[i]: %I64X\n", results[i]);
					//scans.push_back(results[i]);
					//cout << "Found!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n";

				}
			}
/*
			if (!scans.empty() & !scans2.empty()) {
				cout << "Total match: " << dec << scans.size() << "\n";
				for (DWORD i = 0; i < scans.size(); i++) {
					for (DWORD ii = 0; ii < scans2.size(); ii++) {
						if (scans[i] == scans2[ii]) { count++; }

					}
					if (count == 0) { printf("Changed: %I64X\n", scans[i]); }
					count = 0;
				}
			}
			scans2 = scans;
			*/
		}
	}
	return 0;
}

// checks if compass is still valid
VOID CompassCheck() {
	
	if (LocalPlayer != NULL) {
		if (Compass != NULL) {
			BYTE val2 = VirtPReadByte(Compass + 0x7);
			if (val2 != 9) {
				Compass = SearchCompass();
			}
		}
		else {
			Compass = SearchCompass();
		}
	}
}

int Findsom(DWORD64 add1, DWORD add2)
{
	vector<DWORD64> results;
	DWORD64 offset1 = 0x8;
	//vector<INT> ValueCounter;
	vector<DWORD64> list;
	PatternSearch pat = Chopbytes32(add1);


	cout << "Lookin for addresses \n";
	if (!procIDs.empty())
	{
		
		//bb1 = VirtPReadDword(off + offset1);
		//printf("Read1b1: %I64X\n", bb1);
		//bb2 = VirtPReadDword(off + offset2);
		//printf("Read1b2: %I64X\n", bb2);
		pat.SearchRemoteEx(proc, LocalPlayer, LocalPlayer +0x30000000, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			cout <<dec<< results.size() << "\n";
			for (DWORD i = 0; i < results.size(); i++) {
				DWORD bb1 = VirtPReadDword(results[i] + offset1);
				//printf("d1: %I64X\n", bb1);
				//printf("d1: %I64X\n", results[i]);
				if (bb1==add2) {
					//printf("d1: %I64X\n", results[i]);
					list.push_back(results[i]);
					//cout << "Found!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n";
					printf("results[i]: %I64X\n", results[i]);
				}
			}
			cout << dec << list.size()<<"\n";
		}
	}
	return 0;
}

//Finds all matches in memory and compare with Possible id 48bit down
BOOLEAN FindAtSpot(DWORD64 add1, DWORD add2,DWORD64 ID)
{
	vector<DWORD64> results;
	DWORD64 offset1 = 0x8;
	DWORD64 offset2 = 0x30;
	//vector<INT> ValueCounter;
	vector<DWORD64> list;
	vector<DWORD64> list2;
	PatternSearch pat = Chopbytes32(add1);


	INT x = CRL(add1) - CRL(MyLocXRaw);
	INT y = CRL(add2) - CRL(MyLocYRaw);
	if (CheckVisibleLimit(x, y)) {

	cout << "Lookin for addresses \n";
	if (!procIDs.empty())
	{

		//bb1 = VirtPReadDword(off + offset1);
		//printf("Read1b1: %I64X\n", bb1);
		//bb2 = VirtPReadDword(off + offset2);
		//printf("Read1b2: %I64X\n", bb2);
		pat.SearchRemoteEx(proc, LocalPlayer, LocalPlayer + 0x30000000, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			cout << dec << results.size() << "\n";
			for (DWORD i = 0; i < results.size(); i++) {
				DWORD bb1 = VirtPReadDword(results[i] + offset1);
				//printf("d1: %I64X\n", bb1);
				//printf("d1: %I64X\n", results[i]);
				if (bb1 == add2) {
					//printf("d1: %I64X\n", results[i]);
					list.push_back(results[i]);
					//cout << "Found!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n";
					//printf("results[i]: %I64X\n", results[i]);
				}
			}
			cout << dec << list.size() << "\n";
			for (DWORD ii = 0; ii < list.size(); ii++) {
				DWORD bb2 = VirtPReadDword(list[ii] + offset2);
				//printf("d1: %I64X\n", bb2);
				if (bb2 == ID) {
					list2.push_back(results[ii]);
					//printf("results[i]: %I64X\n", list[ii]);
					return true;
				}			
			}
			}
		}
	}
	else { printf("out of range!"); }
	return 0;
}

//test for 1 aob and 1 value
DWORD64 ScanTest1()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	///
	intertest.clear();
	intertest2.clear();
	intertest3.clear();
	intertest4.clear();

	//B3 08 00 00 00 00 00 00
	PatternSearch PS1{0xea,0x03,0x00,0x00,0x00,0x00,0x00,0x00};


	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{



		DWORD64 ScanPlaceHolder = LocalPlayer;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		PS1.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found non test \n"; }

		if (!results.empty()) {
			if (debug) { cout << "test result: " << dec << results.size() << "\n"; }

			//loop for matches
			WORD idoff = 0x38;
			for (DWORD i = 0; i < results.size(); i++) {

				DWORD64 v1 = VirtPRead64(results[i] - 0x10);//id 2227
				BYTE v2 = VirtPReadByte(results[i] -0x21);
				WORD v3 = VirtPReadWord(results[i] + idoff);

				if (v2==0x91) {
				results2.push_back(results[i]);
				intertest.push_back(results[i]);
				intertest2.push_back(v3);
				}
			}
		}



		if (!results2.empty()) {
			cout << "test result2s: " << dec << results2.size() << "\n";
			//pick middle one and hope its right
			int mid = results2.size() / 2;
			cout << "test result2: " << hex << results2[mid] << "\n";
			return results2[mid];
		}
		else { cout << "Failed to find test match" << "\n"; return 0; }
	}
	return 0;
}

//test for 1 aob and 1 value
DWORD64 ScanTest2()
{

	vector<DWORD64> results;
	vector<DWORD64> results2;
	///
	intertest.clear();
	intertest2.clear();
	intertest3.clear();
	intertest4.clear();

	//E6 0E 00 00 00 00 00 00
	PatternSearch PS1{ 0xe6,0x0e,0x00,0x00 };


	//cout << "Lookin for \n";
	if (!procIDs.empty())
	{



		DWORD64 ScanPlaceHolder = LocalPlayer;
		DWORD64 ScanStart;
		DWORD64 ScanEnd;
		if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
		else {
			ScanStart = ScanPlaceHolder - ScanBack;
		}
		ScanEnd = ScanPlaceHolder + ScanFoward;
		if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
		PS1.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
		if (results.empty()) { cout << "Found non test \n"; }

		if (!results.empty()) {
			if (debug) { cout << "test result: " << dec << results.size() << "\n"; }

			//loop for matches
			WORD idoff = 0x40;
			for (DWORD i = 0; i < results.size(); i++) {

				//DWORD64 v1 = VirtPRead64(results[i] - 0x10);//id 2227
				BYTE v2 = VirtPReadByte(results[i] - 0x71);
				BYTE v3 = VirtPReadByte(results[i] - idoff);

				if (v2 == 0x91) {
					intertest.push_back(results[i]);
					intertest2.push_back(v3);
				}
			}
		}
		cout << "Found:" << dec << results.size() << endl;
		cout << "Found filtered:" << dec << intertest.size() << endl;
	}
	return 0;
}

//searches grounditem below player
VOID SearchGItem(INT item)
{

	vector<DWORD64> results;
	DWORD offset1 = 0x8;
	//vector<INT> ValueCounter;
	DWORD add1 = ReadCoordX3i();
	DWORD add2 = ReadCoordY3i();
	printf("ReadingX: %I64X\n", add1);
	printf("ReadingY: %I64X\n", add2);
	//down smaller/0x1000 step at ark
	DWORD step = 0x1000;
	PatternSearch pat = Chopbytes32(add1);
	scans.clear();
	INT count = 0;
	//From x to Id for grounditem
	DWORD off = 0x40;
	DWORD off2 = 0x70;//-

	cout << "Lookin for addresses \n";
	if (!procIDs.empty() & add1>0 & add2>0)
	{
		pat.SearchRemoteWhole(proc, false, 0, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			cout << dec << results.size() << "\n";
			for (DWORD i = 0; i < results.size(); i++) {
				//compares with y
				DWORD bb1 = VirtPReadDword(results[i] + offset1);

				if (bb1 == add2) {
					DWORD ID = VirtPReadDword(results[i] - off2);

					//id
					if (ID==item) { printf("ID match!!!!!!!: %I64X\n", results[i]);}
					printf("results[i]: %I64X\n", results[i]);
					scans.push_back(results[i]);
					//cout << "Found!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n";
					
				}
			}
			
			if (!scans.empty() & !scans2.empty()){
				cout << "Total match: " << dec << scans.size() << "\n";
			for (DWORD i = 0; i < scans.size(); i++) {
				for (DWORD ii = 0; ii < scans2.size(); ii++) {
					if (scans[i] == scans2[ii]) { count++; }
									
				}
				if (count==0){ printf("Changed: %I64X\n", scans[i]); }
				count = 0;
			}	
		}
			scans2 = scans;
		}
	}
}

//experiment
VOID Searchtest(INT item)
{ 

	vector<DWORD64> results;
	DWORD offset1 = 0x4;
	//vector<INT> ValueCounter;
	DWORD add1 = PlayerCoordFloat().x;
	DWORD add2 = PlayerCoordFloat().y;
	printf("ReadingX: %I64X\n", add1);
	printf("ReadingY: %I64X\n", add2);
	//down smaller/0x1000 step at ark
	//DWORD step = 0x1000;
	PatternSearch pat = Chopbytes32(add1);
	scans.clear();
	INT count = 0;
	//From x to Id for grounditem
	DWORD off = 0x40;
	DWORD off2 = 0x70;//-

	cout << "Lookin for addresses \n";
	if (!procIDs.empty() & add1>0 & add2>0)
	{
		pat.SearchRemoteWhole(proc, false, 0, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			cout << dec << results.size() << "\n";
			for (DWORD i = 0; i < results.size(); i++) {
				//compares with y
				DWORD bb1 = VirtPReadDword(results[i] + offset1);

				if (bb1 == add2) {
					DWORD ID = VirtPReadDword(results[i] - off2);

					//id
					if (ID == item) { printf("ID match!!!!!!!: %I64X\n", results[i]); }
					printf("results[i]: %I64X\n", results[i]);
					scans.push_back(results[i]);
					//cout << "Found!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n";

				}
			}

			if (!scans.empty() & !scans2.empty()) {
				cout << "Total match: " << dec << scans.size() << "\n";
				for (DWORD i = 0; i < scans.size(); i++) {
					for (DWORD ii = 0; ii < scans2.size(); ii++) {
						if (scans[i] == scans2[ii]) { count++; }

					}
					if (count == 0) { printf("Changed: %I64X\n", scans[i]); }
					count = 0;
				}
			}
			scans2 = scans;
		}
	}
}
//searches at spot
VOID SearchObj(INT item)
{

	vector<DWORD64> results;
	DWORD offset1 = 0x4;
	//vector<INT> ValueCounter;
	DWORD add1 = 415;
	DWORD add2 = 677;
	//printf("ReadingX: %I64X\n", add1);
	//printf("ReadingY: %I64X\n", add2);
	//down smaller/0x1000 step at ark
	DWORD step = 0x1000;
	PatternSearch pat = Chopbytes32(add1);
	scans.clear();
	INT count = 0;
	//From x to Id for grounditem
	DWORD off = 0x40;
	DWORD off2 = 0x70;//-

	cout << "Lookin for addresses \n";
	if (!procIDs.empty() & add1>0 & add2>0)
	{
		pat.SearchRemoteWhole(proc, false, 0, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			cout << dec << results.size() << "\n";
			for (DWORD i = 0; i < results.size(); i++) {
				//compares with y
				DWORD bb1 = VirtPReadDword(results[i] + offset1);

				if (bb1 == add2) {
					DWORD ID = VirtPReadDword(results[i] - off2);

					//id
					if (ID == item) { printf("ID match!!!!!!!: %I64X\n", results[i]); }
					printf("results[i]: %I64X\n", results[i]-4);
					scans.push_back(results[i]);
					//cout << "Found!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n";

				}
			}

			if (!scans.empty() & !scans2.empty()) {
				cout << "Total match: " << dec << scans.size() << "\n";
				for (DWORD i = 0; i < scans.size(); i++) {
					for (DWORD ii = 0; ii < scans2.size(); ii++) {
						if (scans[i] == scans2[ii]) { count++; }

					}
					if (count == 0) { printf("Changed: %I64X\n", scans[i]); }
					count = 0;
				}
			}
			scans2 = scans;
		}
	}
}

//searches screenobjects near player, nr of tiles up
VOID SearchSOItem(DWORD item)
{

	vector<DWORD64> results;
	DWORD offset1 = 0x8;
    //at death office step 0x4000	
	//priff step is sideways(x) 0x1000
	DWORD step = 0x1000;
	DWORD add1 = ReadCoordX3i()+step;
	DWORD add2 = ReadCoordY3i();
	printf("ReadingX: %I64X\n", add1);
	printf("ReadingY: %I64X\n", add2);
	//down smaller/0x1000 step at ark
	PatternSearch pat = Chopbytes32(add1);
	scans.clear();
	INT count = 0;
	//From x to Id for grounditem
	DWORD off2 = 0x30;
	 
	cout << "Lookin for addresses \n";
	if (!procIDs.empty() & add1>0 & add2>0)
	{
		pat.SearchRemoteWhole(proc, false, 0, results);
		if (results.empty()) { cout << "Found non \n"; }
		if (!results.empty()) {
			cout << dec << results.size() << "\n";
			for (DWORD i = 0; i < results.size(); i++) {
				//compares with y
				DWORD bb1 = VirtPReadDword(results[i] + offset1);

				if (bb1 == add2) {
					DWORD ID = VirtPReadDword(results[i] + off2);

					//id
					if (ID == item) { printf("ID match!!!!!!!: %I64X\n", results[i]); }
					printf("results[i]: %I64X\n", results[i]);
					scans.push_back(results[i]);
					//cout << "Found!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! \n";

				}
			}

			if (!scans.empty() & !scans2.empty()) {
				cout << "Total match: " << dec << scans.size() << "\n";
				for (DWORD i = 0; i < scans.size(); i++) {
					for (DWORD ii = 0; ii < scans2.size(); ii++) {
						if (scans[i] == scans2[ii]) { count++; }

					}
					if (count == 0) { printf("Changed: %I64X\n", scans[i]); }
					count = 0;
				}
			}
			scans2 = scans;
		}
	}
}

//Gathers inventory information from interface//IF2//old
VOID ReadInvArrays2()
{
	vector<DWORD64> IAddr;
	vector<INT> InvSlot;

	InvSlot.clear();
	InvText.clear();
	InvId.clear();
	InvAm.clear();
	InvSlot2.clear();
	IAddr.clear();
	IAddr2.clear();
	 
	DWORD offh = 0;
	INT limit = 0;
	//1468//array start correction
	DWORD off1 = 0x2d4;
	//TO BLOCK dif
	//DWORD off2 = 0x810;
	//slot-
	DWORD off3 = 0x8;
	//text
	//DWORD off4 = 0x58;
	//id
	DWORD off5 = 0x40a;
	//amount
	DWORD off6 = 0x40e;
	//slot valid
	//DWORD offv1= 0x3FC;
    //inv slotmark-
	//DWORD offv5 = 0x2a0;
	//inv float
	DWORD offv6 = 0x3ba;
	// activ block? 90?
	//DWORD offv7 = 0x2d1;
	//other v2
	//DWORD offv8 = 0x40a;
	//other v3
	//DWORD offv9 = 0x6;





	if (!InvIA.empty()) {

		///////////////////////////////
		for (DWORD i = 0; i < InvIA.size(); i++) {

			BYTE bb3 = VirtPReadByte(InvIA[i] + off3);
			if (debug2) { cout << dec << bb3 << ": " << hex << InvIA[i] << "\n"; }
			InvSlot.push_back(bb3);
			IAddr.push_back(InvIA[i]);

		}

		if (debug2) { cout << "valid: " << dec << InvSlot.size() << "\n"; }
		for (DWORD i = 0; i < 28; i++) {
			for (DWORD ii = 0; ii < InvSlot.size(); ii++) {

				if (i == InvSlot[ii]) {
					IAddr2.push_back(IAddr[ii]);
					break;
				}
			}
		}
		//rescan

		//cout <<"IAddr2 size: "<< IAddr2.size() << "\n";
		//if (IAddr2.size() != 0x1c) { cout << "Rescan \n"; R7 = 1; LocateStartAddresses(); }
		//else {
			for (DWORD i = 0; i < IAddr2.size(); i++) {

				//	char* bb4 = VirtPReadChar(IAddr[i]+ + off4);
				DWORD bb3 = VirtPReadByte(IAddr2[i] + off3);
				DWORD bb5 = VirtPReadDword(IAddr2[i] + off5); 
				DWORD bb6 = VirtPReadWord(IAddr2[i] + off6);

				InvSlot2.push_back(bb3);
				//InvText.push_back(bb4);
				if (bb5 == 0xffffffff) { bb5 = 0; }
				InvId.push_back(bb5);
				InvAm.push_back(bb6);
			//}
		}
	}
}

//filters out inventory items from found dynamic inv array data//constantly//read straight in//for debug make another general one
VOID FilterInventory()
{
	Invx.clear();
	Invy.clear();
	//InvText.clear();
	InvId.clear();
	//InvAm.clear();
	InvSlot2.clear();
	//IAddr2.clear();

	DWORD64 offh = 0;
	INT limit = 0;
	WPOINT box;

	if (InterfCheck(InvBoxMemoryLoc, 1477, 107, 0xffff, 44)) {
		box = GetInterfaceData2(InvBoxMemoryLoc).xy;
	}
	else {
		InvBoxMemoryLoc = Locateinterface(1477, 107, 0xffff, 44);
	}


	MEMss BlockA;

	if (!INVIArr.empty()) {
		for (DWORD i5 = 0; i5 < INVIArr.size(); i5++) {
			//cout << hex << INVIArr << endl;
			BlockA = DeterMemoryBlockLenght(INVIArr[i5]);
			limit = 30000;
			DWORD64 Sc = INVIArr[i5] - I2off2*(limit / 2);
			for (DWORD i = 0; i < limit; i++) {
				offh = offh + I2off2;
				DWORD64 Hold = Sc + offh;
				if ((Hold) > BlockA.start) {

					//active check
					DWORD v1 = VirtPReadDword(Hold + I2off555);
					DWORD v2 = VirtPReadDword(Hold + I2off666);
					//1473
					WORD v3 = VirtPReadWord(Hold + I2off55);
					//5
					WORD v4 = VirtPReadWord(Hold + I2off55 + 2);
					//5
					DWORD v7 = VirtPReadDword(Hold + I2off55 + 8);
					if (v1 == 1 && v2 == 1 && v3 == 1473 && v4 == 5 && v7 == 5) {

						WORD startx = VirtPReadWord(Hold + I2off11);
						WORD startxs = VirtPReadWord(Hold + I2off332);
						Invx.push_back(startx + box.x + (startxs / 2) + 3);
						WORD starty = VirtPReadWord(Hold + I2off22);
						WORD startys = VirtPReadWord(Hold + I2off442);
						Invy.push_back(starty + box.y + (startys / 2) + 45);
						BYTE slots = VirtPReadByte(Hold + I2off55 + 6);
						InvSlot2.push_back(slots);
						DWORD ids = VirtPReadDword(Hold + I2offitemids);
						if (ids == 0xffffffff) { ids = 0; }
						InvId.push_back(ids);




					}
				}
			}
		}
	}
}

// filters out bank
VOID FilterB()
{
	Invx.clear();
	Invy.clear();
	//InvText.clear();
	InvId.clear();
	//InvAm.clear();
	InvSlot2.clear();
	IAddr2.clear();

	DWORD64 offh = 0;
	DWORD64 Sc = 0;
	INT limit = 500;


	MEMss BlockA;

	for (int i2 = 0; i2 < BANKArr.size(); i2++) {
		offh = 0;
		Sc = 0;

		Sc = BANKArr[i2] - I3off2*(limit / 2);
		for (DWORD i = 0; i < limit; i++) {
			offh = offh + I3off2;
			//active check
			DWORD v1 = VirtPReadDword(Sc + offh + I3off555);
			DWORD v2 = VirtPReadDword(Sc + offh + I3off666);
			//
			WORD v3 = VirtPReadWord(Sc + offh + I3off55);
			//
			BYTE v4 = VirtPReadByte(Sc + offh + I3off55 + 2);
			WORD v5 = VirtPReadWord(Sc + offh + I3off55 + 4);
			//
			DWORD v7 = VirtPReadDword(Sc + offh + I3off55 + 8);
			if (v1 == 1 && v2 == 1
				&& v3 == 762
				&& v4 == 5 && v5 == 243
				&& v7 == 243
				) {
				FLOAT starty = VirtPReadWord(Sc + offh + I3off22);
				if (starty < 800.f) {
					FLOAT startx = VirtPReadWord(Sc + offh + I3off11);
					FLOAT startxs = VirtPReadWord(Sc + offh + I3off332);
					Invx.push_back(startx + (startxs / 2.f) + 3.5f);
					FLOAT startys = VirtPReadWord(Sc + offh + I3off442);
					Invy.push_back(starty + (startys / 2.f) + 45.f);
					WORD slots = VirtPReadWord(Sc + offh + I3off55 + 6);
					InvSlot2.push_back(slots);
					DWORD ids = VirtPReadDword(Sc + offh + I3offitemids);
					if (ids == 0xffffffff) { ids = 0; }
					InvId.push_back(ids);
					IAddr2.push_back(Sc + offh);
				}
			}
		}
	}
}

// filters out bank inventory
VOID FilterBI()
{
	Invx.clear();
	Invy.clear();
	//InvText.clear();
	InvId.clear();
	//InvAm.clear();
	InvSlot2.clear();
	IAddr2.clear();

	DWORD64 offh = 0;
	DWORD64 Sc = 0;
	INT limit = 1500;


	MEMss BlockA;

	for (int i2 = 0; i2 < BANKIArr.size(); i2++) {
		offh = 0;
		Sc = 0;

		Sc = BANKIArr[i2] - I3off2*(limit / 2);
		for (DWORD i = 0; i < limit; i++) {
			offh = offh + I3off2;
			//active check
			DWORD v1 = VirtPReadDword(Sc + offh + I3off555);
			DWORD v2 = VirtPReadDword(Sc + offh + I3off666);
			//
			WORD v3 = VirtPReadWord(Sc + offh + I3off55);
			//
			BYTE v4 = VirtPReadByte(Sc + offh + I3off55 + 2);
			WORD v5 = VirtPReadWord(Sc + offh + I3off55 + 4);
			//
			DWORD v7 = VirtPReadDword(Sc + offh + I3off55 + 8);
			if (v1 == 1 && v2 == 1
				&& v3 == 762
				&& v4 == 5 && v5 == 10
				&& v7 == 10
				) {
				FLOAT starty = VirtPReadWord(Sc + offh + I3off22);
				if (starty < 800.f) {
					FLOAT startx = VirtPReadWord(Sc + offh + I3off11);
					FLOAT startxs = VirtPReadWord(Sc + offh + I3off332);
					Invx.push_back(startx + (startxs / 2.f) + 3.5f);
					FLOAT startys = VirtPReadWord(Sc + offh + I3off442);
					Invy.push_back(starty + (startys / 2.f) + 45.f);
					WORD slots = VirtPReadWord(Sc + offh + I3off55 + 6);
					InvSlot2.push_back(slots);
					DWORD ids = VirtPReadDword(Sc + offh + I3offitemids);
					if (ids == 0xffffffff) { ids = 0; }
					InvId.push_back(ids);
					IAddr2.push_back(Sc + offh);
				}
			}
		}
	}
}

// filters out loot inventory
VOID FilterLoot()
{
	Invx.clear();
	Invy.clear();
	//InvText.clear();
	InvId.clear();
	//InvAm.clear();
	InvSlot2.clear();
	IAddr2.clear();

	DWORD64 offh = 0;
	DWORD64 Sc = 0;
	INT limit = 1500;


	MEMss BlockA;

	for (int i2 = 0; i2 < LOOTArr.size(); i2++) {
		offh = 0;
		Sc = 0;

		Sc = LOOTArr[i2] - I3off2*(limit / 2);
		for (DWORD i = 0; i < limit; i++) {
			offh = offh + I3off2;
			//active check
			DWORD v1 = VirtPReadDword(Sc + offh + I3off555);
			DWORD v2 = VirtPReadDword(Sc + offh + I3off666);
			//
			WORD v3 = VirtPReadWord(Sc + offh + I3off55);
			//
			BYTE v4 = VirtPReadByte(Sc + offh + I3off55 + 2);
			WORD v5 = VirtPReadWord(Sc + offh + I3off55 + 4);
			//
			DWORD v7 = VirtPReadDword(Sc + offh + I3off55 + 8);
			if (v1 == 1 && v2 == 1
				&& v3 == 1622
				&& v4 == 5 && v5 == 10
				&& v7 == 10
				) {
				FLOAT starty = VirtPReadWord(Sc + offh + I3off22);
				if (starty < 800.f) {
					FLOAT startx = VirtPReadWord(Sc + offh + I3off11);
					FLOAT startxs = VirtPReadWord(Sc + offh + I3off332);
					Invx.push_back(startx + (startxs / 2.f) + 3.5f);
					FLOAT startys = VirtPReadWord(Sc + offh + I3off442);
					Invy.push_back(starty + (startys / 2.f) + 45.f);
					WORD slots = VirtPReadWord(Sc + offh + I3off55 + 6);
					InvSlot2.push_back(slots);
					DWORD ids = VirtPReadDword(Sc + offh + I3offitemids);
					if (ids == 0xffffffff) { ids = 0; }
					InvId.push_back(ids);
					IAddr2.push_back(Sc + offh);
				}
			}
		}
	}
}

VOID ReadGroundItemsArray()
{

	GIX.clear();
	GIY.clear();
	GIID.clear();
	GIAM.clear();
	GIText.clear();
	GIMem.clear();


	INT limit = 0;
	//1430//array start correction
	//DWORD off1 = 0x11;
	//TO BLOCK dif
	DWORD off2 = 0xb0;
	DWORD offh = 0;
	//x
	DWORD off11 = 0x90;
	//y
	DWORD off22 = 0x98;
	//to id
	DWORD off33 = 0x20;
	// amount
	DWORD off5 = 0x24;
	// activ//2
	DWORD off6 = 0x8;
	// activ//1
	DWORD off7 = 0xc;

	if (ScAdd4 != NULL) {
		//BlockA = DeterMemoryBlockLenght(ScAdd4);
		//half should be more than enough
		limit = 400;
		//cout << ":" <<dec<< limit << "\n";

		//make to standard array part+ to x
		DWORD64 Sc = ScAdd4-off2*(limit/2);
		///////////////////////////////
		for (DWORD i = 0; i < limit; i++) {
			offh = offh + off2;
			BYTE bb5 = VirtPReadByte(Sc + offh + off6);
			BYTE bb6 = VirtPReadByte(Sc + offh + off7);
			//active check first
			if ((bb5 >0 && bb5 <5) && (bb6 >0 && bb6 <5)) {
			FLOAT bb1 = VirtPReadFloat(Sc + offh + off11);
			FLOAT bb2 = VirtPReadFloat(Sc + offh + off22);
			DWORD bb4 = VirtPReadDword(Sc + offh + off5);
					
				if (bb1 != NULL && bb2 != NULL && bb4 != NULL) {
					if (CheckVisibleLimit(bb1, bb2)) {
						//printf("ok1:\n");
							//printf("ok2:\n");

						DWORD bb3 = VirtPReadDword(Sc + offh + off33);

						if (bb3 != NULL && bb3 < 60000) {
							GIX.push_back(bb1 - 256.f);
							GIY.push_back(bb2 - 256.f);
							GIID.push_back(bb3);
							GIAM.push_back(bb4);
							GIText.push_back(GetItemText(bb3));
							GIMem.push_back(Sc + offh);
							//if (bb3 == 12442) { printf("GIID: %I64X\n", Sc + offh - off33); }
						}
					}
				}
			}
		}
	}
}

//dimensional part2
VOID ReadGroundItemsArray2()
{

	GIX2.clear();
	GIY2.clear();
	GIID2.clear();
	GIAM2.clear();
	GIFL2.clear();
	GIMem2.clear();
	GIxmid2.clear();
	GIymid2.clear();
	GIText2.clear();
	WORD resy = GetRsResolution2().y;

	INT limit = 0;
	//1430//array start correction
	//DWORD off1 = 0x11;
	//TO BLOCK dif
	DWORD off2 = 0x9a0;
	DWORD offh = 0;
	//x
	DWORD off11 = 0x98C;
	//y
	DWORD off22 = 0x994;
	//to id
	DWORD off33 = 0x130;
	// floor
	DWORD off5 = 0x98C-0x4;
	//xmid
	WORD offxm = 0x88;
	//ymid
	WORD offym = 0x8c;
	// activ
	DWORD off6 = 0x8;
	// activ
	DWORD off7 = 0xc;

	if (ScAdd11 != NULL) {
		//BlockA = DeterMemoryBlockLenght(ScAdd4);
		//half should be more than enough
		limit = 400;
		//cout << ":" <<dec<< limit << "\n";

		//make to standard array part+ to x
		DWORD64 Sc = ScAdd11 - off2*(limit / 2);
		///////////////////////////////
		for (DWORD i = 0; i < limit; i++) {
			offh = offh + off2;
			BYTE bb5 = VirtPReadByte(Sc + offh + off6);
			BYTE bb6 = VirtPReadByte(Sc + offh + off7);
			//active check first
			if ((bb5 >0 && bb5 <5) && (bb6 >0 && bb6 <5)) {
				//printf("ok1:\n");
				FLOAT bb1 = VirtPReadFloat(Sc + offh + off11);
				FLOAT bb2 = VirtPReadFloat(Sc + offh + off22);

				if (bb1 != NULL && bb2 != NULL) {
					if (CheckVisibleLimit(bb1, bb2)) {					
					//	printf("ok2:\n");

						//directly points to other array! where is id written
						DWORD64 placeholder = VirtPRead64(Sc + offh + off33);
						//now read that id from other array
						DWORD OtherID = VirtPReadDword(placeholder+0x20);
						//amount
						BYTE OtherAM= VirtPReadByte(placeholder + 0x24);


						BYTE bb34 = VirtPReadByte(Sc + offh + off5);
						WORD xm = VirtPReadWord(Sc + offh + offxm);
						WORD ym = VirtPReadWord(Sc + offh + offym);

							GIX2.push_back(bb1);
							GIY2.push_back(bb2);
							GIID2.push_back(OtherID);
							GIAM2.push_back(OtherAM);
							GIFL2.push_back(bb34);
							GIxmid2.push_back(xm);
						    GIymid2.push_back(resy - ym);
							GIMem2.push_back(Sc + offh);
							GIText2.push_back(GetItemText(OtherID));


					}
				}
			}
		}
	}
}

//finds ground item, returns true
BOOLEAN FindGItemBool_(vector<DWORD> item) {
	ReadCObjArrays();
	//ReadGroundItemsArray2();
	if (!GIID2.empty() && !item.empty()) {
		for (DWORD i = 0; i < GIID2.size(); i++) {
			for (DWORD ii = 0; ii < item.size(); ii++) {
				if (GIID2[i] == item[ii]) {
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}

// Grounditems click
BOOLEAN FindGItem_(vector<DWORD> item, BYTE maxdistance, INT corx, INT cory, BYTE action, string sidetext) {

	vector<FLOAT> MatchNPCsDist;
	vector<FLOAT> MatchNPCsDist2;
	vector<FLOAT> MatchNPCsDist3;
	vector<DWORD64> MatchNPCsMBlock;
	vector<DWORD64> MatchNPCsMBlock2;
	vector<DWORD> MatchNPCsTimer;
	vector<DWORD> MatchNPCsTimer2;
	FFPOINT p = PlayerCoordFloatRaw();
	FLOAT min = 51200.f;
	//x
	DWORD off11 = 0x15c;
	//y
	DWORD off22 = 0x160;
	//hover
	//DWORD off33 = 0x464;
	DWORD hover;
	DWORD hover2;
	//xm
	DWORD offxm = 0x88;
	//ym
	DWORD offym = 0x8c;
	GetWindowRect(WProcC, &rs);
	WORD resyt = rs.top;
	WORD resxl = rs.left;
	WORD resyy = GetRsResolution2().y;
	//ReadCObjArrays();
	//ReadGroundItemsArray2();

	if (!GIID2.empty() && !item.empty()) {
		for (DWORD i1 = 0; i1 < GIID2.size(); i1++) {
			for (DWORD i2 = 0; i2 < item.size(); i2++) {
				if (item[i1] != NULL || GIID2[i2] != NULL) {
					if (GIID2[i2] == item[i1]) {
						FLOAT dist = sqrt(pow(GIX2[i2] - p.x, 2) + pow(GIY2[i2] - p.y, 2)) + (0.001f*i2);
						if (dist < maxdistance*512.f) {
							MatchNPCsDist.push_back(dist);
							MatchNPCsDist2.push_back(dist);
							MatchNPCsMBlock.push_back(DecorMem[i2]);
							MatchNPCsTimer.push_back(ViewPartialDecor[i2]);
						}
					}
				}
			}
		}
		//sort first dist by distance size
		if (!MatchNPCsMBlock.empty()) {
			sort(MatchNPCsDist.begin(), MatchNPCsDist.end());

			//set memory blocks into order by dist and dist2
			for (DWORD i = 0; i < MatchNPCsDist.size(); i++) {
				for (DWORD ii = 0; ii < MatchNPCsDist2.size(); ii++) {
					if (MatchNPCsDist[i] == MatchNPCsDist2[ii]) {
						//should add closest memory block @ 0(first)
						MatchNPCsMBlock2.push_back(MatchNPCsMBlock[ii]);
						MatchNPCsDist3.push_back(MatchNPCsDist2[ii]);
						MatchNPCsTimer2.push_back(MatchNPCsTimer[ii]);
					}
				}
			}
		}


		BOOLEAN failed = FALSE;
		if (!MatchNPCsMBlock2.empty()) {
			for (DWORD loop = 0; loop < 25; loop++) {
				Sleep(10);
				for (DWORD i = 0; i < MatchNPCsMBlock2.size(); i++) {
					//try minimap/
					if (i < MatchNPCsMBlock2.size()) { failed = TRUE; }
					DWORD64 holder = VirtPRead64(MatchNPCsMBlock2[i] + alloff88);
					DWORD part = VirtPReadDword(holder + alloff66);
					if (MatchNPCsTimer2[i] != part) {
						WPOINT screenp = { VirtPReadWord(MatchNPCsMBlock2[i] + goffxm), VirtPReadWord(MatchNPCsMBlock2[i] + goffym) };
						screenp.y = resyy - screenp.y;
						if (ScreenFilter(screenp)) {
							screenp.x = screenp.x - 7 + corx + resxl;
							screenp.y = screenp.y - 7 + cory + resyt;
							if (action == 0) {
								MoveMouse2(screenp.x, screenp.y, 14, 20);
								RandomSleep2(25, 550, 3000);
								if (SideTextEq(sidetext)) {
									MouseLeftClick(50, 2000);
									return TRUE;
								}
							}
							if (action == 1) {
								MoveMouse2(screenp.x, screenp.y, 14, 20);
								RandomSleep2(25, 550, 3000);
								if (SideTextEq(sidetext)) {
									MouseRightClick(50, 2000);
									return TRUE;
								}
							}
							if (action == 2) {
								MoveMouse2(screenp.x, screenp.y, 14, 20);
								RandomSleep2(25, 550, 3000);
								if (SideTextEq(sidetext)) {
									return TRUE;
								}
							}
							if (action == 3) {
								return TRUE;
							}
						}
					}
				}
			}
			if (failed == TRUE) {
				WPOINT screenp = ToMapFFPOINT2({ VirtPReadWord(MatchNPCsMBlock2[0] + aooff11)*512.f,VirtPReadWord(MatchNPCsMBlock2[0] + aooff22)*512.f });
				if (screenp.x != 0 && screenp.y != 0) {
					screenp.x = screenp.x - 4; screenp.y = screenp.y - 4;
					MoveMouse2(screenp.x, screenp.y, 4, 4);
					RandomSleep2(30, 1150, 5000);
					MouseLeftClick(50, 2000);
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}

//interfaces debug//IF/boxes//main interfaces 1
VOID ReadInterf()
{
	InterfX.clear();
	InterfY.clear();
	InterfXs1.clear();
	InterfYs1.clear();
	InterfXs11.clear();
	InterfYs11.clear();
	InterfID.clear();
	InterfID2.clear();
	InterfID3.clear();
	InterfID4.clear();
	InterfHov.clear();
	InterfMem.clear();
	InterfAct.clear();
	InterName.clear();
	InterfTimer.clear();


	INT limit = 0;
	//
	DWORD Ioffh = 0;
	//DWORD Ioff1 = 0x38;	
	BOOLEAN opend=FALSE;
	MEMss BlockA;


	if (IF != NULL) {
		//cout << hex << INVIArr << endl;
		//BlockA = DeterMemoryBlockLenght(IF);
		limit = 25000;
		DWORD64 Sc = IF - Ioff2*(limit / 2);
		for (DWORD i = 0; i < limit; i++) {
			Ioffh = Ioffh + Ioff2;
			DWORD64 Hold = Sc + Ioffh;
			//active check
			DWORD bb3 = VirtPReadDword(Hold + Ioff555);
			DWORD bb4 = VirtPReadDword(Hold + Ioff666);
			if ((bb3 > 0 && bb3 < 4) && (bb4 > 0 && bb4 < 3)) {
				//cout << "ok1" << "\n";
				//coords
				FLOAT bb1 = VirtPReadWord(Hold + Ioff11);
				FLOAT bb2 = VirtPReadWord(Hold + Ioff22);

				if (bb1 < 4000.f && bb2 < 4000.f) {
					//FLOAT bb3 = VirtPReadWord(Sc + offh + off33);
					//FLOAT bb4 = VirtPReadWord(Sc + offh + off44);
					FLOAT bb3 = VirtPReadWord(Hold + Ioff332);
					FLOAT bb4 = VirtPReadWord(Hold + Ioff442);
					BYTE bb33 = VirtPReadByte(Hold + Ioffhhh);
					WORD bb5 = VirtPReadWord(Hold + Ioff55);
					WORD bb7 = VirtPReadWord(Hold + Ioff55 + 4);
					WORD bb8 = VirtPReadWord(Hold + Ioff55 + 6);
					WORD bb9 = VirtPReadWord(Hold + Ioff55 + 8); 
					DWORD64 placeholder2 = VirtPRead64(Hold + Ioff00);
					//string s = VirtPReadChar(placeholder2);
					//InterName.push_back(s);
					if (bb3 == 0 && bb4 == 0) { opend = FALSE; }
					else { opend = TRUE; }

					InterfX.push_back(bb1);
					InterfY.push_back(bb2);
					InterfXs11.push_back(bb3);
			 		InterfYs11.push_back(bb4);
					InterfID.push_back(bb5);
					InterfID2.push_back(bb7);
					InterfID3.push_back(bb8);
					InterfID4.push_back(bb9);
					InterfAct.push_back(opend);
					InterfHov.push_back(bb33);
					InterfMem.push_back(Sc + Ioffh);

					//directly points to other array
					DWORD64 placeholder = VirtPRead64(Hold + Itimeroff);
					//timer!!/dosent wor, sometimes :I
					DWORD OtherT = VirtPReadDword(placeholder + Itimeroff2);
					InterfTimer.push_back(OtherT);




				}
			}
		}
	} 
}

//finding interface 1 booleans open/closed//boxes//
VOID FindInterfAll()
{
	vector<DWORD64> results;
	//vector<DWORD64> results2;
	//vector<DWORD64> results3;
	WORD Step = 0x18;
	DWORD64 Holder;

	PatternSearch PS1{};

	if (ScAdd1 != NULL) {
		if (InterfCheck(InvBoxMemoryLoc, 1477, 107, 0xffff, 44)) {
		}
		else {
			InvBoxMemoryLoc = Locateinterface(1477, 107, 0xffff, 44);
		}
		//use inventory box as starting point to find all
		if (InvBoxMemoryLoc != NULL) {

			PS1 = Chopbytes64(InvBoxMemoryLoc);
			DWORD64 ScanPlaceHolder = ScAdd1;
			DWORD64 ScanStart;
			DWORD64 ScanEnd;
			if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
			else {
				ScanStart = ScanPlaceHolder - ScanBack;
			}
			ScanEnd = ScanPlaceHolder + ScanFoward;
			if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }
			PS1.SearchRemoteEx(proc, ScanStart, ScanEnd, results);
			//-0x8 up should be boolean on/off
			//step is 0x18      
			//it should hit exactly to middle, 1 line up bool,1 below extra address
			if (!results.empty()){
			//loop to remove inventory box
			for (DWORD i = 0; i < results.size(); i++) {
				if (results[i]-0x10 == InvBoxMemoryLoc) {
					//cout <<"Delete"<< endl;
					results.erase(results.begin()+i);
				}}
			//loop to find right array with over 1000 interfaces//first found
			for (DWORD i = 0; i < results.size(); i++) {	
				Holder = 0;
				Holder = Holder + results[i];
			//	cout << hex <<"Holder: "<< Holder << endl;
				for (DWORD ii = 0; ii < 4000; ii++) {
					Holder = Holder - Step;
					//try to focus on start point
					 DWORD64 h = VirtPRead64(Holder+0x8);
					 //9
					 BYTE h1 = VirtPReadByte(Holder - 0x1);
					 if (Holder==h && h1 == 9) {
						 cout << hex<<"interface hits: "<< Holder-0x8 << endl;
						 Interfexp1 = Holder - 0x8;
						 //20000 lines/24 =1111


					 }
				}}


		}}}}

//interfaces debug//IF/boxes//main interfaces 1
VOID ReadInterfAll()
{
	InterfX.clear();
	InterfY.clear();
	InterfXs1.clear();
	InterfYs1.clear();
	InterfXs11.clear();
	InterfYs11.clear();
	InterfID.clear();
	InterfID2.clear();
	InterfID3.clear();
	InterfID4.clear();
	InterfHov.clear();
	InterfMem.clear();
	InterfAct.clear();
	InterName.clear();
	InterfTimer.clear();


	INT limit = 0;
	INT limit2 = 0;
	//
	DWORD Ioffh = 0;
	//DWORD Ioff1 = 0x38;
	DWORD step1 = 0x18;
	BOOLEAN opend = FALSE;
	//MEMss BlockA;


	if (Interfexp1 != NULL) {
		//

		limit = 600;
		
		if (GetAsyncKeyState(VK_NUMPAD0)) { limit = 200; limit2 = 0; }
		if (GetAsyncKeyState(VK_NUMPAD1)) { limit = 400; limit2 = 200; }
		if (GetAsyncKeyState(VK_NUMPAD2)) { limit = 600; limit2 = 400; }
		if (GetAsyncKeyState(VK_NUMPAD3)) { limit = 800; limit2 = 600; }
		if (GetAsyncKeyState(VK_NUMPAD4)) { limit = 1000; limit2 = 800; }
		if (GetAsyncKeyState(VK_NUMPAD5)) { limit = 1200; limit2 = 1000; }
		if (GetAsyncKeyState(VK_NUMPAD6)) { limit = 1400; limit2 = 1200; }

		DWORD64 Sc = Interfexp1;
		for (DWORD i = 0+limit2; i < limit; i++) {
			Ioffh = 0;
			Ioffh = step1*i;
			DWORD64 Hold = Sc + Ioffh;

			//directly points to other array//first is bool
			BYTE B = VirtPReadByte(Hold);
			DWORD64 DataArray = VirtPRead64(Hold + 0x8);
			//cout << hex << DataArray <<endl;



			//active check
			DWORD bb3 = VirtPReadDword(DataArray + Ioff555);
			DWORD bb4 = VirtPReadDword(DataArray + Ioff666);
			DWORD64 check = VirtPRead64(DataArray+0x10);
			if ((bb3 > 0 && bb3 < 4) && (bb4 > 0 && bb4 < 3)&& check == DataArray) {
				//cout << "ok1" << "\n";
				//coords
				FLOAT bb1 = VirtPReadWord(DataArray + Ioff11);
				FLOAT bb2 = VirtPReadWord(DataArray + Ioff22);

				if (bb1 < 4000.f && bb2 < 4000.f) {
					//FLOAT bb3 = VirtPReadWord(DataArray + off33);
					//FLOAT bb4 = VirtPReadWord(DataArray + off44);
					FLOAT bb3 = VirtPReadWord(DataArray + Ioff332);
					FLOAT bb4 = VirtPReadWord(DataArray + Ioff442);
					BYTE bb33 = VirtPReadByte(DataArray + Ioffhhh);
					WORD bb5 = VirtPReadWord(DataArray + Ioff55);
					WORD bb7 = VirtPReadWord(DataArray + Ioff55 + 4);
					WORD bb8 = VirtPReadWord(DataArray + Ioff55 + 6);
					WORD bb9 = VirtPReadWord(DataArray + Ioff55 + 8);
					DWORD64 placeholder = VirtPRead64(DataArray + Ioff00)+0xc;
					string s = VirtPReadChar(placeholder);
					InterName.push_back(s);
					//if (bb3 == 0 && bb4 == 0) { opend = FALSE; }
					//else { opend = TRUE; }

					InterfX.push_back(bb1);
					InterfY.push_back(bb2);
					InterfXs11.push_back(bb3);
					InterfYs11.push_back(bb4);
					InterfID.push_back(bb5);
					InterfID2.push_back(bb7);
					InterfID3.push_back(bb8);
					InterfID4.push_back(bb9);
					InterfAct.push_back(B);
					InterfHov.push_back(bb33);
					InterfMem.push_back(Sc + Ioffh);

					//directly points to other array
					//DWORD64 placeholder = VirtPRead64(DataArray + Itimeroff);
					//timer!!/dosent wor, sometimes :I
					//DWORD OtherT = VirtPReadDword(placeholder + Itimeroff2);
					//InterfTimer.push_back(OtherT);




				}
			}
		}
	}
}

//screen click filter/tries to filter out interfaces so it dosen't click on them
BOOLEAN ScreenFilter(WPOINT mxy)
{
	vector<WPOINT>SFxy;
	vector<WPOINT>SFxysize;
	vector<string>SFxytest;
	WPOINT p = GetRsResolution2();

	if (mxy.x > 0 && mxy.y > 0 && mxy.x < p.x && mxy.y < p.y) {
		
		//inventory box
		if (InterfCheck(InvBoxMemoryLoc, 1477, 107, 0xffff, 44)) {
			InterfaceComp2 data = GetInterfaceData2(InvBoxMemoryLoc);
			SFxy.push_back(data.xy);
			SFxysize.push_back(data.xys);
			SFxytest.push_back("InvBox");
		}
		else {
			cout << "InvBox" << endl;
			InvBoxMemoryLoc = Locateinterface(1477, 107, 0xffff, 44);
		}
		
		//equipment box
		if (InterfCheck(EqBoxMemoryLoc, 1477, 189, 0xffff, 44)) {
			InterfaceComp2 data = GetInterfaceData2(EqBoxMemoryLoc);
			SFxy.push_back(data.xy);
			SFxysize.push_back(data.xys);
			SFxytest.push_back("Eqbox");
		}
		else {
			cout << "Eqbox" << endl;
			EqBoxMemoryLoc = Locateinterface(1477, 189, 0xffff, 44);
		}
		//prayer box
		if (InterfCheck(PrayBoxMemoryLoc, 1477, 211, 0xffff, 44)) {
			InterfaceComp2 data = GetInterfaceData2(PrayBoxMemoryLoc);
			SFxy.push_back(data.xy);
			SFxysize.push_back(data.xys);
			SFxytest.push_back("Praybox");
		}
		else {
			cout << "Praybox" << endl;
			PrayBoxMemoryLoc = Locateinterface(1477, 211, 0xffff, 44);
		}
		//song list box
		if (InterfCheck(SongBoxMemoryLoc, 1477, 386, 0xffff, 44)) {
			InterfaceComp2 data = GetInterfaceData2(SongBoxMemoryLoc);
			SFxy.push_back(data.xy);
			SFxysize.push_back(data.xys);
			SFxytest.push_back("SongsBox");
		}
		else {
			cout << "SongsBox" << endl;
			SongBoxMemoryLoc = Locateinterface(1477, 386, 0xffff, 44);
		}
		//map box
		if (InterfCheck(MapBoxMemoryLoc, 1477, 87, 0xffff, 44)) {
			InterfaceComp2 data = GetInterfaceData2(MapBoxMemoryLoc);
			SFxy.push_back(data.xy);
			SFxysize.push_back(data.xys);
			SFxytest.push_back("MapBox");
		}
		else {
			cout << "MapBox" << endl;
			MapBoxMemoryLoc = Locateinterface(1477, 87, 0xffff, 44);
			//cout << hex << MapBoxMemoryLoc <<endl;
		}		
		//text box
		if (InterfCheck(ChatBoxMemoryLoc, 1477, 118, 0xffff, 44)) {
			InterfaceComp2 data = GetInterfaceData2(ChatBoxMemoryLoc);
			SFxy.push_back(data.xy);
			SFxysize.push_back(data.xys);
			SFxytest.push_back("ChatBox");
		}
		else {
			cout << "ChatBox" << endl;
			ChatBoxMemoryLoc = Locateinterface(1477, 118, 0xffff, 44);
			//cout << hex << ChatBoxMemoryLoc << endl;
		}
		//ability box
		if (InterfCheck(AbilBoxMemoryLoc, 1477, 62, 0xffff, 44)) {
			InterfaceComp2 data = GetInterfaceData2(AbilBoxMemoryLoc);
			SFxy.push_back(data.xy);
			SFxysize.push_back(data.xys);
			SFxytest.push_back("AbilityBox");
		}
		else {
			cout << "AbilityBox" << endl;
			AbilBoxMemoryLoc = Locateinterface(1477, 62, 0xffff, 44);
		}
		//menuicons box
		if (InterfCheck(MIBoxMemoryLoc, 1477, 45, 0xffff, 44)) {
			InterfaceComp2 data = GetInterfaceData2(MIBoxMemoryLoc);
			SFxy.push_back(data.xy);
			SFxysize.push_back(data.xys);
			SFxytest.push_back("Menuicons");
		}
		else {
			cout << "Menuicons" << endl;
			MIBoxMemoryLoc = Locateinterface(1477, 45, 0xffff, 44);
		}
		//get members box
		if (InterfCheck(MembBoxMemoryLoc, 1477, 743, 0xffff, 18)) {
			InterfaceComp2 data = GetInterfaceData2(MembBoxMemoryLoc);
			SFxy.push_back(data.xy);
			SFxysize.push_back(data.xys);
			SFxytest.push_back("Memb");
		}
		else {
			cout << "MembersBox" << endl;
			MembBoxMemoryLoc = Locateinterface(1477, 743, 0xffff, 18);
		}
		//get treasure hunter box                       0xffff overlay
		//if (InterfCheck(THBoxMemoryLoc, 1252, 5, 0xffff, 0)) {
		//	InterfaceComp2 data = GetInterfaceData2(THBoxMemoryLoc);
		//	SFxy.push_back(data.xy);
		//	SFxysize.push_back(data.xys);
		//	//SFxytest.push_back("thbox");
		//}
		//else {
		//	cout << "THbox" << endl;
		//	THBoxMemoryLoc = Locateinterface(1252, 5, 0xffff, 0);
		//}
		//menopaus box
		/*
		if (InterfCheck(MenoBoxMemoryLoc, 1477, 104, 0xffff, 19)) {
			InterfaceComp2 data = GetInterfaceData2(MenoBoxMemoryLoc);
			SFxy.push_back(data.xy);
			SFxysize.push_back(data.xys);
		}
		else {
			MenoBoxMemoryLoc = Locateinterface(1477, 104, 0xffff, 19);
		}
		//skill ring things
		if (InterfCheck(SkillRingBoxMemoryLoc, 1477, 104, 0xffff, 19)) {
			InterfaceComp2 data = GetInterfaceData2(SkillRingBoxMemoryLoc);
			SFxy.push_back(data.xy);
			SFxysize.push_back(data.xys);
		}
		else {
			SkillRingBoxMemoryLoc = Locateinterface(1477, 104, 0xffff, 19);
		}
		*/
		//Treasure hunter open or skills open? erm boolean thing to do

		//loop 
		for (DWORD i = 0; i < SFxy.size(); i++) {
			//x dosen't require any adding//mark inside box
			if(mxy.x>SFxy[i].x && mxy.x<(SFxy[i].x + SFxysize[i].x)){
			if(mxy.y>SFxy[i].y && mxy.y<(SFxy[i].y + SFxysize[i].y)){
				//cout << dec << mxy.x << ":" << mxy.y << endl;
//cout<<dec<<SFxy[i].x<<":"<< SFxysize[i].x <<":"<< SFxy[i].y <<":"<< (SFxy[i].y + SFxysize[i].y) << endl;
				//cout << SFxytest[i] << endl;
					return FALSE;
				}}
		}}
else {
	//cout << dec << mxy.x << ":" << mxy.y << endl;
	//cout << "Out of range" << endl;
	return FALSE;
}
//cout << "End" << endl;
	return TRUE;
}

//interfaces debug//IF2//text//secondary
VOID ReadInterf2()
{
	InterfX2.clear();
	InterfY2.clear();
	InterfXs2.clear();
	InterfYs2.clear();
	InterfXs22.clear();
	InterfYs22.clear();
	InterfID12.clear();
	InterfID22.clear();
	InterfID32.clear();
	InterfID42.clear();
	InterfAct2.clear();
	InterfHov2.clear();
	InterfMem2.clear();
	InterName2.clear();
	InterfTimer2.clear();

	INT limit = 0;
	//
	DWORD I2offh = 0;
	//DWORD I2off1 = 0x38;
	BOOLEAN opend = FALSE;
	MEMss BlockA;

	
	if (!INVIArr.empty()) {
		for (DWORD i5 = 0; i5 < INVIArr.size(); i5++) {
			//limit = BlockA.size / I2off2;
			limit = 25000;
			DWORD64 Sc = INVIArr[i5] - I2off2*(limit / 2);
			for (DWORD i = 0; i < limit; i++) {
				I2offh = I2offh + I2off2;
				DWORD64 Hold = Sc + I2offh;

				//active check
				DWORD bb3 = VirtPReadDword(Hold + I2off555);
				DWORD bb4 = VirtPReadDword(Hold + I2off666);
				if ((bb3 > 0 && bb3 < 4) && (bb4 > 0 && bb4 < 3)) {
					//cout << "ok1" << "\n";
					//coords
					FLOAT bb1 = VirtPReadWord(Hold + I2off11);
					FLOAT bb2 = VirtPReadWord(Hold + I2off22);

					if (bb1 < 4000.f && bb2 < 4000.f) {
						//FLOAT bb3 = VirtPReadWord(Sc + offh + off33);
						//FLOAT bb4 = VirtPReadWord(Sc + offh + off44);
						FLOAT bb3 = VirtPReadWord(Hold + I2off332);
						FLOAT bb4 = VirtPReadWord(Hold + I2off442);
						//BYTE bb34 = VirtPReadByte(Sc + I2offh + 0x3e1);
						BYTE bb33 = VirtPReadByte(Hold + Ioffhhh2);
						WORD bb5 = VirtPReadWord(Hold + I2off55);
						WORD bb7 = VirtPReadWord(Hold + I2off55 + 4);
						WORD bb8 = VirtPReadWord(Hold + I2off55 + 6);
						WORD bb9 = VirtPReadWord(Hold + I2off55 + 8);
						DWORD64 placeholder2 = VirtPRead64(Hold + Ioff00);
						//string s = VirtPReadChar(placeholder2);
						if (bb3 == 0 && bb4 == 0) { opend = FALSE; }
						else { opend = TRUE; }

						//cout << "ok2" << "\n";
						InterfX2.push_back(bb1);
						InterfY2.push_back(bb2);
						InterfXs22.push_back(bb3);
						InterfYs22.push_back(bb4);
						InterfID12.push_back(bb5);
						InterfID22.push_back(bb7);
						InterfID32.push_back(bb8);
						InterfID42.push_back(bb9);
						InterfAct2.push_back(opend);
						InterfHov2.push_back(bb33);
						InterfMem2.push_back(Sc + I2offh);
						//InterName2.push_back(s);


						//directly points to other array
						DWORD64 placeholder = VirtPRead64(Hold + I2timeroff);
						//timer!!
						DWORD OtherT = VirtPReadDword(placeholder + 0x158);
						InterfTimer2.push_back(OtherT);

					}
				}
			}


		}
	}
}

//active rs objects
VOID ReadObjectsAArrays()
{

	//ObjectsX.clear();
	//ObjectsY.clear();

	ObjectsXf.clear();
	ObjectsYf.clear();
	ObjectsID.clear();
	ObjectsIDu.clear();
	ObjectsMem.clear();
	Objectsxmid.clear();
	Objectsymid.clear();
	Objectsxsize.clear();
	Objectsxsize.clear();

	INT limit = 0;
	//
	//DWORD off1 = 0x82;

	//dif//step
	DWORD off2 = 0x300;
	DWORD offh = 0;
	//y
	DWORD off11 = 0x15c;
	//x
	DWORD off22 = 0x160;
	//ids
	DWORD off33 = 0x198;
	//ids unique
	DWORD off44 = 0x118;
	//choped down boolean
	DWORD off77 = 0x17d;
	//activ
	DWORD off55 = 0x8;
	DWORD off66 = 0xc;
	//xm
	DWORD offxm = 0x88;
	//ym
	DWORD offym = 0x8c;
	//xs
	DWORD offxs = 0x80;
	//ys
	DWORD offys = 0x90;
	WORD resy = GetRsResolution2().y;
	MEMss BlockA;

	if (OB != NULL) {
		BlockA = DeterMemoryBlockLenght(OB);
		//cout << hex << BlockA.start+BlockA.size<<endl;
		//MemoryInfo(OB);
		limit = 2000;
		//printf("limit: %d\n", limit);
		if (GetAsyncKeyState(VK_NUMPAD0)) { limit = limit / 2; }
		if (GetAsyncKeyState(VK_NUMPAD1)) { limit = limit / 3; }
		if (GetAsyncKeyState(VK_NUMPAD2)) { limit = limit / 4; }
		if (GetAsyncKeyState(VK_NUMPAD3)) { limit = limit / 5; }
		if (GetAsyncKeyState(VK_NUMPAD4)) { limit = limit / 6; }
		if (GetAsyncKeyState(VK_NUMPAD5)) { limit = limit / 7; }
		if (GetAsyncKeyState(VK_NUMPAD6)) { limit = limit / 8; }
		if (GetAsyncKeyState(VK_NUMPAD7)) { limit = limit / 9; }
		if (GetAsyncKeyState(VK_NUMPAD8)) { limit = limit / 10; }
		if (GetAsyncKeyState(VK_NUMPAD9)) { limit = limit / 11; }

		DWORD64 Sc = OB - off2*(limit / 2);
		for (DWORD i = 0; i < limit; i++) {
			offh = offh + off2;
			if ((Sc + offh) > BlockA.start) {
				//if ((Sc + offh) < (BlockA.start + 0x1591000)) {
					//printf("ok0:\n");
					//test
					BYTE bb5 = VirtPReadByte(Sc + offh + off77);

					if (bb5 == 0) {
						//active check
						BYTE b3 = VirtPReadByte(Sc + offh + off55);
						BYTE b4 = VirtPReadByte(Sc + offh + off66);
						if ((b3 > 0 && b3 < 9) && (b4 > 0 && b4 < 9)) {
							//printf("ok0:\n");
							//coords
							WORD bb1 = VirtPReadWord(Sc + offh + off11);
							WORD bb2 = VirtPReadWord(Sc + offh + off22);
							if (bb2 != NULL && bb1 != NULL) {
								//printf("ok1:\n");
								if (CheckVisibleLimit2(bb1, bb2)) {
									//printf("ok2:\n");
									ObjectsXf.push_back(bb1*512.f);
									ObjectsYf.push_back(bb2*512.f);
									DWORD bb3 = VirtPReadDword(Sc + offh + off33);
									DWORD bb4 = VirtPReadDword(Sc + offh + off44);
									if (bb3 == 0xffffffff) { bb3 = 0; }
									if (bb4 == 0xffffffff) { bb3 = 0; }
									ObjectsID.push_back(bb3);
									ObjectsIDu.push_back(bb4);
									ObjectsMem.push_back(Sc + offh);

									WORD xm = VirtPReadWord(Sc + offh + offxm);
									WORD ym = VirtPReadWord(Sc + offh + offym);
									WORD xsize = VirtPReadWord(Sc + offh + offxs);
									WORD ysize = VirtPReadWord(Sc + offh + offys);

									Objectsxmid.push_back(xm);
									Objectsymid.push_back(resy - ym);
									Objectsxsize.push_back(xsize);
									Objectsysize.push_back(ysize);
								}
							}
						}
					}
				}
			}
		}
	//}
}

//decor rs objects
VOID ReadDecorObj()
{


	DecorXf.clear();
	DecorYf.clear();
	DecorID.clear();
	DecorMem.clear();
	Decorxmid.clear();
	Decorymid.clear();

	INT limit = 0;
	//
	//DWORD off1 = 0x82;

	//dif//step
	DWORD off2 = 0x138;
	DWORD offh = 0;
	//y
	DWORD off11 = 0x10c;
	//x
	DWORD off22 = 0x110;
	//ids
	DWORD off33 = 0x118;
	//ids unique
	//DWORD off44 = 0x118;
	//choped down boolean
	//DWORD off77 = 0x17d;
	//activ
	DWORD off55 = 0x8;
	DWORD off66 = 0xc;
	//xm
	DWORD offxm = 0x88;
	//ym
	DWORD offym = 0x8c;
	WORD resy = GetRsResolution2().y;
	MEMss BlockA;

	if (DOB2 != NULL) {
		BlockA = DeterMemoryBlockLenght(DOB2);
		//cout << hex << BlockA.start+BlockA.size<<endl;
		//MemoryInfo(OB);
		limit = 10000;
		//printf("limit: %d\n", limit);
		if (GetAsyncKeyState(VK_NUMPAD0)) { limit = limit / 2; }
		if (GetAsyncKeyState(VK_NUMPAD1)) { limit = limit / 3; }
		if (GetAsyncKeyState(VK_NUMPAD2)) { limit = limit / 4; }
		if (GetAsyncKeyState(VK_NUMPAD3)) { limit = limit / 5; }
		if (GetAsyncKeyState(VK_NUMPAD4)) { limit = limit / 6; }
		if (GetAsyncKeyState(VK_NUMPAD5)) { limit = limit / 7; }
		if (GetAsyncKeyState(VK_NUMPAD6)) { limit = limit / 8; }
		if (GetAsyncKeyState(VK_NUMPAD7)) { limit = limit / 9; }
		if (GetAsyncKeyState(VK_NUMPAD8)) { limit = limit / 10; }
		if (GetAsyncKeyState(VK_NUMPAD9)) { limit = limit / 11; }

		DWORD64 Sc = DOB2 - off2*(limit / 2);
		for (DWORD i = 0; i < limit; i++) {
			offh = offh + off2;
			if ((Sc + offh) > BlockA.start) {
				//BYTE bb5 = VirtPReadByte(Sc + offh + off77);

					//active check
					BYTE b3 = VirtPReadByte(Sc + offh + off55);
					BYTE b4 = VirtPReadByte(Sc + offh + off66);
					if ((b3 > 0 && b3 < 9) && (b4 > 0 && b4 < 9)) {
						//printf("ok0:\n");
						//coords
						WORD bb1 = VirtPReadWord(Sc + offh + off11);
						WORD bb2 = VirtPReadWord(Sc + offh + off22);
						if (bb2 != NULL && bb1 != NULL) {
							//printf("ok1:\n");
							if (CheckVisibleLimit2(bb1, bb2)) {
								//printf("ok2:\n");


						    	DecorXf.push_back(bb1*512.f);
						    	DecorYf.push_back(bb2*512.f);
								//DWORD bb3 = VirtPReadDword(Sc + offh + off33);

								//directly points to other array! where is id written
								DWORD64 placeholder = VirtPRead64(Sc + offh + off33);
								//now read that id from other array
								DWORD OtherID = VirtPReadDword(placeholder + 0x40);

								DecorID.push_back(OtherID);
								DecorMem.push_back(Sc + offh);
								WORD xm = VirtPReadWord(Sc + offh + offxm);
								WORD ym = VirtPReadWord(Sc + offh + offym);
								Decorxmid.push_back(xm);
								Decorymid.push_back(resy - ym);

							}
						}
						}}}}}

//read varpbit directly
VB ReadBits(DWORD64 bitaddr){

	DWORD id = VirtPReadDword(bitaddr - 0x10);
	DWORD state = VirtPReadDword(bitaddr + 0x20);
	return{state,id};
}

//settings test reads//varpbits
VOID SettingTest()
{
	SettingsAddr.clear();
	SettingsId.clear();
	SettingsState.clear();
	            //176000
	WORD limit1 = 2000;
	WORD limit2 = 4000;

	//dif//step
	DWORD off1 = 0x80;
	DWORD off2 = 0x58;
	DWORD offh = 0;

	MEMss BlockA;

	//cout << VarBits1.size() << endl;
	if (!VarBits1.empty()) {
		for (DWORD i = 0; i < VarBits1.size(); i++) {
			offh = 0;
			DWORD64 Sc = VarBits1[i] - off1*(limit1 / 2);
			for (DWORD ii = 0; ii < limit1; ii++) {
				offh = offh + off1;
				DWORD64 Hold = Sc + offh;
				BYTE v1 = VirtPReadByte(Hold - 0x21);
				DWORD v2 = VirtPReadDword(Hold);
				//DWORD64 v3 = VirtPRead64(Sc + offh - 0x20);
				if (
					v1 == 0x91
					&&
					v2 == 0x3ea
				//	&&
					//v3 == 1
					) {
					DWORD id = VirtPReadDword(Hold - 0x10);
					if (id > 10 && id<9000) {
						SettingsAddr.push_back(Hold);
						SettingsId.push_back(id);
						DWORD state = VirtPReadDword(Hold + 0x20);
						SettingsState.push_back(state);
					}

				}
			}
		}
	}

	//cout << VarBits2.size() << endl;
	if (!VarBits2.empty()) {
		for (DWORD i = 0; i < VarBits2.size(); i++) {
			offh = 0;
			DWORD64 Sc = VarBits2[i] - off2*(limit2 / 2);
			for (DWORD ii = 0; ii < limit2; ii++) {
				offh = offh + off2;
				DWORD64 Hold = Sc + offh;
				//BYTE v1 = VirtPReadByte(Hold - 0x21);
				DWORD v2 = VirtPReadDword(Hold);
				//DWORD64 v3 = VirtPRead64(Sc + offh - 0x20);
				if (
					//v1 == 0x91
					//&&
					v2 == 0x3ea
					//	&&
					//v3 == 1
					) {
					DWORD id = VirtPReadDword(Hold - 0x10);
					if (id > 10 && id < 9000) {
						SettingsAddr.push_back(Hold);
						SettingsId.push_back(id);
						DWORD state = VirtPReadDword(Hold + 0x20);
						SettingsState.push_back(state);
					}
				}
			}
		}
	}


}

//decor rs objects//old
VOID ReadObjectsDArrays2()
{
	ObjectsXfd.clear();
	ObjectsYfd.clear();
	ObjectsIDd.clear();
	ObjectsIDd2.clear();
	ObjectsIDd3.clear();

	INT limit = 0;
	//
	DWORD off1 = 0x39;
	//dif
	DWORD off2 = 0x138;
	DWORD offh = 0;
	//y
	DWORD off11 = 0x10c;
	//x
	DWORD off22 = 0x110;
	//ids
	DWORD off33 = 0x128;
	//ids 2
	DWORD off44 = 0x12c;
	MEMss BlockA;

	if (DOB != NULL) {
		BlockA = DeterMemoryBlockLenght(DOB);

		limit = BlockA.size / off2 - 1;
		//printf("limit: %d\n", limit);
		if (GetAsyncKeyState(VK_NUMPAD0)) { limit = limit / 2; }
		if (GetAsyncKeyState(VK_NUMPAD1)) { limit = limit / 3; }
		if (GetAsyncKeyState(VK_NUMPAD2)) { limit = limit / 4; }
		if (GetAsyncKeyState(VK_NUMPAD3)) { limit = limit / 5; }
		if (GetAsyncKeyState(VK_NUMPAD4)) { limit = limit / 6; }
		if (GetAsyncKeyState(VK_NUMPAD5)) { limit = limit / 7; }
		if (GetAsyncKeyState(VK_NUMPAD6)) { limit = limit / 8; }
		if (GetAsyncKeyState(VK_NUMPAD7)) { limit = limit / 9; }
		if (GetAsyncKeyState(VK_NUMPAD8)) { limit = limit / 10; }
		if (GetAsyncKeyState(VK_NUMPAD9)) { limit = limit / 11; }

		DWORD64 Sc = DOB + off1 - off2;
		for (DWORD i = 0; i < limit; i++) {
			offh = offh + off2;

			WORD bb1 = VirtPReadWord(Sc + offh + off11);
			//printf("objtile1: %I64X\n", bb1);

			WORD bb2 = VirtPReadWord(Sc + offh + off22);
			//printf("objtile2: %I64X\n", bb2);

			if (bb2 != NULL && bb1 != NULL) {
				//printf("ok1:\n");
				if (CheckVisibleLimit2(bb1, bb2)) {
				//	printf("ok2:\n");

					//ObjectsX.push_back(bb1);
					//  ObjectsY.push_back(bb2);
					ObjectsXfd.push_back(bb1*512.f);
					ObjectsYfd.push_back(bb2*512.f);
					DWORD bb3 = VirtPReadDword(Sc + offh + off33);
					DWORD64 bb5 = VirtPRead64(Sc + offh + off33);
					DWORD bb4 = VirtPReadDword(Sc + offh + off44);
					if (bb3 == 0xffffffff) { bb3 = 0; }
					ObjectsIDd.push_back(bb3);
					ObjectsIDd2.push_back(bb4);
					ObjectsIDd3.push_back(bb5);
				}
			}
		}
		//if (!ObjectsX.empty()) {
		//	cout << ObjectsX.size() << "\n";}
	}
}

//projectiles rs //old
VOID ReadProjectiles()
{
	ProXf.clear();
	ProYf.clear();
	ProID.clear();
	Proxmid.clear();
	Proymid.clear();
	ProMem.clear();

	INT limit = 0;
	//
	//DWORD off1 = 0x82;

	//dif//step
	DWORD off2 = 0x1c8;
	DWORD offh = 0;
	//y
	DWORD off11 = 0x10c;
	//x
	DWORD off22 = 0x110;
	//ids
	DWORD off33 = 0x118;
	//ids unique
	//DWORD off44 = 0x118;
	//choped down boolean
	//DWORD off77 = 0x17d;
	//activ
	DWORD off55 = 0x8;
	DWORD off66 = 0xc;
	//xm
	DWORD offxm = 0x88;
	//ym
	DWORD offym = 0x8c;
	WORD resy = GetRsResolution2().y;
	MEMss BlockA;

	if (PRO != NULL) {
		BlockA = DeterMemoryBlockLenght(PRO);
		//cout << hex << BlockA.start+BlockA.size<<endl;
		//MemoryInfo(OB);
		limit = 4000;
		//printf("limit: %d\n", limit);
		if (GetAsyncKeyState(VK_NUMPAD0)) { limit = limit / 2; }
		if (GetAsyncKeyState(VK_NUMPAD1)) { limit = limit / 3; }
		if (GetAsyncKeyState(VK_NUMPAD2)) { limit = limit / 4; }
		if (GetAsyncKeyState(VK_NUMPAD3)) { limit = limit / 5; }
		if (GetAsyncKeyState(VK_NUMPAD4)) { limit = limit / 6; }
		if (GetAsyncKeyState(VK_NUMPAD5)) { limit = limit / 7; }
		if (GetAsyncKeyState(VK_NUMPAD6)) { limit = limit / 8; }
		if (GetAsyncKeyState(VK_NUMPAD7)) { limit = limit / 9; }
		if (GetAsyncKeyState(VK_NUMPAD8)) { limit = limit / 10; }
		if (GetAsyncKeyState(VK_NUMPAD9)) { limit = limit / 11; }

		DWORD64 Sc = PRO - off2*(limit / 2);
		for (DWORD i = 0; i < limit; i++) {
			offh = offh + off2;
			if ((Sc + offh) > BlockA.start) {
				//BYTE bb5 = VirtPReadByte(Sc + offh + off77);

				//active check
				BYTE b3 = VirtPReadByte(Sc + offh + off55);
				BYTE b4 = VirtPReadByte(Sc + offh + off66);
				if ((b3 > 0 && b3 < 9) && (b4 > 0 && b4 < 9)) {
					//printf("ok0:\n");
					//coords
					//WORD bb1 = VirtPReadWord(Sc + offh + off11);
					//WORD bb2 = VirtPReadWord(Sc + offh + off22);
					//if (bb2 != NULL && bb1 != NULL) {
						//printf("ok1:\n");
						//if (CheckVisibleLimit2(bb1, bb2)) {
							//printf("ok2:\n");


							//ProXf.push_back(bb1*512.f);
							//ProYf.push_back(bb2*512.f);
							//DWORD bb3 = VirtPReadDword(Sc + offh + off33);

							//directly points to other array! where is id written
							//DWORD64 placeholder = VirtPRead64(Sc + offh + off33);
							//now read that id from other array
							//DWORD OtherID = VirtPReadDword(placeholder + 0x40);

							//DecorID.push_back(OtherID);
							ProMem.push_back(Sc + offh);
							WORD xm = VirtPReadWord(Sc + offh + offxm);
							WORD ym = VirtPReadWord(Sc + offh + offym);
							Proxmid.push_back(xm);
							Proymid.push_back(resy - ym);

						//}}
				}
			}
		}
	}
}

///All screenobjects
VOID ReadCObjArrays()
{

	ObjX.clear();
	ObjY.clear();
	ObjID.clear();
	ObjAddrXY.clear();	
	ObjExtra.clear();
	TypeByte.clear();
	ViewPartialPl.clear();
	ViewFullPl.clear();
	ViewPartialNPC.clear();
	ViewFullNPC.clear();
	ViewPartialObjects.clear();
	ViewFullObjects.clear();
	ViewPartialDecor.clear();
	ViewFullDecor.clear();
	ViewPartialGI.clear();
	ViewFullGI.clear();
	//
	PlX.clear();
	PlY.clear();
	PlZ.clear();
	PlID.clear();
	PlLife.clear();
	PlAnim.clear();
	PlMem.clear();
	PlFloor.clear();
	PlTouched.clear();
	PlPraytype.clear();
	PlName.clear();
	Plxmid.clear();
	Plymid.clear();
	//
	NPCX.clear();
	NPCY.clear();
	NPCZ.clear();
	NPCID.clear();
	NPCMem.clear();
	NPCLife.clear();
	NPCAnim.clear();
	NPCName.clear();
	NPCFloor.clear();
	NPCTouched.clear();
	NPCProtOn.clear();
	NPCPraytype.clear();
	NPCxmid.clear();
	NPCymid.clear();
	NPCxsize.clear();
	NPCysize.clear();
	NPCstate.clear();
	//
	ObjectsXf.clear();
	ObjectsYf.clear();
	ObjectsID.clear();
	ObjectsIDu.clear();
	ObjectsMem.clear();
	Objectsxmid.clear();
	Objectsymid.clear();
	Objectsxsize.clear();
	Objectsxsize.clear();
	ObjectsName.clear();
	ObjectsAction1.clear();
	//
	DecorXf.clear();
	DecorYf.clear();
	DecorID.clear();
	DecorMem.clear();
	Decorxmid.clear();
	Decorymid.clear();
	DecorName.clear();
	//
	GIX2.clear();
	GIY2.clear();
	GIID2.clear();
	GIAM2.clear();
	GIFL2.clear();
	GIMem2.clear();
	GIxmid2.clear();
	GIymid2.clear();
	GIText2.clear();



	WORD resy = GetRsResolution2().y;
	char crc32Arr[31];
	BOOLEAN sw=false;
	BOOLEAN sw2 = false;
	INT limit =0;
	DWORD offh = 0;
	MEMss BlockA;

	if (ScAdd1 != NULL) {

		BlockA = DeterMemoryBlockLenght(ScAdd1);

		limit = BlockA.size / alloff2;
		//printf("limit: %d\n", limit);
		if (GetAsyncKeyState(VK_NUMPAD0)) { limit = limit / 2; }
		if (GetAsyncKeyState(VK_NUMPAD1)) { limit = limit / 3; }
		if (GetAsyncKeyState(VK_NUMPAD2)) { limit = limit / 4; }
		if (GetAsyncKeyState(VK_NUMPAD3)) { limit = limit / 5; }
		if (GetAsyncKeyState(VK_NUMPAD4)) { limit = limit / 6; }
		if (GetAsyncKeyState(VK_NUMPAD5)) { limit = limit / 7; }
		if (GetAsyncKeyState(VK_NUMPAD6)) { limit = limit / 8; }
		if (GetAsyncKeyState(VK_NUMPAD7)) { limit = limit / 9; }
		if (GetAsyncKeyState(VK_NUMPAD8)) { limit = limit / 10; }
		if (GetAsyncKeyState(VK_NUMPAD9)) { limit = limit / 11; }
		//if (GetAsyncKeyState(VK_MULTIPLY)) { sw = TRUE; }
		//if (GetAsyncKeyState(VK_DIVIDE)) { sw2 = TRUE; }

		                                //1 step back
		DWORD64 Sc = ScAdd1 + alloff1 - alloff2;
		for (DWORD i = 0; i < limit; i++) {
			offh = offh + alloff2;
			DWORD64 NextChunk = Sc + offh;
			FLOAT bb1 = VirtPReadFloat(NextChunk + alloff11);
			//printf("objtile1: %I64X\n", bb1);

			FLOAT bb2 = VirtPReadFloat(NextChunk + alloff22);
			//printf("objtile2: %I64X\n", bb2);

			//DWORD64 test1 = VirtPReadFloat(NextChunk + off2 + 0x8);
			//DWORD64 test2 = VirtPReadFloat(NextChunk + off2 + 0x10);
			//DWORD64 test3 = VirtPReadFloat(NextChunk + off2 + 0x18);
			//DWORD64 test4 = VirtPReadFloat(NextChunk + off2 + 0x20);



			//if (test1 != 0xffffffff && test2 != 0xffffffff && test3 != 0xffffffff && test4 != 0xffffffff) {
				if (bb2 > NULL && bb1 > NULL) {
					//printf("ok1:\n");
					if (CheckCoordLimit2(bb1, bb2)) {
						//printf("ok2:\n");
						for (DWORD i = 0; i < 32; i++) {
							char bb4 = VirtPReadByte(NextChunk + i + alloff44);
							crc32Arr[i] = bb4;
						}
						ObjAddrXY.push_back(NextChunk);
						ObjX.push_back(bb1 - 256.f);
						ObjY.push_back(bb2 - 256.f);
						//DWORD bb3 = VirtPReadDword(NextChunk + off33);
						ObjID.push_back(CRC32CheckSum(crc32Arr, 31, 0));
						//0x20 to top, could be used to find all array itself
						DWORD64 PlaceHolder = (VirtPRead64(NextChunk + alloff55) - 0x20);
						ObjExtra.push_back(PlaceHolder);
						//0x58 points back here
						//0x60 type
						DWORD Type = VirtPReadDword(PlaceHolder + 0x60);
						TypeByte.push_back(Type);
						DWORD www = VirtPReadDword(PlaceHolder + pa2);
						//if (www == 6) { cout << "found!!:" <<hex<< PlaceHolder << endl; }



						//player type ==2 
						if (Type == 2) {
							FLOAT bb1 = VirtPReadFloat(PlaceHolder + poff11);
							FLOAT bb2 = VirtPReadFloat(PlaceHolder + poff22);

							if (bb1 > 0.f && bb2 > 0.f) {

								BYTE active1 = VirtPReadByte(PlaceHolder + pa1);
								BYTE active2 = VirtPReadByte(PlaceHolder + pa2);
								if ((active1 > 0 && active1 < 4) && (active2 > 0 && active2 < 7)) {						
									//if (CheckVisibleLimit(bb1, bb2)) {
									string s = VirtPReadChar(PlaceHolder + poffname);
									PlName.push_back(s);
									PlMem.push_back(PlaceHolder);
									PlX.push_back(bb1 - 256.f);
									PlY.push_back(bb2 - 256.f);
									FLOAT b234 = VirtPReadFloat(PlaceHolder + poff11 + 4);
									PlZ.push_back(b234);
									DWORD bb66 = VirtPReadDword(PlaceHolder + poff66);
									DWORD bb777 = VirtPReadDword(PlaceHolder + ptest77);
									PlID.push_back(bb66);
									DWORD bb77 = VirtPReadDword(PlaceHolder + poff77);
									if (bb77 == 0xffffffff) { bb77 = 0; }
									PlLife.push_back(bb77);
									if (bb777 == 0xffffffff) { bb777 = 0; }
									PlAnim.push_back(bb777);
									BYTE Read = VirtPReadByte(PlaceHolder + poff88);
									PlFloor.push_back(Read);
									BYTE Read2 = VirtPReadByte(PlaceHolder + poff1111);
									PlPraytype.push_back(Read2); 
									                                         //same as npc
									WORD plxm = VirtPReadWord(PlaceHolder + npcoffxm);
									WORD plym = VirtPReadWord(PlaceHolder + npcoffym);
									Plxmid.push_back(plxm);
									Plymid.push_back(resy - plym);
									DWORD64 holder = VirtPRead64(PlaceHolder + alloff88);
									DWORD part = VirtPReadDword(holder + alloff66);
									BYTE full = VirtPReadByte(holder + alloff77);
									ViewPartialPl.push_back(part);
									ViewFullPl.push_back(full);
									//}
								//}
								}
							}
						}

						//npc type
						if (Type == 1) {
							FLOAT bb1 = VirtPReadFloat(PlaceHolder + npcoff11);
							FLOAT bb2 = VirtPReadFloat(PlaceHolder + npcoff22);
							if (bb1 > 0.f && bb2 > 0.f) {
								BYTE active1 = VirtPReadByte(PlaceHolder + npca1);
								BYTE active2 = VirtPReadByte(PlaceHolder + npca2);
								//1==is active but not on screen, 2 and higher (flickers!) active on screen
								if ((active1 > 0 && active1 < 4) && (active2 > 0 && active2 < 7)) {
									string s = VirtPReadChar(PlaceHolder + npcoffname);
									NPCName.push_back(s);
									NPCMem.push_back(PlaceHolder);
									NPCX.push_back(bb1 - 256.f);
									NPCY.push_back(bb2 - 256.f);
									FLOAT b234 = VirtPReadFloat(PlaceHolder + npcoff11 + 4);
									NPCZ.push_back(b234);
									DWORD bb66 = VirtPReadDword(PlaceHolder + npcoff66);
									NPCID.push_back(bb66);
									DWORD bb77 = VirtPReadDword(PlaceHolder + npcoff77);
									if (bb77 == 0xffffffff) { bb77 = 0; }
									NPCLife.push_back(bb77);
									DWORD bb777 = VirtPReadDword(PlaceHolder + npcoff33);
									if (bb777 == 0xffffffff) { bb777 = 0; }
									NPCAnim.push_back(bb777);
									BYTE Read = VirtPReadByte(PlaceHolder + npcoff88);
									NPCFloor.push_back(Read);

									WORD npcxm = VirtPReadWord(PlaceHolder + npcoffxm);
									WORD npcym = VirtPReadWord(PlaceHolder + npcoffym);
									WORD npcxsize = VirtPReadWord(PlaceHolder + npcoffxsize);
									WORD npcysize = VirtPReadWord(PlaceHolder + npcoffysize);

									NPCxmid.push_back(npcxm);
									NPCymid.push_back(resy - npcym);
									NPCxsize.push_back(npcxsize);
									NPCysize.push_back(npcysize);
									//some odd sync issue
									DWORD64 holder = VirtPRead64(PlaceHolder + alloff88);
									DWORD part = VirtPReadDword(holder + alloff66);
									BYTE full = VirtPReadByte(holder + alloff77);
							        ViewPartialNPC.push_back(part);
									ViewFullNPC.push_back(full);
									//}
								//}
								}
							}
						}

						//activ obj
						if (Type==0) {
							//test somekind boolean
							BYTE bb5 = VirtPReadByte(PlaceHolder + aooff77);
							if (bb5 == 0) {
								//active check
								BYTE b3 = VirtPReadByte(PlaceHolder + aooff55);
								BYTE b4 = VirtPReadByte(PlaceHolder + aooff66);
								if ((b3 > 0 && b3 < 9) && (b4 > 0 && b4 < 9)) {
									//printf("ok0:\n");
									//coords
									WORD bb1 = VirtPReadWord(PlaceHolder + aooff11);
									WORD bb2 = VirtPReadWord(PlaceHolder + aooff22);
									//if (bb2 != NULL && bb1 != NULL) {
										//printf("ok1:\n");
										//if (CheckVisibleLimit2(bb1, bb2)) {
											//printf("ok2:\n");
											ObjectsXf.push_back(bb1*512.f);
											ObjectsYf.push_back(bb2*512.f);
											DWORD bb3 = VirtPReadDword(PlaceHolder + aooff33);
											DWORD bb4 = VirtPReadDword(PlaceHolder + aooff44);
											if (bb3 == 0xffffffff) { bb3 = 0; }
											if (bb4 == 0xffffffff) { bb3 = 0; }
											ObjectsID.push_back(bb3);
											ObjectsIDu.push_back(bb4);
											ObjectsMem.push_back(PlaceHolder);
											//
											DWORD64 Placeholder2 = VirtPRead64(PlaceHolder + aooff33-0x10);
											//
											DWORD64 Placeholder3 = VirtPRead64(Placeholder2 + aoofftx);
											string s = VirtPReadChar(Placeholder3);
											ObjectsName.push_back(s);					
											string s2 = VirtPReadChar(Placeholder2 + aoofftx2);
											ObjectsAction1.push_back(s2);

											WORD xm = VirtPReadWord(PlaceHolder + aooffxm);
											WORD ym = VirtPReadWord(PlaceHolder + aooffym);
											WORD xsize = VirtPReadWord(PlaceHolder + aooffxs);
											WORD ysize = VirtPReadWord(PlaceHolder + aooffys);

											Objectsxmid.push_back(xm);
											Objectsymid.push_back(resy - ym);
											Objectsxsize.push_back(xsize);
											Objectsysize.push_back(ysize);
											DWORD64 holder = VirtPRead64(PlaceHolder + alloff88);
											DWORD part = VirtPReadDword(holder + alloff66);
											BYTE full = VirtPReadByte(holder + alloff77);
											ViewPartialObjects.push_back(part);
											ViewFullObjects.push_back(full);
										//}
									}
								}
							//}
						}

						//dec obj
						if (Type == 12) {
							//BYTE bb5 = VirtPReadByte(Sc + offh + off77);

							//active check
							BYTE b3 = VirtPReadByte(PlaceHolder + dooff55);
							BYTE b4 = VirtPReadByte(PlaceHolder + dooff66);
							if ((b3 > 0 && b3 < 9) && (b4 > 0 && b4 < 9)) {
								//printf("ok0:\n");
								//coords
								WORD bb1 = VirtPReadWord(PlaceHolder + dooff11);
								WORD bb2 = VirtPReadWord(PlaceHolder + dooff22);
								if (bb2 != NULL && bb1 != NULL) {
									//if (CheckVisibleLimit2(bb1, bb2)) {

										DecorXf.push_back(bb1*512.f);
										DecorYf.push_back(bb2*512.f);
										//DWORD bb3 = VirtPReadDword(Sc + offh + off33);

										//directly points to other array! where is id written
										DWORD64 Placeholder2 = VirtPRead64(PlaceHolder + dooff33);
										//now read that id from other array
										DWORD OtherID = VirtPReadDword(Placeholder2 + dooff44);
										//text test
										DWORD64 Placeholder3 = VirtPRead64(Placeholder2 + doofftx);
										string s = VirtPReadChar(Placeholder3);
										DecorName.push_back(s);
										DecorID.push_back(OtherID);
										DecorMem.push_back(PlaceHolder);
										WORD xm = VirtPReadWord(PlaceHolder + dooffxm);
										WORD ym = VirtPReadWord(PlaceHolder + dooffym);
										Decorxmid.push_back(xm);
										Decorymid.push_back(resy - ym);
										DWORD64 holder = VirtPRead64(PlaceHolder + alloff88);
										DWORD part = VirtPReadDword(holder + alloff66);
										BYTE full = VirtPReadByte(holder + alloff77);
										ViewPartialDecor.push_back(part);
										ViewFullDecor.push_back(full);

									//}
								}
							}
						}

						//grounditems
						if (Type == 3) {
							 
							BYTE bb5 = VirtPReadByte(PlaceHolder + goff6);
							BYTE bb6 = VirtPReadByte(PlaceHolder + goff7);
							//active check first
							if ((bb5 >0 && bb5 <5) && (bb6 >0 && bb6 <5)) {
								FLOAT bb1 = VirtPReadFloat(PlaceHolder + goff11);
								FLOAT bb2 = VirtPReadFloat(PlaceHolder + goff22);

								if (bb1 != NULL && bb2 != NULL) {
									//if (CheckVisibleLimit(bb1, bb2)) {

										//directly points to other array! where is id written
										DWORD64 Placeholder2 = VirtPRead64(PlaceHolder + goff33);
										//now read that id from other array
										DWORD OtherID = VirtPReadDword(Placeholder2 + gotherid);
										//amount
										BYTE OtherAM = VirtPReadByte(Placeholder2 + gotheram);


										BYTE bb34 = VirtPReadByte(PlaceHolder + goff5);
										WORD xm = VirtPReadWord(PlaceHolder + goffxm);
										WORD ym = VirtPReadWord(PlaceHolder + goffym);

										GIX2.push_back(bb1);
										GIY2.push_back(bb2);
										GIID2.push_back(OtherID);
										GIAM2.push_back(OtherAM);
										GIFL2.push_back(bb34);
										GIxmid2.push_back(xm);
										GIymid2.push_back(resy - ym);
										GIMem2.push_back(PlaceHolder);
										GIText2.push_back(GetItemText(OtherID));
										DWORD64 holder = VirtPRead64(PlaceHolder + alloff88);
										DWORD part = VirtPReadDword(holder + alloff66);
										BYTE full = VirtPReadByte(holder + alloff77);
										ViewPartialGI.push_back(part);
										ViewFullGI.push_back(full);

									//}
								}
							}
						}









					//}
				}
			}
		}
	}
} 

//max distance from player, array objects, ALL objects
BOOLEAN FindSObj(vector<DWORD> obj, BYTE maxdistance) {

	vector<FLOAT> MatchNPCsDist;
	vector<DWORD64> MatchNPCsMBlock;
	FFPOINT p = PlayerCoordFloatRaw();
	FLOAT min = 51200.f;
	//y
	DWORD off11 = 0x68;
	//x
	DWORD off22 = 0x70;
	//hover
	//DWORD off33 = 0x464;
	DWORD hover;
	DWORD hover2;

	//ReadCObjArrays();
	ReadCObjArrays();
	//add all matching ids to separate aray
	//as it should take milliseconds to go trough all, do distance aswell
	if (!obj.empty() && !ObjID.empty()) {
		for (DWORD ii = 0; ii < obj.size(); ii++) {
			for (DWORD i = 0; i < ObjID.size(); i++) {
				if (obj[ii] != NULL || ObjID[i] != NULL) {
					if (ObjID[i] == obj[ii]) {
						FLOAT dist = sqrt(pow(ObjX[i] - p.x, 2) + pow(ObjY[i] - p.y, 2));
						if (dist < maxdistance*512.f) {
							//cout << "Found \n";
							MatchNPCsDist.push_back(dist);
							MatchNPCsMBlock.push_back(ObjAddrXY[i]);
						}
					}
				}
			}
		}

				//smallest distance
				if (!MatchNPCsMBlock.empty() && !MatchNPCsDist.empty()) {
					//cout <<"objects matched"<< MatchNPCsMBlock.size() << "\n";
					for (DWORD i = 0; i < MatchNPCsMBlock.size(); i++) {
						cout <<"nr:"<< i <<": "<< hex << MatchNPCsMBlock[i] << "\n";
						if (MatchNPCsDist[i] < min) {
							if (MatchNPCsDist[i] >= 0.f && MatchNPCsDist[i] < 51200.f) {
								min = MatchNPCsDist[i];
							}
						}
					}
				}


		//pullout the smallest//click if hover
		if (!MatchNPCsMBlock.empty() && !MatchNPCsDist.empty()) {
			for (DWORD i = 0; i < MatchNPCsMBlock.size(); i++) {
				if (min == MatchNPCsDist[i]) {
					//cout << hex << MatchNPCsMBlock[i] << "\n";
					if (MatchNPCsDist[i]<(6.f*512.f)) {
						WPOINT screenp = TToScreen2({ VirtPReadFloat(MatchNPCsMBlock[i] + off11) - 256.f,VirtPReadFloat(MatchNPCsMBlock[i] + off22) - 256.f });
						if (ScreenFilter(screenp)) {
							screenp.x = screenp.x - 7; screenp.y = screenp.y -7;
							MoveMouse2(screenp.x, screenp.y, 14, 20);
							//hover = VirtPReadDword(MatchNPCsMBlock[i] + npcoff111);
							RandomSleep2(25, 550, 3000);
							//hover2 = VirtPReadDword(MatchNPCsMBlock[i] + npcoff111);
							//if (hover != hover2) {
							MouseLeftClick(50, 2000);
								return TRUE;
							//}
						}
					}
					else
					{
						WPOINT screenp = ToMapFFPOINT2({ VirtPReadFloat(MatchNPCsMBlock[i] + off11) - 256.f,VirtPReadFloat(MatchNPCsMBlock[i] + off22) - 256.f });
						if (screenp.x != 0 && screenp.y != 0) {
							screenp.x = screenp.x - 4; screenp.y = screenp.y - 4;
							MoveMouse2(screenp.x, screenp.y, 4, 4);
							RandomSleep2(25, 550, 3000);
							MouseRightClick(50, 2000);
							return TRUE;
						}
					}
				}
			}
		}
	}
	return FALSE;
}

// max distance from player, array objects, active
BOOLEAN FindAObj(vector<DWORD> obj, BYTE maxdistance, INT corx, INT cory,INT cormx, INT cormy, BOOLEAN usemap, BYTE action, string sidetext) {

	vector<FLOAT> MatchNPCsDist;
	vector<FLOAT> MatchNPCsDist2;
	vector<FLOAT> MatchNPCsDist3;
	vector<DWORD64> MatchNPCsMBlock;
	vector<DWORD64> MatchNPCsMBlock2;
	vector<DWORD> MatchNPCsTimer;
	vector<DWORD> MatchNPCsTimer2;
	FFPOINT p = PlayerCoordFloatRaw();
	GetWindowRect(WProcC, &rs);
	WORD resyt = rs.top;
	WORD resxl = rs.left;
	WORD resyy = GetRsResolution2().y;

	//cout << "test";
	ReadCObjArrays();
	//add all matching ids to separate aray
	//as it should take milliseconds to go trough all, do distance aswell
	if (!obj.empty() && !ObjectsID.empty()) {
		for (DWORD i1 = 0; i1 < obj.size(); i1++) {
			for (DWORD i2 = 0; i2 < ObjectsID.size(); i2++) {
				if (obj[i1] != NULL || ObjectsID[i2] != NULL) {
					if (ObjectsID[i2] == obj[i1]) {
						FLOAT dist = sqrt(pow(ObjectsXf[i2] - p.x, 2) + pow(ObjectsYf[i2] - p.y, 2)) + (0.1f*i2);
						if (dist < maxdistance*512.f) {
							MatchNPCsDist.push_back(dist);
							MatchNPCsDist2.push_back(dist);
							MatchNPCsMBlock.push_back(ObjectsMem[i2]);
							MatchNPCsTimer.push_back(ViewPartialObjects[i2]);
						}
					}
				}
			}
		}
		//sort first dist by distance size
		if (!MatchNPCsMBlock.empty()) {
			sort(MatchNPCsDist.begin(), MatchNPCsDist.end());

			//set memory blocks into order by dist and dist2
			for (DWORD i = 0; i < MatchNPCsDist.size(); i++) {
				for (DWORD ii = 0; ii < MatchNPCsDist2.size(); ii++) {
					if (MatchNPCsDist[i] == MatchNPCsDist2[ii]) {
						//should add closest memory block @ 0(first)
						MatchNPCsMBlock2.push_back(MatchNPCsMBlock[ii]);
						MatchNPCsDist3.push_back(MatchNPCsDist2[ii]);
						MatchNPCsTimer2.push_back(MatchNPCsTimer[ii]);
					}
				}
			}
		}

		BOOLEAN failed = FALSE;
		if (!MatchNPCsMBlock2.empty()) {
			for (DWORD i = 0; i < MatchNPCsMBlock2.size(); i++) {
				//try every block some (random) amount of times before moving onto next block
				for (DWORD loop = 0; loop < rand() % 5 + 1; loop++) {
					DWORD64 holder = VirtPRead64(MatchNPCsMBlock2[i] + alloff88);
					DWORD part = VirtPReadDword(holder + alloff66);
					if (MatchNPCsTimer2[i] != part) {
						WPOINT screenp = { VirtPReadWord(MatchNPCsMBlock2[i] + aooffxm), VirtPReadWord(MatchNPCsMBlock2[i] + aooffym) };
						screenp.y = resyy - screenp.y;
						if (ScreenFilter(screenp)) {
							screenp.x = screenp.x - 7 + corx + resxl;
							screenp.y = screenp.y - 7 + cory + resyt;
							if (action == 0) {
								MoveMouse2(screenp.x, screenp.y, 14, 20);
								RandomSleep2(25, 550, 3000);
								if (SideTextEq(sidetext)) {
									MouseLeftClick(50, 2000);
									return TRUE;
								}
							}
							if (action == 1) {
								MoveMouse2(screenp.x, screenp.y, 14, 20);
								RandomSleep2(25, 550, 3000);
								if (SideTextEq(sidetext)) {
									MouseRightClick(50, 2000);
									return TRUE;
								}
							}
							if (action == 2) {
								MoveMouse2(screenp.x, screenp.y, 14, 20);
								RandomSleep2(25, 550, 3000);
								if (SideTextEq(sidetext)) {
									return TRUE;
								}
							}
							if (action == 3) {
								return TRUE;
							}
						}
					}
				}
				//try minimap
				if (i < MatchNPCsMBlock2.size()) { failed = TRUE; }
			}
			if (failed == TRUE && usemap == TRUE) {
				WPOINT screenp = ToMapFFPOINT2({ VirtPReadWord(MatchNPCsMBlock2[0] + aooff11)*512.f,VirtPReadWord(MatchNPCsMBlock2[0] + aooff22)*512.f });
				if (screenp.x != 0 && screenp.y != 0) {
					screenp.x = screenp.x - 4 + cormx; screenp.y = screenp.y - 4 + cormy;
					MoveMouse2(screenp.x, screenp.y, 4, 4);
					RandomSleep2(25, 550, 3000);
					MouseLeftClick(50, 2000);
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}

// max distance from player, array decor
BOOLEAN FindDObj(vector<DWORD> obj, BYTE maxdistance, INT corx, INT cory, INT cormx, INT cormy, BOOLEAN usemap, BYTE action, string sidetext) {

	vector<FLOAT> MatchNPCsDist;
	vector<FLOAT> MatchNPCsDist2;
	vector<FLOAT> MatchNPCsDist3;
	vector<DWORD64> MatchNPCsMBlock;
	vector<DWORD64> MatchNPCsMBlock2;
	vector<DWORD> MatchNPCsTimer;
	vector<DWORD> MatchNPCsTimer2;
	FFPOINT p = PlayerCoordFloatRaw();
	GetWindowRect(WProcC, &rs);
	WORD resyt = rs.top;
	WORD resxl = rs.left;
	WORD resyy = GetRsResolution2().y;

	//cout << "test";
	//ReadDecorObj();
	ReadCObjArrays();
	//add all matching ids to separate aray
	//as it should take milliseconds to go trough all, do distance aswell
	if (!obj.empty() && !DecorID.empty()) {
		for (DWORD i1 = 0; i1 < obj.size(); i1++) {
			for (DWORD i2 = 0; i2 < DecorID.size(); i2++) {
				if (obj[i1] != NULL || DecorID[i2] != NULL) {
					if (DecorID[i2] == obj[i1]) {
						FLOAT dist = sqrt(pow(DecorXf[i2] - p.x, 2) + pow(DecorYf[i2] - p.y, 2)) + (0.1f*i2);
						if (dist < maxdistance*512.f) {
							MatchNPCsDist.push_back(dist);
							MatchNPCsDist2.push_back(dist);
							MatchNPCsMBlock.push_back(DecorMem[i2]);
							MatchNPCsTimer.push_back(ViewPartialDecor[i2]);
						}
					}
				}
			}
		}

		//sort first dist by distance size
		if (!MatchNPCsMBlock.empty()) {
			sort(MatchNPCsDist.begin(), MatchNPCsDist.end());

			//set memory blocks into order by dist and dist2
			for (DWORD i = 0; i < MatchNPCsDist.size(); i++) {
				for (DWORD ii = 0; ii < MatchNPCsDist2.size(); ii++) {
					if (MatchNPCsDist[i] == MatchNPCsDist2[ii]) {
						//should add closest memory block @ 0(first)
						MatchNPCsMBlock2.push_back(MatchNPCsMBlock[ii]);
						MatchNPCsDist3.push_back(MatchNPCsDist2[ii]);
						MatchNPCsTimer2.push_back(MatchNPCsTimer[ii]);
					}
				}
			}
		}


		BOOLEAN failed = FALSE;
		if (!MatchNPCsMBlock2.empty()) {
			for (DWORD i = 0; i < MatchNPCsMBlock2.size(); i++) {
				//try every block some (random) amount of times before moving onto next block
				for (DWORD loop = 0; loop < rand() % 5 + 1; loop++) {
					DWORD64 holder = VirtPRead64(MatchNPCsMBlock2[i] + alloff88);
					DWORD part = VirtPReadDword(holder + alloff66);
					if (MatchNPCsTimer2[i] != part) {
						WPOINT screenp = { VirtPReadWord(MatchNPCsMBlock2[i] + dooffxm), VirtPReadWord(MatchNPCsMBlock2[i] + dooffym) };
						screenp.y = resyy - screenp.y;
						if (ScreenFilter(screenp)) {
							screenp.x = screenp.x - 7 + corx + resxl;
							screenp.y = screenp.y - 7 + cory + resyt;
							if (action == 0) {
								MoveMouse2(screenp.x, screenp.y, 14, 20);
								RandomSleep2(25, 550, 3000);
								if (SideTextEq(sidetext)) {
									MouseLeftClick(50, 2000);
									return TRUE;
								}
							}
							if (action == 1) {
								MoveMouse2(screenp.x, screenp.y, 14, 20);
								RandomSleep2(25, 550, 3000);
								if (SideTextEq(sidetext)) {
									MouseRightClick(50, 2000);
									return TRUE;
								}
							}
							if (action == 2) {
								MoveMouse2(screenp.x, screenp.y, 14, 20);
								RandomSleep2(25, 550, 3000);
								if (SideTextEq(sidetext)) {
									return TRUE;
								}
							}
							if (action == 3) {
								return TRUE;
							}
						}
					}
				}
				//try minimap
				if (i < MatchNPCsMBlock2.size()) { failed = TRUE; }
			}
			if (failed == TRUE && usemap==TRUE) {
				WPOINT screenp = ToMapFFPOINT2({ VirtPReadWord(MatchNPCsMBlock2[0] + dooff11)*512.f,VirtPReadWord(MatchNPCsMBlock2[0] + dooff22)*512.f });
				if (screenp.x != 0 && screenp.y != 0) {
					screenp.x = screenp.x - 4+cormx; screenp.y = screenp.y - 4+cormy;
					MoveMouse2(screenp.x, screenp.y, 4, 4);
					RandomSleep2(25, 550, 3000);
					MouseLeftClick(50, 2000);
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}

// read that odd array where all players are//old
VOID ReadPArrayold() {

	DWORD plimit = 0;
	DWORD poffh = 0;

	PlX.clear();
	PlY.clear();
	PlZ.clear();
	PlID.clear();
	PlLife.clear();
	PlAnim.clear();
	PlMem.clear();
	PlFloor.clear();
	//
	PlTouched.clear();
	PlPraytype.clear();
	PlName.clear();
	MEMss BlockA;


	  
	if (ScAdd != NULL) {
		BlockA = DeterMemoryBlockLenght(ScAdd);

		plimit = BlockA.size / poff2 - 1;

		DWORD64 Sc = ScAdd + poff1 - poff2;
		for (DWORD i = 0; i < plimit; i++) {
			poffh = poffh + poff2;
				//cout << "ok11" << endl;
			FLOAT bb1 = VirtPReadFloat(Sc + poffh + poff11);
			FLOAT bb2 = VirtPReadFloat(Sc + poffh + poff22);
			//printf("ok12:\n");
			if (bb1 > 0.f && bb2 > 0.f) {
				BYTE active1 = VirtPReadByte(Sc + poffh + npca1);
				BYTE active2 = VirtPReadByte(Sc + poffh + npca2);
				if ((active1 > 0 && active1 < 4) && (active2 > 0 && active2 < 7)) {
					//printf("ok1:\n");
					if (CheckVisibleLimit(bb1, bb2)) {
							//printf("ok2:\n");
						//filter for pengs
						string s = VirtPReadChar(Sc + poffh + poffname);
						//	string cw = "Headless";
						//	if (s.find(cw) != string::npos) {
						PlName.push_back(s);
						PlMem.push_back(Sc + poffh);
						PlX.push_back(bb1 - 256.f);
						PlY.push_back(bb2 - 256.f);
						FLOAT b234 = VirtPReadFloat(Sc + poffh + poff11 + 4);
						PlZ.push_back(b234);
						DWORD bb66 = VirtPReadDword(Sc + poffh + poff66);
						DWORD bb777 = VirtPReadDword(Sc + poffh + ptest77);
						PlID.push_back(bb66);
						DWORD bb77 = VirtPReadDword(Sc + poffh + poff77);
						if (bb77 == 0xffffffff) { bb77 = 0; }
						PlLife.push_back(bb77);
						if (bb777 == 0xffffffff) { bb777 = 0; }
						PlAnim.push_back(bb777);
						BYTE Read = VirtPReadByte(Sc + poffh + poff88);
						PlFloor.push_back(Read);
						BYTE Read2 = VirtPReadByte(Sc + poffh + poff1111);
						PlPraytype.push_back(Read2);

						//}
					}
				}
			}
		}
	}
}

//read that odd array where all npc are//old
VOID ReadNPCArrayold(){

	WORD npclimit = 0;
	DWORD npcoffh = 0;

	NPCX.clear();
	NPCY.clear();
	NPCZ.clear();
	NPCID.clear();
	NPCMem.clear();
	NPCLife.clear();
	NPCAnim.clear();
	NPCName.clear();
	NPCFloor.clear();
	NPCTouched.clear();
	NPCProtOn.clear();
	NPCPraytype.clear();
	NPCxmid.clear();
	NPCymid.clear();
	NPCxsize.clear();
	NPCysize.clear();
	MEMss BlockA;
	WORD resy = GetRsResolution2().y;




	if (NPCAdd != NULL) {
		BlockA = DeterMemoryBlockLenght(NPCAdd);

		npclimit = 1500;
		if (GetAsyncKeyState(VK_NUMPAD0)) { npclimit = npclimit / 2; }
		if (GetAsyncKeyState(VK_NUMPAD1)) { npclimit = npclimit / 3; }
		if (GetAsyncKeyState(VK_NUMPAD2)) { npclimit = npclimit / 4; }
		if (GetAsyncKeyState(VK_NUMPAD3)) { npclimit = npclimit / 5; }
		if (GetAsyncKeyState(VK_NUMPAD4)) { npclimit = npclimit / 6; }
		if (GetAsyncKeyState(VK_NUMPAD5)) { npclimit = npclimit / 7; }
		if (GetAsyncKeyState(VK_NUMPAD6)) { npclimit = npclimit / 8; }
		if (GetAsyncKeyState(VK_NUMPAD7)) { npclimit = npclimit / 9; }
		if (GetAsyncKeyState(VK_NUMPAD8)) { npclimit = npclimit / 10; }
		if (GetAsyncKeyState(VK_NUMPAD9)) { npclimit = npclimit / 11; }

	//	cout << ":" << npclimit;
		DWORD64 Sc = NPCAdd - npcoff2*(npclimit / 2);
		for (DWORD i = 0; i < npclimit; i++) {
			npcoffh = npcoffh + npcoff2;
			//	printf("ok11:\n");
			FLOAT bb1 = VirtPReadFloat(Sc + npcoffh + npcoff11);
			FLOAT bb2 = VirtPReadFloat(Sc + npcoffh + npcoff22);
			//printf("ok12:\n");
			if (bb1 > 0.f && bb2 > 0.f) {
				BYTE active1 = VirtPReadByte(Sc + npcoffh + npca1);
				BYTE active2 = VirtPReadByte(Sc + npcoffh + npca2);
				if ((active1 > 0 && active1 < 4) && (active2 > 0 && active2 < 7)) {
					//printf("ok1:\n");
					if (CheckVisibleLimit(bb1, bb2)) {
						//printf("ok2:\n");
						//filter for pengs
					string s = VirtPReadChar(Sc + npcoffh + npcoffname);
					//	string cw = "Headless";
					//	if (s.find(cw) != string::npos) {
							NPCName.push_back(s);
						NPCMem.push_back(Sc + npcoffh);
						NPCX.push_back(bb1 - 256.f);
						NPCY.push_back(bb2 - 256.f);
						FLOAT b234 = VirtPReadFloat(Sc + npcoffh + npcoff11+4);
						NPCZ.push_back(b234);
						DWORD bb66 = VirtPReadDword(Sc + npcoffh + npcoff66);
						NPCID.push_back(bb66);
						DWORD bb77 = VirtPReadDword(Sc + npcoffh + npcoff77);
						if (bb77 == 0xffffffff) { bb77 = 0; }
						NPCLife.push_back(bb77);
						DWORD bb777 = VirtPReadDword(Sc + npcoffh + npcoff33);
						if (bb777 == 0xffffffff) { bb777 = 0; }
						NPCAnim.push_back(bb777);
						BYTE Read = VirtPReadByte(Sc + npcoffh + npcoff88);
						NPCFloor.push_back(Read);

						WORD npcxm = VirtPReadWord(Sc + npcoffh + npcoffxm);
						WORD npcym = VirtPReadWord(Sc + npcoffh + npcoffym);
						WORD npcxsize = VirtPReadWord(Sc + npcoffh + npcoffxsize);
						WORD npcysize = VirtPReadWord(Sc + npcoffh + npcoffysize);
						
						NPCxmid.push_back(npcxm); 						
						NPCymid.push_back(resy - npcym); 
						NPCxsize.push_back(npcxsize);
						NPCysize.push_back(npcysize);



						//}
					}
				}
			}
		}
	}
}

//first angle//second zoom 
FFPOINT ReadCompass() {
	if (Compass!=NULL) {                         
		return{ VirtPReadFloatAll(Compass + 0x4e0), VirtPReadFloatAll(Compass + 0x468)-0.5f, 0 };
	}
	return{ 0,0,0 };
}

//finds and reads varpbits
VB FindVarBit(WORD id)
{
	SettingTest();
	if (!SettingsId.empty()) {
		for (DWORD i = 0; i < SettingsId.size(); i++) {
			if (SettingsId[i] == id) {
				return{ SettingsState[i], SettingsAddr[i] };
			}
		}
	}
	cout << dec << "Did not find varps:" << id << endl;
	return{ 0 ,0 };
}

// finds and reads sidetext
string FindSideText() {
	string s;
	if (LocalPlayer != NULL) {
		//whole screen box
		if (InterfCheck(UpTextTempMemoryLoc, 1477, 815, 0xffff, 813)) {
			//cout << hex << UpTextTempMemoryLoc << endl;
			if (UpTextTempMemoryLoc != NULL) {
				DWORD64 hold = VirtPRead64(UpTextTempMemoryLoc + 0x228) + 0x8;
				DWORD holdx = VirtPRead64(UpTextTempMemoryLoc + 0x90);
				DWORD holdy = VirtPRead64(UpTextTempMemoryLoc + 0x94);
				if (holdx < 0xffff && holdy < 0xffff) {
					//fork spot//read first
					DWORD64 hold2 = VirtPRead64(hold);
					DWORD64 hold3 = VirtPRead64(hold2 + 0x1d8);
					s = VirtPReadChar(hold3);
					return s;
				}
			}
		}
		else {
			cout << "Looking Up Text" << endl;
			//keeps crashing here without wait
			Sleep(100);
			UpTextTempMemoryLoc = Locateinterface(1477, 815, 0xffff, 813);
		}
	}
	return s;
}

//compare sidetext
BOOLEAN SideTextEq(string text) {
		string f = FindSideText();
		if (text.length()>0 && f.length()>0) {
			if (f.find(text) != string::npos) {
				return TRUE;
			}}
	return FALSE;
}

//tileclick
BOOLEAN ClickTile2_(POINT p)  {
	RECT rs;
	GetWindowRect(WProcC, &rs);
	//FFPOINT rez =GetRsResolution2();
	POINT c,c2;

	GetCursorPos(&c);
	RandomSleep();
	GetCursorPos(&c2);

	if (c.x == c2.x && c.y == c2.y) {
	POINT screenp = TToScreen(p);
	if (screenp.x != 0 && screenp.y != 0) {
		if (screenp.x>(rs.left+10) && screenp.x<(rs.right-10)) {
			screenp.x = screenp.x - 7; screenp.y = screenp.y - 7;
			MoveMouse(screenp.x, screenp.y, 14, 20);
			RandomSleep2(25, 550, 3000);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			RandomSleep2(25, 550, 3000);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			return TRUE;
		}
		//if () {}
	}}
	return FALSE;
}

//finds npc RETURNS TRUE
BOOLEAN FindNPCBool(vector<DWORD> npc, BYTE maxdistance) {

	vector<FLOAT> MatchNPCsDist;
	vector<DWORD64> MatchNPCsMBlock;
	FFPOINT p = PlayerCoordFloatRaw();
	FLOAT min = 51200.f;

	ReadCObjArrays();
	//add all matching ids to separate array
	//as it should take milliseconds to go trough all, do distance aswell
	if (!npc.empty() && !NPCID.empty()) {
		for (DWORD ii = 0; ii < npc.size(); ii++) {
			for (DWORD i = 0; i < NPCID.size(); i++) {
				if (npc[ii] != NULL || NPCID[i] != NULL) {
					if (NPCID[i] == npc[ii]) {
						FLOAT dist = sqrt(pow(NPCX[i] - p.x, 2) + pow(NPCY[i] - p.y, 2));
						if (dist < maxdistance*512.f) {
							MatchNPCsDist.push_back(dist);
							MatchNPCsMBlock.push_back(NPCMem[i]);
						}
					}
				}
			}
		}

		//smallest distance
		if (!MatchNPCsMBlock.empty() && !MatchNPCsDist.empty()) {
			for (DWORD i = 0; i < MatchNPCsMBlock.size(); i++) {
				if (MatchNPCsDist[i] < min) {
					if (MatchNPCsDist[i] >= 0.f && MatchNPCsDist[i] < 51200.f) {
						min = MatchNPCsDist[i];
					}
				}
			}
		}

		//pullout the smallest//
		if (!MatchNPCsMBlock.empty() && !MatchNPCsDist.empty()) {
			for (DWORD i = 0; i < MatchNPCsMBlock.size(); i++) {
				if (min == MatchNPCsDist[i]) {
					return TRUE;
				}
			}
		}
	}
	return FALSE;
}

//finds npc and focus to his address
BOOLEAN FindNPCLock_(vector<DWORD> npc, BYTE maxdistance) {

	vector<FLOAT> MatchNPCsDist;
	vector<DWORD64> MatchNPCsMBlock;
	FFPOINT p = PlayerCoordFloatRaw();
	DWORD hover;
	DWORD hover2;
	POINT c, c2;
	FLOAT min = 51200.f;
	GetWindowRect(WProcC, &rs);
	WORD resyt = rs.top;
	WORD resxl = rs.left;
	WORD resyy = GetRsResolution2().y;

	ReadCObjArrays();
		//add all matching ids to separate array
		//as it should take milliseconds to go trough all, do distance aswell
		if (!npc.empty() && !NPCID.empty()) {
			for (DWORD ii = 0; ii < npc.size(); ii++) {
				for (DWORD i = 0; i < NPCID.size(); i++) {
					if (npc[ii] != NULL || NPCID[i] != NULL) {
						if (NPCID[i] == npc[ii]) {
							FLOAT dist = sqrt(pow(NPCX[i] - p.x, 2) + pow(NPCY[i] - p.y, 2));
							if (dist < maxdistance*512.f) {
								MatchNPCsDist.push_back(dist);
								MatchNPCsMBlock.push_back(NPCMem[i]);
							}
						}
					}
				}
			}

			//smallest distance
			if (!MatchNPCsMBlock.empty() && !MatchNPCsDist.empty()) {
				for (DWORD i = 0; i < MatchNPCsMBlock.size(); i++) {
					if (MatchNPCsDist[i] < min) {
						if (MatchNPCsDist[i] >= 0.f && MatchNPCsDist[i] < 51200.f) {
							min = MatchNPCsDist[i];
						}
					}
				}
			}

			//pullout the smallest//
			if (!MatchNPCsMBlock.empty() && !MatchNPCsDist.empty()) {
				for (DWORD i = 0; i < MatchNPCsMBlock.size(); i++) {
					if (min == MatchNPCsDist[i]) {
						NPCLOCK= MatchNPCsMBlock[i];
						return TRUE;
					}
				}
			}
		}
	return FALSE;
}

//read only npc in focus// checks if valid
NPCFOCUS ReadNPCInFocus_() {

	WORD resy = GetRsResolution2().y;

	if (NPCLOCK !=NULL) {
		
			FLOAT bb1 = VirtPReadFloat(NPCLOCK + npcoff11);
			FLOAT bb2 = VirtPReadFloat(NPCLOCK + npcoff22);
			if (bb1 > 0.f && bb2 > 0.f) {
				BYTE active1 = VirtPReadByte(NPCLOCK + npca1);
				BYTE active2 = VirtPReadByte(NPCLOCK + npca2);
				if ((active1 > 0 && active1 < 10) && (active2 > 0 && active2 < 10)) {
					if (CheckVisibleLimit(bb1, bb2)) {
						//id
						DWORD bb66 = VirtPReadDword(NPCLOCK + npcoff66);

						DWORD bb77 = VirtPReadDword(NPCLOCK + npcoff77);
						if (bb77 == 0xffffffff) { bb77 = 0;
					   //   cout << "test0" << endl;
						NPCLOCK = 0;
						return{ { 0,0 },0,0,{ 0,0 },0 };
						}
						DWORD bb777 = VirtPReadDword(NPCLOCK + npcoff33);
						if (bb777 == 0xffffffff) { bb777 = 0;}

						WORD npcxm = VirtPReadWord(NPCLOCK + npcoffxm);
						WORD npcym = resy - (VirtPReadWord(NPCLOCK + npcoffym));
	
						return{ {bb1 - 256.f,bb2 - 256.f},bb77,bb777,{npcxm,npcym},bb66 };
				}
					cout << "test1" << endl;
					NPCLOCK = 0;
					return{ {0,0},0,0,{0,0},0 };
			}
				cout << "test2" << endl;
				NPCLOCK = 0;
				return{ { 0,0 },0,0,{ 0,0 },0 };
		}
			cout << "test3" << endl;
			NPCLOCK = 0;
			return{ { 0,0 },0,0,{ 0,0 },0 };
	}
	cout << "test4" << endl;
	return{ { 0,0 },0,0,{ 0,0 },0 };
}

//Clicks npc in focus 
BOOLEAN NPCFocusClick_(BYTE mapdistance) {

	vector<FLOAT> MatchNPCsDist;
	vector<FLOAT> MatchNPCsDist2;
	vector<FLOAT> MatchNPCsDist3;
	vector<DWORD64> MatchNPCsMBlock;
	vector<DWORD64> MatchNPCsMBlock2;
	//vector<BYTE> State,State2;
	FFPOINT p = PlayerCoordFloatRaw();
	//	POINT c, c2;
	GetWindowRect(WProcC, &rs);
	WORD resyt = rs.top;
	WORD resxl = rs.left;
	WORD resyy = GetRsResolution2().y;

//	GetCursorPos(&c);
	//should delete if something is wrong
//	ReadNPCInFocus_();
//	Sleep(10);
//	GetCursorPos(&c2);
//	if (c.x == c2.x && c.y == c2.y) {
	if (NPCLOCK != NULL) {


		for (DWORD loop = 0; loop < 25; loop++) {
			Sleep(10);
			if (loop < 20) {


				FLOAT dist = sqrt(pow(NPCLOCK - p.x, 2) + pow(NPCLOCK - p.y, 2));
				if (dist < (8.f*512.f)) {
					WPOINT screenp = { VirtPReadWord(NPCLOCK + npcoffxm),VirtPReadWord(NPCLOCK + npcoffym) };
					screenp.y = resyy - screenp.y;
					if (ScreenFilter(screenp)) {
						screenp.x = screenp.x - 7 + resxl;
						screenp.y = screenp.y - 7 + resyt;
						MoveMouse2(screenp.x, screenp.y, 14, 20);
						RandomSleep2(25, 550, 3000);
						MouseLeftClick(50, 2000);
						return TRUE;
					}
				}
			}
			else {
				FLOAT dist = sqrt(pow(NPCLOCK - p.x, 2) + pow(NPCLOCK - p.y, 2));
				if (dist < 41.f*512.f) {
					WPOINT screenp = ToMapFFPOINT2({ VirtPReadFloat(NPCLOCK + npcoff11) - 256.f,VirtPReadFloat(NPCLOCK + npcoff22) - 256.f });
					if (screenp.x != 0 && screenp.y != 0) {
						screenp.x = screenp.x - 4; screenp.y = screenp.y - 4;
						MoveMouse2(screenp.x, screenp.y, 4, 4);
						RandomSleep2(25, 550, 3000);
						MouseLeftClick(50, 2000);
						return TRUE;
					}
				}
			}
		}
	}
	//}
	return FALSE;
}

//finds x and y for npc
//max distance from player
BOOLEAN FindNPCss(vector<DWORD> npc, BYTE maxdistance, INT corx, INT cory,INT cormx, INT cormy, BOOLEAN usemap, BYTE action, string sidetext) {

	vector<FLOAT> MatchNPCsDist;
	vector<FLOAT> MatchNPCsDist2;
	vector<FLOAT> MatchNPCsDist3;
	vector<DWORD64> MatchNPCsMBlock;
	vector<DWORD64> MatchNPCsMBlock2;
	vector<DWORD> MatchNPCsTimer;
	vector<DWORD> MatchNPCsTimer2;
	FFPOINT p = PlayerCoordFloatRaw();
	//	POINT c, c2;
	GetWindowRect(WProcC, &rs);
	WORD resyt = rs.top;
	WORD resxl = rs.left;
	WORD resyy = GetRsResolution2().y;

	//GetCursorPos(&c);
	//Sleep(10);
	//GetCursorPos(&c2);
	//if (c.x == c2.x && c.y == c2.y) {
	ReadCObjArrays();
	//add all matching ids to separate array
	//as it should take milliseconds to go trough all, do distance aswell
	//cout << "find" << endl;
	if (!npc.empty() && !NPCID.empty()) {
		for (DWORD i1 = 0; i1 < npc.size(); i1++) {
			for (DWORD i2 = 0; i2 < NPCID.size(); i2++) {
				if (npc[i1] != NULL || NPCID[i2] != NULL) {
					if (NPCID[i2] == npc[i1]) {                                  //give some uniqueness
						FLOAT dist = sqrt(pow(NPCX[i2] - p.x, 2) + pow(NPCY[i2] - p.y, 2)) + (0.1f*i2);
						if (dist < maxdistance*512.f) {
							MatchNPCsDist.push_back(dist);
							MatchNPCsDist2.push_back(dist);
							MatchNPCsMBlock.push_back(NPCMem[i2]);
							MatchNPCsTimer.push_back(ViewPartialNPC[i2]);
						}
					}
				}
			}
		}
		//sort first dist by distance size
		if (!MatchNPCsMBlock.empty()) {
			sort(MatchNPCsDist.begin(), MatchNPCsDist.end());

			//set memory blocks into order by dist and dist2
			for (DWORD i = 0; i < MatchNPCsDist.size(); i++) {
				for (DWORD ii = 0; ii < MatchNPCsDist2.size(); ii++) {
					if (MatchNPCsDist[i] == MatchNPCsDist2[ii]) {
						//should add closest memory block @ 0(first)
						MatchNPCsMBlock2.push_back(MatchNPCsMBlock[ii]);
						MatchNPCsDist3.push_back(MatchNPCsDist2[ii]);
						MatchNPCsTimer2.push_back(MatchNPCsTimer[ii]);
					}
				}
			}
		}

		BOOLEAN failed = FALSE;
		if (!MatchNPCsMBlock2.empty()) {
				for (DWORD i = 0; i < MatchNPCsMBlock2.size(); i++) {
					//try every block some (random) amount of times before moving onto next block
					for (DWORD loop = 0; loop < rand() % 5+1; loop++) {
					DWORD64 holder = VirtPRead64(MatchNPCsMBlock2[i] + alloff88);
					DWORD part = VirtPReadDword(holder + alloff66);
					if (MatchNPCsTimer2[i] != part) {
						WPOINT screenp = { VirtPReadWord(MatchNPCsMBlock2[i] + npcoffxm), VirtPReadWord(MatchNPCsMBlock2[i] + npcoffym) };
						
						screenp.y = resyy - screenp.y;
						if (ScreenFilter(screenp)) {
							screenp.x = screenp.x - 7 + corx + resxl;
							screenp.y = screenp.y - 7 + cory + resyt;
							if (action == 0) {
								cout << dec << screenp.x << endl;
								cout << dec << screenp.y << endl;
								MoveMouse2(screenp.x, screenp.y, 14, 20);
								RandomSleep2(25, 550, 3000);
								if (SideTextEq(sidetext)) {
									MouseLeftClick(50,2000);
									return TRUE;
								}
							}
							if (action == 1) {
								MoveMouse2(screenp.x, screenp.y, 14, 20);
								RandomSleep2(25, 550, 3000);
								if (SideTextEq(sidetext)) {
									MouseRightClick(50, 2000);
									return TRUE;
								}
							}
							if (action == 2) {
								MoveMouse2(screenp.x, screenp.y, 14, 20);
								RandomSleep2(25, 550, 3000);
								if (SideTextEq(sidetext)) {
									runsNPC = 0;
									return TRUE;
								}
							}
							if (action == 3) {
								return TRUE;
							}
						}
					}
				}
				//try minimap
				if (i < MatchNPCsMBlock2.size()) { failed = TRUE; }
			}
			if (failed == TRUE && usemap==TRUE) {
				WPOINT screenp = ToMapFFPOINT2({ VirtPReadFloat(MatchNPCsMBlock2[0] + npcoff11) - 256.f,VirtPReadFloat(MatchNPCsMBlock2[0] + npcoff22) - 256.f });
				if (screenp.x != 0 && screenp.y != 0) {
					screenp.x = screenp.x - 4+cormx; screenp.y = screenp.y - 4+cormy;
					MoveMouse2(screenp.x, screenp.y, 4, 4);
					RandomSleep2(25, 550, 3000);
					MouseLeftClick(50, 2000);
					return TRUE;
				}
			}
		}
	}

		//	}
	return FALSE;
}


struct point {
	double x;
	double y;
	point(double x, double y) : x(x), y(y) {}
};

//possibly could be used to find out automaticly if it is being run on rdp
BOOLEAN GetVM(InterceptionDevice device){
	InterceptionContext context;
	context = interception_create_context();
	wchar_t hardware_id[500];

	if (RDPLevel == 0) {
		return TRUE;
	}
	if (RDPLevel==1) {
		size_t length = interception_get_hardware_id(context, device, hardware_id, sizeof(hardware_id));
		if (length > 0 && length < sizeof(hardware_id)) {
			wstring ms = hardware_id;
			//hardware id is diffrent on rdp
			if (ms.find(L"TS_MOU") != string::npos) {
				return TRUE;
			}
		}
	}
	return FALSE;
}

//add manual level up, one rdp is 1 level higher than normal mouse, next rdp window would be +2?
int interception_is_mouse2(InterceptionDevice device)
{
	return device >= INTERCEPTION_MOUSE(0+ RDPLevel) && device <= INTERCEPTION_MOUSE(INTERCEPTION_MAX_MOUSE - 1);
}
int interception_is_keyboard2(InterceptionDevice device)
{
	return device >= INTERCEPTION_KEYBOARD(0+ RDPLevel) && device <= INTERCEPTION_KEYBOARD(INTERCEPTION_MAX_KEYBOARD - 1);
}

int MouseInception() {
	InterceptionContext context;
	InterceptionDevice device;
	InterceptionStroke stroke;
	point position(screen_width2 / 2, screen_height2 / 2);

	context = interception_create_context();
	interception_set_filter(context, interception_is_keyboard2,
		INTERCEPTION_FILTER_KEY_DOWN | INTERCEPTION_FILTER_KEY_UP);
	interception_set_filter(context, interception_is_mouse2,
		INTERCEPTION_FILTER_MOUSE_MOVE);
	
	if (!mouse && !keyboard) { 
		cout << "press any key" << endl; 
	}
	//it seems after we have incepted we need to keep fowarding mouse actions trough here
	while (interception_receive(context, device = interception_wait(context), &stroke, 1) > 0) {
		if (interception_is_mouse2(device)) {
			if (!mouse) {
				mouse = device;
				cout << "mouse found:" << mouse << endl;
				wchar_t hardware_id[500];
				size_t length = interception_get_hardware_id(context, mouse, hardware_id, sizeof(hardware_id));
				if (length > 0 && length < sizeof(hardware_id))
					wcout << hardware_id << endl;
			}

			InterceptionMouseStroke &mstroke = *(InterceptionMouseStroke *)&stroke;
			mstroke.flags = INTERCEPTION_MOUSE_MOVE_ABSOLUTE;
			if (RDPLevel == 0) {
				xyhold2.x += mstroke.x;
				xyhold2.y += mstroke.y;
				if (xyhold2.x < 0)
					xyhold2.x = 0;
				if (xyhold2.x > screen_width2 - 1)
					xyhold2.x = screen_width2 - 1;
				if (xyhold2.y < 0)
					xyhold2.y = 0;
				if (xyhold2.y > screen_height2 - 1)
					xyhold2.y = screen_height2 - 1;
				mstroke.x = static_cast<int>((0xFFFF * xyhold2.x) / screen_width2);
				mstroke.y = static_cast<int>((0xFFFF * xyhold2.y) / screen_height2);
				interception_send(context, mouse, &stroke, 1);
			}
			else {
				//RDP thing
				xyhold2.x = mstroke.x / (0xffff / screen_width2);
				xyhold2.y = mstroke.y / (0xffff / screen_height2);
				if (xyhold2.x < 0)
					xyhold2.x = 0;
				if (xyhold2.x > screen_width2 - 1)
					xyhold2.x = screen_width2 - 1;
				if (xyhold2.y < 0)
					xyhold2.y = 0;
				if (xyhold2.y > screen_height2 - 1)
					xyhold2.y = screen_height2 - 1;
				//cout << "x" << xyhold2.x << endl;
				//cout << "yxyhold2mou" << xyhold2.y << endl;
				mstroke.x = static_cast<int>((0xFFFF * xyhold2.x) / screen_width2);
				mstroke.y = static_cast<int>((0xFFFF * xyhold2.y) / screen_height2);
				interception_send(context, mouse, &stroke, 1);
			}
		}
		if (interception_is_keyboard2(device)) {
			InterceptionKeyStroke &kstroke = *(InterceptionKeyStroke *)&stroke;
			if (!keyboard) {
				keyboard = device;
				cout << "keyboard found" << endl;
			}
			//cout << dec << kstroke.code << endl;
			interception_send(context, keyboard, &stroke, 1);
		}
	}
			interception_destroy_context(context);
		return 0;
} 

//max distance from player, checks npc health
BOOLEAN FindNPCss(vector<DWORD> npc, BYTE maxdistance, DWORD health) {

	vector<FLOAT> MatchNPCsDist;
	vector<DWORD64> MatchNPCsMBlock;
	FFPOINT p = PlayerCoordFloatRaw();
	FLOAT min = 51200.f;
	DWORD hover;
	DWORD hover2;
	POINT c, c2;
	GetCursorPos(&c);
	RandomSleep();
	GetCursorPos(&c2);
	if (c.x == c2.x && c.y == c2.y) {
		ReadCObjArrays();
		//add all matching ids to separate array
		//as it should take milliseconds to go trough all, do distance aswell
		if (!npc.empty() && !NPCID.empty()) {
			for (DWORD ii = 0; ii < npc.size(); ii++) {
				for (DWORD i = 0; i < NPCID.size(); i++) {
					if (npc[ii] != NULL || NPCID[i] != NULL) {
						if (NPCID[i] == npc[ii]) {
							FLOAT dist = sqrt(pow(NPCX[i] - p.x, 2) + pow(NPCY[i] - p.y, 2));
							if (dist < maxdistance*512.f && NPCLife[i] == health) {
								MatchNPCsDist.push_back(dist);
								MatchNPCsMBlock.push_back(NPCMem[i]);
							}
						}
					}


			//smallest distance
			if (!MatchNPCsMBlock.empty() && !MatchNPCsDist.empty()) {
				for (DWORD i = 0; i < MatchNPCsMBlock.size(); i++) {
					if (MatchNPCsDist[i] < min) {
						if (MatchNPCsDist[i] >= 0.f && MatchNPCsDist[i] < 51200.f) {
							min = MatchNPCsDist[i];
						}
					}
				}
			}
		}
	}

		//pullout the smallest//click if hover
		if (!MatchNPCsMBlock.empty() && !MatchNPCsDist.empty()) {
			for (DWORD i = 0; i < MatchNPCsMBlock.size(); i++) {
				if (min == MatchNPCsDist[i]) {
					WPOINT screenp = TToScreen2({ VirtPReadFloat(MatchNPCsMBlock[i] + npcoff11) - 256.f,VirtPReadFloat(MatchNPCsMBlock[i] + npcoff22) - 256.f });
					if (screenp.x != 0 && screenp.y != 0) {
						screenp.x = screenp.x - 7; screenp.y = screenp.y - 7;
						MoveMouse(screenp.x, screenp.y, 14, 20);
						hover = VirtPReadDword(MatchNPCsMBlock[i] + npcoff111);
						RandomSleep();
						hover2 = VirtPReadDword(MatchNPCsMBlock[i] + npcoff111);
						if (hover != hover2) {
							mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
							RandomSleep();
							mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
							return TRUE;
						}
					}
				}
			}
		}
	}
}
	return FALSE;
}

//max distance from slaying spot
BOOLEAN FindNPCss(vector<DWORD> npc, BYTE maxdistance,POINT spot) {

	vector<FLOAT> MatchNPCsDist;
	vector<DWORD64> MatchNPCsMBlock;
	FFPOINT p = PlayerCoordFloatRaw();
	FLOAT min = 51200.f;
	DWORD hover;
	DWORD hover2;
	POINT c, c2;
	GetCursorPos(&c);
	RandomSleep();
	GetCursorPos(&c2);
	if (c.x == c2.x && c.y == c2.y) {
		ReadCObjArrays();
		//add all matching ids to separate array
		//as it should take milliseconds to go trough all, do distance aswell
		if (!npc.empty() && !NPCID.empty()) {
			for (DWORD ii = 0; ii < npc.size(); ii++) {
				for (DWORD i = 0; i < NPCID.size(); i++) {
					if (npc[ii] != NULL || NPCID[i] != NULL) {
						if (NPCID[i] == npc[ii]) {
							FLOAT dist = sqrt(pow(NPCX[i] - spot.x*512.f, 2) + pow(NPCY[i] - spot.y*512.f, 2));
							if (dist < maxdistance*512.f) {
								MatchNPCsDist.push_back(dist);
								MatchNPCsMBlock.push_back(NPCMem[i]);
							}
						}
					}
				}
			}
					//smallest distance
					if (!MatchNPCsMBlock.empty() && !MatchNPCsDist.empty()) {
						for (DWORD i = 0; i < MatchNPCsMBlock.size(); i++) {
							if (MatchNPCsDist[i] < min) {
								if (MatchNPCsDist[i] >= 0.f && MatchNPCsDist[i] < 51200.f) {
									min = MatchNPCsDist[i];
								}
							}
						}
					}

			//pullout the smallest//click if hover
			if (!MatchNPCsMBlock.empty() && !MatchNPCsDist.empty()) {
				for (DWORD i = 0; i < MatchNPCsMBlock.size(); i++) {
					if (min == MatchNPCsDist[i]) {
						WPOINT screenp = TToScreen2({ VirtPReadFloat(MatchNPCsMBlock[i] + npcoff11) - 256.f,VirtPReadFloat(MatchNPCsMBlock[i] + npcoff22) - 256.f });
						if (screenp.x != 0 && screenp.y != 0) {
							screenp.x = screenp.x - 7; screenp.y = screenp.y - 7;
							MoveMouse(screenp.x, screenp.y, 14, 20);
							hover = VirtPReadDword(MatchNPCsMBlock[i] + npcoff111);
							RandomSleep();
							hover2 = VirtPReadDword(MatchNPCsMBlock[i] + npcoff111);
							if (hover != hover2) {
								mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
								RandomSleep();
								mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
								return TRUE;
							}
						}
					}
				}
			}
		}
	}
	return FALSE;
}

//max distance from slaying spot, checks npc health
BOOLEAN FindNPCss(vector<DWORD> npc, BYTE maxdistance, POINT spot, DWORD health) {

	vector<FLOAT> MatchNPCsDist;
	vector<DWORD64> MatchNPCsMBlock;
	FFPOINT p = PlayerCoordFloatRaw();
	FLOAT min = 51200.f;
	DWORD hover;
	DWORD hover2;
	POINT c, c2;
	GetCursorPos(&c);
	RandomSleep();
	GetCursorPos(&c2);
	if (c.x == c2.x && c.y == c2.y) {
		ReadCObjArrays();
	//add all matching ids to separate array
	//as it should take milliseconds to go trough all, do distance aswell
	if (!npc.empty() && !NPCID.empty()) {
		for (DWORD ii = 0; ii < npc.size(); ii++) {
			for (DWORD i = 0; i < NPCID.size(); i++) {
				if (npc[ii] != NULL || NPCID[i] != NULL) {
					if (NPCID[i] == npc[ii]) {
						FLOAT dist = sqrt(pow(NPCX[i] - spot.x*512.f, 2) + pow(NPCY[i] - spot.y*512.f, 2));
						if (dist < maxdistance*512.f  && PlLife[i] == health) {
							MatchNPCsDist.push_back(dist);
							MatchNPCsMBlock.push_back(NPCMem[i]);
						}
					}
				}
			}
		}

				//smallest distance
				if (!MatchNPCsMBlock.empty() && !MatchNPCsDist.empty()) {
					for (DWORD i = 0; i < MatchNPCsMBlock.size(); i++) {
						if (MatchNPCsDist[i] < min) {
							if (MatchNPCsDist[i] >= 0.f && MatchNPCsDist[i] < 51200.f) {
								min = MatchNPCsDist[i];
							}
						}
					}
				}


		//pullout the smallest//click if hover
		if (!MatchNPCsMBlock.empty() && !MatchNPCsDist.empty()) {
			for (DWORD i = 0; i < MatchNPCsMBlock.size(); i++) {
				if (min == MatchNPCsDist[i]) {
					WPOINT screenp = TToScreen2({ VirtPReadFloat(MatchNPCsMBlock[i] + npcoff11) - 256.f,VirtPReadFloat(MatchNPCsMBlock[i] + npcoff22) - 256.f });
					if (screenp.x != 0 && screenp.y != 0) {
						screenp.x = screenp.x - 7; screenp.y = screenp.y - 7;
						MoveMouse(screenp.x, screenp.y, 14, 20);
						hover = VirtPReadDword(MatchNPCsMBlock[i] + npcoff111);
						RandomSleep();
						hover2 = VirtPReadDword(MatchNPCsMBlock[i] + npcoff111);
						if (hover != hover2) {
							mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
							RandomSleep();
							mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
							return TRUE;
						}
					}
				}
			}
		}
	}
}
	return FALSE;
}

//looks through THE array to find localplayer
DWORD64 FindPlayer() {

	DWORD poffh = 0;
	
	//cout <<"test:"<< PlMem.size() << endl;
	//if (PlMem.empty()) { cout << "PLempty"<<endl; }
	if (!PlMem.empty()) {
		for (DWORD i = 0; i < PlMem.size(); i++) {
			poffh = poffh + poff2;

			BYTE bb4 = VirtPReadByte(PlMem[i] + poff44);
		
			if (bb4 > 3 && bb4 <7) {
				LocalPlayer = PlMem[i];
				if (debug) { cout << hex << "localplayer: " << LocalPlayer << "\n"; }
				return LocalPlayer;

			} 
		}
		//possibly couldnt find localplayer from array, lets reset it
		LocalPlayer = 0;
		//cout << "p1" << endl;
		ReadCObjArrays();
		return 0;
	}
	LocalPlayer = 0;
	//cout << "p2" << endl;
	ReadCObjArrays();
	return 0;
}

//makesure it still is localplayer
DWORD64 FindLP(){

	if (LocalPlayer != NULL) {
		//cout << "#1"<<endl;
		DWORD bb4 = VirtPReadDword(LocalPlayer + poff44);
		if (bb4 > 3 && bb4 <7) {
			//cout << "#2"<<endl;
			return LocalPlayer;
		}
		else {
			//cout << "#3"<<endl;		
			FindPlayer();
		}
	}
	else {
		//cout << "#4"<<endl;
		FindPlayer();
	}
	return 0;
}

//item in area//xc is expected pos//xcurrent is actual//
BOOLEAN InArea(WORD xc, WORD rangex,WORD xcurrent, WORD yc, WORD rangey, WORD ycurrent, BYTE floorz,BYTE floorz2) {
	if (abs(xcurrent - xc)<rangex && abs(ycurrent - yc)<rangey && floorz2 == floorz) {
		return TRUE;
	}
	return FALSE;
}

//is player in square area
BOOLEAN PInArea(WORD xc,WORD rangex,WORD yc,WORD rangey,BYTE floorz){
	FFPOINT p= PlayerCoordFloat();
	WORD px = p.x;
	WORD py = p.y;
	BYTE pz = p.z;

	if (InArea(xc, rangex, px, yc, rangey, py, floorz, pz)) {
		return TRUE;
	}
	//if (abs(px-xc)<rangex && abs(py - yc)<rangey && pz==floorz) {
	//	return TRUE;
	//}
	return FALSE;
}

//make a move to keep player in
VOID PIdle1() {
	DWORD Dice = RandomGener2(20);
	QWPOINT q = GetRSCorners();
	WORD resy = GetRsResolution2().y;
	WORD plxm;
	WORD plym;
	switch (Dice) {
	case 1:
		//focus on player
		cout << "1" << endl;
		plxm = VirtPReadWord(LocalPlayer + npcoffxm);
		plym = resy-VirtPReadWord(LocalPlayer + npcoffym);
		if (RandomGener2(100)<91) {
			MoveMouse2(q.left + plxm, q.top + plym, 5, 5);
		}
		else {
			if (RandomGener2(100) < 87) {
				MoveMouse2(q.left + plxm, q.top + plym, 5, 5);
				RandomSleep2(25, 3550, 15000);
				MouseRightClick(50, 2000);
				RandomSleep2(25, 3550, 15000);
				DWORD Dice2 =RandomGener2(100) < 77;
				if (Dice2 >= 70 && Dice2 <= 100) {
					MoveMouse2(q.left + RandomGener2(240), q.top + RandomGener2(q.bottom - q.top), 0, 0);
				}
				if (Dice2 >= 40 && Dice2 < 70) {
					MoveMouse2(q.right - RandomGener2(240), q.top + RandomGener2(q.bottom - q.top), 0, 0);
				}
				if (Dice2 >= 10 && Dice2 < 40) {
					MoveMouse2(q.right - q.left, q.top + RandomGener2(((q.bottom - q.top)/2)-10), 0, 0);
				}
				if (Dice2 >= 8 && Dice2 < 10) {
					MoveMouse2(q.left + RandomGener2(q.right - q.left), q.top + RandomGener2(q.bottom - q.top), 0, 0);
				}
				if (Dice2 >= 0 && Dice2 < 8) {
					MoveMouse2(1 + RandomGener2(screen_width2), 1 + RandomGener2(screen_height2), 0, 0);
				}
			}
			else {
				MoveMouse2(q.left + plxm, q.top + plym, 5, 5);
				RandomSleep2(25, 2550, 16000);
				MouseLeftClick(50, 2000);
			}
		}

		break;
	case 2:		
		//move mouse around at random
		cout << "2" << endl;
		MoveMouse2(q.left, q.top, RandomGener2(q.right - q.left), RandomGener2(q.bottom - q.top));
		break;
	default:
		//move mouse around at random
		cout << "default" << endl;
		MoveMouse2(q.left+RandomGener2(q.right-q.left),q.top+ RandomGener2(q.bottom-q.top),0,0);
		break;
	}
}

FLOAT lerp(float t, float  a, float b) {
	return (1 - t)*a + t*b;
}

// simple
FLOAT lerp2(FLOAT &dest,FLOAT a,FLOAT b, float t)
{
	dest = a + (b - a)*t;
	return dest;
}

// simple linear interpolation between two points
FLOAT lerp(FFPOINT& dest, const FFPOINT& a, const FFPOINT& b, const float t)
{
	dest.x = a.x + (b.x - a.x)*t;
	dest.y = a.y + (b.y - a.y)*t;
	return dest.x;
}

// evaluate a point on a bezier-curve. t goes from 0 to 1.0
void bezier(FFPOINT &dest, const FFPOINT& a, const FFPOINT& b, const FFPOINT& c, const FFPOINT& d, const float t)
{
	FFPOINT ab, bc, cd, abbc, bccd;
	lerp(ab, a, b, t);           // point between a and b (green)
	lerp(bc, b, c, t);           // point between b and c (green)
	lerp(cd, c, d, t);           // point between c and d (green)
	lerp(abbc, ab, bc, t);       // point between ab and bc (blue)
	lerp(bccd, bc, cd, t);       // point between bc and cd (blue)
	lerp(dest, abbc, bccd, t);   // point on the bezier-curve (black)
}

//3 point float
FLOAT bezier2(const FLOAT& a, const FLOAT& b, const FLOAT& c, const float t)
{
	FLOAT dest;
	FLOAT ab, bc, cd, abbc, bccd;
	lerp2(ab, a, b, t);           // point between a and b (green)
	lerp2(bc, b, c, t);           // point between b and c (green)
	lerp2(dest, ab, bc, t);       // point between ab and bc (blue)
	return dest;
}

void test() {

	
	                           //x             //y
	FLOAT dist = sqrt(pow(1000 - 1000,2) + pow(100 - 95,2));

	cout << dist<<"\n";
	//printf("test4: %f\n", bezier2(1.f,500.f,1000.f,0.50f));
}

// small test program.. just prints the points
vector<FFPOINT> BezierCurve(FFPOINT a, FFPOINT b, FFPOINT d, INT e)
{
	// 4 points define the bezier-curve. These are the points used
	// for the example-images on this page.
	FFPOINT c = b;
	vector<FFPOINT>px;
	px.clear();

	for (DWORD i = 0; i<(e+1); ++i)
	{
		FFPOINT p;
		float t = static_cast<float>(i) / (float)e;
		bezier(p, a, b, c, d, t);
		px.push_back(p);		
	}
	return px;
}
                                         //e % of
FFPOINT BezierCurve2(FFPOINT a, FFPOINT b, FFPOINT c, FFPOINT d, INT e, INT max)
{
	// 4 points define the bezier-curve. These are the points used
	// for the example-images on this page.
	



		FFPOINT p;
		float t = static_cast<float>(e) / 999.0f;
		bezier(p, a, b, c, d, t);

		//printf("%f %f\n", p.x, p.y);
	return  p ;
}

//raw test
FFPOINT TileToMouseTest222(FFPOINT ItemCoord)
{
	FLOAT xx = ItemCoord.x;
	FLOAT yy = ItemCoord.y;
	FLOAT zz = ReadCoordZ() - ItemCoord.z;
	FLOAT reshalfx = (GetRsResolution2().x) *512.f / 2.f;
	FLOAT reshalfy = (GetRsResolution2().y) *512.f / 2.f;


	FLOAT Realxx1=0;
	FLOAT Realyy2=0;
	//540 seems to be client minimal size, so below it should be cut off
	FLOAT adj=0;
	FLOAT adj2=0;
	FLOAT curveloc=0;
	FLOAT resy = GetRsResolution2().y;

///////client size/resolutsion correction/////////////////////////////////////////////////////////////
	//aiming 810 peak
	if (resy > 540.f && resy < 810.f) {
		//to 810
		curveloc = (resy - 540.f) / 270.f;
		adj = bezier2(0.f, 66.f, 127.f, curveloc) / 10.f;
	}
	if (resy >= 810.f && resy < 3841.f) {
		//up from 810
		curveloc = (resy - 810.f) / 270.f;
		adj = bezier2(126.f, 110.f, 105.f, curveloc) / 10.f;
		}
/////////////////////////////////////////////////////////////////////////////////////////////////////


	//height compress for y
	FLOAT	fish2y = (yy / 860.f);
	//height decompress y
	FLOAT	fish22y = (yy / 512.f);
	//upper x curve
	FLOAT	fish2x = (yy / (800.f- (adj*18.f)));
	//bottom x curve
	FLOAT	fish2x2 = (yy / (580.f - (adj*18.f)));

	// x spread diffrently in upper more, bottom less
	//bottom
	if (yy >= 0.f) {
		Realyy2 = (reshalfy + 5120.f) + (yy * (29.f + (adj*1.15f)+fish22y ));
		Realxx1 = (reshalfx)-(xx * (32.5f + adj + fish2x2));
		                                     //+fish22
	}
	//upper  
	else {
		Realyy2 = (reshalfy + 5120.f) + (yy * (30.f + (adj*0.70) + fish2y));
		Realxx1 = (reshalfx)-(xx * (32.5f + adj + fish2x));		
	}

	//elevation experiment
	if (ReadCoordZ() != NULL && ItemCoord.z != NULL && !GetAsyncKeyState(VK_ADD)) {
		Realyy2 = Realyy2 + zz*20.f;
		Realxx1 = Realxx1 + xx*(zz / 256.f);
	}
	FFPOINT p;
	p.x = Realxx1 / 512.f;
	p.y = Realyy2 / 512.f;
	return p;

}

//raw
FFPOINT TileToMouseTest22(FFPOINT ItemCoord)
{

	FLOAT xx = ReadCoordX3() - ItemCoord.x;
	FLOAT yy = ReadCoordY3() - ItemCoord.y;
	FLOAT zz = ReadCoordZ() - ItemCoord.z;
	FLOAT reshalfx = (GetRsResolution2().x) *512.f / 2.f;
	FLOAT reshalfy = (GetRsResolution2().y) *512.f / 2.f;


	FLOAT Realxx1 = 0;
	FLOAT Realyy2 = 0;
	//540 seems to be client minimal size, so below it should be cut off
	FLOAT adj = 0;
	FLOAT adj2 = 0;
	FLOAT curveloc = 0;
	FLOAT resy = GetRsResolution2().y;

	///////client size/resolutsion correction/////////////////////////////////////////////////////////////
	//aiming 810 peak
	if (resy > 540.f && resy < 810.f) {
		//to 810
		curveloc = (resy - 540.f) / 270.f;
		adj = bezier2(0.f, 66.f, 127.f, curveloc) / 10.f;
	}
	if (resy >= 810.f && resy < 3841.f) {
		//up from 810
		curveloc = (resy - 810.f) / 270.f;
		adj = bezier2(126.f, 110.f, 105.f, curveloc) / 10.f;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////


	//height compress for y
	FLOAT	fish2y = (yy / 860.f);
	//height decompress y
	FLOAT	fish22y = (yy / 512.f);
	//upper x curve
	FLOAT	fish2x = (yy / (800.f - (adj*18.f)));
	//bottom x curve
	FLOAT	fish2x2 = (yy / (580.f - (adj*18.f)));

	// x spread diffrently in upper more, bottom less
	//bottom
	if (yy >= 0.f) {
		Realyy2 = (reshalfy + 5120.f) + (yy * (29.f + (adj*1.15f) + fish22y));
		Realxx1 = (reshalfx)-(xx * (32.5f + adj + fish2x2));
		//+fish22
	}
	//upper  
	else {
		Realyy2 = (reshalfy + 5120.f) + (yy * (30.f + (adj*0.70) + fish2y));
		Realxx1 = (reshalfx)-(xx * (32.5f + adj + fish2x));
	}

	//elevation experiment
	if (ReadCoordZ() != NULL && ItemCoord.z != NULL && !GetAsyncKeyState(VK_ADD)) {
		Realyy2 = Realyy2 + zz*20.f;
		Realxx1 = Realxx1 + xx*(zz / 256.f);
	}
	FFPOINT p;
	p.x = Realxx1 / 512.f;
	p.y = Realyy2 / 512.f;
	return p;

}

//raw point
WPOINT TileToMouseTest24(FFPOINT ItemCoord)
{
	FLOAT xx = ReadCoordX3() - ItemCoord.x;
	FLOAT yy = ReadCoordY3() - ItemCoord.y;
	FLOAT zz = ReadCoordZ() - ItemCoord.z;
	FLOAT reshalfx = (GetRsResolution2().x) *512.f / 2.f;
	FLOAT reshalfy = (GetRsResolution2().y) *512.f / 2.f;


	FLOAT Realxx1 = 0;
	FLOAT Realyy2 = 0;
	//540 seems to be client minimal size, so below it should be cut off
	FLOAT adj = 0;
	FLOAT adj2 = 0;
	FLOAT curveloc = 0;
	FLOAT resy = GetRsResolution2().y;

	///////client size/resolutsion correction/////////////////////////////////////////////////////////////
	//aiming 810 peak
	if (resy > 540.f && resy < 810.f) {
		//to 810
		curveloc = (resy - 540.f) / 270.f;
		adj = bezier2(0.f, 66.f, 127.f, curveloc) / 10.f;
	}
	if (resy >= 810.f && resy < 3841.f) {
		//up from 810
		curveloc = (resy - 810.f) / 270.f;
		adj = bezier2(126.f, 110.f, 105.f, curveloc) / 10.f;
	}
	/////////////////////////////////////////////////////////////////////////////////////////////////////

	//if anyone wonders where those numbers came for adjustments, trial and error like all of this project

	//height compress for y
	FLOAT	fish2y = (yy / 860.f);
	//height decompress y
	FLOAT	fish22y = (yy / 512.f);
	//upper x curve
	FLOAT	fish2x = (yy / (800.f - (adj*18.f)));
	//bottom x curve
	FLOAT	fish2x2 = (yy / (580.f - (adj*18.f)));

	// x spread diffrently in upper more, bottom less
	//bottom
	if (yy >= 0.f) {
		Realyy2 = (reshalfy + 5120.f) + (yy * (29.f + (adj*1.15f) + fish22y));
		Realxx1 = (reshalfx)-(xx * (32.5f + adj + fish2x2));
		//+fish22
	}
	//upper  
	else {
		Realyy2 = (reshalfy + 5120.f) + (yy * (30.f + (adj*0.70) + fish2y));
		Realxx1 = (reshalfx)-(xx * (32.5f + adj + fish2x));
	}

	//elevation experiment
	if (ReadCoordZ() != NULL && ItemCoord.z != NULL && !GetAsyncKeyState(VK_ADD)) {
		Realyy2 = Realyy2 + zz*20.f;
		Realxx1 = Realxx1 + xx*(zz / 256.f);
	}

	QWPOINT rs=GetRSCorners();
	WPOINT p;
	p.x = rs.left + Realxx1/512.f;
	p.y = rs.top + Realyy2/512.f;
	if (p.x<3842 && p.y<2162) { return p; }
	else { cout<<dec << p.x<< ":" << p.y << "Error click coordinates outside of screen \n"; return{ 0,0 }; }
	return{ 0,0 };
}

//cooked
//for simba, point
POINT TileToMouseTest23(POINT ItemCoord)
{
	FLOAT xx = ReadCoordX3()/512.f - ItemCoord.x;
	FLOAT yy = ReadCoordY3()/512.f - ItemCoord.y;
	FLOAT reshalfx = (GetRsResolution2().y) / 2.f;
	FLOAT reshalfy = (GetRsResolution2().x) / 2.f;

	FLOAT yy2;
	FLOAT Realxx1;
	FLOAT Realyy2;
	FLOAT res = (GetRsResolution2().y) - 540.f;
	FFPOINT point;
	RECT desktop;
	const HWND hDesktop = GetDesktopWindow();
	GetWindowRect(hDesktop, &desktop);
	FLOAT resdivi = (desktop.bottom - desktop.top) / 1080.f;
	point.y = (desktop.bottom - desktop.top) / resdivi - 540.f;
	FLOAT adj;
	FLOAT adj2;

	//client size correction
	FLOAT curveloc = res / (point.y);
	//x
	if (curveloc<0.94f) {
		adj = bezier2(0.f, 160.f, 95.f, curveloc) / 10.f;
		if (res > 150.f && res < 360.f) { adj += 0.5f; }
		if (res > 200.f && res < 340.f) { adj += 0.5f; }
		if (res > 230.f && res < 320.f) { adj += 0.5f; }
		if (res > 250.f && res < 290.f) { adj += 0.5f; }
	}
	else {
		FLOAT curveloc2 = res / ((desktop.bottom - desktop.top - 540.f));
		adj = bezier2(-80.f, 220.f, 525.f, curveloc2) / 10.f;
	}//y
	if (curveloc<0.94f) {
		adj2 = bezier2(0.f, 120.f, 85.f, curveloc) / 10.f;
		if (res > 150.f && res < 360.f) { adj2 += 0.5f; }
		if (res > 200.f && res < 340.f) { adj2 += 0.5f; }
		if (res > 230.f && res < 320.f) { adj2 += 0.5f; }
		if (res > 250.f && res < 290.f) { adj2 += 0.5f; }
	}
	else {
		FLOAT curveloc2 = res / ((desktop.bottom - desktop.top - 540.f));
		adj2 = bezier2(-80.f, 160.f, 435.f, curveloc2) / 10.f;
	}


	//fisheye correction
	// outwards x

	//(8.f*adj2)//(6.3f*adj)
	FLOAT temp = (abs(xx)*abs(2.f / yy) / (abs(xx) + abs(2.f / yy)));
	//50 tile max 12800
	//25 rile 6400
	//my grid shows 13 tiles max
	//brake point at 10 tiles?
	FLOAT fish;
	//y12/x5-x5/y12=zero at center?
	//y-x = weight towards y if x is bigger then towards x
	//FLOAT edges = (abs(xx) - abs(yy)) / 512.f / 100.f;


	//(0.f, 20.f, 140.f
	fish = bezier2(0.f, 20.f, 140.f, (temp / 6400.f)) / 100.f;

	//height compress
	FLOAT	fish2 = (yy )*(0.5f + (0.012f*adj2));
	//height decompress
	FLOAT	fish22 = (yy*2.f)*(0.5f + (0.012f*adj2));
	//- abs(edges)


	// x spread diffrently in upper more, bottom less
	//bottom
	if (yy >= 0.f) {
		Realyy2 = (reshalfy + 20.f + reshalfy / 80.f) + (yy * (29.f + adj2 + fish22));
		Realxx1 = (reshalfx)-(xx * (32.f + adj + fish22));
	}
	//upper  
	else {
		Realyy2 = (reshalfy + 20.f + reshalfy / 80.f) + (yy * (29.f + adj2 + fish2));
		Realxx1 = (reshalfx)-(xx * (32.f + adj + fish2));
	}


	GetWindowRect(WProcC, &rs);
	POINT p;
	p.x = rs.left+ Realxx1;
	p.y = rs.top + Realyy2;
	return p;

}

POINT MouseToTile(POINT Mousecoords)
{
	POINT point;
	//lets imagine that 1step is 40 pixels
	INT xx = (Mousecoords.x- GetRsResolution2().x / 2) / 40;
	INT	yy = (GetRsResolution2().y / 2 - Mousecoords.y) / 40;
	INT xx1 = xx + CRL(MyLocXRaw);
	INT	yy2 = yy + CRL(MyLocYRaw);

	if (xx>0) { printf("Tiles to right: %d\n", xx); }
	if (xx<0) { printf("Tiles to left: %d\n", xx); }
	if (xx == 0) { printf("At player: %d\n", xx); }

	if (yy>0) { printf("Tiles to up: %d\n", yy); }
	if (yy<0) { printf("Tiles to down: %d\n", yy); }
	if (yy == 0) { printf("At player: %d\n", yy); }

	point.x = xx1;
	point.y = yy2;
	return point;
}

POINT TileToMem(INT x, INT y)
{
	POINT point;
	point.x = RXY(x);
	point.y =RXY(y);
	return point;
}
POINT TileToMem(POINT tiles)
{
	POINT point;
	point.x = RXY(tiles.x);
	point.y = RXY(tiles.y);
	return point;
}

FLOAT GetFloat(DWORD64 ang1) {

	if (!procIDs.empty())
	{

			FLOAT Read = VirtPReadFloat(ang1);
			//printf("Read1x: %I64X\n", Read);

			if (Read != NULL)
			{
				return Read;
			}
			else {
				return 0;
			}
	}
	return 0;
}

//rounded up
INT GetAngle() {

	if (!procIDs.empty())
	{
		if (ScAdd2 != NULL)
		{

			DWORD64 mainoffs1 = 0x101F0;
			DWORD64 offs2 = 0x20;
			DWORD64 offs3 = 0x40;
			DWORD64 ang1 = ScAdd2 + mainoffs1;
			DWORD64 ang2 = ang1 + offs2;

			FLOAT Read1 = VirtPReadFloat(ang1);
			FLOAT Read2 = VirtPReadFloat(ang2);
			FLOAT Read3 = GetFloat(ang1 - offs3);
			FLOAT Read4 = 0.f;

			if (Read1 != NULL)
			{
				Read4 = (1.800000f / Read3)*Read1;

				FLOAT test = (Read4) * 100.f;
				if (Read2>0) {
					//right half   
					return INT((((-1.f * (test - 180.f) / 2.f))) + 0.5);
				}
				else {
					return INT(((((test + 540.f) / 2.f)))+0.5);
				}
			}
			else {
				return 0;
			}

		}
	}
	return 0;
}

FLOAT GetAngleF() {

	if (!procIDs.empty())
	{
		if (ScAdd2 != NULL)
		{ 
			DWORD64 mainoffs1 = 0x101F0;
			DWORD64 offs2 = 0x20;
			DWORD64 offs3 = 0x40;
			DWORD64 ang1 = ScAdd2 + mainoffs1;
			DWORD64 ang2 = ang1 + offs2;
			// for tiletomouse
			TileCalc = VirtPReadFloat(ScAdd2+0x1744);

			FLOAT Read1 = VirtPReadFloat(ang1);
			FLOAT Read2 = VirtPReadFloat(ang2);
			FLOAT Read3 = GetFloat(ang1 - offs3);
			FLOAT Read4 = 0.f;

			if (Read1 != NULL && Read2 != NULL)
			{
		    	Read4=(1.800000f/Read3)*Read1;

				FLOAT test = (Read4) * 100.f;
				if (Read2>0.f) {
					//right half                        
					return ((-1.f * (test - 180.f) / 2.f) );
				}
				else {                             
					return (((test + 540.f) / 2.f));
				}
			}
			else {
				return 0;
			}
		}
	}
	return 0;
}

INT WorldToScreen(int x, int y, int z){


return 0;
}

//old
FFPOINT GetSlot( INT slot ) {

	BoxMidsx.clear();
	BoxMidsy.clear();

	if (InvBoxMemoryLoc == 0) {
		cout << "invboxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << "\n";
		InvBoxMemoryLoc = Locateinterface(1477, 107, 0xffff, 44);
	}
	else {
		FFPOINT temp = GetInterfaceData(InvBoxMemoryLoc).xys;
		{
			FLOAT x = temp.x;
			FLOAT y = temp.y;
			FLOAT box = 42.f;
			FLOAT boxy = 36.f;
			//divide into boxes
			INT ss = x / box;
			FLOAT sd = y / box;
			FLOAT divx = 0;
			FLOAT divy = 0;
			//slot =26;

			FLOAT;
			for (DWORD ii = 1; ii < 29; ii++) {
				//x by 45, y by one row
				FLOAT i = ii;
				divx = i; divy = boxy;

				if (i > (ss)) { divx = i - ss; divy = boxy * 2; }

				if (i > (2.f * ss)) {
					divx = i - 2.f*ss; divy = boxy*3.f;
				}
				if (i > (3.f * ss)) {
					divx = i - 3.f*ss; divy = boxy * 4.f;
				}
				if (i > (4.f * ss)) {
					divx = i - 4.f*ss; divy = boxy * 5.f;
				}
				if (i > (5.f * ss)) {
					divx = i - 5.f*ss; divy = boxy * 6.f;
				}
				if (i > (6.f * ss)) {
					divx = i - 6.f*ss; divy = boxy * 7.f;
				}
				if (i > (7.f * ss)) {
					divx = i - 7.f*ss; divy = boxy * 8.f;
				}
				if (i > (8.f * ss)) {
					divx = i - 8.f*ss; divy = boxy * 9.f;
				}
				if (i > (9.f * ss)) {
					divx = i - 9.f*ss; divy = boxy * 10.f;
				}
				if (i > (10.f * ss)) {
					divx = i - 10.f*ss; divy = boxy * 11.f;
				}
				if (i > (11.f * ss)) {
					divx = i - 11.f*ss; divy = boxy * 12.f;
				}

				FLOAT px = divx*box - box / 2;
				FLOAT py = divy - box / 2;

				//BoxMidsx.push_back(px);
				//BoxMidsy.push_back(py);

				FFPOINT p;
				if (slot == i - 1) {
					p.x = px;
					p.y = py;
					return p;
				}


			}
		}
	}
	return {0,0};
}

//old
FFPOINT GetsrealSlot(INT slot)  {

		if (InvBoxMemoryLoc == NULL) {
			// it seems main thing part is 2xffff end
			InvBoxMemoryLoc = Locateinterface(1477, 104, 0xffff, 19);
		}
		else {
			//active check
			DWORD bb3 = VirtPReadDword(InvBoxMemoryLoc + Ioff555);
			DWORD bb4 = VirtPReadDword(InvBoxMemoryLoc + Ioff666);
			//ids
			WORD bb5 = VirtPReadWord(InvBoxMemoryLoc + Ioff55);
			WORD bb7 = VirtPReadWord(InvBoxMemoryLoc + Ioff55 + 4);
			WORD bb8 = VirtPReadWord(InvBoxMemoryLoc + Ioff55 + 6);
			WORD bb9 = VirtPReadWord(InvBoxMemoryLoc + Ioff55 + 8);
			//check if interface is still in same place
			if ((bb3 > 0 && bb3 < 4) && (bb4 > 0 && bb4 < 3) && (bb5 == 1477 && bb7 == 104 && bb8 == 0xffff && bb9 == 19)) {
			}
			else { InvBoxMemoryLoc = Locateinterface(1477, 104, 0xffff, 19); }
			if ((bb3 > 0 && bb3 < 4) && (bb4 > 0 && bb4 < 3) && (bb5 == 1477 && bb7 == 104 && bb8 == 0xffff && bb9 == 19)) {
	     	FFPOINT start = GetInterfaceData(InvBoxMemoryLoc).xy;
			FFPOINT sl = GetSlot(slot);
			FFPOINT p;

			p.x = sl.x + start.x+5.f;
			//+30=?
			p.y = sl.y + start.y+47.f;
			return p;

		}
	}
	return{ 0,0 };
}

//not finished
FFPOINT GetsrealSlotForLoot(INT slot) {

	if (InvBoxMemoryLoc == NULL) {
		// it seems main thing part is 2xffff end
		InvBoxMemoryLoc = Locateinterface(1477, 107, 0xffff, 44);
	}
	else {
		//active check
		DWORD bb3 = VirtPReadDword(InvBoxMemoryLoc + Ioff555);
		DWORD bb4 = VirtPReadDword(InvBoxMemoryLoc + Ioff666);
		//ids
		WORD bb5 = VirtPReadWord(InvBoxMemoryLoc + Ioff55);
		WORD bb7 = VirtPReadWord(InvBoxMemoryLoc + Ioff55 + 4);
		WORD bb8 = VirtPReadWord(InvBoxMemoryLoc + Ioff55 + 6);
		WORD bb9 = VirtPReadWord(InvBoxMemoryLoc + Ioff55 + 8);
		//check if interface is still in same place
		if ((bb3 > 0 && bb3 < 4) && (bb4 > 0 && bb4 < 3) && (bb5 == 1477 && bb7 == 107 && bb8 == 0xffff && bb9 == 44)) {
		}
		else { InvBoxMemoryLoc = Locateinterface(1477, 107, 0xffff, 44); }
		if ((bb3 > 0 && bb3 < 4) && (bb4 > 0 && bb4 < 3) && (bb5 == 1477 && bb7 == 107 && bb8 == 0xffff && bb9 == 44)) {
			FFPOINT start = GetInterfaceData(InvBoxMemoryLoc).xy;
			FFPOINT sl = GetSlot(slot);
			FFPOINT p;

			p.x = sl.x + start.x + 5.f;
			//+30=?
			p.y = sl.y + start.y + 47.f;
			return p;

		}
	}
	return{ 0,0 };
}

//Tile to screen pixels
//simba
POINT TToScreen(POINT spot) {

	if (spot.x != NULL && spot.y != NULL)
	{
		return TileToMouseTest23(spot);
	}
	return{ 0,0 };
}

//Tile to screen pixels
WPOINT TToScreen2(FFPOINT spot) {

	if (spot.x != NULL && spot.y != NULL)
	{
		return TileToMouseTest24(spot);
	}
	return{ 0,0 };
}

//Tile to map
//simba
POINT TToMap(POINT spot) {


	if (spot.x != NULL && spot.y != NULL)
	{
		return ToMap(spot);
	}
	return{ 0,0 };
}

//finds inv stuff
WPOINT InvFindItem(DWORD item) {

	FilterInventory();
	if (!InvId.empty()) {		
		for (DWORD i = 0; i < InvId.size(); i++) {
			if (InvId[i] == item) {
				return{ Invx[i],Invy[i]};
			}
		}
	}
	return{ 0,0 };
}

BOOLEAN ClickInv_(DWORD item) {
	WORD resyt = rs.top;
	WORD resxl = rs.left;
	WORD resyy = GetRsResolution2().y;
	POINT c, c2;
	GetCursorPos(&c);
	RandomSleep();
	GetCursorPos(&c2);
	if (c.x != c2.x || c.y != c2.y) {
		Sleep(5000);
	}
	else
	{
		WPOINT screenp = InvFindItem(item);
		//cout << resxl << ":" << resyt << endl;
		if (screenp.x != 0 && screenp.y != 0 && screenp.x < 4000 && screenp.y < 4000) {
			screenp.x = screenp.x - 7 + resxl; screenp.y = screenp.y - 7 +  resyt;
			MoveMouse(screenp.x, screenp.y, 14, 20);
			RandomSleep2(25, 550, 3000);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			RandomSleep2(100, 1050, 4000);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
			return TRUE;
		}
	}
	return FALSE;
}

BOOLEAN ClickTile_(POINT tile,BYTE minimap) {
	FFPOINT p = PlayerCoordFloatRaw();
	POINT c, c2;
	GetCursorPos(&c);
	RandomSleep();
	GetCursorPos(&c2);
	if (c.x != c2.x || c.y != c2.y) {
		Sleep(5000);
	}
	else
	{
		if (minimap == 0) {
			if (tile.x != NULL && tile.y != NULL) {
				FFPOINT tile512 = { tile.x*512.f,tile.y*512.f };
				FLOAT dist = sqrt(pow(tile512.x - p.x, 2) + pow(tile512.y - p.y, 2));
				if (dist < (6.f*512.f)) {
					WPOINT screenp = TToScreen2({ tile512.x, tile512.y });
					if (screenp.x != 0 && screenp.y != 0) {
						screenp.x = screenp.x - 7; screenp.y = screenp.y - 10;
						MoveMouse(screenp.x, screenp.y, 14, 20);
						//hover = VirtPReadDword(MatchNPCsMBlock[i] + npcoff111);
						RandomSleep2(25, 550, 3000);
						//hover2 = VirtPReadDword(MatchNPCsMBlock[i] + npcoff111);
						//if (hover != hover2) {
						mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
						RandomSleep2(100, 1050, 4000);
						mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
						return TRUE;
						//}
					}
				}
				else
				{
					WPOINT screenp = ToMapFFPOINT2({ tile512.x, tile512.y });
					if (screenp.x != 0 && screenp.y != 0) {
						screenp.x = screenp.x - 4; screenp.y = screenp.y - 4;
						MoveMouse(screenp.x, screenp.y, 4, 4);
						RandomSleep2(25, 550, 3000);
						mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
						RandomSleep2(100, 1050, 4000);
						mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
						return TRUE;
					}
				}
			}
		}
		else {
			if (tile.x != NULL && tile.y != NULL) {
				FFPOINT tile512 = { tile.x*512.f,tile.y*512.f };
				FLOAT dist = sqrt(pow(tile512.x - p.x, 2) + pow(tile512.y - p.y, 2));
				if (dist < (6.f*512.f)) {
					WPOINT screenp = TToScreen2({ tile512.x, tile512.y });
					if (screenp.x != 0 && screenp.y != 0 && minimap == 1) {
						screenp.x = screenp.x - 7; screenp.y = screenp.y - 10;
						MoveMouse(screenp.x, screenp.y, 14, 20);
						//hover = VirtPReadDword(MatchNPCsMBlock[i] + npcoff111);
						RandomSleep2(25, 550, 3000);
						//hover2 = VirtPReadDword(MatchNPCsMBlock[i] + npcoff111);
						//if (hover != hover2) {
						mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
						RandomSleep2(100, 1050, 4000);
						mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
						return TRUE;
						//}
					}
				}
				else
				{
					WPOINT screenp = ToMapFFPOINT2({ tile512.x, tile512.y });
					if (screenp.x != 0 && screenp.y != 0 && minimap == 2) {
						screenp.x = screenp.x - 4; screenp.y = screenp.y - 4;
						MoveMouse(screenp.x, screenp.y, 4, 4);
						RandomSleep2(25, 550, 3000);
						mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
						RandomSleep2(100, 1050, 4000);
						mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
						return TRUE;
					}
				}
			}
		}
	}
	return FALSE;
}

//finds invf
BOOLEAN InvFull() {
	INT count=0;

	FilterInventory();
	if (!InvId.empty()) {
		for (DWORD i = 0; i < InvId.size(); i++) {
			if (InvId[i] != 0) {
				count++;
			}
		}
		//cout << dec << count << endl;
		if (count == 28) { return true; }
	}
	return false;
}

//finds inv item count
BYTE InvItemcount_(DWORD item) {
	INT count = 0;

	FilterInventory();
	if (!InvId.empty()) {
		for (DWORD i = 0; i < InvId.size(); i++) {
			if (InvId[i] == item) {
				count++;
			}
		}
		return count;
	}
	return 0;
}

//finds free slots count
BYTE Invfreecount() {
	INT count = 0;

	FilterInventory();
	if (!InvId.empty()) {
		for (DWORD i = 0; i < InvId.size(); i++) {
			if (InvId[i] == 0) {
				count++;
			}
		}
		return count; 
	}
	return 0;
}

//memory conversion open, divination
BOOLEAN DiviOpen_() {

	FFPOINT size;
	//cout << hex << BankTemp << endl;
	if (InterfCheck(DiviTemp, 131, 4, 0xffff, 2)) {
		size = GetInterfaceData(DiviTemp).xys;
	}
	else {
		DiviTemp = Locateinterface(131, 4, 0xffff, 2);
		if (InterfCheck(DiviTemp, 131, 4, 0xffff, 2)) {
			size = GetInterfaceData(DiviTemp).xys;
		}
	}
	if (size.x != 0 && size.y != 0) {
		return TRUE;
	}
	return FALSE;
}

//Bank open check
BOOLEAN BankOpen_() {

	FFPOINT size;
	//cout << hex << BankTemp << endl;
	if (InterfCheck(BankTemp, 762, 3, 0xffff, 2)) {
		size = GetInterfaceData(BankTemp).xys;
	}
	else {
		BankTemp = Locateinterface(762, 3, 0xffff, 2);
		if (InterfCheck(BankTemp, 762, 3, 0xffff, 2)) {
			size = GetInterfaceData(BankTemp).xys;
		}
	}
		if (size.x != 0 && size.y != 0) {
			return TRUE;
		}
	return FALSE;
}

//Progress running
BOOLEAN ProgressOpen_() {

	FFPOINT size;
	//cout <<hex<< ProgTemp << endl;
	if (InterfCheck(ProgTemp, 1251, 7, 0xffff, 0xffff)) {
		size = GetInterfaceData(ProgTemp).xys;
	}
	else {
		ProgTemp = Locateinterface(1251, 7, 0xffff, 0xffff);
		if (InterfCheck(ProgTemp, 1251, 7, 0xffff, 0xffff)) {
			size = GetInterfaceData(ProgTemp).xys;
		}
	}
	if (size.x != 0 && size.y != 0) {
		return TRUE;
	}
	return FALSE;
}

//choose item do to
BOOLEAN ChooseIOpen_() {

	FFPOINT size;
	//cout << hex << ChooseITemp << endl;
	if (InterfCheck(ChooseITemp,1370, 4, 0xffff, 0xffff)) {
		size = GetInterfaceData(ChooseITemp).xys;
	}
	else {
		ChooseITemp = Locateinterface(1370, 4, 0xffff, 0xffff);
		if (InterfCheck(ChooseITemp, 1370, 4, 0xffff, 0xffff)) {
			size = GetInterfaceData(ChooseITemp).xys;
		}
	}
		if (size.x != 0 && size.y != 0) {
			return TRUE;
		}
	return FALSE;
}

//choose tool
BOOLEAN ChooseTOpen_() {

	FFPOINT size;
	if (InterfCheck(ChooseTTemp, 1179, 21, 0xffff, 0xffff)) {
		size = GetInterfaceData(ChooseTTemp).xys;
	}
	else {
		ChooseTTemp = Locateinterface(1179, 21, 0xffff, 0xffff);
		if (InterfCheck(ChooseTTemp, 1179, 21, 0xffff, 0xffff)) {
			size = GetInterfaceData(ChooseTTemp).xys;
		}
	}
	if (size.x != 0 && size.y != 0) {
		return TRUE;
	}
	return FALSE;
}

//choose loot open
BOOLEAN ChooseLoot_() {
	 
	FFPOINT size;
	if (InterfCheck(LootTemp, 1622, 4, 0xffff, 0xffff)) {
		size = GetInterfaceData(LootTemp).xys;
	}
	else {
		LootTemp = Locateinterface(1622, 4, 0xffff, 0xffff);
		if (InterfCheck(LootTemp, 1622, 4, 0xffff, 0xffff)) {
			size = GetInterfaceData(LootTemp).xys;
		}
	}
	if (size.x != 0 && size.y != 0) {
		return TRUE;
	}
	return FALSE;
}


////////////////////////////////////////////////////////////////////
//sleepy,sometimes longer
VOID RandomSleep() {

	if ((rand() % 100)>97) {
		Sleep(5 + rand() % 2000);
	}
	else {
		Sleep(5 + rand() % 200);
	}
}

//sleepy, First static wait time, second short common, third rarer long sleep
VOID RandomSleep2(DWORD wait ,DWORD sleep, DWORD sleep2){

	if (RandomGener2(100)>96) {
		Sleep(5 + wait + RandomGener2(sleep2));
	}
	else {
		Sleep(5 + wait + RandomGener2(sleep));
	}
}

//windoz api keyboard
VOID KeyPress_(char mK) {
	KeyboardPress(mK, 50,2000);
}

POINT MousePos_() {
	//GetWindowRect(WProcC, &rs);
	//WORD resyt = rs.top;
	//WORD resxl = rs.left;
	//WORD resyy = GetRsResolution2().y;

	POINT p;
	GetCursorPos(&p);	
	return{ p.x - rs.left ,p.y - rs.top };
}

//windoz mouseclick for rs window
VOID MouseCLRS(POINT cursor, BOOLEAN type) {
	GetWindowRect(WProcC, &rs3);

	if (cursor.x != 0 && cursor.y != 0) {
		cursor.x = cursor.x + rs3.left;
		cursor.y = cursor.y + rs3.top;
		MoveMouse2(cursor.x, cursor.y, 10, 10);
		if (type) {
			MouseLeftClick(100, 1200);
		}
		else {
			MouseRightClick(100, 1200);
		}
	}
}

//windoz drag// point a to b for RS window
VOID MouseDrag_RS(POINT cursor, POINT cursor2) {

	GetWindowRect(WProcC, &rs3);
	InterceptionContext context;
	InterceptionMouseStroke mstroke;
	context = interception_create_context();

	if (cursor.x != 0 && cursor.y != 0 && cursor2.x != 0 && cursor2.y != 0) {
		cursor.x = cursor.x + rs3.left;
		cursor.y = cursor.y + rs3.top;
		cursor2.x = cursor2.x + rs3.left;
		cursor2.y = cursor2.y + rs3.top;
		MoveMouse2(cursor.x, cursor.y, 10, 10);
		RandomSleep2(25, 550, 3000);
		mstroke.flags = INTERCEPTION_MOUSE_MOVE_ABSOLUTE;
		mstroke.state = INTERCEPTION_MOUSE_LEFT_BUTTON_DOWN;
		mstroke.x = static_cast<int>((0xFFFF * (xyhold2.x)) / screen_width2);
		mstroke.y = static_cast<int>((0xFFFF * (xyhold2.y)) / screen_height2);
		interception_send(context, mouse, (InterceptionStroke *)&mstroke, 1);
		RandomSleep2(100, 2050, 4000);
		MoveMouse2(cursor2.x, cursor2.y, 10, 10);
		RandomSleep2(100, 2050, 4000);
		mstroke.state = INTERCEPTION_MOUSE_LEFT_BUTTON_UP;
		mstroke.x = static_cast<int>((0xFFFF * (xyhold2.x)) / screen_width2);
		mstroke.y = static_cast<int>((0xFFFF * (xyhold2.y)) / screen_height2);
		interception_send(context, mouse, (InterceptionStroke *)&mstroke, 1);
		RandomSleep2(100, 2050, 4000);
	}
}

//move a mouse, rs focus
VOID MouseMove_(POINT cursor) {

	GetWindowRect(WProcC, &rs3);

	if (cursor.x != 0 && cursor.y != 0) {
		cursor.x = cursor.x + rs3.left;
		cursor.y = cursor.y + rs3.top;
		MoveMouse2(cursor.x, cursor.y, 10, 10);
		RandomSleep2(100, 2050, 4000);
	}
}

//move a mouse, rs focus
VOID MouseMove_2(int x, int y, int rx, int ry) {

	GetWindowRect(WProcC, &rs3);

	if (x != 0 && y != 0) {
		x = x +rs3.left;;
		y = y +rs3.top;
		MoveMouse2(x, y, 10, 10);
		RandomSleep2(100, 2050, 4000);
	}
}

//never returns 0, reason is divided by zero
double RandomGener(double number) {
	if (number>0.0) {
		uniform_real_distribution<double> distribution(0.01, number);
		return distribution(generator);
	}
	return 0.01;
}

//small random thing
DWORD RandomGener2(DWORD number) {
	if (number>0) {
		uniform_int_distribution<DWORD> distribution(1, number);
		return distribution(generator);
	}
	return 1;
}

///////////////////////////////////////////////////////////////////////
	int mouseSpeed = rand() % 10 + 50;
	void MoveMouse(int x, int y, int rx, int ry) {
		POINT c;
		GetCursorPos(&c);
		x += RandomGener(rx); 
		y += RandomGener(ry);  


		double randomSpeed = max((RandomGener(mouseSpeed) / 2.0 + mouseSpeed) / 10.0, 0.1);

		WindMouse(c.x, c.y, x, y, 9.0, 3.0, 10.0 / randomSpeed,
			15.0 / randomSpeed, 10.0 * randomSpeed, 10.0 * randomSpeed);

	}

	void WindMouse(double xs, double ys, double xe, double ye,
		double gravity, double wind, double minWait, double maxWait,
		double maxStep, double targetArea) {

		double dist, windX = 0.1, windY = 0.1, veloX = 0.1, veloY = 0.1, randomDist, veloMag, step;
		int oldX, oldY, newX = (int)round(xs), newY = (int)round(ys);

		double waitDiff = maxWait - minWait;
		double sqrt2 = sqrt(2.0);
		double sqrt3 = sqrt(3.0);
		double sqrt5 = sqrt(5.0);
		dist = Hypot(xe - xs, ye - ys);
		while (dist > 1.0) {

			wind = min(wind, dist);
			if (dist >= targetArea) {
				int w = (RandomGener((int)round(wind) * 2 + 1));
					windX = (windX / sqrt3 + (w - wind) / sqrt5);
					windY = (windY / sqrt3 + (w - wind) / sqrt5);			
			}
			else {
					windX = (windX / sqrt2);
					windY = (windY / sqrt2);			
				if (maxStep < 3)
					maxStep = (RandomGener(3) + 3.0);
				else
					
						maxStep = (maxStep / sqrt5);				
			}

			veloX += windX;
			veloY += windY;
				veloX = (veloX + gravity * (xe - xs) / dist);
				veloY = (veloY + gravity * (ye - ys) / dist);


			if (Hypot(veloX, veloY) > maxStep) {
					randomDist = maxStep / 2.0 + RandomGener((int)round(maxStep) / 2);
				veloMag = (Hypot(veloX, veloY));
					veloX = ((veloX / veloMag) * randomDist);
					veloY = ((veloY / veloMag) * randomDist);
				
			}


			oldX = (int)round(xs);
			oldY = (int)round(ys);
			xs += veloX;
			ys += veloY;
			dist = Hypot(xe - xs, ye - ys);
			newX = (int)round(xs);
			newY = (int)round(ys);

			if (oldX != newX || oldY != newY)
				SetCursorPos(newX, newY);

			step = Hypot(xs - oldX, ys - oldY);
			int wait = (int)round(waitDiff * (step / maxStep) + minWait);
			Sleep(wait);
		}

		int endX = (int)round(xe);
		int endY = (int)round(ye);
		if (endX != newX || endY != newY)
			SetCursorPos(endX, endY);
	}


	void WindMouse2(double xs, double ys, double xe, double ye,
		double gravity, double wind, double minWait, double maxWait,
		double maxStep, double targetArea) {
		if (mouse && CheckRS3()) {
			InterceptionContext context;
			InterceptionMouseStroke mstroke;
			context = interception_create_context();
			mstroke.flags = INTERCEPTION_MOUSE_MOVE_ABSOLUTE;
			mstroke.state = INTERCEPTION_MOUSE_LEFT_BUTTON_UP;
			double dist, windX = 0.1, windY = 0.1, veloX = 0.1, veloY = 0.1, randomDist, veloMag, step;
			int oldX, oldY, newX = (int)round(xs), newY = (int)round(ys);

			double waitDiff = maxWait - minWait;
			double sqrt2 = sqrt(2.0);
			double sqrt3 = sqrt(3.0);
			double sqrt5 = sqrt(5.0);
			dist = Hypot(xe - xs, ye - ys);
			while (dist > 1.0) {

				wind = min(wind, dist);
				if (dist >= targetArea) {
					int w = (RandomGener((int)round(wind) * 2 + 1));
					windX = (windX / sqrt3 + (w - wind) / sqrt5);
					windY = (windY / sqrt3 + (w - wind) / sqrt5);
				}
				else {
					windX = (windX / sqrt2);
					windY = (windY / sqrt2);
					if (maxStep < 3)
						maxStep = (RandomGener(3) + 3.0);
					else

						maxStep = (maxStep / sqrt5);
				}

				veloX += windX;
				veloY += windY;
				veloX = (veloX + gravity * (xe - xs) / dist);
				veloY = (veloY + gravity * (ye - ys) / dist);


				if (Hypot(veloX, veloY) > maxStep) {
					randomDist = maxStep / 2.0 + RandomGener((int)round(maxStep) / 2);
					veloMag = (Hypot(veloX, veloY));
					veloX = ((veloX / veloMag) * randomDist);
					veloY = ((veloY / veloMag) * randomDist);

				}


				oldX = (int)round(xs);
				oldY = (int)round(ys);
				xs += veloX;
				ys += veloY;
				dist = Hypot(xe - xs, ye - ys);
				newX = (int)round(xs);
				newY = (int)round(ys);

				if (oldX != newX || oldY != newY) {
					mstroke.x = static_cast<int>((0xFFFF * (xyhold2.x + newX)) / screen_width2);
					mstroke.y = static_cast<int>((0xFFFF * (xyhold2.y + newY)) / screen_height2);
					interception_send(context, mouse, (InterceptionStroke *)&mstroke, 1);
					step = Hypot(xs - oldX, ys - oldY);
					int wait = (int)round(waitDiff * (step / maxStep) + minWait);
					Sleep(wait);
				}
			}

			int endX = (int)round(xe);
			int endY = (int)round(ye);
			if (endX != newX || endY != newY) {
				mstroke.x = static_cast<int>((0xFFFF * (xyhold2.x + newX)) / screen_width2);
				mstroke.y = static_cast<int>((0xFFFF * (xyhold2.y + newY)) / screen_height2);
				interception_send(context, mouse, (InterceptionStroke *)&mstroke, 1);
			}
			xyhold2.x = xyhold2.x + newX;
			xyhold2.y = xyhold2.y + newY;
			interception_destroy_context(context);
		}
	}


	 double Hypot(double dx, double dy) {
			 return sqrt(dx * dx + dy * dy);
	}

	 //moves mouse around all windows desktop
	 void MoveMouse2(int x, int y, int rx, int ry) {
		 if (x>0 && y>0 && x<screen_width2 && y<screen_height2) {
			 x += RandomGener2(rx);
			 y += RandomGener2(ry);

			 double randomSpeed = max((RandomGener(mouseSpeed) / 2.0 + mouseSpeed) / 10.0, 0.1);
			 WORD xxx = xyhold2.x / RandomGener2(2000);
			 WORD yyy = xyhold2.y / RandomGener2(2000);

			 WindMouse2(xxx, yyy, x - xyhold2.x, y - xyhold2.y, 9.0, 3.0, 10.0 / randomSpeed,
				 15.0 / randomSpeed, 10.0 * randomSpeed, 10.0 * randomSpeed);
		 }
	 }

//click,how long to hold mouse down
VOID MouseLeftClick(WORD sleep,WORD rand) {
	if (mouse && CheckRS3()) {
		InterceptionContext context; 
		InterceptionMouseStroke mstroke;
		context = interception_create_context();
		mstroke.flags = INTERCEPTION_MOUSE_MOVE_ABSOLUTE;
		mstroke.state = INTERCEPTION_MOUSE_LEFT_BUTTON_DOWN;
		mstroke.x = static_cast<int>((0xFFFF * (xyhold2.x)) / screen_width2);
		mstroke.y = static_cast<int>((0xFFFF * (xyhold2.y)) / screen_height2);
		interception_send(context, mouse, (InterceptionStroke *)&mstroke, 1);
		Sleep(sleep + RandomGener2(rand));
		mstroke.state = INTERCEPTION_MOUSE_LEFT_BUTTON_UP;
		mstroke.x = static_cast<int>((0xFFFF * (xyhold2.x)) / screen_width2);
		mstroke.y = static_cast<int>((0xFFFF * (xyhold2.y)) / screen_height2);
		interception_send(context, mouse, (InterceptionStroke *)&mstroke, 1);
		interception_destroy_context(context);
	}
}

//rigth click,how long to hold mouse
VOID MouseRightClick(WORD sleep, WORD rand) {
	if (mouse && CheckRS3()) {
		InterceptionContext context;
		InterceptionMouseStroke mstroke;
		context = interception_create_context();
		mstroke.flags = INTERCEPTION_MOUSE_MOVE_ABSOLUTE;
		mstroke.state = INTERCEPTION_MOUSE_RIGHT_BUTTON_DOWN;
		mstroke.information = 0;
		mstroke.x = static_cast<int>((0xFFFF * (xyhold2.x)) / screen_width2);
		mstroke.y = static_cast<int>((0xFFFF * (xyhold2.y)) / screen_height2);
		interception_send(context, mouse, (InterceptionStroke *)&mstroke, 1);
		Sleep(sleep + RandomGener2(rand));
		mstroke.state = INTERCEPTION_MOUSE_RIGHT_BUTTON_UP;
		mstroke.x = static_cast<int>((0xFFFF * (xyhold2.x)) / screen_width2);
		mstroke.y = static_cast<int>((0xFFFF * (xyhold2.y)) / screen_height2);
		interception_send(context, mouse, (InterceptionStroke *)&mstroke, 1);
		interception_destroy_context(context);
	}
}

//
VOID KeyboardPress(char codes,WORD sleep, WORD rand) {
	if (keyboard && CheckRS3()) {
		InterceptionKeyStroke kstroke;		
		InterceptionContext context;
		context = interception_create_context();
		kstroke.state = INTERCEPTION_KEY_DOWN;
		kstroke.information = 0;
		WORD c = codes;
		//
		kstroke.code = c-59;
		interception_send(context, keyboard, (InterceptionStroke *)&kstroke, 1);
	    Sleep(sleep + RandomGener2(rand));
		kstroke.state = INTERCEPTION_KEY_UP;
		interception_send(context, keyboard, (InterceptionStroke *)&kstroke, 1);
		interception_destroy_context(context);
	}
}

VOID LSA0() {

	 GetWindowsRes();
	if (ScAdd1 == NULL || R7 == 1) {
		R7 = 0;
		cout << "Lookin for Allobj array" << "\n";
			ScAdd1 = ScanAllObjects();
	}


	//most critical
	//player location
	if (ScAdd1 != NULL) {
		R1 = 0;
		cout << "Lookin for Players array" << "\n";
		ReadCObjArrays();
		FindLP();
		MEMss BlockA;
		//BlockA = DeterMemoryBlockLenght(0x1ed98066010);
	//	cout <<"Start:"<<hex<< BlockA.start << "\n";
	//	cout <<"Size:"<< hex << BlockA.size << "\n";
	 //  BlockA = DeterMemoryBlockLenght(0x1ed989ea230);
	//	cout << hex << BlockA.start << "\n";
	//	cout << hex << BlockA.size << "\n";
		RefVarpBits1();
	}
	
	//SettingsStart = ScanSet();
	//if (LocalPlayer != NULL) {
	//	cout << dec << PlayerCoordFloatRaw().x << ":" << PlayerCoordFloatRaw().y << endl;
	//	cout << hex<< ReadCoordX3i()<<":"<< ReadCoordY3i() << endl;
	//}
	//if (R2 == 1 && LocalPlayer!=NULL) {
	//	R2 = 0;
	//	Exe1 = ScanforExe1();
	//	//Exe2 =ScanforExe2();
	//	Exe3 = ScanforExe3();
	//	Exe4 = ScanforExe4();
	//	Exe5 = ScanforExe5();
	//	Exe6 = ScanforExe6();
		//Exe7 = ScanforExe7();
	

	//}
}

VOID LSA1() {
	if (ScAdd1 != NULL) {
		vector<DWORD> offsets5 = {};
		vector<WORD> bytes5 = {};
		vector<BOOLEAN> UPDOWN5 = {};

		//build ver with 8 at start(38ascii)
		PatternSearch PS9{
			0x42, 0x75, 0x69, 0x6c, 0x64, 0x3a, 0x20, 0x38
		};

		//if (LocalPlayer != NULL || R3 == 1) {
		//	R3 = 0;
		//	cout << "Lookin for Npc array" << "\n";
		//	if (NPCAdd == NULL) {
		//		NPCAdd = ScanNPCs();
		//	}
		//}
		//else {
		//	FindLP();
		//}
		//rev
		if (ScAdd9 == NULL || R4 == 1) {
			R4 = 0;
			cout << "Lookin for revision" << "\n";
			DWORD64 ScanPlaceHolder = ScAdd1;
			DWORD64 ScanStart;
			DWORD64 ScanEnd;
			if (ScanBack > ScanPlaceHolder) { ScanStart = 500000; }
			else {
				ScanStart = ScanPlaceHolder - ScanBack;
			}
			ScanEnd = ScanPlaceHolder + ScanFoward;
			if (ScanEnd > RSExeStart) { ScanEnd = RSExeStart; }

			ScAdd9 = ScanMAdvanced22(PS9, ScanStart, ScanEnd, "res: ", offsets5, bytes5, UPDOWN5);
			Revision = ReadText(ScAdd9);
		}
		
		if (SL == NULL || HP==NULL || R5 == 1) {
			R5 = 0;
			 
		}
	}
}
VOID LSA2() {	
	IF = ScanInteraceArray();
}
VOID LSA3() {
	if (Compass == NULL || R10 == 1) {
		R10 = 0;
		Compass = SearchCompass();
	}
}
VOID LSA4() {
	//interface	
	INVIArr = ScanForInvArray();
	//BANKArr = ScanForBankArray();
}



INT LocateStartAddresses(){
	if (!procIDs.empty()){
		DWORD64 TimeStart = 0;
		TimeStart = SystemTime();
   thread t00(LSA0);
	t00.join();
	thread t11(LSA1);	
	thread t22(LSA2);
	thread t33(LSA3);
	thread t44(LSA4);
	t11.join();
	t22.join();
	t33.join();
	t44.join();
	cout << "Whole scan took:" << (SystemTime() - TimeStart)/1000.f <<" Seconds. \n";
		LoadItemText();
		LoadClueScrolls();
	}
	return 0;
}


///checks if active
BOOLEAN ActivHover(DWORD64 summ) {

		DWORD64 off1 = summ -0xe8;

		DWORD Read1 = VirtPReadDword(off1);
		Sleep(40);
		DWORD Read2 = VirtPReadDword(off1);


		if (Read1 != Read2){
			//cout << "hover1";
			return TRUE;
		}
		else {
			//cout << "hover2";
			return FALSE;
		}
	return FALSE;
}

string ReadText(DWORD64 spot)
{
	if (spot != NULL) {
		DWORD64 SummPointer = spot;
		DWORD64 val = NULL;
		DWORD64 val2 = NULL;
		DWORD64 val3 = NULL;
		DWORD64 val4 = NULL;
		DWORD64 val5 = NULL;
		DWORD64 val6 = NULL;
		DWORD64 val7 = NULL;
		DWORD64 val8 = NULL;
		DWORD64 val9 = NULL;
		BOOLEAN zeroterm = NULL;
		string chars;

			proc.remote().memory().Read(SummPointer, sizeof(val), &val);
			proc.remote().memory().Read(SummPointer + 0x8, sizeof(val2), &val2);
			proc.remote().memory().Read(SummPointer + 0x10, sizeof(val3), &val3);
			proc.remote().memory().Read(SummPointer + 0x18, sizeof(val4), &val4);
			proc.remote().memory().Read(SummPointer + 0x20, sizeof(val5), &val5);
			proc.remote().memory().Read(SummPointer + 0x28, sizeof(val6), &val6);
			proc.remote().memory().Read(SummPointer + 0x30, sizeof(val7), &val7);
			proc.remote().memory().Read(SummPointer + 0x38, sizeof(val8), &val8);
			proc.remote().memory().Read(SummPointer + 0x40, sizeof(val9), &val9);


			int c = 0;
			for (DWORD i = 0; i < 8; i++) {
				uint8_t b = ((val >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			c = 0;
			for (DWORD i = 0; i < 8; i++) {
				BYTE b = ((val2 >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			c = 0;
			for (DWORD i = 0; i < 8; i++) {
				BYTE b = ((val3 >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			c = 0;
			for (DWORD i = 0; i < 8; i++) {
				BYTE b = ((val4 >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			c = 0;
			for (DWORD i = 0; i < 8; i++) {
				BYTE b = ((val5 >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			c = 0;
			for (DWORD i = 0; i < 8; i++) {
				BYTE b = ((val6 >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			c = 0;
			for (DWORD i = 0; i < 8; i++) {
				BYTE b = ((val7 >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			c = 0;
			for (DWORD i = 0; i < 8; i++) {
				BYTE b = ((val8 >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			c = 0;
			for (DWORD i = 0; i < 8; i++) {
				BYTE b = ((val9 >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			return chars;

	}
	else { return{ 0 }; }
}

string ReadUpText()
{
	if (ScAdd8 != NULL) {
		DWORD64 SummPointer = ScAdd8 - 0x5680 + 0x838;
		DWORD64 val = NULL;
		DWORD64 val2 = NULL;
		DWORD64 val3 = NULL;
		DWORD64 val4 = NULL;
		DWORD64 val5 = NULL;
		DWORD64 val6 = NULL;
		DWORD64 val7 = NULL;
		DWORD64 val8 = NULL;
		DWORD64 val9 = NULL;
		BOOLEAN zeroterm = NULL;
		string chars;


		if (ActivHover(SummPointer)) {
			proc.remote().memory().Read(SummPointer, sizeof(val), &val);
			proc.remote().memory().Read(SummPointer + 0x8, sizeof(val2), &val2);
			proc.remote().memory().Read(SummPointer + 0x10, sizeof(val3), &val3);
			proc.remote().memory().Read(SummPointer + 0x18, sizeof(val4), &val4);
			proc.remote().memory().Read(SummPointer + 0x20, sizeof(val5), &val5);
			proc.remote().memory().Read(SummPointer + 0x28, sizeof(val6), &val6);
			proc.remote().memory().Read(SummPointer + 0x30, sizeof(val7), &val7);
			proc.remote().memory().Read(SummPointer + 0x38, sizeof(val8), &val8);
			proc.remote().memory().Read(SummPointer + 0x40, sizeof(val9), &val9);


			int c = 0;
			for (DWORD i = 0; i < 8; i++) {
				uint8_t b = ((val >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			c = 0;
			for (DWORD i = 0; i < 8; i++) {
				BYTE b = ((val2 >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			c = 0;
			for (DWORD i = 0; i < 8; i++) {
				BYTE b = ((val3 >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			c = 0;
			for (DWORD i = 0; i < 8; i++) {
				BYTE b = ((val4 >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			c = 0;
			for (DWORD i = 0; i < 8; i++) {
				BYTE b = ((val5 >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			c = 0;
			for (DWORD i = 0; i < 8; i++) {
				BYTE b = ((val6 >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			c = 0;
			for (DWORD i = 0; i < 8; i++) {
				BYTE b = ((val7 >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			c = 0;
			for (DWORD i = 0; i < 8; i++) {
				BYTE b = ((val8 >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			c = 0;
			for (DWORD i = 0; i < 8; i++) {
				BYTE b = ((val9 >> c) & 0x000000ff);
				if (b == 0) { return chars; }
				chars.push_back(b);
				c = c + 8;
			}
			return chars;
		}
		else { return{ 0 }; }
	}
	else { return{0}; }
}

// waits few cycles and then reports did it find any animation.
BOOLEAN CheckAnim() {
	for (DWORD i = 0; i < 50; i++) {
		Sleep(20 + rand() % 10);
		if (ReadPlayerAnim()>0) { return true; }
	}
	return false;
}

// waits few cycles and then reports did it find any animation.
BOOLEAN CheckAnim2() {
	for (DWORD i = 0; i < 100; i++) {
		Sleep(20 + rand() % 10);
		if (ReadPlayerAnim()>0) {return true;}
	}
	return false;
}

// waits few cycles and then reports did it find any animation.
BOOLEAN CheckAnim3() {
	for (DWORD i = 0; i < 200; i++) {
		Sleep(20 + rand() % 10);
		if (ReadPlayerAnim()>0) { return true; }
	}
	return false;
}

// waits few cycles and then reports did it find any animation.
BOOLEAN CheckAnim4() {
	for (DWORD i = 0; i < 400; i++) {
		Sleep(20 + rand() % 10);
		if (ReadPlayerAnim()>0) { return true; }
	}
	return false;
}

// waits long time.
BOOLEAN WaitAnim() {
	INT count;
	INT count2;
	for (DWORD i = 0; i < 100; i++) {
		Sleep(200 + rand() % 100);
		if (ReadPlayerAnim()>0) {
			count++;		
		}
		else { count2++; }
		if (count>0) { i = 0; }
		if (count2>10) { return false; }
	}
	return true;
}

DWORD ReadPlayerAnim() {
	if (LocalPlayer != NULL) {
		DWORD Read = VirtPReadDword(LocalPlayer + poff33);
		if (Read != 4294967295) {
			return Read;
		}
		else {
			return 0;
		}
	}
	return 0;
}

BOOLEAN ReadPlayerMovin() {
	if (LocalPlayer != NULL) {
		for (WORD i = 0; i < 10; i++) {
			Sleep(2 + rand() % 10);
			FFPOINT Read = PlayerCoordFloatRaw();
			if (Read.x != NULL && Read.y != NULL) {
				if (Movingstate.x == NULL && Movingstate.y == NULL) {
					Movingstate.x = Read.x;
					Movingstate.y = Read.y;
				}
				if (Read.x != Movingstate.x || Read.y != Movingstate.y) {
					Movingstate.x = Read.x;
					Movingstate.y = Read.y;
					return TRUE;
				}
				else {
					return FALSE;
				}
			}
		}
	}
	return FALSE;
}

BYTE ReadPlayerPrayT() {
	if (LocalPlayer != NULL) {
		BYTE Read = VirtPReadDword(LocalPlayer + poff1111);
		if (Read != 4294967295) {
			return Read;
		}
		else {
			return 0;
		}
	}
	return 0;
}

FLOAT ReadCoordX3() {                    

		if (LocalPlayer != NULL) {
			FLOAT Read = VirtPReadFloat(LocalPlayer + poff11);
			//printf("Read1x: %I64X\n", Read);
			if (Read != NULL) {
				MyLocXRaw = (Read-256.f);
				return MyLocXRaw;
			}
			else {
				return 0.f;
			}

		}
	
	return 0.f;
}

FLOAT ReadCoordY3() {

		if (LocalPlayer != NULL) {
			
			FLOAT Read = VirtPReadFloat(LocalPlayer + poff22);
			//printf("Read1y1: %I64X\n", Read);
			if (Read != NULL) {
				MyLocYRaw = (Read-256.f);
				return MyLocYRaw;
			}
			else {
				return 0.f;
			}
		}
	
	return 0.f;
}

FLOAT ReadCoordZ() {

	if (LocalPlayer != NULL) {

		FLOAT Read = VirtPReadFloat(LocalPlayer + poff11+4);
		//printf("Read1y1: %I64X\n", Read);
		if (Read != NULL) {
			MyLocZRaw = Read;
			return MyLocZRaw;
		}
		else {
			return 0.f;
		}
	}

	return 0.f;
}

DWORD ReadCoordX3i() {                      

		if (LocalPlayer != NULL) {
			DWORD Read = VirtPReadDword(LocalPlayer + poff11);
			//printf("Read1x: %I64X\n", Read);
			if (Read != NULL) {
				return Read;
			}
			else {
				return 0;
			}

		}
	
	return 0;
}

DWORD ReadCoordY3i() {

		if (LocalPlayer != NULL) {

			DWORD Read = VirtPReadDword(LocalPlayer +poff22);
			//printf("Read1y1: %I64X\n", Read);
			if (Read != NULL) {
				return Read;
			}
			else {
				return 0;
			}
		}
	
	return 0;
}

FFPOINT PlayerCoordFloat() {
	FFPOINT x;
	x.x = ReadCoordX3() / 512.f;
	x.y = ReadCoordY3() / 512.f;
	x.z = GetFloorLv_2();
	return x;
}

FFPOINT PlayerCoordFloatRaw() {
	FFPOINT x;
	x.x = ReadCoordX3();
	x.y = ReadCoordY3();
	return x;
}

BOOLEAN PlayerLoggedIn() {

		if (LocalPlayer != NULL) {
			
			BYTE Read = VirtPReadByte(LocalPlayer + pa1);
			//printf("Read1y1: %I64X\n", Read);
			if (Read != NULL) {;

				return TRUE;
			}
			else {
				return FALSE;
			}
		}
	
	return 0;
}

POINT PlayerCoordPoint() {
	POINT x;
	x.x= ReadCoordX3()/512.f;
	x.y= ReadCoordY3()/512.f;
	return x;
}

int CompareAd()
{

	return 9999;
}

//floor lv localplayer
BYTE GetFloorLv_2(){ 

		if (LocalPlayer != NULL)
		{

			BYTE Read = VirtPReadByte(LocalPlayer + poff88);
			//printf("Read1x: %I64X\n", Read);

			if (Read != NULL)
			{
			//	printf("Read1x1: %lX\n", Read2);
				Floor = Read;
				return Floor;
			}
			else {
				return 0;
			}

		
	}
	return 9999;
}

//not working
int GetMouseID_(){
	
	DWORD64 hackOffset1 = 0xc0;

	if (!procIDs.empty())
	{

		if (ScAdd1 != NULL)
		{
			DWORD64	Read = VirtPRead64(ScAdd1 - hackOffset1);
				//printf("Read1x: %I64X\n", Read);
			DWORD Read2 = ((Read >> 0) & 0xfffffffff);

			if (Read != NULL)
			{
				//	printf("Read1x1: %lX\n", Read2);
				return Read2;
			}
			else {
				return 0;
			}

		}
	}
	return 0;
}

//Finds rs window otherway
BOOL CALLBACK FindWindows(HWND handle, LPARAM option)
{
	DWORD window_process_id = 0;
	GetWindowThreadProcessId(handle, &window_process_id);
	
		if (IsWindowEnabled(handle)) {
			if (HPid == window_process_id) {				
				char out[10];
				GetWindowText(handle, out, 10);
				string prep = out;
				string Rune = "RuneScape";
				if (prep.find(Rune) != string::npos) {
					WProc = handle; 
					cout << "Whandle: " << WProc << "\n";
					return TRUE;
				}
				return TRUE;
			}
			return TRUE;
		}
	return TRUE;
}

//Finds rs window childwindow
BOOL CALLBACK FindWindows2(HWND handle, LPARAM option)
{
	cout << "Whandle Child: " << handle << endl;
	WProcC = handle;
	return TRUE;
}

VOID FindRS()
{
		
//Start opening your file
	//string p= "C:/ProgramData/Jagex/launcher/rs2client.exe";
	ifstream inBigArrayfile;
	inBigArrayfile.open(RSExeFile, std::ios::binary | std::ios::in);

	//Find length of file
	if (inBigArrayfile) {
		inBigArrayfile.seekg(0, std::ios::end);
		long Length = inBigArrayfile.tellg();
		inBigArrayfile.seekg(0, std::ios::beg);

		//read in the data from your file
		char * InFileData = new char[Length];
	inBigArrayfile.read(InFileData, Length);

		//Calculate MD5 hash
		MD5hash = md5(InFileData, Length);
		cout << "Client MD5 hash:" << MD5hash.c_str() << endl;

		//Clean up
		delete[] InFileData;
		inBigArrayfile.close();
	}
	else { cout << "Client exe file not found in standard location" << endl; }

			//some extra stuff
			Cpuinit();
			//////////////////
			LocateStartAddresses();
	//	}
	
}

//checks if process it is attached is still there//there was some talk about how it maybe wrong
BOOLEAN CheckRS3()
{
	if (HProc!=NULL) {
		DWORD stat;
		GetExitCodeProcess(HProc, &stat);
		//STILL_ACTIVE (259)
		if (stat==259) {
			return TRUE;
		}
	}
	return FALSE;
}

BOOLEAN FindRS3()
{    
	//HMODULE hMod[200];
	//DWORD cbNeeded;
	//TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");
	//DWORD cProcesses;
	//MODULEINFO moduleInfo;
	//ZeroMemory(&moduleInfo, sizeof(moduleInfo));
	//char lpFilename[MAX_PATH];
	//char lpBaseName[MAX_PATH];
	cout << ("Trying to find NXT" "\n");
	//lets clean old procIDs
	procIDs.clear();
	Process::EnumByName(L"rs2client.exe", procIDs);



	if (!procIDs.empty())
	{    
		cout << ("NXT Client found!!!" "\n");		
		proc.Attach(procIDs.front());
	    HProc = proc.core().handle();
		cout << "Handle:" << HProc << "\n";
		HPid=proc.pid();
		cout << "Pid:" << HPid << "\n";
		
		const ModuleData*  RS3Maindata = proc.modules().GetMainModule();
		RSExeStart = RS3Maindata->baseAddress;
		RSExeSize = RS3Maindata->size;
		RSExeFile = Utils::WstringToUTF8(RS3Maindata->fullPath);
		cout << "Name:" << Utils::WstringToUTF8(RS3Maindata->name) << " ";
		cout << "Path:" << RSExeFile << " ";
		cout << "Base:" << hex << RSExeStart << " ";
		//cout << hex << RS3Maindata->manual << endl;
		cout <<"Size:"<< hex << RSExeSize << endl;
		//cout << hex << RS3Maindata->type << endl;

		/* not needed
		const ProcessModules::mapModules  RS3Maindata2 = proc.modules().GetAllModules();
		//well this was confusing, but i IS current data
		for (auto i = RS3Maindata2.begin(); i != RS3Maindata2.end();++i) {
			cout << "Name:" << Utils::WstringToUTF8(i->second.name) << " ";
			cout << "Path:" << Utils::WstringToUTF8(i->second.fullPath) << " ";
			cout << "Start:" << hex << i->second.baseAddress << " ";
			cout << "Manual:" << hex << i->second.manual << " ";
			cout << "Size:" <<hex << i->second.size << " ";
			cout << "Type" << hex << i->second.type << endl;
		}





		/* winz
		//first thing loaded is rs exe no need to go further
		if (EnumProcessModules(HProc, hMod, sizeof(hMod),
			&cbNeeded))
		{					

			//winapi thing//old
			cProcesses = cbNeeded / sizeof(DWORD)/2;
				for (DWORD i = 0; i < cProcesses; i++)
				{
					GetModuleBaseName(HProc, hMod[i], szProcessName, sizeof(szProcessName));
					GetModuleFileNameEx(HProc, hMod[i], lpFilename, sizeof(lpFilename));
					cout <<dec<<i<<":"<< "Name:" << szProcessName <<":"<<hex<< hMod[i]<<":"<< lpFilename <<"\n";
					GetModuleInformation(HProc, hMod[i], &moduleInfo, sizeof(moduleInfo));
					//cout << moduleInfo.EntryPoint << "\n";
					cout<<"Size: "<<dec<< moduleInfo.SizeOfImage<< "\n";
					//cout << moduleInfo.lpBaseOfDll << "\n";
					//note up needed info
					if (i == 0) {
						RSExeStart = (DWORD64)hMod[i];
						RSExeSize = moduleInfo.SizeOfImage;
						RSExeFile = lpFilename;
						cout << "exe loc in memory: " << hex << RSExeStart << "\n";
					}
					
					//string text = szProcessName;
					//if (text.find("SHELL32.dll") != string::npos){
					//	SHELL32Start = (DWORD64)hMod[i];
					//	SHELL32Size = moduleInfo.SizeOfImage;
					//}
					 
				}

		}
        */
		EnumWindows(FindWindows, 0);
		EnumChildWindows(WProc, FindWindows2, 0);
		FindRS();
		RS3Found = TRUE;
		return true;
	}
	cout << ("Error" "\n");
	return false;
}


LRESULT CALLBACK MyKeyboardHook(int nCode, WPARAM wParam, LPARAM lParam)
{	
	if (nCode == HC_ACTION)
	{
		KBDLLHOOKSTRUCT* keyboardHookPointer = (KBDLLHOOKSTRUCT *)lParam; //Cast.
		
		//if ((keyboardHookPointer->flags & LLKHF_LOWER_IL_INJECTED) || (keyboardHookPointer->flags & LLKHF_INJECTED))
		//{
		//	cout << "kFake \n";
		//}
		//else {
		//	cout << "kHardware \n"; 
		//}
		
		keyboardHookPointer->dwExtraInfo = 0;
		keyboardHookPointer->flags &= ~LLKHF_LOWER_IL_INJECTED; //Remove flag.
		keyboardHookPointer->flags &= ~LLKHF_INJECTED; //Remove flag.
	} 
	return CallNextHookEx(_hook, nCode, wParam, lParam); //Give Jagex the modified parameters.
}

void Keyhook()
{
	
	if (!(_hook = SetWindowsHookEx(WH_KEYBOARD_LL, MyKeyboardHook, 0, 0)))
	{
		MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
	}
}

LRESULT CALLBACK MyMouseHook(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (nCode == HC_ACTION)
	{
		MSLLHOOKSTRUCT * mouseHookPointer = (MSLLHOOKSTRUCT *)lParam; //Cast.
		/*
		if ((mouseHookPointer->flags & LLMHF_INJECTED) || (mouseHookPointer->flags & LLMHF_LOWER_IL_INJECTED))
		{
			cout << "mFake \n";
		}
		else {
			cout << "mHardware \n";
		}
		*/

		  mouseHookPointer->dwExtraInfo =0;
		  mouseHookPointer->flags &= ~LLMHF_LOWER_IL_INJECTED; //Remove flag.
		  mouseHookPointer->flags &= ~LLMHF_INJECTED; //Remove flag.
	}
	return CallNextHookEx(_hook2, nCode, wParam, lParam); //Give Jagex the modified parameters.
}

void Mousehook()
{
	if (!(_hook2 = SetWindowsHookEx(WH_MOUSE_LL, MyMouseHook, 0, 0)))
	{
		MessageBox(NULL, "Failed to install hook!", "Error", MB_ICONERROR);
	}
}

int StartHookin(){
	HookinActive = TRUE;
	Keyhook();
	Mousehook();
	cout << "Passive hooker started \n";
			MSG msg;
			while (GetMessage(&msg, NULL, 0, 0)>0)
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			cout << "Hooking ended \n";
			return 0;
}

struct HookClass
{
	void HookFn(RemoteContext& context)
	{
		//
		// Get process ID
		//
		



		_CLIENT_ID_T<DWORD_PTR> cid = { 0 };
		auto pcid = context.getArg(3);
		procTaskMgr.memory().Read(pcid, sizeof(cid), &cid);
		DWORD pid = (DWORD)cid.UniqueProcess;

		if (pid == GetCurrentProcessId())
		{
			// Remove PROCESS_TERMINATE access right
			auto mask = context.getArg(1);
			if (mask & PROCESS_TERMINATE)
			{
				std::wcout << L"Attempt to open current process with PROCESS_TERMINATE rights\n";
				context.setArg(1, mask & ~PROCESS_TERMINATE);
			}
		}
	}

	Process procTaskMgr;
};

void Cpuinit() {
	PdhOpenQuery(NULL, NULL, &cpuQuery);
	// You can also use L"\\Processor(*)\\% Processor Time" and get individual CPU values with PdhGetFormattedCounterArray()
	PdhAddEnglishCounter(cpuQuery, TEXT("\\Processor(_Total)\\% Processor Time"), NULL, &cpuTotal);
	PdhCollectQueryData(cpuQuery);

	SYSTEM_INFO sysInfo;
	FILETIME ftime, fsys, fuser;

	GetSystemInfo(&sysInfo);
	numProcessors = sysInfo.dwNumberOfProcessors;

	GetSystemTimeAsFileTime(&ftime);
	memcpy(&lastCPU, &ftime, sizeof(FILETIME));
	memcpy(&lastCPU2, &ftime, sizeof(FILETIME));

	self = GetCurrentProcess();
	GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
	memcpy(&lastSysCPU, &fsys, sizeof(FILETIME));
	memcpy(&lastUserCPU, &fuser, sizeof(FILETIME));
	//for rs
	GetProcessTimes(HProc, &ftime, &ftime, &fsys, &fuser);
	memcpy(&lastSysCPU2, &fsys, sizeof(FILETIME));
	memcpy(&lastUserCPU2, &fuser, sizeof(FILETIME));
}

BYTE cc;
INT SystemCpu() {
	//BYTE cc;
	INT v2;
	PDH_FMT_COUNTERVALUE counterVal;
	cc++;
	if (cc > 20) {
		cc = 0;
		 
			PdhCollectQueryData(cpuQuery);
			PdhGetFormattedCounterValue(cpuTotal, PDH_FMT_DOUBLE, NULL, &counterVal);
			v2 = counterVal.doubleValue;
			v = v + v2;
		
		v = v / 2;
		return v;
	}
	return v;
}

BYTE cc2;
INT SystemCpuSimba() {
	
	INT v2;
	FILETIME ftime, fsys, fuser;
	ULARGE_INTEGER now, sys, user;
	double percent;
	cc2++;
	if (cc2 > 20) {
		cc2 = 0;
		GetSystemTimeAsFileTime(&ftime);
		memcpy(&now, &ftime, sizeof(FILETIME));

		GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
		memcpy(&sys, &fsys, sizeof(FILETIME));
		memcpy(&user, &fuser, sizeof(FILETIME));
		percent = (sys.QuadPart - lastSysCPU.QuadPart) +
			(user.QuadPart - lastUserCPU.QuadPart);
		percent /= (now.QuadPart - lastCPU.QuadPart);
		percent /= numProcessors;
		lastCPU = now;
		lastUserCPU = user;
		lastSysCPU = sys;
		v2 = percent * 100;
		vs = vs + v2;
		vs = vs / 2;
		return vs;
	}
	return vs;

}

BYTE cc3;
INT SystemCpuRs() {

	INT v2;
	FILETIME ftime, fsys, fuser;
	ULARGE_INTEGER now, sys, user;
	double percent;
	cc3++;
	if (cc3 > 20) {
		cc3 = 0;
		GetSystemTimeAsFileTime(&ftime);
		memcpy(&now, &ftime, sizeof(FILETIME));

		GetProcessTimes(HProc, &ftime, &ftime, &fsys, &fuser);
		memcpy(&sys, &fsys, sizeof(FILETIME));
		memcpy(&user, &fuser, sizeof(FILETIME));
		percent = (sys.QuadPart - lastSysCPU2.QuadPart) +
			(user.QuadPart - lastUserCPU2.QuadPart);
		percent /= (now.QuadPart - lastCPU2.QuadPart);
		percent /= numProcessors;
		lastCPU2 = now;
		lastUserCPU2 = user;
		lastSysCPU2 = sys;
		v2 = percent * 100;
		vrs3 = vrs3 + v2;
		vrs3 = vrs3 / 2;
		return vrs3;
	}
	return vrs3;

}

BYTE cc4;
INT SystemMem() {
	cc4++;
	if (cc4 > 20) {
		cc4 = 0;
		MEMORYSTATUSEX memInfo;
		memInfo.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&memInfo);
		DWORDLONG info = memInfo.ullTotalPhys;
		sysmem = (info/1024 / 1024);
		return sysmem;
	}
	return sysmem;
}

BYTE cc5;
INT SystemMemFree() {
	cc5++;
	if (cc5 > 20) {
		cc5 = 0;
		MEMORYSTATUSEX memInfo;
		memInfo.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&memInfo);
		DWORDLONG info = memInfo.ullAvailPhys;
		sysmemfree = (info / 1024/1024);
		return sysmemfree;
	}
	return sysmemfree;
}

BYTE cc6;
INT SystemMemInUse() {
	cc6++;
	if (cc6 > 20) {
		cc6 = 0;
		MEMORYSTATUSEX memInfo;
		memInfo.dwLength = sizeof(MEMORYSTATUSEX);
		GlobalMemoryStatusEx(&memInfo);
		DWORDLONG info = memInfo.ullTotalPhys - memInfo.ullAvailPhys;
		sysmemused = (info / 1024 / 1024);
		return sysmemused;
	}
	return sysmemused;
}

BYTE cc7;
INT SystemMemRs3() {
	cc7++;
	if (cc7 > 20) {
		cc7 = 0;
		PROCESS_MEMORY_COUNTERS_EX pmc;
		GetProcessMemoryInfo(HProc, (PROCESS_MEMORY_COUNTERS*)&pmc, sizeof(pmc));
		SIZE_T info = pmc.PrivateUsage;
		sysmemusedrs3 = (info / 1024 / 1024);
		return sysmemusedrs3;
	}
	return sysmemusedrs3;
}

// Load embedded at ProggyTiny size 10, disable oversampling
ImFont* ImFontAtlas::AddFontDefault2(const ImFontConfig* font_cfg_template)
{
	ImFontConfig font_cfg = font_cfg_template ? *font_cfg_template : ImFontConfig();
	if (!font_cfg_template)
	{
		font_cfg.OversampleH = font_cfg.OversampleV = 1;
		font_cfg.PixelSnapH = true;
	}
	if (font_cfg.Name[0] == '\0') strcpy(font_cfg.Name, "ProggyTiny.ttf, 10px");

	const char* ttf_compressed_base85 = GetDefault2CompressedFontDataTTFBase85();
	ImFont* font = AddFontFromMemoryCompressedBase85TTF(ttf_compressed_base85, 10.0f, &font_cfg, GetGlyphRangesDefault());
	return font;
}

//time
DWORD64 SystemTime() {
	return chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now().time_since_epoch()).count();
}

//player search
VOID StartLoop()
{
	while (RS3Found == TRUE && CheckRS3() && ScAdd1!=NULL)
	{
		Sleep(1000);
		FindLP();
		//CompassCheck();
		GetWindowsRes(); 
	}
}

int StartGraphicOverlay()
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = NULL;
	wcex.hIcon = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(wcex.hInstance, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "Debug1";
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	RegisterClassEx(&wcex);
	GetWindowRect(WProcC, &rs);
	rs3 = rs;
	HWND hwnd = CreateWindowEx(WS_EX_TOPMOST| WS_EX_LAYERED| WS_EX_TRANSPARENT,
		"Debug1",
		"Debug3",
		WS_POPUP,
		rs.left, rs.top,
		rs.right - rs.left, rs.bottom - rs.top,
		NULL,
		NULL,
		wcex.hInstance,
		NULL
	);
	//SetLayeredWindowAttributes(hwnd, 0, 0, LWA_ALPHA);
	//UpdateLayeredWindow(hwnd, 0,0,0,0,0, RGB(0, 0, 0),0, ULW_COLORKEY);
	SetLayeredWindowAttributes(hwnd, 0, RGB(0, 0, 0), LWA_COLORKEY);
	ShowWindow(hwnd, SW_SHOW);
	//MARGINS margins = { -1 };
	//DwmExtendFrameIntoClientArea(hwnd, &margins);
	//UpdateWindow(hwnd);




	// Initialize Direct3D
	LPDIRECT3D9 pD3D;
	if ((pD3D = Direct3DCreate9(D3D_SDK_VERSION)) == NULL)
	{
		UnregisterClass(_T("debug3"), wcex.hInstance);
		return 0;
	}
	ZeroMemory(&g_d3dpp, sizeof(g_d3dpp));
	g_d3dpp.Windowed = TRUE;
	g_d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	g_d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
	g_d3dpp.EnableAutoDepthStencil = TRUE;
	g_d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
	g_d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	// Create the D3DDevice
	if (pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hwnd, D3DCREATE_HARDWARE_VERTEXPROCESSING, &g_d3dpp, &g_pd3dDevice) < 0)
	{
		pD3D->Release();
		UnregisterClass(_T("Debug3"), wcex.hInstance);
		return 0;
	}

	// Setup ImGui binding
	ImGui_ImplDX9_Init(hwnd, g_pd3dDevice);

	// Load Fonts
	// (there is a default font, this is only if you want to change it. see extra_fonts/README.txt for more details)
	ImGuiIO& io = ImGui::GetIO();
	io.Fonts->AddFontDefault();
	io.Fonts->AddFontDefault2();
	//io.Fonts->AddFontFromFileTTF("../../extra_fonts/Cousine-Regular.ttf", 15.0f);
	//ImFont *font1 = io.Fonts->AddFontFromFileTTF("../../extra_fonts/DroidSans.ttf", 16.0f);
	//io.Fonts->AddFontFromFileTTF("../../extra_fonts/ProggyClean.ttf", 13.0f);
	//io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Arial.ttf", 20.0f);
	//io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Arial.ttf", 20.0f);
	//ImFont *font2 = io.Fonts->AddFontFromFileTTF("C:\\Windows\\Fonts\\Gabriola Regular.ttf", 40.0f);
	//io.Fonts->AddFontFromFileTTF("./extra_fonts/ProggyClean.ttf", 10.0f);
	//io.Fonts->AddFontFromFileTTF("C:\\ProggyTiny.ttf", 10.0f);
	//io.Fonts->AddFontFromFileTTF("C:\\ProggyClean.ttf", 20.0f);
	//io.Fonts->AddFontFromFileTTF("../../extra_fonts/ProggyClean.ttf", 40.0f);
	io.Fonts->Build();
	//cout <<"fonts:"<< io.Fonts->Fonts.size() << endl;
	




	//io.Fonts->AddFontFromFileTTF("c:\\Windows\\Fonts\\ArialUni.ttf", 18.0f, NULL, io.Fonts->GetGlyphRangesJapanese());
	io.IniFilename = NULL;
	
	BOOLEAN show_test_window = true;
	BOOLEAN show_another_window = false;
	ImVec4 clear_col = ImColor(0, 0, 0);




	// Main loop
	MSG msg;
	ZeroMemory(&msg, sizeof(msg));
	while (msg.message != WM_QUIT && CheckRS3())
	{

		GetWindowRect(WProcC, &rs);
		if (rs.bottom != rs3.bottom || rs.left != rs3.left || rs.right != rs3.right || rs.top != rs3.top) {
			rs3 = rs; 
			SetWindowPos(hwnd, NULL, rs.left, rs.top, rs.right - rs.left, rs.bottom - rs.top, NULL); 
		}
		BOOLEAN AllObjectBool = FALSE;
		Sleep(5);
		if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			continue;
		}

		ImGui_ImplDX9_NewFrame();
		{


			ImGui::SetWindowSize("Bug", ImVec2((float)rs.right - rs.left, (float)rs.bottom - rs.top));
			ImGui::SetWindowPos("Bug", ImVec2(0, 0));
			ImGui::Begin("Bug", NULL, ImVec2(0, 0), 0.0f, ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove | ImGuiWindowFlags_NoScrollbar);
			if (!GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F12)) {
				if (key13 == TRUE) { key13 = FALSE; Sleep(200); }
				else { if (key13 == FALSE) { key13 = TRUE; Sleep(200); } }
			}
			if (!key13) {
				//cout<<(int)CheckRS3()<<endl;
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 40.f), ImColor(0, 255, 255, 255), "MXY:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(40.f, 40.f), ImColor(0, 255, 0, 255), to_string(GetMLoc().x).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 40.f), ImColor(0, 255, 255, 255), ":", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(80.f, 40.f), ImColor(0, 255, 0, 255), to_string(GetMLoc().y).c_str(), 0, 0.0f, 0);
				//debug rs rev
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 50.f), ImColor(0, 255, 255, 255), "MD5:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(40.f, 50.f), ImColor(0, 255, 0, 255), MD5hash.c_str(), 0, 0.0f, 0);
				//debug rs rev
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 60.f), ImColor(0, 255, 255, 255), "Rev:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(40.f, 60.f), ImColor(0, 255, 0, 255), Revision.c_str(), 0, 0.0f, 0);
				//debug fps
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 70.f), ImColor(0, 255, 255, 255), "Fps:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(40.f, 70.f), ImColor(0, 255, 0, 255), (to_string(ImGui::GetIO().Framerate)).c_str(), 0, 0.0f, 0);
				//debug coords
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 80.f), ImColor(0, 255, 255, 255), "X:coord:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 80.f), ImColor(0, 255, 0, 255), to_string(ReadCoordX3() / 512.f).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 90.f), ImColor(0, 255, 255, 255), "Y:coord:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 90.f), ImColor(0, 255, 0, 255), to_string(ReadCoordY3() / 512.f).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 100.f), ImColor(0, 255, 255, 255), "Floor:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 100.f), ImColor(0, 255, 0, 255), to_string(GetFloorLv_2()).c_str(), 0, 0.0f, 0);

				//debug rs X,Y window resulution

				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 110.f), ImColor(0, 255, 255, 255), "RsXres:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 110.f), ImColor(0, 255, 0, 255), to_string(GetRsResolution2().x).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 120.f), ImColor(0, 255, 255, 255), "RsYres:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 120.f), ImColor(0, 255, 0, 255), to_string(GetRsResolution2().y).c_str(), 0, 0.0f, 0);
				//debug Angle
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 130.f), ImColor(0, 255, 255, 255), "Angle1:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 130.f), ImColor(0, 255, 0, 255), to_string(ReadCompass().x).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 140.f), ImColor(0, 255, 255, 255), "Angle2:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 140.f), ImColor(0, 255, 0, 255), to_string(ReadCompass().y).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 150.f), ImColor(0, 255, 255, 255), "Logged:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 150.f), ImColor(0, 255, 0, 255), to_string(PlayerLoggedIn()).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 160.f), ImColor(0, 255, 255, 255), "Z-Elev:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 160.f), ImColor(0, 255, 0, 255), to_string(ReadCoordZ()).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 170.f), ImColor(0, 255, 255, 255), "fl2:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 170.f), ImColor(0, 255, 0, 255), to_string(GetInterfaceSize(ScAdd10).y).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 180.f), ImColor(0, 255, 255, 255), "PAnim:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 180.f), ImColor(0, 255, 0, 255), to_string(ReadPlayerAnim()).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 190.f), ImColor(0, 255, 255, 255), "HP:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 190.f), ImColor(0, 255, 0, 255), to_string(GetHP_()).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 200.f), ImColor(0, 255, 255, 255), "Pray:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 200.f), ImColor(0, 255, 0, 255), to_string(GetPray_()).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 210.f), ImColor(0, 255, 255, 255), "Sidetest:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 210.f), ImColor(0, 255, 0, 255),  FindSideText().c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 220.f), ImColor(0, 255, 255, 255), "IFilter:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 220.f), ImColor(0, 255, 0, 255), to_string(InterfAdd).c_str(), 0, 0.0f, 0);
				//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 230.f), ImColor(0, 255, 255, 255), "PMoving:", 0, 0.0f, 0);
				//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(70.f, 230.f), ImColor(0, 255, 0, 255), to_string(ReadPlayerMovin()).c_str(), 0, 0.0f, 0);

				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 390.f), ImColor(0, 255, 255, 255), "CPUCores:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(75.f, 390.f), ImColor(0, 255, 0, 255), to_string(numProcessors).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 400.f), ImColor(0, 255, 255, 255), "CPUTotal:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(75.f, 400.f), ImColor(0, 255, 0, 255), to_string(SystemCpu()).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(92.f, 400.f), ImColor(0, 255, 255, 255), "%", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 410.f), ImColor(0, 255, 255, 255), "CPUSimba:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(75.f, 410.f), ImColor(0, 255, 0, 255), to_string(SystemCpuSimba()).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(90.f, 410.f), ImColor(0, 255, 255, 255), "%", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 420.f), ImColor(0, 255, 255, 255), "CPURs3:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(75.f, 420.f), ImColor(0, 255, 0, 255), to_string(SystemCpuRs()).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(92.f, 420.f), ImColor(0, 255, 255, 255), "%", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 430.f), ImColor(0, 255, 255, 255), "MemTotal:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(75.f, 430.f), ImColor(0, 255, 0, 255), to_string(SystemMem()).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(112.f, 430.f), ImColor(0, 255, 255, 255), "Mb", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 440.f), ImColor(0, 255, 255, 255), "MemFree:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(75.f, 440.f), ImColor(0, 255, 0, 255), to_string(SystemMemFree()).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(112.f, 440.f), ImColor(0, 255, 255, 255), "Mb", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 450.f), ImColor(0, 255, 255, 255), "MemUsed:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(75.f, 450.f), ImColor(0, 255, 0, 255), to_string(SystemMemInUse()).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(112.f, 450.f), ImColor(0, 255, 255, 255), "Mb", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 460.f), ImColor(0, 255, 255, 255), "MemRs3:", 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(75.f, 460.f), ImColor(0, 255, 0, 255), to_string(SystemMemRs3()).c_str(), 0, 0.0f, 0);
				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(112.f, 460.f), ImColor(0, 255, 255, 255), "Mb", 0, 0.0f, 0);
			}


			//
			if (GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_DELETE)) {
				NPCLOCK = NULL;
			}
			if (!GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_DELETE)) {
				if (key25 == TRUE) { key25 = FALSE; Sleep(200); }
				else { if (key25 == FALSE) { key25 = TRUE; Sleep(200); } }
			}
			if (key25) {
			
			}

			//invbox spots
			if (!GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F5)) {
				if (key5 == TRUE) { key5 = FALSE; Sleep(200); }
				else { if (key5 == FALSE) { key5 = TRUE; Sleep(200); } }
			} 
			if (key5) {
				for (DWORD ii = 0; ii < 28; ii++) {
					//FFPOINT p = GetsrealSlot(ii);
					//ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(p.x, p.y), 4, ImColor(255, 255, 0, 255));
					//ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(200.f + Getslot(29).x, 200.f + Getslot(29).y), 4, ImColor(255, 255, 0, 255));
				}
			}

			//debug  gr2 array	
			if (!GetAsyncKeyState(VK_CONTROL) && !GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F1)) {

				if (key1 == TRUE) { key1 = FALSE; Sleep(200); }
				else { if (key1 == FALSE) { key1 = TRUE; Sleep(200); } }
			}
			if (key1) {
				if (AllObjectBool == FALSE) {
					AllObjectBool = TRUE;
					AllObjectCount++;
					if (AllObjectCount>10) {
						AllObjectCount = 0;
						ReadCObjArrays();
					}
				}
				//ReadGroundItemsArray2();
				if (!GIID2.empty()) {
					for (DWORD i = 0; i < GIID2.size(); i++) {

						//FFPOINT xy = TileToMouseTest22({ GIX2[i], GIY2[i] });

						stringstream stream;
						stream << hex << GIMem2[i];
						string result(stream.str());

						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(GIxmid2[i] - 20.f, GIymid2[i] +10.f), ImColor(0, 255, 255, 255), "Fl:", 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(GIxmid2[i], GIymid2[i] + 10.f), ImColor(0, 255, 255, 255), to_string((GIFL2[i])).c_str(), 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(GIxmid2[i] - 20.f, GIymid2[i]), ImColor(0, 255, 255, 255), "Id:", 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(GIxmid2[i], GIymid2[i]), ImColor(0, 255, 255, 255), to_string((GIID2[i])).c_str(), 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(GIxmid2[i], GIymid2[i]), 1, ImColor(255, 0, 0, 255));
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(GIxmid2[i] - 20.f, GIymid2[i] - 10.f), ImColor(0, 255, 0, 255), "Am:", 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(GIxmid2[i], GIymid2[i] - 10.f), ImColor(0, 255, 0, 255), to_string((GIAM2[i])).c_str(), 0, 0.0f, 0);
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x + 30, xy.y - 5.f), ImColor(255, 0, 0, 255), GIText[i].c_str(), 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(GIxmid2[i] - 25.f, GIymid2[i] -20.f), ImColor(0, 255, 255, 255), "Mem:", 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(GIxmid2[i], GIymid2[i] -20.f), ImColor(0, 255, 255, 255), (result).c_str(), 0, 0.0f, 0);

					}
				}
			}

		
			//test
			if (GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_F2)) {
				if (key2 == TRUE) { key2 = FALSE; Sleep(200); }
				else { if (key2 == FALSE) { key2 = TRUE; Sleep(200); } }
			}
			if (key2) {


				for (FLOAT i = 0; i < 13056.f; i += 512.f) {
					FLOAT	yy = -6656.f + i;;
					for (FLOAT i = 0; i < 13056.f; i += 512.f) {
						FLOAT xx = -6656.f + i;
						//FLOAT	yy = 0;
						FFPOINT x2 = TileToMouseTest222({ xx, yy });
						ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(x2.x, x2.y), 3, ImColor(255, 0, 0, 255));
						//
						ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX[i] + 6.f, InterfY[i] + 30.f), ImVec2(InterfX[i] + 5.f + InterfXs11[i], InterfY[i] + 30.f), ImColor(255, 0, 0, 255), 1.f);
						ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX[i] + 6.f + InterfXs11[i], InterfY[i] + 30.f), ImVec2(InterfX[i] + 6.f + InterfXs11[i], InterfY[i] + 30.f + InterfYs11[i]), ImColor(255, 0, 0, 255), 1.f);
						ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX[i] + 6.f, InterfY[i] + 30.f + InterfYs11[i]), ImVec2(InterfX[i] + 6.f + InterfXs11[i], InterfY[i] + 30.f + InterfYs11[i]), ImColor(255, 0, 0, 255), 1.f);
						ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX[i] + 6.f, InterfY[i] + 30.f), ImVec2(InterfX[i] + 6.f, InterfY[i] + 30.f + InterfYs11[i]), ImColor(255, 0, 0, 255), 1.f);



					}
				}

			}

			//test
			if (!GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F3)) {
				if (key3 == TRUE) { key3 = FALSE; Sleep(200); }
				else { if (key3 == FALSE) { key3 = TRUE; Sleep(200); } }
			}
			if (!key3) {



				for (FLOAT i = 0; i < 25600.f; i += 512.f) {
					FLOAT xx1 = -12800.f + i;
					FLOAT	yy1 = 0;
					FFPOINT x21 = TileToMouseTest222({ xx1, yy1 });
					ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(x21.x, x21.y), 3, ImColor(255, 0, 0, 255));
				}
				
				for (FLOAT i = 0; i < 25600.f; i += 512.f) {
					FLOAT xx2 = 0;
					FLOAT	yy2 = -12800.f + i;
					FFPOINT x22 = TileToMouseTest222({ xx2, yy2 });
					ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(x22.x, x22.y), 3, ImColor(255, 0, 0, 255));
				}
				for (FLOAT i = 0; i < 25600.f; i += 512.f) {
					FLOAT xx3 = -12800.f + i;
					FLOAT	yy3 = -12800.f + i;;
					FFPOINT x23 = TileToMouseTest222({ xx3, yy3 });
					ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(x23.x, x23.y), 3, ImColor(255, 0, 0, 255));
				}

				for (FLOAT i = 0; i < 25600.f; i += 512.f) {
					FLOAT xx4 = -12800.f + i;
					FLOAT	yy4 = 12800.f + (-1 * i);;
					FFPOINT x24 = TileToMouseTest222({ xx4, yy4 });
					ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(x24.x, x24.y), 3, ImColor(255, 0, 0, 255));
				}
			

			}



			//clue currently
			if (!GetAsyncKeyState(VK_SHIFT) && !GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_F4)) {
				if (key4 == TRUE) { key4 = FALSE; Sleep(200); }
				else { if (key4 == FALSE) { key4 = TRUE; Sleep(200); } }
			}
			//xyhold.x = 0;
			if (key4) {

				//FilterInventory();
				//if (!InvSlot2.empty()) {
				//	for (DWORD i = 0; i < InvSlot2.size(); i++) {
				//		for (DWORD ii = 0; ii < CNR.size(); ii++) {
				//			if (InvId[i] == CNR[ii]) {
				//				ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(10.f, 10), ImColor(0, 255, 0, 255), (CText[ii]).c_str(), 0, 0.0f, 0);
				//				FFPOINT p;
				//				p.x = CCoord[ii].x*512.f;
				//				p.y = CCoord[ii].y*512.f;
				//				FFPOINT xy = ToMapFFPOINT({ p.x,p.y });
				//				ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(xy.x, xy.y), 4, ImColor(0, 255, 200, 255));
				//			}
				//		}
				//	}
				//}


				QWPOINT q = GetRSCorners();
				MoveMouse2(q.left+692, q.top+443, 0,0);
				Sleep(500);
				MouseRightClick(222, 666);
				//MoveMouse2(22, 110, 0, 0);
				//Sleep(5000);
				//MoveMouse2(1880, 22, 0, 0);
				//MouseLeftClick(100,1000);
				//KeyboardPress('m',50,1000);
				//MoveMouse(100, 200, 555, 555);
				//math_track3(mouse,xyhold2, {200,200});
				//movemessage2=TRUE;
				//xyhold.x = 200;
				//math_track2(500, 500, 0, 0);
				//TEST99();
				//FFPOINT testing =ToMapFFPOINTExperiment1({ 1.f,1.f });
			//	ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(testing.x, testing.y), 4, ImColor(0, 255, 200, 255));
				//cout <<hex<< InvBoxMemoryLoc << endl;
			//	FindInterfAll();
				//MarkupMem(LocalPlayer,LocalPlayer+5000000);
				//MemoryRegionsFM();
				//LOOTArr = ScanForLootArray();
				//if (ChooseLoot_() == 1) { cout << "BankOpen:True" << endl; }else { cout << "BankOpen:False" << endl; }
				//binary_to_compressed_c("C:\\ProggyTiny.ttf", "ProggyTiny", TRUE, TRUE);
				//ScanTest1();
				//ScanTest2();
				key4 = FALSE;	
				//test();
				//Searchtest(385);
				//SearchCompass();
				//SearchSOItem(0xC3870000);
				//SearchGItem(385);
				//SearchObj(9999);
				//FFPOINT p =FindSObj(3280404480);
				//ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(p.x, p.y), 4, ImColor(255, 255, 0, 255));
			}

			//VarpBits
			if (GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_F4)) {
				if (key27 == TRUE) { key27 = FALSE; Sleep(200); }
				else { if (key27 == FALSE) { key27 = TRUE; Sleep(200); } }
			}
			if (key27) {
				SettingTest();
				//cout << dec << SettingsId.size() << endl;

				for (DWORD i = 0; i < SettingsId.size(); i++) {
					//random junk filter
					if (SettingsId[i]!=3913 && SettingsId[i] != 3914 && SettingsId[i] != 3915
						&& SettingsId[i] != 3937 && SettingsId[i] != 2835 && SettingsId[i] != 46)
					//for all ids range
					//cout << "id:" << dec << SettingsId[i] << endl;
					//key4 = FALSE;
					//if  (SettingsId[i]==1582){ cout << "1582:"<<hex<< SettingsAddr[i] << endl;}
					for (DWORD ii = 0; ii < SettingsIdRec.size(); ii++) {
						if ((SettingsId[i] == SettingsIdRec[ii]) && (SettingsAddr[i] == SettingsAddrRec[ii])) {
							//cout << SettingsId[i] << ":" << SettingsIdRec[ii] << endl;
							//if (SettingsState.size()==SettingsStateRec.size()) {
							if (SettingsState[i] != SettingsStateRec[ii]) {

								//cout << SettingsState.size() << ":" << SettingsStateRec.size() << endl;
								cout << dec << "Id:" << SettingsId[i] << " changed:" << SettingsStateRec[ii] << " To:" << SettingsState[i] << hex << " addr: " << SettingsAddr[i] << endl;
								//break;
							}
							//}
							//else { break; }
						}
					}
				}
				SettingsAddrRec.clear();
				SettingsAddrRec = SettingsAddr;
				SettingsIdRec.clear();
				SettingsIdRec = SettingsId;
				SettingsStateRec.clear();
				SettingsStateRec = SettingsState;
			}
			
			//
			if (GetAsyncKeyState(VK_SHIFT) && !GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_F4)) {
				if (key23 == TRUE) { key23 = FALSE; Sleep(200); }
				else { if (key23 == FALSE) { key23 = TRUE; Sleep(200); } }
			}
			if (key23) {

				}

			//
			if (!GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_F4)) {
				if (key26 == TRUE) { key26 = FALSE; Sleep(200); }
				else { if (key26 == FALSE) { key26 = TRUE; Sleep(200); } }
			}
			if (key26) {

			}

			//inv
			if (!GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F6)) {
				if (key6 == TRUE) { key6 = FALSE; Sleep(200); }
				else { if (key6 == FALSE) { key6 = TRUE; Sleep(200); } }
			}
			if (key6) {

				FilterInventory();
				//cout <<hex<< InvSlot2.size() << endl;
				
				if (!InvSlot2.empty()) {
					//cout << dec << InvSlot2.size() << endl;
					for (DWORD i = 0; i < InvSlot2.size(); i++) {		
						//stringstream stream;
						//stream << hex << IAddr2[i];
						//string result(stream.str());
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Invx[i], Invy[i] - 10.f), ImColor(0, 255, 0, 255), to_string((InvSlot2[i])).c_str(), 0, 0.0f, 0);
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Invx[i], Invy[i]), ImColor(0, 255, 0, 255), result.c_str(), 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Invx[i], Invy[i]), ImColor(0, 255, 0, 255), to_string((InvId[i])).c_str(), 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(Invx[i], Invy[i]), 4, ImColor(255, 255, 0, 255));
					}
				}
				
			}

			//classic objects
			if (!GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F7))  {
				if (key7 == TRUE) { key7 = FALSE; Sleep(200); }
				else { if (key7 == FALSE) { key7 = TRUE; Sleep(200); } }
			}
			if (key7) {
				if (AllObjectBool == FALSE) {
					AllObjectBool = TRUE;
					AllObjectCount++;
					if (AllObjectCount > 10) {
						AllObjectCount = 0;
						ReadCObjArrays();
					}
				}
				//ReadObjectsAArrays();
				if (!ObjectsXf.empty()) {
					for (DWORD i = 0; i < ObjectsXf.size(); i++) {
						//DWORD64 holder = VirtPRead64(ObjectsMem[i] + alloff88);
						//DWORD part = VirtPReadDword(holder + alloff66);
						//if (ViewPartialObjects[i] == part) {

							stringstream stream;
							stream << hex << ObjectsMem[i];
							string result(stream.str());

							if (Objectsxmid[i] != NULL && Objectsymid[i] != NULL) {
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Objectsxmid[i]-20.f, Objectsymid[i] - 40.f), ImColor(0, 255, 0, 255), ObjectsAction1[i].c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Objectsxmid[i], Objectsymid[i] - 30.f), ImColor(0, 255, 0, 255), ObjectsName[i].c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Objectsxmid[i] - 25.f, Objectsymid[i] - 20.f), ImColor(0, 255, 0, 255), "id:", 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Objectsxmid[i], Objectsymid[i] - 20.f), ImColor(0, 255, 0, 255), to_string(ObjectsID[i]).c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Objectsxmid[i] - 25.f, Objectsymid[i] - 10), ImColor(0, 255, 0, 255), "idu:", 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Objectsxmid[i], Objectsymid[i] - 10.f), ImColor(0, 255, 0, 255), to_string(ObjectsIDu[i]).c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Objectsxmid[i] - 25.f, Objectsymid[i]), ImColor(0, 255, 0, 255), "Mem:", 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Objectsxmid[i], Objectsymid[i]), ImColor(0, 255, 0, 255), result.c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(Objectsxmid[i], Objectsymid[i]), 1, ImColor(255, 0, 0, 255));
							}
							else {
								FFPOINT xy = TileToMouseTest22({ ObjectsXf[i], ObjectsYf[i] });
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x-20.f, xy.y - 40.f), ImColor(255, 255, 0, 255), ObjectsAction1[i].c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 30.f), ImColor(255, 255, 0, 255), ObjectsName[i].c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 25.f, xy.y - 20.f), ImColor(255, 255, 0, 255), "id:", 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 20.f), ImColor(255, 255, 0, 255), to_string(ObjectsID[i]).c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 25.f, xy.y - 10), ImColor(255, 255, 0, 255), "idu:", 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 10.f), ImColor(255, 255, 0, 255), to_string(ObjectsIDu[i]).c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 25.f, xy.y), ImColor(255, 255, 0, 255), "Mem:", 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y), ImColor(255, 255, 0, 255), result.c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(xy.x, xy.y), 1, ImColor(255, 255, 0, 255));
							}
					//	}
					}
				}
			}

			//c0obj//all objects
			if (!GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F8)) {
				if (key8 == TRUE) { key8 = FALSE; Sleep(200); }
				else { if (key8 == FALSE) { key8 = TRUE; Sleep(200); } }
			}
			if ( key8) {

				if (AllObjectBool == FALSE) {
					AllObjectBool = TRUE;
					AllObjectCount++;
					if (AllObjectCount>10) {
						AllObjectCount = 0;
						ReadCObjArrays();
					}
				}
				if (!ObjX.empty()) {
					for (DWORD i = 0; i < ObjX.size(); i++) {


						//cout <<dec<< "Mousec:" << NPCX[i] << ":" << NPCY[i] << "\n";
						FFPOINT xy = TileToMouseTest22({ ObjX[i], ObjY[i] });
						//cout <<dec<< "Mousec:" << x2 <<":"<< y2 << "\n";


						stringstream stream, stream2;
						stream << hex << ObjAddrXY[i];
						string objAddr(stream.str());
						stream2 << hex << ObjExtra[i];
						string objAddr2(stream2.str()); 

						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y - 20.f), ImColor(0, 255, 0, 255), "id:", 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 20.f), ImColor(0, 255, 0, 255), to_string(ObjID[i]).c_str(), 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y - 10.f), ImColor(0, 255, 0, 255), "Addr:", 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 10.f), ImColor(0, 255, 0, 255), objAddr.c_str(), 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y), ImColor(0, 255, 0, 255), "Type:", 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y), ImColor(0, 255, 255, 255), to_string(TypeByte[i]).c_str(), 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y +10.f), ImColor(0, 255, 0, 255), "Addr2:", 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y +10.f), ImColor(0, 255, 255, 255), objAddr2.c_str(), 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(xy.x, xy.y), 1, ImColor(255, 0, 0, 255));

					}
				}
			}

			//decor objects
			if (!GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F9)) {
				if (key9 == TRUE) { key9 = FALSE; Sleep(200); }
				else { if (key9 == FALSE) { key9 = TRUE; Sleep(200); } }
			}
			if (key9) {
				if (AllObjectBool == FALSE) {
					AllObjectBool = TRUE;
					AllObjectCount++;
					if (AllObjectCount > 10) {
						AllObjectCount = 0;
						ReadCObjArrays();
					}
				}
				//ReadDecorObj();
				if (!Decorxmid.empty()) {
					for (DWORD i = 0; i < Decorxmid.size(); i++) {
						//DWORD64 holder = VirtPRead64(DecorMem[i] + alloff88);
						//DWORD part = VirtPReadDword(holder + alloff66);
						//if (ViewPartialDecor[i] == part) {
							stringstream stream;
							stream << hex << DecorMem[i];
							string result(stream.str());

							if (Decorxmid[i] != NULL && Decorymid[i] != NULL) {
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Decorxmid[i], Decorymid[i] - 20.f), ImColor(0, 255, 0, 255), DecorName[i].c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Decorxmid[i], Decorymid[i] - 10.f), ImColor(0, 255, 0, 255), to_string(DecorID[i]).c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(Decorxmid[i], Decorymid[i]), 1, ImColor(255, 0, 0, 255));
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Decorxmid[i] - 25.f, Decorymid[i]), ImColor(0, 255, 0, 255), "Mem:", 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Decorxmid[i], Decorymid[i]), ImColor(0, 255, 0, 255), result.c_str(), 0, 0.0f, 0);
							}
							else {
								FFPOINT xy = TileToMouseTest22({ DecorXf[i], DecorYf[i] });
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 20.f), ImColor(255, 255, 0, 255), DecorName[i].c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 10.f), ImColor(255, 255, 0, 255), to_string(DecorID[i]).c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(xy.x, xy.y), 1, ImColor(255, 0, 0, 255));
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 25.f, xy.y), ImColor(255, 255, 0, 255), "Mem:", 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y), ImColor(255, 255, 0, 255), result.c_str(), 0, 0.0f, 0);
							}
						//}
					}
				}
			}

			// npc
			if (!GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F10)) {
				if (key10 == TRUE) { key10 = FALSE; Sleep(200); }
				else { if (key10 == FALSE) { key10 = TRUE; Sleep(200); } }
			}
			if (key10) {
				if (GetAsyncKeyState(VK_ADD)) {
					if (key13 == TRUE) { key13 = FALSE; Sleep(200); }
					else { if (key13 == FALSE) { key13 = TRUE; Sleep(200); } }
				}

				//ReadNPCArray();
				if (AllObjectBool == FALSE) {
					AllObjectBool = TRUE;
					AllObjectCount++;
					if (AllObjectCount > 20) {
						AllObjectCount = 0;
						ReadCObjArrays();
					}
				}
				if (!NPCX.empty()) {
					for (DWORD i = 0; i < NPCX.size(); i++) {
						DWORD64 holder = VirtPRead64(NPCMem[i] + alloff88);
						DWORD part = VirtPReadDword(holder + alloff66);
						if (ViewPartialNPC[i] != part) {
							if (!key13) {
								stringstream stream;
								stream << hex << NPCMem[i];
								string result(stream.str());
								stringstream stream2;
								stream2<< hex << holder + alloff66;
								string result2(stream2.str());
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(NPCxmid[i], NPCymid[i] + 40.f), ImColor(0, 255, 0, 255), result2.c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(NPCxmid[i], NPCymid[i] + 30.f), ImColor(0, 255, 0, 255), to_string(part).c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(NPCxmid[i], NPCymid[i] + 20.f), ImColor(0, 255, 0, 255), to_string((ViewPartialNPC[i])).c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(NPCxmid[i] - 50.f, NPCymid[i] + 10.f), ImColor(0, 255, 0, 255), "MemLoc:", 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(NPCxmid[i], NPCymid[i] + 10.f), ImColor(0, 255, 0, 255), result.c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(NPCxmid[i] - 50.f, NPCymid[i]), ImColor(0, 255, 0, 255), "Name:", 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(NPCxmid[i], NPCymid[i]), ImColor(0, 255, 0, 255), NPCName[i].c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(NPCxmid[i] - 50.f, NPCymid[i] - 20.f), ImColor(0, 255, 0, 255), "id:", 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(NPCxmid[i], NPCymid[i] - 20.f), ImColor(0, 255, 0, 255), to_string((NPCID[i])).c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(NPCxmid[i] - 50.f, NPCymid[i] - 10), ImColor(0, 255, 0, 255), "Health:", 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(NPCxmid[i], NPCymid[i] - 10.f), ImColor(0, 255, 0, 255), to_string((NPCLife[i])).c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(NPCxmid[i], NPCymid[i] - 30.f), ImColor(0, 255, 0, 255), to_string((NPCAnim[i])).c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(NPCxmid[i], NPCymid[i]), 2, ImColor(255, 0, 0, 255));

							}
							else {
								//ImGui::GetWindowDrawList()->AddLine(ImVec2(NPCxstart[i], NPCymid[i]), ImVec2(NPCxend[i], NPCymid[i]), ImColor(255, 0, 0, 255), 1.f);
								//ImGui::GetWindowDrawList()->AddLine(ImVec2(NPCxmid[i], NPCystart[i]), ImVec2(NPCxmid[i], NPCyend[i]), ImColor(255, 0, 0, 255), 1.f);

								ImGui::GetWindowDrawList()->AddLine(ImVec2(NPCxmid[i] - NPCxsize[i] / 2, NPCymid[i] - NPCysize[i] / 2), ImVec2(NPCxmid[i] + NPCxsize[i] / 2, NPCymid[i] - NPCysize[i] / 2), ImColor(255, 0, 255, 255), 1.f);
								ImGui::GetWindowDrawList()->AddLine(ImVec2(NPCxmid[i] - NPCxsize[i] / 2, NPCymid[i] + NPCysize[i] / 2), ImVec2(NPCxmid[i] + NPCxsize[i] / 2, NPCymid[i] + NPCysize[i] / 2), ImColor(255, 0, 255, 255), 1.f);
								ImGui::GetWindowDrawList()->AddLine(ImVec2(NPCxmid[i] + NPCxsize[i] / 2, NPCymid[i] - NPCysize[i] / 2), ImVec2(NPCxmid[i] + NPCxsize[i] / 2, NPCymid[i] + NPCysize[i] / 2), ImColor(255, 0, 255, 255), 1.f);
								ImGui::GetWindowDrawList()->AddLine(ImVec2(NPCxmid[i] - NPCxsize[i] / 2, NPCymid[i] - NPCysize[i] / 2), ImVec2(NPCxmid[i] - NPCxsize[i] / 2, NPCymid[i] + NPCysize[i] / 2), ImColor(255, 0, 255, 255), 1.f);

								//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 60.f), ImColor(0, 255, 0, 255), to_string((NPCxstart[i])).c_str(), 0, 0.0f, 0);
								//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 50.f), ImColor(0, 255, 0, 255), to_string((NPCxend[i])).c_str(), 0, 0.0f, 0);
								//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 80.f), ImColor(0, 255, 0, 255), to_string((NPCystart[i])).c_str(), 0, 0.0f, 0);
								//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 70.f), ImColor(0, 255, 0, 255), to_string((NPCyend[i])).c_str(), 0, 0.0f, 0);
								//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 90.f), ImColor(0, 255, 0, 255), to_string((NPCxmid[i])).c_str(), 0, 0.0f, 0);
								//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 100.f), ImColor(0, 255, 0, 255), to_string((NPCymid[i])).c_str(), 0, 0.0f, 0);
							}
						}
					}
				}
			}

			// players
			if (!GetAsyncKeyState(VK_SHIFT) && !GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_F2)) {
				if (key29 == TRUE) { key29 = FALSE; Sleep(200); }
				else { if (key29 == FALSE) { key29 = TRUE; Sleep(200); } }
			}
			if (key29) {
				if (AllObjectBool == FALSE) {
					AllObjectBool = TRUE;
					AllObjectCount++;
					if (AllObjectCount > 20) {
						AllObjectCount = 0;
						ReadCObjArrays();
					}
				}
				if (!PlX.empty()) {
					for (DWORD i = 0; i < PlX.size(); i++) {
					//	if (ViewFullPl[i] == 1) {

							stringstream stream;
							stream << hex << PlMem[i];
							string result(stream.str());
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Plxmid[i] - 50.f, Plymid[i] + 10.f), ImColor(0, 255, 0, 255), "MemLoc:", 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Plxmid[i], Plymid[i] + 10.f), ImColor(0, 255, 0, 255), result.c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Plxmid[i] - 50.f, Plymid[i]), ImColor(0, 255, 0, 255), "Name:", 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Plxmid[i], Plymid[i]), ImColor(0, 255, 0, 255), PlName[i].c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Plxmid[i] - 50.f, Plymid[i] - 20.f), ImColor(0, 255, 0, 255), "id:", 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Plxmid[i], Plymid[i] - 20.f), ImColor(0, 255, 0, 255), to_string((PlID[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Plxmid[i] - 50.f, Plymid[i] - 10), ImColor(0, 255, 0, 255), "Health:", 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Plxmid[i], Plymid[i] - 10.f), ImColor(0, 255, 0, 255), to_string((PlLife[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(Plxmid[i], Plymid[i] - 30.f), ImColor(0, 255, 0, 255), to_string((PlAnim[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(Plxmid[i], Plymid[i]), 2, ImColor(255, 0, 0, 255));

						}
					}
			//	}
			}

			//Main INTEREFaces
			if (!GetAsyncKeyState(VK_SHIFT) && !GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_F11)) {
				if (key11 == TRUE) { key11 = FALSE; Sleep(200); }
				else { if (key11 == FALSE) { key11 = TRUE; Sleep(200); } }
			}
			if (key11) {

				ReadInterf();
				///cout << "ex:" << dec << InterfActive.size() << "\n";
				///cout << "ex2:" << dec << InterfID.size() << "\n";
				if(!InterfID.empty()){
					for (DWORD i = 0; i < InterfID.size(); i++) {
						//filter
						//1477 is based on timer
						// directly points to other array
							DWORD64 placeholder = VirtPRead64(InterfMem[i] + Itimeroff);
						//timer!!
						WORD OtherT = VirtPReadWord(placeholder + Itimeroff2);
						if (//InterfID[i] == 1477
							//dno try to filter some mess out
							//&&
							!(InterfID[i] == 137 && InterfID2[i] == 0 && InterfID3[i] == 0xffff && InterfID4[i] == 5)
							//covers entire screen!
							&&
							!(InterfID[i] == 1488 && InterfID2[i] == 0 && InterfID3[i] == 0xffff && InterfID4[i] == 0xffff)
							//covers entire screen! closes when mouse right menu opens
							&&
							!(InterfID[i] == 1680 && InterfID2[i] == 0 && InterfID3[i] == 0xffff && InterfID4[i] == 0xffff)
							//dno
							&&
							!(InterfID[i] == 1536 && InterfID2[i] == 0 && InterfID3[i] == 0xffff && InterfID4[i] == 0xffff)
							//covers screen
							&&
							!(InterfID[i] == 1216 && InterfID2[i] == 1 && InterfID3[i] == 0xffff && InterfID4[i] == 0)
							//covers screen
							&&
							!(InterfID[i] == 1482 && InterfID2[i] == 1 && InterfID3[i] == 0xffff && InterfID4[i] == 0xffff)
							//covers screen
							&&
							!(InterfID[i] == 1488 && InterfID2[i] == 2 && InterfID3[i] == 0xffff && InterfID4[i] == 0)
							//dno hover to open
							&&
							!(InterfID[i] == 1488 && InterfID2[i] == 4 && InterfID3[i] == 0xffff && InterfID4[i] == 0)
							//dno cons open
							&&
							!(InterfID[i] == 137 && InterfID2[i] == 24 && InterfID3[i] == 0xffff && InterfID4[i] == 21)
							//dno cons open
							&&
							!(InterfID[i] == 137 && InterfID2[i] == 21 && InterfID3[i] == 0xffff && InterfID4[i] == 0)					
							//dno cons open
							&&
							InterfID[i] != 1433
							//&&
							//&&
							//InterfID[i] == 1370
							//&&
							//InterfHov[i]==1
							//&&
							//InterfID3[i] == 0xffff
							//&&
							//InterfID4[i] == 0xffff
						//	&&
							//InterfID2[i] >=0 && InterfID2[i] <10
							&&
							InterfTimer[i] != OtherT
							//&&
							//InterfAct[i]==TRUE
							) {
							//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i], InterfY[i]), ImColor(0, 255, 0, 255), InterName[i].c_str(), 0, 0.0f, 0);
							//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i]-50.f, InterfY[i] - 20.f), ImColor(0, 255, 0, 255), "id:", 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i] + 10.f, InterfY[i] + 20.f), ImColor(0, 255, 0, 255), to_string((InterfID[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i] + 60.f + 10.f, InterfY[i] + 20.f), ImColor(0, 255, 0, 255), to_string((InterfID2[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i] + 90.f + 10.f, InterfY[i] + 20.f), ImColor(0, 255, 0, 255), to_string((InterfID3[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i] + 130.f + 10.f, InterfY[i] + 20.f), ImColor(0, 255, 0, 255), to_string((InterfID4[i])).c_str(), 0, 0.0f, 0);
							stringstream stream;
							stream << hex << InterfMem[i];
							string result(stream.str());
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i] + 10.f, InterfY[i] + 30.f), ImColor(0, 255, 0, 255), result.c_str(), 0, 0.0f, 0);

							//
							ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(InterfX[i], InterfY[i]), 4, ImColor(255, 0, 0, 255));
							//
							ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX[i], InterfY[i]), ImVec2(InterfX[i] + InterfXs11[i], InterfY[i]), ImColor(255, 0, 0, 255), 1.f);
							ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX[i] + InterfXs11[i], InterfY[i]), ImVec2(InterfX[i] + InterfXs11[i], InterfY[i] + InterfYs11[i]), ImColor(255, 0, 0, 255), 1.f);
							ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX[i], InterfY[i] + InterfYs11[i]), ImVec2(InterfX[i] + InterfXs11[i], InterfY[i] + InterfYs11[i]), ImColor(255, 0, 0, 255), 1.f);
							ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX[i], InterfY[i]), ImVec2(InterfX[i] , InterfY[i] + InterfYs11[i]), ImColor(255, 0, 0, 255), 1.f);
						}
					}
				}
			}

			//Main INTEREFaces 1477
			if (GetAsyncKeyState(VK_CONTROL) && !GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F11)) {
				if (key28 == TRUE) { key28 = FALSE; Sleep(200); }
				else { if (key28 == FALSE) { key28 = TRUE; Sleep(200); } }
			}
			if (key28) {

				ReadInterf();
				if (!InterfID.empty()) {
					for (DWORD i = 0; i < InterfID.size(); i++) {
						//filter
						//1477 is based on timer
						//directly points to other array
						//DWORD64 placeholder = VirtPRead64(InterfMem[i] + 0x3e8);
						//timer!!
						//DWORD OtherT = VirtPReadDword(placeholder + 0x158);
						//762 bank
						//1218 13 ffff ffff skill guide
						//1253 0 ffff ffff treasure hunter open
						//1048 31 ffff 0 log out ask
						// lootbox open 1622 4 ffff ffff
						if (GetAsyncKeyState(VK_ADD)) { 							
							InterfAdd = InterfAdd + 50; 
							Sleep(200);
						}
						if (GetAsyncKeyState(VK_SUBTRACT)) {
							InterfAdd = InterfAdd - 50; 
							Sleep(200);
						}
						if (
							(InterfID[i] > InterfAdd 
							&& InterfID[i] < InterfAdd+50
							)
							&& InterfID[i] == 131
							//&& InterfID4[i] == 65535
						     &&
							InterfHov[i] == 1
							//&&
							//InterfID2[i] <60
							//&&
							//InterfTimer[i]!= OtherT
							//&&
							//InterfAct[i] == TRUE
							//InterfID12[i] == 1477
							//&&
							//InterfID4[i] == 0xffff
							) {
							//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i], InterfY[i]), ImColor(0, 255, 0, 255), InterName[i].c_str(), 0, 0.0f, 0);
							//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i]-50.f, InterfY[i] - 20.f), ImColor(0, 255, 0, 255), "id:", 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i] + 10.f, InterfY[i] + 20.f), ImColor(0, 255, 0, 255), to_string((InterfID[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i] + 60.f + 10.f, InterfY[i] + 20.f), ImColor(0, 255, 0, 255), to_string((InterfID2[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i] + 90.f + 10.f, InterfY[i] + 20.f), ImColor(0, 255, 0, 255), to_string((InterfID3[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i] + 130.f + 10.f, InterfY[i] + 20.f), ImColor(0, 255, 0, 255), to_string((InterfID4[i])).c_str(), 0, 0.0f, 0);
							stringstream stream;
							stream << hex << InterfMem[i];
							string result(stream.str());
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i] + 10.f, InterfY[i] + 30.f), ImColor(0, 255, 0, 255), result.c_str(), 0, 0.0f, 0);

							//
							ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(InterfX[i], InterfY[i]), 4, ImColor(255, 0, 0, 255));
							//
							ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX[i], InterfY[i]), ImVec2(InterfX[i] + InterfXs11[i], InterfY[i]), ImColor(255, 0, 0, 255), 1.f);
							ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX[i] + InterfXs11[i], InterfY[i]), ImVec2(InterfX[i] + InterfXs11[i], InterfY[i] + InterfYs11[i]), ImColor(255, 0, 0, 255), 1.f);
							ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX[i], InterfY[i] + InterfYs11[i]), ImVec2(InterfX[i] + InterfXs11[i], InterfY[i] + InterfYs11[i]), ImColor(255, 0, 0, 255), 1.f);
							ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX[i], InterfY[i]), ImVec2(InterfX[i], InterfY[i] + InterfYs11[i]), ImColor(255, 0, 0, 255), 1.f);
						}
					}
				}
			}

			//Secondary INTEREFaces
			if (!GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F11)) {
				if (key22 == TRUE) { key22 = FALSE; Sleep(200); }
				else { if (key22 == FALSE) { key22 = TRUE; Sleep(200); } }
			}
			if (key22) {

				ReadInterf2();
				///cout << "ex:" << dec << InterfActive.size() << "\n";
				///cout << "ex2:" << dec << InterfID.size() << "\n";
				if (!InterfID12.empty()) {
					for (DWORD i = 0; i < InterfID12.size(); i++) {
						if (GetAsyncKeyState(VK_ADD)) {
							InterfAdd = InterfAdd + 50;
							Sleep(200);
						}
						if (GetAsyncKeyState(VK_SUBTRACT)) {
							InterfAdd = InterfAdd - 50;
							Sleep(200);
						}
						if (
							//InterfHov2[i]==1
					    	//&& 
							//InterfAct2[i]==TRUE
							//
							//&&
							(InterfID12[i] > InterfAdd && InterfID12[i] < InterfAdd+50)
							//InterfID12[i] == 1477
							//InterfID22[i] == 815
							//&&
							//InterfID42[i] == 813
							) {
							//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX2[i], InterfY2[i]), ImColor(0, 255, 0, 255), InterName2[i].c_str(), 0, 0.0f, 0);
							//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX2[i]-50.f, InterfY2[i] - 20.f), ImColor(0, 255, 0, 255), "id:", 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX2[i] + 10.f, InterfY2[i] + 20.f), ImColor(0, 255, 0, 255), to_string((InterfID12[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX2[i] + 60.f + 10.f, InterfY2[i] + 20.f), ImColor(0, 255, 0, 255), to_string((InterfID22[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX2[i] + 90.f + 10.f, InterfY2[i] + 20.f), ImColor(0, 255, 0, 255), to_string((InterfID32[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX2[i] + 130.f + 10.f, InterfY2[i] + 20.f), ImColor(0, 255, 0, 255), to_string((InterfID42[i])).c_str(), 0, 0.0f, 0);
							stringstream stream;
							stream << hex << InterfMem2[i];
							string result(stream.str());
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX2[i]  + 10.f, InterfY2[i]+ 30.f), ImColor(0, 255, 0, 255), result.c_str(), 0, 0.0f, 0);

							//
							ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(InterfX2[i], InterfY2[i]), 4, ImColor(255, 0, 0, 255));
							//
							ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX2[i], InterfY2[i]), ImVec2(InterfX2[i] + InterfXs22[i], InterfY2[i]), ImColor(255, 0, 0, 255), 1.f);
							ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX2[i] + InterfXs22[i], InterfY2[i]), ImVec2(InterfX2[i] + InterfXs22[i], InterfY2[i] + InterfYs22[i]), ImColor(255, 0, 0, 255), 1.f);
							ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX2[i], InterfY2[i] + InterfYs22[i]), ImVec2(InterfX2[i] + InterfXs22[i], InterfY2[i] + InterfYs22[i]), ImColor(255, 0, 0, 255), 1.f);
							ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX2[i], InterfY2[i]), ImVec2(InterfX2[i], InterfY2[i] + InterfYs22[i]), ImColor(255, 0, 0, 255), 1.f);
						}
					}
				}
			}


			//Main INTEREFaces test
			if (GetAsyncKeyState(VK_SHIFT) && !GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_F12)) {
				if (key12 == TRUE) { key12 = FALSE; Sleep(200); }
				else { if (key12 == FALSE) { key12 = TRUE; Sleep(200); } }
			}
			if (key12) {

				ReadInterfAll();
				///cout << "ex:" << dec << InterfActive.size() << "\n";
				///cout << "ex2:" << dec << InterfID.size() << "\n";
				if (!InterfID.empty()) {
					for (DWORD i = 0; i < InterfID.size(); i++) {
						//filter
						//1477 is based on timer
						// directly points to other array
						//DWORD64 placeholder = VirtPRead64(InterfMem[i] + Itimeroff);
						//timer!!
						//WORD OtherT = VirtPReadWord(placeholder + Itimeroff2);
						if (
							//
							//InterfID[i] == 1477
							//dno try to filter some mess out
							//&&
							//!(InterfID[i] == 137 && InterfID2[i] == 0 && InterfID3[i] == 0xffff && InterfID4[i] == 5)
							//covers entire screen!
							//&&
							//!(InterfID[i] == 1488 && InterfID2[i] == 0 && InterfID3[i] == 0xffff && InterfID4[i] == 0xffff)
							//covers entire screen! closes when mouse right menu opens
							//&&
							//!(InterfID[i] == 1680 && InterfID2[i] == 0 && InterfID3[i] == 0xffff && InterfID4[i] == 0xffff)
							//dno
							//&&
							//!(InterfID[i] == 1536 && InterfID2[i] == 0 && InterfID3[i] == 0xffff && InterfID4[i] == 0xffff)
							//covers screen
							//&&
							//!(InterfID[i] == 1216 && InterfID2[i] == 1 && InterfID3[i] == 0xffff && InterfID4[i] == 0)
							//covers screen
							//&&
							//!(InterfID[i] == 1482 && InterfID2[i] == 1 && InterfID3[i] == 0xffff && InterfID4[i] == 0xffff)
							//covers screen
							//&&
							//!(InterfID[i] == 1488 && InterfID2[i] == 2 && InterfID3[i] == 0xffff && InterfID4[i] == 0)
							//dno hover to open
							//&&
							//!(InterfID[i] == 1488 && InterfID2[i] == 4 && InterfID3[i] == 0xffff && InterfID4[i] == 0)
							//dno cons open
							//&&
							//!(InterfID[i] == 137 && InterfID2[i] == 24 && InterfID3[i] == 0xffff && InterfID4[i] == 21)
							//dno cons open
							//&&
							//!(InterfID[i] == 137 && InterfID2[i] == 21 && InterfID3[i] == 0xffff && InterfID4[i] == 0)
							//dno cons open
							//&&
							//InterfID[i] != 1433
							//&&
							//&&
							//InterfID[i] == 1370
							//&&
							//InterfHov[i]==1
							//&&
							//InterfID3[i] == 0xffff
							//&&
							//InterfID4[i] == 0xffff
							//	&&
							//InterfID2[i] >=0 && InterfID2[i] <10
							//&&
							//InterfTimer[i] != OtherT
							//&&
							InterfAct[i]==0
							) {
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i], InterfY[i]), ImColor(0, 255, 0, 255), InterName[i].c_str(), 0, 0.0f, 0);
							//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i]-50.f, InterfY[i] - 20.f), ImColor(0, 255, 0, 255), "id:", 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i] + 10.f, InterfY[i] + 20.f), ImColor(0, 255, 0, 255), to_string((InterfID[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i] + 60.f + 10.f, InterfY[i] + 20.f), ImColor(0, 255, 0, 255), to_string((InterfID2[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i] + 90.f + 10.f, InterfY[i] + 20.f), ImColor(0, 255, 0, 255), to_string((InterfID3[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i] + 130.f + 10.f, InterfY[i] + 20.f), ImColor(0, 255, 0, 255), to_string((InterfID4[i])).c_str(), 0, 0.0f, 0);
							stringstream stream;
							stream << hex << InterfMem[i];
							string result(stream.str());
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(InterfX[i] + 10.f, InterfY[i] + 30.f), ImColor(0, 255, 0, 255), result.c_str(), 0, 0.0f, 0);

							//
							ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(InterfX[i], InterfY[i]), 4, ImColor(255, 0, 0, 255));
							//
							ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX[i], InterfY[i]), ImVec2(InterfX[i] + InterfXs11[i], InterfY[i]), ImColor(255, 0, 0, 255), 1.f);
							ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX[i] + InterfXs11[i], InterfY[i]), ImVec2(InterfX[i] + InterfXs11[i], InterfY[i] + InterfYs11[i]), ImColor(255, 0, 0, 255), 1.f);
							ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX[i], InterfY[i] + InterfYs11[i]), ImVec2(InterfX[i] + InterfXs11[i], InterfY[i] + InterfYs11[i]), ImColor(255, 0, 0, 255), 1.f);
							ImGui::GetWindowDrawList()->AddLine(ImVec2(InterfX[i], InterfY[i]), ImVec2(InterfX[i], InterfY[i] + InterfYs11[i]), ImColor(255, 0, 0, 255), 1.f);
						}
					}
				}
			}
			
			//minimap npcs
			if (GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F10)) {
				if (key15 == TRUE) { key15 = FALSE; Sleep(200); }
				else { if (key15 == FALSE) { key15 = TRUE; Sleep(200); } }
			}
			if (key15) {
				//ReadNPCArray();
				if (AllObjectBool == FALSE) {
					AllObjectBool = TRUE;
					AllObjectCount++;
					if (AllObjectCount>10) {
						AllObjectCount = 0;
						ReadCObjArrays();
					}
				}
				for (DWORD i = 0; i < NPCX.size(); i++) {
					//for (DWORD i = 0; i < ObjX.size(); i++) {

					//cout <<dec<< "Mousec:" <<"\n";
					//FFPOINT xy = ToMapFFPOINT({ ObjX[i], ObjY[i] });
					FFPOINT xy = ToMapFFPOINT({ NPCX[i], NPCY[i] });
					//cout <<dec<< "Mousec:" << x2 <<":"<< y2 << "\n";


					//stringstream stream;
					//stream << hex << ObjID[i];
					//	string result(stream.str());

					//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y - 20.f), ImColor(0, 255, 0, 255), "id:", 0, 0.0f, 0);
					//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 20.f), ImColor(0, 255, 0, 255), to_string((PlID[i])).c_str(), 0, 0.0f, 0);
					//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y - 10), ImColor(0, 255, 0, 255), "Health:", 0, 0.0f, 0);
					//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 10.f), ImColor(0, 255, 0, 255), to_string((PlLife[i])).c_str(), 0, 0.0f, 0);

					//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 30.f), ImColor(0, 255, 0, 255), to_string((test777[i])).c_str(), 0, 0.0f, 0);
					ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(xy.x, xy.y), 2, ImColor(255, 0, 0, 255));
					ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y), ImColor(0, 255, 0, 255), NPCName[i].c_str(), 0, 0.0f, 0);

				}
			}

			//minimap players
			if (GetAsyncKeyState(VK_SHIFT) && !GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_F2)) {
				if (key31 == TRUE) { key31 = FALSE; Sleep(200); }
				else { if (key31 == FALSE) { key31 = TRUE; Sleep(200); } }
			}
			if (key31) {
				//ReadPArray();
				if (AllObjectBool == FALSE) {
					AllObjectBool = TRUE;
					AllObjectCount++;
					if (AllObjectCount>10) {
						AllObjectCount = 0;
						ReadCObjArrays();
					}
				}
				for (DWORD i = 0; i < PlX.size(); i++) {
					//localplayer filter
					if (VirtPReadByte(PlMem[i] + poff44) != 6) {
					FFPOINT xy = ToMapFFPOINT({ PlX[i], PlY[i] });



					//stringstream stream;
					//stream << hex << ObjID[i];
					//	string result(stream.str());

					//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y - 20.f), ImColor(0, 255, 0, 255), "id:", 0, 0.0f, 0);
					//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 20.f), ImColor(0, 255, 0, 255), to_string((PlID[i])).c_str(), 0, 0.0f, 0);
					//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y - 10), ImColor(0, 255, 0, 255), "Health:", 0, 0.0f, 0);
					//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 10.f), ImColor(0, 255, 0, 255), to_string((PlLife[i])).c_str(), 0, 0.0f, 0);

					//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 30.f), ImColor(0, 255, 0, 255), to_string((test777[i])).c_str(), 0, 0.0f, 0);
					ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(xy.x, xy.y), 2, ImColor(255, 0, 0, 255));
					ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y), ImColor(0, 255, 0, 255), PlName[i].c_str(), 0, 0.0f, 0);
				}
				}
			}

			//all
			if (GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F8)) {
				if (key24 == TRUE) { key24 = FALSE; Sleep(200); }
				else { if (key24 == FALSE) { key24 = TRUE; Sleep(200); } }
			}
			if ( key24) {
				if (AllObjectBool == FALSE) {
					AllObjectBool = TRUE;
					AllObjectCount++;
					if (AllObjectCount>10) {
						AllObjectCount = 0;
						ReadCObjArrays();
					}
				}
				if (!ObjX.empty()) {
					for (DWORD i = 0; i < ObjX.size(); i++) {
							FFPOINT xy = ToMapFFPOINT({ ObjX[i], ObjY[i] });

							stringstream stream2;
							stream2 << hex << ObjExtra[i];
							string objAddr2(stream2.str());


							//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y - 20.f), ImColor(0, 255, 0, 255), "id:", 0, 0.0f, 0);
							//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 20.f), ImColor(0, 255, 0, 255), to_string((PlID[i])).c_str(), 0, 0.0f, 0);
							//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y - 10), ImColor(0, 255, 0, 255), "Health:", 0, 0.0f, 0);
							//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 10.f), ImColor(0, 255, 0, 255), to_string((PlLife[i])).c_str(), 0, 0.0f, 0);

							//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 30.f), ImColor(0, 255, 0, 255), to_string((test777[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(xy.x, xy.y), 2, ImColor(255, 0, 0, 255));
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y), ImColor(0, 255, 0, 255), objAddr2.c_str(), 0, 0.0f, 0);
						}
				}
			}

			//minimap Aobjects
			if (!GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F7)) {
				if (key20 == TRUE) { key20 = FALSE; Sleep(200); }
				else { if (key20 == FALSE) { key20 = TRUE; Sleep(200); } }
			}
			if (key20) {

				if (AllObjectBool == FALSE) {
					AllObjectBool = TRUE;
					AllObjectCount++;
					if (AllObjectCount>10) {
						AllObjectCount = 0;
						ReadCObjArrays();
					}
				}
				if (!ObjectsXf.empty()) {
					ImGui::PushFont(io.Fonts->Fonts[1]);
					for (DWORD i = 0; i < ObjectsXf.size(); i++) {
						//for (DWORD i = 0; i < ObjX.size(); i++) {

						//cout <<dec<< "Mousec:" <<"\n";
						//FFPOINT xy = ToMapFFPOINT({ ObjX[i], ObjY[i] });
						FFPOINT xy = ToMapFFPOINT({ ObjectsXf[i], ObjectsYf[i] });
						//cout <<dec<< "Mousec:" << x2 <<":"<< y2 << "\n";


						//stringstream stream;
						//stream << hex << ObjID[i];
						//	string result(stream.str());

						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y - 20.f), ImColor(0, 255, 0, 255), "id:", 0, 0.0f, 0);
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 20.f), ImColor(0, 255, 0, 255), to_string((PlID[i])).c_str(), 0, 0.0f, 0);
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y - 10), ImColor(0, 255, 0, 255), "Health:", 0, 0.0f, 0);
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 10.f), ImColor(0, 255, 0, 255), to_string((PlLife[i])).c_str(), 0, 0.0f, 0);

						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 30.f), ImColor(0, 255, 0, 255), to_string((test777[i])).c_str(), 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(xy.x, xy.y), 2, ImColor(255, 0, 0, 255));
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y), ImColor(0, 255, 0, 255), ObjectsName[i].c_str(), 0, 0.0f, 0);

					}
					ImGui::PopFont();
				}
			}

			//minimap Aobjects special filter for dung doors
			if (GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F7)) {
				if (key32 == TRUE) { key32 = FALSE; Sleep(200); }
				else { if (key32 == FALSE) { key32 = TRUE; Sleep(200); } }
			}
			if (key32) {

				if (AllObjectBool == FALSE) {
					AllObjectBool = TRUE;
					AllObjectCount++;
					if (AllObjectCount > 10) {
						AllObjectCount = 0;
						ReadCObjArrays();
					}
				}
				ImGui::PushFont(io.Fonts->Fonts[1]);
				//active doors
				if (!ObjectsXf.empty()) {
					for (DWORD i = 0; i < ObjectsXf.size(); i++) {
						//for (DWORD i = 0; i < ObjX.size(); i++) {
						if (ObjectsName[i].length() > 0 && ObjectsAction1[i].length() > 0) {
							if ((ObjectsName[i].find("door") != string::npos && ObjectsAction1[i].find("Unlock") != string::npos)
								|| ObjectsName[i].find("Guardian") != string::npos
								|| ObjectsAction1[i].find("Drain") != string::npos
								|| ObjectsAction1[i].find("Prune") != string::npos
								|| ObjectsAction1[i].find("Force") != string::npos
								|| ObjectsAction1[i].find("Dispel") != string::npos
								|| ObjectsAction1[i].find("Disarm") != string::npos
								|| (ObjectsName[i].find("door") != string::npos && ObjectsAction1[i].find("Imbue") != string::npos)
								|| (ObjectsName[i].find("rocks") != string::npos && ObjectsAction1[i].find("Mine") != string::npos)
								|| ObjectsAction1[i].find("Fix") != string::npos
								|| ObjectsAction1[i].find("Repair") != string::npos
								|| ObjectsAction1[i].find("Pick-") != string::npos
								|| ObjectsAction1[i].find("Exorcise") != string::npos
								|| ObjectsAction1[i].find("Burn") != string::npos
								|| ObjectsAction1[i].find("Dismiss") != string::npos
								|| ObjectsAction1[i].find("Add-") != string::npos
								|| ObjectsAction1[i].find("Chop-") != string::npos
								) {
								string p = ObjectsName[i];
								//resize						
								p.resize(9, ' ');

								//FFPOINT xy = ToMapFFPOINT({ ObjX[i], ObjY[i] });
								FFPOINT xy = ToMapFFPOINT({ ObjectsXf[i], ObjectsYf[i] });
								//cout <<dec<< "Mousec:" << x2 <<":"<< y2 << "\n";


								//stringstream stream;
								//stream << hex << ObjID[i];
								//	string result(stream.str());

								//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y - 20.f), ImColor(0, 255, 0, 255), "id:", 0, 0.0f, 0);
								//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 20.f), ImColor(0, 255, 0, 255), to_string((PlID[i])).c_str(), 0, 0.0f, 0);
								//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y - 10), ImColor(0, 255, 0, 255), "Health:", 0, 0.0f, 0);
								//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 10.f), ImColor(0, 255, 0, 255), to_string((PlLife[i])).c_str(), 0, 0.0f, 0);

								//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 30.f), ImColor(0, 255, 0, 255), to_string((test777[i])).c_str(), 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(xy.x, xy.y), 2, ImColor(200, 0, 200, 255));
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y), ImColor(0, 255, 0, 255), p.c_str(), 0, 0.0f, 0);
							}
						}
					}
				}
				if (!GIID2.empty()) {
					for (DWORD i = 0; i < GIID2.size(); i++) {
						if (GIID2[i] > 18201 && GIID2[i] < 18329) {
							FFPOINT xy = ToMapFFPOINT({ GIX2[i], GIY2[i] });
							//varp status
							DungMap p = GetItemText2(GIID2[i]);
							//no idea where to go from here
							//FindVarBit(p.varp);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y), ImColor(0, 255, 255, 255), p.text.c_str(), 0, 0.0f, 0);

						}
					}
				}
				if (!NPCX.empty()) {
					for (DWORD i = 0; i < NPCX.size(); i++) {
						if (NPCName[i].find("dragon") != string::npos) {
							FFPOINT xy = ToMapFFPOINT({ NPCX[i], NPCY[i] });
							ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(xy.x, xy.y), 2, ImColor(255, 0, 0, 255));
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y), ImColor(0, 0, 255, 255), NPCName[i].c_str(), 0, 0.0f, 0);
						}
					}
				}
				ImGui::PopFont();
			}

			//minimap Dobjects
			if (GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F9)) {
				if (key30 == TRUE) { key30 = FALSE; Sleep(200); }
				else { if (key30 == FALSE) { key30 = TRUE; Sleep(200); } }
			}
			if (key30) {

				if (AllObjectBool == FALSE) {
					AllObjectBool = TRUE;
					AllObjectCount++;
					if (AllObjectCount>10) {
						AllObjectCount = 0;
						ReadCObjArrays();
					}
				}				
				if (!DecorXf.empty()) {
					ImGui::PushFont(io.Fonts->Fonts[1]);
					for (DWORD i = 0; i < DecorXf.size(); i++) {
						//if (DecorID[i]>61469) {

						//cout <<dec<< "Mousec:" <<"\n";
						//FFPOINT xy = ToMapFFPOINT({ ObjX[i], ObjY[i] });
						FFPOINT xy = ToMapFFPOINT({ DecorXf[i], DecorYf[i] });
						//cout <<dec<< "Mousec:" << x2 <<":"<< y2 << "\n";


						//stringstream stream;
						//stream << hex << ObjID[i];
						//	string result(stream.str());

						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y - 20.f), ImColor(0, 255, 0, 255), "id:", 0, 0.0f, 0);
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 20.f), ImColor(0, 255, 0, 255), to_string((PlID[i])).c_str(), 0, 0.0f, 0);
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y - 10), ImColor(0, 255, 0, 255), "Health:", 0, 0.0f, 0);
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 10.f), ImColor(0, 255, 0, 255), to_string((PlLife[i])).c_str(), 0, 0.0f, 0);

						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 30.f), ImColor(0, 255, 0, 255), to_string((test777[i])).c_str(), 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(xy.x, xy.y), 2, ImColor(255, 0, 0, 255));
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y), ImColor(0, 255, 0, 255), DecorName[i].c_str(), 0, 0.0f, 0);
					}
					ImGui::PopFont();
				}
			}

			//debug  gr2 array minimap
			if (!GetAsyncKeyState(VK_CONTROL) && GetAsyncKeyState(VK_SHIFT) && GetAsyncKeyState(VK_F1)) {

				if (key21 == TRUE) { key21 = FALSE; Sleep(200); }
				else { if (key21 == FALSE) { key21 = TRUE; Sleep(200); } }
			}
			if (key21) {
				if (AllObjectBool == FALSE) {
					AllObjectBool = TRUE;
					AllObjectCount++;
					if (AllObjectCount>10) {
						AllObjectCount = 0;
						ReadCObjArrays();
					}
				}
				//ReadGroundItemsArray2();
				if (!GIID2.empty()) {
					ImGui::PushFont(io.Fonts->Fonts[1]);
					for (DWORD i = 0; i < GIID2.size(); i++) {

						//FFPOINT xy = TileToMouseTest22({ GIX[i], GIY[i] });
						FFPOINT xy = ToMapFFPOINT({ GIX2[i], GIY2[i] });

						//stringstream stream;
						//stream << hex << GIMem2[i];
						//string result(stream.str());
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 20.f, xy.y), ImColor(0, 255, 255, 255), "ID:", 0, 0.0f, 0);
						if (GIText2[i] == "") {
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y), ImColor(0, 255, 255, 255), to_string((GIID2[i])).c_str(), 0, 0.0f, 0);
						}
						else {
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y), ImColor(0, 255, 255, 255), GIText2[i].c_str(), 0, 0.0f, 0);
						}
						//ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(xy.x, xy.y), 1, ImColor(255, 0, 0, 255));
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 20.f, xy.y - 10.f), ImColor(0, 255, 0, 255), "am:", 0, 0.0f, 0);
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 10.f), ImColor(0, 255, 0, 255), to_string((GIAM[i])).c_str(), 0, 0.0f, 0);
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x + 30, xy.y - 5.f), ImColor(255, 0, 0, 255), GIText[i].c_str(), 0, 0.0f, 0);
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 20.f, xy.y - 20.f), ImColor(0, 255, 255, 255), "Mem:", 0, 0.0f, 0);
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 20.f), ImColor(0, 255, 255, 255), (result).c_str(), 0, 0.0f, 0);						
					}
					ImGui::PopFont();
				}
			}

			//
			if (GetAsyncKeyState(VK_HOME)) {
				if (key16 == TRUE) { key16 = FALSE; Sleep(200); }
				else { if (key16 == FALSE) { key16 = TRUE; Sleep(200); } }
			}
			if (LocalPlayer != NULL && key16) {
				
				//cout << "Time" <<endl;
				if (CheckAnim()==FALSE && ReadPlayerMovin()==FALSE) {
					
					if (StartTime == 0) { cout << '\a'; StartTime = SystemTime(); }
					if ((SystemTime() - StartTime) > 500) { StartTime = 0; }

					//cout << "Time in Milliseconds =" << StartTime - SystemTime() << std::endl;
				}



				/*
				if (!PlX.empty()) {
					for (DWORD i = 0; i < PlX.size(); i++) {
						if (PlID[i] > 0xffff) {
							if (VirtPReadByte(PlMem[i] + npcoff44) != 6) {


								if (StartTime == 0) { cout << '\a'; StartTime = SystemTime(); }
								if ((SystemTime()-StartTime) > 500) { StartTime = 0; }

								//cout << "Time in Milliseconds =" << StartTime- SystemTime() << std::endl;

								FFPOINT xy = ToMapFFPOINT({ PlX[i], PlY[i] });
								ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(xy.x, xy.y), 4, ImColor(255, 0, 0, 255));
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(400.f, 480.f), ImColor(255, 0, 0, 255), "Other Player!!!!!!!!!!!!!!!!:", 0, 0.0f, 0);
								ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(400.f, 500.f), ImColor(0, 255, 0, 255), "Other Player!!!!!!!!!!!!!!!!:", 0, 0.0f, 0);
							}
						}
					}
				}
               */
			}
			//debug  g array for revants	
			if (GetAsyncKeyState(VK_END)) {

				if (key17 == TRUE) { key17 = FALSE; Sleep(200); }
				else { if (key17 == FALSE) { key17 = TRUE; Sleep(200); } }
			}
			if (key17) {
				if (AllObjectBool == FALSE) {
					AllObjectBool = TRUE;
					AllObjectCount++;
					if (AllObjectCount>10) {
						AllObjectCount = 0;
						ReadCObjArrays();
					}
				}
				//ReadGroundItemsArray();
				if (!GIID.empty()) {
					for (DWORD i = 0; i < GIID.size(); i++) {

						if (GIID[i]!=995 && GIID[i]!=31737) {
							//cout <<dec<< "Mousec:" << obj.objx[i] << ":" << obj.objy[i] << "\n";
							FFPOINT xy = TileToMouseTest22({ GIX[i], GIY[i] });
							//cout <<dec<< "Mousec:" << x2 <<":"<< y2 << "\n";
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 20.f, xy.y), ImColor(0, 255, 255, 255), "ID:", 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y), ImColor(0, 255, 255, 255), to_string((GIID[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(xy.x, xy.y), 1, ImColor(255, 0, 0, 255));
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 20.f, xy.y - 10.f), ImColor(0, 255, 0, 255), "am:", 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 10.f), ImColor(0, 255, 0, 255), to_string((GIAM[i])).c_str(), 0, 0.0f, 0);
							ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x + 30, xy.y - 5.f), ImColor(255, 0, 0, 255), GIText[i].c_str(), 0, 0.0f, 0);
						}
						}
				}
			}
			//minimap npcs wisps
			if (GetAsyncKeyState(VK_PRIOR)) {
				if (key18 == TRUE) { key18 = FALSE; Sleep(200); }
				else { if (key18 == FALSE) { key18 = TRUE; Sleep(200); } }
			}
			if (LocalPlayer != NULL && key18) {
				if (AllObjectBool == FALSE) {
					AllObjectBool = TRUE;
					AllObjectCount++;
					if (AllObjectCount>10) {
						AllObjectCount = 0;
						ReadCObjArrays();
					}
				}
				for (DWORD i = 0; i < NPCX.size(); i++) {
					//for (DWORD i = 0; i < ObjX.size(); i++) {
					//important ones
					        string cw1 = "Blue wisp"; 
							string cw11 = "Green wisp"; 
							string cw12 = "Purple wisp"; 
							string cw13 = "Red wisp"; 
							string cw14 = "Yellow wisp";
							string cw2 = "patriarch";
							string cw3 = "impling";
							string cw4 = "Raven";
						if (
							NPCName[i].find(cw1) != string::npos || 
							NPCName[i].find(cw11) != string::npos ||
							NPCName[i].find(cw12) != string::npos ||
							NPCName[i].find(cw13) != string::npos ||
							NPCName[i].find(cw14) != string::npos ||
							NPCName[i].find(cw2) != string::npos || 
							NPCName[i].find(cw3) != string::npos ||
							NPCName[i].find(cw4) != string::npos) {

							


						
						//FFPOINT xy = ToMapFFPOINT({ ObjX[i], ObjY[i] });
						FFPOINT xy = ToMapFFPOINT({ NPCX[i], NPCY[i] });
						//cout <<dec<< "Mousec:" << x2 <<":"<< y2 << "\n";


						//stringstream stream;
						//stream << hex << ObjID[i];
						//	string result(stream.str());

						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y - 20.f), ImColor(0, 255, 0, 255), "id:", 0, 0.0f, 0);
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 20.f), ImColor(0, 255, 0, 255), to_string((PlID[i])).c_str(), 0, 0.0f, 0);
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x - 50.f, xy.y - 10), ImColor(0, 255, 0, 255), "Health:", 0, 0.0f, 0);
						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 10.f), ImColor(0, 255, 0, 255), to_string((PlLife[i])).c_str(), 0, 0.0f, 0);

						//ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y - 30.f), ImColor(0, 255, 0, 255), to_string((test777[i])).c_str(), 0, 0.0f, 0);
						ImGui::GetWindowDrawList()->AddCircleFilled(ImVec2(xy.x, xy.y), 2, ImColor(255, 0, 0, 255));
						ImGui::GetWindowDrawList()->AddText(ImGui::GetWindowFont(), ImGui::GetWindowFontSize(), ImVec2(xy.x, xy.y), ImColor(0, 255, 0, 255), NPCName[i].c_str(), 0, 0.0f, 0);
					}
				}
			}


			ImGui::End();
		}
		// Rendering
		g_pd3dDevice->SetRenderState(D3DRS_ZENABLE, false);
		g_pd3dDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
		g_pd3dDevice->SetRenderState(D3DRS_SCISSORTESTENABLE, false);
		D3DCOLOR clear_col_dx = D3DCOLOR_RGBA((int)(clear_col.x*255.0f), (int)(clear_col.y*255.0f), (int)(clear_col.z*255.0f), (int)(clear_col.w*255.0f));
		g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, clear_col_dx, 0.0f, 0);
		if (g_pd3dDevice->BeginScene() >= 0)
		{
			ImGui::Render();
			g_pd3dDevice->EndScene();
		}
		g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
	}

	ImGui_ImplDX9_Shutdown();
	if (g_pd3dDevice) g_pd3dDevice->Release();
	if (pD3D) pD3D->Release();
	UnregisterClass(_T("Debug3"), wcex.hInstance);

	return 0;
}


BOOLEAN Start(BOOLEAN OverlayB, BYTE level)
{    
	RDPLevel = level;
	//try to reset
	if (!CheckRS3()) {
		RS3Found = FALSE;
		//PaintActive = FALSE;//paint crashes to investigate someday
		//HookinActive = FALSE;//one time is enough
		RefreshLoop = FALSE;
		ScAdd1 = FALSE;
		ScAdd9 = FALSE;
		LocalPlayer = FALSE;
		Compass = FALSE;
		IF = FALSE;

	}
		//ehm main thread
		if (!RS3Found) {
			thread t1(FindRS3);
			t1.join();
		}

		if (!PaintActive && OverlayB) {
			PaintActive = TRUE;
			thread t2(StartGraphicOverlay);
			t2.detach();
		}

		//totally useless
		//mouse and keyboard software flags
		//if (!HookinActive && HookB) {
		//	thread t3(StartHookin);
		//	t3.detach();
		//}

		//Loop for
		if (!RefreshLoop) {
			RefreshLoop = TRUE;
			thread t4(StartLoop);
			t4.detach();
		}
		//mouse inception
		if (!HookinActive) {
			HookinActive = TRUE;
			thread t5(MouseInception);
			t5.detach();
		}


	//return report about success
	if (RS3Found == TRUE && CheckRS3()) {
		return TRUE;
	}
	return FALSE;
}

//crc32
DWORD CRC32CheckSum(void* Data, DWORD Size, DWORD InitialValue)
{
	static const DWORD LookUpTable[256] =
	{
		0x00000000, 0x77073096, 0xEE0E612C, 0x990951BA,
		0x076DC419, 0x706AF48F, 0xE963A535, 0x9E6495A3,
		0x0EDB8832, 0x79DCB8A4, 0xE0D5E91E, 0x97D2D988,
		0x09B64C2B, 0x7EB17CBD, 0xE7B82D07, 0x90BF1D91,
		0x1DB71064, 0x6AB020F2, 0xF3B97148, 0x84BE41DE,
		0x1ADAD47D, 0x6DDDE4EB, 0xF4D4B551, 0x83D385C7,
		0x136C9856, 0x646BA8C0, 0xFD62F97A, 0x8A65C9EC,
		0x14015C4F, 0x63066CD9, 0xFA0F3D63, 0x8D080DF5,
		0x3B6E20C8, 0x4C69105E, 0xD56041E4, 0xA2677172,
		0x3C03E4D1, 0x4B04D447, 0xD20D85FD, 0xA50AB56B,
		0x35B5A8FA, 0x42B2986C, 0xDBBBC9D6, 0xACBCF940,
		0x32D86CE3, 0x45DF5C75, 0xDCD60DCF, 0xABD13D59,
		0x26D930AC, 0x51DE003A, 0xC8D75180, 0xBFD06116,
		0x21B4F4B5, 0x56B3C423, 0xCFBA9599, 0xB8BDA50F,
		0x2802B89E, 0x5F058808, 0xC60CD9B2, 0xB10BE924,
		0x2F6F7C87, 0x58684C11, 0xC1611DAB, 0xB6662D3D,
		0x76DC4190, 0x01DB7106, 0x98D220BC, 0xEFD5102A,
		0x71B18589, 0x06B6B51F, 0x9FBFE4A5, 0xE8B8D433,
		0x7807C9A2, 0x0F00F934, 0x9609A88E, 0xE10E9818,
		0x7F6A0DBB, 0x086D3D2D, 0x91646C97, 0xE6635C01,
		0x6B6B51F4, 0x1C6C6162, 0x856530D8, 0xF262004E,
		0x6C0695ED, 0x1B01A57B, 0x8208F4C1, 0xF50FC457,
		0x65B0D9C6, 0x12B7E950, 0x8BBEB8EA, 0xFCB9887C,
		0x62DD1DDF, 0x15DA2D49, 0x8CD37CF3, 0xFBD44C65,
		0x4DB26158, 0x3AB551CE, 0xA3BC0074, 0xD4BB30E2,
		0x4ADFA541, 0x3DD895D7, 0xA4D1C46D, 0xD3D6F4FB,
		0x4369E96A, 0x346ED9FC, 0xAD678846, 0xDA60B8D0,
		0x44042D73, 0x33031DE5, 0xAA0A4C5F, 0xDD0D7CC9,
		0x5005713C, 0x270241AA, 0xBE0B1010, 0xC90C2086,
		0x5768B525, 0x206F85B3, 0xB966D409, 0xCE61E49F,
		0x5EDEF90E, 0x29D9C998, 0xB0D09822, 0xC7D7A8B4,
		0x59B33D17, 0x2EB40D81, 0xB7BD5C3B, 0xC0BA6CAD,
		0xEDB88320, 0x9ABFB3B6, 0x03B6E20C, 0x74B1D29A,
		0xEAD54739, 0x9DD277AF, 0x04DB2615, 0x73DC1683,
		0xE3630B12, 0x94643B84, 0x0D6D6A3E, 0x7A6A5AA8,
		0xE40ECF0B, 0x9309FF9D, 0x0A00AE27, 0x7D079EB1,
		0xF00F9344, 0x8708A3D2, 0x1E01F268, 0x6906C2FE,
		0xF762575D, 0x806567CB, 0x196C3671, 0x6E6B06E7,
		0xFED41B76, 0x89D32BE0, 0x10DA7A5A, 0x67DD4ACC,
		0xF9B9DF6F, 0x8EBEEFF9, 0x17B7BE43, 0x60B08ED5,
		0xD6D6A3E8, 0xA1D1937E, 0x38D8C2C4, 0x4FDFF252,
		0xD1BB67F1, 0xA6BC5767, 0x3FB506DD, 0x48B2364B,
		0xD80D2BDA, 0xAF0A1B4C, 0x36034AF6, 0x41047A60,
		0xDF60EFC3, 0xA867DF55, 0x316E8EEF, 0x4669BE79,
		0xCB61B38C, 0xBC66831A, 0x256FD2A0, 0x5268E236,
		0xCC0C7795, 0xBB0B4703, 0x220216B9, 0x5505262F,
		0xC5BA3BBE, 0xB2BD0B28, 0x2BB45A92, 0x5CB36A04,
		0xC2D7FFA7, 0xB5D0CF31, 0x2CD99E8B, 0x5BDEAE1D,
		0x9B64C2B0, 0xEC63F226, 0x756AA39C, 0x026D930A,
		0x9C0906A9, 0xEB0E363F, 0x72076785, 0x05005713,
		0x95BF4A82, 0xE2B87A14, 0x7BB12BAE, 0x0CB61B38,
		0x92D28E9B, 0xE5D5BE0D, 0x7CDCEFB7, 0x0BDBDF21,
		0x86D3D2D4, 0xF1D4E242, 0x68DDB3F8, 0x1FDA836E,
		0x81BE16CD, 0xF6B9265B, 0x6FB077E1, 0x18B74777,
		0x88085AE6, 0xFF0F6A70, 0x66063BCA, 0x11010B5C,
		0x8F659EFF, 0xF862AE69, 0x616BFFD3, 0x166CCF45,
		0xA00AE278, 0xD70DD2EE, 0x4E048354, 0x3903B3C2,
		0xA7672661, 0xD06016F7, 0x4969474D, 0x3E6E77DB,
		0xAED16A4A, 0xD9D65ADC, 0x40DF0B66, 0x37D83BF0,
		0xA9BCAE53, 0xDEBB9EC5, 0x47B2CF7F, 0x30B5FFE9,
		0xBDBDF21C, 0xCABAC28A, 0x53B39330, 0x24B4A3A6,
		0xBAD03605, 0xCDD70693, 0x54DE5729, 0x23D967BF,
		0xB3667A2E, 0xC4614AB8, 0x5D681B02, 0x2A6F2B94,
		0xB40BBE37, 0xC30C8EA1, 0x5A05DF1B, 0x2D02EF8D
	};

	DWORD CRC = ~InitialValue;
	uint8_t* Pointer = static_cast<uint8_t*>(Data);

	for (DWORD I = 0; I < Size; ++I)
	{
		CRC = LookUpTable[(CRC ^ *Pointer++) & 0xFF] ^ (CRC >> 8);
	}

	return ~CRC;
}


VOID LoadItemText() {
	//  TextNR.push_back(); TextTxt.push_back("");
	//TextNR.push_back(0) ;TextTxt.push_back("Dwarf remains");
	TextNR.push_back(1) ;TextTxt.push_back("Toolkit");
	TextNR.push_back(2) ;TextTxt.push_back("Cannonball");
	TextNR.push_back(3); TextTxt.push_back("Cannonball-N");
	TextNR.push_back(44); TextTxt.push_back("Rune arrowheads");
	TextNR.push_back(113); TextTxt.push_back("Strength potion (4)");
	TextNR.push_back(114); TextTxt.push_back("Strength potion (4)-N");
	TextNR.push_back(115); TextTxt.push_back("Strength potion (3)");
	TextNR.push_back(116); TextTxt.push_back("Strength potion (3)-N");
	TextNR.push_back(117); TextTxt.push_back("Strength potion (2)");
	TextNR.push_back(118); TextTxt.push_back("Strength potion (2)-N");
	TextNR.push_back(119); TextTxt.push_back("Strength potion (1)");
	TextNR.push_back(120); TextTxt.push_back("Strength potion (1)-N");
	TextNR.push_back(121); TextTxt.push_back("Attack potion (3)");
	TextNR.push_back(122); TextTxt.push_back("Attack potion (3)-N");
	TextNR.push_back(123); TextTxt.push_back("Attack potion (2)");
	TextNR.push_back(124); TextTxt.push_back("Attack potion (2)-N");
	TextNR.push_back(125); TextTxt.push_back("Attack potion (1)");
	TextNR.push_back(126); TextTxt.push_back("Attack potion (1)-N");
	TextNR.push_back(127); TextTxt.push_back("Restore potion (3)");
	TextNR.push_back(128); TextTxt.push_back("Restore potion (3)-N");
	TextNR.push_back(129); TextTxt.push_back("Restore potion (2)");
	TextNR.push_back(130); TextTxt.push_back("Restore potion (2)-N");
	TextNR.push_back(131); TextTxt.push_back("Restore potion (1)");
	TextNR.push_back(132); TextTxt.push_back("Restore potion (1)-N");
	TextNR.push_back(133); TextTxt.push_back("Defence potion (3)");
	TextNR.push_back(134); TextTxt.push_back("Defence potion (3)-N");
	TextNR.push_back(135); TextTxt.push_back("Defence potion (2)");
	TextNR.push_back(136); TextTxt.push_back("Defence potion (2)-N");
	TextNR.push_back(137); TextTxt.push_back("Defence potion (1)");
	TextNR.push_back(138); TextTxt.push_back("Defence potion (1)-N");
	TextNR.push_back(139); TextTxt.push_back("Prayer potion (3)");
	TextNR.push_back(140); TextTxt.push_back("Prayer potion (3)-N");
	TextNR.push_back(141); TextTxt.push_back("Prayer potion (2)");
	TextNR.push_back(142); TextTxt.push_back("Prayer potion (2)-N");
	TextNR.push_back(143); TextTxt.push_back("Prayer potion (1)");
	TextNR.push_back(144); TextTxt.push_back("Prayer potion (1)-N");
	TextNR.push_back(145); TextTxt.push_back("Super attack (3)");
	TextNR.push_back(146); TextTxt.push_back("Super attack (3)-N");
	TextNR.push_back(147); TextTxt.push_back("Super attack (2)");
	TextNR.push_back(148); TextTxt.push_back("Super attack (2)-N");
	TextNR.push_back(149); TextTxt.push_back("Super attack (1)");
	TextNR.push_back(150); TextTxt.push_back("Super attack (1)-N");
	TextNR.push_back(151); TextTxt.push_back("Fishing potion (3)");
	TextNR.push_back(152); TextTxt.push_back("Fishing potion (3)-N");
	TextNR.push_back(153); TextTxt.push_back("Fishing potion (2)");
	TextNR.push_back(154); TextTxt.push_back("Fishing potion (2)-N");
	TextNR.push_back(155); TextTxt.push_back("Fishing potion (1)");
	TextNR.push_back(156); TextTxt.push_back("Fishing potion (1)-N");
	TextNR.push_back(157); TextTxt.push_back("Super strength (3)");
	TextNR.push_back(158); TextTxt.push_back("Super strength (3)-N");
	TextNR.push_back(159); TextTxt.push_back("Super strength (2)");
	TextNR.push_back(160); TextTxt.push_back("Super strength (2)-N");
	TextNR.push_back(161); TextTxt.push_back("Super strength (1)");
	TextNR.push_back(162); TextTxt.push_back("Super strength (1)-N");
	TextNR.push_back(163); TextTxt.push_back("Super defence (3)");
	TextNR.push_back(164); TextTxt.push_back("Super defence (3)");
	TextNR.push_back(165); TextTxt.push_back("Super defence (3)-N");
	TextNR.push_back(165); TextTxt.push_back("Super defence (2)");
	TextNR.push_back(166); TextTxt.push_back("Super defence (2)-N");
	TextNR.push_back(167); TextTxt.push_back("Super defence (1)");
	TextNR.push_back(168); TextTxt.push_back("Super defence (1)-N");
	TextNR.push_back(169); TextTxt.push_back("Ranging potion (3)");
	TextNR.push_back(170); TextTxt.push_back("Ranging potion (3)-N");
	TextNR.push_back(171); TextTxt.push_back("Ranging potion (2)");
	TextNR.push_back(172); TextTxt.push_back("Ranging potion (2)-N");
	TextNR.push_back(173); TextTxt.push_back("Ranging potion (1)");
	TextNR.push_back(174); TextTxt.push_back("Ranging potion (1)-N");
	TextNR.push_back(175); TextTxt.push_back("Antipoison (3)");
	TextNR.push_back(176); TextTxt.push_back("Antipoison (3)-N");
	TextNR.push_back(177); TextTxt.push_back("Antipoison (2)");
	TextNR.push_back(178); TextTxt.push_back("Antipoison (2)-N");
	TextNR.push_back(179); TextTxt.push_back("Antipoison (1)");
	TextNR.push_back(180); TextTxt.push_back("Antipoison (1)-N");
	TextNR.push_back(181); TextTxt.push_back("Super antipoison (3)");
	TextNR.push_back(182); TextTxt.push_back("Super antipoison (3)-N");
	TextNR.push_back(183); TextTxt.push_back("Super antipoison (2)");
	TextNR.push_back(184); TextTxt.push_back("Super antipoison (2)-N");
	TextNR.push_back(185); TextTxt.push_back("Super antipoison (1)");
	TextNR.push_back(186); TextTxt.push_back("Super antipoison (1)-N");
	TextNR.push_back(187); TextTxt.push_back("Weapon poison");
	TextNR.push_back(188); TextTxt.push_back("Weapon poison-N");
	TextNR.push_back(189); TextTxt.push_back("Zamorak brew (3)");
	TextNR.push_back(190); TextTxt.push_back("Zamorak brew (3)-N");
	TextNR.push_back(191); TextTxt.push_back("Zamorak brew (2)");
	TextNR.push_back(192); TextTxt.push_back("Zamorak brew (2)-N");
	TextNR.push_back(193); TextTxt.push_back("Zamorak brew (1)");
	TextNR.push_back(194); TextTxt.push_back("Zamorak brew (1)-N");
	TextNR.push_back(195); TextTxt.push_back("Potion");
	TextNR.push_back(196); TextTxt.push_back("Potion-N");
	TextNR.push_back(197); TextTxt.push_back("Poison chalice");
	TextNR.push_back(198); TextTxt.push_back("Poison chalice-N");
	TextNR.push_back(199); TextTxt.push_back("Grimy guam");
	TextNR.push_back(200); TextTxt.push_back("Grimy guam-N");
	TextNR.push_back(201); TextTxt.push_back("Grimy marrentill");
	TextNR.push_back(202); TextTxt.push_back("Grimy marrentill-N");
	TextNR.push_back(203); TextTxt.push_back("Grimy tarromin");
	TextNR.push_back(204); TextTxt.push_back("Grimy tarromin-N");
	TextNR.push_back(205); TextTxt.push_back("Grimy harralander");
	TextNR.push_back(206); TextTxt.push_back("Grimy harralander-N");
	TextNR.push_back(207); TextTxt.push_back("Grimy ranarr");
	TextNR.push_back(208); TextTxt.push_back("Grimy ranarr-N");
	TextNR.push_back(209); TextTxt.push_back("Grimy irit");
	TextNR.push_back(210); TextTxt.push_back("Grimy irit-N");
	TextNR.push_back(211); TextTxt.push_back("Grimy avantoe");
	TextNR.push_back(212); TextTxt.push_back("Grimy avantoe-N");
	TextNR.push_back(213); TextTxt.push_back("Grimy kwuarm");
	TextNR.push_back(214); TextTxt.push_back("Grimy kwuarm-N");
	TextNR.push_back(215); TextTxt.push_back("Grimy cadantine");
	TextNR.push_back(216); TextTxt.push_back("Grimy cadantine-N");
	TextNR.push_back(217); TextTxt.push_back("Grimy dwarf weed");
	TextNR.push_back(218); TextTxt.push_back("Grimy dwarf weed-N");
	TextNR.push_back(219); TextTxt.push_back("Grimy torstol");
	TextNR.push_back(220); TextTxt.push_back("Grimy torstol-N");
	TextNR.push_back(221); TextTxt.push_back("Eye of newt");
	TextNR.push_back(222); TextTxt.push_back("Eye of newt-N");
	TextNR.push_back(223); TextTxt.push_back("Red spiders' eggs");
	TextNR.push_back(224); TextTxt.push_back("Red spiders' eggs-N");
	TextNR.push_back(225); TextTxt.push_back("Limpwurt root");
	TextNR.push_back(226); TextTxt.push_back("Limpwurt root-N");
	TextNR.push_back(227); TextTxt.push_back("Vial of water");
	TextNR.push_back(228); TextTxt.push_back("Vial of water-N");
	TextNR.push_back(229); TextTxt.push_back("Vial");
	TextNR.push_back(230); TextTxt.push_back("Vial-N");
	TextNR.push_back(231); TextTxt.push_back("Snape grass");
	TextNR.push_back(232); TextTxt.push_back("Snape grass-N");
	TextNR.push_back(233); TextTxt.push_back("Pestle and mortar");
	TextNR.push_back(234); TextTxt.push_back("Pestle and mortar-N");
	TextNR.push_back(235); TextTxt.push_back("Unicorn horn dust");
	TextNR.push_back(236); TextTxt.push_back("Unicorn horn dust-N");
	TextNR.push_back(237); TextTxt.push_back("Unicorn horn");
	TextNR.push_back(238); TextTxt.push_back("Unicorn horn-N");
	TextNR.push_back(239); TextTxt.push_back("White berries");
	TextNR.push_back(240); TextTxt.push_back("White berries-N");
	TextNR.push_back(241); TextTxt.push_back("Dragon scale dust");
	TextNR.push_back(242); TextTxt.push_back("Dragon scale dust-N");
	TextNR.push_back(243); TextTxt.push_back("Blue dragon scale");
	TextNR.push_back(244); TextTxt.push_back("Blue dragon scale-N");
	TextNR.push_back(245); TextTxt.push_back("Wine of zamorak");
	TextNR.push_back(246); TextTxt.push_back("Wine of zamorak-N");
	TextNR.push_back(247); TextTxt.push_back("Jangerberries");
	TextNR.push_back(248); TextTxt.push_back("Jangerberries-N");
	TextNR.push_back(249); TextTxt.push_back("Clean guam");
	TextNR.push_back(250); TextTxt.push_back("Clean guam-N");
	TextNR.push_back(251); TextTxt.push_back("Clean marrentill");
	TextNR.push_back(252); TextTxt.push_back("Clean marrentill-N");
	TextNR.push_back(253); TextTxt.push_back("Clean tarromin");
	TextNR.push_back(254); TextTxt.push_back("Clean tarromin-N");
	TextNR.push_back(255); TextTxt.push_back("Clean harralander");
	TextNR.push_back(256); TextTxt.push_back("Clean harralander-N");
	TextNR.push_back(257); TextTxt.push_back("Clean ranarr");
	TextNR.push_back(258); TextTxt.push_back("Clean ranarr-N");
	TextNR.push_back(259); TextTxt.push_back("Clean irit");
	TextNR.push_back(260); TextTxt.push_back("Clean irit-N");
	TextNR.push_back(261); TextTxt.push_back("Clean avantoe");
	TextNR.push_back(262); TextTxt.push_back("Clean avantoe-N");
	TextNR.push_back(263); TextTxt.push_back("Clean kwuarm");
	TextNR.push_back(264); TextTxt.push_back("Clean kwuarm-N");
	TextNR.push_back(265); TextTxt.push_back("Clean cadantine");
	TextNR.push_back(266); TextTxt.push_back("Clean cadantine-N");
	TextNR.push_back(267); TextTxt.push_back("Clean dwarf weed");
	TextNR.push_back(268); TextTxt.push_back("Clean dwarf weed-N");
	TextNR.push_back(269); TextTxt.push_back("Clean torstol");
	TextNR.push_back(270); TextTxt.push_back("Clean torstol-N");
	TextNR.push_back(371); TextTxt.push_back("Raw swordfish");
	TextNR.push_back(372); TextTxt.push_back("Raw swordfish-N");
	TextNR.push_back(373); TextTxt.push_back("Swordfish");
	TextNR.push_back(374); TextTxt.push_back("Swordfish-N");
	TextNR.push_back(377); TextTxt.push_back("Raw lobster");
	TextNR.push_back(378); TextTxt.push_back("Raw lobster-N");
	TextNR.push_back(379); TextTxt.push_back("Lobster");
	TextNR.push_back(380); TextTxt.push_back("Lobster-N");
	TextNR.push_back(383); TextTxt.push_back("Raw shark");
	TextNR.push_back(384); TextTxt.push_back("Raw shark-N");
	TextNR.push_back(385); TextTxt.push_back("Shark");
	TextNR.push_back(386); TextTxt.push_back("Shark-N");
	TextNR.push_back(389); TextTxt.push_back("Raw manta ray");
	TextNR.push_back(390); TextTxt.push_back("Raw manta ray-N");
	TextNR.push_back(391); TextTxt.push_back("Manta ray");
	TextNR.push_back(392); TextTxt.push_back("Manta ray-N");
	TextNR.push_back(395); TextTxt.push_back("Raw sea turtle");
	TextNR.push_back(396); TextTxt.push_back("Raw sea turtle-N");
	TextNR.push_back(397); TextTxt.push_back("Sea turtle");
	TextNR.push_back(398); TextTxt.push_back("Sea turtle-N");
	TextNR.push_back(405); TextTxt.push_back("Casket");
	TextNR.push_back(406); TextTxt.push_back("Casket-N");
	TextNR.push_back(434); TextTxt.push_back("Clay");
	TextNR.push_back(435); TextTxt.push_back("Clay-N");
	TextNR.push_back(436); TextTxt.push_back("Copper ore");
	TextNR.push_back(437); TextTxt.push_back("Copper ore-N");
	TextNR.push_back(438); TextTxt.push_back("Tin ore");
	TextNR.push_back(439); TextTxt.push_back("Tin ore-N");
	TextNR.push_back(440); TextTxt.push_back("Iron ore");
	TextNR.push_back(441); TextTxt.push_back("Iron ore-N");
	TextNR.push_back(442); TextTxt.push_back("Silver ore");
	TextNR.push_back(443); TextTxt.push_back("Silver ore-N");
	TextNR.push_back(444); TextTxt.push_back("Gold ore");
	TextNR.push_back(445); TextTxt.push_back("Gold ore-N");
	TextNR.push_back(447); TextTxt.push_back("Mithril ore");
	TextNR.push_back(448); TextTxt.push_back("Mithril ore-N");
	TextNR.push_back(449); TextTxt.push_back("Adamantite ore");
	TextNR.push_back(450); TextTxt.push_back("Adamantite ore-N");
	TextNR.push_back(451); TextTxt.push_back("Runite ore");
	TextNR.push_back(452); TextTxt.push_back("Runite ore-N");
	TextNR.push_back(453); TextTxt.push_back("Coal");
	TextNR.push_back(454); TextTxt.push_back("Coal-N");
	TextNR.push_back(532); TextTxt.push_back("Big bones");
	TextNR.push_back(533); TextTxt.push_back("Big bones-N");
	TextNR.push_back(534); TextTxt.push_back("Babydragon bones");
	TextNR.push_back(535); TextTxt.push_back("Babydragon bones-N");
	TextNR.push_back(536); TextTxt.push_back("Dragon bones");
	TextNR.push_back(537); TextTxt.push_back("Dragon bones-N");
	TextNR.push_back(554);TextTxt.push_back("Fire rune");
	TextNR.push_back(555); TextTxt.push_back("Water rune");
	TextNR.push_back(556); TextTxt.push_back("Air rune");
	TextNR.push_back(557); TextTxt.push_back("Earth rune");
	TextNR.push_back(558); TextTxt.push_back("Mind rune");
	TextNR.push_back(559); TextTxt.push_back("Body rune");
	TextNR.push_back(560); TextTxt.push_back("Death rune");
	TextNR.push_back(561); TextTxt.push_back("Nature rune");
	TextNR.push_back(562); TextTxt.push_back("Chaos rune");
	TextNR.push_back(563); TextTxt.push_back("Law rune");
	TextNR.push_back(564); TextTxt.push_back("Cosmic rune");
	TextNR.push_back(565); TextTxt.push_back("Blood rune");
	TextNR.push_back(566); TextTxt.push_back("Soul rune");
	TextNR.push_back(960); TextTxt.push_back("Plank");
	TextNR.push_back(961); TextTxt.push_back("Plank-N");
	TextNR.push_back(962); TextTxt.push_back("Christmas cracker");
	TextNR.push_back(963); TextTxt.push_back("Christmas cracker-N");
	TextNR.push_back(981); TextTxt.push_back("Disk of returning");
	TextNR.push_back(982); TextTxt.push_back("Disk of returning-N");
	TextNR.push_back(983); TextTxt.push_back("Brass key");
	TextNR.push_back(984); TextTxt.push_back("Brass key-N");
	TextNR.push_back(985); TextTxt.push_back("Tooth half of a key");
	TextNR.push_back(986); TextTxt.push_back("Tooth half of a key-N");
	TextNR.push_back(987); TextTxt.push_back("Loop half of a key");
	TextNR.push_back(988); TextTxt.push_back("Loop half of a key-N");
	TextNR.push_back(989); TextTxt.push_back("Crystal key");
	TextNR.push_back(990); TextTxt.push_back("Crystal key-N");
	TextNR.push_back(991); TextTxt.push_back("Muddy key");
	TextNR.push_back(992); TextTxt.push_back("Muddy key-N");
	TextNR.push_back(993); TextTxt.push_back("Sinister key");
	TextNR.push_back(994); TextTxt.push_back("Sinister key-N");
	TextNR.push_back(995); TextTxt.push_back("Coins");
	TextNR.push_back(1123); TextTxt.push_back("Adamant platebody");
	TextNR.push_back(1124); TextTxt.push_back("Adamant platebody-N");
	TextNR.push_back(1127); TextTxt.push_back("Rune platebody");
	TextNR.push_back(1128); TextTxt.push_back("Rune platebody-N");
	TextNR.push_back(1150); TextTxt.push_back("Dragon med"); 
	TextNR.push_back(1151); TextTxt.push_back("Dragon med-N");
	TextNR.push_back(1249); TextTxt.push_back("Dragon spear");
	TextNR.push_back(1250); TextTxt.push_back("Dragon spear-N");
	TextNR.push_back(1305); TextTxt.push_back("Dragon longsword");
	TextNR.push_back(1306); TextTxt.push_back("Dragon longsword-N");
	TextNR.push_back(1373); TextTxt.push_back("Rune battleaxe");
	TextNR.push_back(1374); TextTxt.push_back("Rune battleaxe-N");
	TextNR.push_back(1379); TextTxt.push_back("Staff");
	TextNR.push_back(1380); TextTxt.push_back("Staff-N");
	TextNR.push_back(1391); TextTxt.push_back("Battlestaff");
	TextNR.push_back(1392); TextTxt.push_back("Battlestaff-N");
	TextNR.push_back(1434); TextTxt.push_back("Dragon mace");
	TextNR.push_back(1435); TextTxt.push_back("Dragon mace-N");
	TextNR.push_back(1438); TextTxt.push_back("Air talisman");
	TextNR.push_back(1439); TextTxt.push_back("Air talisman-N");
	TextNR.push_back(1440); TextTxt.push_back("Earth talisman");
	TextNR.push_back(1441); TextTxt.push_back("Earth talisman-N");
	TextNR.push_back(1442); TextTxt.push_back("Fire talisman");
	TextNR.push_back(1443); TextTxt.push_back("Fire talisman-N");
	TextNR.push_back(1444); TextTxt.push_back("Water talisman");
	TextNR.push_back(1445); TextTxt.push_back("Water talisman-N");
	TextNR.push_back(1446); TextTxt.push_back("Body talisman");
	TextNR.push_back(1447); TextTxt.push_back("Body talisman-N");
	TextNR.push_back(1448); TextTxt.push_back("Mind talisman");
	TextNR.push_back(1449); TextTxt.push_back("Mind talisman-N");
	TextNR.push_back(1450); TextTxt.push_back("Blood talisman");
	TextNR.push_back(1451); TextTxt.push_back("Blood talisman-N");
	TextNR.push_back(1452); TextTxt.push_back("Chaos talisman");
	TextNR.push_back(1453); TextTxt.push_back("Chaos talisman-N");
	TextNR.push_back(1454); TextTxt.push_back("Cosmic talisman");
	TextNR.push_back(1455); TextTxt.push_back("Cosmic talisman-N");
	TextNR.push_back(1456); TextTxt.push_back("Death talisman");
	TextNR.push_back(1457); TextTxt.push_back("Death talisman-N");
	TextNR.push_back(1458); TextTxt.push_back("Law talisman");
	TextNR.push_back(1459); TextTxt.push_back("Law talisman-N");
	TextNR.push_back(1460); TextTxt.push_back("Soul talisman");
	TextNR.push_back(1461); TextTxt.push_back("Soul talisman-N");
	TextNR.push_back(1462); TextTxt.push_back("Nature talisman");
	TextNR.push_back(1463); TextTxt.push_back("Nature talisman-N");
	TextNR.push_back(1511); TextTxt.push_back("Logs");
	TextNR.push_back(1512); TextTxt.push_back("Logs-N");
	TextNR.push_back(1513); TextTxt.push_back("Magic logs");
	TextNR.push_back(1514); TextTxt.push_back("Magic logs-N");
	TextNR.push_back(1515); TextTxt.push_back("Yew logs");
	TextNR.push_back(1516); TextTxt.push_back("Yew logs-N");
	TextNR.push_back(1517); TextTxt.push_back("Maple logs");
	TextNR.push_back(1518); TextTxt.push_back("Maple logs-N");
	TextNR.push_back(1519); TextTxt.push_back("Willow logs");
	TextNR.push_back(1520); TextTxt.push_back("Willow logs-N");
	TextNR.push_back(1521); TextTxt.push_back("Oak logs");
	TextNR.push_back(1522); TextTxt.push_back("Oak logs-N");
	TextNR.push_back(1523); TextTxt.push_back("Lockpick");
	TextNR.push_back(1524); TextTxt.push_back("Lockpick-N");
	TextNR.push_back(1601); TextTxt.push_back("Diamond");
	TextNR.push_back(1602); TextTxt.push_back("Diamond-N");
	TextNR.push_back(1603); TextTxt.push_back("Ruby");
	TextNR.push_back(1604); TextTxt.push_back("Ruby-N");
	TextNR.push_back(1605); TextTxt.push_back("Emerald");
	TextNR.push_back(1606); TextTxt.push_back("Emerald-N");
	TextNR.push_back(1607); TextTxt.push_back("Sapphire");
	TextNR.push_back(1608); TextTxt.push_back("Sapphire-N");
	TextNR.push_back(1609); TextTxt.push_back("Opal");
	TextNR.push_back(1610); TextTxt.push_back("Opal-N");
	TextNR.push_back(1611); TextTxt.push_back("Jade");
	TextNR.push_back(1612); TextTxt.push_back("Jade-N");
	TextNR.push_back(1613); TextTxt.push_back("Red topaz");
	TextNR.push_back(1614); TextTxt.push_back("Red topaz-N");
	TextNR.push_back(1615); TextTxt.push_back("Dragonstone");
	TextNR.push_back(1616); TextTxt.push_back("Dragonstone-N");
	TextNR.push_back(1617); TextTxt.push_back("Uncut Diamond");
	TextNR.push_back(1618); TextTxt.push_back("Uncut Diamond-N");
	TextNR.push_back(1619); TextTxt.push_back("Uncut ruby");
	TextNR.push_back(1620); TextTxt.push_back("Uncut ruby-N");
	TextNR.push_back(1621); TextTxt.push_back("Uncut emerald");
	TextNR.push_back(1622); TextTxt.push_back("Uncut emerald-N");
	TextNR.push_back(1623); TextTxt.push_back("Uncut sapphire");
	TextNR.push_back(1624); TextTxt.push_back("Uncut sapphire-N");
	TextNR.push_back(1625); TextTxt.push_back("Uncut opal");
	TextNR.push_back(1626); TextTxt.push_back("Uncut opal-N");
	TextNR.push_back(1627); TextTxt.push_back("Uncut jade");
	TextNR.push_back(1628); TextTxt.push_back("Uncut jade-N");
	TextNR.push_back(1629); TextTxt.push_back("Uncut red topaz");
	TextNR.push_back(1630); TextTxt.push_back("Uncut red topaz-N");
	TextNR.push_back(1631); TextTxt.push_back("Uncut dragonstone");
	TextNR.push_back(1632); TextTxt.push_back("Uncut dragonstone-N");
	TextNR.push_back(1633); TextTxt.push_back("Crushed gem");
	TextNR.push_back(1634); TextTxt.push_back("Crushed gem-N");
	TextNR.push_back(1635); TextTxt.push_back("Gold ring");
	TextNR.push_back(1636); TextTxt.push_back("Gold ring-N");
	TextNR.push_back(1637); TextTxt.push_back("Sapphire ring");
	TextNR.push_back(1638); TextTxt.push_back("Sapphire ring-N");
	TextNR.push_back(1639); TextTxt.push_back("Emerald ring");
	TextNR.push_back(1640); TextTxt.push_back("Emerald ring-n");
	TextNR.push_back(1641); TextTxt.push_back("Ruby ring");
	TextNR.push_back(1642); TextTxt.push_back("Ruby ring-N");
	TextNR.push_back(1643); TextTxt.push_back("Diamond ring");
	TextNR.push_back(1644); TextTxt.push_back("Diamond ring-N");
	TextNR.push_back(1645); TextTxt.push_back("Dragonstone ring");
	TextNR.push_back(1646); TextTxt.push_back("Dragonstone ring-N");
	TextNR.push_back(1647); TextTxt.push_back("ZERO");
	TextNR.push_back(1648); TextTxt.push_back("ZERO");
	TextNR.push_back(1649); TextTxt.push_back("Sapphire ring");
	TextNR.push_back(1650); TextTxt.push_back("Emerald ring");
	TextNR.push_back(1651); TextTxt.push_back("Ruby ring");
	TextNR.push_back(1652); TextTxt.push_back("Diamond ring");
	TextNR.push_back(1653); TextTxt.push_back("Dragonstone ring");
	TextNR.push_back(1654); TextTxt.push_back("Gold necklace");
	TextNR.push_back(1655); TextTxt.push_back("Gold necklace-N");
	TextNR.push_back(1656); TextTxt.push_back("Sapphire necklace");
	TextNR.push_back(1657); TextTxt.push_back("Sapphire necklace-N");
	TextNR.push_back(1658); TextTxt.push_back("Emerald necklace");
	TextNR.push_back(1659); TextTxt.push_back("Emerald necklace-N");
	TextNR.push_back(1660); TextTxt.push_back("Ruby necklace");
	TextNR.push_back(1661); TextTxt.push_back("Ruby necklace-N");
	TextNR.push_back(1662); TextTxt.push_back("Diamond necklace");
	TextNR.push_back(1663); TextTxt.push_back("Diamond necklace-N");
	TextNR.push_back(1664); TextTxt.push_back("Dragon necklace");
	TextNR.push_back(1665); TextTxt.push_back("Dragon necklace-N");
	TextNR.push_back(1666); TextTxt.push_back("ZERO");
	TextNR.push_back(1667); TextTxt.push_back("ZERO");
	TextNR.push_back(1668); TextTxt.push_back("Sapphire necklace");
	TextNR.push_back(1669); TextTxt.push_back("Emerald necklace");
	TextNR.push_back(1670); TextTxt.push_back("Ruby necklace");
	TextNR.push_back(1671); TextTxt.push_back("Diamond necklace");
	TextNR.push_back(1672); TextTxt.push_back("Dragon necklace");
	TextNR.push_back(1673); TextTxt.push_back("Gold amulet");
	TextNR.push_back(1674); TextTxt.push_back("Gold amulet-N");
	TextNR.push_back(1675); TextTxt.push_back("Sapphire amulet");
	TextNR.push_back(1676); TextTxt.push_back("Sapphire amulet-N");
	TextNR.push_back(1677); TextTxt.push_back("Emerald amulet");
	TextNR.push_back(1678); TextTxt.push_back("Emerald amulet-N");
	TextNR.push_back(1679); TextTxt.push_back("Ruby amulet");
	TextNR.push_back(1680); TextTxt.push_back("Ruby amulet-N");
	TextNR.push_back(1681); TextTxt.push_back("Diamond amulet");
	TextNR.push_back(1682); TextTxt.push_back("Diamond amulet-N");
	TextNR.push_back(1683); TextTxt.push_back("Dragonstone ammy");
	TextNR.push_back(1684); TextTxt.push_back("Dragonstone ammy-N");
	TextNR.push_back(1685); TextTxt.push_back("ZERO");
	TextNR.push_back(1686); TextTxt.push_back("ZERO");
	TextNR.push_back(1687); TextTxt.push_back("Sapphire amulet");
	TextNR.push_back(1688); TextTxt.push_back("Emerald amulet");
	TextNR.push_back(1689); TextTxt.push_back("Ruby amulet");
	TextNR.push_back(1690); TextTxt.push_back("Diamond amulet");
	TextNR.push_back(1691); TextTxt.push_back("Dragonstone ammy");
	TextNR.push_back(1692); TextTxt.push_back("Gold amulet");
	TextNR.push_back(1693); TextTxt.push_back("Gold amulet-N");
	TextNR.push_back(1694); TextTxt.push_back("Sapphire amulet");
	TextNR.push_back(1695); TextTxt.push_back("Sapphire amulet-N");
	TextNR.push_back(1696); TextTxt.push_back("Emerald amulet");
	TextNR.push_back(1697); TextTxt.push_back("Emerald amulet-N");
	TextNR.push_back(1698); TextTxt.push_back("Ruby amulet");
	TextNR.push_back(1699); TextTxt.push_back("Ruby amulet-N");
	TextNR.push_back(1700); TextTxt.push_back("Diamond amulet");
	TextNR.push_back(1701); TextTxt.push_back("Diamond amulet-N");
	TextNR.push_back(1702); TextTxt.push_back("Dragonstone ammy");
	TextNR.push_back(1703); TextTxt.push_back("Dragonstone ammy-N");
	TextNR.push_back(1704); TextTxt.push_back("Amulet of glory");
	TextNR.push_back(1705); TextTxt.push_back("Amulet of glory-N");
	TextNR.push_back(1706); TextTxt.push_back("Amulet of glory (1)");
	TextNR.push_back(1707); TextTxt.push_back("Amulet of glory (1)-N");
	TextNR.push_back(1708); TextTxt.push_back("Amulet of glory (2)");
	TextNR.push_back(1709); TextTxt.push_back("Amulet of glory (2)-N");
	TextNR.push_back(1710); TextTxt.push_back("Amulet of glory (3)");
	TextNR.push_back(1711); TextTxt.push_back("Amulet of glory (3)-N");
	TextNR.push_back(1712); TextTxt.push_back("Amulet of glory (4)");
	TextNR.push_back(1713); TextTxt.push_back("Amulet of glory (4)-N");
	TextNR.push_back(1714); TextTxt.push_back("Unstrung symbol");
	TextNR.push_back(1715); TextTxt.push_back("Unstrung symbol-N");
	TextNR.push_back(1716); TextTxt.push_back("Unblessed symbol");
	TextNR.push_back(1717); TextTxt.push_back("Unblessed symbol-N");
	TextNR.push_back(1718); TextTxt.push_back("Holy symbol");
	TextNR.push_back(1719); TextTxt.push_back("Holy symbol-N");
	TextNR.push_back(1720); TextTxt.push_back("Unstrung emblem");
	TextNR.push_back(1721); TextTxt.push_back("Unstrung emblem-N");
	TextNR.push_back(1722); TextTxt.push_back("Unpowered symbol");
	TextNR.push_back(1723); TextTxt.push_back("Unpowered symbol-N");
	TextNR.push_back(1724); TextTxt.push_back("Unholy symbol");
	TextNR.push_back(1725); TextTxt.push_back("Amulet of strength");
	TextNR.push_back(1726); TextTxt.push_back("Amulet of strength-N");
	TextNR.push_back(1727); TextTxt.push_back("Amulet of magic");
	TextNR.push_back(1728); TextTxt.push_back("Amulet of magic-N");
	TextNR.push_back(1729); TextTxt.push_back("Amulet of defence");
	TextNR.push_back(1730); TextTxt.push_back("Amulet of defence-N");
	TextNR.push_back(1731); TextTxt.push_back("Amulet of power");
	TextNR.push_back(1732); TextTxt.push_back("Amulet of power-N");
	TextNR.push_back(1733); TextTxt.push_back("Needle");
	TextNR.push_back(1734); TextTxt.push_back("Thread");
	TextNR.push_back(1735); TextTxt.push_back("Shears");
	TextNR.push_back(1736); TextTxt.push_back("Shears-N");
	TextNR.push_back(1737); TextTxt.push_back("Wool");
	TextNR.push_back(1738); TextTxt.push_back("Wool-N");
	TextNR.push_back(1739); TextTxt.push_back("Cowhide");
	TextNR.push_back(1740); TextTxt.push_back("Cowhide-N");
	TextNR.push_back(1741); TextTxt.push_back("Leather");
	TextNR.push_back(1742); TextTxt.push_back("Leather-N");
	TextNR.push_back(1743); TextTxt.push_back("Hard leather");
	TextNR.push_back(1744); TextTxt.push_back("Hard leather-N");
	TextNR.push_back(1745); TextTxt.push_back("Green dragon leather");
	TextNR.push_back(1746); TextTxt.push_back("Green dragon leather-N");
	TextNR.push_back(1747); TextTxt.push_back("Black dragonhide");
	TextNR.push_back(1748); TextTxt.push_back("Black dragonhide-N");
	TextNR.push_back(1749); TextTxt.push_back("Red dragonhide");
	TextNR.push_back(1750); TextTxt.push_back("Red dragonhide-N");
	TextNR.push_back(1751); TextTxt.push_back("Blue dragonhide");
	TextNR.push_back(1752); TextTxt.push_back("Blue dragonhide-N");
	TextNR.push_back(1753); TextTxt.push_back("Green dragonhide");
	TextNR.push_back(1754); TextTxt.push_back("Green dragonhide-N");
	TextNR.push_back(1761); TextTxt.push_back("Soft clay");
	TextNR.push_back(1762); TextTxt.push_back("Soft clay-N");
	TextNR.push_back(1775); TextTxt.push_back("Molten glass");
	TextNR.push_back(1776); TextTxt.push_back("Molten glass-N");
	TextNR.push_back(1777); TextTxt.push_back("Bow string");
	TextNR.push_back(1778); TextTxt.push_back("Bow string-N");
	TextNR.push_back(1779); TextTxt.push_back("Flax");
	TextNR.push_back(1780); TextTxt.push_back("Flax-N");
	TextNR.push_back(1780); TextTxt.push_back("Flax-N");
	TextNR.push_back(1939); TextTxt.push_back("Swamp tar-N");
	//TextNR.push_back(2349); TextTxt.push_back("Bronze bar");
	TextNR.push_back(2350); TextTxt.push_back("Bronze bar-N");
	//TextNR.push_back(2351); TextTxt.push_back("Iron bar");
	TextNR.push_back(2352); TextTxt.push_back("Iron bar-N");
	//TextNR.push_back(2353); TextTxt.push_back("Steel bar");
	TextNR.push_back(2354); TextTxt.push_back("Steel bar-N");
	//TextNR.push_back(2355); TextTxt.push_back("Silver bar");
	TextNR.push_back(2356); TextTxt.push_back("Silver bar-N");
	//TextNR.push_back(2357); TextTxt.push_back("Gold bar");
	TextNR.push_back(2358); TextTxt.push_back("Gold bar-N");
	//TextNR.push_back(2359); TextTxt.push_back("Mithril bar");
	TextNR.push_back(2360); TextTxt.push_back("Mithril bar-N");
	TextNR.push_back(2361); TextTxt.push_back("Adamant bar");
	TextNR.push_back(2362); TextTxt.push_back("Adamant bar-N");
	TextNR.push_back(2363); TextTxt.push_back("Rune bar");
	TextNR.push_back(2364); TextTxt.push_back("Rune bar-N");
	TextNR.push_back(2366); TextTxt.push_back("Shield left half");
	TextNR.push_back(2367); TextTxt.push_back("Shield left half-N");
	TextNR.push_back(2428); TextTxt.push_back("Attack potion (4)");
	TextNR.push_back(2429); TextTxt.push_back("Attack potion (4)-N");
	TextNR.push_back(2430); TextTxt.push_back("Restore potion (4)");
	TextNR.push_back(2431); TextTxt.push_back("Restore potion (4)-N");
	TextNR.push_back(2432); TextTxt.push_back("Defence potion (4)");
	TextNR.push_back(2433); TextTxt.push_back("Defence potion (4)-N");
	TextNR.push_back(2434); TextTxt.push_back("Prayer potion (4)");
	TextNR.push_back(2435); TextTxt.push_back("Prayer potion (4)-N");
	TextNR.push_back(2436); TextTxt.push_back("Super attack (4)");
	TextNR.push_back(2437); TextTxt.push_back("Super attack (4)-N");
	TextNR.push_back(2438); TextTxt.push_back("Fishing potion (4)");
	TextNR.push_back(2439); TextTxt.push_back("Fishing potion (4)-N");
	TextNR.push_back(2440); TextTxt.push_back("Super strength (4)");
	TextNR.push_back(2441); TextTxt.push_back("Super strength (4)-N");
	TextNR.push_back(2442); TextTxt.push_back("Super defence (4)");
	TextNR.push_back(2443); TextTxt.push_back("Super defence (4)-N");
	TextNR.push_back(2444); TextTxt.push_back("Ranging potion (4)");
	TextNR.push_back(2445); TextTxt.push_back("Ranging potion (4)-N");
	TextNR.push_back(2446); TextTxt.push_back("Antipoison (4)");
	TextNR.push_back(2447); TextTxt.push_back("Antipoison (4)-N");
	TextNR.push_back(2448); TextTxt.push_back("Super antipoison (4)");
	TextNR.push_back(2449); TextTxt.push_back("Super antipoison (4)-N");
	TextNR.push_back(2450); TextTxt.push_back("Zamorak brew (4)");
	TextNR.push_back(2451); TextTxt.push_back("Zamorak brew (4)-N");
	TextNR.push_back(2452); TextTxt.push_back("Antifire (4)");
	TextNR.push_back(2453); TextTxt.push_back("Antifire (4)-N");
	TextNR.push_back(2454); TextTxt.push_back("Antifire (3)");
	TextNR.push_back(2455); TextTxt.push_back("Antifire (3)-N");
	TextNR.push_back(2456); TextTxt.push_back("Antifire (2)");
	TextNR.push_back(2457); TextTxt.push_back("Antifire (2)-N");
	TextNR.push_back(2458); TextTxt.push_back("Antifire (1)");
	TextNR.push_back(2459); TextTxt.push_back("Antifire (1)-N");
	TextNR.push_back(2481); TextTxt.push_back("Clean lantadyme");
	TextNR.push_back(2482); TextTxt.push_back("Clean lantadyme-N");
	TextNR.push_back(2485); TextTxt.push_back("Grimy lantadyme");
	TextNR.push_back(2486); TextTxt.push_back("Grimy lantadyme-N");
	TextNR.push_back(2998); TextTxt.push_back("Clean toadflax");
	TextNR.push_back(2999); TextTxt.push_back("Clean toadflax-N");
	TextNR.push_back(3000); TextTxt.push_back("Clean snapdragon");
	TextNR.push_back(3001); TextTxt.push_back("Clean snapdragon-N");
	TextNR.push_back(3008); TextTxt.push_back("Energy potion (4)");
	TextNR.push_back(3009); TextTxt.push_back("Energy potion (4)-N");
	TextNR.push_back(3010); TextTxt.push_back("Energy potion (3)");
	TextNR.push_back(3011); TextTxt.push_back("Energy potion (3)-N");
	TextNR.push_back(3012); TextTxt.push_back("Energy potion (2)");
	TextNR.push_back(3013); TextTxt.push_back("Energy potion (2)-N");
	TextNR.push_back(3014); TextTxt.push_back("Energy potion (1)");
	TextNR.push_back(3015); TextTxt.push_back("Energy potion (1)-N");
	TextNR.push_back(3016); TextTxt.push_back("Super energy (4)");
	TextNR.push_back(3017); TextTxt.push_back("Super energy (4)-N");
	TextNR.push_back(3018); TextTxt.push_back("Super energy (3)");
	TextNR.push_back(3019); TextTxt.push_back("Super energy (3)-N");
	TextNR.push_back(3020); TextTxt.push_back("Super energy (2)");
	TextNR.push_back(3021); TextTxt.push_back("Super energy (2)-N");
	TextNR.push_back(3022); TextTxt.push_back("Super energy (1)");
	TextNR.push_back(3023); TextTxt.push_back("Super energy (1)-N");
	TextNR.push_back(3024); TextTxt.push_back("Super restore (4)");
	TextNR.push_back(3025); TextTxt.push_back("Super restore (4)-N");
	TextNR.push_back(3026); TextTxt.push_back("Super restore (3)");
	TextNR.push_back(3027); TextTxt.push_back("Super restore (3)-N");
	TextNR.push_back(3028); TextTxt.push_back("Super restore (2)");
	TextNR.push_back(3029); TextTxt.push_back("Super restore (2)-N");
	TextNR.push_back(3030); TextTxt.push_back("Super restore (1)");
	TextNR.push_back(3031); TextTxt.push_back("Super restore (1)-N");
	TextNR.push_back(3032); TextTxt.push_back("Agility potion (4)");
	TextNR.push_back(3033); TextTxt.push_back("Agility potion (4)-N");
	TextNR.push_back(3034); TextTxt.push_back("Agility potion (3)");
	TextNR.push_back(3035); TextTxt.push_back("Agility potion (3)-N");
	TextNR.push_back(3036); TextTxt.push_back("Agility potion (2)");
	TextNR.push_back(3037); TextTxt.push_back("Agility potion (2)-N");
	TextNR.push_back(3038); TextTxt.push_back("Agility potion (1)");
	TextNR.push_back(3039); TextTxt.push_back("Agility potion (1)-N");
	TextNR.push_back(3040); TextTxt.push_back("Magic potion (4)");
	TextNR.push_back(3041); TextTxt.push_back("Magic potion (4)-N");
	TextNR.push_back(3042); TextTxt.push_back("Magic potion (3)");
	TextNR.push_back(3043); TextTxt.push_back("Magic potion (3)-N");
	TextNR.push_back(3044); TextTxt.push_back("Magic potion (2)");
	TextNR.push_back(3045); TextTxt.push_back("Magic potion (2)-N");
	TextNR.push_back(3046); TextTxt.push_back("Magic potion (1)");
	TextNR.push_back(3047); TextTxt.push_back("Magic potion (1)-N");
	TextNR.push_back(3049); TextTxt.push_back("Grimy toadflax");
	TextNR.push_back(3050); TextTxt.push_back("Grimy toadflax-N");
	TextNR.push_back(3051); TextTxt.push_back("Grimy snapdragon");
	TextNR.push_back(3052); TextTxt.push_back("Grimy snapdragon-N");
	TextNR.push_back(3053); TextTxt.push_back("Lava battlestaff");
	TextNR.push_back(3054); TextTxt.push_back("Mystic lava staff");
	TextNR.push_back(3055); TextTxt.push_back("Lava battlestaff-N");
	TextNR.push_back(3056); TextTxt.push_back("Mystic lava staff-N");
	TextNR.push_back(3138); TextTxt.push_back("Potato cactus");
	TextNR.push_back(3139); TextTxt.push_back("Potato cactus-N");
	TextNR.push_back(3260); TextTxt.push_back("Manifest shadow core");
	TextNR.push_back(3261); TextTxt.push_back("Manifest shadow core-N");
	TextNR.push_back(4151); TextTxt.push_back("Abyssal whip");
	TextNR.push_back(4152); TextTxt.push_back("Abyssal whip-N");
	TextNR.push_back(5070); TextTxt.push_back("Bird's nest");
	TextNR.push_back(5071); TextTxt.push_back("Bird's nest");
	TextNR.push_back(5072); TextTxt.push_back("Bird's nest");
	TextNR.push_back(5073); TextTxt.push_back("Bird's nest");
	TextNR.push_back(5074); TextTxt.push_back("Bird's nest");
	TextNR.push_back(5075); TextTxt.push_back("Bird's nest");
	TextNR.push_back(5280); TextTxt.push_back("Cactus seed");
	TextNR.push_back(5281); TextTxt.push_back("Belladonna seed");
	TextNR.push_back(5282); TextTxt.push_back("Mushroom spore");
	TextNR.push_back(5283); TextTxt.push_back("Apple tree seed");
	TextNR.push_back(5284); TextTxt.push_back("Banana tree seed");
	TextNR.push_back(5285); TextTxt.push_back("Orange tree seed");
	TextNR.push_back(5286); TextTxt.push_back("Curry tree seed");
	TextNR.push_back(5287); TextTxt.push_back("Pineapple tree seed");
	TextNR.push_back(5288); TextTxt.push_back("Papaya tree seed");
	TextNR.push_back(5289); TextTxt.push_back("Palm tree seed");
	TextNR.push_back(5290); TextTxt.push_back("Calquat tree seed");
	TextNR.push_back(5291); TextTxt.push_back("Guam seed");
	TextNR.push_back(5292); TextTxt.push_back("Marrentill seed");
	TextNR.push_back(5293); TextTxt.push_back("Tarromin seed");
	TextNR.push_back(5294); TextTxt.push_back("Harralander seed");
	TextNR.push_back(5295); TextTxt.push_back("Ranarr seed");
	TextNR.push_back(5296); TextTxt.push_back("Toadflax seed");
	TextNR.push_back(5297); TextTxt.push_back("Irit seed");
	TextNR.push_back(5298); TextTxt.push_back("Avantoe seed");
	TextNR.push_back(5299); TextTxt.push_back("Kwuarm seed");
	TextNR.push_back(5300); TextTxt.push_back("Snapdragon seed");
	TextNR.push_back(5301); TextTxt.push_back("Cadantine seed");
	TextNR.push_back(5302); TextTxt.push_back("Lantadyme seed");
	TextNR.push_back(5303); TextTxt.push_back("Dwarf weed seed");
	TextNR.push_back(5304); TextTxt.push_back("Torstol seed");
	TextNR.push_back(5312); TextTxt.push_back("Acorn");
	TextNR.push_back(5313); TextTxt.push_back("Willow seed");
	TextNR.push_back(5314); TextTxt.push_back("Maple seed");
	TextNR.push_back(5315); TextTxt.push_back("Yew seed");
	TextNR.push_back(5316); TextTxt.push_back("Magic seed");
	TextNR.push_back(5317); TextTxt.push_back("Spirit seed");
	TextNR.push_back(5321); TextTxt.push_back("Watermelon seed");
	TextNR.push_back(6034); TextTxt.push_back("Supercompost");
	TextNR.push_back(6035); TextTxt.push_back("Supercompost-N");
	TextNR.push_back(6155); TextTxt.push_back("Dagannoth hide");
	TextNR.push_back(6156); TextTxt.push_back("Dagannoth hide-N");
	TextNR.push_back(6562); TextTxt.push_back("Mud battlestaff");
	TextNR.push_back(6571); TextTxt.push_back("Uncut onyx");
	TextNR.push_back(6572); TextTxt.push_back("Uncut onyx-N");
	TextNR.push_back(6573); TextTxt.push_back("Onyx");
	TextNR.push_back(6574); TextTxt.push_back("Onyx-N");
	TextNR.push_back(6685); TextTxt.push_back("Saradomin brew (4)");
	TextNR.push_back(6686); TextTxt.push_back("Saradomin brew (4)-N");
	TextNR.push_back(6687); TextTxt.push_back("Saradomin brew (3)");
	TextNR.push_back(6688); TextTxt.push_back("Saradomin brew (3)-N");
	TextNR.push_back(6689); TextTxt.push_back("Saradomin brew (2)");
	TextNR.push_back(6690); TextTxt.push_back("Saradomin brew (2)-N");
	TextNR.push_back(6691); TextTxt.push_back("Saradomin brew (1)");
	TextNR.push_back(6692); TextTxt.push_back("Saradomin brew (1)-N");
	TextNR.push_back(6693); TextTxt.push_back("Crushed nest");
	TextNR.push_back(6694); TextTxt.push_back("Crushed nest-N");
	TextNR.push_back(6724); TextTxt.push_back("Seercull");
	TextNR.push_back(6725); TextTxt.push_back("Seercull-N");
	TextNR.push_back(6726); TextTxt.push_back("Mud battlestadd-N");
	TextNR.push_back(6729); TextTxt.push_back("Dagannoth bones");
	TextNR.push_back(6730); TextTxt.push_back("Dagannoth bones-N");
	TextNR.push_back(6731); TextTxt.push_back("Seers' ring");
	TextNR.push_back(6732); TextTxt.push_back("Seers' ring-N");
	TextNR.push_back(6733); TextTxt.push_back("Archers' ring");
	TextNR.push_back(6734); TextTxt.push_back("Archers' ring-N");
	TextNR.push_back(6735); TextTxt.push_back("Warriors' ring");
	TextNR.push_back(6736); TextTxt.push_back("Warriors' ring-N");
	TextNR.push_back(6737); TextTxt.push_back("Berserkers' ring");
	TextNR.push_back(6738); TextTxt.push_back("Berserkers' ring-N");
	TextNR.push_back(6739); TextTxt.push_back("Dragon hatchet");
	TextNR.push_back(6740); TextTxt.push_back("Dragon hatchet-N");
	TextNR.push_back(7413); TextTxt.push_back("Bird's nest");
	TextNR.push_back(8778); TextTxt.push_back("Oak plank");
	TextNR.push_back(8779); TextTxt.push_back("Oak plank-N");
	TextNR.push_back(8780); TextTxt.push_back("Teak plank");
	TextNR.push_back(8781); TextTxt.push_back("Teak plank-N");
	TextNR.push_back(8782); TextTxt.push_back("Mahogany plank");
	TextNR.push_back(8783); TextTxt.push_back("Mahogany plank-N");
	TextNR.push_back(8836); TextTxt.push_back("Mahogany logs-N");
	TextNR.push_back(9185); TextTxt.push_back("Rune crossbow");
	TextNR.push_back(9186); TextTxt.push_back("Rune crossbow-N");
	TextNR.push_back(9193); TextTxt.push_back("Dragon bolt tips-N");
	TextNR.push_back(9194); TextTxt.push_back("Onyx bolt tips-N");
	TextNR.push_back(9342); TextTxt.push_back("Onyx bolts-N");
	TextNR.push_back(11286); TextTxt.push_back("Draconic visage");
	TextNR.push_back(11287); TextTxt.push_back("Dragonic visage-N");
	TextNR.push_back(11966); TextTxt.push_back("Bird's nest");
	TextNR.push_back(12172); TextTxt.push_back("Grimy spirit weed");
	TextNR.push_back(12173); TextTxt.push_back("Grimy spirit weed-N");
	TextNR.push_back(12174); TextTxt.push_back("Grimy spirit weed");
	TextNR.push_back(12175); TextTxt.push_back("Grimy spirit weed-N");
	TextNR.push_back(12539); TextTxt.push_back("Grenwall spikes-N");
	TextNR.push_back(14497); TextTxt.push_back("Dagon'hai robe top");
	TextNR.push_back(14499); TextTxt.push_back("Dagon'hai hat");
	TextNR.push_back(14501); TextTxt.push_back("Dagon'hai robe bottom");
	TextNR.push_back(14870); TextTxt.push_back("Wergali seed");
	TextNR.push_back(15486); TextTxt.push_back("Staff of light");
	TextNR.push_back(15487); TextTxt.push_back("Staff of light-N");
	TextNR.push_back(15488); TextTxt.push_back("Hexcrest");
	TextNR.push_back(15489); TextTxt.push_back("Hexcrestt-N");
	TextNR.push_back(15490); TextTxt.push_back("Focus sight");
	TextNR.push_back(15491); TextTxt.push_back("Focus sight-N");
	TextNR.push_back(18202); TextTxt.push_back("Orange triangle key");    Dungvarp.push_back(1812);
	TextNR.push_back(18204); TextTxt.push_back("Orange diamond key");     Dungvarp.push_back(1813);
	TextNR.push_back(18206); TextTxt.push_back("Orange rectangle key");   Dungvarp.push_back(1814);
	TextNR.push_back(18208); TextTxt.push_back("Orange pentagon key");    Dungvarp.push_back(1815);
	TextNR.push_back(18210); TextTxt.push_back("Orange corner key");      Dungvarp.push_back(1816);
	TextNR.push_back(18212); TextTxt.push_back("Orange crescent key");    Dungvarp.push_back(1817);
	TextNR.push_back(18214); TextTxt.push_back("Orange wedge key");       Dungvarp.push_back(1818);
	TextNR.push_back(18216); TextTxt.push_back("Orange shield key");      Dungvarp.push_back(1819);
	TextNR.push_back(18218); TextTxt.push_back("Silver triangle key");    Dungvarp.push_back(1820);
	TextNR.push_back(18220); TextTxt.push_back("Silver diamond key");     Dungvarp.push_back(1821);
	TextNR.push_back(18222); TextTxt.push_back("Silver rectangle key");   Dungvarp.push_back(1822);
	TextNR.push_back(18224); TextTxt.push_back("Silver pentagon key");    Dungvarp.push_back(1823);
	TextNR.push_back(18226); TextTxt.push_back("Silver corner key");      Dungvarp.push_back(1824);
	TextNR.push_back(18228); TextTxt.push_back("Silver crescent key");    Dungvarp.push_back(1825);
	TextNR.push_back(18230); TextTxt.push_back("Silver wedge key");       Dungvarp.push_back(1826);
	TextNR.push_back(18232); TextTxt.push_back("Silver shield key");      Dungvarp.push_back(1827);
	TextNR.push_back(18234); TextTxt.push_back("Yellow triangle key");    Dungvarp.push_back(1828);
	TextNR.push_back(18236); TextTxt.push_back("Yellow diamond key");     Dungvarp.push_back(1829);
	TextNR.push_back(18238); TextTxt.push_back("Yellow rectangle key");   Dungvarp.push_back(1830);
	TextNR.push_back(18240); TextTxt.push_back("Yellow pentagon key");    Dungvarp.push_back(1831);
	TextNR.push_back(18242); TextTxt.push_back("Yellow corner key");      Dungvarp.push_back(1832);
	TextNR.push_back(18244); TextTxt.push_back("Yellow crescent key");    Dungvarp.push_back(1833);
	TextNR.push_back(18246); TextTxt.push_back("Yellow wedge key");       Dungvarp.push_back(1834);
	TextNR.push_back(18248); TextTxt.push_back("Yellow shield key");      Dungvarp.push_back(1835);
	TextNR.push_back(18250); TextTxt.push_back("Green triangle key");     Dungvarp.push_back(1836);
	TextNR.push_back(18252); TextTxt.push_back("Green diamond key");      Dungvarp.push_back(1837);
	TextNR.push_back(18254); TextTxt.push_back("Green rectangle key");    Dungvarp.push_back(1838);
	TextNR.push_back(18256); TextTxt.push_back("Green pentagon key");     Dungvarp.push_back(1839);
	TextNR.push_back(18258); TextTxt.push_back("Green corner key");       Dungvarp.push_back(1840);
	TextNR.push_back(18260); TextTxt.push_back("Green crescent key");     Dungvarp.push_back(1841);
	TextNR.push_back(18262); TextTxt.push_back("Green wedge key");        Dungvarp.push_back(1842);
	TextNR.push_back(18264); TextTxt.push_back("Green shield key");       Dungvarp.push_back(1843);
	TextNR.push_back(18266); TextTxt.push_back("Blue triangle key");      Dungvarp.push_back(1844);
	TextNR.push_back(18268); TextTxt.push_back("Blue diamond key");       Dungvarp.push_back(1845);
	TextNR.push_back(18270); TextTxt.push_back("Blue rectangle key");     Dungvarp.push_back(1846);
	TextNR.push_back(18272); TextTxt.push_back("Blue pentagon key");      Dungvarp.push_back(1847);
	TextNR.push_back(18274); TextTxt.push_back("Blue corner key");        Dungvarp.push_back(1848);
	TextNR.push_back(18276); TextTxt.push_back("Blue crescent key");      Dungvarp.push_back(1849);
	TextNR.push_back(18278); TextTxt.push_back("Blue wedge key");         Dungvarp.push_back(1850);
	TextNR.push_back(18280); TextTxt.push_back("Blue shield key");        Dungvarp.push_back(1851);
	TextNR.push_back(18282); TextTxt.push_back("Purple triangle key");    Dungvarp.push_back(1852);
	TextNR.push_back(18284); TextTxt.push_back("Purple diamond key");     Dungvarp.push_back(1853);
	TextNR.push_back(18286); TextTxt.push_back("Purple rectangle key");   Dungvarp.push_back(1854);
	TextNR.push_back(18288); TextTxt.push_back("Purple pentagon key");    Dungvarp.push_back(1855);
	TextNR.push_back(18290); TextTxt.push_back("Purple corner key");      Dungvarp.push_back(1856);
	TextNR.push_back(18292); TextTxt.push_back("Purple crescent key");    Dungvarp.push_back(1857);
	TextNR.push_back(18294); TextTxt.push_back("Purple wedge key");       Dungvarp.push_back(1858);
	TextNR.push_back(18296); TextTxt.push_back("Purple shield key");      Dungvarp.push_back(1859);
	TextNR.push_back(18298); TextTxt.push_back("Crimson triangle key");   Dungvarp.push_back(1860);
	TextNR.push_back(18300); TextTxt.push_back("Crimson diamond key");    Dungvarp.push_back(1861);
	TextNR.push_back(18302); TextTxt.push_back("Crimson rectangle key");  Dungvarp.push_back(1862);
	TextNR.push_back(18304); TextTxt.push_back("Crimson pentagon key");   Dungvarp.push_back(1863);
	TextNR.push_back(18306); TextTxt.push_back("Crimson corner key");     Dungvarp.push_back(1864);
	TextNR.push_back(18308); TextTxt.push_back("Crimson crescent key");   Dungvarp.push_back(1865);
	TextNR.push_back(18310); TextTxt.push_back("Crimson wedge key");      Dungvarp.push_back(1866);
	TextNR.push_back(18312); TextTxt.push_back("Crimson shield key");     Dungvarp.push_back(1867);
	TextNR.push_back(18314); TextTxt.push_back("Gold triangle key");      Dungvarp.push_back(1868);
	TextNR.push_back(18316); TextTxt.push_back("Gold diamond key");       Dungvarp.push_back(1869);
	TextNR.push_back(18318); TextTxt.push_back("Gold rectangle key");     Dungvarp.push_back(1870);
	TextNR.push_back(18320); TextTxt.push_back("Gold pentagon key");      Dungvarp.push_back(1871);
	TextNR.push_back(18322); TextTxt.push_back("Gold corner key");        Dungvarp.push_back(1872);
	TextNR.push_back(18324); TextTxt.push_back("Gold crescent key");      Dungvarp.push_back(1873);
	TextNR.push_back(18326); TextTxt.push_back("Gold wedge key");         Dungvarp.push_back(1874);
	TextNR.push_back(18328); TextTxt.push_back("Gold shield key");        Dungvarp.push_back(1875);
	TextNR.push_back(18778); TextTxt.push_back("Starved ancient effigy");
	TextNR.push_back(20667); TextTxt.push_back("Vecna skull");
	TextNR.push_back(20668); TextTxt.push_back("Vecna skull-N");
	TextNR.push_back(21621); TextTxt.push_back("Fellstalk seed");
	TextNR.push_back(22448); TextTxt.push_back("Polypore spore");
	TextNR.push_back(22451); TextTxt.push_back("Ganodermic flake");
	TextNR.push_back(25316); TextTxt.push_back("Dragon rider boots");
	TextNR.push_back(25317); TextTxt.push_back("Dragon rider boots-N");
	TextNR.push_back(25318); TextTxt.push_back("Dragon rider gloves");
	TextNR.push_back(25319); TextTxt.push_back("Dragon rider gloves-N");
	TextNR.push_back(25689); TextTxt.push_back("Off-hand dragon mace");
	TextNR.push_back(25690); TextTxt.push_back("Off-hand dragon mace");
	TextNR.push_back(25891); TextTxt.push_back("Off-hand rune crossbow");
	TextNR.push_back(25892); TextTxt.push_back("Off-hand rune crossbow-N");
	TextNR.push_back(25980); TextTxt.push_back("Ganodermic boots");
	TextNR.push_back(27481); TextTxt.push_back("Static gloves");
	TextNR.push_back(27482); TextTxt.push_back("Static gloves-N");
	TextNR.push_back(27483); TextTxt.push_back("Static gloves");
	TextNR.push_back(27484); TextTxt.push_back("Tracking gloves");
	TextNR.push_back(27485); TextTxt.push_back("Tracking gloves-N");
	TextNR.push_back(27486); TextTxt.push_back("Tracking gloves");
	TextNR.push_back(27487); TextTxt.push_back("Pneumatic gloves");
	TextNR.push_back(27488); TextTxt.push_back("Pneumatic gloves-N");
	TextNR.push_back(27489); TextTxt.push_back("Pneumatic gloves");
	TextNR.push_back(27490); TextTxt.push_back("Cresbot (unpoked)");
	TextNR.push_back(27493); TextTxt.push_back("Cresbot (unpoked)");
	TextNR.push_back(27494); TextTxt.push_back("Cresbot (unpoked)");
	TextNR.push_back(28258); TextTxt.push_back("Potato cactus seed-N");
	TextNR.push_back(28259); TextTxt.push_back("Prickly pear seed-N");
	TextNR.push_back(28560); TextTxt.push_back("Fly trap seed-N");
	TextNR.push_back(28561); TextTxt.push_back("Sunchoke seed-N");
	TextNR.push_back(28262); TextTxt.push_back("Snape grass seed-N");
	TextNR.push_back(28263); TextTxt.push_back("Reed weed seed-N");
	TextNR.push_back(28264); TextTxt.push_back("Grapevine seed-N");
	TextNR.push_back(28265); TextTxt.push_back("Butterfly flower seed-N");
	TextNR.push_back(28266); TextTxt.push_back("Barberry seed-N");
	TextNR.push_back(28267); TextTxt.push_back("Wishing well bush seed-N");
	TextNR.push_back(28465); TextTxt.push_back("Ascension bolts-N");
	TextNR.push_back(28547); TextTxt.push_back("Crystal triskelion fragment 1");
	TextNR.push_back(28548); TextTxt.push_back("Crystal triskelion fragment 2");
	TextNR.push_back(28549); TextTxt.push_back("Crystal triskelion fragment 3");
	TextNR.push_back(28550); TextTxt.push_back("Crystal triskelion");
	TextNR.push_back(30139); TextTxt.push_back("Spirit sapphire");
	TextNR.push_back(30140); TextTxt.push_back("Spirit emerald");
	TextNR.push_back(30141); TextTxt.push_back("Spirit ruby");
	TextNR.push_back(30142); TextTxt.push_back("Spirit diamond");
	TextNR.push_back(30143); TextTxt.push_back("Spirit dragonstone");
	TextNR.push_back(30144); TextTxt.push_back("Spirit onyx");
	TextNR.push_back(30216); TextTxt.push_back("Tuska mask upper tusks");
	TextNR.push_back(30218); TextTxt.push_back("Tuska mask lower tusks");
	TextNR.push_back(30220); TextTxt.push_back("Tuska mask headpiece");
	TextNR.push_back(30222); TextTxt.push_back("Tuska mask mask plate");
	TextNR.push_back(30224); TextTxt.push_back("Tuska mask mask top");
	TextNR.push_back(30226); TextTxt.push_back("Tuska mask");
	TextNR.push_back(30447); TextTxt.push_back("Spirit sapphire");
	TextNR.push_back(30448); TextTxt.push_back("Spirit emerald");
	TextNR.push_back(30449); TextTxt.push_back("Spirit ruby");
	TextNR.push_back(30450); TextTxt.push_back("Spirit diamond");
	TextNR.push_back(30451); TextTxt.push_back("Spirit dragonstone");
	TextNR.push_back(30452); TextTxt.push_back("Spirit onyx");
	TextNR.push_back(30930); TextTxt.push_back("Dragon Rider helm"); 
	TextNR.push_back(30931); TextTxt.push_back("Dragon Rider helm-N");
	TextNR.push_back(30932); TextTxt.push_back("Dragon Rider helm");
	TextNR.push_back(30933); TextTxt.push_back("Dragon Rider body");
	TextNR.push_back(30934); TextTxt.push_back("Dragon Rider body-N");
	TextNR.push_back(30935); TextTxt.push_back("Dragon Rider body");
	TextNR.push_back(30936); TextTxt.push_back("Dragon Rider chaps");
	TextNR.push_back(30937); TextTxt.push_back("Dragon Rider chaps-N");
	TextNR.push_back(30938); TextTxt.push_back("Dragon Rider chaps");
	TextNR.push_back(30939); TextTxt.push_back("Dragon Rider cape");
	TextNR.push_back(30940); TextTxt.push_back("Dragon Rider cape-N");
	TextNR.push_back(30941); TextTxt.push_back("Dragon Rider cape");
	TextNR.push_back(30943); TextTxt.push_back("Dragon Rider kit");
	TextNR.push_back(30944); TextTxt.push_back("Dragon Rider kit-N");
	TextNR.push_back(31189); TextTxt.push_back("Celestial handwraps");
	TextNR.push_back(31190); TextTxt.push_back("Celestal handwraps-N");
	TextNR.push_back(31191); TextTxt.push_back("Celestial handwraps");
	TextNR.push_back(31421); TextTxt.push_back("Aviansie talons");
	TextNR.push_back(32608); TextTxt.push_back("Manifest shadow core");	
	TextNR.push_back(32609); TextTxt.push_back("Light core");
	TextNR.push_back(32749); TextTxt.push_back("Dungeoneering tokens(100)");
	TextNR.push_back(33877); TextTxt.push_back("Manifest shadow core-N");
	TextNR.push_back(37227); TextTxt.push_back("Congealed blood");
	TextNR.push_back(37952); TextTxt.push_back("Bloodweed seed");
	TextNR.push_back(41582); TextTxt.push_back("Hexhunter bow");
	TextNR.push_back(41589); TextTxt.push_back("Stalker essence");
	TextNR.push_back(36814); TextTxt.push_back("Mimic kill token-N");
	TextNR.push_back(40310); TextTxt.push_back("Key to the Crossing");
	TextNR.push_back(42006); TextTxt.push_back("Sealed clue scroll (easy)-N");
	TextNR.push_back(42007); TextTxt.push_back("Sealed clue scroll (medium)-N");
	TextNR.push_back(42008); TextTxt.push_back("Sealed clue scroll (hard)-N");
	TextNR.push_back(42009); TextTxt.push_back("Sealed clue scroll (elite)-N");
	TextNR.push_back(42010); TextTxt.push_back("Sealed clue scroll (master)-N");


































































}


VOID LoadClueScrolls() {

	//scroll box 18964,18963
	//  CNR.push_back(); CText.push_back(""); CCoord.push_back({});
	//hard
	
	CNR.push_back(1644); CText.push_back("Mort swamp,near fspot");     CCoord.push_back({ 3440,3419 });
	CNR.push_back(2722); CText.push_back("Varrock sawmill,lumber yard teleport scroll");           CCoord.push_back({ 3309,3503 });
	CNR.push_back(2733); CText.push_back("level 36 wilderness,canoe or wild volcano->west");           CCoord.push_back({ 3140,3804 });
	CNR.push_back(2739); CText.push_back("Behind Pirates' hideout,lv56 wild,west from mages bank"); CCoord.push_back({ 3039,3960 });
	CNR.push_back(2745); CText.push_back("Lv22 Wild,west'Ruins',tele Trollheim->jump down to wild or Dareeyak Teleport");CCoord.push_back({ 2967,3689 });
	CNR.push_back(2764); CText.push_back("Lv22 Wild,near east green drags,Carrallanger Teleport->run east");CCoord.push_back({ 3305,3692 });
	CNR.push_back(2773); CText.push_back("Lumby basement,box");           CCoord.push_back({3219,9617});
	CNR.push_back(2774); CText.push_back("Edgeville yews,next to nettles");           CCoord.push_back({ 3089,3469 });
	CNR.push_back(2776); CText.push_back("Varrock west bank basement,dig by gate");           CCoord.push_back({ 3188,3433 });
	CNR.push_back(2778); CText.push_back("Port Sarim,Gerrant");           CCoord.push_back({ 3013,3225 });
	CNR.push_back(2780); CText.push_back("Draynor,Aggie outside window dig"); CCoord.push_back({ 3084,3257 });
	CNR.push_back(2782); CText.push_back("Lumbridge flax room drawers,bronze dagger at top"); CCoord.push_back({3213,3216});
	CNR.push_back(2783); CText.push_back("Ardy zoo,next to torch");           CCoord.push_back({ 2599,3266 });
	CNR.push_back(2785); CText.push_back("Windmill between draynor and lumby, at top,Crate"); CCoord.push_back({ 3167,3309 });
	CNR.push_back(2790); CText.push_back("Varrock sewers,near moss giants,caldron"); CCoord.push_back({3161,9904});
	CNR.push_back(2792); CText.push_back("Hans walking around lumby castle"); CCoord.push_back({ 3221,3219 });
	CNR.push_back(2793); CText.push_back("Abbot Langley in Edgeville Monastery"); CCoord.push_back({ 3058,3484 });
	CNR.push_back(2794); CText.push_back("Edgeville,Oziach"); CCoord.push_back({ 3068,3516 });
	CNR.push_back(2796); CText.push_back("Sir Prysin in varrock castle"); CCoord.push_back({3204,3472});
	CNR.push_back(2797); CText.push_back("Varrock square,Wilough"); CCoord.push_back({ 3220,3434 });
	CNR.push_back(2801); CText.push_back("Draynor,close to jail"); CCoord.push_back({3136,3252});
	CNR.push_back(2848); CText.push_back("Hajedy, Karamja cart travel"); CCoord.push_back({ 2778,3210 });
	CNR.push_back(2827); CText.push_back("South of Drynor bank"); CCoord.push_back({3093,3225});	
	CNR.push_back(3520); CText.push_back("Behind Yanille smithhouse"); CCoord.push_back({2617,3076});
	CNR.push_back(3522); CText.push_back("West ardougne, broken house row"); CCoord.push_back({ 2488,3307 });
	CNR.push_back(3524); CText.push_back("Near castle wars,up to north,goblins Crate"); CCoord.push_back({ 2457,3182 });
	CNR.push_back(3526); CText.push_back("Trollheim tablet tele"); CCoord.push_back({ 2884,3668 });
	CNR.push_back(3528); CText.push_back("In front of troll stronghold"); CCoord.push_back({2848,3685});
	CNR.push_back(3532); CText.push_back("Kharazi jungle,small island tip poking to south,skeleton nearby");            CCoord.push_back({2775,2891});
	CNR.push_back(3534); CText.push_back("Kharazi Jungle,quest pool");            CCoord.push_back({ 2838,2914 });
	CNR.push_back(3536); CText.push_back("Juju herb area,witchdoctor mask");            CCoord.push_back({ 2950,2902 });
	CNR.push_back(3538); CText.push_back("Outside the east wall of the Ship yard building,Port Sarim charter ship there");            CCoord.push_back({ 2961,3024 });
	CNR.push_back(3540); CText.push_back("Karamja,near Shilo gate,stepping stones,jogres");       CCoord.push_back({2924,2963});
	CNR.push_back(3542); CText.push_back("Mort Myre swamp,Nature Spirit's grotto,use quick-travel on gate");       CCoord.push_back({ 3440,3341 });
	CNR.push_back(3544); CText.push_back("Middle of Mort swamp,near 2 fishing spots");       CCoord.push_back({3441,3419});
	CNR.push_back(3546); CText.push_back("Middle of Gu'tanoth");       CCoord.push_back({2543,3032});	
	CNR.push_back(3548); CText.push_back("Below Gu'tanoth,ALP,Hole that takes to island,");       CCoord.push_back({ 2581,3030 });
	CNR.push_back(3552); CText.push_back("Bedabin camp pond,Bandit camp->to north");            CCoord.push_back({ 3168,3041 });
	CNR.push_back(3554); CText.push_back("Dual arena, top");            CCoord.push_back({ 3361,3243 });
	CNR.push_back(3560); CText.push_back("Small pond next to tyras camp,Elven lands,charter ship"); CCoord.push_back({2209,3161});
	CNR.push_back(3562); CText.push_back("Elven lands,small pond,Tirannwn home tele->run north->leafstrap->west"); CCoord.push_back({ 2181,3206 });
	CNR.push_back(3566); CText.push_back("Exam centre,Examiner"); CCoord.push_back({ 3360,3343 });
	CNR.push_back(3570); CText.push_back("WhiteWolfMountain,Captain Bleemadge");            CCoord.push_back({ 2850,3493 });
	CNR.push_back(3572); CText.push_back("northern bookcase on the 1st floor of the Sorcerer's Tower,ardy farm->northeast");     CCoord.push_back({ 2702,3408 });
	CNR.push_back(3573); CText.push_back("Baxtorian Falls,house 1st floor,boxes,barb tele->south");     CCoord.push_back({ 2521,3494 });
	CNR.push_back(3574); CText.push_back("Below coalcarts,boxes,fishing guild tele is closest");     CCoord.push_back({2578,3464});
	CNR.push_back(3575); CText.push_back("Heckel Funch in Tree Gnome Stronghold,2nd floor,eastside");     CCoord.push_back({ 2490,3488 });
	CNR.push_back(3577); CText.push_back("Gnome trainer,gnome agility area");     CCoord.push_back({ 2474,3428 });
	CNR.push_back(3579); CText.push_back("Entrana,drawers");     CCoord.push_back({2818,3353});
	CNR.push_back(3580); CText.push_back("Under red spiders eggs,in karamaja vulcano"); CCoord.push_back({ 2832,9586 });
	CNR.push_back(3582); CText.push_back("In front of slayer tower"); CCoord.push_back({3443,3515});	
	CNR.push_back(3586); CText.push_back("Burthorpe,near barracks"); CCoord.push_back({2920,3535});
	CNR.push_back(3592); CText.push_back("Tree Gnome Stronghold,west,terrorbird pen with bridge"); CCoord.push_back({ 2387,3435 });
	CNR.push_back(3598); CText.push_back("McGrubor's Wood, west of Seers' Village. Fairy ring code ALS"); CCoord.push_back({ 2658,3488 });
	CNR.push_back(3599); CText.push_back("TowerOfLife,fairy DJP"); CCoord.push_back({2649,3231});
	CNR.push_back(3602); CText.push_back("Chemist house in Rimmington"); CCoord.push_back({2923,3209});
	CNR.push_back(3614); CText.push_back("Ulizius,near Mort swamp gate"); CCoord.push_back({3441,3461});
	CNR.push_back(7239); CText.push_back("Lv50 wild,3 little vulcanos,west of mage bank");  CCoord.push_back({ 3021,3912 });
	CNR.push_back(7241); CText.push_back("Front of legends guild");  CCoord.push_back({2723,3338});
	CNR.push_back(7248); CText.push_back("Bandit camp,general store crate");  CCoord.push_back({3178,2987});
	CNR.push_back(7249); CText.push_back("Wizards tower,spinning bookcase");  CCoord.push_back({ 3094,3152 });
	CNR.push_back(7250); CText.push_back("Elemental workshop crate");  CCoord.push_back({ 2723,9891 });
	CNR.push_back(7251); CText.push_back("Dwarven mines,around middle,mine cart search");  CCoord.push_back({ 3041,9820 });
	CNR.push_back(7252); CText.push_back("Yanille dung,pray at alter,crates");  CCoord.push_back({ 2577,9583 });
	CNR.push_back(7253); CText.push_back("Carpet ride->Uzer,boxes");  CCoord.push_back({3478,3091});
	CNR.push_back(7255); CText.push_back("Ardy,west from bank,north from castle,Jimmy Dazzler house,drawers");  CCoord.push_back({ 2562,3322 });
	CNR.push_back(7256); CText.push_back("Arandar pass,next to world gate,under red spider eggs");  CCoord.push_back({2340,3312});
	CNR.push_back(7258); CText.push_back("Bandit camp->run west->peninsula tip");  CCoord.push_back({ 3138,2969 });
	CNR.push_back(7262); CText.push_back("North from abyss rc");  CCoord.push_back({ 3113,3602 });
	CNR.push_back(7266); CText.push_back("Rellekka->north->seaweed");  CCoord.push_back({ 2712,3732 });
	CNR.push_back(7268); CText.push_back("Gnome stronghold,Gnome coach,near gnomeball,6");  CCoord.push_back({ 2409,3488 });
	CNR.push_back(7270); CText.push_back("Tree Gnome Village general store upstairs,Bolkoy,13");  CCoord.push_back({ 2526,3262 });
	CNR.push_back(7272); CText.push_back("Cap'n Izzy no Beard,Brimhaven agility arena entrance,33");  CCoord.push_back({ 2807,3191 });
	CNR.push_back(7286); CText.push_back("Miscellania");  CCoord.push_back({2536,3865});	
	CNR.push_back(7288); CText.push_back("Mort'ton road, near Abandoned mine");  CCoord.push_back({3433,3267});
	CNR.push_back(7290); CText.push_back("Near ZMI-rc entrance,close to altar");  CCoord.push_back({2454,3230});
	CNR.push_back(7292); CText.push_back("Lighthouse island,near crystal tree");  CCoord.push_back({2579,3597});
	CNR.push_back(7294); CText.push_back("Between Rellekka and Seers,fairy cjr");  CCoord.push_back({2668,3561});
	CNR.push_back(7313); CText.push_back("Near Shattered worlds minigame");  CCoord.push_back({3185,3149});
	CNR.push_back(7315); CText.push_back("Rellekka,swaying tree");  CCoord.push_back({ 2735,3638 });
	CNR.push_back(7317); CText.push_back("Karamja,between nature altar and G-wisps");  CCoord.push_back({2875,3046});
	CNR.push_back(10236); CText.push_back("Fishing guild,elemtal shield,blue-d chaps,rune warhammer,raspberry"); CCoord.push_back({ 2585,3422 });
	CNR.push_back(10238); CText.push_back("Lighthouse top,blue dhide body,vambs,no jewellery,BOW"); CCoord.push_back({ 2512,3640});
	CNR.push_back(10240); CText.push_back("Panic at middle of haunted woods, no items equiped"); CCoord.push_back({3620,3486});
	CNR.push_back(10242); CText.push_back("Pyramid,r-life,uncharged glory,adam 2h,dance"); CCoord.push_back({ 3294,2782 });
	CNR.push_back(10246); CText.push_back("Salute Banana plant,diamond ring,amulet of power,nothing chest&legs"); CCoord.push_back({2914,3155});
	CNR.push_back(10248); CText.push_back("Jokul,rune fullhelm,blue dragonhide chaps,fire battlestaff,laugh"); CCoord.push_back({ 2795,3670 });
	CNR.push_back(10250); CText.push_back("WhiteWolfMountain,mithril platelegs,ring of life,rune hatchet,panic"); CCoord.push_back({ 2846,3496 });
	CNR.push_back(10252); CText.push_back("Shilo,blowkiss bank,splitbark helm,mud pie,rune plate"); CCoord.push_back({ 2852,2954 });
	CNR.push_back(10254); CText.push_back("Canifis,dance at center,bow,spiny helmet,mith platelegs,iron 2h"); CCoord.push_back({3493,3488});
	CNR.push_back(10258); CText.push_back("Barbarian village bridge,mith full helm,steelkite,iron hatchet,twirl,salute"); CCoord.push_back({3113,3418});
	CNR.push_back(10268); CText.push_back("Yanille bank jump,jig,iron crossbow,adamant helm,snakeskin chaps"); CCoord.push_back({});
	CNR.push_back(13010); CText.push_back("Keldagrim,sculptor model"); CCoord.push_back({ 2904,10207 });
	CNR.push_back(13012); CText.push_back("Piscatoris Fishing Colony,Ramara du Croissant"); CCoord.push_back({ 2340,3675 });
	CNR.push_back(13014); CText.push_back("Wizards' Tower,ground floor,Professor Onglewip"); CCoord.push_back({ 3104,3158 });
	CNR.push_back(13016); CText.push_back("Shiratti the Cu,Nardah,next to the pray thing"); CCoord.push_back({3426,2928});
	CNR.push_back(13018); CText.push_back("Port sarim docks,trader Stan"); CCoord.push_back({ 3033,3190 });
	CNR.push_back(13020); CText.push_back("South of the Castle Wars,Uglug Nar"); CCoord.push_back({ 2442,3051 });
	CNR.push_back(13022); CText.push_back("Zanaris,Fairy Nuff,north from bank"); CCoord.push_back({ 2387,4469 });
	CNR.push_back(13024); CText.push_back("Cam the Camel,Al Kharid->west"); CCoord.push_back({ 3288,3236 });
	CNR.push_back(13026); CText.push_back("Captain Ninto,under WhiteWolfmountain"); CCoord.push_back({2868,9876});
	CNR.push_back(13028); CText.push_back("Ardy platebody shop seller,Zenesha"); CCoord.push_back({2660,3292});
	CNR.push_back(13030); CText.push_back("Yanille,Wizards guild basement,wizard Frumscone"); CCoord.push_back({2588,9489});
	CNR.push_back(13032); CText.push_back("Miscelannia,Queen Sigrid"); CCoord.push_back({2501,3861});
	CNR.push_back(13034); CText.push_back("Limestone mine,The bonesack(e) or lumberyard teleport scroll, Odd Old Man"); CCoord.push_back({ 3363,3505 });
	CNR.push_back(13036); CText.push_back("Dung cape->Braindeath Island,top lake"); CCoord.push_back({2133,5162});
	CNR.push_back(13038); CText.push_back("Barbarian outpost,shell"); CCoord.push_back({ 2519,3594 });
	CNR.push_back(13041); CText.push_back("General store crate in Lletya"); CCoord.push_back({ 2340,3185 });
	CNR.push_back(13042); CText.push_back("Gnome glider to Karamja(Gandius),Dig by fire"); CCoord.push_back({2969,2974});
	CNR.push_back(13046); CText.push_back("Nardah flying carpets, near cactus"); CCoord.push_back({ 3397,2917 });
	CNR.push_back(13048); CText.push_back("Rellekka,Swensen the Navigator's house,Crate"); CCoord.push_back({ 2648,3662 });
	CNR.push_back(13053); CText.push_back("Limestone mine,small building near the Odd Old Man,lumberyard scroll teleport<-"); CCoord.push_back({ 3356,3507 });
	CNR.push_back(13058); CText.push_back("Next to the well in Pollnivneach."); CCoord.push_back({3360,2971});
	CNR.push_back(13063); CText.push_back("Port Sarim->run to south->Mudskipper point,starfish"); CCoord.push_back({3000,3110});
	CNR.push_back(33269); CText.push_back("Near fishing guild,behind mid willow "); CCoord.push_back({ 2631,3407 });
	CNR.push_back(33272); CText.push_back("Travely wheat field,next to travely dung"); CCoord.push_back({ 2895,3398 });
	CNR.push_back(33275); CText.push_back("Karamja,north from nature RC,nexto divination"); CCoord.push_back({ 2887,3044 });
	CNR.push_back(33278); CText.push_back("Below Yanille,near sea,near 3 bushes "); CCoord.push_back({ 2602,3062 });
	CNR.push_back(33281); CText.push_back("Below eagles peaks lodestone"); CCoord.push_back({ 2364,3462 });
	CNR.push_back(33288); CText.push_back("AL Kharid->Citharede Abbey,Valerio,17"); CCoord.push_back({3400,3149});
	//CNR.push_back(33289); CText.push_back("17"); CCoord.push_back({3400,3149});

	//puzzle 13017,helwyr puzzle 13019,troll puzzle 13027,13033,bridge puzzle 13031,13035,2798,3576
	//easy casket 10219,7237
	//easy scroll box 19065-19102
	///////////////////////////////////
	//medium scroll box 19078-19120
	//medium casket 7291,7314,7318,10269
	//////////////////////////////////
	//hard scroll box 18937-19004,33271-33280
	//hard casket olds 3545,3547 new 42003
	////////////////////////////////////////////////////////////////////////
	//puzzle box 19042
	//scroll box 19041
	//elite casket 19039,19040
	//elite unopend 42009 hard 42008 medium 42007 easy 42006 master 42010
	CNR.push_back(19042); CText.push_back("Puzzle"); CCoord.push_back({ 0,0 });
	CNR.push_back(19043); CText.push_back("Ardy"); CCoord.push_back({ 0,0 });
	CNR.push_back(19044); CText.push_back("Varrock"); CCoord.push_back({ 0,0 });
	CNR.push_back(19045); CText.push_back("Elven lands"); CCoord.push_back({ 0,0 });
	CNR.push_back(19046); CText.push_back("Falador"); CCoord.push_back({ 0,0 });
	CNR.push_back(19047); CText.push_back("Piscatoris hunter"); CCoord.push_back({ 0,0 });
	CNR.push_back(19048); CText.push_back("Wolf moutain"); CCoord.push_back({ 0,0 });
	CNR.push_back(19049); CText.push_back("Haunted woods"); CCoord.push_back({ 0,0 });
	CNR.push_back(19050); CText.push_back("North of Nardah"); CCoord.push_back({ 0,0 });
	CNR.push_back(19053); CText.push_back("Kharazi jungle"); CCoord.push_back({ 0,0 });
	CNR.push_back(19054); CText.push_back("Jatizso and Neitiznot"); CCoord.push_back({ 0,0 });
	CNR.push_back(19055); CText.push_back("Keldagrim"); CCoord.push_back({ 0,0 });
	CNR.push_back(19056); CText.push_back("Zanaris"); CCoord.push_back({ 0,0 });
	CNR.push_back(19057); CText.push_back("Fremennik slayer dung"); CCoord.push_back({ 0,0 });
	CNR.push_back(19058); CText.push_back("Lumbrige swamp dung"); CCoord.push_back({ 0,0 });
	CNR.push_back(19059); CText.push_back("Dorgesh-Kaan"); CCoord.push_back({ 0,0 });
	CNR.push_back(19060); CText.push_back("Brimhaven dung"); CCoord.push_back({ 0,0 });
	CNR.push_back(19061); CText.push_back("Taverly dungeon"); CCoord.push_back({ 0,0 });
	CNR.push_back(19062); CText.push_back("Mos Le'Harmless"); CCoord.push_back({ 0,0 });
	CNR.push_back(19063); CText.push_back("Chaos tunnels"); CCoord.push_back({ 0,0 });
	CNR.push_back(19064); CText.push_back("Arrow"); CCoord.push_back({0,0});

	//mastery
	//scroll box 41795,41788
	//casket 42005
//////////////stuff///////////////////
	CNR.push_back(41789); CText.push_back("Puzzle box"); CCoord.push_back({ 0,0 });
	CNR.push_back(41790); CText.push_back("Priff"); CCoord.push_back({ 0,0 });
	CNR.push_back(41792); CText.push_back("Heart of Gielinor"); CCoord.push_back({ 0,0 });
	CNR.push_back(41793); CText.push_back("Turtles Islands"); CCoord.push_back({ 0,0 });
	CNR.push_back(41794); CText.push_back("Item puzzle"); CCoord.push_back({0,0});
	CNR.push_back(41796); CText.push_back("Talk to"); CCoord.push_back({ 0,0 });
	CNR.push_back(41797); CText.push_back("Skill puzzle"); CCoord.push_back({0,0});
	CNR.push_back(41798); CText.push_back("Eastern Lands arrow"); CCoord.push_back({ 0,0 });
	CNR.push_back(41800); CText.push_back("Lockbox2"); CCoord.push_back({ 0,0 });

	
}