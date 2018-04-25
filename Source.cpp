#include <windows.h>
#include<Windowsx.h>
#include <stdio.h>
#include "resource.h"
#include"Items.h"
int price;
TCHAR str[255];
HWND shopnd = NULL;
int i;
bool LoadMyBitmap(LPCWSTR, HDC, LONG, LONG, LONG width, LONG Bottom);
void init_data();
int sum;
bool proced = false;
bool bill = false;
bool recpt = false;
bool rest = false; 
struct Final_Input {
	int cpu_company;	
	TCHAR cpu_company1[20];
	int cpu_generation; 	
	TCHAR cpu_generation1[20];
	int cpu_architecture;	
	TCHAR cpu_architecture1[20];
	int cpu_price;	
	int cpu_price1;
	int ram_company;	
	TCHAR ram_company1[20];
	int ram_size;	
	CHAR ram_size1[20];
	int ram_price;	
	int ram_price1;
	int mother_company; 
	TCHAR mother_company1[20];
	int mother_price; 
	int mother_price1;
	int graphics_company; 
	TCHAR graphics_company1[20];
	int	graphics_size; 
	TCHAR graphics_size1[20];
	int	graphics_type; 
	TCHAR graphics_type1[20];
	int	graphics_price; 
	int graphics_price1;
	int key_company; 
	TCHAR key_company1[20];
	int key_price;	
	int key_price1;
	int mouse_company; 
	TCHAR mouse_company1[20];
	int mouse_price; 
	int mouse_price1;
	int cd_company; 
	TCHAR cd_company1[20];
	int cd_price; 
	int cd_price1;
	int smpaintstruc_company; 
	TCHAR smpaintstruc_company1[20];
	int smpaintstruc_price;	
	int smpaintstruc_price1;
	int monitor_company;
	TCHAR monitor_company1[20];
	int monitor_price; 
	int monitor_price1;
	int cabinet_company;
	TCHAR cabinet_company1[20];
	int cabinet_price; 
	int cabinet_price1;
	int harddisk_company; 
	TCHAR harddisk_company1[20];
	int harddisk_size; 
	TCHAR harddisk_size1[20];
	int harddisk_price; 
	int harddisk_price1;
}ins;
TCHAR *buf;
BOOL CALLBACK MyDlgProc(HWND hDlg, UINT iMsg, WPARAM wParam, LPARAM lParam)
{
	HWND ace;
	HDC hdcstat;
	HFONT hFont;
	HDC hdc;
	RECT rc;
	PAINTSTRUCT paintstruc;
	switch (iMsg)
	{
	case WM_PAINT:

		hdc = BeginPaint(hDlg, &paintstruc);
		GetWindowRect(hDlg, &rc);
		SetBkMode(hdc, TRANSPARENT);
		LoadMyBitmap(TEXT("image1.bmp"), hdc, rc.left , rc.top , rc.right , rc.bottom );
		//LoadMyBitmap(TEXT("image2.bmp"), hdc, rect.left, rect.top + 50, rect.right, rect.bottom - 110);
		EndPaint(hDlg, &paintstruc);
		break;
	case WM_INITDIALOG:
		for (i = 0; i < 2; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO1, CB_ADDSTRING, 0, (LPARAM)cpu_name[i]);
		for (i = 0; i < 3; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO4, CB_ADDSTRING, 0, (LPARAM)ram_company[i]);

		for (i = 0; i < 3; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO6, CB_ADDSTRING, 0, (LPARAM)mother_company[i]);

		for (i = 0; i < 2; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO7, CB_ADDSTRING, 0, (LPARAM)graphics_company[i]);

		for (i = 0; i < 2; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO9, CB_ADDSTRING, 0, (LPARAM)harddisk_company[i]);

		for (i = 0; i < 3; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO11, CB_ADDSTRING, 0, (LPARAM)key_company[i]);

		for (i = 0; i < 2; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO12, CB_ADDSTRING, 0, (LPARAM)mouse_company[i]);

		for (i = 0; i < 2; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO13, CB_ADDSTRING, 0, (LPARAM)cd_company[i]);

		for (i = 0; i < 2; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO14, CB_ADDSTRING, 0, (LPARAM)smpaintstruc_company[i]);

		for (i = 0; i < 4; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO15, CB_ADDSTRING, 0, (LPARAM)cabinet_company[i]);

		for (i = 0; i < 3; i++)
			SendDlgItemMessage(hDlg, IDC_COMBO16, CB_ADDSTRING, 0, (LPARAM)monitor_company[i]);
		ace = GetDlgItem(hDlg, IDC_COMBO2);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, IDC_COMBO3);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_CPU);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, IDC_COMBO5);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_RAM);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_MOTHER);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_GRAPHICS);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_HARD);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_KEY);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_MOUSE);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_CD);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_SMpaintstruc);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_CABINET);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_MONITOR);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, IDC_COMBO8);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, IDC_COMBO8_1);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, IDC_COMBO10);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_CPU_RS);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_RAM_RS);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_MOTHER_RS);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_GRAPHICS_RS);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_HARD_RS);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_KEY_RS);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_MOUSE_RS);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_CD_RS);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_SMpaintstruc_RS);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_CABINET_RS);
		ShowWindow(ace, SW_HIDE);
		ace = GetDlgItem(hDlg, ID_MONITOR_RS);
		ShowWindow(ace, SW_HIDE);

		break;
	case WM_COMMAND:

		switch (LOWORD(wParam))
		{
		case ID_OK_D:
			bill = true;
			init_data();
			ace = GetDlgItem(hDlg, IDC_COMBO1);
			ins.cpu_company = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.cpu_company, (LPARAM)ins.cpu_company1);
			//MessageBox(hDlg, (LPCWSTR)ins.cpu_company1, TEXT(""), MB_OK);

			ace = GetDlgItem(hDlg, IDC_COMBO2);
			ins.cpu_generation = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.cpu_generation, (LPARAM)ins.cpu_generation1);
			//MessageBox(hDlg, (LPCWSTR)ins.cpu_generation1, TEXT(""), MB_OK);

			ace = GetDlgItem(hDlg, IDC_COMBO3);
			ins.cpu_architecture = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.cpu_architecture, (LPARAM)ins.cpu_architecture1);
			//MessageBox(hDlg, (LPCWSTR)ins.cpu_generation1, TEXT(""), MB_OK);

			ins.cpu_price1 = GetDlgItemInt(hDlg, ID_CPU, NULL, TRUE);

			ace = GetDlgItem(hDlg, IDC_COMBO4);
			ins.ram_company = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.ram_company, (LPARAM)ins.ram_company1);


			ace = GetDlgItem(hDlg, IDC_COMBO5);
			ins.ram_size = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.ram_size, (LPARAM)ins.ram_size1);

			ins.ram_price1 = GetDlgItemInt(hDlg, ID_RAM, NULL, TRUE);

			ace = GetDlgItem(hDlg, IDC_COMBO6);
			ins.mother_company = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.mother_company, (LPARAM)ins.mother_company1);

			ins.mother_price1 = GetDlgItemInt(hDlg, ID_MOTHER, NULL, TRUE);

			ace = GetDlgItem(hDlg, IDC_COMBO7);
			ins.graphics_company = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.graphics_company, (LPARAM)ins.graphics_company1);

			ace = GetDlgItem(hDlg, IDC_COMBO8);
			ins.graphics_size = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.graphics_size, (LPARAM)ins.graphics_size1);

			ace = GetDlgItem(hDlg, IDC_COMBO8_1);
			ins.graphics_type = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.graphics_type, (LPARAM)ins.graphics_type1);

			ins.graphics_price1 = GetDlgItemInt(hDlg, ID_GRAPHICS, NULL, TRUE);

			ace = GetDlgItem(hDlg, IDC_COMBO9);
			ins.harddisk_company = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.harddisk_company, (LPARAM)ins.harddisk_company1);

			ace = GetDlgItem(hDlg, IDC_COMBO10);
			ins.harddisk_size = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.harddisk_size, (LPARAM)ins.harddisk_size1);

			ins.harddisk_price1 = GetDlgItemInt(hDlg, ID_HARD, NULL, TRUE);

			ace = GetDlgItem(hDlg, IDC_COMBO11);
			ins.key_company = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.key_company, (LPARAM)ins.key_company1);

			ins.key_price1 = GetDlgItemInt(hDlg, ID_KEY, NULL, TRUE);

			ace = GetDlgItem(hDlg, IDC_COMBO12);
			ins.mouse_company = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.mouse_company, (LPARAM)ins.mouse_company1);

			ins.mouse_price1 = GetDlgItemInt(hDlg, ID_MOUSE, NULL, TRUE);


			ace = GetDlgItem(hDlg, IDC_COMBO13);
			ins.cd_company = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.cd_company, (LPARAM)ins.cd_company1);

			ins.cd_price1 = GetDlgItemInt(hDlg, ID_CD, NULL, TRUE);


			ace = GetDlgItem(hDlg, IDC_COMBO14);
			ins.smpaintstruc_company = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.smpaintstruc_company, (LPARAM)ins.smpaintstruc_company1);

			ins.smpaintstruc_price1 = GetDlgItemInt(hDlg, ID_SMpaintstruc, NULL, TRUE);


			ace = GetDlgItem(hDlg, IDC_COMBO15);
			ins.cabinet_company = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.cabinet_company, (LPARAM)ins.cabinet_company1);

			ins.cabinet_price1 = GetDlgItemInt(hDlg, ID_CABINET, NULL, TRUE);



			ace = GetDlgItem(hDlg, IDC_COMBO16);
			ins.monitor_company = SendMessage(ace, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
			(TCHAR)SendMessage(ace, (UINT)CB_GETLBTEXT, (WPARAM)ins.monitor_company, (LPARAM)ins.monitor_company1);

			ins.monitor_price1 = GetDlgItemInt(hDlg, ID_MONITOR, NULL, TRUE);

			InvalidateRect(shopnd, NULL, TRUE);
			EndDialog(hDlg, 0);
			break;
		case IDC_COMBO1:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				ace = GetDlgItem(hDlg, ID_CPU);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				ace = GetDlgItem(hDlg, IDC_COMBO2);
				ShowWindow(ace, SW_SHOW);
				ins.cpu_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO2, CB_RESETCONTENT, 0, 0);
				SendDlgItemMessage(hDlg, IDC_COMBO3, CB_RESETCONTENT, 0, 0);
				if (ins.cpu_company == 0)
				{
					for (i = 0; i < 3; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)intel_generation[i]);
				}
				else if (ins.cpu_company == 1)
				{
					for (i = 0; i < 3; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO2, CB_ADDSTRING, 0, (LPARAM)amd_generation[i]);
				}
			}
			break;
		case IDC_COMBO2:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				ace = GetDlgItem(hDlg, ID_CPU);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				ace = GetDlgItem(hDlg, IDC_COMBO3);
				ShowWindow(ace, SW_SHOW);

				ins.cpu_generation = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
					(WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO3, CB_RESETCONTENT, 0, 0);

				if (ins.cpu_company == 0)
				{
					for (i = 0; i < 6; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO3, CB_ADDSTRING, 0, (LPARAM)i3_architecture[i]);
				}
				else if (ins.cpu_company == 1)
				{
					for (i = 0; i < 6; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO3, CB_ADDSTRING, 0, (LPARAM)a4_architecture[i]);
				}
			}
			break;
		case IDC_COMBO3:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				ace = GetDlgItem(hDlg, ID_CPU_RS);
				ShowWindow(ace, SW_SHOW);
				EnableWindow(ace, FALSE);

				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT("Rs"));
				ace = GetDlgItem(hDlg, ID_CPU);
				ShowWindow(ace, SW_SHOW);
				ins.cpu_architecture = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (ins.cpu_company == 0)
				{
					switch (ins.cpu_generation)
					{
					case 0:
						(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)i3_architecture_price[ins.cpu_architecture]);
						break;
					case 1:
						(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)i5_architecture_price[ins.cpu_architecture]);
						break;
					case 2:
						(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)i7_architecture_price[ins.cpu_architecture]);
						break;
					}
				}
				else
				{
					switch (ins.cpu_generation)
					{
					case 0:
						(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)a4_architecture_price[ins.cpu_architecture]);
						break;
					case 1:
						(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)am3_architecture_price[ins.cpu_architecture]);
						break;
					case 2:
						(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)fx_architecture_price[ins.cpu_architecture]);
						break;
					}
				}

				EnableWindow(ace, FALSE);
			}
			break;
		case IDC_COMBO4:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{

				ace = GetDlgItem(hDlg, ID_RAM);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				ace = GetDlgItem(hDlg, IDC_COMBO5);
				ShowWindow(ace, SW_SHOW);
				ins.ram_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL,
					(WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO5, CB_RESETCONTENT, 0, 0);

				if (ins.ram_company == 0)
				{
					for (i = 0; i < 3; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO5, CB_ADDSTRING, 0, (LPARAM)gskill_size[i]);
				}
				else if (ins.ram_company == 1)
				{
					for (i = 0; i < 3; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO5, CB_ADDSTRING, 0, (LPARAM)samsung_size[i]);
				}
				else if (ins.ram_company == 2)
				{
					for (i = 0; i < 3; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO5, CB_ADDSTRING, 0, (LPARAM)transcend_size[i]);
				}
			}
			break;
		case IDC_COMBO5:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				ace = GetDlgItem(hDlg, ID_RAM_RS);
				ShowWindow(ace, SW_SHOW);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT("Rs"));
				EnableWindow(ace, FALSE);
				ace = GetDlgItem(hDlg, ID_RAM);
				ShowWindow(ace, SW_SHOW);
				ins.ram_size = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (ins.ram_company == 0)
				{
					(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)gskill_price[ins.ram_size]);
				}
				else if (ins.ram_company == 1)
				{
					(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)samsumg_price[ins.ram_size]);
				}
				else if (ins.ram_company == 2)
				{
					(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)transcend_price[ins.ram_size]);
				}

				EnableWindow(ace, FALSE);
			}
			break;
		case IDC_COMBO6:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				ace = GetDlgItem(hDlg, ID_MOTHER_RS);
				ShowWindow(ace, SW_SHOW);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT("Rs"));
				EnableWindow(ace, FALSE);
				ace = GetDlgItem(hDlg, ID_MOTHER);
				ShowWindow(ace, SW_SHOW);
				ins.mother_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)mother_price[ins.mother_company]);
				EnableWindow(ace, FALSE);
			}
			break;
		case IDC_COMBO7:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				ace = GetDlgItem(hDlg, ID_GRAPHICS);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				ace = GetDlgItem(hDlg, IDC_COMBO8);
				ShowWindow(ace, SW_SHOW);
				ins.graphics_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO8, CB_RESETCONTENT, 0, 0);
				SendDlgItemMessage(hDlg, IDC_COMBO8_1, CB_RESETCONTENT, 0, 0);
				if (ins.graphics_company == 0)
				{
					for (i = 0; i < 3; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO8, CB_ADDSTRING, 0, (LPARAM)nvidia_size[i]);
				}
				else if (ins.graphics_company == 1)
				{
					for (i = 0; i < 2; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO8, CB_ADDSTRING, 0, (LPARAM)amd_size[i]);
				}
			}
			break;
		case IDC_COMBO8:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				ace = GetDlgItem(hDlg, ID_GRAPHICS);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT(""));

				ace = GetDlgItem(hDlg, IDC_COMBO8_1);
				ShowWindow(ace, SW_SHOW);
				ins.graphics_size = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO8_1, CB_RESETCONTENT, 0, 0);
				for (i = 0; i < 2; i++)
					SendDlgItemMessage(hDlg, IDC_COMBO8_1, CB_ADDSTRING, 0, (LPARAM)nvidia_type[i]);
			}


			break;
		case IDC_COMBO8_1:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				ace = GetDlgItem(hDlg, ID_GRAPHICS_RS);
				ShowWindow(ace, SW_SHOW);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT("Rs"));
				EnableWindow(ace, FALSE);
				ace = GetDlgItem(hDlg, ID_GRAPHICS);
				ShowWindow(ace, SW_SHOW);
				EnableWindow(ace, FALSE);
				ins.graphics_type = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (ins.graphics_company == 0)
				{
					if (ins.graphics_size == 0)
					{
						if (ins.graphics_type == 0)
						{
							(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)nvidia_ddr3_price[ins.graphics_size]);
						}
						else if (ins.graphics_type == 1)
						{
							(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)nvidia_ddr5_price[ins.graphics_size]);
						}
					}
					else if (ins.graphics_size == 1)
					{

						if (ins.graphics_type == 0)
						{
							(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)nvidia_ddr3_price[ins.graphics_size]);
						}
						else if (ins.graphics_type == 1)
						{
							(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)nvidia_ddr5_price[ins.graphics_size]);
						}
					}
					else if (ins.graphics_size == 2)
					{

						if (ins.graphics_type == 0)
						{
							(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)nvidia_ddr3_price[ins.graphics_size]);
						}
						else if (ins.graphics_type == 1)
						{
							(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)nvidia_ddr5_price[ins.graphics_size]);
						}
					}
				}
				else
				{
					if (ins.graphics_size == 0)
					{
						if (ins.graphics_type == 0)
						{
							(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)amd_ddr3_price[ins.graphics_size]);
						}
						else if (ins.graphics_type == 1)
						{
							(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)amd_ddr5_price[ins.graphics_size]);
						}
					}
					else if (ins.graphics_size == 1)
					{

						if (ins.graphics_type == 0)
						{
							(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)amd_ddr3_price[ins.graphics_size]);
						}
						else if (ins.graphics_type == 1)
						{
							(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)amd_ddr5_price[ins.graphics_size]);
						}
					}

				}

			}
			break;
		case IDC_COMBO9:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				ace = GetDlgItem(hDlg, ID_HARD);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT(""));
				ace = GetDlgItem(hDlg, IDC_COMBO10);
				ShowWindow(ace, SW_SHOW);
				ins.harddisk_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				SendDlgItemMessage(hDlg, IDC_COMBO10, CB_RESETCONTENT, 0, 0);

				if (ins.harddisk_company == 0)
				{
					for (i = 0; i < 4; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO10, CB_ADDSTRING, 0, (LPARAM)sea_size[i]);
				}
				else if (ins.harddisk_company == 1)
				{
					for (i = 0; i < 2; i++)
						SendDlgItemMessage(hDlg, IDC_COMBO10, CB_ADDSTRING, 0, (LPARAM)to_size[i]);
				}
			}
			break;
		case IDC_COMBO10:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				ace = GetDlgItem(hDlg, ID_HARD_RS);
				ShowWindow(ace, SW_SHOW);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT("Rs"));
				EnableWindow(ace, FALSE);
				ace = GetDlgItem(hDlg, ID_HARD);
				ShowWindow(ace, SW_SHOW);
				ins.harddisk_size = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				if (ins.harddisk_company == 0)
				{
					(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)sea_price[ins.harddisk_size]);
				}
				else if (ins.harddisk_company == 1)
				{
					(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)sea_price[ins.harddisk_size]);
				}

				EnableWindow(ace, FALSE);
			}

			break;
		case IDC_COMBO11:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				ace = GetDlgItem(hDlg, ID_KEY_RS);
				ShowWindow(ace, SW_SHOW);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT("Rs"));
				EnableWindow(ace, FALSE);
				ace = GetDlgItem(hDlg, ID_KEY);
				ShowWindow(ace, SW_SHOW);
				ins.key_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)key_price[ins.key_company]);
				EnableWindow(ace, FALSE);
			}
			break;
		case IDC_COMBO12:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				ace = GetDlgItem(hDlg, ID_MOUSE_RS);
				ShowWindow(ace, SW_SHOW);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT("Rs"));
				EnableWindow(ace, FALSE);
				ace = GetDlgItem(hDlg, ID_MOUSE);
				ShowWindow(ace, SW_SHOW);
				ins.mouse_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)mouse_price[ins.mouse_company]);
				EnableWindow(ace, FALSE);
			}
			break;
		case IDC_COMBO13:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				ace = GetDlgItem(hDlg, ID_CD_RS);
				ShowWindow(ace, SW_SHOW);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT("Rs"));
				EnableWindow(ace, FALSE);
				ace = GetDlgItem(hDlg, ID_CD);
				ShowWindow(ace, SW_SHOW);
				ins.cd_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)cd_price[ins.cd_company]);
				EnableWindow(ace, FALSE);
			}
			break;
		case IDC_COMBO14:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				ace = GetDlgItem(hDlg, ID_SMpaintstruc_RS);
				ShowWindow(ace, SW_SHOW);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT("Rs"));
				EnableWindow(ace, FALSE);
				ace = GetDlgItem(hDlg, ID_SMpaintstruc);
				ShowWindow(ace, SW_SHOW);
				ins.smpaintstruc_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)smpaintstruc_price[ins.smpaintstruc_company]);
				EnableWindow(ace, FALSE);
			}
			break;
		case IDC_COMBO15:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				ace = GetDlgItem(hDlg, ID_CABINET_RS);
				ShowWindow(ace, SW_SHOW);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT("Rs"));
				EnableWindow(ace, FALSE);
				ace = GetDlgItem(hDlg, ID_CABINET);
				ShowWindow(ace, SW_SHOW);
				ins.cabinet_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)cabinet_price[ins.cabinet_company]);
				EnableWindow(ace, FALSE);
			}
			break;
		case IDC_COMBO16:
			if (HIWORD(wParam) == CBN_SELCHANGE)
			{
				ace = GetDlgItem(hDlg, ID_MONITOR_RS);
				ShowWindow(ace, SW_SHOW);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)TEXT("Rs"));
				EnableWindow(ace, FALSE);
				ace = GetDlgItem(hDlg, ID_MONITOR);
				ShowWindow(ace, SW_SHOW);
				ins.monitor_company = SendMessage((HWND)lParam, (UINT)CB_GETCURSEL, (WPARAM)0, (LPARAM)0);
				(TCHAR)SendMessage(ace, WM_SETTEXT, 0, (LPARAM)monitor_price[ins.monitor_company]);
				EnableWindow(ace, FALSE);
			}
			break;
		case ID_CANCEL:
			EndDialog(hDlg, 0);
			proced = false;
			InvalidateRect(shopnd, NULL, TRUE);
			break;
		}
		return(TRUE);
	}return(FALSE);
}
HINSTANCE ha;
BOOL CALLBACK MyDlgProc_Details(HWND hDlg1, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	switch (iMsg)
	{
		TCHAR name[50];
	case WM_PAINT:
		break;
	case WM_INITDIALOG:
		SetFocus(GetDlgItem(hDlg1, ID_ETNAME_D1));
		return(TRUE);
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_OK_D1:
			char str1[255];

			GetDlgItemText(hDlg1, ID_ETNAME_D1, (LPWSTR)str1, 50);
			recpt = true;
			wsprintf(str, TEXT("%s.txt"), str1);
			FILE *fp;
			wcstombs(str1, str, sizeof(str1));
			fopen_s(&fp, str1, "w");

			TCHAR dash[3] = TEXT("--"), cap1[7][15] = { TEXT("Device"), TEXT("Company"), TEXT("Subtype"), TEXT("Generation"), TEXT("Size"),TEXT("Price (Rs)") }, devices[12][20] = { TEXT("CPU"),TEXT("RAM"),TEXT("Motherboard"),TEXT("Graphics Card"),TEXT("HardDisk"),TEXT("Keyboard"),TEXT("Mouse"),TEXT("CD / DVD Drive"),TEXT("SMpaintstruc"),TEXT("Cabinet"),TEXT("Monitor") };
			fprintf_s(fp, "****************************************************************************************************************************************************\n");
			fprintf_s(fp, "											     Thanks For Shopping    \n");
			fprintf_s(fp, "****************************************************************************************************************************************************\n");
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20S\n", cap1[0], cap1[1], cap1[2], cap1[3], cap1[4], cap1[5]);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[0], ins.cpu_company1, ins.cpu_generation1, ins.cpu_architecture1, dash, ins.cpu_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[1], ins.ram_company1, dash, dash, ins.ram_size1, ins.ram_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[2], ins.mother_company1, dash, dash, dash, ins.mother_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[3], ins.graphics_company1, ins.graphics_type1, dash, ins.graphics_size1, ins.graphics_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[4], ins.harddisk_company1, dash, dash, ins.harddisk_size1, ins.harddisk_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[5], ins.key_company1, dash, dash, dash, ins.key_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[6], ins.mouse_company1, dash, dash, dash, ins.mouse_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[7], ins.cd_company1, dash, dash, dash, ins.cd_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[8], ins.smpaintstruc_company1, dash, dash, dash, ins.smpaintstruc_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[9], ins.cabinet_company1, dash, dash, dash, ins.cabinet_price1);
			fprintf_s(fp, "%20S%20S%20S%20S%20S%20d\n", devices[10], ins.monitor_company1, dash, dash, dash, ins.monitor_price1);
			fprintf_s(fp, "****************************************************************************************************************************************************\n");
			fprintf_s(fp, "                                         Amount    =    Rs   %d    \n", sum);
			fprintf_s(fp, "****************************************************************************************************************************************************\n");

			fprintf_s(fp, "                                       ");
			fprintf_s(fp, "****************************************************************************************************************************************************\n");

			fclose(fp);
			fp = NULL;
			EndDialog(hDlg1, 0);
			InvalidateRect(shopnd, NULL, TRUE);
			wsprintf(str, TEXT("Your Receipt file Has Saved with name %S"), str1);
			MessageBox(shopnd, str, TEXT("File"), MB_OK);

			break;
		}
		return(TRUE);
	}return(FALSE);
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg, WPARAM wParam, LPARAM lParam)
{

	//HWND hwndchild;
	PAINTSTRUCT paintstruc;
	HDC hdc, hdcMem;
	HBITMAP bitmap;
	static HBITMAP hBitRect;
	RECT rect;
	switch (iMsg)
	{
	case WM_CREATE:
		break;
	case WM_KEYDOWN:
		switch (LOWORD(wParam))
		{
		case VK_ESCAPE:
			DestroyWindow(hwnd);
			break;
		case VK_SPACE:
			if (proced == false)
			{
				proced = true;
				InvalidateRect(hwnd, NULL, TRUE);
				ha = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);
				DialogBox(ha, MAKEINTRESOURCE(IDD_DIALOG1), hwnd, &MyDlgProc);
			}
			break;
		case 'R':
		case 'r':

			if (bill == true)
				if (recpt == false)
				{
					HINSTANCE ha = (HINSTANCE)GetWindowLong(hwnd, GWL_HINSTANCE);
					DialogBox(ha, MAKEINTRESOURCE(IDD_DETAILS), hwnd, &MyDlgProc_Details);
				}
			break;
		case 'C':
		case 'c':
			if (rest == true)
			{
				bill = false;
				recpt = false;
				proced = false;

				InvalidateRect(shopnd, NULL, TRUE);
			}
			break;
		}
		break;
	case WM_PAINT:
		HDC hdc;
		RECT rect;
		PAINTSTRUCT paintstruc;
		HFONT hFont;
		if (proced == false)
		{
			hdc = BeginPaint(hwnd, &paintstruc);
			GetClientRect(hwnd, &rect);
			SetBkColor(hdc, RGB(0, 0, 0));
			SetTextColor(hdc, RGB(255, 0, 0));

			DrawText(hdc, TEXT("Space to Continue"), -1, &rect, DT_SINGLELINE | DT_BOTTOM | DT_CENTER);

			hFont = CreateFont(40, 0, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
				CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Impact"));
			SelectObject(hdc, hFont);
			SetBkColor(hdc, RGB(0, 0, 0));
			SetTextColor(hdc, RGB(255, 0, 0));
			DrawText(hdc, TEXT("Welcome to Computer Shoppee"), -1, &rect, DT_SINGLELINE | DT_RIGHT);
			DeleteObject(hFont);
			GetWindowRect(hwnd, &rect);
			LoadMyBitmap(TEXT("image2.bmp"), hdc, rect.left, rect.top + 50, rect.right, rect.bottom - 110);
			EndPaint(hwnd, &paintstruc);
		}
		else
		{
			if (bill == false)
			{
				hdc = BeginPaint(hwnd, &paintstruc);
				GetClientRect(hwnd, &rect);
				HBRUSH hBrush;
				hBrush = CreateSolidBrush(RGB(0, 0, 0));
				SelectObject(hdc, hBrush);
				FillRect(hdc, &rect, hBrush);
				EndPaint(hwnd, &paintstruc);
			}
			else if (bill == true)
			{

				hdc = BeginPaint(hwnd, &paintstruc);
				SetBkColor(hdc, RGB(0, 0, 0));
				SetTextColor(hdc, RGB(0, 255, 0));
				SetRect(&rect, 0, 60, 1700, 1500);
				DrawText(hdc, TEXT("==============================================================================================================================================================================="), -1, &rect, DT_SINGLELINE);
				SetTextColor(hdc, RGB(0, 255, 0));
				SetRect(&rect, 0, 110, 1700, 1500);

				DrawText(hdc, TEXT("==============================================================================================================================================================================="), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 0, 570, 1700, 1500);

				DrawText(hdc, TEXT("==============================================================================================================================================================================="), -1, &rect, DT_SINGLELINE);
				hFont = CreateFont(40, 0, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
					CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Impact"));
				SelectObject(hdc, hFont);
				SetTextColor(hdc, RGB(0, 150, 255));
				SetRect(&rect, 500, 20, 800, 200);
				DrawText(hdc, TEXT("Comp Shopee "), -1, &rect, DT_SINGLELINE | DT_CENTER);
				DeleteFont(hFont);
				hFont = NULL;
				hFont = CreateFont(25, 0, 0, 0, FW_DONTCARE, FALSE, TRUE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
					CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Impact"));
				SelectObject(hdc, hFont);
				SetTextColor(hdc, RGB(255, 0, 0));
				SetRect(&rect, 50, 80, 250, 150);
				DrawText(hdc, TEXT("Device"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 80, 475, 150);
				DrawText(hdc, TEXT("Company"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 80, 750, 150);
				DrawText(hdc, TEXT("Subtype"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 80, 900, 150);
				DrawText(hdc, TEXT("Generation"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 80, 1050, 150);
				DrawText(hdc, TEXT("Size"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 80, 1350, 150);
				DrawText(hdc, TEXT("Price"), -1, &rect, DT_SINGLELINE);
				DeleteFont(hFont);
				hFont = NULL;
				hFont = CreateFont(23, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, DEFAULT_CHARSET, OUT_OUTLINE_PRECIS,
					CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, VARIABLE_PITCH, TEXT("Arial"));
				SelectObject(hdc, hFont);
				SetTextColor(hdc, RGB(0, 150, 255));
				SetRect(&rect, 50, 140, 250, 170);
				//cpu
				DrawText(hdc, TEXT("CPU"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 140, 475, 170);
				DrawText(hdc, ins.cpu_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 140, 750, 170);
				DrawText(hdc, ins.cpu_generation1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 140, 900, 170);
				DrawText(hdc, ins.cpu_architecture1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 140, 1050, 170);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 140, 1350, 170);

				wsprintf(str, TEXT("Rs %d.00"), ins.cpu_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//ram
				SetRect(&rect, 50, 180, 250, 270);
				DrawText(hdc, TEXT("RAM"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 180, 475, 270);
				DrawText(hdc, ins.ram_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 180, 750, 270);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 180, 900, 270);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 180, 1050, 270);
				DrawText(hdc, ins.ram_size1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 180, 1350, 270);

				wsprintf(str, TEXT("Rs %d.00"), ins.ram_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//motherboard
				SetRect(&rect, 50, 220, 350, 350);
				DrawText(hdc, TEXT("MotherBoard"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 220, 475, 350);
				DrawText(hdc, ins.mother_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 220, 750, 350);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 220, 900, 350);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 220, 1050, 350);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 220, 1350, 350);

				wsprintf(str, TEXT("Rs %d.00"), ins.mother_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//graphics card
				SetRect(&rect, 50, 260, 450, 420);
				DrawText(hdc, TEXT("Graphics Card"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 260, 475, 420);
				DrawText(hdc, ins.graphics_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 260, 750, 420);
				DrawText(hdc, ins.graphics_type1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 260, 900, 420);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 260, 1050, 420);
				DrawText(hdc, ins.graphics_size1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 260, 1350, 420);

				wsprintf(str, TEXT("Rs %d.00"), ins.graphics_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//hard disc
				SetRect(&rect, 50, 300, 520, 470);
				DrawText(hdc, TEXT("Hard Disk"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 300, 475, 470);
				DrawText(hdc, ins.harddisk_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 300, 750, 470);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 300, 900, 470);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 300, 1050, 470);
				DrawText(hdc, ins.harddisk_size1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 300, 1350, 470);

				wsprintf(str, TEXT("Rs %d.00"), ins.harddisk_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//cd Drive
				SetRect(&rect, 50, 340, 580, 500);
				DrawText(hdc, TEXT("CD / DVD Drive"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 340, 475, 500);
				DrawText(hdc, ins.cd_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 340, 750, 500);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 340, 900, 500);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 340, 1050, 500);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 340, 1350, 500);

				wsprintf(str, TEXT("Rs %d.00"), ins.cd_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//SMpaintstruc
				SetRect(&rect, 50, 380, 620, 540);
				DrawText(hdc, TEXT("SMpaintstruc"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 380, 475, 540);
				DrawText(hdc, ins.smpaintstruc_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 380, 750, 540);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 380, 900, 540);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 380, 1050, 540);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 380, 1350, 540);

				wsprintf(str, TEXT("Rs %d.00"), ins.smpaintstruc_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//Cabinet
				SetRect(&rect, 50, 420, 680, 580);
				DrawText(hdc, TEXT("Cabinet"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 420, 475, 580);
				DrawText(hdc, ins.cabinet_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 420, 750, 580);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 420, 900, 580);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 420, 1050, 580);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 420, 1350, 580);

				wsprintf(str, TEXT("Rs %d.00"), ins.cabinet_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//keyboard
				SetRect(&rect, 50, 460, 720, 620);
				DrawText(hdc, TEXT("Keyboard"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 460, 475, 620);
				DrawText(hdc, ins.key_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 460, 750, 620);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 460, 900, 620);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 460, 1050, 620);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 460, 1350, 620);

				wsprintf(str, TEXT("Rs %d.00"), ins.key_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//mouse
				SetRect(&rect, 50, 500, 760, 650);
				DrawText(hdc, TEXT("Mouse"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 500, 475, 650);
				DrawText(hdc, ins.mouse_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 500, 750, 650);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 500, 900, 650);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 500, 1050, 650);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 500, 1350, 650);

				wsprintf(str, TEXT("Rs %d.00"), ins.mouse_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//monitor
				SetRect(&rect, 50, 540, 800, 660);
				DrawText(hdc, TEXT("Monitor"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 300, 540, 475, 660);
				DrawText(hdc, ins.monitor_company1, -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 505, 540, 750, 660);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 725, 540, 900, 660);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 945, 540, 1050, 660);
				DrawText(hdc, TEXT("-"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 540, 1350, 660);

				wsprintf(str, TEXT("Rs %d.00"), ins.monitor_price1);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);

				//amt
				SetRect(&rect, 50, 590, 900, 700);
				DrawText(hdc, TEXT("Amount To Be Paid"), -1, &rect, DT_SINGLELINE);
				SetRect(&rect, 1120, 590, 1350, 700);

				sum = ins.cpu_price1 + ins.ram_price1 + ins.mother_price1 + ins.graphics_price1 + ins.harddisk_price1 + ins.key_price1 + ins.mouse_price1 + ins.cd_price1 + ins.smpaintstruc_price1 + ins.cabinet_price1 + ins.monitor_price1;

				wsprintf(str, TEXT("Rs %d.00"), sum);
				DrawText(hdc, str, -1, &rect, DT_SINGLELINE);
				if (recpt == false)
				{
					SetTextColor(hdc, RGB(255, 0, 0));
					SetRect(&rect, 300, 610, 1200, 720);
					rest = true;
					DrawText(hdc, TEXT("Press R to get the receipt, C to continue Shoping once again, Esc to Exit !!"), -1, &rect, DT_SINGLELINE);
				}
				else
				{
					SetTextColor(hdc, RGB(255, 0, 0));
					SetRect(&rect, 300, 610, 1200, 720);
					rest = true;
					DrawText(hdc, TEXT("Thank You for visiting!!"), -1, &rect, DT_SINGLELINE);

				}

				DeleteFont(hFont);
				hFont = NULL;
				EndPaint(hwnd, &paintstruc);

			}
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return(DefWindowProc(hwnd, iMsg, wParam, lParam));
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE,LPSTR, int) {

	init_data();
	WNDCLASSEX wndclass;
	HWND hwnd;
	MSG msg;
	TCHAR AppName[] = TEXT("Comp Shoppee");
	wndclass.cbSize = sizeof(WNDCLASSEX);
	wndclass.style = CS_HREDRAW | CS_VREDRAW;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = 0;
	wndclass.lpszClassName = AppName;
	wndclass.lpszMenuName = NULL;
	wndclass.lpfnWndProc = WndProc;
	wndclass.hInstance = hInstance;
	wndclass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);

	RegisterClassEx(&wndclass);
	hwnd = CreateWindow(AppName, TEXT("Comp Shoppee"), WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	if (hwnd == NULL)
	{
		MessageBox(NULL, TEXT("Window not created"), TEXT("Error..."), 0);
		exit(0);
	}
	ha = hInstance;
	shopnd = hwnd;
	ShowWindow(hwnd, SW_MAXIMIZE);
	UpdateWindow(hwnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return((int)msg.wParam);
}



bool LoadMyBitmap(LPCWSTR szFileName, HDC hdc, LONG x, LONG y, LONG width, LONG Bottom)
{
	HBITMAP hBitmap;
	hBitmap = (HBITMAP)LoadImage(NULL, szFileName, IMAGE_BITMAP, 0, 0,
		LR_LOADFROMFILE);

	if (hBitmap == NULL) {
		MessageBox(NULL, TEXT("LoadImage Failed"), TEXT("Error"), MB_OK);
		return false;
	}
	HDC hdcLocal;
	hdcLocal = ::CreateCompatibleDC(hdc);
	if (hdcLocal == NULL) {
		MessageBox(NULL, TEXT("CreateCompatibleDC Failed"), TEXT("Error"), MB_OK);
		return false;
	}

	BITMAP bitmapq;
	int iReturn = GetObject(reinterpret_cast<HGDIOBJ>(hBitmap), sizeof(BITMAP),
		reinterpret_cast<LPVOID>(&bitmapq));
	if (!iReturn) {
		MessageBox(NULL, TEXT("GetObject Failed"), TEXT("Error"), MB_OK);
		return false;
	}

	HBITMAP oldbitmap = (HBITMAP)::SelectObject(hdcLocal, hBitmap);
	if (oldbitmap == NULL) {
		MessageBox(NULL, TEXT("SelectObject Failed"), TEXT("Error"), MB_OK);
		return false;
	}
	LPRECT rect;

	BOOL Blitmap = StretchBlt(hdc, x, y, width, Bottom, hdcLocal, 0, 0, width, Bottom, SRCCOPY);
	if (!Blitmap) {
		MessageBox(NULL, TEXT("Blit Failed"), TEXT("Error"), MB_OK);
		return false;
	}

	::SelectObject(hdcLocal, oldbitmap);
	::DeleteDC(hdcLocal);
	::DeleteObject(hBitmap);
	return true;
}

void init_data() {
	ins.cpu_company = -1;
	ins.cpu_company1[0] = '\0';
	ins.cpu_generation = -1;
	ins.cpu_generation1[0] = '\0';
	ins.cpu_architecture = -1; ins.cpu_architecture1[0] = '\0';
	ins.cpu_price = -1;	ins.cpu_price1 = 0;
	ins.ram_company = -1; ins.ram_company1[0] = '\0';
	ins.ram_size = -1; ins.ram_size1[0] = '\0';
	ins.ram_price = -1; ins.ram_price1 = 0;
	ins.mother_company = -1;  ins.mother_company1[0] = '\0';
	ins.mother_price = -1;  ins.mother_price1 = 0;
	ins.graphics_company = -1;  ins.graphics_company1[0] = '\0';
	ins.graphics_size = -1; ins.graphics_size1[0] = '\0';
	ins.graphics_type = -1; ins.graphics_type1[0] = '\0';
	ins.graphics_price = -1; ins.graphics_price1 = 0;
	ins.key_company = -1; ins.key_company1[0] = '\0';
	ins.key_price = -1;		ins.key_price1 = 0;
	ins.mouse_company = -1; ins.mouse_company1[0] = '\0';
	ins.mouse_price = -1;  ins.mouse_price1 = 0;
	ins.cd_company = -1;   	ins.cd_company1[0] = '\0';
	ins.cd_price = -1;    ins.cd_price = 0;
	ins.smpaintstruc_company = -1;   	ins.smpaintstruc_company1[0] = '\0';
	ins.smpaintstruc_price = -1;	 ins.smpaintstruc_price1 = 0;
	ins.monitor_company = -1;    ins.monitor_company1[0] = '\0';
	ins.monitor_price = -1; ins.monitor_price1 = 0;
	ins.cabinet_company = -1;	ins.cabinet_company1[0] = '\0';
	ins.cabinet_price = -1; ins.cabinet_price1 = 0;
	ins.harddisk_company = -1;  ins.harddisk_company1[0] = '\0';
	ins.harddisk_size = -1; ins.harddisk_size1[0] = '\0';
	ins.harddisk_price = -1; 	ins.harddisk_price1 = 0;
}


