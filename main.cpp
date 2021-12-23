#include <iostream>

using namespace std;
int nOfMembers;
// Definition of user-defined function findNumber()
void findNumber(int arr[], int k) //
{
    cout << '\n';
    for(int i = 0; i < nOfMembers; i++)
    {
        if (arr[i] == k)
        {
            cout << "YES \n\n";
            cout << "i =  " << i << "\n";
            break;
        }
        else
        {
            if (i == nOfMembers -1)
            {
                cout << "NO \n\n";
                cout << "i =  " << i << "\n";
            }

        }
    }
}

int main()
{
    cout << "Enter a number of members: \n";      // ask user for a number of members
    cin >> nOfMembers;                            // store number of members in nOfMembers
    int arrayOfNumbers[nOfMembers];               // array definition
    for(int i = 0; i < nOfMembers; i++)           // array initialization
    {
        cout << "Enter arr[" << i << "] \n";
        cin >> arrayOfNumbers[i];
    }
    cout << "Enter k \n";                         // ask user for a number we are searching for
    int k;                                        // definition k
    cin >> k;                                     // initialization k
    findNumber(arrayOfNumbers, k);                // let function do its job

    return 0;
}
