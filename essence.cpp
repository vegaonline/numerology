#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <functional>
#include <cstdlib>

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
    mName = (mName[0] == '-') ? " " : mName;
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
    else if(x > 9 && x < 100) {
        if(x == 11 || x == 22) {
            return x;
        }
        else {
            int x1 = x / 10;
            int x2 = x % 10;
            return getSum(x1 + x2);
        }
    }
    else if(x > 99 && x < 1000) {
        int x1 = x / 100;
        int x2 = x % 100;
        int x3 = getSum(x2);
        return getSum(x1 + x3);
    }
    else if(x > 999 && x < 10000) {
        int x1 = x / 1000;
        int x2 = x % 1000;
        return getSum(x1 + x2);
    }
}

void getLPATH(int dd, int mm, int yr, int& lptot, int& lpFull)
{
    lpFull = getSum(dd) + getSum(mm) + getSum(yr);
    lptot = getSum(lpFull);
}

int getSoulUrge(std::string fn, std::string vowel, std::map<char, int> letterNum)
{
    int soul = 0;
    for(std::string::iterator itr = fn.begin(); itr != fn.end(); ++itr) {
        if(vowel.find(*itr) != std::string::npos)
            soul += letterNum[*itr];
    }
    return soul;
}

int exprss(std::string fn, std::string mn, std::string ln, std::map<char, int> letterNum)
{
    int expression1 = 0, expression2 = 0, expression3 = 0;
    for(std::string::iterator itr = fn.begin(); itr != fn.end(); ++itr) {
        expression1 += letterNum[*itr];
    }

    if(mn[0] != '-') {
        for(std::string::iterator itr = mn.begin(); itr != mn.end(); ++itr) {
            expression2 += letterNum[*itr];
        }
    }

    for(std::string::iterator itr = ln.begin(); itr != ln.end(); ++itr) {
        expression3 += letterNum[*itr];
    }

    return expression1 + expression2 + expression3;
}

int make2dig(int x)
{
    int sum = 0, rest = 0;
    sum += x / 1000;
    rest = x % 1000;
    sum += rest / 100;
    rest = rest % 100;
    sum += rest / 10;
    sum += rest % 10;

    return sum;
}

void getPinnacle(int date, int month, int year, int& pinnacle1, int& pinnacle2, int& pinnacle3, int& pinnacle4)
{
    pinnacle1 = date + make2dig(month);
    pinnacle1 = (pinnacle1 == 11 || pinnacle1 == 22) ? pinnacle1 : getSum(pinnacle1);
    pinnacle2 = date + make2dig(year);
    pinnacle2 = (pinnacle2 == 11 || pinnacle2 == 22) ? pinnacle2 : getSum(pinnacle2);
    pinnacle3 = pinnacle1 + pinnacle2;
    pinnacle3 = (pinnacle3 == 11 || pinnacle3 == 22) ? pinnacle3 : getSum(pinnacle3);
    pinnacle4 = make2dig(month) + make2dig(year);
    pinnacle4 = (pinnacle4 == 11 || pinnacle4 == 22) ? pinnacle4 : getSum(pinnacle4);
}

void makeEssence(std::string fn, std::string mn, std::string ln, int yr, int lastYear, std::map<char, int> letterNum)
{
    int fnL = fn.length();
    int mnL = mn.length();
    int lnL = ln.length();
    int fCnt = 0, mCnt = 0, lCnt = 0;
    int fiter = 1, miter = 1, liter = 1;
    int trVal;
    std::string transit = "";

    for(int iYR = 0; iYR < lastYear; iYR++) {
        trVal = 0;
        fCnt = (fCnt == fnL) ? 0 : fCnt;
        mCnt = (mCnt == mnL) ? 0 : mCnt;
        lCnt = (lCnt == lnL) ? 0 : lCnt;
        transit = fn[fCnt];
        trVal += letterNum[fn[fCnt]];
        if(fiter == letterNum[fn[fCnt]]) {
            fiter = 1;
            fCnt++;
        }
        else {
            fiter++;
        }

        transit += mn[mCnt];
        trVal += letterNum[mn[mCnt]];
        if(miter == letterNum[mn[mCnt]]) {
            miter = 1;
            mCnt++;
        }
        else {
            miter++;
        }

        transit += ln[lCnt];
        trVal += letterNum[ln[lCnt]];
        if(liter == letterNum[ln[lCnt]]) {
            liter = 1;
            lCnt++;
        }
        else {
            liter++;
        }
        std::cout << yr++ << " age from " << iYR << " to " << iYR + 1 << " TRANSIT letters : " << transit
                  << " TRANSIT values " << letterNum[transit[0]] << letterNum[transit[1]] << letterNum[transit[2]]
                  << "  essence value " << getSum(trVal) << "  \n";
    }
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
    int LifePath = 0;
    int soulUrge = 0;
    int expression = 0;
    int pinnacle1 = 0;
    int pinnacle2 = 0;
    int pinnacle3 = 0;
    int pinnacle4 = 0;

    std::string vowel = "AEIOU";

    std::map<char, int> letterNum;
    letterNum[' '] = 0;
    letterNum['-'] = 0;
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
    letterNum['Q'] = 8;
    letterNum['R'] = 9;
    letterNum['S'] = 1;
    letterNum['T'] = 2;
    letterNum['U'] = 3;
    letterNum['V'] = 4;
    letterNum['W'] = 5;
    letterNum['X'] = 6;
    letterNum['Y'] = 7;
    letterNum['Z'] = 8;

    getName(fName, mName, lName);
    getDOB(date, month, year);
    getLPATH(date, month, year, LPATHtot, LPATHfull);
    LifePath = (LPATHfull == 11 || LPATHfull == 22) ? LPATHfull : LPATHtot;
    soulUrge = getSoulUrge(fName, vowel, letterNum);
    soulUrge = (soulUrge == 11 || soulUrge == 2) ? soulUrge : getSum(soulUrge);
    expression = exprss(fName, mName, lName, letterNum);
    expression = (expression == 11 || expression == 22) ? expression : getSum(expression);
    getPinnacle(date, month, year, pinnacle1, pinnacle2, pinnacle3, pinnacle4);

    // ****** reporting *********
    // system("clear");
    std::cout << " Numerology Report : - \n\n";
    std::cout << " " << fName << " " << mName << " " << lName << "   DOB :-  " << date << "/" << month << "/" << year
              << std::endl;
    std::cout << " Life Path Number : " << LifePath << std::endl;
    std::cout << " Soul Urge Number : " << soulUrge << std::endl;
    std::cout << " Expression : " << expression << std::endl;
    std::cout << " First Pinnacle Number : " << pinnacle1 << " spans from age 0 to " << (36 - pinnacle1)
              << " years age. \n";
    std::cout << " Second Pinnacle Number : " << pinnacle2 << " spans from " << (36 - pinnacle1) << "  years  to "
              << (36 - pinnacle1 + pinnacle2) << " years age. \n";
    std::cout << " Third Pinnacle Number : " << pinnacle3 << " spans from " << (36 - pinnacle1 + pinnacle2)
              << "  years  to " << (36 - pinnacle1 + pinnacle2 + pinnacle3) << " years age. \n";
    std::cout << " Fourth Pinnacle Number : " << pinnacle4 << " spans from " << (36 - pinnacle1 + pinnacle2 + pinnacle3)
              << "  years  till death. \n\n";

    makeEssence(fName, mName, lName, year, (36 - pinnacle1 + pinnacle2 + pinnacle3 + pinnacle4), letterNum);
    return 0;
}
