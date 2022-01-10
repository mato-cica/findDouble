/****************************************************************************************
* Given is a vector of integers. The function findDouble(vector values) should find all members
* of vector wich have double values in the vector. If there is many members with double values
* then that member should not be counted. Members should be pushed to the terminal (stdout)
* sorted in ascending order.
*
* For example: for vector values = [1,2,3,4,5,6,7,8,9,0,8] the result is 0 1 2 3
* because 2x0 = 0, 2x1=2, 2x2=4 and 2x3=6
*
* Altough 2x4=8 4 is not counted because there is 2 member of vector with value of 8.
*******************************************************************************************/
#include <iostream>
#include <vector>
#include <set>

using namespace std;

/***********************************************************************
* Multiset 'valuesMSet' is used to sort vector 'values'. This function populates multiset
* with members of given vector.
* Parameters: vector<int> ('values'), multiset<int> ('valuesMSet')
* Return: nothing, but populates multiset
***********************************************************************/
void populateMultiset(vector<int>& values, multiset<int>& valuesMSet)
{
    for(int value : values)                  // initialising multiset with members of vector 'values'
        valuesMSet.insert(value);
}

/***********************************************************************
* There is no need to search multiset after reaching the member whose value is a half of
* value of greatest member in multiset. Since the multiset is sorted that is the last element.
* Parameters: multiset<int> ('valuesMSet'), multiset iterator ('it')
* Return: nothing, but does the job on variables
***********************************************************************/
void findTheEnd(multiset<int>& valuesMSet, multiset<int>::iterator& it, int& theEnd)
{
    it = valuesMSet.cend();
    it--;                                    // Catch the last member of the multiset...
    theEnd = (*it / 2) + 1;                  // ... to find the end of searching
}

/***********************************************************************
* Initialisation of multiset's iterators before the passing through the multiset starts.
* Parameters: multiset<int> ('valuesMSet'), iterators 'it' and 'it1'
* Return: nothing, but does the initialisation of the variables
***********************************************************************/
void initIterators(multiset<int>& valuesMSet, multiset<int>::iterator& it, multiset<int>::iterator& it1)
{
    it = valuesMSet.cbegin();                // set iterators pointing to first two members of multiset
    it1 = valuesMSet.cbegin();
    ++it1;
}

/***********************************************************************
* This function finds negative integers from multiset 'valuesMSet' according to
* assignment's requirements.
* Parameters: iterators 'it','it1' and 'it2'
* Return: nothing, but does the job
***********************************************************************/
void findNegative(multiset<int>::iterator& it, multiset<int>::iterator& it1, multiset<int>::iterator& it2)
{
    while(*it < 0)                           // Negative numbers
    {
        if(*it % 2 != 0)                     // Is the number even?
        {
            while(*it % 2 != 0)              // If the number is not even...
                it++;                        // ... skip it
            it1 = it;
            it1++;
        }

        if(*it >= 0)                         // When the members are not negative anymore...
            break;                           // ... leave the loop

        it2 = it;
        if(*it == *it1)                      // If the members have the same value ...
        {
            while(*it == *it2)
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
}
/***********************************************************************
* This function finds nonnegative integers from multiset 'valuesMSet' according to
* assignment's requirements.
* Parameters: iterators 'it','it1','it2' wich pass through multiset and integer 'theEnd'
* wich value is half of greatest number in the multiset
* Return: nothing, but does the job
***********************************************************************/
void findNonNegative(multiset<int>::iterator& it, multiset<int>::iterator& it1, multiset<int>::iterator& it2, int& theEnd)
{
    while(*it != theEnd)                      // Nonnegative integers start here
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
                    it2 = it1;               // If there are more then one...
                    while(*it1 == *it2)        // ... just skip it
                        it1++;
                }
            }
            else                               // If the next is greater then double previous...
            {
                while(*it * 2 < *it1)          //... skip current member
                    it++;
            }
        }
    }
}

/***********************************************************************
* This function finds all the integers from multiset 'valuesMSet' according to
* assignment's requirements.
* Parameters: given vector<int>
* Return: nothing, but does the job
***********************************************************************/
void findDoubles(vector<int>& values)
{
    multiset<int> valuesMSet;                // multiset will sort vector 'values'
    multiset<int>::iterator it;              // 3 iterators for searching multiset
    multiset<int>::iterator it1;
    multiset<int>::iterator it2;
    int theEnd;                              // End of passing through the multiset

    populateMultiset(values, valuesMSet);
    findTheEnd(valuesMSet, it, theEnd);
    initIterators(valuesMSet, it, it1);
    findNegative(it, it1, it2);
    findNonNegative(it, it1, it2, theEnd);
}

int main()
{
    vector<int> values{1,2,3,4,5,6,7,8,9,0,8,8,8,9,10,11,9,8,5,-7,-5,-3,-8,-4,-7,-2,-1,-1,-7,-9,-6};    // Given vector 'values'
    findDoubles(values);                                                                                // function findDoubles(vector<int> values) in action

    return 0;
}
