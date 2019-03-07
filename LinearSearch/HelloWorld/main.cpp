#include <iostream>
#include<limits.h>

using namespace std;

bool WoodTest()
{
	
}
	
bool GetMinCommonMultiple(int a, int b, int* common, int* multiple)
{
	// leader advice
    if(a == b)
    {
        return false;
    }

    if(a > b)
    {
        a = a ^ b;
        b = a ^ b;
        a = a ^ b;
    }

    int num1 = a;
    int num2 = b;

    int result = 0;
    while(num1 != 0)
    {
        result = num2 % num1;
        num2 = num1;
        num1 = result;
    }

    *common = num2;
    *multiple = (a * b) / (*common);
    return true;
}

int main()
{
    int lineNumber = 0;
    cin >> lineNumber;
    for(int i = 0; i < lineNumber; ++i)
    {
        int n, a, b, k = 0;
        cin >> n >> a >> b >> k;
        int common;
        int multiple;
        if(!GetMinCommonMultiple(a, b, &common, &multiple))
        {
            cout << "Lose";
        }
        int totalASolveCount = n / a;
        int totalBSolveCount = n / b;
        int totalRepetiveCount = n / multiple;

        if(totalASolveCount + totalBSolveCount - 2 * totalRepetiveCount >=k )
        {
            cout << "Win";
        }
        else
        {
            cout << "Lose";
        }
    }
    return 0;
}
