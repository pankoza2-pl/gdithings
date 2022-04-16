#include <windows.h>

int __fastcall CircleInvert2(int a1, int a2, int a3, int a4)
{
    HRGN ho; // [rsp+58h] [rbp-18h]
    HDC hdc; // [rsp+60h] [rbp-10h]

    hdc = GetDC(0);
    ho = CreateEllipticRgn(a1, a2, a1 + a3, a4 + a2);
    BitBlt(hdc, a1, a2, a3, a4, hdc, a1, a2, 0x5A0049u);
    DeleteObject(ho);
    ReleaseDC(0, hdc);
}

int main()
{
    HWND v3; // rax
    struct tagRECT Rect; // [rsp+20h] [rbp-30h] BYREF
    int v6; // [rsp+30h] [rbp-20h]
    int v7; // [rsp+34h] [rbp-1Ch]
    int v8; // [rsp+38h] [rbp-18h]
    int v9; // [rsp+3Ch] [rbp-14h]
    int v10; // [rsp+40h] [rbp-10h]
    int v11; // [rsp+44h] [rbp-Ch]
    int j; // [rsp+48h] [rbp-8h]
    int i; // [rsp+4Ch] [rbp-4h]
    v3 = GetDesktopWindow();
    GetWindowRect(v3, &Rect);
    v11 = Rect.right - Rect.top - 500;
    v10 = Rect.bottom - Rect.top - 500;
    v9 = 0;
    for (i = 0; ; i %= 2)
    {
        v8 = 1000;
        v7 = rand() % (v11 + 1000) - 500;
        v6 = rand() % (v10 + 1000) - 500;
        for (j = 0; j <= 999; j += 100)
            CircleInvert2(v7 - j / 2, v6 - j / 2, j, j);
        Sleep(0x64u);
        if (!i)
            InvalidateRect(0, 0, 0);
        ++i;
    }
}
