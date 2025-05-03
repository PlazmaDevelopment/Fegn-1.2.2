#ifndef FEGN_EVENT_HPP
#define FEGN_EVENT_HPP

#include <string>
#include <map>
#include <memory>
#include <functional>

namespace Fegn {
    // Olay yöneticisi
    class EventManager {
    private:
        std::map<std::string, std::vector<std::function<void(const std::map<std::string, std::string>&)>>> listeners;
        
    public:
        // Olay dinleyici ekleme
        void on(const std::string& eventName, const std::function<void(const std::map<std::string, std::string>&)>& callback) {
            if (listeners.find(eventName) == listeners.end()) {
                listeners[eventName] = std::vector<std::function<void(const std::map<std::string, std::string>&)>>();
            }
            listeners[eventName].push_back(callback);
        }
        
        // Olay tetikleme
        void trigger(const std::string& eventName, const std::map<std::string, std::string>& data) {
            if (listeners.find(eventName) != listeners.end()) {
                for (const auto& callback : listeners[eventName]) {
                    callback(data);
                }
            }
        }
        
        // Olay dinleyici kaldırma
        void off(const std::string& eventName, const std::function<void(const std::map<std::string, std::string>&)>& callback) {
            if (listeners.find(eventName) != listeners.end()) {
                listeners[eventName].erase(
                    std::remove(listeners[eventName].begin(), listeners[eventName].end(), callback),
                    listeners[eventName].end()
                );
            }
        }
    };
    
    // Olay tetikleyici
    class EventTrigger {
    private:
        std::shared_ptr<EventManager> manager;
        
    public:
        EventTrigger(std::shared_ptr<EventManager> manager) : manager(manager) {}
        
        void trigger(const std::string& eventName, const std::map<std::string, std::string>& data) {
            manager->trigger(eventName, data);
        }
    };
}

#endif // FEGN_EVENT_HPP
