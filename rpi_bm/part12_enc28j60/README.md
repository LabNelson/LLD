# Preface
This is the SPI-programm of LLD (Low Level Devel) extended with the enc28j60 driver from Christian Schoffit, portions from Gregory Nutt (https://github.com/wolfgangr/enc28j60).
Many thanks to them. The arp-test function is provided by babbleberry (https://github.com/babbleberry/rpi4-osdev).

The goal of this code is to get the enc28j60 working with the interrupt of the enc28j60 module.

# Setup
I followed the very helpful instructions from babbleberry [here] (https://github.com/babbleberry/rpi4-osdev/tree/master/part14-spi-ethernet) to hook up the ENC28J60 to the RPi4's SPI0 interface.

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

![GPIO location](./images/gpio-pinloc.png)



# Disclaimer

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