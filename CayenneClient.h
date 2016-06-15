/*
The MIT License(MIT)

Cayenne Arduino Client Library
Copyright © 2016 myDevices

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
documentation files(the "Software"), to deal in the Software without restriction, including without limitation
the rights to use, copy, modify, merge, publish, distribute, sublicense, and / or sell copies of the Software,
and to permit persons to whom the Software is furnished to do so, subject to the following conditions :
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

This software uses open source blynk-library - see blynk-library/LICENSE
*/

#ifndef _CAYENNECLIENT_h
#define _CAYENNECLIENT_h

class CayenneClient
{
public:
	/**
	* Main Cayenne loop
	*/
	bool run()
	{
		return Blynk.run();
	}

	/**
	* Sends value to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	*/
	template <typename T>
	void virtualWrite(int pin, const T& value)
	{
		Blynk.virtualWrite(pin, value);
	}

	/**
	* Sends a measurement to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	* @param unit  Measurement unit
	* @param type  Measurement type
	*/
	void virtualWrite(int pin, const char* value, const char* unit, const char* type)
	{
		char mem[BLYNK_MAX_SENDBYTES];
		sprintf(mem, "%s,%s=%s", type, unit, value);
		Blynk.virtualWrite(pin, mem);
	}

	/**
	* Sends a measurement to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	* @param unit  Measurement unit
	* @param type  Measurement type
	*/
	void virtualWrite(int pin, int value, const char* unit, const char* type)
	{
		char str[2 + 8 * sizeof(value)];
		itoa(value, str, 10);
		virtualWrite(pin, str, unit, type);
	}

	/**
	* Sends a measurement to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	* @param unit  Measurement unit
	* @param type  Measurement type
	*/
	void virtualWrite(int pin, unsigned int value, const char* unit, const char* type)
	{
		char str[1 + 8 * sizeof(value)];
		utoa(value, str, 10);
		virtualWrite(pin, str, unit, type);
	}

	/**
	* Sends a measurement to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	* @param unit  Measurement unit
	* @param type  Measurement type
	*/
	void virtualWrite(int pin, long value, const char* unit, const char* type)
	{
		char str[2 + 8 * sizeof(value)];
		ltoa(value, str, 10);
		virtualWrite(pin, str, unit, type);
	}

	/**
	* Sends a measurement to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	* @param unit  Measurement unit
	* @param type  Measurement type
	*/
	void virtualWrite(int pin, unsigned long value, const char* unit, const char* type)
	{
		char str[1 + 8 * sizeof(value)];
		ultoa(value, str, 10);
		virtualWrite(pin, str, unit, type);
	}

#if defined(__AVR__) || defined (ARDUINO_ARCH_ARC32)

	/**
	* Sends a measurement to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	* @param unit  Measurement unit
	* @param type  Measurement type
	*/
	void virtualWrite(int pin, float value, const char* unit, const char* type)
	{
		char str[33];
		dtostrf(value, 5, 3, str);
		virtualWrite(pin, str, unit, type);
	}

	/**
	* Sends a measurement to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	* @param unit  Measurement unit
	* @param type  Measurement type
	*/
	void virtualWrite(int pin, double value, const char* unit, const char* type)
	{
		char str[33];
		dtostrf(value, 5, 3, str);
		virtualWrite(pin, str, unit, type);
	}

#else

	/**
	* Sends a measurement to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	* @param unit  Measurement unit
	* @param type  Measurement type
	*/
	void virtualWrite(int pin, float value, const char* unit, const char* type)
	{
		char str[33];
		snprintf(str, 33, "%2.3f", value);
		virtualWrite(pin, str, unit, type);
	}

	/**
	* Sends a measurement to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	* @param unit  Measurement unit
	* @param type  Measurement type
	*/
	void virtualWrite(int pin, double value, const char* unit, const char* type)
	{
		char str[33];
		snprintf(str, 33, "%2.3f", value);
		virtualWrite(pin, str, unit, type);
	}

#endif

	/**
	* Requests Server to re-send current values for all widgets.
	*/
	void syncAll()
	{
		Blynk.syncAll();
	}

	/**
	* Requests App or Server to re-send current value of a Virtual Pin.
	* This will cause the user-defined CAYENNE_IN handler to be called.
	*
	* @param pin  Virtual Pin number
	*/
	void syncVirtual(int pin)
	{
		Blynk.syncVirtual(pin);
	}

	/**
	* Sends a Celsius value to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	*/
	void celsiusWrite(int pin, float value)
	{
		virtualWrite(pin, value, CELSIUS, TEMPERATURE);
	}

	/**
	* Sends a Fahrenheit value to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	*/
	void fahrenheitWrite(int pin, float value)
	{
		virtualWrite(pin, value, FAHRENHEIT, TEMPERATURE);
	}

	/**
	* Sends a Kelvin value to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	*/
	void kelvinWrite(int pin, float value)
	{
		virtualWrite(pin, value, KELVIN, TEMPERATURE);
	}

	/**
	* Sends a Lux value to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	*/
	void luxWrite(int pin, float value)
	{
		virtualWrite(pin, value, LUX, LUMINOSITY);
	}

	/**
	* Sends a Pascal value to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	*/
	void pascalWrite(int pin, float value)
	{
		virtualWrite(pin, value, PASCAL, BAROMETRIC_PRESSURE);
	}

	/**
	* Sends a Hectopascal value to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	*/
	void hectoPascalWrite(int pin, float value)
	{
		virtualWrite(pin, value, HECTOPASCAL, BAROMETRIC_PRESSURE);
	}

	/**
	* Sends a Relative Humidity value to a Virtual Pin
	*
	* @param pin  Virtual Pin number
	* @param value  Value to be sent
	*/
	void relativeHumidityWrite(int pin, float value)
	{
		virtualWrite(pin, value, RELATIVE_HUMIDITY, HUMIDITY);
	}
};

#endif