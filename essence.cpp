#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <ctime>
#include <algorithm>
#include <functional>
#include <cstdlib>

time_t ttime = time ( 0 ); // get time now
struct tm* now = localtime ( &ttime );

std::string StringToUpper ( std::string strToConvert )
{
    std::transform ( strToConvert.begin (), strToConvert.end (), strToConvert.begin (), ::toupper );
    return strToConvert;
}

void getName ( std::string& fName, std::string& mName, std::string& lName )
{
    //  std::string fName;  // first Name
    //  std::string mName;  // middle Name
    //  std::string lName;  // last Name
    std::cout << " ENTER NAME \n\n";

    std::cout << " First Name : ";
    std::cin >> fName;
    std::cout << std::endl;
    fName = StringToUpper ( fName );

    std::cout << " Middle Name ['-' if there is no middle name] : ";
    std::cin >> mName;
    std::cout << std::endl;
    mName = ( mName[0] == '-' ) ? " " : mName;
    mName = StringToUpper ( mName );

    std::cout << " Last name : ";
    std::cin >> lName;
    std::cout << std::endl;
    lName = StringToUpper ( lName );
}

void getDOB ( int& dd, int& mm, int& yr )
{
    std::cout << " ENTER DATE OF BIRTH \n\n";

    while ( dd < 1 || dd > 31 ) {
        std::cout << " Enter Birth date [ 1 - 31]  :";
        std::cin >> dd;
        std::cout << std::endl;
    }
    while ( mm < 1 || mm > 12 ) {
        std::cout << " Enter Birth Monh [1 - 12]  :";
        std::cin >> mm;
        std::cout << std::endl;
    }
    while ( yr < 1900 || yr > ( now->tm_year + 1900 ) ) {
        std::cout << " Enter Birth Year  [yyyy] : ";
        std::cin >> yr;
        std::cout << std::endl;
    }
}

int getSum ( int x )
{
    if ( x < 10 ) {
        return x;
    } else if ( x > 9 && x < 99 ) {
        if ( x == 11 || x == 22 ) {
            return x;
        } else {
            int x1 = x / 10;
            int x2 = x % 10;
            return getSum ( x1 + x2 );
        }
    } else if ( x > 99 && x < 999 ) {
        int x1 = x / 100;
        int x2 = x % 100;
        int x3 = getSum ( x2 );
        return getSum ( x1 + x3 );
    } else if ( x > 999 && x < 9999 ) {
        int x1 = x / 1000;
        int x2 = x % 1000;
        int x3 = getSum ( x2 );
        return getSum ( x1 + x3 );
    }
}

void getLPATH ( int dd, int mm, int yr, int& lptot, int& lpFull )
{
    lpFull = getSum ( dd ) + getSum ( mm ) + getSum ( yr );
    lptot = getSum ( lpFull );
}

int getSoulUrge ( std::string fn, std::string vowel, std::map<char, int> letterNum )
{
    int soul = 0;
    for ( std::string::iterator itr = fn.begin (); itr != fn.end (); ++itr ) {
        if ( vowel.find ( *itr ) != std::string::npos ) soul += letterNum[*itr];
    }
    return soul;
}

int exprss ( std::string fn, std::string mn, std::string ln, std::map<char, int> letterNum )
{
    int expression1 = 0, expression2 = 0, expression3 = 0;
    for ( std::string::iterator itr = fn.begin (); itr != fn.end (); ++itr ) {
        expression1 += letterNum[*itr];
    }

    if ( mn[0] != '-' ) {
        for ( std::string::iterator itr = mn.begin (); itr != mn.end (); ++itr ) {
            expression2 += letterNum[*itr];
        }
    }

    for ( std::string::iterator itr = ln.begin (); itr != ln.end (); ++itr ) {
        expression3 += letterNum[*itr];
    }

    return expression1 + expression2 + expression3;
}

void getPinnacle ( int date, int month, int year, int& pinnacle1, int& pinnacle2, int& pinnacle3, int& pinnacle4 )
{
    pinnacle1 = date + getSum ( month );
    pinnacle1 = ( pinnacle1 == 11 || pinnacle1 == 22 ) ? pinnacle1 : getSum ( pinnacle1 );
    pinnacle2 = date + getSum ( year );
    pinnacle2 = ( pinnacle2 == 11 || pinnacle2 == 22 ) ? pinnacle2 : getSum ( pinnacle2 );
    pinnacle3 = pinnacle1 + pinnacle2;
    pinnacle3 = ( pinnacle3 == 11 || pinnacle3 == 22 ) ? pinnacle3 : getSum ( pinnacle3 );
    pinnacle4 = getSum ( month ) + getSum ( year );
    std::cout << "P4 " << pinnacle4 << "  " << getSum ( month ) << "  " << getSum ( year ) << "\n";
    pinnacle4 = ( pinnacle4 == 11 || pinnacle4 == 22 ) ? pinnacle4 : getSum ( pinnacle4 );
}

int main ()
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

    getName ( fName, mName, lName );
    getDOB ( date, month, year );
    getLPATH ( date, month, year, LPATHtot, LPATHfull );
    LifePath = ( LPATHfull == 11 || LPATHfull == 22 ) ? LPATHfull : LPATHtot;
    soulUrge = getSoulUrge ( fName, vowel, letterNum );
    soulUrge = ( soulUrge == 11 || soulUrge == 2 ) ? soulUrge : getSum ( soulUrge );
    expression = exprss ( fName, mName, lName, letterNum );
    expression = ( expression == 11 || expression == 22 ) ? expression : getSum ( expression );
    getPinnacle ( date, month, year, pinnacle1, pinnacle2, pinnacle3, pinnacle4 );

    // ****** reporting *********
    // system ( "clear" );
    std::cout << " Numerology Report : - \n\n";
    std::cout << " " << fName << " " << mName << " " << lName << "   DOB :-  " << date << "/" << month << "/" << year
              << std::endl;
    std::cout << " Life Path Number : " << LifePath << std::endl;
    std::cout << " Soul Urge Number : " << soulUrge << std::endl;
    std::cout << " Expression : " << expression << std::endl;
    std::cout << " First Pinnacle Number : " << pinnacle1 << "\n";
    std::cout << " Second Pinnacle Number : " << pinnacle2 << "\n";
    std::cout << " Third Pinnacle Number : " << pinnacle3 << "\n";
    std::cout << " Fourth Pinnacle Number : " << pinnacle4 << "\n";

    return 0;
}
