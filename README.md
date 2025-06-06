# ESP32-WiFi-Data-Logger-to-ThingSpeak-Using-Arduino
Arduino-based ESP-01 WiFi module sends sensor data to ThingSpeak for remote monitoring via HTTP requests.

## Features

- Connects ESP32 to WiFi using built-in WiFi capabilities
- Sends data periodically to ThingSpeak channel using HTTP GET requests
- Simple and efficient code using ESP32’s native WiFi support
- Adjustable WiFi credentials and ThingSpeak API key

## Hardware Required

- ESP32 Development Board
- USB cable for programming and power

## How to Use

1. Update the `WIFI_SSID`, `WIFI_PASS`, and `API` variables in the code with your WiFi credentials and ThingSpeak API key.
2. Upload the sketch to your ESP32 board.
3. Open the Serial Monitor at 115200 baud to see debug messages.
4. The ESP32 will connect to WiFi and send incremental dummy data to ThingSpeak every 20 seconds.

## Code Explanation

- Uses the ESP32’s built-in WiFi library for network connectivity.
- Establishes a TCP connection with ThingSpeak’s server.
- Sends HTTP GET requests with data fields.
- Closes the connection after each transmission.

## Notes

- Ensure your ESP32 board is correctly set up in the Arduino IDE.
- ThingSpeak allows limited updates per channel (typically once every 15 seconds).
- This example sends dummy data; replace with sensor readings as needed.

## References

- [ThingSpeak API Documentation](https://thingspeak.com/docs/api/)
- [ESP32 WiFi Library](https://www.arduino.cc/en/Reference/WiFi)

## License

This project is for educational and hobby use. Feel free to modify and share!

