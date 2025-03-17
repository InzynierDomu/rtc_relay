# rtc_relay

![GitHub Workflow Status](https://img.shields.io/github/actions/workflow/status/InzynierDomu/rtc_relay/main.yml?logo=github&style=flat-square)
![GitHub release (latest SemVer)](https://img.shields.io/github/v/release/InzynierDomu/rtc_relay?style=flat-square)
<a href="https://discord.gg/KmW6mHdg">![Discord](https://img.shields.io/discord/815929748882587688?logo=discord&logoColor=green&style=flat-square)</a>
![GitHub](https://img.shields.io/github/license/InzynierDomu/rtc_relay?style=flat-square)

Simple time relay based on Arduino and RTC

- [rtc\_relay](#rtc_relay)
  - [About](#about)
  - [Scheme](#scheme)
  - [IDE](#ide)

## About

To config project for own needs You should change (in src/main.cpp):

```cpp
const DateTime m_start = DateTime(2000, 1, 1, 16, 48, 0); ///< time when realy turn on
const DateTime m_stop = DateTime(2000, 1, 1, 16, 50, 0); ///< time when realy turn off
```

From these two DateTime format yyyy, mm, dd, hh, mm, ss only hh, mm is important.
For this example relay turn in 16:48 and turn of in 16:50.
<br><br>
Setting the time is executing when the project is built and uploaded to the board with the connected RTC
<br><br>
If you want additional information delete ; in
paltformio.ini

```cpp
;build_flags = -D DEBUG
```

It isn't work for RTC_DS3231

<div align="center">
<h2>Support</h2>

<p>If any of my projects have helped you in your work, studies, or simply made your day better, you can buy me a coffee. <a href="https://buycoffee.to/inzynier-domu" target="_blank"><img src="https://buycoffee.to/img/share-button-primary.png" style="width: 195px; height: 51px" alt="Postaw mi kawę na buycoffee.to"></a></p>
</div>

## Scheme

You can use ready RTC module
![alt text](https://github.com/InzynierDomu/rtc_relay/blob/main/schem_2.PNG)
<br>
or use chip with other elements.
![alt text](https://github.com/InzynierDomu/rtc_relay/blob/main/schem_1.PNG)

## IDE

The project is prepared for the Platform IO environment. A video on how to install such an environment can be watched on this [video](https://youtu.be/Em9NuebT2Kc).
<br><br>
Formatting is executed using clang-format. The description of the tool configuration is in the [video](https://youtu.be/xxuaOG0WjIE).
<br><br>
The code contains a comment prepared for doxygen, their use is described in the [video](https://youtu.be/1YKJtrCsPD4).
