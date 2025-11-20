#ifndef __CONFIGURATIONMANAGER_HPP__
#define __CONFIGURATIONMANAGER_HPP__

#include <nlohmann/json.hpp>
#include <string>

class ConfigurationManager
{
  public:
    static ConfigurationManager& getInstance(const std::string& filePath = "");

    nlohmann::json getConfig() const;
    int loadConfig(const std::string& filePath);

    int GetDefaultFPS();
    int GetWindowWidth();
    int GetWindowHeight();
    std::string GetWindowName();
    char GetDefaultExitChar();
    void printConfig() const;

  private:
    ConfigurationManager() = default;
    ConfigurationManager(const std::string& filePath);

    // Delete copy constructor and assignment operator
    ConfigurationManager(const ConfigurationManager&) = delete;
    ConfigurationManager& operator=(const ConfigurationManager&) = delete;

    nlohmann::json configData;
};

#endif // __CONFIGURATIONMANAGER_HPP__