# Accessing Ethernet with baremetal C on RPi4
The goal of this code is to get the enc28j60 working with the interrupt of the enc28j60 module. Advanced will be a lightweight tcpip stack

## Background
I'm really excited about aquiring knowledge and having a holistic process while doing so.
In this process you stumble over simulations, calculations, test plans, testbench-systems, data-analysis and writing scientific papers. Preferably in one tool an of course open source.

The championship of filling the gap between simulations and calculations of scientific approaches combined with real measurements on real hardware and data-analysis.
I explored some simulation/testbendch-systems over the years like Matlab, GNU-Octave, LabView, [NI myDAQ](https://www.ni.com/en/shop/engineering-education/portable-student-devices/mydaq/what-is-mydaq.html), [MLab](https://www.stiegele.eu/software-ueberblick/), [Speedgoat](https://www.speedgoat.com/solutions).
They are all dealing with software and hardware. Ether the software is expensive or the hardware. 

A tool like [CAMeL-View](https://camelview.org/) can take over a lot of the sub-processes: simulation, calculation, testbench-system (and data-analysis). It prepares the data, being analysed by GNU-Octave and delivers figures to [Latex](https://en.wikipedia.org/wiki/LaTeX), which is also in my holistic-toolchain.
The software is nearly open source but the hardware is not. So let's start making the RPi4 even more powerful.

The GUI of CAMeL-View is written in smalltalk. The IDE from instantiations needs a license, so we can't build the GUI on open source basis yet.
The simulation can run on the development machine or on the target machine as well. Therefore CAMeL-View generates c-code which is then compiled and linked against the desired hardware which needs available implementations of the target-drivers.
To meet hard real-time requirements [FreeRTOS](https://www.freertos.org/index.html) is used as OS. The API to the hardware-code is a C-library. So in writing c-code drivers for the RPi4-peripherals we simultaneously get closer to the CAMeL-View open source hardware.

## Preface
This is the SPI-programm forked from LLD (Low Level Devel) extended with the enc28j60 driver from [Christian Schoffit, portions from Gregory Nutt](https://github.com/wolfgangr/enc28j60). Many thanks to them.
The arp-test function is provided by [babbleberry](https://github.com/babbleberry/rpi4-osdev).

## Setup
I followed the very helpful instructions from babbleberry [here](https://github.com/babbleberry/rpi4-osdev/tree/master/part14-spi-ethernet) to hook up the ENC28J60 to the RPi4's SPI0 interface.

The difference is that we will connect the interrupt line:

 | Pi pin | Pi GPIO     | Jumper colour | ENC28J60 pin |
 | ------ | ----------- | ------------- | ------------ |
 | Pin 17 | +3V3 power  | red           | VCC          |
 | Pin 19 | GPIO10/MOSI | orange        | SI           |
 | Pin 20 | GND         | brown         | GND          |
 | Pin 21 | GPIO09/MISO | yellow        | SO           |
 | Pin 23 | GPIO11/SCLK | green         | SCK          |
 | Pin 24 | GPIO08/CE0  | blue          | CS           |
 | Pin 24 | GPIO08/CE0  | violett       | INT          |

You can find these pins on the gpio-header of the RPi4, here:

![GPIO location](./images/gpio-pinloc.png)
from [RPi-Homepage](https://www.raspberrypi.com/documentation/computers/raspberry-pi.html#gpio-and-the-40-pin-header)

## Code
t.b.d


## Disclaimer

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.