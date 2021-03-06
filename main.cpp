#include <vector>
#include "vector.h"
#include "functions.h"
#include "StudentDerived.h"

int main()
{
    std::vector<int> A;
    Vector<int> B;
    int loc1[5] = {0, 0, 0, 0, 0}, loc2[5] = { 0, 0, 0, 0, 0 };
    cout << "Push_back(int):" << endl;
    cout << "Inserted 10000 elements:" << endl;
    runPushback(A, 10000, loc1[0]);
    A.clear();
    runPushback(B, 10000, loc2[0]);
    B.clear();
    cout << "Inserted 100000 elements:" << endl;
    runPushback(A, 100000, loc1[1]);
    A.clear();
    runPushback(B, 100000, loc2[1]);
    B.clear();
    cout << "Inserted 1000000 elements:" << endl;
    runPushback(A, 1000000, loc1[2]);
    A.clear();
    runPushback(B, 1000000, loc2[2]);
    B.clear();
    cout << "Inserted 10000000 elements:" << endl;
    runPushback(A, 10000000, loc1[3]);
    A.clear();
    runPushback(B, 10000000, loc2[3]);
    B.clear();
    cout << "Inserted 100000000 elements:" << endl;
    runPushback(A, 100000000, loc1[4]);
    A.clear();
    runPushback(B, 100000000, loc2[4]);
    B.clear();
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

    std::vector<StudentDerived> C;
    Vector<StudentDerived> D;
    StudentDerived x;
    x.setVardas("Vardas");
    x.setPav("Pavarde");
    Vector<int> nd{ 1, 1, 1, 1, 1 };
    x.setNd(nd);
    x.setEgz(1);
    x.setGal(1);

    cout << "Push_back(Studentai):" << endl;
    cout << "Inserted 10000 elements:" << endl;
    runPushback(C, x, 10000);
    C.clear();
    runPushback(D, x, 10000);
    D.clear();
    cout << "Inserted 100000 elements:" << endl;
    runPushback(C, x, 100000);
    C.clear();
    runPushback(D, x, 100000);
    D.clear();
    cout << "Inserted 1000000 elements:" << endl;
    runPushback(C, x, 1000000);
    C.clear();
    runPushback(D, x, 1000000);
    D.clear();
    system("pause");
    return 0;
}
