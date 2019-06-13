#include <vector>
#include <memory>
#include <tuple>
#include <cstring>
#include <chrono>


class bulk_handler
{    
public:
    virtual void handler_run(const  std::vector<std::string>& vectr) = 0;
};




class bulk
{
    std::vector<bulk_handler*> _hndl;
public:
    bulk(int _bulk):bulk_size(_bulk)
    {
        subs.reserve(bulk_size);
    };
    void add_handler(bulk_handler* _new)
    {
        _hndl.emplace_back(_new);
    }
    auto get_dynamic_block()
    {
        auto line_protector = 1;
        static auto protector = 0;
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
                         if (output.size())
                             output.pop_back();
                         break;
                    }
                }
                else
                {
                    output+=line+=",";
                }       
           }
           else
           { 
               protector = 1;
               break;
           }
        }
        if (protector && line_protector)
            output.clear();

        return std::make_tuple(protector,output);
    }
    auto run_bulk(std::chrono::system_clock::time_point start_time)
    {  
        static auto protector = 0;
        subs.clear();
       
        for (unsigned int i = 0; i < bulk_size;i++)
        {
            std::string line;
            if (std::getline(std::cin,line))
            {
                if (i==0)
                    time = std::chrono::duration_cast<std::chrono::seconds>(start_time.time_since_epoch()).count();

                if (line == "{")
                {
                    std::string dynamic_block;
                    std::tie(protector,dynamic_block) = get_dynamic_block();
                    if (dynamic_block.size())
                        subs.push_back(dynamic_block);
                    if (protector)
                        break;
                }
                else if (line != "}" && line != "{")
                {
                    subs.push_back(line);
                }
            }
            else
            {
                protector = 1;
                break;
            }
            
        }
        if (subs.size())
            notify();
        return protector;
    }
    
    void start()
    {
        auto protector = 0;
        while (!protector)
        {
            protector  = run_bulk(std::chrono::system_clock::now());
        }
    }
    void notify()
    {
        for (const auto& it : _hndl)
            it->handler_run(subs);
    }
private:
    unsigned int bulk_size;
    unsigned long long time;
    std::vector<std::string> subs;
};


class bulk_output : public bulk_handler
{
public:
    bulk_output(bulk * _bulk)
    {
        _bulk->add_handler(this);
    }
    void handler_run (const  std::vector<std::string>& vectr)  override
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
    void handler_run(const std::vector<std::string>& vectr) override
    {
        std::cout << "bulk: ";
        for (auto it = vectr.cbegin() ; it !=vectr.cend();it++)
        {
            if (it != vectr.cbegin())
                std::cout << ", ";
            std::cout << *it;
        }
        std::cout << std::endl;
    }
};