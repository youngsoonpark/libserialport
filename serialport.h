/*
 * This file is part of the libserialport project.
 *
 * Copyright (C) 2010-2012 Bert Vermeulen <bert@biot.com>
 * Copyright (C) 2010-2012 Uwe Hermann <uwe@hermann-uwe.de>
 * Copyright (C) 2012 Alexandru Gagniuc <mr.nuke.me@gmail.com>
 * Copyright (C) 2013 Martin Ling <martin-libserialport@earth.li>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stddef.h>
#ifdef _WIN32
#include <windows.h>
#endif

/* A serial port. */
struct sp_port {
	/* Name used to open the port */
	char *name;
	/* OS-specific port handle */
#ifdef _WIN32
	HANDLE hdl;
#else
	int fd;
#endif
};

/* Return values. */
enum {
	/* Operation completed successfully. */
	SP_OK = 0,
	/* A system error occured while executing the operation. */
	SP_ERR_FAIL = -1,
	/* Invalid arguments were passed to the function. */
	SP_ERR_ARG = -2
};

/* Port access modes. */
enum {
	/* Open port for read/write access. */
	SP_MODE_RDWR = 1,
	/* Open port for read access only. */
	SP_MODE_RDONLY = 2,
	/* Open port in non-blocking mode. */
	SP_MODE_NONBLOCK = 4
};

/* Parity settings. */
enum {
	/* No parity. */
	SP_PARITY_NONE = 0,
	/* Even parity. */
	SP_PARITY_EVEN = 1,
	/* Odd parity. */
	SP_PARITY_ODD = 2
};

int sp_open(struct sp_port *port, char *portname, int flags);
int sp_close(struct sp_port *port);
int sp_flush(struct sp_port *port);
int sp_write(struct sp_port *port, const void *buf, size_t count);
int sp_read(struct sp_port *port, void *buf, size_t count);
int sp_set_params(struct sp_port *port, int baudrate, int bits, int parity,
		int stopbits, int flowcontrol, int rts, int dtr);
int sp_last_error_code(void);
char *sp_last_error_message(void);
void sp_free_error_message(char *message);
