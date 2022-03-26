#include <iomanip>
#include <sstream>
#include <vector>
#include <ctime>

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/rotating_file_sink.h>
#include <spdlog/spdlog.h>

#include <blueberry/log.hh>

static std::vector<spdlog::sink_ptr> _sinks;
static std::shared_ptr<spdlog::logger> _core_logger;

void blueberry::logger::init()
{
    auto _stdout_sink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
#ifdef _WIN32
    _stdout_sink->set_color(spdlog::level::info, 0b1010);
#else
    _stdout_sink->set_color(spdlog::level::info, "\033[92m");
#endif // _WIN32

    _sinks.push_back(_stdout_sink);
    auto t = std::time(nullptr);
    auto tm = *std::localtime(&t);
    std::ostringstream ss; ss << "logs/blueberry_log " << std::put_time(&tm, "%d-%m-%Y %H-%M-%S");
    std::string file = ss.str();
    _sinks.push_back(std::make_shared<spdlog::sinks::rotating_file_sink_mt>(file, 1024 * 1024 * 5, 3));
    _core_logger = std::make_shared<spdlog::logger>("logger_core", begin(_sinks), end(_sinks));
    _core_logger->set_pattern("%a %b %H:%M:%S\n%^[%l] %v%$");
    spdlog::register_logger(_core_logger);
}
