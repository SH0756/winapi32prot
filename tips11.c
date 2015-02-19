/******************************************************************************
title    : tips11 - �_�C�A���O�x�[�X�A�v���̃X�P���g���@�@�@�@  for win95/NT4.0
compiler : VC++ 5.0
******************************************************************************/
#include<windows.h>
#include"resource.h"

/* �O���[�o���ϐ� */
const char  szClassName[] = "Tips11Class";
const char  szAppName[] = "Tips11";
const char  szAppVer[] = "1.0";
HWND        hDlg;           //���C���_�C�A���O�n���h��
HINSTANCE   hInst;          //�C���X�^���X�n���h��


/*-----------------------------------------------------------------------------
���C���_�C�A���O�v���V�[�W��
-----------------------------------------------------------------------------*/
LRESULT CALLBACK mainDlgProc(HWND hWnd, UINT uMessage, WPARAM wParam, LPARAM lParam){
	switch (uMessage){
		//�E�C���h�E�쐬���̏���
	case WM_INITDIALOG:
		break;

		//���[�U�[���b�Z�[�W����
	case WM_COMMAND:
		switch (LOWORD(wParam)){
			//�I��
		case IDCANCEL:
			DestroyWindow(hWnd);
			break;

		default:
			return DefWindowProc(hWnd, uMessage, wParam, lParam);
		}
		break;

		//[X]�{�^��
	case WM_CLOSE:
		PostMessage(hWnd, WM_COMMAND, IDCANCEL, 0);
		break;

		//�v���O�����I�����̃E�C���h�E�j��
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

	//���C���E�C���h�E�N���X�̓o�^
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
		MessageBox(NULL, "�E�C���h�E�N���X��o�^�ł��܂���ł���",
			szAppName, MB_APPLMODAL | MB_ICONSTOP);
		return FALSE;
	}

	//���C���E�C���h�E�̐���
	if ((hDlg = CreateDialog(hInst, MAKEINTRESOURCE(IDD_DIALOG1), 0, mainDlgProc)) == NULL)
	{
		MessageBox(NULL, "���C���E�C���h�E���쐬�ł��܂���ł���",
			szAppName, MB_APPLMODAL | MB_ICONSTOP);
		return FALSE;
	}

	//���C���E�C���h�E�̕\��
	ShowWindow(hDlg, nCmdShow);
	UpdateWindow(hDlg);

	//���b�Z�[�W���[�v
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