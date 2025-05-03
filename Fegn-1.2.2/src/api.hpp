#ifndef FEGN_API_HPP
#define FEGN_API_HPP

#include <string>
#include <map>
#include <memory>

namespace Fegn {
    // API isteği
    class Request {
    public:
        std::string method;
        std::string url;
        std::map<std::string, std::string> headers;
        std::string body;
        
        Request(const std::string& method, const std::string& url)
            : method(method), url(url) {}
        
        void addHeader(const std::string& key, const std::string& value) {
            headers[key] = value;
        }
        
        void setBody(const std::string& body) {
            this->body = body;
        }
    };
    
    // API yanıt
    class Response {
    public:
        int status;
        std::string body;
        
        Response(int status, const std::string& body)
            : status(status), body(body) {}
    };
    
    // API yöneticisi
    class ApiManager {
    private:
        std::string baseUrl;
        std::map<std::string, std::string> headers;
        
    public:
        ApiManager(const std::string& baseUrl)
            : baseUrl(baseUrl) {}
        
        void addHeader(const std::string& key, const std::string& value) {
            headers[key] = value;
        }
        
        Response get(const std::string& endpoint) {
            Request request("GET", baseUrl + endpoint);
            // GET isteği yap ve yanıt döndür
            return Response(200, "{}");
        }
        
        Response post(const std::string& endpoint, const std::string& data) {
            Request request("POST", baseUrl + endpoint);
            request.setBody(data);
            // POST isteği yap ve yanıt döndür
            return Response(200, "{}");
        }
    };
}

#endif // FEGN_API_HPP
