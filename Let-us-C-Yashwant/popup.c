#include <windows.h>

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR lpCmd, int nShow)
{
    MessageBox(
        NULL,
        "Hello from C!",
        "Simple Popup",
        MB_OK | MB_ICONINFORMATION
    );
    return 0;
}
