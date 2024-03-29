#include <windows.h>
#include <windowsx.h>

int main(){
	while(1){
		int w = GetSystemMetrics(0), h = GetSystemMetrics(1);
		HDC hdc = GetDC(0);
		HPEN hPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN hOldPen = SelectPen(hdc, hPen);
	
		HBRUSH hBrush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH hOldBrush = SelectBrush(hdc, hBrush);
		
		POINT vertices[] = { {rand() % w, rand() % h}, {rand() % w, rand() % h}, {rand() % w, rand() % h} };
		Polygon(hdc, vertices, sizeof(vertices) / sizeof(vertices[0]));
		
		SelectBrush(hdc, hOldBrush);
		DeleteObject(hBrush);
		
		SelectPen(hdc, hOldPen);
		DeleteObject(hPen);
		ReleaseDC(0,hdc);
	}
}
