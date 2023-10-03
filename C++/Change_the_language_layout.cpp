#include <Windows.h>
#include <setupapi.h>
#include <iostream>

int main() {
    // Enumerate all input devices
    HDEVINFO deviceInfoSet = SetupDiGetClassDevs(&GUID_DEVCLASS_HIDCLASS, 0, 0, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE);

    if (deviceInfoSet == INVALID_HANDLE_VALUE) {
        std::cerr << "Error enumerating devices." << std::endl;
        return 1;
    }

    // Iterate through devices and identify keyboards
    SP_DEVINFO_DATA deviceInfoData;
    deviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);

    // TODO: Identify keyboards based on device information

    // Capture and process input events
    RAWINPUTDEVICE rawInputDevice[1];
    rawInputDevice[0].usUsagePage = 1; // Generic Desktop Controls
    rawInputDevice[0].usUsage = 6;     // Keyboard
    rawInputDevice[0].dwFlags = RIDEV_INPUTSINK;
    rawInputDevice[0].hwndTarget = NULL;

    if (!RegisterRawInputDevices(rawInputDevice, 1, sizeof(RAWINPUTDEVICE))) {
        std::cerr << "Error registering raw input devices." << std::endl;
        return 1;
    }

    while (true) {
        // TODO: Capture and process input events, and determine the source keyboard
    }

    return 0;
}
