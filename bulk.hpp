#include <vector>
#include <memory>
#include <tuple>
#include <cstring>


enum class bulk_status{run,end_of_line,dynamic_block,end_dynamic_block};


class bulk_handler
{    
public:
    virtual void handler_run(const  std::vector<std::string> *vectr) = 0;
};




class bulk
{
    std::vector<bulk_handler*> _hndl;
public:
    bulk(int _bulk):bulk_size(_bulk){subs.reserve(bulk_size);};
    void add_handler(bulk_handler* _new)
    {
        _hndl.emplace_back(_new);
    }

    void start()
    {  
       
        static auto protector = 0;
        subs.clear();
        for (auto i = 0; i < bulk_size;i++)
        {
            std::string line;
            if (std::getline(std::cin,line))
            {
                subs.emplace_back(line);
            }
            else
            {
                protector = 1;
                break;
            }
        }
        run_bulk();

        if (!protector)
           start();
    }
    void run_bulk()
    {
        for (auto it : _hndl)
            it->handler_run(&subs);
    }
private:
    int bulk_size;
    std::vector<std::string> subs;
};


class bulk_output : public bulk_handler
{
public:
    bulk_output(bulk * _bulk)
    {
        _bulk->add_handler(this);
    }
    void handler_run (const  std::vector<std::string> *vectr)  override
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
    void handler_run(const std::vector<std::string> *vectr) override
    {        
        if (vectr->size())
            std::cout << "bulk: ";
        for (auto it = vectr->cbegin() ; it !=vectr->cend();it++)
        {
            if (it != vectr->cbegin())
                std::cout << ",";
            std::cout << *it;
        }
        if (vectr->size())
            std::cout << std::endl;
        
    }
};