# IIR Filter in C
This repository contains an implementation of an Infinite Impulse Response (IIR) filter in C. The filter is designed to remove noise from a signal by using feedback to filter out specific frequency components.

## Getting Started
To use the filter, you will need to include the iir.h and iir.c files in your project. The filter can then be initialized by calling the iir_init() function and passing in the desired filter coefficients. The filtered signal can be obtained by calling the iir_filter() function and passing in the input signal.

## Examples
./filter44 <audio_input.au >audio_output.au

## Limitations
The current implementation of the IIR filter is limited to second order filters. However, this can be easily extended to support higher order filters by modifying the iir.c file.

## Contributing
If you would like to contribute to this project, please feel free to submit a pull request.

## Authors
Cleiton Moreira - Initial work
## License
This project is licensed under the MIT License - see the LICENSE.md file for details.

