1. GPIO (General Purpose Input/Output)
Chức năng: Sử dụng nút nhấn vật lý để điều khiển trạng thái bật/tắt của LED.

2. UART (Universal Asynchronous Receiver-Transmitter)
Chức năng: Giao tiếp nối tiếp với máy tính thông qua module chuyển đổi CP2102 để hiển thị log hoặc nhận lệnh.
Chân kết nối: TX, RX, GND.

3. I2C (Inter-Integrated Circuit)
Chức năng: Giao tiếp với cảm biến gia tốc ADXL345 để đọc dữ liệu trục X, Y, Z.
Chân kết nối: SDA, SCL.

4. SPI (Serial Peripheral Interface)
Chức năng: Giao tiếp giữa hai board STM32 (Master - Slave) để truyền nhận dữ liệu tốc độ cao.
Chân kết nối: MOSI, MISO, SCK, CS.

5. TIMER
Chức năng: Sử dụng ngắt Timer để tạo các khoảng thời gian chính xác, phục vụ việc tự động bật/tắt LED theo chu kỳ.

6. ADC (Analog to Digital Converter)
Chức năng: Đọc giá trị điện áp tương tự từ cảm biến nhiệt độ LM35 để tính toán nhiệt độ môi trường.

📺 Video Demo Tổng Hợp bài tập:
https://drive.google.com/drive/folders/1eHDi-OnSF_2o42w9VER3xrLBZewaVPjC?usp=drive_link
