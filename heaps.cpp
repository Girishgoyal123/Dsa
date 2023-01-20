#include <iostream>
using namespace std;
class Node
{
public:
    int key;
    int p;
    Node(int n = 0, int pri = 0)
    {
        key = n;
        p = pri;
    }
};
class heap
{
public:
    Node arr[50];
    int size;
    heap()
    {
        arr[0].key = -1;
        arr[0].p = -1;
        size = 0;
    }
    void insert(int x, int pri)
    {
        if (size == 50)
            throw "Heap Full";
        Node t(x, pri);
        arr[++size] = t;
        int i = size;
        while (i > 1)
        {
            int p = i / 2;
            if (arr[p].p < arr[i].p)
            {
                swap(arr[p], arr[i]);
                i = p;
            }
            else
                return;
        }
    }
    void delete_root()
    {
        if (size == 0)
            throw "Empty Heap";

        arr[1] = arr[size--];

        int i = 1;
        while (i < size)
        {
            int l_child_ind = 2 * i;
            int r_child_ind = 2 * i + 1;
            if (l_child_ind < size && arr[i].p < arr[l_child_ind].p)
            {
                swap(arr[i], arr[l_child_ind]);
                i = l_child_ind;
            }
            else if (r_child_ind < size && arr[i].p < arr[r_child_ind].p)
            {
                swap(arr[i], arr[r_child_ind]);
                i = r_child_ind;
            }
            else
                return;
        }
    }

    void display()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i].key << " ";
        }
        cout << endl;
    }
};
int main()
{
    heap h;
    h.insert(20, 2);
    h.insert(1, 1);
    h.insert(4, 4);
    h.insert(7, 7);
    h.insert(16, 16);
    h.insert(23, 23);
    h.insert(12, 12);
    h.insert(2, 20);
    // h.delete_root();
    h.display();
}