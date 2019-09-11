#include <iostream>
#include <string>
#include <array>
#include <vector>

// basic io: print line and accept line
void io()
{
    using namespace std;
    cout << "Hello, C++ newbee, please say hello to me: ";
    string in;
    getline(cin, in);
    cout << in << endl;
}

void char_array_vs_string()
{
    using namespace std;
    char a = 'a';
    cout << "char a: " << a << endl;

    char b[] = "I am a char array string";
    cout << "string b: \"" << b << "\" has size: " << strlen(b) << endl;

    string c = "I am a string string";
    cout << "string c: \"" << c << "\" has size: " << c.size() << endl;
}

void _swap_str(char a[], int size)
{
    for (int i = 0; i < size / 2; i++)
    {
        char temp = a[i];
        a[i] = a[size - i - 1];
        a[size - i - 1] = temp;
    }
}

void swap_str()
{
    char odd[] = "odd";
    std::cout << "before swap: " << odd << std::endl;
    _swap_str(odd, strlen(odd));
    std::cout << "after  swap: " << odd << std::endl;
    char even[] = "even";
    std::cout << "before swap: " << even << std::endl;
    _swap_str(even, strlen(even));
    std::cout << "after  swap: " << even << std::endl;
}

void iterate_vector()
{
    using namespace std;
    vector<int> v = {1, 2, 3, 4, 5};
    cout << "easy and happy way:" << endl;
    cout << "for (auto i : v)\n\ti" << endl;
    for (auto i : v)
        cout << i << endl;
    cout << "\nolder way:" << endl;
    cout << "for (auto i = v.begin(); i != v.end(); ++i)\n\t*i" << endl;
    for (auto i = v.begin(); i != v.end(); ++i)
        cout << *i << endl;
    cout << "\noldest way:" << endl;
    cout << "for (int i = 0; i < v.size(); ++i)\n\tv[i]" << endl;
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
}

int main(int argc, char const *argv[])
{
    io();
    char_array_vs_string();
    swap_str();
    iterate_vector();
    return 0;
}
