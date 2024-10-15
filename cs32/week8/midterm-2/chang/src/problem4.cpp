#include "headers.h"
#include <iostream>
#include <algorithm> // defines int min(int a, int b); returns the minimum of a and b
using namespace std;

bool isDoable(int jug1, int cap1, int jug2, int cap2, int target, int depth);

void Problem4()
{
    cout << "Problem 4" << std::endl;
    cout << "Enter the capacities of the two jugs and the target amount: ";

    int jug1_capacity, jug2_capacity, target;
    cin >> jug1_capacity >> jug2_capacity >> target;

    cout << "The capacities of the two jugs are " << jug1_capacity << " and " << jug2_capacity << endl;

    if (isDoable(0, jug1_capacity, 0, jug2_capacity, target, 0))
        cout << "This can be solved!" << endl;
    else
        cout << "This cannot be solved within 9 steps!" << endl;

}

bool isDoable(int jug1, int cap1, int jug2, int cap2, int target, int depth)
{
    if (jug1 == target || jug2 == target)
        return true;
    if (depth == 9) // our limit on the depth of a recursion
        return false;

    // Can you solve it by filling A first?
    if (isDoable(cap1, cap1, jug2, cap2, target, depth+1))
        return true;

    // Can you solve it by filling B first?
    if (isDoable(jug1, cap1, cap2, cap2, target, depth+1))
        return true;

    // Can you solve it by emptying A first?
    if (isDoable(0, cap1, jug2, cap2, target, depth+1))
        return true;

    // Can you solve it by emptying B first?
    if (isDoable(jug1, cap1, 0, cap2, target, depth+1))
        return true;

    // Can you solve it by pouring from B to A first?
    int amt1 = min(cap1-jug1, jug2); // unused capacity in A, or all of what's in B
    if (isDoable(jug1 + amt1, cap1, jug2 - amt1, cap2, target, depth+1))
        return true;

    // Can you solve it by pouring from A to B first? [fill in code below]
    int amt2 = min(jug1, cap2-jug2); // unused capacity in B, or all of what's in A
    if (isDoable(jug1 - amt2, cap1, jug2 + amt2, cap2, target, depth+1))
        return true;

    // Nothing leads to a solution
    return false;
}