#ifndef USB_PHONE_DEVICE_HPP
#define USB_PHONE_DEVICE_HPP
class __USBB2KDevice {
private:

	int _USBB2Ksocket;
	void InitSocket();
	
public:
	__USBB2KDevice();
	void Ringing();
	void RingOff();
	void SwitchToPSTN();
	void SwitchToUSB();
	void SetHandsetOnKeyEnable();
};
#endif
