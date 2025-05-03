#ifndef FEGN_DATA_HPP
#define FEGN_DATA_HPP

#include <string>
#include <map>
#include <vector>
#include <memory>

namespace Fegn {
    // Veri deposu
    class DataStore {
    private:
        std::map<std::string, std::vector<std::map<std::string, std::string>>> stores;
        
    public:
        // Veri ekleme
        void add(const std::string& storeName, const std::map<std::string, std::string>& data) {
            if (stores.find(storeName) == stores.end()) {
                stores[storeName] = std::vector<std::map<std::string, std::string>>();
            }
            stores[storeName].push_back(data);
        }
        
        // Veri alma
        std::vector<std::map<std::string, std::string>> getAll(const std::string& storeName) {
            if (stores.find(storeName) != stores.end()) {
                return stores[storeName];
            }
            return std::vector<std::map<std::string, std::string>>();
        }
        
        // Veri silme
        void remove(const std::string& storeName, int index) {
            if (stores.find(storeName) != stores.end() && index < stores[storeName].size()) {
                stores[storeName].erase(stores[storeName].begin() + index);
            }
        }
    };
    
    // Veri filtreleme
    class DataFilter {
    public:
        std::vector<std::map<std::string, std::string>> filter(
            const std::vector<std::map<std::string, std::string>>& data,
            const std::string& key,
            const std::string& value) {
            
            std::vector<std::map<std::string, std::string>> result;
            for (const auto& item : data) {
                if (item.find(key) != item.end() && item[key] == value) {
                    result.push_back(item);
                }
            }
            return result;
        }
    };
}

#endif // FEGN_DATA_HPP
