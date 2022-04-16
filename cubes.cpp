#include <windows.h>

int main(){
    int hSrc; // [rsp+60h] [rbp-10h]
    int wSrc; // [rsp+64h] [rbp-Ch]
    HDC hdcDest; // [rsp+68h] [rbp-8h]
    GetDC(0);
    wSrc = GetSystemMetrics(0);
    for (hSrc = GetSystemMetrics(1);
        ;
        StretchBlt(hdcDest, -10, -10, wSrc + 20, hSrc + 20, hdcDest, 0, 0, wSrc, hSrc, 0xCC0020u))
    {
        hdcDest = GetDC(0);
        (hdcDest, 4);
        StretchBlt(hdcDest, 10, 10, wSrc - 20, hSrc - 20, hdcDest, 0, 0, wSrc, hSrc, 0xCC0020u);
    }
}
