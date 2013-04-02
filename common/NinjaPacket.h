#ifndef NINJAPACKET_H
#define NINJAPACKET_H

#if (ARDUINO >= 100)
#include <Arduino.h>
#else
#include <WProgram.h>
#endif

#define TYPE_DEVICE		1
#define TYPE_PLUGIN		2
#define TYPE_UNPLUG		3
#define TYPE_ACK		4
#define TYPE_ERROR		5

class NinjaPacket
{
private:
	int					m_nType;
	int					m_nGuid;
	int					m_nDevice;
	
	byte				m_nEncoding;
	word				m_nTiming;
	unsigned long long	m_nData;
	

	static char*		DELIMITERS;

private:
	void				printData();
	void				printDataHex();
	void 				printHex( unsigned long long nDataToPrint, int nNumBytesRequired);

public:
	NinjaPacket();

	int					getType();
	void				setType(int nType);
	int					getGuid();
	void				setGuid(int nGuid);
	int					getDevice();
	void				setDevice(int nDevice);
	unsigned long long	getData();
	void				setData(unsigned long long nData);
	byte				getEncoding();
	void				setEncoding(byte nEncoding);
	word				getTiming();
	void 				setTiming(word nTiming);

	bool				fromJson(char* strJson);
	void				printToSerial();
};

#endif