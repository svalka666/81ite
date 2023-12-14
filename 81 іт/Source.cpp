#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>

using namespace std;

int countLetterGroups(char* str) {
    int count = 0;
    int i = 0;
    while (str[i] != '\0') {
        // Перевірка поточного символу та двох наступних на належність до 'a', 'b' або 'c'
        if ((str[i] == 'a' || str[i] == 'b' || str[i] == 'c') &&
            (str[i + 1] == 'a' || str[i + 1] == 'b' || str[i + 1] == 'c') &&
            (str[i + 2] == 'a' || str[i + 2] == 'b' || str[i + 2] == 'c')) {
            count++;
            i += 3;
        }
        else {
            i++;
        }
    }
    return count;
}


char* Change(char* str) {
    int len = strlen(str);

    char* tmp = new char[len * 2 + 1];
    char* t = tmp;
    tmp[0] = '\0';

    for (int i = 0; i < len; i++) {
        if ((str[i] == 'a' || str[i] == 'b' || str[i] == 'c') &&
            (str[i + 1] == 'a' || str[i + 1] == 'b' || str[i + 1] == 'c') &&
            (str[i + 2] == 'a' || str[i + 2] == 'b' || str[i + 2] == 'c')) {
            strcat(t, "**");
            t += 2;
            i += 2;
        }
        else {
            *t++ = str[i];
            *t = '\0';
        }
    }

    return tmp;
}


int main() {
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "i: " << countLetterGroups(str) << endl;
    char* dest = Change(str);

    cout << "Modified string: " << dest << endl;

    delete[] dest;
    return 0;
}