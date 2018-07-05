# input_lib

C++ input mapping library. Supports GLFW.

See the [demo source](input_lib_demo/src/main.cpp) for usage examples.

## Devices

Device inputs can be queried directly or through ActionMap instances.


### Mouse

```cpp
const Coord mousePosition = mouse.getPosition();
const Coord mouseScroll = mouse.getScroll();
const ButtonState leftButtonState = mouse.getLeftButtonState();
```


## ActionMap

The ActionMap class is used to map user-defined action IDs to device inputs. Analog (float) and digital (bool) values can than be queried from devices using the mapped action IDs.


### User Action IDs

User-defined action IDs can be unsigned values or enums.

```cpp
enum InputActionId
{
    Accept,
    Accelerate,
    MoveDown,
    MoveLeft,
    MoveRight,
    MoveUp,
    Quit,
};
```

### Axis

Devices return axis values in the range of -1.0 to 1.0.

When mapping an axis with ActionMap, you can specify the range of the axis to use (full, positive only, negative only) as well as the range of analog values to use instead of -1.0 and 1.0.

AxisRange can be used to split an axis into two user-defined action IDs (e.g. to assign the same gamepad stick to MoveLeft and MoveRight action IDs).

* AxisRange::Full - Returns values from -1.0 to 1.0
* AxisRange::Positive - Returns values from 0.0 to 1.0
* AxisRange::Negative - Returns values from 0.0 to -1.0

If an AxisRange other than Full is specified, the minimum and maximum values still specify the values across the full range of the axis. After the analog value is queried from the device and clamped to the specified AxisRange, it will be scaled to the range of values specified by the minimum and maximum.

```cpp
//  Map a Gamepad button
actionMap.map(InputActionId::Accept, Gamepad360::A_BUTTON);

//  Map a Gamepad axis
actionMap.map(
    InputActionId::Accelerate,
    Gamepad360::RIGHT_TRIGGER,
    AxisRange::Full,
    0.0f,
    1.0f
);

//  Map two action IDs to one axis (negative and positive)
actionMap.map(
    InputActionId::MoveLeft,
    Gamepad360::LEFT_STICK_X,
    AxisRange::Negative
);

actionMap.map(
    InputActionId::MoveRight,
    Gamepad360::LEFT_STICK_X,
    AxisRange::Positive
);
```


### Button

```cpp
//  Map a gamepad button
actionMap.map(InputActionId::Accept, Gamepad360::A_BUTTON);

//  Map a mouse button
actionMap.map(InputActionId::Accept, MouseButton::LeftButton);
```


### Key

```cpp
//  Map some keys
actionMap.map(InputActionId::Accept, Key::Enter);
actionMap.map(InputActionId::Accelerate, Key::Space);
actionMap.map(InputActionId::MoveRight, Key::E);
actionMap.map(InputActionId::MoveDown, Key::O);
actionMap.map(InputActionId::Quit, Key::Escape);

//  Map some keys to custom analog values
actionMap.map(InputActionId::MoveLeft, Key::A, -1.0f);
actionMap.map(InputActionId::MoveUp, Key::Comma, -1.0f);
```


### Querying Devices

```cpp
//  Get a digital value
bool crouch = actionMap.getDigitalValue(InputActionId::Crouch, device);

//  Get an analog value
float accelerate = actionMap.getAnalogValue(InputActionId::Accelerate);

//  Check if an input was pressed but not held
actionMap.isPressed(InputActionId::Accept, device)  {
    std::cout << "Accept was pressed." << std::endl;
}
```


# GLFW

```cpp
//  Create InputManager instance
GlfwInputManager inputManager;

//  Register input callbacks
registerGlfwCallbacks(window);

//  Main loop
while (!glfwWindowShouldClose(window)) {
    //  Update InputManager (calls glfwPollEvents)
    inputManager.update();
}
```

## GLFW Input Callbacks

InputLib uses five input callback functions with GLFW:
* joystickCallback
* keyboardCallback
* mousePositionCallback
* mouseButtonCallback
* scrollCallback

You can register all of these callbacks with GLFW with one function call:

```cpp
registerGlfwCallbacks(window);
```

You could also register callbacks individually:

```cpp
glfwSetKeyCallback(window, keyboardCallback);
glfwSetJoystickCallback(joystickCallback);
glfwSetCursorPosCallback(window, mousePositionCallback);
glfwSetMouseButtonCallback(window, mouseButtonCallback);
glfwSetScrollCallback(window, scrollCallback);
```

You could also register your own callbacks and then call the InputLib callbacks when needed. This is useful with libraries like [Dear ImGUI](https://github.com/ocornut/imgui) that may capture input first.


# CMake

```shell
mkdir build
cd build
cmake  ..
make
```

Install is supported.

```shell
cmake -DCMAKE_BUILD_TYPE=Release ..
make install

cmake -DCMAKE_BUILD_TYPE=Debug ..
make install
```
