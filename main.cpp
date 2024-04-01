#include <windows.h>

int main() {
    system("echo set game resolution in FHD + windowed + fill and then");
    system("pause");

    DEVMODE dm;
    dm.dmSize = sizeof(dm);
    dm.dmPelsWidth = 1440;
    dm.dmPelsHeight = 1080;
    dm.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;
    ChangeDisplaySettings(&dm, CDS_FULLSCREEN);

    HWND hWnd = FindWindow(NULL, "VALORANT  ");
    LONG style = GetWindowLong(hWnd, GWL_STYLE);

    style &=
        ~(WS_DLGFRAME |
          WS_BORDER);  // logical delete "WS_DLGFRAME", "WS_BORDER" from style

    SetWindowLong(hWnd, GWL_STYLE, style);
    ShowWindow(hWnd, SW_MAXIMIZE);

    system("pause");
    ChangeDisplaySettings(NULL, 0);  // reset display

    return 0;
}