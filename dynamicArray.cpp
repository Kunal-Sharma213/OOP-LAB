#include <iostream>
#include <vector>
using namespace std;
// template <class T> // creating template to handle various types of input
// class Vector
// {
// public:
//     T *arr;
//     Vector(int M) // if a floating value is entered as the M, it will comverted to int
//     {
//         arr = new T[M];
//     }
// };
void create_vector(string type, int M)
{
    if (type.compare("int") == 0)
    {
        vector<int> *v = new vector<int>(M);
        if (v)
        {
            cout << "VECTOR OF TYPE " << type << " WITH M " << M << " CREATED\n";
            delete (v);
        }
        else
            cout << "MEMORY NOTE AVAILABLE\n";
    }

    else if (type.compare("long") == 0)
    {
        vector<long> *v = new vector<long>(M);
        if (v)
        {
            cout << "VECTOR OF TYPE " << type << " WITH M " << M << " CREATED\n";
            delete (v);
        }
        else
            cout << "MEMORY NOTE AVAILABLE\n";
    }
    else if (type.compare("float") == 0)
    {
        vector<float> *v = new vector<float>(M);
        if (v)
        {
            cout << "VECTOR OF TYPE " << type << " WITH M " << M << " CREATED\n";
            delete (v);
        }
        else
            cout << "MEMORY NOTE AVAILABLE\n";
    }
    else if (type.compare("double") == 0)
    {
        vector<double> *v = new vector<double>(M);
        if (v)
        {
            cout << "VECTOR OF TYPE " << type << " WITH M " << M << " CREATED\n";
            delete (v);
        }
        else
            cout << "MEMORY NOTE AVAILABLE\n";
    }
    else if (type.compare("char") == 0)
    {
        vector<char> *v = new vector<char>(M);
        if (v)
        {
            cout << "VECTOR OF TYPE " << type << " WITH M " << M << " CREATED\n";
            delete (v);
        }
        else
            cout << "MEMORY NOTE AVAILABLE\n";
    }
    else if (type.compare("string") == 0)
    {
        vector<string> *v = new vector<string>(M);
        if (v)
        {
            cout << "VECTOR OF TYPE " << type << " WITH M " << M << " CREATED\n";
            delete (v);
        }
        else
            cout << "MEMORY NOTE AVAILABLE\n";
    }
    else
    {
        cout << "UNABLE TO IDENTITY THE DATA TYPE " << type << "\n";
    }
}
int main()
{
    char ch = 'y';
    while (ch == 'y')
    {
        cout << "ENTER DATA TYPE AND M\n";
        string type;
        int M;
        while (true)
        {
            if (cin >> type >> M && M > 0)
            {
                create_vector(type, M);
                break;
            }
            else
            {
                cout << "INVALID INPUT TRY AGAIN!!\n";
                cin.clear();              // to clear error flag
                while (cin.get() != '\n') // validates until enter is entered
                    ;
            }
        }
        cout << "-------------------------------------\n";
        fflush(stdin);
        cout << "WANT TO CONTINUE?(y/n)\n";
        cin >> ch;
        cout << "-------------------------------------\n";
    }
}
