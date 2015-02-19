/******************************************************************************
title    : tips11 - ダイアログベースアプリのスケルトン　　　　  for win95/NT4.0
compiler : VC++ 5.0
******************************************************************************/
#include<windows.h>
#include"resource.h"

/* グローバル変数 */
const char  szClassName[] = "Tips11Class";
const char  szAppName[] = "Tips11";
const char  szAppVer[] = "1.0";
HWND        hDlg;           //メインダイアログハンドル
HINSTANCE   hInst;          //インスタンスハンドル


/*-----------------------------------------------------------------------------
メインダイアログプロシージャ
-----------------------------------------------------------------------------*/
LRESULT CALLBACK mainDlgProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam){
	switch (uMessage){
		//ウインドウ作成時の処理
	case WM_INITDIALOG:
		break;

		//ユーザーメッセージ処理
	case WM_COMMAND:
		switch (LOWORD(wParam)){
			//終了
		case IDCANCEL:
			DestroyWindow(hWnd);
			break;

		default:
			return DefWindowProc(hWnd, uMessage, wParam, lParam);
		}
		break;

		//[X]ボタン
	case WM_CLOSE:
		PostMessage(hWnd, WM_COMMAND, IDCANCEL, 0);
		break;

		//プログラム終了時のウインドウ破棄
	case WM_DESTROY:
		PostQuitMessage(0);
		break;

	default:
		return DefWindowProc(hWnd, uMessage, wParam, lParam);
	}//switch end

	return 0;
}


/*=============================================================================
WinMain
=============================================================================*/
int APIENTRY WinMain(HINSTANCE hInstCurrent, HINSTANCE hinstPrevious, LPSTR lpszCmdLine, int nCmdShow)
{
	MSG             msg;
	WNDCLASS        wndclass;

	hInst = hInstCurrent;

	//メインウインドウクラスの登録
	wndclass.style = 0;
	wndclass.lpfnWndProc = mainDlgProc;
	wndclass.cbClsExtra = 0;
	wndclass.cbWndExtra = DLGWINDOWEXTRA;
	wndclass.hInstance = hInst;
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);
	wndclass.hbrBackground = (HBRUSH)(COLOR_BTNFACE + 1);
	wndclass.lpszMenuName = NULL;
	wndclass.lpszClassName = szClassName;
	if (RegisterClass(&wndclass) == 0)
	{
		MessageBox(NULL, "ウインドウクラスを登録できませんでした",
			szAppName, MB_APPLMODAL | MB_ICONSTOP);
		return FALSE;
	}

	//メインウインドウの生成
	if ((hDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, mainDlgProc)) == NULL)
	{
		MessageBox(NULL, "メインウインドウを作成できませんでした",
			szAppName, MB_APPLMODAL | MB_ICONSTOP);
		return FALSE;
	}

	//メインウインドウの表示
	ShowWindow(hDlg, nCmdShow);
	UpdateWindow(hDlg);

	//メッセージループ
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (IsDialogMessage(hDlg, &msg) == FALSE)
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}