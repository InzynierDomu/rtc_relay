# rtc_relay

Simple time relay based on Arduino and RTC

- [About](#About)
- [Scheme](#Scheme)
- [IDE](#IDE)

## About

To config project for own needs You should change:

```cpp
const DateTime m_start = DateTime(2000, 1, 1, 16, 48, 0); ///< time when realy turn on
const DateTime m_stop = DateTime(2000, 1, 1, 16, 50, 0); ///< time when realy turn off
```

From these two DateTime format yyyy, mm, dd, hh, mm, ss only hh, mm is important.
For this example relay turn in 16:48 and turn of in 16:50.

## Scheme

![alt text](https://github.com/InzynierDomu/rtc_relay/blob/main/schem_1.PNG)

## IDE

The project is prepared for the Platform IO environment. A video on how to install such an environment can be watched on this [video](https://youtu.be/Em9NuebT2Kc).
<br>
Formatting is done using clang-format. The description of the tool configuration is in the [video](https://youtu.be/xxuaOG0WjIE).
<br>
The code contains a comment prepared for doxygen, their use is described in the [video](https://youtu.be/1YKJtrCsPD4).
