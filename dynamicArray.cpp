#include <iostream>
using namespace std;
template <class T>
class Vector
{
public:
    T *arr;
    Vector(int size) // if a floating value is entered as the size, it will comverted to int
    {
        arr = new T[size];
    }
};
int main()
{
    char ch = 'y';
    while (ch == 'y')
    {
        cout << "ENTER DATA TYPE AND SIZE\n";
        string type;
        int size;
        while (true)
        {
            if (cin >> type >> size && size > 0)
            {
                if (type.compare("int") == 0)
                {
                    Vector<int> *v = new Vector<int>(size);
                    if (v)
                    {
                        cout << "VECTOR OF TYPE " << type << " WITH SIZE " << size << " CREATED\n";
                        delete (v);
                    }
                    else
                        cout << "MEMORY NOTE AVAILABLE\n";
                    break;
                }

                else if (type.compare("long") == 0)
                {
                    Vector<long> *v = new Vector<long>(size);
                    if (v)
                    {
                        cout << "VECTOR OF TYPE " << type << " WITH SIZE " << size << " CREATED\n";
                        delete (v);
                    }
                    else
                        cout << "MEMORY NOTE AVAILABLE\n";
                    break;
                }
                else if (type.compare("float") == 0)
                {
                    Vector<float> *v = new Vector<float>(size);
                    if (v)
                    {
                        cout << "VECTOR OF TYPE " << type << " WITH SIZE " << size << " CREATED\n";
                        delete (v);
                    }
                    else
                        cout << "MEMORY NOTE AVAILABLE\n";
                    break;
                }
                else if (type.compare("double") == 0)
                {
                    Vector<double> *v = new Vector<double>(size);
                    if (v)
                    {
                        cout << "VECTOR OF TYPE " << type << " WITH SIZE " << size << " CREATED\n";
                        delete (v);
                    }
                    else
                        cout << "MEMORY NOTE AVAILABLE\n";
                    break;
                }
                else if (type.compare("char") == 0)
                {
                    Vector<char> *v = new Vector<char>(size);
                    if (v)
                    {
                        cout << "VECTOR OF TYPE " << type << " WITH SIZE " << size << " CREATED\n";
                        delete (v);
                    }
                    else
                        cout << "MEMORY NOTE AVAILABLE\n";
                    break;
                }
                else if (type.compare("string") == 0)
                {
                    Vector<string> *v = new Vector<string>(size);
                    if (v)
                    {
                        cout << "VECTOR OF TYPE " << type << " WITH SIZE " << size << " CREATED\n";
                        delete (v);
                    }
                    else
                        cout << "MEMORY NOTE AVAILABLE\n";
                    break;
                }
                else
                {
                    cout << "UNABLE TO IDENTITY THE DATA TYPE " << type << "\n";
                    break;
                }
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