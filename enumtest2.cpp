
#if 0
program=enumtest2
g++ -Wall -O2 --std=c++11 -o bin_${program} ${program}.cpp;
exit 0;
#endif

#include    <iostream>

struct  MyBoolean
{
    enum  class  Type {
        BOOL_FALSE = 0,
        BOOL_TRUE  = 1,
    } value_;

    //explicit
    MyBoolean(const Type v) : value_(v) { }

/*
    operator bool () const {
        return ( value_ != Type::BOOL_FALSE );
    }
*/
    const bool toBool() const {
        return ( value_ != Type::BOOL_FALSE );
}
};

int main(int argc, char * argv[])
{
    MyBoolean   x = MyBoolean::Type::BOOL_TRUE;
    //  MyBoolean   x2  = 1;      //  Error!
    //  MyBoolean   x3  = static_cast<MyBoolean>(1);    //  Error !
    int y = x;                  //  OK : int <- Boolean
    MyBoolean   z1 = x;         //  OK
    //  MyBoolean   z2 = y;     //  Error! : Boolean <- int

    if ( x.toBool() ) {
        std::cerr   <<  "TRUE\n";
    } else {
        std::cerr   <<  "FALSE\n";
    }
}
