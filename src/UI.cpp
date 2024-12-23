#include <UI.h>
#include <ConsoleHandler.h>
#include <iostream>
#include <ctime>

using std::cout;

void UI::DrawBoxBorder(int width, int height, int offsetX, int offsetY) {
    ConsoleHandler::SetColor(ColorCode::DarkGray);

    ConsoleHandler::SetCursorPosition(offsetX, offsetY);
    cout << char(201); // '╔'

    for (int i = 1; i < width - 1; ++i) {
        cout << char(205); // '═'
    }

    cout << char(187); // '╗'

    for (int i = 1; i < height - 1; ++i) {
        ConsoleHandler::SetCursorPosition(offsetX, offsetY + i);
        cout << char(186); // '║'
        ConsoleHandler::SetCursorPosition(offsetX + width - 1, offsetY + i);
        cout << char(186); // '║'
    }

    ConsoleHandler::SetCursorPosition(offsetX, offsetY + height - 1);
    cout << char(200); // '╚'

    for (int i = 1; i < width - 1; ++i) {
        cout << char(205); // '═'
    }

    cout << char(188); // '╝'
}

void UI::DrawTableBorder(int width, int height, int offsetX, int offsetY) {
    ConsoleHandler::SetColor(ColorCode::DarkGray);

    ConsoleHandler::SetCursorPosition(offsetX, offsetY);
    cout << char(218); // '┌'

    for (int i = 1; i < width - 1; ++i) {
        cout << char(196); // '─'
    }

    cout << char(191); // '┐'

    for (int i = 1; i < height - 1; ++i) {
        ConsoleHandler::SetCursorPosition(offsetX, offsetY + i);
        cout << char(179); // '│'
        ConsoleHandler::SetCursorPosition(offsetX + width - 1, offsetY + i);
        cout << char(179); // '│'
    }

    ConsoleHandler::SetCursorPosition(offsetX, offsetY + height - 1);
    cout << char(192); // '└'

    for (int i = 1; i < width - 1; ++i) {
        cout << char(196); // '─'
    }

    cout << char(217); // '┘'
}

void UI::DrawHorizontalLine(int width, int offsetX, int offsetY) {
    ConsoleHandler::SetColor(ColorCode::DarkGray);

    ConsoleHandler::SetCursorPosition(offsetX, offsetY);
    cout << char(195); // '├'
    for (int i = 1; i < width - 2; ++i) cout << char(196); // '─'
    cout << char(180); // '┤'
}

void UI::DrawVerticalLine(int height, int offsetX, int offsetY) {
    ConsoleHandler::SetColor(ColorCode::DarkGray);

    ConsoleHandler::SetCursorPosition(offsetX, offsetY);
    cout << char(194); // '┬'
    ConsoleHandler::SetCursorPosition(offsetX, offsetY + 1);
    int cnt = 0;
    for (int i = 1; i < height - 1; ++i) {
        if (cnt == 4) cout << char(197), cnt = 0; // '┼'
        else cout << char(179); // '│'
        cnt++;
        ConsoleHandler::SetCursorPosition(offsetX, offsetY + i);
    }
    cout << char(193); // '┴'
}

void UI::DisplayTime(int x, int y) {
    time_t currentTime = time(nullptr);
    tm *localTime = localtime(&currentTime);
    char buffer[6];
    sprintf_s(buffer, "%02d:%02d", localTime->tm_hour, localTime->tm_min);
    std::string timeStr = "Time: " + std::string(buffer);

    ConsoleHandler::SetCursorPosition(x, y);
    std::cout << timeStr;
}

void UI::DisplayTitle(const std::string &title, int x, int y) {
    ConsoleHandler::SetColor(ColorCode::LightCyan);
    ConsoleHandler::SetCursorPosition(x, y);
    std::cout << title;
    ConsoleHandler::SetColor(ColorCode::White);
}

void UI::ClearRegion(int startX, int startY, int width, int height) {
    for (int y = startY; y < startY + height; ++y) {
        ConsoleHandler::SetCursorPosition(startX, y);
        for (int x = startX; x < startX + width; ++x) {
            std::cout << ' ';
        }
    }
}
