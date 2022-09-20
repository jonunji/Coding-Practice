#include <iostream>
#include <vector>

using namespace std;

template <class T = int>
class Sorting {
public:

    // As we go through our array, the large values "bubble" up
    // Time complexity: worst case   |   best case
    //                    O(n^2)            O(n)
    static void bubble(vector<T> &arr)
    {
        bool swapped = true;

        // If we didn't swap, we break out of the loop
        for (int i = 0; i < arr.size() - 1 && swapped; i++)
        {
            // reset the flag
            swapped = false;

            for (int j = 0; j < arr.size() - 1 - i; j++)
                if (arr[j] > arr[j + 1])
                {
                    swap(arr[j], arr[j + 1]);
                    swapped = true;
                }

        }
    }

    // "Selects" the biggest element and moves it to the top,
    // or the smallest element and puts it at the beginning
    // Time complexity: worst case   |   best case
    //                    O(n^2)           O(n^2)
    static void selection(vector<T> &arr)
    {
        int min;

        for (int i = 0; i < arr.size(); i++)
        {
            min = i;

            for (int j = i; j < arr.size(); j++)
                if (arr[min] > arr[j])
                    min = j;

            swap(arr[min], arr[i]);
        }
    }

    // As we traverse the array, we "insert" the value into its correct spot.
    // We do this by going back until a value is smaller then the one we are inserting.
    static void insertion(vector<T> &arr)
    {
        for (int i = 1; i < arr.size(); i++)
        {
            int val = arr[i];
            int j = i-1;

            // Find something less than our value
            while (j >= 0 && val < arr[j])
                arr[j + 1] = arr[j--];

            arr[j + 1] = val;
        }
    }

private:
    Sorting() {}

};