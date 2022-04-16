#include <windows.h>

int main() {
    HDC dc;

    int w = GetSystemMetrics(0), h = GetSystemMetrics(1), x;
    while(1) {
        dc= GetDC(0);
        x = rand() % w;
        BitBlt(dc, x, 1, 10, h, dc, x, 0, SRCCOPY);
        Sleep(2);
    }
}
