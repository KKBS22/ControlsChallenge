# ControlsChallenge


# Usage 
```
1. Clone the repository
2. cd /ControlsChallenge
3. mkdir build
4. cd build
5. cmake ..
6. make
``````

# Running tests
```
Build command : gcc -I ./cmocka-1.1.5/include/ -L ./cmocka-1.1.5/build/src/ test_controlLib.c -l:libcmocka-static.a libControlLib.a

[==========] Running 5 test(s).
[ RUN      ] test_system_pre_check
[       OK ] test_system_pre_check
[ RUN      ] test_temp_scale
[       OK ] test_temp_scale
[ RUN      ] test_flow_scale
[       OK ] test_flow_scale
[ RUN      ] test_pump_control
[       OK ] test_pump_control
[ RUN      ] test_fan_control
[       OK ] test_fan_control
[==========] 5 test(s) run.
[  PASSED  ] 5 test(s).

```
