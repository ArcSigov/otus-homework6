#include <vector>
#include <string>
#include <tuple>
#include <cstdlib>
#include <fstream>
#include <chrono>

class bulk_handler
{    
public:
    virtual void handler_run(const std::vector<std::string>& vstr,[[maybe_unused]] const unsigned long long &time) = 0;
};



class bulk
{
    using system_time = std::chrono::time_point<std::chrono::system_clock>;
    std::vector<bulk_handler*> _hndl;
public:
    explicit bulk(int _bulk):bulk_size(_bulk), time(0){};
    void start();
    void add_handler(bulk_handler* _new);
private:
    void notify();
    auto run_bulk();
    auto get_dynamic_block();
    unsigned int bulk_size;
    unsigned long long time;
    system_time sys_time;
    std::vector<std::string> subs;
};


class bulk_output : public bulk_handler
{
public:
    bulk_output(bulk * _bulk)
    {
        _bulk->add_handler(this);
    }
    void handler_run(const std::vector<std::string>& vstr, [[maybe_unused]] const unsigned long long &time) override
    {
        std::ofstream output("bulk" + std::to_string(time) +".log");
        output << "bulk: ";
        for (auto it = vstr.cbegin() ; it !=vstr.cend();it++)
        {
            if (it != vstr.cbegin())
                output << ", ";
            output << *it;
        }
        output<< std::endl;
        output.close();
    }
};


class bulk_terminal : public bulk_handler
{
public:
    bulk_terminal(bulk* _bulk)
    {
        _bulk->add_handler(this);
    }
    void handler_run(const std::vector<std::string>& vstr,[[maybe_unused]] const unsigned long long &time) override
    {
        std::cout << "bulk: ";
        for (auto it = vstr.cbegin() ; it !=vstr.cend();it++)
        {
            if (it != vstr.cbegin())
                std::cout << ", ";
            std::cout << *it;
        }
        std::cout << std::endl;
    }
};


auto bulk::run_bulk()
{  
    static auto protector = 0;
    auto dynamic = 0;
    for (unsigned int i = 0; i < bulk_size;i++)
    {
        std::string line;
        if (std::getline(std::cin,line))
        {
            if (line == "{")
            {
                dynamic = 1;
                break;
            }
            else if (line != "}")
            {
                if (i==0)
                {
                    time = std::chrono::duration_cast<std::chrono::seconds>(sys_time.time_since_epoch()).count();
                }
                subs.push_back(line);
            }
        }
        else
        {
            protector = 1;
            break;
        }
        
    }
    return std::make_tuple(dynamic,protector);
}

auto bulk::get_dynamic_block()
{
    auto line_protector = 1;
    static auto protector = 0;
    auto dynamic = 1;
    static auto first = 1;
    std::string line {'\n'};
    std::string output;
    while (1)
    {
        if(std::getline(std::cin,line))
        {
            if (line == "{")
            {
                line_protector ++;
            }
            else if (line == "}")
            {
                if (line_protector)
                    line_protector--;
                
                if (!line_protector)
                {
                        dynamic = 0;
                        first = 1;
                        break;
                }
            }
            else
            {
                if (first)
                {
                    time = std::chrono::duration_cast<std::chrono::seconds>(sys_time.time_since_epoch()).count();
                    first = 0;
                }
                subs.push_back(line);
            }       
        }
        else
        { 
            protector = 1;
            break;
        }
    }
    return std::make_tuple(dynamic,protector);
}

void bulk::notify()
{
    for (const auto& it : _hndl)
        it->handler_run(subs,time);
}


void bulk::add_handler(bulk_handler* _new)
{
    _hndl.emplace_back(_new);
}

void bulk::start()
{
    auto protector = 0;
    auto dynamic = 0;
    while (!protector)
    {
        sys_time = std::chrono::system_clock::now();
        subs.clear();
        if (dynamic)
        {
            std::tie(dynamic,protector) = get_dynamic_block();
        }
        else
        {
            std::tie(dynamic,protector)  = run_bulk();
        }
        if (subs.size())
        {
            notify();
        }
    }
}