#include <iostream>
using namespace std;

void naivePatternSearch(string searchString, string searchPattern, int array[], int *count)
{
    int patLen = searchPattern.size();
    int strLen = searchString.size();

    for (int i = 0; i <= (strLen - patLen); i++)
    {
        int j;
        for (j = 0; j < patLen; j++)
        {
            if (searchString[i+j] != searchPattern[j]){
                break;                
            }
        }
        // j is 3 at the end of the loop
        if (j == patLen){
            (*count)++;
            array[(*count)] = i;
        }
    }
}

void patternSearchUsingSubString(string searchString, string searchPattern)
{
    int stringLen = searchString.size();
    int patternLen = searchPattern.size();

    for (int i = 0; i <= (stringLen - patternLen); i++)
    {
        string pattern = searchString.substr(i, patternLen);
        if (pattern == searchPattern)
        {
            cout << "Pattern " << searchPattern << " Found at index " << i << endl;
        }
    }
}

int main()
{
    string searchString = "ABAAABCDBBABCDDEBCABC";
    string searchPattern = "ABC";
    int posArray[searchString.size()];
    int count = -1;
    //patternSearchUsingSubString(searchString, searchPattern);
    naivePatternSearch(searchString, searchPattern, posArray, &count);

    for (int i = 0; i <= count; i++)
    {
        cout << "Pattern found at position: " << posArray[i] << endl;
    }
}