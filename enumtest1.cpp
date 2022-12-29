
#if 0
program=enumtest1
g++ -Wall -O2 --std=c++11 -o bin_${program} ${program}.cpp;
exit 0;
#endif

#include    <iostream>

#if 0
enum class MyBoolean {
    BOOL_FALSE = 0,
    BOOL_TRUE  = 1,
};

operator bool () //(const MyBoolean b)
{
    return ( b != MyBoolean::BOOL_FALSE );
}
#endif

struct  MyBoolean
{
    enum  Type {
        BOOL_FALSE = 0,
        BOOL_TRUE  = 1,
    } value_;

    //explicit
    MyBoolean(const Type v) : value_(v) { }

    operator bool () const {
        return ( value_ != BOOL_FALSE );
    }
};

int main(int argc, char * argv[])
{
    MyBoolean   x = MyBoolean::BOOL_TRUE;
    //  MyBoolean   x = 1;      //  Error!
    int y = x;                  //  OK : int <- Boolean
    MyBoolean   z1 = x;         //  OK
    //  MyBoolean   z2 = y;     //  Error! : Boolean <- int

    if ( x ) {
        std::cerr   <<  "TRUE\n";
    } else {
        std::cerr   <<  "FALSE\n";
    }
}
