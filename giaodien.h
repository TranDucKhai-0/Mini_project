#ifndef GIAODIEN_H
#define GIAODIEN_H

#include<iostream>
#include<string>
#include<conio.h> // Sử dụng hàm getch()
#include<windows.h>

#define MAUCHU 123 // màu của vị trí thao tác
#define MAUNEN 0 // màu các vị trí còn lại


using namespace std;

// Đặt trạng thái con trỏ
void Cursor(bool logic) {
    // Lấy handle cho cửa sổ console hiện tại
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hConsole == INVALID_HANDLE_VALUE) {
        return; // Thoát nếu không lấy được handle
    }

    // Cấu trúc chứa thông tin về con trỏ console
    CONSOLE_CURSOR_INFO cursorInfo;

    // Lấy thông tin hiện tại của con trỏ
    if (GetConsoleCursorInfo(hConsole, &cursorInfo)) {
        cursorInfo.bVisible = logic; // TRUE bật, FALSE tắt
        SetConsoleCursorInfo(hConsole, &cursorInfo); // Áp dụng thay đổi
    }
}


// hàm tô màu chữ (lấy từ thư viện console.h)
void TextColor(int color)
{
    // Lấy mã màu hiện tại của console
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    
    // Kết hợp màu chữ mới với màu nền hiện tại
    int newColor = (csbi.wAttributes & 0xF0) | (color & 0x0F);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), newColor);
}

// Trạng thái thao tác chọn trong Menu (định nghĩa các thao tác có nghĩa)
enum TRANGTHAI{UP, DOWN, ENTER, NONE};

// Sự kiện nhận từ bàn phím
TRANGTHAI Event(int x) {
    if (x == 224) { // 224 là mã của 4 nút UP, DOWN, LEFT, RIGHT
        char event = getch();
        switch (event) {
            case 72: // 72 là mã của nút UP
                return UP;
            case 80: // 80 là mã của nút DOWN
                return DOWN;
        }
    } else if (x == 13) {  // 13 là mã của nút ENTER
        return ENTER;
    }
    return NONE;
}

int menu(string NameMenu, string Menu[], int n) {
    int thaotac = 0; // biến chỉ vị trí thao tác, =0 là ở vị trí đầu
    int *mau = new int[n]; // cấp phát bộ nhớ cho mảng
    for(int i = 0; i < n; i++) {
        mau[i] = MAUNEN; // tô màu ở các vị trí khác
    }
    mau[0] = MAUCHU; // tô màu ở thao tác vị trí đầu (màu khác so với màu chữ ở các vị trí còn lại)

    while(1) {
        system("cls");

        // in Menu 
        TextColor(MAUNEN); // tô màu cho tên Menu
        cout << "\n\n\t\t\t\t\t" << NameMenu << endl
                        << endl;
        for(int i = 0; i < n; i++) {
            TextColor(mau[i]); // in màu cho chữ
            cout << "\n\n\t\t\t\t\t" << i+1 << ". " << Menu[i];
        }

        int x = getch();
        TRANGTHAI trangthai = Event(x);
        switch(trangthai) {
            case UP:
                if(thaotac == 0)
                    thaotac = n-1; // nếu up khi thao tác ở vị trí đầu thì chuyển xuống dưới cuói
                else
                    thaotac--; // thao tác up
                break;
            case DOWN:
                if(thaotac == n-1)
                    thaotac = 0; // nếu down khi thao tác ở vị trí cuối thì chuyển lên vị trí đầu
                else
                    thaotac++; // thao tác down
                break;
            case ENTER:
                return thaotac + 1;// trả về vị trí đã chọn cộng thêm 1 (vì mảng bắt đầu từ 0, còn chỉ số ta lấy từ 1)
            case NONE:
                break;
        }

        // tô lại màu vị trí thao tác
        for(int i = 0; i < n; i++) {
            mau[i] = MAUNEN; // tô màu các vị trí còn lại
        }
        mau[thaotac] = MAUCHU; // tô màu ở vị trí thao tác (màu khác so với màu chữ ở các vị trí còn lại)
    }
}

#endif

