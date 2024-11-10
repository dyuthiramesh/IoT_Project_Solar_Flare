# solar-flare-classification-ESP32

"A neural network model for solar flare classification, trained on solar flare data and optimized for deployment on ESP32 with TensorFlow Lite."

This repository contains a project for solar flare classification using a neural network model, trained on solar flare data and optimized for deployment on an ESP32 microcontroller using TensorFlow Lite.

## Project Overview

The project aims to predict solar flare classes (common, moderate, and severe) based on various solar flare features. The dataset includes multiple solar flare predictors, and the trained model is deployed on the ESP32 microcontroller for edge inference.

- **Subject Area:** Space Science / Astrophysics
- **Associated Tasks:** Classification
- **Data Characteristics:** Multivariate
- **Total Instances:** (Update based on dataset size)
- **Features:** 10 (including modified Zurich class, spot size, area, etc.)

## Dataset

The dataset used for training includes solar flare observations with multiple features, such as:
- `modified Zurich class`
- `largest spot size`
- `spot distribution`
- `activity`
- `evolution`
- `previous 24-hour flare activity`
- `historically-complex`
- `became complex on this pass`
- `area`
- `area of largest spot`

The dataset is used to predict the classes of solar flares: **common flares**, **moderate flares**, and **severe flares**.

## Neural Network Model

The neural network model is designed for edge inference on the ESP32 microcontroller. It is a small, lightweight model suitable for real-time classification tasks in constrained environments.

After training the model in Keras, it is saved in the `.h5` format and then converted to TensorFlow Lite (`.tflite`) for deployment on the ESP32.

## Repository Structure

- `data/` - Contains the dataset files used for training (solar flare data).
- `model/` - Includes the saved Keras model (`solar_flare_model.h5`) and the converted TFLite model (`solar_flare_model.tflite`).
- `scripts/` - Includes Python scripts for data preprocessing, model training, and TensorFlow Lite conversion.
- `SolarFlare_ESP32/` - Contains the Arduino `.ino` file (`solar_flare_ESP32.ino`) and the generated header file for running on the ESP32.
- `README.md` - Project documentation.

## Installation

1. Clone this repository:
   ```bash
   https://github.com/dyuthiramesh/IoT_Project_Solar_Flare.git
   ```
   
2. Install the required dependencies for Python (for model training and conversion):
   ```bash
   pip install tensorflow numpy scikit-learn
   ```

3. Set up the Arduino IDE for ESP32:
   - Install the ESP32 board package in Arduino IDE.
   - Ensure the required libraries (`EloquentTinyML`, `TensorFlow Lite`, etc.) are installed.

4. Upload the `solar_flare_ESP32.ino` file to your ESP32 board:
   - Open the `.ino` file in Arduino IDE.
   - Set the correct port and board type.
   - Upload the code.

## Contributing

Feel free to open issues or submit pull requests for improvements! Any suggestions for further optimization or expansion are welcome.