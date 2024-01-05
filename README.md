# uart-relay-switch
This is a command-line tool that controls your board's reset button.

It uses UART's `RTS` pin to control the relay that emulates electrical switch.

## Prerequisites
* 1x USB to UART(TTL) serial converter
* 1x relay
* few jumper wires

## Wiring

## Build
Implement your own switch logic in *main.c* and compile it with *relay.c*.

```sh
gcc relay.c main.c -o switch
gcc relay.c examples/push_return.c -o switch # example
```

Then put the executable to somewhere in `PATH`.

## Usage
```bash
./switch /dev/<your_uart_converter>
./switch /dev/cu.usbmodem51850106861 # example
```

## Examples
* **example/push_return.c**: simple push-return(tact) switch press implementation (ex. T2080RDB reset button)
* **example/push_toggle.c**: push-toggle switch on&off implementation (ex. IMA-FCC-T2080 power switch)
