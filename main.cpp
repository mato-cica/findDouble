#include <iostream>
#include <vector>
#include <set>

using namespace std;

void findDoubles(vector<int>& values)
{

    multiset<int> valuesMSet;                // multiset will sort vector 'values'
    multiset<int>::iterator it;              // two iterstors for searching for members with equal values in multiset
    multiset<int>::iterator it1;


    int iter1;

    for(int value : values)                  // initialising multiset with members of vector 'values'
        valuesMSet.insert(value);

    it = valuesMSet.cbegin();                 // set iterators pointing to first two members of multiset
    it1 = valuesMSet.cbegin();
    ++it1;

    while(it1 != valuesMSet.cend())            // Passing through multiset
    {
        if(*it == 0 && *it1 != 0)              // If there is only one zero in multiset...
        {
            cout << *it << " ";                // Send it to std out...
            it++;                              // and increment the pointers
            it1++;
        }
        else
        {
            if(*it == 0 && *it1 == 0)          // If there are more zeros...
            {
                it++;                          //  just skip them and increment the iterators
                it1++;
                while(*it == 0)                // Increment the iterators until 'it' is not pointing to zero
                {
                    it++;
                    it1++;
                }
            }
        }

        if(*it * 2 > *it1)                     // If the member is more then 1/2 of next one...
        {
            it1++;                             // ...increment 'it1' iterator. Don't touch 'it' iterator until...
            while(*it * 2 > *it1 )             // ... the multiset member is smaller then 1/2 of one 'it1' pointing to
                it1++;
        }
        else                                   // If the member is exactly 1/2 of the next one...
        {
            if(*it * 2 == *it1)
            {
                iter1 = *it1;                   // ... check the next of next one
                it1++;
                if(*it1 != iter1)               // If the next one is not equal to the previous one...
                {
                    cout << *it << " ";         // ... send it to the console...
                    it++;                       // ... and increment 'it'
                }
                else                            // If the next of the next one is ...
                {                               // ... equal to the previous one...
                    if(*it1 == iter1)
                    {
                        it1++;                  // ... just increment the 'it1' until it is not pointing to...
                        while(*it1 == iter1)    // ... the member with equal value
                            it1++;
                        it++;
                    }
                }
            }
        }
        if(*it * 2 < *it1)                      // And finaly if the next member is more then 1/2 of previous one...
        {
            it++;                               // ... just increment iterators.
            it1++;                              // And that is it
        }
    }
}

int main()
{
    vector<int> values{1,2,3,4,5,6,7,8,9,0,8,8,8,9,10,11,9,8,5,1,0,0};
    findDoubles(values);

    return 0;
}
