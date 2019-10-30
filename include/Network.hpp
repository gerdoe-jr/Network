#ifndef Network_hpp
#define Network_hpp

#include <cstdio>
#include <string>
#include <map>

namespace wtlgo {

class Network{
public:
    static Network& instance();
    
    Network(Network const&) = delete;
    void operator=(Network const&) = delete;
    
    void set_proxy(const std::string& proxy);
    
    std::string request(std::string url, const std::map<std::string, std::string>& args = {}, bool post = false) const;
    
    std::string upload(std::string url, const std::string& fieldname, const std::string& filename) const;
    
    bool download(const std::string& url, const std::string& save_as = "") const;
    
private:
    std::string proxy;

    Network();
    ~Network();
    
    static size_t string_writer(char* contents, size_t size, size_t nmemb, std::string* stream);
    static size_t file_writer(void* contents, size_t size, size_t nmemb, FILE* stream);
};

}

#endif /* Network_hpp */
