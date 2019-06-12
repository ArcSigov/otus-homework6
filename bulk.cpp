#include <iostream>

#include "bulk.hpp"


int main(int argc , char* argv[])
{

       if (argc>1)
        {
            bulk b(std::atoi(argv[argc-1]));
            bulk_output output(&b);
            bulk_terminal terminal(&b);
            b.start();
        }
    return 1;
}