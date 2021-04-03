/* USB Driver */
#include <stdint.h>
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

/* modifier */
#define MOD_L_CTRL     0x01
#define MOD_L_SHIFT    0x02
#define MOD_L_ALT      0x04
#define MOD_L_META     0x08

#define MOD_R_CTRL     0x10
#define MOD_R_SHIFT    0x20
#define MOD_R_ALT      0x40
#define MOD_R_META     0x80

/* key */
#define KEY_A          0x04
#define KEY_B          0x05
#define KEY_C          0x06
#define KEY_D          0x07
#define KEY_E          0x08
#define KEY_F          0x09
#define KEY_G          0x0a
#define KEY_H          0x0b
#define KEY_I          0x0c
#define KEY_J          0x0d
#define KEY_K          0x0e
#define KEY_L          0x0f
#define KEY_M          0x10
#define KEY_N          0x11
#define KEY_O          0x12
#define KEY_P          0x13
#define KEY_Q          0x14
#define KEY_R          0x15
#define KEY_S          0x16
#define KEY_T          0x17
#define KEY_U          0x18
#define KEY_V          0x19
#define KEY_W          0x1a
#define KEY_X          0x1b
#define KEY_Y          0x1c
#define KEY_Z          0x1d

#define KEY_1          0x1e
#define KEY_2          0x1f
#define KEY_3          0x20
#define KEY_4          0x21
#define KEY_5          0x22
#define KEY_6          0x23
#define KEY_7          0x24
#define KEY_8          0x25
#define KEY_9          0x26
#define KEY_0          0x27

#define KEY_ENTER      0x28
#define KEY_ESC        0x29
#define KEY_BACKSPACE  0x2a
#define KEY_TAB        0x2b
#define KEY_SPACE      0x2c
#define KEY_MINUS      0x2d
#define KEY_EQUAL      0x2e
#define KEY_LEFTBRACE  0x2f
#define KEY_RIGHTBRACE 0x30
#define KEY_BACKSLASH  0x31
#define KEY_HASHTILDE  0x32
#define KEY_SEMICOLON  0x33
#define KEY_APOSTROPHE 0x34
#define KEY_GRAVE      0x35
#define KEY_COMMA      0x36
#define KEY_DOT        0x37
#define KEY_SLASH      0x38
#define KEY_CAPSLOCK   0x39

#define KEY_F1         0x3a
#define KEY_F2         0x3b
#define KEY_F3         0x3c
#define KEY_F4         0x3d
#define KEY_F5         0x3e
#define KEY_F6         0x3f
#define KEY_F7         0x40
#define KEY_F8         0x41
#define KEY_F9         0x42
#define KEY_F10        0x43
#define KEY_F11        0x44
#define KEY_F12        0x45

#define KEY_INSERT     0x49
#define KEY_HOME       0x4a
#define KEY_PAGEUP     0x4b
#define KEY_DELETE     0x4c
#define KEY_END        0x4d
#define KEY_PAGEDOWN   0x4e

#define KEY_RIGHT      0x4f
#define KEY_LEFT       0x50
#define KEY_DOWN       0x51
#define KEY_UP         0x52

#define KEY_L_CTRL     0xe0
#define KEY_L_SHIFT    0xe1
#define KEY_L_ALT      0xe2
#define KEY_L_META     0xe3

#define KEY_R_CTRL     0xe4
#define KEY_R_SHIFT    0xe5
#define KEY_R_ALT      0xe6
#define KEY_R_META     0xe7

static const uint8_t layout_en[] PROGMEM =
{
	/* ' ',  */ 0,           KEY_SPACE,
	/* '!',  */ MOD_L_SHIFT, KEY_1,
	/* '\"', */ MOD_L_SHIFT, KEY_APOSTROPHE,
	/* '#',  */ MOD_L_SHIFT, KEY_3,
	/* '$',  */ MOD_L_SHIFT, KEY_4,
	/* '%',  */ MOD_L_SHIFT, KEY_5,
	/* '&',  */ MOD_L_SHIFT, KEY_7,
	/* '\'', */ 0,           KEY_APOSTROPHE,
	/* '(',  */ MOD_L_SHIFT, KEY_9,
	/* ')',  */ MOD_L_SHIFT, KEY_0,
	/* '*',  */ MOD_L_SHIFT, KEY_8,
	/* '+',  */ MOD_L_SHIFT, KEY_EQUAL,
	/* ',',  */ 0,           KEY_COMMA,
	/* '-',  */ 0,           KEY_MINUS,
	/* '.',  */ 0,           KEY_DOT,
	/* '/',  */ 0,           KEY_SLASH,
	/* '0',  */ 0,           KEY_0,
	/* '1',  */ 0,           KEY_1,
	/* '2',  */ 0,           KEY_2,
	/* '3',  */ 0,           KEY_3,
	/* '4',  */ 0,           KEY_4,
	/* '5',  */ 0,           KEY_5,
	/* '6',  */ 0,           KEY_6,
	/* '7',  */ 0,           KEY_7,
	/* '8',  */ 0,           KEY_8,
	/* '9',  */ 0,           KEY_9,
	/* ':',  */ MOD_L_SHIFT, KEY_SEMICOLON,
	/* ';',  */ 0,           KEY_SEMICOLON,
	/* '<',  */ MOD_L_SHIFT, KEY_COMMA,
	/* '=',  */ 0,           KEY_EQUAL,
	/* '>',  */ MOD_L_SHIFT, KEY_DOT,
	/* '?',  */ MOD_L_SHIFT, KEY_SLASH,
	/* '@',  */ MOD_L_SHIFT, KEY_2,
	/* 'A',  */ MOD_L_SHIFT, KEY_A,
	/* 'B',  */ MOD_L_SHIFT, KEY_B,
	/* 'C',  */ MOD_L_SHIFT, KEY_C,
	/* 'D',  */ MOD_L_SHIFT, KEY_D,
	/* 'E',  */ MOD_L_SHIFT, KEY_E,
	/* 'F',  */ MOD_L_SHIFT, KEY_F,
	/* 'G',  */ MOD_L_SHIFT, KEY_G,
	/* 'H',  */ MOD_L_SHIFT, KEY_H,
	/* 'I',  */ MOD_L_SHIFT, KEY_I,
	/* 'J',  */ MOD_L_SHIFT, KEY_J,
	/* 'K',  */ MOD_L_SHIFT, KEY_K,
	/* 'L',  */ MOD_L_SHIFT, KEY_L,
	/* 'M',  */ MOD_L_SHIFT, KEY_M,
	/* 'N',  */ MOD_L_SHIFT, KEY_N,
	/* 'O',  */ MOD_L_SHIFT, KEY_O,
	/* 'P',  */ MOD_L_SHIFT, KEY_P,
	/* 'Q',  */ MOD_L_SHIFT, KEY_Q,
	/* 'R',  */ MOD_L_SHIFT, KEY_R,
	/* 'S',  */ MOD_L_SHIFT, KEY_S,
	/* 'T',  */ MOD_L_SHIFT, KEY_T,
	/* 'U',  */ MOD_L_SHIFT, KEY_U,
	/* 'V',  */ MOD_L_SHIFT, KEY_V,
	/* 'W',  */ MOD_L_SHIFT, KEY_W,
	/* 'X',  */ MOD_L_SHIFT, KEY_X,
	/* 'Y',  */ MOD_L_SHIFT, KEY_Y,
	/* 'Z',  */ MOD_L_SHIFT, KEY_Z,
	/* '[',  */ MOD_L_SHIFT, KEY_LEFTBRACE,
	/* '\\', */ 0,           KEY_BACKSLASH,
	/* ']',  */ MOD_L_SHIFT, KEY_RIGHTBRACE,
	/* '^',  */ MOD_L_SHIFT, KEY_6,
	/* '_',  */ MOD_L_SHIFT, KEY_MINUS,
	/* '`',  */ 0,           KEY_GRAVE,
	/* 'a',  */ 0,           KEY_A,
	/* 'b',  */ 0,           KEY_B,
	/* 'c',  */ 0,           KEY_C,
	/* 'd',  */ 0,           KEY_D,
	/* 'e',  */ 0,           KEY_E,
	/* 'f',  */ 0,           KEY_F,
	/* 'g',  */ 0,           KEY_G,
	/* 'h',  */ 0,           KEY_H,
	/* 'i',  */ 0,           KEY_I,
	/* 'j',  */ 0,           KEY_J,
	/* 'k',  */ 0,           KEY_K,
	/* 'l',  */ 0,           KEY_L,
	/* 'm',  */ 0,           KEY_M,
	/* 'n',  */ 0,           KEY_N,
	/* 'o',  */ 0,           KEY_O,
	/* 'p',  */ 0,           KEY_P,
	/* 'q',  */ 0,           KEY_Q,
	/* 'r',  */ 0,           KEY_R,
	/* 's',  */ 0,           KEY_S,
	/* 't',  */ 0,           KEY_T,
	/* 'u',  */ 0,           KEY_U,
	/* 'v',  */ 0,           KEY_V,
	/* 'w',  */ 0,           KEY_W,
	/* 'x',  */ 0,           KEY_X,
	/* 'y',  */ 0,           KEY_Y,
	/* 'z',  */ 0,           KEY_Z,
	/* '{',  */ 0,           KEY_LEFTBRACE,
	/* '|',  */ MOD_L_SHIFT, KEY_BACKSLASH,
	/* '~',  */ MOD_L_SHIFT, KEY_GRAVE,
	/* '}',  */ 0,           KEY_RIGHTBRACE
};

static const uint8_t layout_de[] PROGMEM =
{
	/* ' ',  */ 0,           KEY_SPACE,
	/* '!',  */ MOD_L_SHIFT, KEY_1,
	/* '\"', */ MOD_L_SHIFT, KEY_2,
	/* '#',  */ 0,           KEY_BACKSLASH,
	/* '$',  */ MOD_L_SHIFT, KEY_4,
	/* '%',  */ MOD_L_SHIFT, KEY_5,
	/* '&',  */ MOD_L_SHIFT, KEY_6,
	/* '\'', */ MOD_L_SHIFT, KEY_BACKSLASH,
	/* '(',  */ MOD_L_SHIFT, KEY_8,
	/* ')',  */ MOD_L_SHIFT, KEY_9,
	/* '*',  */ MOD_L_SHIFT, KEY_RIGHTBRACE,
	/* '+',  */ 0,           KEY_RIGHTBRACE,
	/* ',',  */ 0,           KEY_COMMA,
	/* '-',  */ 0,           KEY_SLASH,
	/* '.',  */ 0,           KEY_DOT,
	/* '/',  */ MOD_L_SHIFT, KEY_7,
	/* '0',  */ 0,           KEY_0,
	/* '1',  */ 0,           KEY_1,
	/* '2',  */ 0,           KEY_2,
	/* '3',  */ 0,           KEY_3,
	/* '4',  */ 0,           KEY_4,
	/* '5',  */ 0,           KEY_5,
	/* '6',  */ 0,           KEY_6,
	/* '7',  */ 0,           KEY_7,
	/* '8',  */ 0,           KEY_8,
	/* '9',  */ 0,           KEY_9,
	/* ':',  */ MOD_L_SHIFT, KEY_DOT,
	/* ';',  */ MOD_L_SHIFT, KEY_COMMA,
	/* '<',  */ MOD_L_SHIFT, KEY_COMMA,
	/* '=',  */ 0,           KEY_EQUAL,
	/* '>',  */ MOD_L_SHIFT, KEY_DOT,
	/* '?',  */ MOD_L_SHIFT, KEY_SLASH,
	/* '@',  */ MOD_R_ALT,   KEY_Q,
	/* 'A',  */ MOD_L_SHIFT, KEY_A,
	/* 'B',  */ MOD_L_SHIFT, KEY_B,
	/* 'C',  */ MOD_L_SHIFT, KEY_C,
	/* 'D',  */ MOD_L_SHIFT, KEY_D,
	/* 'E',  */ MOD_L_SHIFT, KEY_E,
	/* 'F',  */ MOD_L_SHIFT, KEY_F,
	/* 'G',  */ MOD_L_SHIFT, KEY_G,
	/* 'H',  */ MOD_L_SHIFT, KEY_H,
	/* 'I',  */ MOD_L_SHIFT, KEY_I,
	/* 'J',  */ MOD_L_SHIFT, KEY_J,
	/* 'K',  */ MOD_L_SHIFT, KEY_K,
	/* 'L',  */ MOD_L_SHIFT, KEY_L,
	/* 'M',  */ MOD_L_SHIFT, KEY_M,
	/* 'N',  */ MOD_L_SHIFT, KEY_N,
	/* 'O',  */ MOD_L_SHIFT, KEY_O,
	/* 'P',  */ MOD_L_SHIFT, KEY_P,
	/* 'Q',  */ MOD_L_SHIFT, KEY_Q,
	/* 'R',  */ MOD_L_SHIFT, KEY_R,
	/* 'S',  */ MOD_L_SHIFT, KEY_S,
	/* 'T',  */ MOD_L_SHIFT, KEY_T,
	/* 'U',  */ MOD_L_SHIFT, KEY_U,
	/* 'V',  */ MOD_L_SHIFT, KEY_V,
	/* 'W',  */ MOD_L_SHIFT, KEY_W,
	/* 'X',  */ MOD_L_SHIFT, KEY_X,
	/* 'Y',  */ MOD_L_SHIFT, KEY_Z,
	/* 'Z',  */ MOD_L_SHIFT, KEY_Y,
	/* '[',  */ MOD_R_ALT,   KEY_8,
	/* '\\', */ 0,           KEY_BACKSLASH,
	/* ']',  */ MOD_R_ALT,   KEY_9,
	/* '^',  */ MOD_L_SHIFT, KEY_6,
	/* '_',  */ MOD_L_SHIFT, KEY_MINUS,
	/* '`',  */ 0,           KEY_GRAVE,
	/* 'a',  */ 0,           KEY_A,
	/* 'b',  */ 0,           KEY_B,
	/* 'c',  */ 0,           KEY_C,
	/* 'd',  */ 0,           KEY_D,
	/* 'e',  */ 0,           KEY_E,
	/* 'f',  */ 0,           KEY_F,
	/* 'g',  */ 0,           KEY_G,
	/* 'h',  */ 0,           KEY_H,
	/* 'i',  */ 0,           KEY_I,
	/* 'j',  */ 0,           KEY_J,
	/* 'k',  */ 0,           KEY_K,
	/* 'l',  */ 0,           KEY_L,
	/* 'm',  */ 0,           KEY_M,
	/* 'n',  */ 0,           KEY_N,
	/* 'o',  */ 0,           KEY_O,
	/* 'p',  */ 0,           KEY_P,
	/* 'q',  */ 0,           KEY_Q,
	/* 'r',  */ 0,           KEY_R,
	/* 's',  */ 0,           KEY_S,
	/* 't',  */ 0,           KEY_T,
	/* 'u',  */ 0,           KEY_U,
	/* 'v',  */ 0,           KEY_V,
	/* 'w',  */ 0,           KEY_W,
	/* 'x',  */ 0,           KEY_X,
	/* 'y',  */ 0,           KEY_Z,
	/* 'z',  */ 0,           KEY_Y,
	/* '{',  */ MOD_R_ALT,   KEY_7,
	/* '|',  */ MOD_L_SHIFT, KEY_BACKSLASH,
	/* '}',  */ MOD_R_ALT,   KEY_0,
	/* '~',  */ MOD_L_SHIFT, KEY_GRAVE
};

#define UART_BAUD  9600
#define _BAUD          (((F_CPU / (UART_BAUD * 16UL))) - 1)

static void uart_init(void)
{
	UCSR0B = (1 << RXEN0) | (1 << TXEN0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	UBRR0L = (uint8_t)(_BAUD & 0xFF);
	UBRR0H = (uint8_t)((_BAUD >> 8) & 0xFF);
}

static void uart_tx(uint8_t c)
{
	while(!(UCSR0A & (1 << UDRE0))) ;
	UDR0 = c;
}

static void uart_tx_buf(uint8_t *a, uint8_t len)
{
	while(len--)
	{
		uart_tx(*a++);
	}
}

static void usb_init(void)
{
	uart_init();
	_delay_ms(5000);
}

static void usb_char(char c)
{
	static uint8_t buf[8];

	if(c == '\n')
	{
		buf[0] = 0;
		buf[2] = KEY_ENTER;
	}
	else if(c == '\t')
	{
		buf[0] = 0;
		buf[2] = KEY_TAB;
	}
	else
	{
		buf[0] = pgm_read_byte(layout_de + (c - 32) * 2);
		buf[2] = pgm_read_byte(layout_de + (c - 32) * 2 + 1);
	}

	uart_tx_buf(buf, 8);
	buf[0] = 0;
	buf[2] = 0;
	uart_tx_buf(buf, 8);
}

static void usb_string(const char *s)
{
	char c;
	while((c = *s++))
	{
		usb_char(c);
	}
}

static void usb_string_P(const char *s)
{
	char c;
	while((c = pgm_read_byte(s++)))
	{
		usb_char(c);
	}
}

