#include <windows.h>

int main() {
    HDC hdc;

    int w = GetSystemMetrics(0), h = GetSystemMetrics(1), x;
    while(1) {
        hdc= GetDC(0);
        x = rand() % w;
        BitBlt(hdc, x, 1, 10, h, hdc, x, 0, SRCCOPY);
        Sleep(2);
        ReleaseDC(0, hdc);
    }
}
