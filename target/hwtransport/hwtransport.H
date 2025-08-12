#pragma once

#include <targeting/target.H>

namespace HWTRANSPORT
{
class HwTransportInterface
{
public:
        static int getCfam(std::string& path, uint32_t addr, uint32_t& val); 
        static int putCfam(std::string& path, uint32_t addr, uint32_t val);
};
} // namespace HwTransport
