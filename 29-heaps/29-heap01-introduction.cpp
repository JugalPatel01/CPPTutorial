/*

    * Heaps
    -> A Heap is a special Tree-based data structure in which the tree is a complete binary tree.
    -> if 'i' is a parent node in heap then '2*i + 1' is left child and '2*i + 2' is right child.
    -> insertion and deletion of elements take O(log N) time in heaps.

    types of heaps:
    1) Min heap
    2) Max heap
    3) Min-max heap
    4) binomail heap
    5) fibonacci heap
    6) Leftlist heap
    7) K-ary heap

    1) Min heap
    -> if root of the tree is smallest in the rest of the elements in its subtree for all elements in the tree then it's min heap

                    1
                   / \
                  2   3
                 / \ / \
                4  6 5  7

    2) Max heap
    -> if root of the tree is greatest in the rest of the elements in its subtree for all elements in the tree then it's max heap


                    6
                   / \
                  5   4
                 / \ / \
                1  3 3  2

    * covert an array to max-heap
    -> [10 15 21 30 ]

        10    ->      10    ->    15     ->     15      ->      21    ->
                     /           /             / \             / \
                    15          10            10  21          10 15


     ->        21       ->       21         ->       30
              / \               / \                 / \
             10 15             30 15               21 15
            /                 /                   /
           30                10                  10

    * poping out element from heap
    in max heap or min heap we can pop only root element so

    ->       30     ->       10     ->      15
            / \             / \             / \
           21 15           21 15           21 10
          /
         10

*/

#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class MaxHeap
{
    int *arr;
    int maxSize;
    int heapSize;

public:
    MaxHeap(int size)
    {
        heapSize = 0;
        maxSize = size;
        arr = new int[maxSize];
    }

    int parent(int i)
    {
        if (i == 0)
        {
            cout << "it's a root node." << endl;
            return 0;
        }
        return (i - 1) / 2;
    }

    int lChild(int i)
    {
        return 2 * i + 1;
    }

    int rChild(int i)
    {
        return 2 * i + 2;
    }

    int getMax()
    {
        if (heapSize == 0)
        {
            cout << "no element in heap" << endl;
            return -1;
        }
        return arr[0];
    }

    int curSize()
    {
        return heapSize;
    }

    void insertKey(int x)
    {
        if (heapSize == maxSize)
        {
            cout << "overflow : <<<" << endl;
            return;
        }
        // insert element at last
        int i = heapSize;
        arr[i] = x;
        heapSize++;

        // restoring heap
        while (i != 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void increaseKey(int i, int newVal)
    {
        arr[i] = newVal;
        while (i != 0 && arr[i] > arr[parent(i)])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    void deleteKey(int i)
    {
        increaseKey(i, INT_MAX);
        removeMax();
    }

    void MaxHeapify(int i)
    {
        int l = lChild(i);
        int r = rChild(i);
        int largest = i;

        if (l < heapSize && arr[l] > arr[i])
        {
            largest = l;
        }
        if (r < heapSize && arr[r] > arr[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            MaxHeapify(largest);
        }
        return;
    }

    int removeMax()
    {
        if (heapSize <= 0)
        {
            cout << "Underflow :<<" << endl;
            return -1;
        }
        if (heapSize == 1)
        {
            heapSize--;
            return arr[heapSize];
        }

        int root = arr[0];
        heapSize--;
        arr[0] = arr[heapSize];

        MaxHeapify(0);
        return root;
    }
};

int main()
{
    MaxHeap h(15);
    cout << "enter total no. of elements : ";
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        h.insertKey(x);
    }

    cout << "size of the heap is : " << h.curSize() << endl;

    cout << "current max element is : " << h.getMax() << endl;

    cout << "removing max element from the heap : " << h.removeMax() << endl;

    cout << "The current size of the heap is : " << h.curSize() << endl;

    return 0;
}