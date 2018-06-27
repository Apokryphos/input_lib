#pragma once

#include "input_lib/device_type.hpp"

namespace InputLib
{
class Device
{
    DeviceType mDeviceType;

public:
    Device(const DeviceType deviceType)
    : mDeviceType(deviceType) {
    }

    virtual ~Device() {}

    DeviceType getDeviceType() const {
        return mDeviceType;
    }
};
}
