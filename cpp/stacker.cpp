// testing the Stack class
#include <iostream>
#include <cctype>
#include "stack.h"

int main(int argc, char const *argv[])
{
    using namespace std;
    // create an empty Stack
    Stack st;
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        while (cin.get() != '\n')
            continue;
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch(ch)
        {
            case 'A':
            case 'a': cout << "Enter a PO number to add: ";
                      cin >> po;
                      if (st.isfull())
                          cout << "stack already full\n";
                      else
                          st.push(po);
                      break;
                      case 'P':
                      case 'p': if (st.isempty())
                                    cout << "stack alread empty\n";
                                else
                                {
                                    st.pop(po);
                                    cout << "PO #" << po << " popped\n";
                                }
                                break;
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}