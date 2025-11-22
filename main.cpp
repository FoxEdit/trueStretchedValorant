#include <windows.h>
#include <iostream>

int main() {
    SetConsoleTitle("VALORANT True Stretch Tool");

    int width = 0;
    int height = 0;
    int choice = 0;

    std::cout << "==========================================" << std::endl;
    std::cout << "       VALORANT TRUE STRETCH TOOL         " << std::endl;
    std::cout << "==========================================" << std::endl;
    std::cout << "Select your monitor/target resolution:" << std::endl;
    std::cout << "(All options are optimized for HQ, ratio > 1.45)" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "1. Full HD (1080p) -> Set to 1568 x 1080" << std::endl;
    std::cout << "2. 2K QHD  (1440p) -> Set to 2096 x 1440" << std::endl;
    std::cout << "3. 4K UHD  (2160p) -> Set to 3136 x 2160" << std::endl;
    std::cout << "------------------------------------------" << std::endl;
    std::cout << "Enter your choice (1-3): ";
    std::cin >> choice;

    switch (choice) {
    case 1: // FHD
        width = 1568;
        height = 1080;
        break;
    case 2: // 2K
        width = 2096;
        height = 1440;
        break;
    case 3: // 4K
        width = 3136;
        height = 2160;
        break;
    default:
        std::cout << "\n[ERROR] Invalid choice. Please restart the program." << std::endl;
        system("pause");
        return 1;
    }

    std::cout << "\n[IMPORTANT] Prerequisites before continuing:" << std::endl;
    std::cout << "1. You MUST add this resolution to your system first (e.g., via NVIDIA Control Panel)." << std::endl;
    std::cout << "2. In-game settings: Set Display Mode to 'Windowed' and Aspect Ratio Method to 'Fill'." << std::endl;
	
    std::cout << "Press any key to APPLY the stretch..." << std::endl;
    system("pause > nul");

    // resulution settings
    DEVMODE dm;
    memset(&dm, 0, sizeof(dm));
    dm.dmSize = sizeof(dm);
    dm.dmPelsWidth = width;
    dm.dmPelsHeight = height;
    dm.dmFields = DM_PELSWIDTH | DM_PELSHEIGHT;

    long result = ChangeDisplaySettings(&dm, CDS_FULLSCREEN);

    if (result != DISP_CHANGE_SUCCESSFUL) {
        std::cout << "[ERROR] Failed to change resolution. Error code: " << result << std::endl;
        system("pause");
        return 1;
    }

    // find valorant window
	HWND hWnd = FindWindow(NULL, "VALORANT  ");
    if (!hWnd) hWnd = FindWindow(NULL, "VALORANT");

    if (hWnd) {
        LONG style = GetWindowLong(hWnd, GWL_STYLE);

        // logical delete "WS_DLGFRAME", "WS_BORDER" from style and apply
        style &= ~(WS_DLGFRAME | WS_BORDER);
        SetWindowLong(hWnd, GWL_STYLE, style);
        
        // Force maximize
        ShowWindow(hWnd, SW_MAXIMIZE);
        
        std::cout << "\n>>> SUCCESS! Resolution " << width << "x" << height << " applied." << std::endl;
    }
    else {
        std::cout << "\n[WARNING] Resolution changed, but VALORANT window was not found." << std::endl;
        std::cout << "Make sure the game is running." << std::endl;
    }

    std::cout << "\n------------------------------------------" << std::endl;
    std::cout << "        DO NOT CLOSE THIS WINDOW          " << std::endl;
    std::cout << "   Press ENTER here to revert settings    " << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    // clear input buffer to prevent accidental closing
    std::cin.ignore(1000, '\n'); 
    std::cin.get();

    // reset
    ChangeDisplaySettings(NULL, 0);
    std::cout << "Resolution reverted to default." << std::endl;
    
    Sleep(1000); 
    return 0;
}