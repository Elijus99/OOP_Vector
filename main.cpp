#include <vector>
#include "vector.h"
#include "functions.h"

int main()
{
    std::vector<int> A;
    Vector<int> B;
    int loc1[5] = {0, 0, 0, 0, 0}, loc2[5] = { 0, 0, 0, 0, 0 };
    cout << "Push_back:" << endl;
    cout << "Inserted 10000 elements:" << endl;
    runPushback(A, 10000, loc1[0]);
    runPushback(B, 10000, loc2[0]);
    cout << "Inserted 100000 elements:" << endl;
    runPushback(A, 100000, loc1[1]);
    runPushback(B, 100000, loc2[1]);
    cout << "Inserted 1000000 elements:" << endl;
    runPushback(A, 1000000, loc1[2]);
    runPushback(B, 1000000, loc2[2]);
    cout << "Inserted 10000000 elements:" << endl;
    runPushback(A, 10000000, loc1[3]);
    runPushback(B, 10000000, loc2[3]);
    cout << "Inserted 100000000 elements:" << endl;
    runPushback(A, 100000000, loc1[4]);
    runPushback(B, 100000000, loc2[4]);
    cout << "\nRealocations:" << endl;
    cout << "Reallocations while inserting 10000 elements:" << endl;
    cout << "std::vector: " << loc1[0] << endl;
    cout << "Vector: " << loc2[0] << endl;
    cout << "Reallocations while inserting 100000 elements:" << endl;
    cout << "std::vector: " << loc1[1] << endl;
    cout << "Vector: " << loc2[1] << endl;
    cout << "Reallocations while inserting 1000000 elements:" << endl;
    cout << "std::vector: " << loc1[2] << endl;
    cout << "Vector: " << loc2[2] << endl;
    cout << "Reallocations while inserting 10000000 elements:" << endl;
    cout << "std::vector: " << loc1[3] << endl;
    cout << "Vector: " << loc2[3] << endl;
    cout << "Reallocations while inserting 100000000 elements:" << endl;
    cout << "std::vector: " << loc1[4] << endl;
    cout << "Vector: " << loc2[4] << endl;

    return 0;
}
