#include "Solutions.h"

int main()
{
    // [1,1,1]
    std::vector<int> testCase83_1 = {1, 1, 1, 2, 2, 3};
    ListNode* test83_1 = CreateFrom(testCase83_1);
    PrintListVisual(test83_1);

    PrintListVisual(DeleteDuplicates(test83_1));
    system("pause");
    return 0;
}