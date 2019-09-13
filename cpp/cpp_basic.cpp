#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <map>
#include <unordered_map>
#include <sstream>

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

void iterate_map()
{
    using namespace std;
    map<int, int> m;
    m[1] = 1;
    m[2] = 2;
    m[3] = 3;
    m.insert(pair<int, int>(4, 4));
    m.insert(pair<int, int>(55, 4));
    m.erase(55);
    m.insert(pair<int, int>(4, 44));
    cout << "if 4 in m: " << boolalpha << (m.count(4) ? true : false) << endl;
    cout << "iterate map in happy way:" << endl;
    cout << "for (auto i : m)\n\ti.first, i.second" << endl;
    for (auto i : m)
        cout << "key " << i.first << " => value " << i.second << endl;
}

void iterate_unordered_map()
{
    using namespace std;
    unordered_map<string, string> m;
    m["name"] = "liuximin";
    m["age"] = "99";
    m.insert(pair<string, string>("lover", "flower"));
    cout << "iterate unordered_map m:" << endl;
    for (auto i : m)
        cout << "key " << i.first << " =>" << " value " << i.second << endl;
}

// best way convert to string
template < typename CanToStr >
std::string to_str(const CanToStr & t)
{
    std::ostringstream ss;
    ss << t;
    return ss.str();
}

template < typename MaybeToInt >
int to_int(const MaybeToInt & t)
{
    std::stringstream ss(t);
    int i;
    ss >> i;
    return i;
}

void play_to_str()
{
    using namespace std;
    string str = to_str(3.14e10);
    cout << str << endl;
    str = to_str(0.234e1);
    cout << str << endl;
}

void play_to_int()
{
    using namespace std;
    // best way convert to int
    int i = stoi("2945");
    cout << i << endl;
    i = to_int("2945");
    cout << i << endl;
}

void play_struct()
{
    using namespace std;
    struct address {
        string name;
        string phone;
        string mail_code;
        int city_code;
    };

    address my_home{
        "fei xian",
        "1234567",
        "0539",
        22,
    };
    cout << "print my_home:\n";
    cout << my_home.name << endl;
    cout << my_home.phone << endl;
    cout << my_home.mail_code << endl;
    cout << my_home.city_code << endl;
    my_home.name = "su zhou";
    cout << "print my new home:\n";
    cout << my_home.name << endl;
}

int main(int argc, char const *argv[])
{
    io();
    char_array_vs_string();
    swap_str();
    iterate_vector();
    iterate_map();
    iterate_unordered_map();
    play_to_str();
    play_to_int();
    play_struct();
    return 0;
}
