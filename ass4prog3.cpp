#include <iostream>
using namespace std;

int main()
{
    int ip1[4], ip2[4], mask[4];
    int i, valid = 1, same = 1;

    cout << "Enter first IP address: ";
    for(i = 0; i < 4; i++)
    {
        cin >> ip1[i];
    }

    cout << "Enter second IP address: ";
    for(i = 0; i < 4; i++)
    {
        cin >> ip2[i];
    }

    cout << "Enter subnet mask: ";
    for(i = 0; i < 4; i++)
    {
        cin >> mask[i];
    }

    // Validate IP addresses and subnet mask ranges (0 - 255)
    for(i = 0; i < 4; i++)
    {
        if(ip1[i] < 0 || ip1[i] > 255 ||
           ip2[i] < 0 || ip2[i] > 255 ||
           mask[i] < 0 || mask[i] > 255)
        {
            valid = 0;
        }
    }

    if(valid == 0)
    {
        cout << "Invalid IP address or subnet mask" << endl;
        return 0;
    }

    cout << "Both IP addresses are valid." << endl;

    // Check if both hosts belong to the same subnet using bitwise AND
    for(i = 0; i < 4; i++)
    {
        if((ip1[i] & mask[i]) != (ip2[i] & mask[i]))
        {
            same = 0;
        }
    }

    if(same == 1)
    {
        cout << "Both hosts belong to the same subnet." << endl;
    }
    else
    {
        cout << "Both hosts belong to different subnets." << endl;
    }

    return 0;
}
