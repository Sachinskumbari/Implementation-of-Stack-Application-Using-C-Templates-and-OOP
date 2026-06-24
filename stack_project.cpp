#include <iostream>
using namespace std;

/***************** Colour Codes ********************/

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define CYAN "\033[1;36m"
#define MAGNETA "\033[1;35m"
#define RESET "\033[0m"

/************************************Stack class***************************************/

#define max_size 5
template <class Type>
class Stack
{
    static int TOP;
    Type stk[max_size];

public:
    Stack()
    {
        TOP = -1;
    }

    void push(Type ele)
    {
        if (TOP >= max_size - 1)
            cout << RED << "Stack Overflow" << RESET << endl;
        else
        {
            stk[++TOP] = ele;
            cout << GREEN << "Element Pushed Successfuly" << RESET << endl;
        }
    }

    void pop()
    {
        if (TOP == -1)
            cout << RED << "Stack Underflow" << RESET << endl;
        else
        {
            cout << GREEN << "Popped Element : " << stk[TOP--] << RESET << endl;
        }
    }

    void display()
    {
        if (TOP == -1)
            cout << "Stack is Empty" << endl;
        else
        {
            cout << "Stack Elements(top to bottom) :" << endl;
            for (int i = TOP; i >= 0; i--)
                cout << " [" << i << "] " << stk[i] << endl;
        }
    }

    bool isEmpty()
    {
        return TOP == -1;
    }

    int getTop()
    {
        return TOP;
    }
};

template <class Type>
int Stack<Type>::TOP;

/**********************************Wrong option Handling***************************************/

int wrongCount = 0;

void resetWrongCount()
{
    wrongCount = 0;
}

bool handlewrongoption()
{
    wrongCount++;
    if (wrongCount == 1)
        cout << RED << "Please read the options carefully" << RESET << endl;
    else if (wrongCount == 2)
        cout << RED << "Last chance please take care" << RESET << endl;
    else
    {
        cout << RED << "Thanks for using our application, Please read the manual and come back properly" << RESET << endl;
        return false;
    }
    return true;
}

/************************** Sub Menu and calling of methods of class Stack **********************/

template <class Type>
void subMenu(Stack<Type> &s)
{
    int subchoice;
    while (true)
    {
        cout << CYAN;
        cout << "Stack Sub Menu options :" << endl;
        cout << "1.push" << endl;
        cout << "2.pop" << endl;
        cout << "3.display" << endl;
        cout << "4.Main Menu" << endl;
        cout << RESET;
        cout << "Enter the choice" << endl;
        cin >> subchoice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            if (!handlewrongoption())
                return;
            continue;
        }

        switch (subchoice)
        {
        case 1:
        {
            resetWrongCount();
            Type val;
            cout << GREEN << "Enter the element to push : " << RESET;
            cin >> val;
            s.push(val);
            break;
        }
        case 2:
            resetWrongCount();
            s.pop();
            break;
        case 3:
            resetWrongCount();
            s.display();
            break;
        case 4:
            resetWrongCount();
            return;
        default:
            if (!handlewrongoption())
            {
                resetWrongCount();
                return;
            }
        }
    }
}

/*************************************** Pointers creation *****************************************/

Stack<int> *intStack = nullptr;
Stack<char> *charStack = nullptr;
Stack<float> *floatStack = nullptr;
Stack<double> *doubleStack = nullptr;
Stack<string> *stringStack = nullptr;

/************************************* Creation of Object **************************************/

template <class Type>
void handleStack(Stack<Type> *&stackPtr, const string &typeName)
{
    if (stackPtr != NULL)
    {
        int ch;
        cout << YELLOW << "A " << typeName << " Stack already exists. Choose to :" << endl;
        cout << "1.Continue with Old Satck" << endl;
        cout << "2.Create New Stack" << RESET << endl;
        cout << "Enter the choice : ";
        cin >> ch;
        if (ch == 2)
        {
            delete stackPtr;
            stackPtr = new Stack<Type>();
            cout << GREEN << "New " << typeName << " Stack created" << RESET << endl;
        }
        else
        {
            cout << GREEN << "continuing with the existing " << typeName << " Stack" << RESET << endl;
        }
    }
    else
    {
        stackPtr = new Stack<Type>();
        cout << GREEN << typeName << " Stack application is ready to use" << RESET << endl;
    }
    subMenu(*stackPtr);
}

/************************************** Main() function *******************************************/

int main()
{
    int choice;
    while (true)
    {
        cout << MAGNETA;
        cout << "Stack Main Menu options : " << endl;
        cout << "1.int" << endl;
        cout << "2.char" << endl;
        cout << "3.float" << endl;
        cout << "4.double" << endl;
        cout << "5.string" << endl;
        cout << "6.exit" << endl;
        cout << RESET;
        cout << "Enter the choice : ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(10000, '\n');
            if (!handlewrongoption())
                return 0;
            continue;
        }

        switch (choice)
        {
        case 1:
            resetWrongCount();
            handleStack(intStack, "int");
            break;
        case 2:
            resetWrongCount();
            handleStack(charStack, "char");
            break;
        case 3:
            resetWrongCount();
            handleStack(floatStack, "float");
            break;
        case 4:
            resetWrongCount();
            handleStack(doubleStack, "double");
            break;
        case 5:
            resetWrongCount();
            handleStack(stringStack, "string");
            break;
        case 6:
            goto EXIT;
        default:
            if (!handlewrongoption())
                goto EXIT;
        }
    }

EXIT:
    delete intStack;
    delete charStack;
    delete floatStack;
    delete doubleStack;
    delete stringStack;
    cout << GREEN << "Terminating Good Bye\n"
         << RESET;
    return 0;
}