# STM32 Microcontroller – Peripheral Interface & Communication Projects

## 📌 Giới thiệu dự án

Repository này tổng hợp các bài tập thực hành lập trình vi điều khiển **STM32**, tập trung vào việc tìm hiểu, cấu hình và ứng dụng các ngoại vi (Peripherals) cơ bản trong hệ thống nhúng (Embedded Systems).

Thông qua các bài thực hành, dự án hướng đến việc xây dựng nền tảng kiến thức về lập trình vi điều khiển, điều khiển thiết bị ngoại vi, giao tiếp giữa các module phần cứng và xử lý tín hiệu từ cảm biến.

Các chương trình được phát triển nhằm giúp hiểu rõ hơn cách vi điều khiển STM32 tương tác với thế giới bên ngoài thông qua các giao tiếp phần cứng và cơ chế xử lý dữ liệu.

## 🎯 Mục tiêu thực hiện

- Tìm hiểu kiến trúc và nguyên lý hoạt động cơ bản của vi điều khiển STM32.
- Làm quen với các ngoại vi GPIO, UART, I2C, SPI, TIMER và ADC.
- Thực hành cấu hình thanh ghi (Register-level Programming) và điều khiển ngoại vi.
- Nắm được nguyên lý truyền nhận dữ liệu giữa vi điều khiển với máy tính, cảm biến và các thiết bị ngoại vi.
- Tìm hiểu cơ chế ngắt (Interrupt) và cách xử lý các sự kiện phần cứng.
- Rèn luyện kỹ năng đọc Datasheet, Reference Manual và Debug chương trình nhúng.
- Từng bước xây dựng nền tảng để phát triển các hệ thống Embedded và ứng dụng điều khiển trong lĩnh vực Cơ điện tử.

## 🛠️ Nội dung các bài thực hành

### 1. GPIO (General Purpose Input/Output)

**Chức năng:** Điều khiển trạng thái bật/tắt của LED thông qua nút nhấn vật lý.

**Nội dung thực hiện:**
- Cấu hình các chân GPIO ở chế độ Input và Output.
- Sử dụng nút nhấn để tạo tín hiệu đầu vào điều khiển vi điều khiển.
- Đọc trạng thái logic của chân GPIO để xác định trạng thái nhấn hoặc nhả nút.
- Điều khiển LED thông qua việc thay đổi mức logic HIGH/LOW tại chân GPIO.
- Tìm hiểu cơ chế điện trở kéo lên (Pull-up) và kéo xuống (Pull-down).
- Tìm hiểu hiện tượng dội phím (Button Debouncing) khi sử dụng nút nhấn cơ học.

**Kết quả:** Có thể sử dụng nút nhấn vật lý để điều khiển trạng thái LED, qua đó hiểu được nguyên lý giao tiếp cơ bản giữa STM32 và các thiết bị đầu vào/đầu ra.

### 2. UART (Universal Asynchronous Receiver-Transmitter)

**Chức năng:** Thiết lập giao tiếp nối tiếp giữa vi điều khiển STM32 và máy tính thông qua module chuyển đổi USB-to-UART CP2102.

**Chân kết nối:** TX, RX, GND.

**Nội dung thực hiện:**
- Tìm hiểu nguyên lý truyền nhận dữ liệu nối tiếp không đồng bộ.
- Cấu hình các thông số truyền thông như Baud Rate, Data Bits, Parity và Stop Bits.
- Thiết lập kết nối UART giữa STM32 và máy tính thông qua CP2102.
- Truyền dữ liệu từ STM32 lên máy tính để hiển thị thông tin Debug và Log.
- Nhận dữ liệu từ máy tính để thực hiện các lệnh điều khiển vi điều khiển.
- Tìm hiểu cơ chế truyền nhận dữ liệu bằng phương pháp Polling và Interrupt.

**Kết quả:** Xây dựng được kênh giao tiếp hai chiều giữa STM32 và máy tính, hỗ trợ giám sát trạng thái hệ thống, kiểm tra chương trình và điều khiển thiết bị thông qua giao diện Serial Terminal.

### 3. I2C (Inter-Integrated Circuit)

**Chức năng:** Giao tiếp giữa vi điều khiển STM32 và cảm biến gia tốc ADXL345 để thu thập dữ liệu chuyển động theo ba trục X, Y, Z.

**Chân kết nối:** SDA, SCL.

**Thiết bị sử dụng:** STM32, cảm biến gia tốc ADXL345.

**Nội dung thực hiện:**
- Tìm hiểu giao thức truyền thông I2C và mô hình giao tiếp Master-Slave.
- Cấu hình chân GPIO ở chế độ Alternate Function Open-Drain.
- Tìm hiểu vai trò của hai đường tín hiệu SDA (Serial Data) và SCL (Serial Clock).
- Thực hiện quá trình khởi tạo và giao tiếp với cảm biến ADXL345.
- Đọc các thanh ghi chứa dữ liệu gia tốc theo ba trục X, Y và Z.
- Tìm hiểu địa chỉ thiết bị, thanh ghi dữ liệu và cơ chế ACK/NACK trong I2C.
- Xử lý dữ liệu thu được để phục vụ việc theo dõi hướng và trạng thái chuyển động của cảm biến.

**Kết quả:** Thu thập được dữ liệu gia tốc từ cảm biến ADXL345 thông qua giao thức I2C, giúp làm quen với phương pháp giao tiếp và khai thác dữ liệu từ các cảm biến trong hệ thống nhúng.

### 4. SPI (Serial Peripheral Interface)

**Chức năng:** Thiết lập giao tiếp truyền nhận dữ liệu giữa hai board STM32 theo mô hình Master-Slave.

**Chân kết nối:** MOSI, MISO, SCK, CS/SS.

**Nội dung thực hiện:**
- Tìm hiểu nguyên lý truyền thông nối tiếp đồng bộ SPI.
- Phân biệt vai trò của thiết bị Master và Slave trong quá trình giao tiếp.
- Cấu hình các chân MOSI, MISO, SCK và CS.
- Thiết lập các thông số SPI như Clock Polarity (CPOL), Clock Phase (CPHA) và tốc độ xung Clock.
- Thực hiện truyền dữ liệu từ Master đến Slave thông qua đường MOSI.
- Thực hiện nhận dữ liệu từ Slave thông qua đường MISO.
- Tìm hiểu cơ chế lựa chọn thiết bị Slave thông qua tín hiệu Chip Select.
- Kiểm tra tính chính xác của dữ liệu trong quá trình truyền nhận giữa hai vi điều khiển.

**Kết quả:** Thiết lập được mô hình giao tiếp giữa hai board STM32, qua đó tìm hiểu cách tổ chức truyền nhận dữ liệu đồng bộ và vai trò của từng đường tín hiệu trong giao thức SPI.

### 5. TIMER (Timer/Counter Peripheral)

**Chức năng:** Sử dụng bộ định thời của STM32 để tạo khoảng thời gian chính xác, điều khiển các hoạt động theo chu kỳ và xử lý sự kiện bằng ngắt Timer.

**Nội dung thực hiện:**
- Tìm hiểu cấu trúc và nguyên lý hoạt động của bộ định thời trong STM32.
- Cấu hình các thanh ghi Prescaler (PSC) và Auto-Reload Register (ARR).
- Thiết lập chu kỳ đếm và tần số hoạt động của Timer.
- Sử dụng cơ chế Update Interrupt để tạo ngắt định kỳ.
- Xây dựng bộ đếm thời gian bằng biến toàn cục và xử lý trong hàm Interrupt Handler.
- Điều khiển LED bật/tắt theo chu kỳ mà không cần sử dụng các hàm Delay làm chương trình bị chặn.
- Tìm hiểu cơ chế ngắt phần cứng và cách phối hợp giữa hàm main() với các hàm phục vụ ngắt.

**Kết quả:** Tạo được các khoảng thời gian định kỳ bằng Timer Interrupt, đồng thời hiểu được cách sử dụng ngắt để xử lý nhiều tác vụ trong chương trình nhúng một cách hiệu quả hơn.

### 6. ADC (Analog-to-Digital Converter)

**Chức năng:** Đọc tín hiệu điện áp tương tự từ cảm biến nhiệt độ LM35 và chuyển đổi thành dữ liệu số để tính toán nhiệt độ môi trường.

**Thiết bị sử dụng:** Cảm biến nhiệt độ LM35.

**Nội dung thực hiện:**
- Tìm hiểu nguyên lý chuyển đổi tín hiệu Analog sang Digital.
- Cấu hình chân GPIO tương ứng ở chế độ Analog Input.
- Thiết lập các thông số ADC như độ phân giải, thời gian lấy mẫu và kênh chuyển đổi.
- Đọc giá trị ADC từ tín hiệu điện áp đầu ra của cảm biến LM35.
- Tìm hiểu mối quan hệ giữa điện áp đầu ra và nhiệt độ đo được.
- Thực hiện chuyển đổi giá trị ADC thành điện áp thực tế.
- Tính toán và xử lý dữ liệu để xác định nhiệt độ môi trường.

**Kết quả:** Đọc được tín hiệu Analog từ cảm biến LM35, chuyển đổi thành giá trị số và tính toán nhiệt độ thông qua bộ ADC tích hợp trên STM32.

## 🔧 Phần cứng sử dụng

| STT | Thiết bị | Chức năng |
|---|---|---|
| 1 | STM32 Development Board | Vi điều khiển trung tâm |
| 2 | CP2102 USB-to-UART | Chuyển đổi giao tiếp USB sang UART |
| 3 | ADXL345 | Cảm biến gia tốc 3 trục |
| 4 | LM35 | Cảm biến nhiệt độ Analog |
| 5 | LED | Thiết bị đầu ra hiển thị trạng thái |
| 6 | Push Button | Thiết bị đầu vào điều khiển |
| 7 | STM32 Slave Board | Vi điều khiển phụ trong giao tiếp SPI |

## 💻 Công cụ và môi trường phát triển

- **Programming Language:** C.
- **IDE:** STM32CubeIDE.
- **Microcontroller:** STM32 Series.
- **Debugging:** ST-Link.
- **Communication:** UART, I2C, SPI.
- **Documentation:** STM32 Datasheet và Reference Manual.

## 📚 Kiến thức và kỹ năng đạt được

Sau khi hoàn thành các bài thực hành, các kiến thức và kỹ năng được củng cố bao gồm:

- **Embedded C Programming:** Sử dụng ngôn ngữ C để xây dựng chương trình điều khiển vi điều khiển.
- **Register-level Programming:** Làm quen với việc cấu hình và thao tác trực tiếp trên các thanh ghi ngoại vi.
- **Peripheral Configuration:** Hiểu cách thiết lập và sử dụng các ngoại vi tích hợp trên STM32.
- **Communication Protocols:** Nắm được nguyên lý hoạt động của UART, I2C và SPI.
- **Interrupt Handling:** Hiểu cơ chế ngắt và cách xử lý sự kiện phần cứng.
- **Sensor Interfacing:** Thực hiện giao tiếp, thu thập và xử lý dữ liệu từ cảm biến.
- **Hardware Debugging:** Rèn luyện kỹ năng kiểm tra kết nối, phân tích tín hiệu và khắc phục lỗi phần cứng/phần mềm.

## 📺 Video Demo tổng hợp

Các video dưới đây ghi lại quá trình thực hiện và kết quả hoạt động thực tế của các bài tập:

**Google Drive:**  
https://drive.google.com/drive/folders/1eHDi-OnSF_2o42w9VER3xrLBZewaVPjC?usp=drive_link
