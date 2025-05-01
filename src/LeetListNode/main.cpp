#include "Solutions.h"

int main()
{
    std::vector<int> test82a = { 1, 2, 3, 3, 3, 4, 4, 5 };
    //MakeTest(test82a, "No82a", &DeleteDuplicates_DistinctOnly);

    std::vector<int> test82b = { 1, 1, 1, 2, 3 };
    //MakeTest(test82b, "No82b", &DeleteDuplicates_DistinctOnly);

    std::vector<int> test82c = { 1, 1, 2, 2 };
    //MakeTest(test82c, "No82c", &DeleteDuplicates_DistinctOnly);

    std::vector<int> test82d = { 1, 1 };
    //MakeTest(test82d, "No82d", &DeleteDuplicates_DistinctOnly);

    std::vector<int> test82e = { 1, 2, 2 };
    MakeTest(test82e, "No82e", &DeleteDuplicates_DistinctOnly);
    
    std::vector<int> test82f = { 1, 1, 2, 2 , 3, 3};
    //MakeTest(test82f, "No82f", &DeleteDuplicates_DistinctOnly);

    std::vector<int> test83 = { 1, 1, 1, 2, 2, 3 };
    //MakeTest(test83, "No83", &DeleteDuplicates);

    system("pause");
    return 0;
}