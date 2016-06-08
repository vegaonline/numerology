#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <functional>

time_t ttime = time(0); // get time now
struct tm* now = localtime(&ttime);

std::string StringToUpper(std::string strToConvert)
{
    std::transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);
    return strToConvert;
}

void getName(std::string& fName, std::string& mName, std::string& lName)
{
    //  std::string fName;  // first Name
    //  std::string mName;  // middle Name
    //  std::string lName;  // last Name
    std::cout << " ENTER NAME \n\n";

    std::cout << " First Name : ";
    std::cin >> fName;
    std::cout << std::endl;
    fName = StringToUpper(fName);

    std::cout << " Middle Name ['-' if there is no middle name] : ";
    std::cin >> mName;
    std::cout << std::endl;
    mName = StringToUpper(mName);

    std::cout << " Last name : ";
    std::cin >> lName;
    std::cout << std::endl;
    lName = StringToUpper(lName);
}

void getDOB(int& dd, int& mm, int& yr)
{
    std::cout << " ENTER DATE OF BIRTH \n\n";

    while(dd < 1 || dd > 31) {
        std::cout << " Enter Birth date [ 1 - 31]  :";
        std::cin >> dd;
        std::cout << std::endl;
    }
    while(mm < 1 || mm > 12) {
        std::cout << " Enter Birth Monh [1 - 12]  :";
        std::cin >> mm;
        std::cout << std::endl;
    }
    while(yr < 1900 || yr > (now->tm_year + 1900)) {
        std::cout << " Enter Birth Year  [yyyy] : ";
        std::cin >> yr;
        std::cout << std::endl;
    }
}

int getSum(int x)
{
    if(x < 10) {
        return x;
    }
    else if(x > 9 && x < 99) {
        int x1 = x / 10;
        int x2 = x % 10;
        return getSum(x1 + x2);
    }
    else if(x > 99 && x < 999) {
        int x1 = x / 100;
        int x2 = x % 100;
        int x3 = getSum(x2);
        return getSum(x1 + x3);
    }
    else if(x > 999 && x < 9999) {
        int x1 = x / 1000;
        int x2 = x % 1000;
        int x3 = getSum(x2);
        return getSum(x1 + x3);
    }
}

void getLPATH(int dd, int mm, int yr, int& lptot, int& lpFull)
{
    lpFull = getSum(dd) + getSum(mm) + getSum(yr);
    lptot = getSum(lpFull);
}

int main()
{
    std::string fName = "";
    std::string mName = "";
    std::string lName = "";
    int date = 0;
    int month = 0;
    int year = 0;
    int LPATHfull = 0;
    int LPATHtot = 0;
    std::string vowel = "AEIOU";

    std::map<char, int> letterNum;
    letterNum['A'] = 1;
    letterNum['B'] = 2;
    letterNum['C'] = 3;
    letterNum['D'] = 4;
    letterNum['E'] = 5;
    letterNum['F'] = 6;
    letterNum['G'] = 7;
    letterNum['H'] = 8;
    letterNum['I'] = 9;
    letterNum['J'] = 1;
    letterNum['K'] = 2;
    letterNum['L'] = 3;
    letterNum['M'] = 4;
    letterNum['N'] = 5;
    letterNum['O'] = 6;
    letterNum['P'] = 7;
    letterNum['R'] = 8;
    letterNum['S'] = 9;
    letterNum['T'] = 1;
    letterNum['U'] = 2;
    letterNum['V'] = 3;
    letterNum['W'] = 4;
    letterNum['X'] = 5;
    letterNum['Y'] = 6;
    letterNum['Z'] = 7;

    getName(fName, mName, lName);
    getDOB(date, month, year);
    getLPATH(date, month, year, LPATHtot, LPATHfull);
    std::cout << fName.find(vowel) << std::endl;

    return 0;
}
