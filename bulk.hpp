#include <vector>
#include <memory>
#include <tuple>



class bulk_handler
{    
public:
    virtual void handler_run(const std::tuple<int, std::string> &tuple) = 0;
};

class bulk
{
    std::vector<bulk_handler*> _hndl;
public:
    bulk(int _bulk = int()):bulk_size(_bulk){};

    void add_handler(bulk_handler* _new)
    {
        _hndl.emplace_back(_new);
    }

    void get_input_stream()
    {   
        static std::string line;
        auto asize = 0;
        while (std::getline(std::cin,line))
        {   
           
        }
        std::cout << line << std::endl;
    }
    void run_bulk(const std::string& input)
    {
        for (auto it : _hndl)
            it->handler_run(std::make_tuple(bulk_size,input));
    }
private:
    int bulk_size;
};


class bulk_output : public bulk_handler
{
public:
    bulk_output(bulk * _bulk)
    {
        _bulk->add_handler(this);
    }
    void handler_run (const std::tuple<int, std::string> &tuple) override
    {
        //std::cout << "write_to_file " << std::endl;
    }
};


class bulk_terminal : public bulk_handler
{
public:
    bulk_terminal(bulk* _bulk)
    {
        _bulk->add_handler(this);
    }
    void handler_run(const std::tuple<int, std::string>& tuple) override
    {
        std::string output;
        int size = 0;
        std::tie(size,output) = tuple;
        //std::cout << "bulk: " << output << std::endl;
    }
};