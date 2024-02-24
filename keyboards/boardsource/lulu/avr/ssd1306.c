#include <stdint.h>
#include <stddef.h>
#include "ssd1306.h"
#include "progmem.h"
#include "i2c_master.h"

const uint8_t output_frame_1[] PROGMEM = {0xff, 131, 0x3f, 0x9f, 0xcf, 0xef, 0xe7, 0xe7, 0xf3, 0xf3, 0xfb, 0xfb, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xf9, 0xfb, 0xfb, 0xf3, 0xf3, 0xe7, 0xe7, 0xef, 0xcf, 0x9f, 0x3f, 0x7f, 0xff, 98, 0x00, 2, 0xff, 6, 0x83, 0x01, 0x83, 0xc7, 0xff, 7, 0x83, 0x01, 0x83, 0xc7, 0xff, 7, 0x00, 2, 0xff, 97, 0xfc, 0xf9, 0xf3, 0xe7, 0xef, 0xcf, 0xcf, 0x9f, 0x9f, 0xbf, 0xbf, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xbf, 0xbf, 0x9f, 0x9f, 0xcf, 0xcf, 0xef, 0xe7, 0xf3, 0xf9, 0xfc, 0xfe, 0xff, 96};
#define OUTPUT_FRAME_1_COMPRESSION 3

// [Compressed to 16.40625% of original. Len = 84 vs 512]

const uint8_t output_frame_2[] PROGMEM = {0xff, 166, 0x3f, 0x3f, 0xbf, 0x9f, 0x9f, 0xdf, 0xdf, 0xdf, 0xcf, 0xcf, 0xcf, 0xcf, 0xcf, 0xdf, 0xdf, 0xdf, 0x9f, 0x9f, 0xbf, 0x3f, 0x3f, 0x7f, 0xff, 101, 0x03, 0xf1, 0xfc, 0xfe, 0xfe, 0xff, 3, 0x0f, 0x07, 0x0f, 0x9f, 0xff, 7, 0x0f, 0x07, 0x0f, 0x9f, 0xff, 4, 0xfe, 0xfc, 0xf1, 0x03, 0x0f, 0xff, 97, 0xf8, 0xf3, 0xf7, 0xe7, 0xcf, 0xcf, 0xdf, 0x9f, 0x9e, 0xbf, 0xbf, 0xbf, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xbf, 0xbf, 0xbe, 0x9f, 0x9f, 0xdf, 0xcf, 0xcf, 0xe7, 0xf7, 0xf3, 0xf8, 0xfc, 0xff, 64};
#define OUTPUT_FRAME_2_COMPRESSION 3

// [Compressed to 16.40625% of original. Len = 84 vs 512]

const uint8_t output_frame_3[] PROGMEM = {0xff, 73, 0x7f, 0x3f, 0xbf, 0xbf, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0x9f, 0xbf, 0xbf, 0x3f, 0x7f, 0x7f, 0xff, 105, 0x8f, 0xe7, 0xf3, 0xf9, 0xfc, 0xfe, 0xfe, 0xff, 2, 0xff, 11, 0xff, 3, 0xfe, 0xfc, 0xf9, 0xf3, 0xe7, 0x8f, 0x1f, 0xff, 97, 0x00, 2, 0xff, 6, 0xe0, 0xc0, 0xe0, 0xf1, 0xff, 7, 0xe0, 0xc0, 0xe0, 0xf1, 0xff, 7, 0x00, 2, 0xff, 98, 0xfc, 0xf9, 0xf3, 0xe7, 0xef, 0xcf, 0xdf, 0x9f, 0x9f, 0xbf, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xbf, 0x9f, 0x9f, 0xdf, 0xcf, 0xef, 0xe7, 0xf3, 0xf9, 0xfc, 0xfe, 0xff, 33};
#define OUTPUT_FRAME_3_COMPRESSION 3

// [Compressed to 17.96875% of original. Len = 92 vs 512]

const uint8_t output_frame_4[] PROGMEM = {0xff, 239, 0x7f, 0x7f, 0x7f, 0x7f, 0xff, 110, 0x0f, 0xe7, 0xe7, 0xf3, 0xf9, 0xf9, 0xfd, 0x3c, 0x1c, 0x1e, 0x1e, 0x3e, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0xfe, 0x3e, 0x1e, 0x1e, 0x1e, 0x3c, 0xfc, 0xfd, 0xf9, 0xf9, 0xf3, 0xe7, 0xe7, 0x0f, 0xff, 97, 0xf8, 0xf3, 0xf3, 0xe7, 0xcf, 0xcf, 0xdf, 0x9e, 0x9c, 0xbc, 0xbc, 0xbe, 0xbf, 0x3f, 0x3f, 0x3f, 0x3f, 0x3f, 0xbe, 0xbc, 0xbc, 0xbc, 0x9e, 0x9f, 0xdf, 0xcf, 0xcf, 0xe7, 0xf3, 0xf3, 0xf8};
#define OUTPUT_FRAME_4_COMPRESSION 3

// [Compressed to 14.0625% of original. Len = 72 vs 512]

const uint8_t* output_images[]             = {output_frame_1, output_frame_2, output_frame_3, output_frame_4};
const int      output_images_compression[] = {OUTPUT_FRAME_1_COMPRESSION, OUTPUT_FRAME_2_COMPRESSION, OUTPUT_FRAME_3_COMPRESSION, OUTPUT_FRAME_4_COMPRESSION};

#define I2C_CMD 0x00
#define I2C_DATA 0x40
// ------------------------------------------------------------------------------------
#define SSD1306_ADDR 0x3C

// Command definition
// ------------------------------------------------------------------------------------
#define SSD1306_COMMAND 0x80        // Continuation bit=1, D/C=0; 1000 0000
#define SSD1306_COMMAND_STREAM 0x00 // Continuation bit=0, D/C=0; 0000 0000
#define SSD1306_DATA 0xC0           // Continuation bit=1, D/C=1; 1100 0000
#define SSD1306_DATA_STREAM 0x40    // Continuation bit=0, D/C=1; 0100 0000

#define SSD1306_SET_MUX_RATIO 0xA8    // Set MUX ratio to N+1 MUX, N=A[5:0] : from 16MUX to 64MUX
#define SSD1306_DISPLAY_OFFSET 0xD3   // Set Display Offset
#define SSD1306_DISPLAY_ON 0xAF       // Display ON in normal mode
#define SSD1306_DISPLAY_OFF 0xAE      // Display OFF (sleep mode)
#define SSD1306_DIS_ENT_DISP_ON 0xA4  // Entire Display ON, Output ignores RAM content
#define SSD1306_DIS_IGNORE_RAM 0xA5   // Resume to RAM content display, Output follows RAM content
#define SSD1306_DIS_NORMAL 0xA6       // Normal display, 0 in RAM: OFF in display panel, 1 in RAM: ON in display panel
#define SSD1306_DIS_INVERSE 0xA7      // Inverse display, 0 in RAM: ON in display panel, 1 in RAM: OFF in display panel
#define SSD1306_DEACT_SCROLL 0x2E     // Stop scrolling that is configured by command 26h/27h/29h/2Ah
#define SSD1306_ACTIVE_SCROLL 0x2F    // Start scrolling that is configured by the scrolling setup commands:26h/27h/29h/2Ah
#define SSD1306_SET_START_LINE 0x40   // Set Display Start Line
#define SSD1306_MEMORY_ADDR_MODE 0x20 // Set Memory, Addressing Mode
#define SSD1306_SET_COLUMN_ADDR 0x21  // Set Column Address
#define SSD1306_SET_PAGE_ADDR 0x22    // Set Page Address
#define SSD1306_SEG_REMAP 0xA0        // Set Segment Re-map, X[0]=0b column address 0 is mapped to SEG0
#define SSD1306_SEG_REMAP_OP 0xA1     // Set Segment Re-map, X[0]=1b: column address 127 is mapped to SEG0
#define SSD1306_COM_SCAN_DIR 0xC0     // Set COM Output, X[3]=0b: normal mode (RESET) Scan from COM0 to COM[N –1], e N is the Multiplex ratio
#define SSD1306_COM_SCAN_DIR_OP 0xC8  // Set COM Output, X[3]=1b: remapped mode. Scan from COM[N-1] to COM0, e N is the Multiplex ratio
#define SSD1306_COM_PIN_CONF \
    0xDA                          // Set COM Pins Hardware Configuration,
                                  // A[4]=0b, Sequential COM pin configuration, A[4]=1b(RESET), Alternative COM pin configuration
                                  // A[5]=0b(RESET), Disable COM Left/Right remap, A[5]=1b, Enable COM Left/Right remap
#define SSD1306_SET_CONTRAST 0x81 // Set Contrast Control, Double byte command to select 1 to 256 contrast steps, increases as the value increases
#define SSD1306_SET_OSC_FREQ \
    0xD5 // Set Display Clock Divide Ratio/Oscillator Frequency
         // A[3:0] : Define the divide ratio (D) of the  display clocks (DCLK): Divide ratio= A[3:0] + 1, RESET is 0000b (divide ratio = 1)
         // A[7:4] : Set the Oscillator Frequency, FOSC. Oscillator Frequency increases with the value of A[7:4] and vice versa. RESET is 1000b
#define SSD1306_SET_CHAR_REG \
    0x8D                           // Charge Pump Setting, A[2] = 0b, Disable charge pump(RESET), A[2] = 1b, Enable charge pump during display on
                                   // The Charge Pump must be enabled by the following command:
                                   // 8Dh ; Charge Pump Setting
                                   // 14h ; Enable Charge Pump
                                   // AFh; Display ON
#define SSD1306_SET_PRECHARGE 0xD9 // Set Pre-charge Period
#define SSD1306_VCOM_DESELECT 0xDB // Set VCOMH Deselect Leve
#define SSD1306_NOP 0xE3           // No operation
#define SSD1306_RESET 0xE4         // Maybe SW RESET, @source https://github.com/SmingHub/Sming/issues/501

// @const uint8_t - List of init commands according to datasheet SSD1306
const uint8_t INIT_SSD1306[] PROGMEM = {
    17,                                // number of initializers
    SSD1306_DISPLAY_OFF, 0,            // 0xAE = Set Display OFF
    SSD1306_SET_MUX_RATIO, 1, 0x1F,    // 0xA8 - 0x3F for 128 x 64 version (64MUX)
                                       //      - 0x1F for 128 x 32 version (32MUX)
    SSD1306_MEMORY_ADDR_MODE, 1, 0x00, // 0x20 = Set Memory Addressing Mode
                                       // 0x00 - Horizontal Addressing Mode
                                       // 0x01 - Vertical Addressing Mode
                                       // 0x02 - Page Addressing Mode (RESET)
    SSD1306_SET_START_LINE, 0,         // 0x40
    SSD1306_DISPLAY_OFFSET, 1, 0x00,   // 0xD3
    SSD1306_SEG_REMAP_OP, 0,           // 0xA0 / remap 0xA1
    SSD1306_COM_SCAN_DIR_OP, 0,        // 0xC0 / remap 0xC8
    SSD1306_COM_PIN_CONF, 1, 0x02,     // 0xDA, 0x12 - Disable COM Left/Right remap, Alternative COM pin configuration
                                       //       0x12 - for 128 x 64 version
                                       //       0x02 - for 128 x 32 version
    SSD1306_SET_CONTRAST, 1, 0x7F,     // 0x81, 0x7F - reset value (max 0xFF)
    SSD1306_DIS_ENT_DISP_ON, 0,        // 0xA4
    SSD1306_DIS_NORMAL, 0,             // 0xA6
    SSD1306_SET_OSC_FREQ, 1, 0x80,     // 0xD5, 0x80 => D=1; DCLK = Fosc / D <=> DCLK = Fosc
    SSD1306_SET_PRECHARGE, 1, 0xc2,    // 0xD9, higher value less blinking
                                       // 0xC2, 1st phase = 2 DCLK,  2nd phase = 13 DCLK
    SSD1306_VCOM_DESELECT, 1, 0x20,    // Set V COMH Deselect, reset value 0x22 = 0,77xUcc
    SSD1306_SET_CHAR_REG, 1, 0x14,     // 0x8D, Enable charge pump during display on
    SSD1306_DEACT_SCROLL, 0,           // 0x2E
    SSD1306_DISPLAY_ON, 0              // 0xAF = Set Display ON
};
void ssd1306_send_command(uint8_t cmd, const uint8_t* args, size_t argslen) {
    i2c_write(0x00, I2C_TIMEOUT_INFINITE);
    i2c_write(cmd, I2C_TIMEOUT_INFINITE);
    while (argslen--) {
        uint8_t b = pgm_read_byte(args++);
        i2c_write(b, I2C_TIMEOUT_INFINITE);
    }
}

void ssd1306_send_screen(int index) {
    const uint8_t* data = output_images[index];
    int            comp = output_images_compression[index];
    i2c_start(0x3C, I2C_TIMEOUT_INFINITE);
    uint8_t args[] = {0, 3};
    ssd1306_send_command(0x22, args, sizeof(args));
    args[1] = 127;
    ssd1306_send_command(0x21, args, sizeof(args));
    i2c_stop();
    size_t rem = 127;
    int    len = 0;
    i2c_start(0x3C, I2C_TIMEOUT_INFINITE);
    i2c_write(0x40, I2C_TIMEOUT_INFINITE);
    switch (comp) {
        case 0: // no compression
            while (len < 512) {
                uint8_t b = pgm_read_byte(data++);
                i2c_write(b, I2C_TIMEOUT_INFINITE);
                ++len;
                --rem;
                if (rem == 0) {
                    rem = 127;
                    i2c_stop();
                    i2c_start(0x3C, I2C_TIMEOUT_INFINITE);
                    i2c_write(0x40, I2C_TIMEOUT_INFINITE);
                }
            }
            break;
        default:
            while (len < 512) {
                uint8_t b     = pgm_read_byte(data++);
                uint8_t count = 1;
                if (((comp == 1 || comp == 3) && b == 0) || ((comp == 2 || comp == 3) && b == 255)) {
                    count = pgm_read_byte(data++);
                }
                while (count--) {
                    i2c_write(b, I2C_TIMEOUT_INFINITE);
                    ++len;
                    --rem;
                    if (rem == 0) {
                        rem = 127;
                        i2c_stop();
                        i2c_start(0x3C, I2C_TIMEOUT_INFINITE);
                        i2c_write(0x40, I2C_TIMEOUT_INFINITE);
                    }
                }
            }
            break;
    }
    i2c_stop();
}

void ssd1306_init(void) {
    i2c_init();
    i2c_start(0x3C, I2C_TIMEOUT_INFINITE);
    const uint8_t* init = INIT_SSD1306;
    uint8_t        len  = pgm_read_byte(init);
    const uint8_t* p    = init + 1;
    while (len--) {
        uint8_t cmd    = pgm_read_byte(p++);
        uint8_t arglen = pgm_read_byte(p++);
        ssd1306_send_command(cmd, p, arglen);
        p += arglen;
    }
    i2c_stop();
}
