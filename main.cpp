#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

void my_insert(char str[], int pos, int n, char c)
{
    int len = 0;

    while (str[len] != '\0')
        len++;

    for (int i = len; i >= pos; i--)
        str[i + n] = str[i];

    for (int i = 0; i < n; i++)
        str[pos + i] = c;
}

void task1()
{
    char str1[100];
    string str2;

    cout << "Enter string: ";
    cin >> str1;

    str2 = str1;

    my_insert(str1, 2, 3, '*');
    str2.insert(2, 3, '*');

    cout << "My function result: " << str1 << endl;
    cout << "String method result: " << str2 << endl;
}

bool isValid(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (!isdigit(s[i]))
            return false;
    }

    return true;
}

string toBinary(string s)
{
    int num = stoi(s);

    if (num == 0)
        return "0";

    string result = "";

    while (num > 0)
    {
        result = char('0' + num % 2) + result;
        num /= 2;
    }

    return result;
}

void task2()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    if (!fin)
    {
        cout << "File input.txt not found!" << endl;
        return;
    }

    string line;

    while (getline(fin, line))
    {
        if (isValid(line))
        {
            string bin = toBinary(line);
            fout << bin << endl;
        }
    }

    fin.close();
    fout.close();

    cout << "Result written to output.txt" << endl;
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1 - Task 1 (insert)\n";
        cout << "2 - Task 2 (decimal -> binary)\n";
        cout << "0 - Exit\n";
        cout << "Your choice: ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            task1();
            break;

        case 2:
            task2();
            break;
        }

    } while (choice != 0);

    return 0;
}
