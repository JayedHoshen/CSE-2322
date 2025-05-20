#include <bits/stdc++.h>
using namespace std;
class user
{
private:
public:
    int capacity = 100;
    int size = 0;
    int arr[100];
    void create()
    {
        arr[capacity];
        cout << "Enter value for array: ";
        while (true)
        {
            int x;
            cin >> x;
            if (x == 0)
                break;
            arr[size] = x;
            cout << "press any button for continue, 0 for Cancel...";
            size++;
        }

        return;
    }
    void traverse()
    {
        cout << "After traverse the array is: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    void insert_at_first(int value)
    {

        for (int i = size; i >= 1; i--)
        {
            arr[i] = arr[i - 1];
        }
        arr[0] = value;
        size++;
        return;
    }
    void insert_at_last(int val)
    {
        if (size + 1 > capacity)
        {
            cout << "Overflow" << endl;
            return;
        }
        arr[size] = val;
        size++;
    }
    void insert_at_any_position(int place, int val)
    {
        if (size + 1 > capacity)
        {
            cout << "Overflow";
            return;
        }
        for (int i = place; i < size; i++)
        {
            arr[i + 1] = arr[i];
        }
        arr[place] = val;
        size++;
    }
    void delete_at_first()
    {

        for (int i = 0; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
        return;
    }
    void delete_at_last()
    {
        if (size <= 0)
        {
            cout << "Underflow" << endl;
            return;
        }
        size--;
    }
    void delete_at_any_position(int place)
    {
        if (size <= 0)
        {
            cout << "Underflow";
            return;
        }
        for (int i = place; i < size; i++)
        {
            arr[i] = arr[i + 1];
        }
        size--;
    }
};
int main()
{
    user obj1;
    obj1.create();
    obj1.traverse();
    obj1.insert_at_first(10);
    obj1.insert_at_last(90);
    obj1.insert_at_any_position(5, 50);
    obj1.traverse();
    obj1.delete_at_first();
    obj1.delete_at_last();
    obj1.delete_at_any_position(5);
    obj1.traverse();

    return 0;
}
