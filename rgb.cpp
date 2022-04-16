#include <windows.h>

int main()
{
    HWND v3; // rax
    HBITMAP h; // [rsp+58h] [rbp-38h]
    HDC hdcSrc; // [rsp+60h] [rbp-30h]
    HDC hdc; // [rsp+68h] [rbp-28h]
    void* lpvBits; // [rsp+70h] [rbp-20h]
    int nHeight; // [rsp+78h] [rbp-18h]
    int nWidth; // [rsp+7Ch] [rbp-14h]
    DWORD v12; // [rsp+80h] [rbp-10h]
    int j; // [rsp+84h] [rbp-Ch]
    int v14; // [rsp+88h] [rbp-8h]
    int i; // [rsp+8Ch] [rbp-4h]
    v12 = GetTickCount();
    nWidth = GetSystemMetrics(0);
    nHeight = GetSystemMetrics(1);
    lpvBits = VirtualAlloc(0, 4 * nWidth * (nHeight + 1), 0x3000u, 4u);
    for (i = 0; ; i = (i + 1) % 2)
    {
        hdc = GetDC(0);
        hdcSrc = CreateCompatibleDC(hdc);
        h = CreateBitmap(nWidth, nHeight, 1u, 0x20u, lpvBits);
        SelectObject(hdcSrc, h);
        BitBlt(hdcSrc, 0, 0, nWidth, nHeight, hdc, 0, 0, 0xCC0020u);
        GetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
        v14 = 0;
        if (GetTickCount() - v12 > 0xA)
            rand();
        for (j = 0; nHeight * nWidth > j; ++j)
        {
            if (!(j % nHeight) && !(rand() % 110))
                v14 = rand() % 24;
            *((BYTE*)lpvBits + 4 * j + v14) -= 5;
        }
        SetBitmapBits(h, 4 * nHeight * nWidth, lpvBits);
        BitBlt(hdc, 0, 0, nWidth, nHeight, hdcSrc, 0, 0, 0xCC0020u);
        DeleteObject(h);
        DeleteObject(hdcSrc);
        DeleteObject(hdc);
    }
}
