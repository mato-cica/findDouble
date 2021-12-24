#include <iostream>
#include <vector>
#include <set>

using namespace std;
void findDoubles(vector<int>& values)
{
    set<int> equals;                         // set for members with equals values in vector 'values'
    set<int>::iterator its;                  // iterator for set 'equals'

    multiset<int> valuesMSet;                // multiset will sort vector 'values'
    multiset<int>::iterator it;              // two iterstors for searching for members with equal values in multiset
    multiset<int>::iterator it1;

    for(int value : values)                  // initialising multiset with members of vector 'values'
        valuesMSet.insert(value);

    it = valuesMSet.cbegin();                // first iterator pointed to first element of multiset...
    it1 = valuesMSet.cbegin();
    ++it1;                                   // ... and second to second element

    while(it1 != valuesMSet.cend())          // start finding members with equal values in the multiset
    {
        if(*it == *it1)                      // if first two members equal...
        {
            equals.insert(*it);              // ... insert one of them in set 'equals'...
            ++it1;                           // ... and increment both iterators
            ++it;
        }
        else                                 // ... if first two members are not equal...
        {
            ++it1;                           // ... just increment both iterators
            ++it;
        }
    }

    for(int eq : equals)                     // erasing doubles in multiset
        valuesMSet.erase(eq);

    /** searching for doubles in the multiset **/
    it = valuesMSet.cbegin();                // set iterators pointing to first two members of multiset
    it1 = valuesMSet.cbegin();
    ++it1;
    while(it1 != valuesMSet.cend())          // iterators passing through the multiset
    {
        if(*it == 0)                         // if the first member is 0...
        {
            cout << *it << " ";              // ... push it to output terminal...
            ++it;                            // ... then increment iterators
            ++it1;
        }
        else                                 // if the first member of the multiset is not 0
        {
            if(*it * 2 == *it1)              // compare first two members and if second is double of first
            {
                cout << *it << " ";          // ... push it to output terminal...
                ++it;                        // ... then increment iterators
                ++it1;
            }
            else                             // if the second member is not double as of first one...
            {
                if(*it * 2 > *it1)           // ... check if it is smaller then double as of first one...
                    ++it1;                   // ... if it is just increment the second iterator (take the next member)
                else                         // if the second is greather then double as of first one...
                {
                        ++it;                //... just increase both iterators
                        ++it1;
                }
            }
        }
    }
}

int main()
{
    vector<int> values{1,2,3,4,5,6,7,8,9,0,8,8,8,9,10,11,9,8,5,1};
    findDoubles(values);

    return 0;
}
