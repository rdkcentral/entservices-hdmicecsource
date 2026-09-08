#pragma once

#include <cstdint>
#include <string>

#include "dsDisplay.h"
#include "hdmiIn.hpp"
#include "videoOutputPort.hpp"

namespace device {

class Host {
public:
    class IDisplayDeviceEvents {
    public:
        virtual ~IDisplayDeviceEvents() = default;
        virtual void OnDisplayHDMIHotPlug(dsDisplayEvent_t displayEvent) = 0;
    };

    class IHdmiInEvents {
    public:
        virtual ~IHdmiInEvents() = default;
        virtual void OnHdmiInEventHotPlug(dsHdmiInPort_t port, bool isConnected) = 0;
    };

    static Host& getInstance()
    {
        static Host instance;
        return instance;
    }

    template<typename T>
    void Register(T*, const std::string&)
    {
    }

    template<typename T>
    void UnRegister(T*)
    {
    }

    std::string getDefaultVideoPortName() const
    {
        return "HDMI0";
    }

    VideoOutputPort getVideoOutputPort(const char*)
    {
        return VideoOutputPort();
    }

private:
    Host() = default;
    ~Host() = default;
    Host(const Host&) = delete;
    Host& operator=(const Host&) = delete;
};

} // namespace device
