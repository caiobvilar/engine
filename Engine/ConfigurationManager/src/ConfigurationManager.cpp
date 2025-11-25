#include "ConfigurationManager.hpp"
#include <fstream>
#include <iostream>
#include <spdlog/spdlog.h>

ConfigurationManager* ConfigurationManager::instance = nullptr;

ConfigurationManager::ConfigurationManager(const std::string& filePath)
{
    spdlog::info("Creating ConfigurationManager instance...");
    spdlog::info("Loading configuration file: {}", filePath);
}

/**
 * @brief Retrieves the singleton instance of ConfigurationManager.
 *
 * This function returns the singleton instance of the ConfigurationManager
 * class. If the instance does not exist, it will be created using the provided
 * file path.
 *
 * @param filePath The path to the configuration file.
 * @return A reference to the singleton instance of ConfigurationManager.
 */
ConfigurationManager& ConfigurationManager::getInstance()
{
    if (instance == nullptr)
    {
        instance = new ConfigurationManager();
    }
    return *instance;
}

nlohmann::json ConfigurationManager::getConfig() const { return configData; }

int ConfigurationManager::loadConfig(const std::string& filePath)
{
    std::ifstream configFile(filePath);
    if (!configFile.is_open())
    {
        spdlog::error(
            "Could not open the config file: {} {}", filePath, strerror(errno));
        return -1;
    } else
    {
        try
        {
            configFile >> this->configData;
        } catch (const nlohmann::json::parse_error& e)
        {
            spdlog::error("Error parsing the config file: {}", e.what());
            return -1;
        }
    }
    return 0;
}
void ConfigurationManager::printConfig() const
{
    spdlog::info("Current Configuration:");
    spdlog::info("{}", this->configData.dump(4));
}

int ConfigurationManager::GetDefaultFPS()
{
    if (configData.contains("default_fps") &&
        configData["default_fps"].is_number_integer())
    {
        return configData["default_fps"].get<int>();
    } else
    {
        spdlog::warn(
            "default_fps not found in configuration. Using default value 60.");
        return 60; // Default FPS
    }
}

int ConfigurationManager::GetWindowWidth()
{
    if (configData.contains("window_width") &&
        configData["window_width"].is_number_integer())
    {
        return configData["window_width"].get<int>();
    } else
    {
        spdlog::warn("window_width not found in configuration. Using default "
                     "value 1280.");
        return 1280; // Default width
    }
}

int ConfigurationManager::GetWindowHeight()
{
    if (configData.contains("window_height") &&
        configData["window_height"].is_number_integer())
    {
        return configData["window_height"].get<int>();
    } else
    {
        spdlog::warn("window_height not found in configuration. Using default "
                     "value 720.");
        return 720; // Default height
    }
}

std::string ConfigurationManager::GetWindowName()
{
    if (configData.contains("window_name") &&
        configData["window_name"].is_string())
    {
        return configData["window_name"].get<std::string>();
    } else
    {
        spdlog::warn("window_name not found in configuration. Using default "
                     "value 'Main Window'.");
        return "Main Window"; // Default window name
    }
}

char ConfigurationManager::GetDefaultExitChar()
{
    if (configData.contains("default_exit_char") &&
        configData["default_exit_char"].is_string() &&
        configData["default_exit_char"].get<std::string>().length() == 1)
    {
        return configData["default_exit_char"].get<std::string>()[0];
    } else
    {
        spdlog::warn("default_exit_char not found in configuration. Using "
                     "default value 'Q'.");
        return 'Q'; // Default exit character
    }
}