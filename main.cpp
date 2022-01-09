#include <iostream>
#include <vector>
#include <set>

using namespace std;

void findDoubles(vector<int>& values)
{
    multiset<int> valuesMSet;                // multiset will sort vector 'values'
    multiset<int>::iterator it;              // 3 iterstors for searching for the members with equal values in multiset
    multiset<int>::iterator it1;
    multiset<int>::iterator it2;

    for(int value : values)                  // initialising multiset with members of vector 'values'
        valuesMSet.insert(value);

    it = valuesMSet.cend();
    it--;                                    // Catch the last member of the multiset
    int theEnd = (*it / 2) + 1;              // End of searching
    int temp;

    it = valuesMSet.cbegin();                // set iterators pointing to first two members of multiset
    it1 = valuesMSet.cbegin();
    ++it1;

    while(*it < 0)                           // Negative numbers
    {
        if(*it % 2 != 0)                     // Is the number even?
        {
            while(*it % 2 != 0)              // If the number is not even...
                it++;                        // ... skip it
            it1 = it;
            it1++;
        }
        if(*it == 0)                         // When the members are not negative anymore...
            break;                           // ... leave the loop

        temp = *it;
        if(*it == *it1)                      // If the members have the same value ...
        {
            while(*it == temp)
                it++;                        // ... just skip them
            it1 = it;
            it1++;
        }

        if(*it > *it1 * 2)                    // If the half of the member is greater then next member...
        {
            while(*it > *it1 * 2)             // ... the multiset member is smaller then 1/2 of one 'it1' is pointing to...
                it1++;                        // ... so skip it
        }
        else
        {
            if(*it == *it1 * 2)               // If the half of the member is equal to the next member...
            {
                cout << *it1 << " ";          // ... send it to the console...
                it++;                         // ... and increment 'it'
                it1++;
            }
            else    //if(*it < *it1 * 2)      If the half of the member is ...
            {                                 // ... less then to the next one...
                while(*it < *it1 * 2)         // ... skip it
                    it++;
            }
        }
    }

    while(*it != theEnd)                      // Positive integers start
    {
        if(it == it1)                         // 'it1' should pointing the next member
        {
            it1++;
            it2 = it1;
        }
        if(*it == 0 && *it1 > 0)              // Zero is special number
        {
            cout << *it << " ";               // If there is only one zero send it to the console
            it++;
            it1++;
        }
        else
        {
            if(*it == 0 && *it1 == 0)          // If there are more zeros...
            {
                while(*it == 0)                // Increment the iterators until 'it' is not pointing to zero
                    it++;
                it1 = it;
                it1++;
            }
        }

        if(*it * 2 > *it1)                     // If the next is smaller then double previous...
        {
            while(*it * 2 > *it1)              // ... skip it
                it1++;
        }
        else
        {
            if(*it * 2 == *it1)                 // If the next is equal to double previous...
            {
                it2 = it1;
                it2++;
                if(*it1 != *it2)                // ... check is it the only one in the multiset
                {
                    cout << *it << " ";         // If it is send it to the console
                    it++;
                    it1++;
                }
                else
                {
                    temp = *it1;               // If there are more then one...
                    while(*it1 == temp)        // ... just skip it
                        it1++;
                }
            }
            else                               // If the next is greater then double previous...
            {
                while(*it * 2 < *it1)          //... skip it
                    it++;
            }
        }
    }                                          // And that's it
}

int main()
{
    vector<int> values{1,2,3,4,5,6,7,8,9,0,8,8,8,9,10,11,9,8,5,-7,-5,-3,-8,-4,-7,-2,-1,-1,-7,-9,-6};
    findDoubles(values);

    return 0;
}
