/**
 * @file Exercise-2_pmacdonald1.cpp
 * @author Phillip Macdonald
 * @date 2026-22-11
 * @brief Translate Morse Code to english and english to Morse Code.
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Morse {
private:
    vector<string> codes = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....",
        "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.",
        "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-",
        "-.--", "--.."
    };

public:
    string getCode(char letter);
    char getLetter(string symbol);
};

string Morse::getCode(char letter) {
    if (letter >= 'a' && letter <= 'z') {
        letter = letter - 32;
    }

    if (letter >= 'A' && letter <= 'Z') {
        return codes[letter - 'A'];
    }

    return "";
}

char Morse::getLetter(string symbol) {
    for (int i = 0; i < codes.size(); i++) {

        if (codes[i] == symbol) {
            return 'A' + i;
        }
    }

    return '?';
}


class EngTrans {
private:
    Morse mc;

public:
    void convert(string sent);
};


void EngTrans::convert(string sent) {
    cout << endl;
    cout << "Translated Morse Code: " << endl;

    for (int i = 0; i < sent.length(); i++) {
        if ((sent[i] >= 'A' && sent[i] <= 'Z') || (sent[i] >= 'a' && sent[i] <= 'z')) {
            cout << mc.getCode(sent[i]) << " ";
        }
    }

    cout << endl;
}


class MorseTrans {
private:
    Morse mc;
    void printLet(string &symbol);

public:
    void convert(string in);
};

void MorseTrans::printLet(string &symbol) {
    if (symbol != "") {
        cout << mc.getLetter(symbol);
        symbol = "";
    }
}

void MorseTrans::convert(string in) {
    string symbol = "";

    cout << endl;
    cout << "Translated English:" << endl;

    for (int i = 0; i < in.length(); i++) {

        if (in[i] == ' ') {
            printLet(symbol);
        }
        else if (in[i] == '/') {
            printLet(symbol);
            cout << " ";
        }
        else {
            symbol += in[i];
        }
    }
    printLet(symbol);
    cout << endl;
}


class App {
private:
    EngTrans eng;
    MorseTrans morse;
    int getMenu();
    void engOption();
    void morseOption();

public:
    void run();
};

int App::getMenu() {
    string in;

    cout << endl;
    cout << "--- Morse Code Translator ---" << endl;
    cout << "1. English to Morse Code" << endl;
    cout << "2. Morse Code to English" << endl;
    cout << "3. Exit" << endl;
    cout << "Select an option: ";
    getline(cin, in);

    if (in == "1") {
        return 1;
    }

    if (in == "2") {
        return 2;
    }

    if (in == "3") {
        return 3;
    }

    return 0;
}

void App::engOption() {
    string sent;

    cout << endl;
    cout << "Enter a sentence (maximum 50 characters): ";
    getline(cin, sent);

    if (sent.length() > 50) {
        cout << "Sentence is too long. Try again." << endl;
        return;
    }

    eng.convert(sent);
}

void App::morseOption() {
    string in;

    cout << endl;
    cout << "Enter Morse Code (spaces between letters, / between words): ";
    getline(cin, in);

    morse.convert(in);
}

void App::run() {
    int ch = 0;

    while (ch != 3) {
        ch = getMenu();

        if (ch == 1) {
            engOption();
        }
        else if (ch == 2) {
            morseOption();
        }
        else if (ch == 3) {
            cout << endl;
            cout << "Thanks for using the translator!" << endl;
        }
        else {
            cout << endl;
            cout << "Invalid selection. Please try again." << endl;
        }
    }
}


int main() {
    App app;
    app.run();
    return 0;
}