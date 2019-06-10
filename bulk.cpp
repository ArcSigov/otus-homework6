#include <iostream>

#include "bulk.hpp"


int main(int argc , char* argv[])
{
    std::cout << "hello" << std::endl;

    if (argc>1)
    {
        bulk b(std::atoi(argv[argc-1]));
        bulk_output output(&b);
        bulk_terminal terminal(&b);
        b.get_input_stream();
    }

    return 1;
}