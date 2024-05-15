### Low Level Devel

Code for https://www.youtube.com/playlist?list=PLVxiWMqQvhg9FCteL7I0aohj1_YiUx1x8

### Parts

1.  Setup & Makefile
2.  Setup & UART
3.  GPIO
4.  UART
5.  Setup of RPi (First bootable program)
6.  Exception Level & ARM stub
7.  Boot to EL1
8.  Interrupts
9.  Timers
10. I2C
11. I2C LCD
12. SPI
13. VideoCore Mailbox
14. HDMI Video
15. Video with DMA
16. Enabling MMU
17. EMMC SD Card

### Building on Linux
Using aarch64-linux-gnu compiler mentioned in youtube-video of part 1

### Building on Windows
Using msys2 (at C:\msys64\usr\bin) and the gcc-arm-11.2-2022.02-mingw-w64-i686-aarch64-none-linux-gnu from the repo in LLD_tutorials.
A template batchfile exists in part6-7, just copy it to the tutorial you want to build.
Adjust BOOTMNT an RPI_VERSION (if needed) in makefile to your system, run it and have fun. 