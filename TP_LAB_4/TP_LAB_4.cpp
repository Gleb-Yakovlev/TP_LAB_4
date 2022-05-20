#include <iostream>
#include "safe_input.h"
#include "mega_function.h"
#include "Squaring.h"
using namespace std;

int main()
{
    Squaring<int>* s1 = nullptr;
    Squaring<float>* s2 = nullptr;
    int size1, size2;
    size1 = size2 = 0;
    while (1) {
        cout << "ARRAY" << endl;
        cout << "Int:" << endl;
        if (size1 == 0) cout << "No arrays" << endl;
        else
            for (int i = 0; i < size1; i++) {
                cout << i + 1 << ")" << s1[i] << endl;
            }
        cout << "Float:" << endl;
        if (size2 == 0) cout << "No arrays" << endl;
        else
            for (int i = 0; i < size2; i++) {
                cout << i + 1 << ")" << s2[i] << endl;
            }
        cout << "Select a order" << endl
            << "1 - Create new array" << endl
            << "2 - Add items to the array" << endl
            << "3 - Square the elements" << endl
            << "4 - Calculating the summ" << endl
            << "5 - Calculating the average value" << endl
            << "6 - Add two arrays" << endl
            << "7 - Subtract two arrays" << endl
            << "8 - Compare arrays" << endl
            << "0 - Exit" << endl;
        int order = safe_input();
        switch (order)
        {
        case 1: {
            system("cls");
            cout << "Select the data type" << endl
                << "1 - Int" << endl
                << "2 - Float" << endl;
            int type = 0;
            while (1) {
                type = safe_input();
                switch (type)
                {
                case 1: {
                    if (size1 != 0) {
                        Squaring<int>* old_arr = new Squaring<int>[size1];
                        for (int i = 0; i < size1; i++) old_arr[i] = s1[i];
                        size1++;
                        s1 = new Squaring<int>[size1];
                        for (int i = 0; i < size1-1; i++) s1[i] = old_arr[i];
                    }
                    else { size1++; s1 = new Squaring<int>[size1]; }
                    break;
                }
                case 2: {
                    if (size2 != 0) {
                        Squaring<float>* old_arr = new Squaring<float>[size2];
                        for (int i = 0; i < size2; i++) old_arr[i] = s2[i];
                        size2++;
                        s2 = new Squaring<float>[size2];
                        for (int i = 0; i < size2 - 1; i++) s2[i] = old_arr[i];
                    }
                    else { size2++; s2 = new Squaring<float>[size2]; }
                    break;
                }
                default: break;
                }
                if (type == 1 || type == 2) break;
            }
            system("cls");
            break;
        }
        case 2: {
            cout << "Select the queue type" << endl
                << "1 - Int" << endl
                << "2 - Float" << endl;
            int type = 0;
            while (1) {
                type = safe_input();
                switch (type)
                {
                case 1: {
                    if (size1 < 1) { system("cls"); cout << "Few arrays" << endl; break; }
                    cout << "Select number" << endl;
                    while (1) {
                        int number;
                        number = safe_input();
                        if (number <= size1 && number > -1) {
                            cout << "Enter the values, if you enter incorrectly, the filling of the array will be stop" << endl;
                            cin >> s1[number - 1];
                            break;
                        }
                    }
                    break;
                }
                case 2: {
                    if (size2 < 1) { system("cls"); cout << "Few arrays" << endl; break; }
                    cout << "Select number" << endl;
                    while (1) {
                        int number;
                        number = safe_input();
                        if (number <= size2 + 1 && number > -1) {
                            cout << "Enter the values, if you enter incorrectly, the filling of the array will be stop" << endl;
                            cin >> s2[number - 1];
                            break;
                        }
                    }
                    break;
                }
                default: break;
                }
                break;
            }
            break;
        }
        case 3: {
            cout << "Select the data type" << endl
                << "1 - Int" << endl
                << "2 - Float" << endl;
            int type = 0;
            while (1) {
                type = safe_input();
                switch (type)
                {
                case 1: {
                    if (size1 < 1) { break; }
                    cout << "Select number" << endl;
                    while (1) {
                        int number;
                        number = safe_input();
                        if (number <= size1 + 1 && number > -1) { SQ(s1[number - 1].m_data, s1[number - 1].m_size); break; }
                    }
                    break;
                }
                case 2: {
                    if (size2 < 1) { system("cls"); cout << "Few arrays" << endl; break; }
                    cout << "Select number" << endl;
                    while (1) {
                        int number;
                        number = safe_input();
                        if (number <= size2 + 1 && number > -1) { SQ(s2[number - 1].m_data, s2[number - 1].m_size); break; }
                    }
                    break;
                }
                default: break;
                }
                if (type == 1 || type == 2){system("cls"); break;}
            }
            break;
        }
        case 4: {
            cout << "Select the data type" << endl
                << "1 - Int" << endl
                << "2 - Float" << endl;
            int type = 0;
            while (1) {
                type = safe_input();
                switch (type)
                {
                case 1: {
                    if (size1 < 1) { system("cls"); cout << "Few arrays" << endl; break; }
                    cout << "Select number" << endl;
                    while (1) {
                        int number;
                        number = safe_input();
                        if (number <= size1 + 1 && number > -1) { system("cls"); cout << "Summ = " << s1[number-1].Summ() << endl; break; }
                    }
                    break;
                }
                case 2: {
                    if (size2 < 1) { system("cls"); cout << "Few arrays" << endl; break; }
                    cout << "Select number" << endl;
                    while (1) {
                        int number;
                        number = safe_input();
                        if (number <= size2 + 1 && number > -1) { system("cls"); cout << "Summ = " << s2[number - 1].Summ() << endl; break; }
                    }
                    break;
                }
                default: break;
                }
                if (type == 1 || type == 2) break;
            }
            break;
        }
        case 5: {
            cout << "Select the data type" << endl
                << "1 - Int" << endl
                << "2 - Float" << endl;
            int type = 0;
            while (1) {
                type = safe_input();
                switch (type)
                {
                case 1: {
                    if (size1 < 1) { system("cls"); cout << "Few arrays" << endl; break; }
                    cout << "Select number" << endl;
                    while (1) {
                        int number;
                        number = safe_input();
                        if (number <= size1 + 1 && number > -1) { system("cls"); cout << "Average value = " << s1[number - 1].Aver() << endl; break; }
                    }
                    break;
                }
                case 2: {
                    if (size2 < 1) { system("cls"); cout << "Few arrays" << endl; break; }
                    cout << "Select number" << endl;
                    while (1) {
                        int number;
                        number = safe_input();
                        if (number <= size2 + 1 && number > -1) { system("cls"); cout << "Average value = " << s2[number - 1].Aver() << endl; break; }
                    }
                    break;
                }
                default: break;
                }
                if (type == 1 || type == 2) break;
            }
            break;
        }
        case 6: {
            cout << "Select the data type" << endl
                << "1 - Int" << endl
                << "2 - Float" << endl;
            int type = 0;
            while (1) {
                type = safe_input();
                switch (type)
                {
                case 1: {
                    if (size1 < 2) break;
                    cout << "Select 1 number" << endl;
                    int number1, number2;
                    while (1) {
                        number1 = safe_input();
                        if (number1 <= size1 + 1 && number1 > -1) break;
                    }
                    cout << "Select 2 number" << endl;
                    while (1) {
                        number2 = safe_input();
                        if (number2 <= size1 + 1 && number2 > -1) break;
                    }
                    s1[number1-1] + s1[number2-1];
                    break;
                }
                case 2: {
                    if (size2 < 2) break;
                    cout << "Select 1 number" << endl;
                    int number1, number2;
                    while (1) {
                        number1 = safe_input();
                        if (number1 <= size2 + 1 && number1 > -1) break;
                    }
                    cout << "Select 2 number" << endl;
                    while (1) {
                        number2 = safe_input();
                        if (number2 <= size2 + 1 && number2 > -1) break;
                    }
                    s2[number1 - 1] + s2[number2 - 1];
                }
                default: break;
                }
                if (type == 1 || type == 2) { system("cls"); break; }
            }
            break;
        }
        case 7: {
            cout << "Select the data type" << endl
                << "1 - Int" << endl
                << "2 - Float" << endl;
            int type = 0;
            while (1) {
                type = safe_input();
                switch (type)
                {
                case 1: {
                    if (size1 < 2) break;
                    cout << "Select 1 number" << endl;
                    int number1, number2;
                    while (1) {
                        number1 = safe_input();
                        if (number1 <= size1 + 1 && number1 > -1) break;
                    }
                    cout << "Select 2 number" << endl;
                    while (1) {
                        number2 = safe_input();
                        if (number2 <= size1 + 1 && number2 > -1) break;
                    }
                    s1[number1 - 1] - s1[number2 - 1];
                    break;
                }
                case 2: {
                    if (size2 < 2) break;
                    cout << "Select 1 number" << endl;
                    int number1, number2;
                    while (1) {
                        number1 = safe_input();
                        if (number1 <= size2 + 1 && number1 > -1) break;
                    }
                    cout << "Select 2 number" << endl;
                    while (1) {
                        number2 = safe_input();
                        if (number2 <= size2 + 1 && number2 > -1) break;
                    }
                    s2[number1 - 1] - s2[number2 - 1];
                }
                default: break;
                }
                if (type == 1 || type == 2) { system("cls"); break; }
            }
            break;
        }
        case 8: {
            cout << "Select the data type" << endl
                << "1 - Int" << endl
                << "2 - Float" << endl;
            int type = 0;
            while (1) {
                type = safe_input();
                switch (type)
                {
                case 1: {
                    if (size1 < 2) { system("cls"); cout << "Few arrays" << endl; break; }
                    cout << "Select 1 number" << endl;
                    int number1, number2;
                    while (1) {
                        number1 = safe_input();
                        if (number1 <= size1 + 1 && number1 > -1) { number1--; break; }
                    }
                    cout << "Select 2 number" << endl;
                    while (1) {
                        number2 = safe_input();
                        if (number2 <= size1 + 1 && number2 > -1) { number2--; break; }
                    }
                    if (s1[number1] != s1[number2]) {
                        if (s1[number1] < s1[number2]) { system("cls"); cout << "1 < 2" << endl; }
                        else { system("cls"); cout << "2 < 1" << endl; }
                    }
                    else { system("cls"); cout << "1 = 2" << endl; }
                    break;
                }
                case 2: {
                    if (size2 < 2) { system("cls"); cout << "Few arrays" << endl; break; }
                    cout << "Select 1 number" << endl;
                    int number1, number2;
                    while (1) {
                        number1 = safe_input();
                        if (number1 <= size2 + 1 && number1 > -1) { number1--; break; }
                    }
                    cout << "Select 2 number" << endl;
                    while (1) {
                        number2 = safe_input();
                        if (number2 <= size2 + 1 && number2 > -1) { number2--; break; }
                    }
                    if (s2[number1] != s2[number2]) {
                        if (s2[number1] < s2[number2]) { system("cls"); cout << "1 < 2" << endl; }
                        else { system("cls"); cout << "2 < 1" << endl; }
                    }
                    else { system("cls"); cout << "1 = 2" << endl;}
                    break;
                }
                default: break;
                }
                if (type == 1 || type == 2) break;
            }
            break;
        }
        case 0: return 0;
        default:
            break;
        }
    }
}
