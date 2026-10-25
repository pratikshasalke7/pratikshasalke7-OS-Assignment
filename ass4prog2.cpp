#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a[20], n, head, i, j, temp;
    int total, pos, min, size;
    int visited[20] = {0};

    cout << "Enter number of requests: ";
    cin >> n;

    cout << "Enter disk requests: ";
    for(i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter head position: ";
    cin >> head;

    cout << "Enter total disk size: ";
    cin >> size;

    // 1. FCFS (First-Come, First-Served)
    total = 0;
    temp = head;

    for(i = 0; i < n; i++)
    {
        total += abs(temp - a[i]);
        temp = a[i];
    }

    cout << "\nFCFS Head Movement = " << total << endl;

    // 2. SSTF (Shortest Seek Time First)
    total = 0;
    temp = head;
    
    // Reset visited array
    for(i = 0; i < n; i++)
    {
        visited[i] = 0;
    }

    for(i = 0; i < n; i++)
    {
        min = 9999;
        pos = -1;
        for(j = 0; j < n; j++)
        {
            if(visited[j] == 0 && abs(temp - a[j]) < min)
            {
                min = abs(temp - a[j]);
                pos = j;
            }
        }
        visited[pos] = 1;
        total += abs(temp - a[pos]);
        temp = a[pos];
    }

    cout << "SSTF Head Movement = " << total << endl;

    // Sort requests for SCAN and C-SCAN
    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(a[i] > a[j])
            {
                int x = a[i];
                a[i] = a[j];
                a[j] = x;
            }
        }
    }

    // 3. SCAN (Moving Right First)
    total = 0;
    temp = head;

    for(i = 0; i < n; i++)
    {
        if(a[i] >= head)
        {
            total += abs(temp - a[i]);
            temp = a[i];
        }
    }
    // Go to the end of the disk if not already there
    total += abs((size - 1) - temp);
    temp = size - 1;

    for(i = n - 1; i >= 0; i--)
    {
        if(a[i] < head)
        {
            total += abs(temp - a[i]);
            temp = a[i];
        }
    }

    cout << "SCAN Head Movement = " << total << endl;

    // 4. C-SCAN (Circular SCAN - Moving Right First)
    total = 0;
    temp = head;

    for(i = 0; i < n; i++)
    {
        if(a[i] >= head)
        {
            total += abs(temp - a[i]);
            temp = a[i];
        }
    }
    // Go to end of disk
    total += abs((size - 1) - temp);
    // Jump to start of disk (0)
    total += (size - 1); 
    temp = 0;

    for(i = 0; i < n; i++)
    {
        if(a[i] < head)
        {
            total += abs(temp - a[i]);
            temp = a[i];
        }
    }

    cout << "C-SCAN Head Movement = " << total << endl;

    return 0;
}
