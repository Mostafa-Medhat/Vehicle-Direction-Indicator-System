# Vehicle-Direction-FinalProject Based on Design Patterns and RTOS
# Project Title:
vehicle direction and hazard indicator controller.
## Project Description:
The project requires the design and implementation of a Vehicle direction and hazard indicator
control system the besides **complete software static architecture, real time
analysis and selected design patterns with justification**. The system controls the vehicle indicator LEDs based on the state of the
indicator arm and the hazard button through **RTOS**.

## System Architecture:
![image](https://user-images.githubusercontent.com/61350640/223499525-de91f0f5-8407-4635-a88c-8e6b22242353.png)

The system has four inputs. One Push button is referred to as SW1. This button simulates the input coming from the hazard button. Two on off switch inputs. They are combined in an SP3T connection. Two terminals are connected to the MCU and are referred to as SW2 and SW3. The third terminal is not connected. So, when selected, no input will be applied from the two switch inputs. The combination simulates the input coming from the indicator arm with the three selections, right indicator, left indicator and no indicator. The last input is an ON/OFF switch with one terminal. The switch simulates the ignition key of the vehicle. The system has two outputs. LED1 which represents the right indicator LED and LED2 which indicates the left indicator LED. The two LEDs shall be driven through PWM signals

## Demo:
![Demo](https://user-images.githubusercontent.com/61350640/219145619-8b5c7e40-204c-42ce-815b-00045844997a.gif)
